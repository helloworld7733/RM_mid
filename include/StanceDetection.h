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
private:
	unordered_map<string, int>& mp;//情感分析词表
public:
	StanceDetection(unordered_map<string, int>& mp_out):mp(mp_out){}
	int cal_score(vector<string> words_nost);//查表计算对应得分并返回
	void classifier(int score);//根据得分给出立场
};