template<typename K, typename V>
class IReader
{
public:
	virtual V operator[](const K & key) = 0;
};