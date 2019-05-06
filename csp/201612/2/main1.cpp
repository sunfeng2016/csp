/*
201612-2
Ëï·å
*/
#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
    int T,S;
    cin >> T;
    if(T <= 11255)
    {
        if(T > 4955)
        {
            if(T <= 7655)   //(4955,7655]
            {
                S = (T - 455) / 0.9;
            }
            else            //(7655,11255]
            {
                S = (T - 1255)/ 0.8;
            }
        }
        else
        {
            if(T <= 3500)   //(0,3500]
            {
                S = T;
            }
            else            //(3500,4955]
            {
                S = (T - 105) /0.97;
            }
            
        }
    }
    else
    {
        if(T <= 43255)
        {
            if(T > 29255)   //(29255,43255]
            {
               S = (T - 3705) /0.7; 
            }
            else            //(11255,29255]
            {
                S = (T - 1880) /0.75;
            }
        }
        else
        {
            if(T <= 59505)   //(43255,59505]
            {
               S = (T - 6530) /0.65; 
            }
            else            //(59505,+00]
            {
                S = (T - 14680) /0.55;
            }
        }
    }
    cout << S << endl;
    system("pause");
    return 0;
}