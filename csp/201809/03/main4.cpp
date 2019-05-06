/*************************************************
 * About: csp201809-3 Ԫ��ѡ����
 * Author: woxiang
 *************************************************/
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 101

struct tree
{
    int dots;                   //����
    string tag;                 //��ǩ
    string id;                  //����
    int parent;                 //���ڵ�
    tree(int dots,string tag,string id,int parent):dots(dots),tag(tag),id(id),parent(parent){}
};

stack <int> Stack;              //����ջ������Ѱ�Ҹ��ڵ�
vector<tree> List;              //����ı�
vector<string> selector;        //���ѡ����

void AddLine(string line,int n) //�������ÿ���ı���ӵ�������
{
    int i;
    int dots = 0;
    int parent = -1;
    string tag = "";
    string id = "";
    for(i = 0; i < line.size();i++)
    {
        if(line[i] != '.')      //�ҳ�ÿ���ı��ļ���
            break;
    }
    dots = i;
    for(i;i < line.size();i++)
    {
        if(line[i] == ' ')      //�ҳ�ÿ���ı��ı�ǩ
            break;
        else
            tag += tolower(line[i]);
    }
    for(i++; i < line.size(); i++)
    {
        id += line[i];          //�ҳ�ÿ���ı�������
    }
    while(!Stack.empty())       //�ҳ�ÿ���ı��ĸ��ڵ�
    {
        parent = Stack.top();
        if(List[parent].dots < dots)
            break;
        Stack.pop();
    }
    List.push_back(tree(dots,tag,id,parent));
    Stack.push(n);
}

void AddSelector(string sel)    //�������ÿ��ѡ�������뵽ѡ����������
{
    selector.push_back(sel);    
}

bool check(string &str,int n)   //���ѡ�������ı��Ƿ�ƥ��
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

void Search(string &sel,int n)  //Ϊÿ��ѡ����Ѱ�Һ��ʵ�ƥ����
{
    int i;
    int temp;
    int index;
    vector<string>selectors;    //���ÿ��ѡ�����е����б�ǩ��id
    vector<int>ans;             //�����ѡ����������ƥ����
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
