#include "IReader.h"
//#include <string>

template<typename K, typename V, typename _S> class FileReader : public IReader<K, V>
{
public:
	virtual V operator[](const K & key)
	{
		
	}
	FileReader(_S &is)
	{
		_stream = is;
	}
protected:
	_S _stream;
};
