/****************************************
 * About: csp201809-3
 * Author: 孙峰
 * Date: 2019-3-15
 ****************************************/

#include <iostream>
using namespace std;
#include <ctype.h>
#include <string>
#include <stack>
#include <vector>

struct Line                             //结构化文档的元素类型
{
    int level;                          //层级
    string tag;                         //标签
    string id;                          //id
    int parent;                         //直接父节点的位置
};

Line Documents[101];                    //结构化文档
string selectors[11];                   //元素选择器
stack <int> Stack;                      //寻找元素父节点的辅助栈

void AddLine(string line, int n)        //将结构化文档的第n行元素加入文档中
{
    string tag = "";
    string id = "";
    int parents = 0;
    int level = 0;
    int top = 0;
    int i;
    for(i = 0;i < line.size();i++)      //求level
    {
        if(line[i] == '.')
            level++;
        else
            break;
    }
    for(i;i < line.size();i++)          //求tag
    {
        if(line[i] == ' ')
            break;
        else
            tag += line[i];
    }
    for(i++;i < line.size();i++)        //求id
    {
        id += line[i];
    }
    while(!Stack.empty())               //求parent
    {
        top = Stack.top();
        if(Documents[top].level < level)
            break;
        Stack.pop();
    }
    Stack.push(n);
    Documents[n].level = level;
    Documents[n].tag = tag;
    Documents[n].id = id;
    Documents[n].parent = top;
}

bool check(string sel,Line line)        //验证选择器跟元素是否匹配
{
    if(sel[0] == '#')                   //id选择器
        return (sel == line.id);
    else                                //标签选择器
    {
        if(sel.size() != line.tag.size())
            return false;
        for(int i = 0;i < sel.size();i++)
        {
            if(tolower(sel[i]) != tolower(line.tag[i]))
                return false;
        }
        return true;
    }
}

void Search(string selector,int n)
{
    int i;
    vector <string> List;
    vector <int> ans;
    string str = "";
    int sel;
    int temp;
    for(i = 0;i < selector.size();i++)
    {
        if(selector[i] != ' ')
            str += selector[i];
        else
        {
            List.push_back(str);
            str = "";
        }
    }
    List.push_back(str);
    for(i = 1;i <= n;i++)
    {
        sel = List.size() - 1;
        str = List[sel];
        if(check(str,Documents[i]))
        {
            sel--;
            temp = Documents[i].parent;
            while(sel >= 0 && temp > 0)
            {
                if(check(List[sel],Documents[temp]))
                {
                    sel--;
                }
                temp = Documents[temp].parent;
            }
            if(sel == -1)
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
    int i;
    int n,m;
    string line;
    cin >> n >> m;
    cin.ignore();
    for(i = 1;i <= n;i++)               //读入结构化文档
    {
        getline(cin,line);
        AddLine(line,i);
    }
    for(i = 1;i <= m;i++)               //读入元素选择器
    {
        getline(cin,selectors[i]);
    }
    for(i = 1;i <= m;i++)
    {
        Search(selectors[i],n);
    }
    system("pause");
    return 0;
}