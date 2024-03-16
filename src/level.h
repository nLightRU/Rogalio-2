#pragma once

#include <vector>

#include <SFML/System.hpp>

class Level
{
private:
	std::vector<sf::Vector2i> *m_tiles;

public:
	Level();
	~Level();
};
