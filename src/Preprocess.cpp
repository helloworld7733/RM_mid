#include"Preprocess.h"
#include<iostream>
#include<string>

using namespace std;

string Preprocess::remove_punctuation(string text)
{
	string s_dest;//用于存放目标字符串
	for (int i = 0; i < text.size();i++)
	{
		if ((text[i] >= 'a'&& text[i]<='z') || (text[i] >= 'A' && text[i]<='Z')||text[i]==39||text[i]==' ')
		{
			//如果是字母，有效
			s_dest += text[i];
		}
	}
	return s_dest;//不含标点符号
}

string Preprocess::To_lower(string text)
{
	string s_dest;
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] >= 'A' && text[i] <= 'Z')
		{
			s_dest += text[i] + 32;
		}
		else s_dest += text[i];
	}
	return s_dest;//全是小写字母
}

