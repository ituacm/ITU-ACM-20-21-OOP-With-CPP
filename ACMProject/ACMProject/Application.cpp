#include <SFML/Graphics.hpp>
#include <chrono>

class Level
{
private:
	sf::Sprite player;
	sf::Texture playerTexture;
public:
	Level()
	{}

	void init()
	{
		playerTexture.loadFromFile("player.png");
		player.setTexture(playerTexture);
	}

	void update(float deltaTime)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			player.move(-1 * deltaTime, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			player.move(1 * deltaTime, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			player.move(0, -1 * deltaTime);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			player.move(0, 1 * deltaTime);
	}

	void render(sf::RenderWindow& window)
	{
		window.draw(player);
	}
};

class Game
{
private:
	sf::RenderWindow window;
	Level* level;
public:
	Game(std::string title, unsigned int width, unsigned int height)
		: window(sf::VideoMode(width, height), title), level(nullptr)
	{

	}

	void attachLevel(Level* l)
	{
		this->level = l;
		this->level->init();
	}

	void run()
	{
		std::chrono::time_point<std::chrono::steady_clock> t1 = std::chrono::high_resolution_clock::now();
		while (window.isOpen())
		{
			auto t2 = std::chrono::high_resolution_clock::now();
			std::chrono::duration<float> duration = t2 - t1;
			float dt = duration.count() * 1000.0f;
			t1 = t2;

			// Input Handling
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			// Update
			level->update(dt);

			// Render
			window.clear(sf::Color(255)); // Render Begin
			level->render(window);
			window.display(); // Render End
		}
	}
};


int main()
{
	Game game("My Game", 800, 600);
	Level level;
	game.attachLevel(&level);
	game.run();
	return 0;
}