#pragma once

#include <vector>

#include <SFML/System.hpp>

class Level
{
private:
	std::vector<sf::Vector2i> *m_tiles;

public:
	Level() {
		m_tiles = new std::vector<sf::Vector2i>;
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < 10; ++j)
			{
				m_tiles->push_back(sf::Vector2i(j, i));
			}
		}
	}

	~Level();
};
