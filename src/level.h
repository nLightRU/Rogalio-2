#ifndef _LEVEL_H_
#define _LEVEL_H_
#include <vector>
#include <SFML/System.hpp>

class Level
{
private:
	std::vector<sf::Vector2f> m_tiles;
public:
	Level();
	~Level();
};
#endif // _LEVEL_H_
