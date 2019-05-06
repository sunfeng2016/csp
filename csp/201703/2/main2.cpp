/*
201703-2
2019.3.3
*/
#include <iostream>
using namespace std;
#include <list>
#include <vector>

int main()
{
    int N,M;
    int p,q;
    cin >> N >> M;
    list<int> lst;
    vector<list<int>::iterator> vec(N+1);
    for(int i = 1;i <= N;i++)
    {
        lst.push_back(i);
        vec[i] = --lst.end();
    }
    for(int m = 0;m < M;m++)
    {
        cin >> p >> q;
        list<int>::iterator inpos = vec[p];
        if(q > 0)
        {
            q++;
            while(q)
            {
                inpos++;
                q--;
            }
        }
        else
        {
            while(q)
            {
                inpos--;
                q++;
            }
        }
        lst.splice(inpos,lst,vec[p]);
    }
    for(list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        cout << *it << " ";
    system("pause");
    return 0;
}