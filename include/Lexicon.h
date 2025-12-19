#pragma once
#include<iostream>
#include<string>
#include<unordered_map>
#include"DataTable.h"
using namespace std;

//继承datatable基类，实现多态
class Lexicon: public Datatable
{
private:
	unordered_map<string, int>& mp;
public:
	Lexicon(unordered_map<string, int>& mp_out): mp(mp_out){}
	void construct_datatable();//利用哈希表构建词表
};