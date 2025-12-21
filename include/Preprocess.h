#pragma once
#include<iostream>
#include<string>


using namespace std;
//使用聚合：Preprocess是一个聚合类
class Preprocess
{
public:
	string remove_punctuation(string sentence);//去除标点符号
	string To_lower(string sentence);//全部字母转为小写

};