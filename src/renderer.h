#pragma once

#include <SFML/Graphics.hpp>

#include "config.h"
#include "level.h"

class Renderer
{
private:
	sf::RenderWindow *m_Window;
	sf::View* m_View;
	sf::Texture* m_floorTexture;
	sf::Texture* m_wallTexture;

	sf::Texture* m_playerTexture;

private:
	bool loadTextures();

public:
	Renderer();
	Renderer(size_t width, size_t heigth, const std::string& title);
	~Renderer();

	void render();
	void renderLevel(const Level& lvl);

	sf::RenderWindow* window() { return m_Window;  }
};

