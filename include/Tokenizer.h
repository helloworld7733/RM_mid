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
public:
	Tokenizer(unordered_set<string>& st_list_out):st_list(st_list_out){}
	vector<string> Tokenizer_to_words(string sentence);
	void construct_datatable();
	vector<string> remove_stopwords(vector<string> src_arr, unordered_set<string> st_list);
};