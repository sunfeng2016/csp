/****************************************
 * About: csp201809-3
 * Author: ���
 * Date: 2019-3-15
 ****************************************/

#include <iostream>
using namespace std;
#include <ctype.h>
#include <string>
#include <stack>
#include <vector>

struct Line                             //�ṹ���ĵ���Ԫ������
{
    int level;                          //�㼶
    string tag;                         //��ǩ
    string id;                          //id
    int parent;                         //ֱ�Ӹ��ڵ��λ��
};

Line Documents[101];                    //�ṹ���ĵ�
string selectors[11];                   //Ԫ��ѡ����
stack <int> Stack;                      //Ѱ��Ԫ�ظ��ڵ�ĸ���ջ

void AddLine(string line, int n)        //���ṹ���ĵ��ĵ�n��Ԫ�ؼ����ĵ���
{
    string tag = "";
    string id = "";
    int parents = 0;
    int level = 0;
    int top = 0;
    int i;
    for(i = 0;i < line.size();i++)      //��level
    {
        if(line[i] == '.')
            level++;
        else
            break;
    }
    for(i;i < line.size();i++)          //��tag
    {
        if(line[i] == ' ')
            break;
        else
            tag += line[i];
    }
    for(i++;i < line.size();i++)        //��id
    {
        id += line[i];
    }
    while(!Stack.empty())               //��parent
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

bool check(string sel,Line line)        //��֤ѡ������Ԫ���Ƿ�ƥ��
{
    if(sel[0] == '#')                   //idѡ����
        return (sel == line.id);
    else                                //��ǩѡ����
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
    for(i = 1;i <= n;i++)               //����ṹ���ĵ�
    {
        getline(cin,line);
        AddLine(line,i);
    }
    for(i = 1;i <= m;i++)               //����Ԫ��ѡ����
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