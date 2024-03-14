#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"
#include "level.h"

class Renderer
{
private:
	sf::RenderWindow *m_window;

public:
	Renderer();
	Renderer(int width, int heigth, const std::string& title);
	~Renderer();

	void renderLevel(const Level& lvl);
};

