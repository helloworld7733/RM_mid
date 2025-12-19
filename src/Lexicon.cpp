#include<iostream>
#include<string>
#include"Lexicon.h"
using namespace std;
#include<fstream>
#include<unordered_map>

void Lexicon::construct_datatable()
{
	//先将词表单词构建哈希表，方便后续快速查找
	std::ifstream file("AFINN-en-165.txt", ios::in);
	string data;
	while (getline(file, data))
	{
		int i = 0;
		string word;
		while (data[i] != 32&&data[i]!='\t')
		{
			word += data[i];
			i++;
		}
		for (int ii = 0; ii < 2&& data[i] != '\t'; ii++)//考虑短语（所有短语长度<=3）
		{
			while (data[i] == ' ') i++;
			if (data[i] >= 'a' && data[i] <= 'z')//说明是短语
			{
				word += '_';
				while (data[i] != '\t'&& data[i] != ' ')
				{
					word += data[i];
					i++;
				}
			}
			else break;
		}
		while (data[i] =='\t') i++;
		string num;
		while (i < data.size())
		{
			num += data[i];
			i++;
		}
		int val = stoi(num);
		mp[word] = val;
	}
}