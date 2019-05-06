/*
201803-1
2019.3.3
*/

#include <iostream>
using namespace std;

int main()
{
    int score = 1;
    int total = 0;
    int location;
    while(1)
    {
        cin >> location;
        if(location == 1)       //不在中心
        {
            score = 1;
            total += score;
        }
        else if(location == 2)  //中心
        {
            if(score == 1)  
                score = 2;
            else
                score += 2;
            total += score;
        }
        else
            break;
    }
    cout << total << endl;
    system("pause");
    return 0;
}