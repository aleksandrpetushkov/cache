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
	FileReader rd(&dataFile);
	Cache<string, string> cache(rd);

	try
	{

		for (unsigned int i = 1; i <=30 ;++i)
		{
			std::cout << "key" << " - " << i << " = " << cache[to_string(i)] << endl;

		}

		cin.get();
		for (unsigned int i = 1; i <= 40; ++i)
		{
			std::cout << "key" << " - " << i << " = " << cache[to_string(i)] << endl;

		}
		cin.get();


	}
	catch (const range_error  &e)
	{
		cerr << e.what() << endl;
		cin.get();
	}
}