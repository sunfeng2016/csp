/******************************************************************
 * About: csp201809-3 元素选择器
 * Author: woxiang
 * Reference: https://www.cnblogs.com/KonjakJuruo/p/9999194.html
 ******************************************************************/
#include <bits/stdc++.h>
using namespace std;

struct tree
{
    string tag;             //标签
    string name;            //标识符
    int dots;               //级数
    tree *parent;           //父节点
    tree(int dots,string tag,string name):dots(dots),tag(tag),name(name),parent(NULL){}
};

//判断选择器是否和某行文档匹配
bool check(string &s,tree *t)
{
    if(s[0] == '#')                     //id选择器
        return s == t->name;
    else                                //标签选择器
    {
        if(s.size() != t->tag.size())
            return false;
        for(int i = 0;i < s.size();i++)
        {
            if(tolower(s[i]) != tolower(t->tag[i]))
                return false;
        }
        return true;
    }
}

//将输入的选择器分成若干个标签和id选择器
void divide(string &s, vector<string> &vec)
{
    string token;
    token.clear();
    vec.clear();
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == ' ')
        {
            vec.push_back(token);
            token.clear();
        }
        else
        {
            token += s[i];
        }
    }
    vec.push_back(token);
}

int main()
{
    int n,m;
    int i,j;
    int dots;
    string line;
    string tag,name;
    cin >> n >> m;
    cin.ignore();
    vector<tree* > nodes;
    nodes.clear();
    stack<tree* > sta;
    sta.empty();
    for(i = 1;i <= n;i++)
    {
        getline(cin,line);
        dots = 0;
        tag.clear();
        name.clear();
        for(j = 0;j < line.size();j++)
        {
            if(line[j] != '.')
                break;
        }
        dots = j;
        for(j;j < line.size();j++)
        {
            if(line[j] == ' ')
                break;
            else
                tag += line[j];
        }
        for(j++;j < line.size();j++)
        {
            name += line[j];
        }
        tree *now = new tree(dots, tag, name);
        if(!sta.empty())
        {
            tree *top;
            top = sta.top();
            while(!sta.empty() && top->dots >= dots)
            {
                sta.pop();
                top = sta.top();
            }
            now->parent = top;
        }
        sta.push(now);
        nodes.push_back(now);
    }
    vector<string> sel;
    vector<int> ans;
    while(m--)
    {
        getline(cin,line);
        divide(line,sel);
        ans.clear();
        for(i = 0;i < nodes.size();i++)
        {
            int sl = sel.size()-1;
            if(check(sel[sl],nodes[i]))
            {
                tree *t = nodes[i]->parent;
                sl--;
                while(t && sl >= 0){
                    if(check(sel[sl],t))
                        sl--;
                    t = t->parent;
                }
                if(sl == -1)
                    ans.push_back(i+1);
            }
        }
        cout << ans.size() << " ";
        for(i = 0;i < ans.size();i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}