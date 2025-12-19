#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include <io.h>
#include"DataTable.h"
using namespace std;

class Negword_list :public Datatable
{
private:
	unordered_set<string>& neg_list;
public:
	Negword_list(unordered_set<string>& neg_out):neg_list(neg_out){}
	void construct_datatable();
};