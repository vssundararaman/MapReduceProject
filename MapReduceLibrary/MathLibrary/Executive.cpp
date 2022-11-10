#include "pch.h"
#include "Executive.h"
#include "FileManagement.h"
#include <iostream>
#include <filesystem>
#include <map>
#include <fstream>

using namespace std;
namespace MapReduce {
	int mapReduce()
	{
		cout << "Enter the directory of the input file: \n";
		string inputPath;
		cin >> inputPath;
		filesystem::path inPath = inputPath;
		bool validIn = FileManagement::checkDir(inPath);
		if (!validIn)
			return 0;

		cout << "Enter the directory of the output file: \n";
		string outputPath;
		cin >> outputPath;
		filesystem::path outPath = outputPath;
		bool validOut = FileManagement::checkDir(outPath);
		if (!validOut)
			return 0;

		cout << "Enter the temporary directory for intermediate files: \n";
		string interPath;
		cin >> interPath;
		filesystem::path intPath = interPath;
		bool validInter = FileManagement::checkDir(intPath);
		if (!validInter)
			return 0;

		cout << "Creating output files in intermediate and output folder... \n";

		intPath /= "output.txt";
		ofstream intOf(intPath);
		FileManagement::setIntermediatePath(intPath);

		outPath /= "output.txt";
		ofstream outOf(outPath);
		FileManagement::setOutputPath(outPath);

		cout << "Starting to parse files in input directory... \n";

		FileManagement::iterateFiles(inPath);

		cout << "Reducing values...\n";

		FileManagement::pushReduce(intPath);

		cout << "The files have been successfully outputted! Closing program... \n";
		return 0;
	}
}