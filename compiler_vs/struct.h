#pragma once
#include <string>
#include<vector>
#include <iostream>
#include <fstream>
using namespace std;


typedef struct Token_List
{
    string word;        //此结点的单词
    int type_flag;      //此结点单词的类型编号,首结点存放结点个数
    string type_name;   //此结点单词的类型名称
    int number;         //当前单词在对应类型表中的编号
} Token_List;

//I_List 0 标识符表
//C_List 1 常数表
//K_List 2 关键字表
//P_List 3 界符表
//CT_LIst 4 字符表
//ST_List 5 字符串表


typedef struct List
{
    int num;        //头节点记录对应flag值，其他结点记录编号
    int number = 0; //如果这个是整数的结点，则记录其值的大小
    string s;       //头节点记录类名，其他结点记录具体内容
} List;

void initialize_K_List(vector<List>&);
void initialize_P_List(vector<List>&);
void initialize_I_List(vector<List>&);
void initialize_C_List(vector<List>&);
void initialize_CH_List(vector<List>&);
void initialize_ST_List(vector<List>&);
void create_List();
void initialize_Token(vector<Token_List> &);
void scanner(string s);
void initialize_automate(int[20][256]);
//void HEX_to_DEC(vector<List>& C1_List);

