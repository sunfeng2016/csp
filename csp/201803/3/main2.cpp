/**********************************************
 * About: csp 201803-3 URLӳ��
 * Author: ���
 * Date: 2019-3-16
 **********************************************/

#include <iostream>
using namespace std;
#include <string>

#define MAX_N 101
#define MAX_M 101

string p[MAX_N];                            //URL����
string r[MAX_N];                            //��������
string q[MAX_M];                            //URL��ַ

bool match(string &s, string &t, bool flag) //���URL��ַs��URL����t�Ƿ�ƥ�䣬��flagΪ��ʱ�������
{
    int lent = t.size();
    int lens = s.size();
    int pt = 0;
    int ps = 0;
    bool ok;
    while(ps < lens && pt < lent)
    {
        if(t[pt] == s[ps])                  //������ͷ��ͬ�������ַ�
        {
            pt++;
            ps++;
        }
        else
        {
            if(t[pt] != '<')                //����<
            {
                return false;
            }
            else
            {
                pt++;
            }
            
            if(flag)                        //�������ƺͲ���֮���ÿո�ֿ�
                cout << ' ';
            
            if(t[pt] == 'i')                //ƥ��<int>
            {
                ok = false;
                while(s[ps] && isdigit(s[ps])){
                    if(s[ps] != '0')          //ȥ��ǰ����
                        ok = true;
                    if(flag && ok)
                        cout << s[ps];
                    ps++;
                }
                if(!ok)
                    return false;
                pt += 4;
            }

            else if(t[pt] == 's')           //ƥ��<str>
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

            else if(t[pt] == 'p')           //����Ϸ��Ļ���<path.һ�������һ����
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