#include<iostream>
#include<string>
#include"StanceDetection.h"
#include"Preprocess.h"
#include"Lexicon.h"
#include"Tokenizer.h"
#include<fstream>
#include<unordered_map>
using namespace std;

unordered_map<string, int>mp;

void showmenu()
{
	cout << "欢迎使用立场检测系统，请选择您的输入方式 (1/2)：" << endl;
	cout << "1. 控制台输入" << endl;
	cout << "2. 文件读入" << endl;

}
void Stance_analysis(string s)
{
	//第一步：预处理
	//去除标点符号
	Preprocess process_obj;
	string s_nop=process_obj.remove_punctuation(s);

	//全部字符转小写
	string s_lower = process_obj.To_lower(s_nop);

	//去除常见停用词
	string s_clean = process_obj.remove_stopwords(s_lower);

	//第二步：分词
	char arr[110] = { 0 };//用于存放分词后的单词
	Tokenizer tokenizer_obj;
	tokenizer_obj.Tokenizer_to_words(s_clean,arr);

	//第三步：查找词典的哈希表，计算句子得分，进行立场检测
	StanceDetection stancedetection_obj;
	int score = stancedetection_obj.cal_score(arr);
	stancedetection_obj.classifier(score);


}
int main()
{
	//初始化，预先构建词表空间
	Lexicon lexicon_obj;
	lexicon_obj.construct_English_lexicon(mp);
	
	while(1)
	{
		showmenu();
		int choice;
		cin >> choice;
		StanceDetection obj;
		string s;//用来存放待检测文本
		if (choice == 1)
		{
			cout << "输入您的文本：(不超过100词)" << endl;
			cin >> s;
		}
		else
		{
			cout << "请输入完整的文件名：" << endl;
			string file_name; cin >> file_name;
			std::ifstream file(file_name, ios::in);
			getline(file, s);
		}
		Stance_analysis(s);
		cout << "本次立场检测结束，请问您是否还想继续？(y/n)" << endl;
		char c; cin >> c;
		if (c == 'n') break;
	}
	cout << "程序结束!" << endl;
	return 0;
}