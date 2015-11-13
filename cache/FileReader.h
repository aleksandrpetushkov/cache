#include "IReader.h"


template<typename K, typename V, typename _S> class FileReader : public IReader<K, V>
{
public:




	override std::string operator[](K & key)
	{
		
	}
	
	
	FileReader::FileReader(_S & is)
	{
		_stream = is;
	}
protected:
	_S _stream;
};
