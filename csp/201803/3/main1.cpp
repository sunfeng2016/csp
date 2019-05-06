/****************************************
 * About: CSP 201803-3 URLӳ��
 * Author: woxiang
 * Reference: 
 * Date: 2019-3-13
 ****************************************/
#include <iostream>
using namespace std;
#include <string>

#define MAX_N 101
#define MAX_M 101

string P[MAX_N];                            //URL����
string R[MAX_N];                            //��������
string S[MAX_M];                            //URL��ַ

bool match(string &s, string &t, bool flag)
{
    int lent = t.size();
    int lens = s.size();
    int ps = 0;
    int pt = 0;
    bool ok;
    while(ps < lens && pt < lent)
    {
        if(t[pt] == s[ps])                  //����URL����ǰ��ķǲ�������
        {
            ps++;
            pt++;
        }
        else                                //ƥ�����
        {
            if (t[pt] != '<') {             //����<
                return false;
            }
            else
            {
                pt++;
            }

            if(flag)
                cout << ' ';
            
            if(t[pt] == 'i')                //ƥ��<int>
            {
                ok = false;
                while(s[ps] && isdigit(s[ps])){
                    if(s[ps] != '0')
                        ok = true;          //ȥ��ǰ����
                    if(flag && ok)
                        cout << s[ps];
                    ps++;
                }
                if(!ok)
                    return false;
                pt += 4;
            }

            else if (t[pt] == 's')          //ƥ��<str>
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

            else if(t[pt] == 'p')           //����Ϸ��Ļ���<path>һ���Ѿ������һ����             
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
            if(match(S[i],P[j],false)){ //��������match��true��ʱ�����
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