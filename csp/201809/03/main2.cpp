/********************************************
 * About: csp 201809-3
 * Author: 孙峰
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

struct node                             //结构化文档的元素类型
{
    int level;                          //级数
    string tag;                         //标签
    string id;                          //id
    int parent;                         //父节点
};

node nodes[MAX_N];                      //结构化文档
stack <int> Stack;                      //找父节点的辅助栈

void AddLine(string line,int n)         //添加元素
{
    int level = 0;
    int i;
    int top;
    string tag = "";
    string id = "";
    int parent = 0;
    for(i = 0;i < line.size();i++)      //求级数    
    {
        if(line[i] == '.')
            level++;
        else
            break;
    }
    nodes[n].level = level;
    for(i;i < line.size();i++)          //求标签
    {
        if(line[i] != ' ')
            tag += tolower(line[i]);
        else
            break;
    }
    nodes[n].tag = tag;
    for(i++;i < line.size();i++)        //求id
    {
        id += line[i];
    }
    nodes[n].id = id;
    while(!Stack.empty()){              //求父节点
        top = Stack.top();
        if(nodes[top].level < level)
            break;
        Stack.pop();
    }
    Stack.push(n);
    nodes[n].parent = top;
}

bool check(string selector,int n)       //检查选择器与元素是否匹配
{
    if(selector[0] == '#')              //id选择器
    {
        return (selector == nodes[n].id);
    }
    else                                //标签选择器
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
    if(selector.find(' ') == string::npos)  //不是后代选择器
    {
        for(i = 1;i <= n;i++)
        {
            if(check(selector,i))           //和第i行元素匹配
            {
                ans.push_back(i);
            }
        }
    }
    else                                    //后代选择器
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
