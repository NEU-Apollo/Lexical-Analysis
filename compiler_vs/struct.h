#pragma once
#include <string>
#include<vector>
#include <iostream>
#include <fstream>
using namespace std;


typedef struct Token_List
{
    string word;        //�˽��ĵ���
    int type_flag;      //�˽�㵥�ʵ����ͱ��,�׽���Ž�����
    string type_name;   //�˽�㵥�ʵ���������
    int number;         //��ǰ�����ڶ�Ӧ���ͱ��еı��
} Token_List;

//I_List 0 ��ʶ����
//C_List 1 ������
//K_List 2 �ؼ��ֱ�
//P_List 3 �����
//CT_LIst 4 �ַ���
//ST_List 5 �ַ�����


typedef struct List
{
    int num;        //ͷ�ڵ��¼��Ӧflagֵ����������¼���
    int number = 0; //�������������Ľ�㣬���¼��ֵ�Ĵ�С
    string s;       //ͷ�ڵ��¼��������������¼��������
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

