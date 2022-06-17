#include <iostream>
#include <string>
using namespace std;

int automate[20][256]; //自动机数组

typedef struct Token
{
    string word;        //此结点的单词
    int type_flag;      //此结点单词的类型编号,首结点存放结点个数
    string type_name;   //此结点单词的类型名称
    int number;         //当前单词在对应类型表中的编号
    struct Token *next; //指向下一个Token结点
} Token, *PToken;

void initializeTokenList(PToken &p) //初始化链表
{
    p = new Token;
    p->type_flag = 0;
    p->next = nullptr;
}

void insertTailTokenList(PToken &p, string t_word, int t_type_flag, int t_number) // Token插入尾结点
{
    p->type_flag++;
    PToken p1 = p;
    while (p1->next != nullptr)
    {
        p1 = p1->next;
    }
    p1 = p1->next = new Token;
    p1->type_flag = t_type_flag;
    p1->number = t_number;
    switch (p1->type_flag)
    {
    case 1:
        p1->type_name = "K";
        break;
    case 2:
        p1->type_name = "P";
        break;
    case 3:
        p1->type_name = "I";
        break;
    case 4:
        p1->type_name = "C1";
        break;
    case 5:
        p1->type_name = "C2";
        break;
    case 6:
        p1->type_name = "CT";
        break;
    case 7:
        p1->type_name = "ST";
        break;
    }
    p1->word = t_word;
    p1->next = nullptr;
    return;
}

typedef struct Node
{
    int num;        //头节点记录对应flag值，其他结点记录编号
    int number = 0; //如果这个是整数的结点，则记录其值的大小
    string s;       //头节点记录类名，其他结点记录具体内容
    struct Node *next;
} Node, *PNode;

void initializeNodeList(PNode &p, int t_num)
{
    p = new Node;
    p->num = t_num;
    switch (p->num)
    {
    case 1:
        p->s = "K";
        break;
    case 2:
        p->s = "P";
        break;
    case 3:
        p->s = "I";
        break;
    case 4:
        p->s = "C1";
        break;
    case 5:
        p->s = "C2";
        break;
    case 6:
        p->s = "CT";
        break;
    case 7:
        p->s = "ST";
        break;
    }
    p->next = nullptr;
}

void insertTailNodeList(PNode &p, string t_s)
{
    PNode p1 = p;
    int last_num = 1;
    while (p1->next != nullptr)
    {
        p1 = p1->next;
        last_num++;
    }
    p1 = p1->next = new Node;
    p1->num = last_num;
    p1->s = t_s;
    p1->next = nullptr;
}

void create_K_NodeList(PNode &p)
{
    initializeNodeList(p, 1);
    insertTailNodeList(p, "int");
    insertTailNodeList(p, "void");
    insertTailNodeList(p, "break");
    insertTailNodeList(p, "float");
    insertTailNodeList(p, "while");
    insertTailNodeList(p, "do");
    insertTailNodeList(p, "struct");
    insertTailNodeList(p, "const");
    insertTailNodeList(p, "case");
    insertTailNodeList(p, "for");
    insertTailNodeList(p, "return");
    insertTailNodeList(p, "if");
    insertTailNodeList(p, "default");
    insertTailNodeList(p, "else");
    insertTailNodeList(p, "char");
    return;
}

void create_P_NodeList(PNode &p)
{
    initializeNodeList(p, 2);
    insertTailNodeList(p, "-");
    insertTailNodeList(p, "/");
    insertTailNodeList(p, "(");
    insertTailNodeList(p, ")");
    insertTailNodeList(p, "==");
    insertTailNodeList(p, "<=");
    insertTailNodeList(p, "<");
    insertTailNodeList(p, "+");
    insertTailNodeList(p, "*");
    insertTailNodeList(p, ">");
    insertTailNodeList(p, "=");
    insertTailNodeList(p, ",");
    insertTailNodeList(p, ";");
    insertTailNodeList(p, "++");
    insertTailNodeList(p, "{");
    insertTailNodeList(p, "}");
    return;
}

void create_I_NodeList(PNode &p)
{
    initializeNodeList(p, 3);
}

void create_C1_NodeList(PNode &p)
{
    initializeNodeList(p, 4);
}

void create_C2_NodeList(PNode &p)
{
    initializeNodeList(p, 5);
}

void create_CT_NodeList(PNode &p)
{
    initializeNodeList(p, 6);
}

void create_ST_NodeList(PNode &p)
{
    initializeNodeList(p, 7);
}

void createAutomate()
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

static PNode K_List;
static PNode P_List;
static PNode I_List;
static PNode C1_List;
static PNode C2_List;
static PNode CT_List;
static PNode ST_List;
static PToken Token_List;
static int correct_flag = 1;

void makeTokenList(string s) //核心部分：构造token序列，单词类序列
{
    s = s + '#';
    unsigned int loc1 = 0, loc2 = 0;
    int state;
    int last_state;
    while (correct_flag == 1 && s[loc1] != '#')
    {
        state = 1;
        if (s[loc1] == ' ') //空格继续读取
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
            PNode temp_p = CT_List->next;
            int ct_number = 1;
            while (temp_p != nullptr && temp_p->s.compare(now_string) != 0)
            {
                temp_p = temp_p->next;
                ct_number++;
            }
            if (temp_p == nullptr)
            {
                insertTailTokenList(Token_List, now_string, 6, ct_number);
                insertTailNodeList(CT_List, now_string);
            }
            else
            {
                insertTailTokenList(Token_List, now_string, 6, ct_number);
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
            PNode temp_p = ST_List->next;
            int st_number = 1;
            while (temp_p != nullptr && temp_p->s.compare(now_string) != 0)
            {
                temp_p = temp_p->next;
                st_number++;
            }
            if (temp_p == nullptr)
            {
                insertTailTokenList(Token_List, now_string, 7, st_number);
                insertTailNodeList(ST_List, now_string);
            }
            else
            {
                insertTailTokenList(Token_List, now_string, 7, st_number);
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
            PNode temp_p = K_List->next;
            int k_number = 1;
            while (temp_p != nullptr && now_string.compare(temp_p->s) != 0)
            {
                temp_p = temp_p->next;
                k_number++;
            }
            if (temp_p != nullptr)
            {
                insertTailTokenList(Token_List, now_string, 1, k_number);
            }
            else
            {
                temp_p = I_List->next;
                int i_number = 1;
                while (temp_p != nullptr && now_string.compare(temp_p->s) != 0)
                {
                    temp_p = temp_p->next;
                    i_number++;
                }
                if (temp_p != nullptr)
                {
                    insertTailTokenList(Token_List, now_string, 3, i_number);
                }
                else
                {
                    insertTailTokenList(Token_List, now_string, 3, i_number);
                    insertTailNodeList(I_List, now_string);
                }
            }
            if (s[loc2 - 1] != ' ' && s[loc2 - 1] != '=' && s[loc2 - 1] != '<' && s[loc2 - 1] != '>' && s[loc2 - 1] != '*' && s[loc2 - 1] != '/' && s[loc2 - 1] != '(' && s[loc2 - 1] != ')' && s[loc2 - 1] != ';' && s[loc2 - 1] != '{' && s[loc2 - 1] != '}' && s[loc2 - 1] != '#' && s[loc2 - 1] != '+' && s[loc2 - 1] != '-' && s[loc2 - 1] != ',')
            {
                correct_flag = 0;
            }
            break;
        }
        case 3: //整数
        case 12:
        {
            PNode temp_p = C1_List->next;
            int C1_number = 1;
            while (temp_p != nullptr && now_string.compare(temp_p->s) != 0)
            {
                temp_p = temp_p->next;
                C1_number++;
            }
            if (temp_p == nullptr)
            {
                insertTailTokenList(Token_List, now_string, 4, C1_number);
                insertTailNodeList(C1_List, now_string);
            }
            else
            {
                insertTailTokenList(Token_List, now_string, 4, C1_number);
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
            PNode temp_p = C2_List->next;
            int C2_number = 1;
            while (temp_p != nullptr && now_string.compare(temp_p->s) != 0)
            {
                temp_p = temp_p->next;
                C2_number++;
            }
            if (temp_p == nullptr)
            {
                insertTailTokenList(Token_List, now_string, 5, C2_number);
                insertTailNodeList(C2_List, now_string);
            }
            else
            {
                insertTailTokenList(Token_List, now_string, 5, C2_number);
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
            PNode temp_p = P_List->next;
            int p_number = 1;
            while (temp_p != nullptr && now_string.compare(temp_p->s) != 0)
            {
                temp_p = temp_p->next;
                p_number++;
            }
            insertTailTokenList(Token_List, now_string, 2, p_number);
            break;
        }
        default:
            correct_flag = 0;
            break;
        }
        loc1 = --loc2;
    }
}

void HEX_to_DEC(PNode &C1_List) // 16进制转10进制函数
{
    PNode p = C1_List->next;
    while (p != nullptr)
    {
        if (p->s[0] == '0')
        {
            int number = 0;
            for (unsigned int i = 3; i <= p->s.length(); i++)
            {
                int now_number = 0;
                switch (p->s[i - 1])
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    now_number = p->s[i - 1] - 48;
                    break;
                case 'a':
                case 'b':
                case 'c':
                case 'd':
                case 'e':
                    now_number = p->s[i - 1] - 87;
                    break;
                }
                number = number * 16 + now_number;
            }
            p->number = number;
        }
        else
        {
            int number = 0;
            for (unsigned int i = 1; i <= p->s.length(); i++)
            {
                int now_number = 0;
                switch (p->s[i - 1])
                {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    now_number = p->s[i - 1] - 48;
                    break;
                }
                number = number * 10 + now_number;
            }
            p->number = number;
        }
        p = p->next;
    }
}

int main()
{
    create_K_NodeList(K_List);
    create_P_NodeList(P_List);
    create_I_NodeList(I_List);
    create_C1_NodeList(C1_List);
    create_C2_NodeList(C2_List);
    create_CT_NodeList(CT_List);
    create_ST_NodeList(ST_List);
    initializeTokenList(Token_List);
    createAutomate();
    string s;
    getline(cin, s);
    makeTokenList(s);
    if (correct_flag == 0)
    {
        cout << "ERROR" << endl;
        return 0;
    }
    cout << "Token :";
    PToken Token_List_p = Token_List->next;
    while (Token_List_p != nullptr)
    {
        cout << "(" << Token_List_p->type_name << " " << Token_List_p->number << ")";
        Token_List_p = Token_List_p->next;
    }
    cout << endl
         << "I :";
    PNode List_p;
    List_p = I_List->next;
    while (List_p != nullptr)
    {
        cout << List_p->s;
        if (List_p->next != nullptr)
        {
            cout << " ";
        }
        List_p = List_p->next;
    }
    cout << endl
         << "C1 :";
    HEX_to_DEC(C1_List);
    List_p = C1_List->next;
    while (List_p != nullptr)
    {
        cout << List_p->number;
        if (List_p->next != nullptr)
        {
            cout << " ";
        }
        List_p = List_p->next;
    }
    cout << endl
         << "C2 :";
    List_p = C2_List->next;
    while (List_p != nullptr)
    {
        cout << List_p->s;
        if (List_p->next != nullptr)
        {
            cout << " ";
        }
        List_p = List_p->next;
    }
    cout << endl
         << "CT :";
    List_p = CT_List->next;
    while (List_p != nullptr)
    {
        cout << List_p->s;
        if (List_p->next != nullptr)
        {
            cout << " ";
        }
        List_p = List_p->next;
    }
    cout << endl
         << "ST :";
    List_p = ST_List->next;
    while (List_p != nullptr)
    {
        cout << List_p->s;
        if (List_p->next != nullptr)
        {
            cout << " ";
        }
        List_p = List_p->next;
    }
}