/*************************************************
 * About: csp201809-3 元素选择器
 * Author: woxiang
 *************************************************/
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 101

struct tree
{
    int dots;                   //级数
    string tag;                 //标签
    string id;                  //属性
    int parent;                 //父节点
    tree(int dots,string tag,string id,int parent):dots(dots),tag(tag),id(id),parent(parent){}
};

stack <int> Stack;              //辅助栈，用来寻找父节点
vector<tree> List;              //存放文本
vector<string> selector;        //存放选择器

void AddLine(string line,int n) //将读如的每行文本添加到向量中
{
    int i;
    int dots = 0;
    int parent = -1;
    string tag = "";
    string id = "";
    for(i = 0; i < line.size();i++)
    {
        if(line[i] != '.')      //找出每行文本的级数
            break;
    }
    dots = i;
    for(i;i < line.size();i++)
    {
        if(line[i] == ' ')      //找出每行文本的标签
            break;
        else
            tag += tolower(line[i]);
    }
    for(i++; i < line.size(); i++)
    {
        id += line[i];          //找出每行文本的属性
    }
    while(!Stack.empty())       //找出每行文本的父节点
    {
        parent = Stack.top();
        if(List[parent].dots < dots)
            break;
        Stack.pop();
    }
    List.push_back(tree(dots,tag,id,parent));
    Stack.push(n);
}

void AddSelector(string sel)    //将读入的每个选择器加入到选择器向量中
{
    selector.push_back(sel);    
}

bool check(string &str,int n)   //检查选择器与文本是否匹配
{
    if(str[0] == '#')
        return (str == List[n].id);
    else
    {
        if(str.size() != List[n].tag.size())
            return false;
        else
        {
            for(int i = 0;i < str.size();i++)
                str[i] = tolower(str[i]);
            return (str == List[n].tag);
        }
    }
}

void Search(string &sel,int n)  //为每个选择器寻找合适的匹配项
{
    int i;
    int temp;
    int index;
    vector<string>selectors;    //存放每个选择器中的所有标签或id
    vector<int>ans;             //满足给选择器的所有匹配项
    string token = "";
    for(i = 0;i < sel.size();i++)
    {
        if(sel[i] == ' ')
        {
            selectors.push_back(token);
            token.clear();
        }
        else
        {
            token += sel[i];
        }
    }
    selectors.push_back(token);
    for(i = 0;i < n;i++)
    {
        index = selectors.size() - 1;
        if(check(selectors[index],i))
        {
            temp = List[i].parent;
            index--;
            while(temp != -1 && index >= 0)
            {
                if(check(selectors[index],temp))
                    index--;
                temp = List[temp].parent;
            }
            if(index == -1)
                ans.push_back(i + 1);
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
    cin >> n >> m;
    cin.ignore();
    string line;
    for(i = 1; i <= n;i++)
    {
        getline(cin,line);
        AddLine(line,i-1);
    }
    for(i = 1;i <= m;i++)
    {
        getline(cin,line);
        AddSelector(line);
    }
    for(i = 0;i < m;i++)
    {
        Search(selector[i],n);
    }
    system("pause");
    return 0;
}
