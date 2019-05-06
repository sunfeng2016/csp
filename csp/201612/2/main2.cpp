/*
201612-2
2019.3.3
*/

#include <iostream>
using namespace std;

int main()
{
    int gross_pay;                  //税前工资
    int net_pay;                    //税后工资
    cin >> net_pay;
    
    if(net_pay <= 3500)
    {
        gross_pay = net_pay;
    }
    else if(net_pay <= 4955)
    {
        gross_pay = (net_pay - 3500) * 100 / 97 + 3500;
    }
    else if(net_pay <= 7655)
    {
        gross_pay = (net_pay - 4955) * 100 / 90 + 5000;
    }
    else if(net_pay <= 11255)
    {
        gross_pay = (net_pay - 7655) * 100 / 80 + 8000;
    }
    else if(net_pay <= 30755)
    {
        gross_pay = (net_pay - 11255) * 100 / 75 + 12500;
    }
    else if(net_pay <= 44755)
    {
        gross_pay = (net_pay - 30755) * 100 / 70 + 38500;
    }
    else if(net_pay <= 61005)
    {
        gross_pay = (net_pay - 44755) * 100 / 65 + 58500;
    }
    else
    {
        gross_pay = (net_pay - 61005) * 100 / 55 + 83500;
    }
    cout <<gross_pay << endl;
    system("pause");
    return 0;
}