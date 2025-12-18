#pragma once
#include<iostream>
#include<string>
using namespace std;

class StanceDetection
{
public:
	int cal_score(char* arr);//查表计算对应得分并返回
	void classifier(int score);//根据得分给出立场
};