/********************************************
 * About: csp 201809-3
 * Author: ���
 * Date: 2019-3-11
 ********************************************/
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <ctype.h>
#include <sstream>

#define MAX_N 101
#define MAX_M 11

struct node                             //�ṹ���ĵ���Ԫ������
{
    int level;                          //����
    string tag;                         //��ǩ
    string id;                          //id
    int parent;                         //���ڵ�
};

node nodes[MAX_N];                      //�ṹ���ĵ�
stack <int> Stack;                      //�Ҹ��ڵ�ĸ���ջ

void AddLine(string line,int n)         //���Ԫ��
{
    int level = 0;
    int i;
    int top;
    string tag = "";
    string id = "";
    int parent = 0;
    for(i = 0;i < line.size();i++)      //����    
    {
        if(line[i] == '.')
            level++;
        else
            break;
    }
    nodes[n].level = level;
    for(i;i < line.size();i++)          //���ǩ
    {
        if(line[i] != ' ')
            tag += tolower(line[i]);
        else
            break;
    }
    nodes[n].tag = tag;
    for(i++;i < line.size();i++)        //��id
    {
        id += line[i];
    }
    nodes[n].id = id;
    while(!Stack.empty()){              //�󸸽ڵ�
        top = Stack.top();
        if(nodes[top].level < level)
            break;
        Stack.pop();
    }
    Stack.push(n);
    nodes[n].parent = top;
}

bool check(string selector,int n)       //���ѡ������Ԫ���Ƿ�ƥ��
{
    if(selector[0] == '#')              //idѡ����
    {
        return (selector == nodes[n].id);
    }
    else                                //��ǩѡ����
    {
        if(selector.size() != nodes[n].tag.size())
            return false;
        for(int i = 0;i < selector.size();i++)
        {
            if(tolower(selector[i]) != nodes[n].tag[i])
                return false;
        }
        return true;
    }
}

void Search(string selector,int n)
{
    vector <int> ans;
    int i;
    if(selector.find(' ') == string::npos)  //���Ǻ��ѡ����
    {
        for(i = 1;i <= n;i++)
        {
            if(check(selector,i))           //�͵�i��Ԫ��ƥ��
            {
                ans.push_back(i);
            }
        }
    }
    else                                    //���ѡ����
    {
        vector <string> sel;
        string str;
        int temp;
        stringstream ss(selector);
        while(ss >> str)
            sel.push_back(str);
        for(i = 1;i <= n;i++)
        {
            int index = sel.size() - 1;
            if(check(sel[index],i))
            {
                index--;
                temp = nodes[i].parent;
                while(temp != 0 && index >= 0)
                {
                    if(check(sel[index],temp))
                        index--;
                    temp = nodes[temp].parent;
                }
            }
            if(index == -1)
                ans.push_back(i);
        }
    }
    cout << ans.size() << " ";
    for(i = 0;i < ans.size();i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
{
    int n,m;
    int i;
    string line;
    string selector;
    cin >> n >> m;
    cin.ignore();
    for(i = 1;i <= n;i++)
    {
        getline(cin,line);
        AddLine(line,i);
    }
    for(i = 1;i <= m;i++)
    {
        getline(cin,selector);
        Search(selector,n);
    }
   /*
     for(i = 1;i <= n;i++)
    {
        cout << "*******************************" << endl;
        cout << "line: " << i << endl;
        cout << "level: " << nodes[i].level << endl;
        cout << "tag: " << nodes[i].tag << endl;
        cout << "id: " << nodes[i].id << endl;
        cout << "parent: " << nodes[i].parent << endl;
    }
   */
    system("pause");
    return 0;
}
