#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>


class Game
{
private:
	const char* m_title;
	size_t m_width, m_height;
	sf::RenderWindow m_window;

public:
	Game();
	Game(const std::string& title, size_t width, size_t height);
	~Game();

	void run();
};

