#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include"DataTable.h"
using namespace std;

class Tokenizer: public Datatable
{
private:
	unordered_set<string>& st_list;
	bool& flag_neg;//若标记为true,则意味着句中有否定词，则立场判断翻转
public:
	Tokenizer(unordered_set<string>& st_list_out,bool& flag_out):st_list(st_list_out),flag_neg(flag_out){}
	vector<string> Tokenizer_to_words(string sentence);//分词，使用vector来存储分词结果
	void construct_datatable();//构建停用词表
	void check_neg(vector<string> arr,unordered_set<string> neg_list);//检查句中是否含有否定词
	vector<string> remove_stopwords(vector<string> src_arr, unordered_set<string> st_list);//去除停用词，即常见的无用词(I,am,he,his...)
};