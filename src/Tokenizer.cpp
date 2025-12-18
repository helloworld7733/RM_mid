#include<iostream>
#include<string>
#include"Tokenizer.h"
#include<fstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<string> Tokenizer::Tokenizer_to_words(string text)
{
	vector<string> arr_dest;//使用STL里动态伸缩长度的vector，作为最终返回的字符串数组
	int i = 0;
	while (i < text.size())
	{
		string element;//每个即将存入的元素
		while (text[i] != ' '&&i<=text.size()-1)
		{
			element += text[i];
			i++;
		}
		arr_dest.push_back(element);
		i++;

	}
	return arr_dest;
}

void Tokenizer::construct_stopword_list(unordered_set<string>& st_list)
{
	std::ifstream file("../data/stopword.txt", ios::in);
	//使用STL的unordered_set来存放停用词，便于后续快速查找
	string element;
	while (file >> element)
	{
		st_list.insert(element);
	}
}

vector<string> Tokenizer::remove_stopwords(vector<string> src_arr,unordered_set<string> st_list)
{
	vector<string> dest_arr;
	//在停用词表里查找
	for (int i = 0; i < src_arr.size(); i++)
	{
		if (st_list.count(src_arr[i]) == 0)//不是停用词
		{
			dest_arr.push_back(src_arr[i]);
		}
	}
	return dest_arr;
}
