#include <cmath>
#include <iostream>

class Complex
{
private:
	double re;
	double im;
public:
	Complex(double re = 0, double im = 0)
		: re(re), im(im)
	{	}

	double real() const
	{
		return re;
	}
	double imaginary() const
	{
		return im;
	}

	Complex getConjugate() const
	{
		return Complex(re, -im);
	}
	double getConjugateMultiplicate() const
	{
		return re * re + im * im;
	}

	double abs() const
	{
		return std::sqrt(re * re + im * im);
	}
	double absSq() const
	{
		return re * re + im * im;
	}

	Complex operator+(const Complex& right) const
	{
		return Complex(this->re + right.re, this->im + right.im);
	}
	Complex operator-(const Complex& right) const
	{
		return Complex(this->re - right.re, this->im - right.im);
	}
	Complex operator*(const Complex& right) const
	{
		// (a + bi) * (c + di) = ac-bd + i(ad+bc)
		return Complex(this->re * right.re - this->im * right.im, this->re * right.im + this->im * right.re);
	}
	Complex operator/(const Complex& right) const
	{
		Complex temp = (*this) * right.getConjugate();
		double x = right.getConjugateMultiplicate();
		temp.re /= x;
		temp.im /= x;
		return temp;
	}

	Complex& operator+=(const Complex& right)
	{
		this->re += right.re;
		this->im += right.im;
		return *this;
	}
	Complex& operator-=(const Complex& right)
	{
		this->re -= right.re;
		this->im -= right.im;
		return *this;
	}
	Complex& operator*=(const Complex& right)
	{
		double a = this->re * right.re - this->im * right.im;
		double b = this->re * right.im + this->im * right.re;
		this->re = a;
		this->im = b;
		return *this;
	}
	Complex& operator/=(const Complex& right)
	{
		double x = right.getConjugateMultiplicate();
		*this *= right.getConjugate();
		this->re /= x;
		this->im /= x;
		return *this;
	}

	Complex operator-() const
	{
		return Complex(-re, -im);
	}
	Complex operator+() const
	{
		return *this;
	}

	friend Complex operator+(double left, const Complex& right);
	friend Complex operator-(double left, const Complex& right);
	friend Complex operator*(double left, const Complex& right);
	friend Complex operator/(double left, const Complex& right);

	friend std::ostream& operator<<(std::ostream& os, const Complex& x)
	{
		os << x.re << " + i" << x.im;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Complex& x)
	{
		char t;
		is >> x.re >> t >> x.im;
		return is;
	}
};

int main()
{
	Complex num1(1, 2);
	Complex num2(2, 1);
	std::cout << "(" << num1 << ") * (" << num2 << ") = " << num1 * num2 << std::endl;
	std::cin >> num1;
	std::cout << num1;
	return 0;
}

Complex operator+(double left, const Complex& right)
{
	return Complex(left) + right;
}

Complex operator-(double left, const Complex& right)
{
	return Complex(left) - right;
}

Complex operator*(double left, const Complex& right)
{
	return Complex(left) * right;
}

Complex operator/(double left, const Complex& right)
{
	return Complex(left) / right;
}
