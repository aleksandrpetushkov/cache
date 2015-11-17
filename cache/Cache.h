#include <time.h>
#include <map>




template<typename K, typename V, size_t limit = 1024> class Cache : public IReader<K, V>
{
public:
	Cache(IReader<std::string, std::string> & _file_reader)
	{
		file_reader = &_file_reader;
	}
	void reset(void)
	{
		massKV.clear();
		massTK.clear();
	}


	virtual V operator[](const K & key)
	{
		
		if(massKV.find(key) != massKV.end()) //Проверяем - имеется ли что-то по поплученному ключу в кэше, если имеется, обновляем время доступа к значению и возвращаем занчение 
		{
			for (std::map<time_t, K>::iterator iter = massTK.begin(); iter != massTK.end(); ++iter)
			{
				if(iter->second==key)
				{
					massTK.erase(iter);
				}
				massTK[time(NULL)] = key;
				cout << "readin from cache\n";
				return massKV[key];
			}
			
		}
		else //если эелемента нет в кэше - пытаемся прочитать его из файла
		{
			//*
			V result="error";

			result = (*file_reader)[key]; // пытаемся получить из файлй значение по ключу, ключ не будет обноружен будет сгенериравано исключение которое должно обработаться в главной программе
			if(massKV.size()>=limit)  // Если кэш полон - удаляем самы старый элемент и записываем полученый.
			{
				//std::map<time_t, K>::iterator iter = massTK.begin();
				massKV.erase(massTK.begin()->second); //Удаляем елемент по ключу время которого самое старое, т.е. он располагается первым в massTK
				massTK.erase(massTK.begin()); //Удаляем самый старый (самы первый) эелемен из massTK
				
			}
			massTK[time(NULL)] = key; //добавляем в массТК новй ключ с тещем временем.
			massKV[key] = result; //Добовляем в массКВ значение по ключу.
			//*/
			cout << "readin from file\n";
			return result;
		}
	}
	void add (std::string s1, std::string st2)
	{
		massKV[s1] = st2;
		massTK[time(NULL)] = s1;
		cout << "all right\n"<<massKV.size()<<endl;

	}
protected:
	IReader *file_reader;
	std::map<K, V> massKV;
	std::map<time_t, K> massTK;
};
/*
template< typename K, typename V, size_t limit = 1024> class Cache : public IReader<K, V>
{
public:


	Cache(IReader  *_file_reader)
	{
		
		file_reader = _file_reader;
	}
	
	void reset(void)
	{

		massKV.clear();
		massTK.clear();
		
	}


	virtual V operator[]( K key)
	{
		
		//*
		if(massKV.find(key)!=massKV.end())
		{
			return massKV[key];
		}
		else
		{
			return *(file_reader)[key];
		}

	}

protected:

	IReader *file_reader;
	std::map<K, V> massKV;
	std::map<K, V> massTK;
};
//*/