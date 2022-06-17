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



int automate[20][256];
int correct_flag = 1;
vector<Token_List> Token;
vector<List> I_List;
vector<List> C_List;
vector<List> K_List;
vector<List> P_List;
vector<List> CH_List;
vector<List> ST_List;

void initialize_Token(vector<Token_List>& Token)
{
    Token.push_back({ "Token",0,"Token",0 });
}

void initialize_K_List(vector<List>& K_List)
{
    K_List.push_back({ 2,0,"K_List" });
    K_List.push_back({ 1,0,"int" });
    K_List.push_back({ 2,0,"float" });
    K_List.push_back({ 3,0,"char" });
    K_List.push_back({ 4,0,"void" });
    K_List.push_back({ 5,0,"if" });
    K_List.push_back({ 6,0,"else" });
    K_List.push_back({ 7,0,"swich" });
    K_List.push_back({ 8,0,"case" });
    K_List.push_back({ 9,0,"for" });
    K_List.push_back({ 10,0,"do" });
    K_List.push_back({ 11,0,"while" });
    K_List.push_back({ 12,0,"continue" });
    K_List.push_back({ 13,0,"break" });
    K_List.push_back({ 14,0,"default" });
    K_List.push_back({ 15,0,"sizeof" });
    K_List.push_back({ 16,0,"return" });
    K_List.push_back({ 17,0,"cout" });
    K_List.push_back({ 18,0,"cin" });
}

void initialize_P_List(vector<List>& P_List)
{
    P_List.push_back({ 3,0,"P_List" });
    P_List.push_back({ 1,0,">=" });
    P_List.push_back({ 2,0,"<=" });
    P_List.push_back({ 3,0,"==" });
    P_List.push_back({ 4,0,"=" });
    P_List.push_back({ 5,0,">" });
    P_List.push_back({ 6,0,"<" });
    P_List.push_back({ 7,0,"+" });
    P_List.push_back({ 8,0,"-" });
    P_List.push_back({ 9,0,"*" });
    P_List.push_back({ 10,0,"/" });
    P_List.push_back({ 11,0,"{" });
    P_List.push_back({ 12,0,"}" });
    P_List.push_back({ 13,0,"," });
    P_List.push_back({ 14,0,";" });
    P_List.push_back({ 15,0,"(" });
    P_List.push_back({ 16,0,")" });
    P_List.push_back({ 17,0,"[" });
    P_List.push_back({ 18,0,"]" });
}

void initialize_I_List(vector<List>& I_List)
{
    I_List.push_back({ 0,0,"I_List" });
}

void initialize_C_List(vector<List>& C_List)
{
    C_List.push_back({ 1,0,"C_List" });
}


void initialize_CH_List(vector<List>& CH_List)
{
    CH_List.push_back({ 4,0,"CH_List" });
}

void initialize_ST_List(vector<List>& ST_List)
{
    ST_List.push_back({ 5,0,"ST_List" });
}

void initialize_automate(int automate[20][256])
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            automate[i][j] = 0;
        }
    }
    // 1的状态转换
    for (int i = 65; i <= 90; i++)
    {
        automate[1][i] = 2;
        automate[1][i + 32] = 2;
    }
    for (int i = 49; i <= 57; i++)
    {
        automate[1][i] = 3;
    }
    automate[1][48] = 10;  // 0
    automate[1][60] = 13;  //<
    automate[1][61] = 13;  //=
    automate[1][62] = 13;  //>
    automate[1][42] = 13;  //*
    automate[1][47] = 13;  // /
    automate[1][40] = 13;  //(
    automate[1][41] = 13;  //)
    automate[1][59] = 13;  //;
    automate[1][123] = 13; //{
    automate[1][125] = 13; //}
    automate[1][44] = 13;  //,
    automate[1][43] = 15;  //+
    automate[1][45] = 17;  //-
    //automate[1]['\t'] = 1;//Tab键
    //automate[1][' '] = 1;
    // 2的状态转化
    for (int i = 65; i <= 90; i++)
    {
        automate[2][i] = 2;
        automate[2][i + 32] = 2;
    }
    for (int i = 48; i <= 57; i++)
    {
        automate[2][i] = 2;
    }
    // 3的状态转化
    for (int i = 48; i <= 57; i++)
    {
        automate[3][i] = 3;
    }
    automate[3][46] = 4;
    automate[3][101] = 6;
    // 4的状态转化
    for (int i = 48; i <= 57; i++)
    {
        automate[4][i] = 5;
    }
    // 5的状态转化
    for (int i = 48; i <= 57; i++)
    {
        automate[5][i] = 5;
    }
    automate[5]['e'] = 6;
    // 6的状态转化
    for (int i = 49; i <= 57; i++)
    {
        automate[6][i] = 7;
    }
    automate[6][45] = 8;
    automate[6][43] = 8;
    // 7的状态转化
    for (int i = 48; i <= 57; i++)
    {
        automate[7][i] = 7;
    }
    // 8的状态转化
    for (int i = 49; i <= 57; i++)
    {
        automate[8][i] = 9;
    }
    // 9的状态转化
    for (int i = 48; i <= 57; i++)
    {
        automate[9][i] = 9;
    }
    // 10的状态转化
    automate[10][120] = 11;
    automate[10][46] = 4;
    // 11的状态转化
    for (int i = 49; i <= 57; i++)
    {
        automate[11][i] = 12;
    }
    for (int i = 65; i <= 90; i++)
    {
        automate[11][i] = 12;
        automate[11][i + 32] = 12;
    }
    // 12的状态转化
    for (int i = 48; i <= 57; i++)
    {
        automate[12][i] = 12;
    }
    for (int i = 65; i <= 90; i++)
    {
        automate[12][i] = 12;
        automate[12][i + 32] = 12;
    }
    // 13的状态转化
    automate[13][61] = 14;
    // 15的状态转化
    automate[15][43] = 16;
    // 17的状态转化
    automate[17][45] = 18;
}

void scanner(string s)
{
    s = s + '#';
    unsigned int loc1 = 0, loc2 = 0;
    int state;
    int last_state;
    while (correct_flag == 1 && s[loc1] != '#')
    {
        state = 1;
        while (s[loc1] == ' ' || s[loc1] == '\t') //空格继续读取
        {
            loc1++;
            loc2++;
        }
        if (s[loc1] == '\'') //字符判断
        {
            loc2++;
            while (s[loc2] != '\'')
            {
                loc2++;
            }
            if (loc2 - loc1 != 2)
            {
                correct_flag = 0;
                break;
            }
            string now_string;
            now_string.append(s, loc1 + 1, loc2 - loc1 - 1);
            int ct_number = 1;
            while (ct_number != CH_List.size() && P_List[ct_number].s.compare(now_string) != 0)
            {
                ct_number++;
            }
            if (ct_number == CH_List.size())
            {
                CH_List.push_back({ ct_number,0,now_string });
                Token.push_back({ now_string,4,"CH",ct_number });
            }
            else
            {
                Token.push_back({ now_string,4,"CH",ct_number });
            }
            loc2++;
            loc1 = loc2;
            if (s[loc2] != ' ' && s[loc2] != '=' && s[loc2] != '<' && s[loc2] != '>' && s[loc2] != '*' && s[loc2] != '/' && s[loc2] != '(' && s[loc2] != ')' && s[loc2] != ';' && s[loc2] != '{' && s[loc2] != '}' && s[loc2] != '#' && s[loc2] != '+' && s[loc2] != '-' && s[loc2 - 1] != ',')
            {
                correct_flag = 0;
            }
            continue;
        }
        else if (s[loc1] == '\"') //字符串判断
        {
            loc2++;
            while (s[loc2] != '\"')
            {
                loc2++;
            }
            string now_string;
            now_string.append(s, loc1 + 1, loc2 - loc1 - 1);
            int st_number = 1;
            while (st_number != ST_List.size() && ST_List[st_number].s.compare(now_string) != 0)
            {
                st_number++;
            }
            if (st_number == ST_List.size())
            {
                ST_List.push_back({ st_number,0,now_string });
                Token.push_back({ now_string,5,"ST",st_number });
            }
            else
            {
                Token.push_back({ now_string,5,"ST",st_number });
            }
            loc2++;
            loc1 = loc2;
            if (s[loc2] != ' ' && s[loc2] != '=' && s[loc2] != '<' && s[loc2] != '>' && s[loc2] != '*' && s[loc2] != '/' && s[loc2] != '(' && s[loc2] != ')' && s[loc2] != ';' && s[loc2] != '{' && s[loc2] != '}' && s[loc2] != '#' && s[loc2] != '+' && s[loc2] != '-' && s[loc2] != ',')
            {
                correct_flag = 0;
            }
            continue;
        }
        char now_char;
        while (state != 0) //有限自动机状态转化
        {
            now_char = s[loc2];
            last_state = state;
            state = automate[state][(int)now_char];
            loc2++;
        }
        string now_string;
        now_string.append(s, loc1, loc2 - loc1 - 1);
        switch (last_state)
        {
        case 2: //关键字、标识符
        {
            int k_number = 1;
            while (k_number != K_List.size() && now_string.compare(K_List[k_number].s) != 0)
            {
                k_number++;
            }
            if (k_number != K_List.size())
            {
                Token.push_back({ now_string,2,"K",k_number });
            }
            else
            {
                int i_number = 1;
                while (i_number != I_List.size() && now_string.compare(I_List[i_number].s) != 0)
                {
                    i_number++;
                }
                if (i_number != I_List.size())
                {
                    Token.push_back({ now_string,0,"I",i_number });
                }
                else
                {
                    I_List.push_back({ i_number,0,now_string });
                    Token.push_back({ now_string,0,"I",i_number });
                }
            }
            if (s[loc2 - 1] != ' ' && s[loc2 - 1] != '=' && s[loc2 - 1] != '<' && s[loc2 - 1] != '>' && s[loc2 - 1] != '*' && s[loc2 - 1] != '/' && s[loc2 - 1] != '(' && s[loc2 - 1] != ')' && s[loc2 - 1] != ';' && s[loc2 - 1] != '{' && s[loc2 - 1] != '}' && s[loc2 - 1] != '#' && s[loc2 - 1] != '+' && s[loc2 - 1] != '-' && s[loc2 - 1] != ',')
            {
                correct_flag = 0;
            }
            break;
        }
        case 3: //整数
        case 10:
        case 12:
        {
            int C1_number = 1;
            while (C1_number != C_List.size() && now_string.compare(C_List[C1_number].s) != 0)
            {
                C1_number++;
            }
            if (C1_number == C_List.size())
            {
                C_List.push_back({ C1_number,0,now_string });
                Token.push_back({ now_string,1,"C",C1_number });
            }
            else
            {
                Token.push_back({ now_string,1,"C",C1_number });
            }
            if (s[loc2 - 1] != ' ' && s[loc2 - 1] != '=' && s[loc2 - 1] != '<' && s[loc2 - 1] != '>' && s[loc2 - 1] != '*' && s[loc2 - 1] != '/' && s[loc2 - 1] != '(' && s[loc2 - 1] != ')' && s[loc2 - 1] != ';' && s[loc2 - 1] != '{' && s[loc2 - 1] != '}' && s[loc2 - 1] != '#' && s[loc2 - 1] != '+' && s[loc2 - 1] != '-' && s[loc2 - 1] != ',')
            {
                correct_flag = 0;
            }
            break;
        }
        case 5: //浮点数
        case 7:
        case 9:
        {
            int C2_number = 1;
            while (C2_number != C_List.size() && now_string.compare(C_List[C2_number].s) != 0)
            {
                C2_number++;
            }
            if (C2_number == C_List.size())
            {
                C_List.push_back({ C2_number,0,now_string });
                Token.push_back({ now_string,1,"C",C2_number });
            }
            else
            {
                Token.push_back({ now_string,1,"C",C2_number });
            }
            if (s[loc2 - 1] != ' ' && s[loc2 - 1] != '=' && s[loc2 - 1] != '<' && s[loc2 - 1] != '>' && s[loc2 - 1] != '*' && s[loc2 - 1] != '/' && s[loc2 - 1] != '(' && s[loc2 - 1] != ')' && s[loc2 - 1] != ';' && s[loc2 - 1] != '{' && s[loc2 - 1] != '}' && s[loc2 - 1] != '#' && s[loc2 - 1] != '+' && s[loc2 - 1] != '-' && s[loc2 - 1] != ',')
            {
                correct_flag = 0;
            }
            break;
        }
        case 13: //界符
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        {
            int p_number = 1;
            while (now_string.compare(P_List[p_number].s) != 0)
            {
                p_number++;
            }
            Token.push_back({ now_string,3,"P",p_number });
            break;
        }
        default:
            correct_flag = 0;
            break;
        }
        loc1 = --loc2;
    }
}
//
//void HEX_to_DEC(vector<List> &C1_List) // 16进制转10进制函数
//{
//    PNode p = C1_List->next;
//    while (p != nullptr)
//    {
//        if (p->s[0] == '0')
//        {
//            int number = 0;
//            for (unsigned int i = 3; i <= p->s.length(); i++)
//            {
//                int now_number = 0;
//                switch (p->s[i - 1])
//                {
//                case '0':
//                case '1':
//                case '2':
//                case '3':
//                case '4':
//                case '5':
//                case '6':
//                case '7':
//                case '8':
//                case '9':
//                    now_number = p->s[i - 1] - 48;
//                    break;
//                case 'a':
//                case 'b':
//                case 'c':
//                case 'd':
//                case 'e':
//                    now_number = p->s[i - 1] - 87;
//                    break;
//                }
//                number = number * 16 + now_number;
//            }
//            p->number = number;
//        }
//        else
//        {
//            int number = 0;
//            for (unsigned int i = 1; i <= p->s.length(); i++)
//            {
//                int now_number = 0;
//                switch (p->s[i - 1])
//                {
//                case '0':
//                case '1':
//                case '2':
//                case '3':
//                case '4':
//                case '5':
//                case '6':
//                case '7':
//                case '8':
//                case '9':
//                    now_number = p->s[i - 1] - 48;
//                    break;
//                }
//                number = number * 10 + now_number;
//            }
//            p->number = number;
//        }
//        p = p->next;
//    }
//}

void create_List()
{
    initialize_K_List(K_List);
    initialize_P_List(P_List);
    initialize_I_List(I_List);
    initialize_C_List(C_List);
    initialize_CH_List(CH_List);
    initialize_ST_List(ST_List);
    initialize_Token(Token);
    initialize_automate(automate);
    cout << "请输入文件名：";
    string filename;
    cin >> filename;
    ifstream ifs;
    ifs.open(filename, ios::in);
    if (!ifs.is_open())
    {
        cout << "打开文件失败" << endl;
    }
    string s;
    while (getline(ifs, s))
    {
        cout << s << endl;
        scanner(s);
    }
    ifs.close();
    ofstream ofs;
    ofs.open("tokenanlz.txt", ios::out);
    for (int i = 1; i < Token.size(); i++)
    {
        if (Token[i].type_flag == 2 || Token[i].type_flag == 3)
            ofs << Token[i].type_flag << endl << Token[i].number << endl;
        else
            ofs << Token[i].type_flag << endl << Token[i].word << endl;
    }
    cout << endl << endl<< "Token" << endl;
    cout << "类型号" << '\t' << "类型名" << '\t' << "单词" << endl;
    for (int i = 1; i < Token.size(); i++)
    {
            cout << Token[i].type_flag << '\t' << Token[i].type_name<<'\t'<<Token[i].word << endl;
    }
    ofs.close();
}