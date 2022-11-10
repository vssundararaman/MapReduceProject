#include "Reduce.h"
#include "pch.h"
#include "FileManagement.h"
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
#include <stdio.h>

using namespace std;

// no file io
void exportAll(string key, int result)
{
	// write result out to the output directory
	FileManagement::outputWrite(key, result);
}

// reads out (string: the word, [1,1,1,1]), passes in "the word" and 4 to export to output file
void reduce(string key, int iterator)
{
	int sum = iterator;

	exportAll(key, sum);

	FileManagement::writeOutputFile();
}