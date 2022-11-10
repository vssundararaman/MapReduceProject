#include "Map.h"
#include "pch.h"
#include "FileManagement.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>


using namespace std;

// calls writeFile to write to temp directory
void mapExport(string key, int value)
{
	FileManagement::intermediateWrite(key, value);
}

void mapFile(string filename, string input)
{
	// remove punctuation, whitespace and capitalization
	locale loc;
	string tokenWord = input;

	// removes capitalization from line
	transform(tokenWord.begin(), tokenWord.end(), tokenWord.begin(), ::tolower);

	// removes punctuation from line
	auto it = std::remove_if(tokenWord.begin(), tokenWord.end(), [](char const& c) {
		return std::ispunct(c);
		});
	tokenWord.erase(it, tokenWord.end());

	stringstream spaceWord(tokenWord);
	string temp;

	// identifies whitespace and pushes word into intermediate map file
	while (spaceWord >> temp)
	{
		mapExport(temp, 1);
	}

	FileManagement::writeInterFile();
	//	words_count.insert(pair<string, int>(tokenWord, 1));
}
