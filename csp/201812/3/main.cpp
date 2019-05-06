#include <iostream>
using namespace std;
#include <string>
#include <list>
#include <algorithm>

struct IP_PR
{
    string pref;
    int len;
    IP_PR(string Pref,int Len):pref(Pref),len(Len){}
    bool operator < (IP_PR &IP)
    {
        if(this->pref < IP.pref)
            return true;
        else if(this->pref == IP.pref && this->len < IP.len)
            return true;
        else
            return false;
    }
};

list <IP_PR> IP_List;

void CreatList(string IP)
{
    string pref = "";
    string str;
    int length = 0;
    int i,j;
    int temp = 0;
    int Point_count = 0;
    int Sprit_index = IP.find('/');
    if(Sprit_index == -1)
    {
        if(IP[0] != '0')
        {
            for(i = 0;i < IP.size();i++)
            {
                if(IP[i] == '.')
                    Point_count++;
            }
            length = (Point_count + 1) * 8;
        }
        IP += '/';
    }
    else
    {
        for(i = Sprit_index + 1;i < IP.size();i++)
        {
            length = (length * 10) + IP[i] - '0';
        }
    }

    for(i = 0;i < IP.size();i++)
    {
        if(IP[i] != '.' && IP[i] != '/')
        {
            temp = temp * 10 + IP[i] - '0';
        }
        else
        {
            str = "";
            for(j = 0;j < 8;j++)
            {
                if(temp % 2 == 0)
                    str.insert(0,1,'0');
                else
                    str.insert(0,1,'1');
                temp /= 2;
            }
            pref += str;
            if(IP[i] == '/')
                break;
        }
    }
    while(pref.size() < 32)
        pref += '0';
    IP_List.push_back(IP_PR(pref,length));
}

void output(IP_PR &IP)
{
    int IP1 = 0;
    int IP2 = 0;
    int IP3 = 0;
    int IP4 = 0;
    int i;
    for(i = 0;i < 8;i++)
        IP1 = IP1 * 2 + IP.pref[i] - '0';
    for(i = 8;i < 16;i++)
        IP2 = IP2 * 2 + IP.pref[i] - '0';
    for(i = 16;i < 24;i++)
        IP3 = IP3 * 2 + IP.pref[i] - '0';
    for(i = 24;i < 32;i++)
        IP4 = IP4 * 2 + IP.pref[i] - '0';
    cout << IP1 << '.' << IP2 << '.' << IP3 << '.' << IP4 << '/' << IP.len << endl; 
}

bool IsChildCollection(IP_PR &p,IP_PR &q)
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

void Merge1()
{
    list <IP_PR>::iterator p,q;
    p = IP_List.begin();
    q = IP_List.begin();
    q++;
    while(q != IP_List.end())
    {
        if(IsChildCollection(*p,*q))
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

bool unionCollection(IP_PR &p,IP_PR &q)
{
    if(p.len != q.len)
        return false;
    else
    {
        for(int i = 0;i < p.len - 1;i++)
        {
            if(p.pref[i] != q.pref[i])
                return false;
        }    
        return p.pref[p.len - 1] != q.pref[p.len - 1];
    }
}

void Merge2()
{
    list <IP_PR>::iterator a,b;
    a = IP_List.begin();
    b = IP_List.begin();
    b++;
    while(b != IP_List.end())
    {
        if(unionCollection(*a,*b))
        {
            b = IP_List.erase(b);
            (*a).len--;
            if(a != IP_List.begin())
            {
                a--;
                b--;
            }
        }
        else
        {
            a++;
            b++;
        }
    } 
}

int main()
{
    int n;
    int i;
    string IP;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> IP;
        CreatList(IP);
    }
    IP_List.sort();
    list <IP_PR>::iterator p;
    Merge1();
    Merge2();
    for(p = IP_List.begin();p != IP_List.end();p++)
    {
        output(*p);
    }
    system("pause");
    return 0;
}