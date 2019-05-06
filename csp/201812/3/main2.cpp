/*****************************************************
 * About: csp 201812-3 CIDR合并
 * Author: 孙峰
 * Date: 2019-3-11
 *****************************************************/
#include <iostream>
using namespace std;
#include <string>
#include <list>

struct IP                       //ip前缀
{
    string pref;                //前缀
    int len;                    //前缀长度
    IP(string pref,int len):pref(pref),len(len){}
    bool operator < (IP &ip){
        if(this->pref < ip.pref)
            return true;
        else if(this->pref == ip.pref && this->len < ip.len)
            return true;
        else    
            return false;
    }
};

list <IP> IP_List;              //前缀列表

void AddIp(string ip)
{
    string pref = "";
    int temp = 0;
    string str = "";
    int i,j;
    int len = 0;
    int location = ip.find('/');
    int point = 0;

    if(location == -1)          //IP前缀长度
    {
        if(ip[0] != '0')
        {
            for(i == 0; i < ip.size();i++)
            {
                if(ip[i] == '.')
                    point++;
            }
            len = (point + 1) * 8;
        }
        ip += '/';              //强制加上'/',便于后面处理
    }
    else
    {
        for(i = location + 1;i < ip.size();i++)
        {
            len = len * 10 + (ip[i] - '0');
        }
    }

    for(i = 0;i < ip.size();i++)//IP前缀
    {
        if(ip[i] != '.' && ip[i] != '/')
        {
            temp = temp * 10 + (ip[i] - '0');
        }
        else
        {
            for(j = 1;j <= 8;j++)
            {
                if(temp % 2 == 0)
                    str.insert(0,1,'0');
                else
                    str.insert(0,1,'1');
                temp /= 2;
            }
            pref += str;
            str.clear();
            if(ip[i] == '/')
                break;
        }
    }
    while(pref.size() < 32)
        pref += '0';
    IP_List.push_front(IP(pref,len));
}

void OutputIP(IP ip)    //打印每个IP前缀
{
    int temp = 0;
    int i;
    for(i = 0;i < 32;i++)
    {
        temp = temp * 2 + (ip.pref[i] - '0');
        if((i + 1) % 8 == 0)
        {
            cout << temp;
            temp = 0;
            if(i != 31)
                cout << ".";
        }
    }
    cout << "/" << ip.len << endl;
}

bool ChildCollection(IP a,IP b) //判断a和b的匹配集是否是子集关系
{
    if(a.len > b.len)
        return false;
    else
    {
        for(int i = 0;i < a.len;i++)
        {
            if(a.pref[i] != b.pref[i])
                return false;
        }
        return true;
    } 
}

void Merge1()                   //从大到小合并
{
    list <IP>::iterator p,q;            
    p = IP_List.begin();
    q = IP_List.begin();
    q++;
    while(q != IP_List.end())
    {
        if(ChildCollection(*p,*q))
        {
            q = IP_List.erase(q);
        }
        else
        {
            p++;
            q++;
        }  
    }
}

bool UnionCollection(IP a,IP b) //判断是否是并集关系
{
    if(a.len != b.len)
        return false;
    else
    {
        for(int i = 0;i < a.len -1;i++)
        {
            if(a.pref[i] != b.pref[i])
                return false;
        }
        return a.pref[a.len -1] != b.pref[a.len -1];
    }
}

void Merge2()
{
    list <IP>::iterator p,q;
    p = IP_List.begin();
    q = IP_List.begin();
    q++;
    while(q != IP_List.end())
    {
        if(UnionCollection(*p,*q))
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
    list<IP>::iterator p;
    cin >> n;
    for(i = 1;i <= n;i++)
    {
        cin >> ip;
        AddIp(ip);              //将ip加入前缀列表
    }
    IP_List.sort();
    Merge1();
    Merge2();
    for(p = IP_List.begin();p != IP_List.end();p++)
        OutputIP(*p);
    system("pause");
    return 0;
}
