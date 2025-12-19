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
	vector<string> Tokenizer_to_words(string sentence);
	void construct_datatable();
	void check_neg(vector<string> arr,unordered_set<string> neg_list);
	vector<string> remove_stopwords(vector<string> src_arr, unordered_set<string> st_list);
};