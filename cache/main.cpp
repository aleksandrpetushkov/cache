#include "FileReader.h"
#include "Cache.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>


using namespace std;

int main()
{


	fstream dataFile;
	dataFile.open("data.txt", ios::in);
	FileReader<string, string, fstream> rd(dataFile);
	Cache<string, string> cache(rd);
	string k="1";

	cache.reset();
	try
	{
		std::cout << "key = " << cache[k] << std::endl;
	}
	catch (const range_error & e)
	{
		cerr << e.what << endl;
	}
	

	/*
	char buffer[80];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%A, %B %d, %Y %I:%M:%S";
	strftime(buffer, 80, format, timeinfo);
	cout << "Current Datetime: " << buffer << endl << timeinfo << endl << seconds << endl;
	cin.get();
	return 0;
	*/
}