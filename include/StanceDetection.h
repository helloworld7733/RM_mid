#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<unordered_map>
#include<unordered_set>
using namespace std;


class StanceDetection
{
public:
	int cal_score(vector<string> words_nost);//查表计算对应得分并返回
	void classifier(int score);//根据得分给出立场
};