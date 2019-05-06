/****************************************
 * About: CSP 201803-3 URL映射
 * Author: woxiang
 * Reference: 
 * Date: 2019-3-13
 ****************************************/
#include <iostream>
using namespace std;
#include <string>

#define MAX_N 101
#define MAX_M 101

string P[MAX_N];                            //URL规则
string R[MAX_N];                            //规则名称
string S[MAX_M];                            //URL地址

bool match(string &s, string &t, bool flag)
{
    int lent = t.size();
    int lens = s.size();
    int ps = 0;
    int pt = 0;
    bool ok;
    while(ps < lens && pt < lent)
    {
        if(t[pt] == s[ps])                  //跳过URL规则前面的非参数部分
        {
            ps++;
            pt++;
        }
        else                                //匹配参数
        {
            if (t[pt] != '<') {             //跳过<
                return false;
            }
            else
            {
                pt++;
            }

            if(flag)
                cout << ' ';
            
            if(t[pt] == 'i')                //匹配<int>
            {
                ok = false;
                while(s[ps] && isdigit(s[ps])){
                    if(s[ps] != '0')
                        ok = true;          //去掉前导零
                    if(flag && ok)
                        cout << s[ps];
                    ps++;
                }
                if(!ok)
                    return false;
                pt += 4;
            }

            else if (t[pt] == 's')          //匹配<str>
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

            else if(t[pt] == 'p')           //如果合法的话，<path>一定已经是最后一个了             
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
        cin >> P[i] >> R[i];
    for(i = 1;i <= m;i++)
        cin >> S[i];
    for(i = 1;i <= m;i++)
    {
        flag = true;
        for(j = 1;flag && j <= n;j++)
        {
            if(match(S[i],P[j],false)){ //用了两次match，true的时候输出
                flag = false;
                cout << R[j];
                match(S[i],P[j],true);
            }
        }
        if(flag)
            cout << "404";
        cout << endl;
    }
    system("pause");
    return 0;
}