#include "pch.h"
#include "FileManagement.h"
#include "Reduce.h"
#include <iostream>
#include <stdio.h>


using namespace std;

filesystem::path interPath;
filesystem::path outerPath;
vector<pair<string, int>> inter_count;
vector<pair<string, int>> outer_count;

// check directory if it exists, and if it does, continue to parse files
// read files from input directory and feed into map
void FileManagement::readFile(const filesystem::path& filename)
{
	string line;
	fstream file;
	file.open(filename);

	while (!file.eof())
	{
		getline(file, line);
		//Map::mapFile(filename.string(), line);
	}
}

// function that creates and writes to a file in given directory, will call from reduce class
void FileManagement::writeInterFile()
{
	fstream output;
	output.open(interPath);
	sort(inter_count.begin(), inter_count.end());

	for (auto const& pair : inter_count) {
		output << pair.first << ", " << pair.second << "\n";
	}
}

// writes to the output file.
void FileManagement::writeOutputFile()
{
	fstream output;
	output.open(outerPath);

	for (auto const& pair : outer_count) {
		output << pair.first << ", " << pair.second << "\n";
	}
}

// error check if directory input is valid
bool FileManagement::checkDir(filesystem::path& p)
{
	if (!filesystem::exists(p))
	{
		cout << "The file directory does not exist. Try again. \n";
		return false;
	}
	else
		return true;

}

// iterates through files in input directory
void FileManagement::iterateFiles(filesystem::path& p)
{
	if (filesystem::is_empty(p))
		cout << "There are no files in the directory";
	else
	{
		for (auto const& dir_entry : filesystem::directory_iterator(p))
		{
			cout << dir_entry.path() << '\n';
			readFile(dir_entry.path());
		}
	}
}

// similar to readfile to push to reduce
void FileManagement::pushReduce(filesystem::path& p)
{
	string temp;
	vector<string> count;

	fstream file;
	file.open(p);

	// parses file
	while (!file.eof())
	{
		string noCount;
		getline(file, temp);
		noCount = temp.substr(0, temp.find(", 1"));
		count.push_back(noCount);
	}

	// pushes results to reduce
	int sum = 1;
	for (int i = 0; i < count.size() - 1; i++)
	{
		if (count[i] == count[i + 1])
		{
			sum++;
		}
		else
		{
			//Reduce::reduce(count[i], sum);
			sum = 1;
		}
	}
}

// called by map to push into class vector for writing to output file
void FileManagement::intermediateWrite(string key, int value)
{
	inter_count.push_back(make_pair(key, value));
}

// called by the reduce 
void FileManagement::outputWrite(string key, int value)
{
	outer_count.push_back(make_pair(key, value));
}

// creates an output file in the given path directory
void FileManagement::createOutput(filesystem::path& p)
{
	p /= "output.txt";
	ofstream outfile;
	outfile.open(p);
}

void FileManagement::setIntermediatePath(filesystem::path& p)
{
	interPath = p;
}

void FileManagement::setOutputPath(filesystem::path& p)
{
	outerPath = p;
}