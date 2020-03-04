#ifndef LEVEL_H
#define LEVEL_H

#include <string>

class Level
{
public:
	bool Load(const std::string& filename);

private:
	int width;
	int height;
	int tileWidth;
	int tileHeight;
};

#endif