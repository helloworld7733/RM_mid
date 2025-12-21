#include<iostream>
#include<string>
#include"Negword.h"
#include<fstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include <io.h>
using namespace std;

void Negword_list::construct_datatable()
{
	std::ifstream file("D:/RM_mid/data/negative_words.txt", ios::in);
	string element;
	while (file >> element)
	{
		neg_list.insert(element);//使用set 构建否定词表
	}
}