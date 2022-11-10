#pragma once

#ifdef REDUCE_H
#define REDUCE_H __declspec(dllexport)
#else
#define REDUCE_H __declspec(dllimport)
#endif

#include <iostream>
#include <vector>
#include <iterator>
#include <stdio.h>
class Reduce
{
public:

	static void exportAll(std::string key, int result);
	static void reduce(std::string key, int iterator);

};
