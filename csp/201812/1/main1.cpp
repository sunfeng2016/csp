/*
201812-1
���
*/
#include <iostream>
using namespace std;

int main()
{
    int n,k,t;
    int r,y,g;
    cin >> r >> y >> g;
    int total = 0;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> k >> t;
        if(k == 0)      //��·
            total += t;
        else if(k == 1) //���
            total += t;
        else if(k == 2) //�Ƶ�
            total += (t + r);
        else
            continue;
    }
    cout << total << endl;
    //system("pause");
    return 0;
}   