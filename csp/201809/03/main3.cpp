#include <iostream>
using namespace std;
#include <stdio.h>
#include <string>
#include <string.h>
#include <ctype.h>
#include <vector>

#define MAX_N 101
#define MAX_M 11

struct Tree
{
    string tag;
    string id;
};

int Line_Count = 1;
int Sel_count = 1;
Tree Html_Text[MAX_N];
string selector[MAX_M];

void AddText(char *Text)
{
    string tag = "";
    string id = "";
    int i;
    int len = strlen(Text);
    for(i = 0;i < len;i++)
    {
        if(Text[i] != '.')
            break;
    }
    for(i; i < len;i++)
    {
        if(Text[i] == ' ')
            break;
        else
            tag += tolower(Text[i]);
    }
    for(i++; i < len;i++)
    {
        id += Text[i];
    }
    Html_Text[Line_Count].tag = tag;
    Html_Text[Line_Count].id = id;
    Line_Count++;
}

void AddSelector(char *sel)
{
    selector[Sel_count].assign(sel);
    Sel_count++;
}

bool check(string &s,Tree &t)
{
    int i;
    if(s[0] == '#')
        return (s == t.id);
    else
    {
        if(s.size() != t.tag.size())   
            return false;
        for(i = 0;i < s.size();i++)
            s[i] = tolower(s[i]);
        return (s == t.tag);
    }
}

void Search(int n,int v)
{
    int i;
    vector <int> list;
    string sel = selector[v];
    int count = 0;
    for(i = 1;i <= n;i++)
    {
        if(check(sel,Html_Text[i]))
        {
            list.push_back(i);
            count++;
        }
    }
    cout << count << " ";
    for(i = 0;i < count;i++)
        cout << list[i] << " ";
    cout << endl;
}

int main()
{
    int i;
    int n,m;
    char text[81];
    cin >> n >> m;
    cin.ignore();
    for(i = 1;i <= n;i++)
    {
        cin.getline(text,81);
        AddText(text);
    }
    for(i = 1;i <= m;i++)
    {
        cin.getline(text,81);
        AddSelector(text);
    }
    for(i = 1;i <= m;i++)
    {
        Search(n,i);
    }
    system("pause");
    return 0;
}
