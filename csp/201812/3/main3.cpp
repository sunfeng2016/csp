/**********************************
 * About: csp 201812-3 CIDR�ϲ� 
 * Author: ���
 * Date: 2019-3-14
 **********************************/
#include <iostream>
using namespace std;
#include <string>
#include <List>
#include <algorithm>

struct IP
{
    string pref;
    int len;
    IP(string pref, int len):pref(pref),len(len){}
    bool operator < (IP &ip){
        if(this->pref < ip.pref)
            return true;
        else if(this->pref == ip.pref && this->len < ip.len)
            return true;
        else
            return false;
    }
};

list <IP> IP_List;                  //�����������е�IPǰ׺

void AddIP(string ip)               //ÿ����һ��ipǰ׺��������ӵ�ǰ׺�б���
{
    int len = 0;
    string pref = "";
    int i,j;
    int temp = 0;
    string str = "";
    int count = 0;                  //ipǰ׺��.�ĸ���
    
    i = ip.find('/');               //��ǰ׺����
    if(i == -1)                     //ʡ�Գ�����
    {
        if(ip[0] != '0')
        {
            for(j = 0;j < ip.size();j++)
            {
                if(ip[j] == '.')
                    count++;
            }
            len = (count + 1) * 8;
        }
        ip += '/';                  //Ϊ�˱��ں������������ǿ�м�'/'
    }
    else                            //��׼�ͻ�ʡ�Ժ�׺��
    {
        for(i++; i < ip.size();i++)
        {
            len = len * 10 + (ip[i] - '0');
        }
    }
    
    for(i = 0;i < ip.size();i++)    //��ǰ׺
    {
        if(ip[i] == '.' || ip[i] == '/')
        {
            for(j = 0;j < 8;j++)
            {
                if(temp % 2 == 1)
                    str.insert(0,1,'1');
                else
                    str.insert(0,1,'0');
                temp /= 2;
            }
            pref += str;
            str = "";
            if(ip[i] == '/')
                break;
        }
        else
        {
            temp = temp * 10 + (ip[i] - '0');
        }
    }
    pref += str;
    while(pref.size() < 32){
        pref += '0';
    }
    IP_List.push_back(IP(pref,len));
}

void OutputIP(IP ip)
{
    int i;
    int temp = 0;
    for(i = 0;i < 32;i++)
    {
        temp = temp * 2 + (ip.pref[i] - '0');
        if((i + 1) % 8 == 0)
        {
            cout << temp;
            temp = 0;
            if(i == 31)
                cout << "/";
            else
                cout << ".";
        }
    }
    cout << ip.len << endl;
}    

bool IsChildCollection(IP p,IP q)   //�ж�����IPǰ׺��ƥ�伯�Ƿ����Ӽ���ϵ
{
    if(p.len > q.len)
        return false;
    else
    {
        for(int i = 0;i < p.len;i++)
        {
            if(p.pref[i] != q.pref[i])
                return false;
        }
        return true;
    }
}

void Merge1()                       //��С����ϲ�
{
    list <IP>::iterator p,q;
    p = IP_List.begin();
    q = IP_List.begin();
    q++;
    while(q != IP_List.end())
    {
        if(IsChildCollection(*p,*q))
            q = IP_List.erase(q);
        else
        {
            p++;
            q++;
        }
    }
}            

bool IsUnionCollection(IP p,IP q)   //�ж�ǰ׺��ƥ�伯�Ƿ���ڲ�����ϵ
{
    if(p.len != q.len)
        return false;
    else
    {
        for(int i = 0;i < p.len - 1;i++)
        {
            if(p.pref[i] != q.pref[i])
                return  false;
        }
        return p.pref[p.len - 1] !=  q.pref[p.len - 1];
    }
}

void Merge2()                       //ͬ���ϲ�
{
    list <IP>::iterator p,q;       
    p = IP_List.begin();
    q = IP_List.begin();
    q++;
    while(q != IP_List.end())
    {
        if(IsUnionCollection(*p,*q))
        {
            q = IP_List.erase(q);
            (*p).len--;
            if(p != IP_List.begin())
            {
                p--;
                q--;
            }
        }
        else
        {
            p++;
            q++;
        }        
    }  
}

int main()
{
    int n;
    int i;
    string ip;
    list <IP>::iterator p;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> ip;
        AddIP(ip);
    }
    IP_List.sort();
    Merge1();
    Merge2();
    for(p = IP_List.begin(); p != IP_List.end();p++)
    {
        OutputIP(*p);
    }
    system("pause");
    return 0;
}