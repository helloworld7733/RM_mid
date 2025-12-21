#pragma once
#include<iostream>
#include<string>

using namespace std;

//接口类，用于后续创建构建停用词表、情感词表和否定词表空间
class Datatable
{
public:
	virtual void construct_datatable() = 0;
};