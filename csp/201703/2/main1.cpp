/*
201703-2
孙峰
*/

#include <iostream>
using namespace std;

int students[1001];         //每个位置上的学生学号
int locations[1001];        //每个学生所在的位置

int main()
{
    int n,m;
    int p,q;
    int i,j;
    cin >> n >> m;
    for(i = 1;i <= n;i++)
    {
        locations[i] = i;
        students[i] = i;
    }
    for(i = 1;i <= m;i++)
    {
        cin >> p >> q;
        if(q > 0)         //向后
        {
            for(j = locations[p] + 1;j <= locations[p] + q;j++)
            {
                locations[students[j]]--;
            }
        }
        else            //向前
        {
            for(j = locations[p] - 1;j >= locations[p] + q;j--)
            {
                locations[students[j]]++;
            }
        }
        locations[p] += q;
        for(j = 1;j <= n;j++)
        {
            students[locations[j]] = j;
        }
    }
    for(i = 1;i <= n;i++)
        cout << students[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}