#include "renderer.h"

#include <SFML/Graphics.hpp>

#include "config.h"
#include "level.h"

Renderer::Renderer() 
{
	m_window = new sf::Window(sf::VideoMode(800, 600), "Rogalio 2", DEFAULT_FLAGS);
}

Renderer::Renderer(int width, int heigth, const std::string& title)
{
	m_window = new sf::Window(sf::VideoMode(width, heigth), 
								title, DEFAULT_FLAGS);
}

Renderer::~Renderer()
{
}

void Renderer::renderLevel(const Level& lvl)
{

}
