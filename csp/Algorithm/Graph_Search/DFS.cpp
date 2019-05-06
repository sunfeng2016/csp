#include <iostream>
using namespace std;
#include <stdio.h>

int main()
{
    int a,b;
//    freopen("in.txt","r",stdin);
    while(cin >> a >> b)
        cout << a + b << endl;
//    fclose(stdin);
    system("pause");
    return 0;        
}