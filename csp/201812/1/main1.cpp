/*
201812-1
Ëï·å
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
        if(k == 0)      //µÀÂ·
            total += t;
        else if(k == 1) //ºìµÆ
            total += t;
        else if(k == 2) //»ÆµÆ
            total += (t + r);
        else
            continue;
    }
    cout << total << endl;
    //system("pause");
    return 0;
}   