#include<iostream>
#include<string>
#include"StanceDetection.h"
#include"Preprocess.h"
#include"Lexicon.h"
#include"Tokenizer.h"
#include<fstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include <io.h>
using namespace std;

unordered_map<string, int>mp;//情感分析词表：(word/phrase,score)
unordered_set<string> st_list;//停用词表
void showmenu()
{
	cout << "欢迎使用立场检测系统，请选择您的输入方式 (1/2)：" << endl;
	cout << "1. 控制台输入" << endl;
	cout << "2. 文件读入" << endl;

}
bool check_cn(string s)
{
	for (char c : s)
	{
		if (c & 0x80) return true;
	}
	return false;
}
void Stance_analysis(string s)
{
	//第一步：预处理
	//去除标点符号
	Preprocess process_obj;
	string s_nop=process_obj.remove_punctuation(s);

	//全部字符转小写
	string s_lower = process_obj.To_lower(s_nop);

	//第二步：分词
	vector<string> tokenized_words;//用于存放分词后的单词
	Tokenizer tokenizer_obj(st_list);
	tokenized_words=tokenizer_obj.Tokenizer_to_words(s_lower);

	//去除停用词
	vector<string> words_nost;//去除停用词后的分词表
	words_nost = tokenizer_obj.remove_stopwords(tokenized_words, st_list);

	////第三步：查找词典的哈希表，计算句子得分，进行立场检测
	StanceDetection stancedetection_obj(mp);
	int score = stancedetection_obj.cal_score(words_nost);
	stancedetection_obj.classifier(score);

}
int main()
{
	//初始化，预先构建词表空间和停用词表空间
	Lexicon lexicon_obj(mp);
	lexicon_obj.construct_datatable();
	
	Tokenizer stopword_obj(st_list);
	stopword_obj.construct_datatable();

	while(1)
	{
		int choice;
		while(1)
		{
			showmenu();
			cin >> choice;
			cin.ignore();
			if (choice != 1 && choice != 2)
			{
				cout << "Bad input! Input again!" << endl;
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			else break;
		}
		StanceDetection obj(mp);
		string s;//用来存放待检测文本
		if (choice == 1)
		{
			cout << "输入您的英语文本：" << endl;
			while(1)
			{
				getline(cin, s);
				if (check_cn(s))
				{
					cout << "您输入的文本里含有中文字符，请重新输入:" << endl;
				}
				else break;
			}
		}
		else
		{
			cout << "请输入完整的文件名：" << endl;
			while(1)
			{
				string file_name; cin >> file_name;
				if (_access(file_name.c_str(), 0) != 0)
				{
					cout << "您输入了错误的文件名，该文件不存在，请重新输入" << endl;
					continue;
				}
				std::ifstream file(file_name, ios::in);
				getline(file, s);
				if (check_cn(s))
				{
					cout<< "您的文件里含有中文字符，请更换文件:" << endl;
					continue;
				}
				break;
			}
		}
		Stance_analysis(s);
		cout << "本次立场检测结束，请问您是否还想继续？(y/n)" << endl;
		while(1)
		{
			char c; cin >> c;
			cin.ignore();
			if (c == 'n' || c == 'N')
			{
				cout << "程序结束!" << endl;
				return 0;
			}
			else if (c != 'y' && c != 'Y')
			{
				cout << "Bad input! Input again: (y/n)" << endl;
				cin.ignore(INT_MAX, '\n');
				continue;
			}
			break;
		}
	}
	return 0;
}