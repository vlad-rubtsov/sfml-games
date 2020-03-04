#include "Level.h"

#include "TinyXML/tinyxml.h"
#include <iostream>

#define DEBUG 1

bool Level::Load(const std::string& filename)
{
	TiXmlDocument levelFile(filename.c_str());

	// Загружаем XML-карту
    if(!levelFile.LoadFile())
    {
        std::cout << "Loading level \"" << filename << "\" failed." << std::endl;
        return false;
    }

    const TiXmlElement* map = levelFile.FirstChildElement("map");

	// TODO: Add check for map version

	// Пример карты: <map version="1.0" orientation="orthogonal"
	// width="10" height="10" tilewidth="34" tileheight="34">

	map->Attribute(std::string("width"), &width);
	map->Attribute(std::string("height"), &height);
	map->Attribute(std::string("tilewidth"), &tileWidth);
	const std::string* s = map->Attribute(std::string("tileheight"));
	tileHeight = std::stoi(*s);

#ifdef DEBUG
	std::cout << "width: " << width << std::endl;
	std::cout << "height: " << height << std::endl;
	std::cout << "tile width: " << tileWidth << std::endl;
	std::cout << "tile height: " << tileHeight << std::endl;
#endif

	return true;
}
