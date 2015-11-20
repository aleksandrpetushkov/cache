#include <time.h>
#include <map>
#include <vector>
#include <list>


template<typename K, typename V, size_t limit = 30> class Cache : public IReader<K, V>
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
		
		if(massKV.find(key) != massKV.end()) //��������� - ������� �� ���-�� �� ����������� ����� � ����, ���� �������, ��������� ����� ������� � �������� � ���������� �������� 
		{
			for (std::vector<K>::iterator iter = vecK.begin(); iter != vecK.end(); ++iter)
			{
				if(*iter==key)
				{
					vecK.erase(iter);
					vecK.push_back(key);
					cout << "readin from cache - ";
					return massKV[key];

				}
			}
		}
		else //����� - �������� ��������� ��� �� �����
		{
			V result;
			result = (*file_reader)[key]; // �������� �������� �� ���� �������� �� �����, ���� �� ����� ��������� ����� ��������������� ���������� ������� ������ ������������ � ������� ���������
			if(massKV.size()>=limit)  // ���� ��� ����� - ������� ����� ������ ������� � ���������� ����������.
			{
				massKV.erase(*(vecK.begin()));
				vecK.erase(vecK.begin());
			}
			massKV[key] = result;
			vecK.push_back(key);
			cout << "readin from file - ";
			return result;
		}
	}

protected:
	IReader *file_reader;
	std::map<K, V> massKV;
	std::vector<K> vecK;




};