#include "IReader.h"
#include <string>
#include <iostream>

class FileReader : public IReader<std::string, std::string>
{
public:
	FileReader(std::istream * _is)
	{
		is = _is;
	}
	virtual std::string operator[](const std::string & key)
	{

		std::string result,tmp;
		while(!(*is).eof())
		{
			std::getline(*is, tmp);
			size_t pos, pos1;
			pos1 = tmp.find_first_of(" ", pos);
			result = tmp.substr(pos, pos1 - pos);
			if(result==key)
			{
				pos = tmp.find_first_not_of(" \t", pos1);
				pos1 = tmp.find_first_of(" \t", pos);
				result = tmp.substr(pos, pos1 - pos);
				return result;
			}
		}
		throw std::range_error("in file no key\n");
	}
protected:
	std::istream *is;
};