#pragma once
#ifdef EXECUTIVE_H
#define EXECUTIVE_H __declspec(dllexport)
#else
#define EXECUTIVE_H __declspec(dllimport)
#endif

#include <iostream>
#include <filesystem>
#include <map>


namespace MapReduce{

class Executive
{
public:
	static int mapReduce();  
};
}