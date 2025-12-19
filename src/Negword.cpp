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
	std::ifstream file("negative_words.txt", ios::in);
	string element;
	while (file >> element)
	{
		neg_list.insert(element);
	}
}