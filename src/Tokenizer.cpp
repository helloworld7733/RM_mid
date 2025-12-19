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
	vector<string> arr_dest;//ʹ��STL�ﶯ̬�������ȵ�vector����Ϊ���շ��ص��ַ�������
	int i = 0;
	while (i < text.size())
	{
		string element;//ÿ�����������Ԫ��
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

void Tokenizer::construct_datatable()
{
	std::ifstream file("D:/RM_mid/data/stopword.txt", ios::in);
	//ʹ��STL��unordered_set�����ͣ�ôʣ����ں������ٲ���
	string element;
	while (file >> element)
	{
		st_list.insert(element);
	}
}

vector<string> Tokenizer::remove_stopwords(vector<string> src_arr,unordered_set<string> st_list)
{
	vector<string> dest_arr;
	//��ͣ�ôʱ������
	for (int i = 0; i < src_arr.size(); i++)
	{
		if (st_list.count(src_arr[i]) == 0)//����ͣ�ô�
		{
			dest_arr.push_back(src_arr[i]);
		}
	}
	return dest_arr;
}

void Tokenizer::check_neg(vector<string> arr, unordered_set<string> neg_list)
{
	for (auto e : arr)
	{
		if (neg_list.count(e) != 0)
		{
			flag_neg = true;
			return;
		}
		if (e.size()>=2&&e[e.size() - 2] == 39&& e[e.size() - 1]=='t'&& e[e.size() - 3]=='n')//���n't
		{
			flag_neg = true;
			return;
		}
	}
}