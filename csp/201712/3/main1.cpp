/********************************
 * About: csp 201712-3 crontab
 * Author: ���
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
int firstyear, lastyear;                                                //��ʼ����������
int range[5] = {60, 24, 31, 12, 7};                                     //����ʱ����ķ�Χ
int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};    //�����·ݵ�����
string week[7] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};     //���ڶ�Ӧ��Ӣ����д
string month[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"}
map <string, int> mp;                                                   //�������Ӣ����д�Ķ�Ӧֵ
vector <pair<LL, int>> ans;                                             //ans��Ž����"ʱ��,id"��

//�������ĸ��ͷ��һ����Ӣ����д��ֱ�ӷ���tmp�ж�Ӧ��ֵ��
//����������֣���λ�ۼӼ���
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
        str[i] = tolower(str[i]);                                       //�����ִ�Сд
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

//�ȷ���s�Ƿ�Ϊ��*�����ٷ�����,����������'-'
void findValue(set <LL> &tmp, string &s,int j)
{
    if(s == "*")
    {
        for(int i = 0;i != range[j]; i++)
        {
            if(j == 2 || j == 3)            //���ں��·��Ǵ�1��ͷ��
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
    vector<vector<string>> cron(n, vector<string>(6));                  //����һ��n * 6�Ķ�άstring����cron
    for(i = 0;i != n;i++)                                               //����n ��cron������Ϣ
    {
        for(j = 0;j != 6;j++)
        {
            cin >> cron[i][j];
        }
    }  
    //����ÿһ��ָ��ȷ�����Ч��minute��Χ���洢��v[0]���ٷ�����Ч��hour��Χ��������
    //minute��Χ������ϣ��洢��v[1]���Դ����ƣ����Եó�v[4]�����ļ�Ϊ���յ���Чʱ��
    for(i = 0; i != n;i++)
    {
        vector<vector<LL>> v(5);
        LL mul = 1;
        for(j = 0; j != 5;j++)
        {
            set <LL> valid;         //��Ϊ��Ŀ�������п�����"3,2-4"���֣�����Ҫ��set�洢ȥ�ظ�
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