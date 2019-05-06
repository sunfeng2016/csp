/**********************************************
 * About: csp 201803-3 URL映射
 * Author: 孙峰
 * Date: 2019-3-16
 **********************************************/

#include <iostream>
using namespace std;
#include <string>

#define MAX_N 101
#define MAX_M 101

string p[MAX_N];                            //URL规则
string r[MAX_N];                            //规则名称
string q[MAX_M];                            //URL地址

bool match(string &s, string &t, bool flag) //检查URL地址s和URL规则t是否匹配，当flag为真时进行输出
{
    int lent = t.size();
    int lens = s.size();
    int pt = 0;
    int ps = 0;
    bool ok;
    while(ps < lens && pt < lent)
    {
        if(t[pt] == s[ps])                  //跳过开头相同的若干字符
        {
            pt++;
            ps++;
        }
        else
        {
            if(t[pt] != '<')                //跳过<
            {
                return false;
            }
            else
            {
                pt++;
            }
            
            if(flag)                        //规则名称和参数之间用空格分开
                cout << ' ';
            
            if(t[pt] == 'i')                //匹配<int>
            {
                ok = false;
                while(s[ps] && isdigit(s[ps])){
                    if(s[ps] != '0')          //去掉前导零
                        ok = true;
                    if(flag && ok)
                        cout << s[ps];
                    ps++;
                }
                if(!ok)
                    return false;
                pt += 4;
            }

            else if(t[pt] == 's')           //匹配<str>
            {
                ok = false;
                while(s[ps] && s[ps] != '/')
                {
                    ok = true;
                    if(flag)
                        cout << s[ps];
                    ps++;
                }
                if(!ok)
                    return false;
                    pt += 4;
            }

            else if(t[pt] == 'p')           //如果合法的话，<path.一定是最后一个呢
            {
                if(flag)
                {
                    while(s[ps])
                    {
                        cout << s[ps];
                        ps++;
                    }
                }
                return true;
            }
        }    
    }
    return pt == lent && ps == lens;
}

int main()
{
    int i,j;
    int n,m;
    bool flag;
    cin >> n >> m;
    for(i = 1;i <= n;i++)
        cin >> p[i] >> r[i];
    for(i = 1;i <= m;i++)
        cin >> q[i];
    for(i = 1;i <= m;i++)
    {
        flag = true;
        for(j = 1;flag && j <= n;j++)
        {
            if(match(q[i],p[j],false))
            {
                flag = false;
                cout << r[j];
                match(q[i],p[j],true);
            }
        }
        if(flag)
            cout << "404";
        cout << endl;
    }
    system("pause");
    return 0;
}