#pragma once
#include<iostream>
#include<string>

using namespace std;

//接口类，用于后续创建构建停用词表和情感词表空间
class Datatable
{
public:
	virtual void construct_datatable() = 0;
};