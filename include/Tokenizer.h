#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

class Tokenizer
{
public:
	vector<string> Tokenizer_to_words(string sentence);
	void construct_stopword_list(unordered_set<string>& st_list);
	vector<string> remove_stopwords(vector<string> src_arr, unordered_set<string> st_list);
};