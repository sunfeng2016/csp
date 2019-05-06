/*
201803-1
2019.2.28
*/

#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int score = 1;
    int total = 0;
    int location = 1;
    while(location)
    {
        cin >> location;
        if(location == 1)
            score = 1;
        else if(location == 2)
        {
            if(score == 1)
                score = 2;
            else
                score += 2;
        }
        else
            break;
        total += score;
    }
    cout << total << endl;
    system("pause");
    return 0;
}