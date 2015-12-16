#include "FileReader.h"
#include "Cache.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "gtest\gtest.h"

using namespace std;

TEST(Cache, size)  //тест на размер кэша,  создаем кэш на 3 элемента читаем 40 элементом, размер кэша должен быть 3 элемента
{
	fstream dataFile;
	dataFile.open("data.txt", ios::in);
	FileReader rd(&dataFile);
	Cache<string, string, 3> ch(rd);
	string st;
	for (int i = 0; i <= 40;++i)
	{
		st = ch[to_string(i)];
	}
	EXPECT_EQ(3, ch.size());
}



TEST(Cahce, element) // тест на наличие элемента, читаем 40 элементов, 40 элемент должен быть в кэше, а первый элемент нет
{
	fstream dataFile;
	dataFile.open("data.txt", ios::in);
	FileReader rd(&dataFile);
	Cache<string, string, 3> ch(rd);
	string st;
	for (int i = 0; i <= 40; ++i)
	{
		st = ch[to_string(i)];
	}
	
	ASSERT_TRUE(ch.exist(to_string(40))); //40 - есть 
	ASSERT_FALSE(ch.exist(to_string(1))); //1 - нет
}


int main(int argc, char ** argv)
{



	
	fstream dataFile;
	dataFile.open("data.txt", ios::in);
	FileReader rd(&dataFile);
	Cache<string, string, 20> cache(rd);

	try
	{

		for (unsigned int i = 1; i <=10 ;++i)
		{
			std::cout << "key" << " - " << i << " = " << cache[to_string(i)] << endl;

		}
		
		//cout << cache.size() << endl << cache[3] << endl ;
		
		for (unsigned int i = 1; i <= 15; ++i)
		{
			std::cout << "key" << " - " << i << " = " << cache[to_string(i)] << endl;

		}
		cache[to_string(40)];
		::testing::InitGoogleTest(&argc, argv);
		RUN_ALL_TESTS();
		cin.get();


	}
	catch (const range_error  &e)
	{
		cerr << e.what() << endl;
		cin.get();
	}


}