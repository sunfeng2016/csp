/*
201812-3
*/
#include <iostream>
using namespace std;
#include <string>
#include <stdlib.h>
#include <algorithm>

string IP[100001];

void Input_process(string &str)
{
    int point_count;
    int sprit_loc;
    int length;
    int i,j;
    string strobj;
    point_count = 0;
    for(j = 0;j < str.size();j++)
    {
        if(str[j] == '.')
            point_count++;
    }
    sprit_loc = str.find('/');
    if(sprit_loc == -1)
    {
        length = 0;
        if(str[0] != '0')
            length = 8 * (point_count + 1);
        str += '/';
        if(length > 9)
        {
            str += (length / 10 + 48);
            length %= 10; 
        }
        str += (length + 48);
    }
    strobj = ".0";
    while(point_count < 3)
    {
        sprit_loc = str.find('/');
        str.insert(sprit_loc,strobj);
        point_count++;
    }
}

int length(string &str)
{
    int loc = str.find('/');
    int len = 0;
    for(int i = loc + 1;i < str.size();i++)
    {
        len =  len * 10 + (str[i] - 48);
    }
    return len;
}

string Value(string &str)
{
    int i,j;
    string value = "";
    string str1;
    int temp = 0;
    for(i = 0;i < str.size();i++)
    {
        if(str[i] != '.' && str[i] != '/')
        {
            temp = temp * 10 + (str[i] - '0');
        }
        else
        {
            str1 = "";
            for(j = 7;j >= 0;j--)
            {
                if(temp % 2 == 0)
                    str1.insert(0,1,'0');
                else
                    str1.insert(0,1,'1');
                temp = temp/2;
            }
            value += str1;
            if(str[i] == '/')
                break;
        }
    }
    return value;
}

bool compare(string &str1,string &str2)
{ 
    if(Value(str1) == Value(str2))
        return length(str1) < length(str2);
    else
        return Value(str1) < Value(str2);
}

int main()
{
    int n;
    int i;
    string str;
    cin >> n;
    for(i = 0;i < n;i++)
    {
        cin >> IP[i];
        Input_process(IP[i]);
    }
    sort(IP,IP + n,compare);
    for(i = 0;i < n;i++)
        cout << IP[i] << endl;
    system("pause");
    return 0;
}