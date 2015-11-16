#include <map>


template< typename K, typename V, size_t limit = 1024> class Cache : public IReader<K, V>
{
public:
	
	IReader *fileStream;
	Cache(IReader & _file_reader)
	{
		
		fileStream = _file_reader;
	}
	
	void reset(void)
	{

		massKV.clear();
		massTK.clear();
		
	}


	virtual V operator[](const K & key)
	{
		
	}
	

protected:

	map<K, V> massKV;
	map<time_t, K> massTK;
};