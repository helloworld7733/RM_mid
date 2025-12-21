#include<iostream>
#include<string>
#include"Tokenizer.h"
#include<fstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<string> Tokenizer::Tokenizer_to_words(string text)//分词
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

void Tokenizer::construct_datatable()//构建停用词表
{
	std::ifstream file("D:/RM_mid/data/stopword.txt", ios::in);
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
	//在停用词表里查找，如果是停用词，则去除该单词（对立场检测无用）
	for (int i = 0; i < src_arr.size(); i++)
	{
		if (st_list.count(src_arr[i]) == 0)//不是停用词
		{
			dest_arr.push_back(src_arr[i]);
		}
	}
	return dest_arr;
}

void Tokenizer::check_neg(vector<string> arr, unordered_set<string> neg_list)
{
	//检查是否有负面词，如not,no等，如果有，则将句子立场检测情况翻转
	for (auto e : arr)
	{
		if (neg_list.count(e) != 0)
		{
			flag_neg = true;
			return;
		}
		if (e.size()>=2&&e[e.size() - 2] == 39&& e[e.size() - 1]=='t'&& e[e.size() - 3]=='n')//检测n't
		{
			flag_neg = true;
			return;
		}
	}
}