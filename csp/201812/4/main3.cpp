/********************************************
About: Csp201812-04
Author: woxiang
Reference:
********************************************/

#include <iostream>
using namespace std;
#include <algorithm>

#define MAX_N 500001
#define MAX_M 100001

struct Edge
{
    int start;
    int end;
    int value;
    bool operator < (Edge &edge){
        return this->value < edge.value;
    }
};

Edge edges[MAX_M];
int Pre[MAX_N];

int find(int x)
{
    if(Pre[x] == x)
        return x;
    else
    {
        Pre[x] = find(Pre[x]);
        return Pre[x];
    }
}

void kruskal(int m,int n)
{
    int total = 0;
    int i;
    int u,v;
    int max = 0;
    for(i = 1;i <= m;i++)
    {
        u = find(edges[i].start);
        v = find(edges[i].end);
        if(u == v)          //±ÜÈ¦·¨
            continue;
        max = (edges[i].value < max) ? max : edges[i].value;
        total++;
        Pre[v] = u;
        if(total == n-1)
            break;
    }
    cout << max << endl;
}

int main()
{
    int N,M,root;
    cin >> N >> M >> root;
    int i;
    for(i = 1;i <= N;i++)
        Pre[i] = i;
    for(i = 1;i <= M;i++)
    {
        cin >> edges[i].start >> edges[i].end >> edges[i].value;
    }
    sort(edges + 1,edges + M + 1);
    kruskal(M,N);
    system("pause");
    return 0;
}


