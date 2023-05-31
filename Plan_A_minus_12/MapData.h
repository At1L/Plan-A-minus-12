#pragma once
#include <string>
struct MapData
{
	std::string tilesheet = "";
	std::string name = "";
	int version = 0;
	int tileWidth = 0;
	int tileHeight = 0;
	int scaleX = 0;
	int scaleY = 0;
	int dataLength = 0;
	int* data = nullptr;
};