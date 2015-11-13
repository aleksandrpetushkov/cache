template< typename K, typename V, size_t limit = 1024> class Cache : public IReader<K, V>
{
public:


	Cache(IReader<K, V> & _file_reader); 
	void reset(void);
	override V operator[](const K & key);


protected:
	

	
};