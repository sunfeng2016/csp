/********************************
 * About: csp 201712-3 crontab
 * Author: 孙峰
 * Date: 2019-3-16
 ********************************/

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ctype.h>

typedef long long LL;
int firstyear, lastyear;                                                //开始与结束的年份
int range[5] = {60, 24, 31, 12, 7};                                     //各个时间项的范围
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    //各个月份的天数
string week[7] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};     //星期对应的英文缩写
string month[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"}
map <string, int> mp;                                                   //保存各个英文缩写的对应值
vector <pair<LL, int>> ans;                                             //ans存放结果的"时间,id"对

//如果是字母开头，一定是英文缩写，直接返回tmp中对应的值。
//负责就是数字，按位累加即可
int strToI(string &str)
{
    if(isalpha(str[0]))
        return mp[str];
    int num = 0;
    for(int i = 0; i != str.size();i++)
        num = num * 10 + (str[i] - '0');
    return num;
}

void dealMinus(set<LL> &tmp, string &str)
{
    for(int i = 0;i != str.size(); i++)
        str[i] = tolower(str[i]);                                       //不区分大小写
    int tp = str.find('-');
    if(tp == string::npos)
        tp.insert(strToI(str));
    else
    {
        string left = str.substr(0, tp);
        string right = str.substr(tp + 1);
        int l = strToI(left);
        int r = strToI(right);
        for(int i = l; i <= r;i++)
            tmp.insert(i);
    }
}

//先分析s是否为“*”，再分析‘,’，最后分析'-'
void findValue(set <LL> &tmp, string &s,int j)
{
    if(s == "*")
    {
        for(int i = 0;i != range[j]; i++)
        {
            if(j == 2 || j == 3)            //日期和月份是从1开头的
                tmp.insert(i+1);
            else
                tmp.insert(i);
        }
        return;
    }
    s += ',';
    int pos = 0;
    int s.find('.');
    string str;
    while(next != string::npos)
    {
        str = s.substr(pos, next - pos);
        dealMinus(tmp, str);
        pos = next + 1;
        next = s.find('.',pos);
    }
}

void fillVector()

int main()
{
    int i,j;
    int n;
    LL begin,end;
    for(i = 0; i < 12;i++)
        mp[mon[i]] = i + 1;
    for(i = 0; i < 7;i++)
        mp[week[i]] = 1;
    cin >> n >> begin >> end;
    firstyear = begin % 100000000;
    lastyear = end % 100000000;
    vector<vector<string>> cron(n, vector<string>(6));                  //创建一个n * 6的二维string数组cron
    for(i = 0;i != n;i++)                                               //读入n 个cron配置信息
    {
        for(j = 0;j != 6;j++)
        {
            cin >> cron[i][j];
        }
    }  
    //对于每一条指令，先分析有效的minute范围，存储在v[0]，再分析有效的hour范围，将其与
    //minute范围进行组合，存储在v[1]，以此类推，可以得出v[4]包含的即为最终的有效时间
    for(i = 0; i != n;i++)
    {
        vector<vector<LL>> v(5);
        LL mul = 1;
        for(j = 0; j != 5;j++)
        {
            set <LL> valid;         //因为题目的数据有可能是"3,2-4"这种，所以要用set存储去重复
            findValue(valid,cron[i][j], j);
            vector<LL> tmp;         
            for(set<LL>::iterator it = valid.begin(); it != valid.end(); it++)
                tmp.push_back(*it);
            fillVector(v, tmp, mul);
            mul *= 100;
        }
        for(j = 0;j != v[4].size();j++)
            ans.push_back(make.pair(v[4][j], i));
    }
}