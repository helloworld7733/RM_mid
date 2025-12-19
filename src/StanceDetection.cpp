#include<iostream>
#include<string>
#include"StanceDetection.h"
#include<fstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

int StanceDetection::cal_score(vector<string> word_arr)
{
	int score = 0;
	int i = 0;
	while(i<word_arr.size())
	{
		bool flag = true;
		//考虑到phrase也属于情感词的缘故，故不仅仅检测单词
		if (i + 2 < word_arr.size())
		{
			string phrase3 = word_arr[i] + "_" + word_arr[i + 1] + "_" + word_arr[i + 2];
			if (mp[phrase3] != 0)
			{
				//优先考虑长度最长的phrase
				score += mp[phrase3];
				i += 3;
				flag = false;//避免后续再次读入分数
			}
		}
		if(flag&&i + 1 < word_arr.size())
		{
			string phrase2 = word_arr[i] + "_" + word_arr[i + 1];
			if (mp[phrase2] != 0)
			{
				score += mp[phrase2];
				i += 2;
				flag = false;
			}
		}
		if(flag)
		{
			string phrase1 = word_arr[i];
			score += mp[phrase1];
			i++;
		}
		
		
		
	}
	return score;
}

void StanceDetection::classifier(int score)
{
	if (score > 0)
	{
		cout << "此段文本的立场为: postive" << endl;

	}
	else if (score < 0)
	{
		cout << "此段文本的立场为: negative" << endl;
	}
	else cout << "此段文本的立场为: neutral" << endl;
}