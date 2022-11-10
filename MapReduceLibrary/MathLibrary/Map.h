#pragma once

#ifdef MAP_H
#define MAP_H __declspec(dllexport)
#else
#define MAP_H __declspec(dllimport)
#endif

#include <string>
#include <map>

// map class

class Map
{
public:
	static void mapExport(std::string key, int value);
	static void mapFile(std::string filename, std::string input);
};