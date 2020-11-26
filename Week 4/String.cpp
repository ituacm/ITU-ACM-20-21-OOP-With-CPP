#include <iostream>
#include <string>

class String
{
private:
	char* m_data = nullptr;
public:
	String(const char* str)
	{
		std::cout << "String(const char*)" << std::endl;
		size_t size = strlen(str) + 1;
		m_data = new char[size];
		memcpy(m_data, str, size * sizeof(char));
	}

	String(const std::string& str)
	{
		std::cout << "String(const std::string&)" << std::endl;
		size_t size = str.size() + 1;
		m_data = new char[size + 1];
		memcpy(m_data, str.c_str(), size * sizeof(char));
	}

	String(const String& str)
	{
		std::cout << "String(const String&)" << std::endl;
		size_t size = strlen(str.m_data) + 1;
		m_data = new char[size];
		memcpy(m_data, str.m_data, size * sizeof(char));
	}

	~String()
	{
		std::cout << "~String()" << std::endl;
		delete[] m_data;
	}

	String& operator=(const String& str)
	{
		std::cout << "String& operator=(const String&)" << std::endl;

		if (this == &str)
			return *this;

		delete[] m_data;
		size_t size = strlen(str.m_data) + 1;
		m_data = new char[size];
		memcpy(m_data, str.m_data, size * sizeof(char));

		return *this;
	}

	explicit operator const char* ()
	{
		std::cout << "operator const char* ()" << std::endl;
		return m_data;
	}

	friend std::ostream& operator<<(std::ostream& os, const String& str);
};

std::ostream& operator<<(std::ostream& os, const String& str)
{
	std::cout << "std::ostream& operator<<(std::ostream&, const String&)" << std::endl;
	return os << str.m_data;
}


int main()
{
	String myString = "Hello";
	String myString2 = myString;
	myString = myString2;
	std::cout << myString << std::endl;
	return 0;
}
