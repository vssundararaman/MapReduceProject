#pragma once

#ifdef FILEMANAGEMENT_H
#define FILEMANAGEMENT_H __declspec(dllexport)
#else
#define FILEMANAGEMENT_H __declspec(dllimport)
#endif

#include <filesystem>
#include <string>
#include <fstream>
#include <stdio.h>

class FileManagement
{
public:
	static void readFile(const std::filesystem::path& filename);
	static void writeInterFile();
	static void writeOutputFile();
	static bool checkDir(std::filesystem::path& p);
	static void iterateFiles(std::filesystem::path& p);
	static void pushReduce(std::filesystem::path& p);
	static void intermediateWrite(std::string key, int value);
	static void outputWrite(std::string key, int value);
	static void createOutput(std::filesystem::path& p);
	static void setIntermediatePath(std::filesystem::path& p);
	static void setOutputPath(std::filesystem::path& p);
};
