/**************************************************************
 * About: csp 201812-4
 * Author: 孙峰
 * Date: 2019-3-11
 **************************************************************/
#include <iostream>
using namespace std;
#include <algorithm>

#define MAX_M 500001
#define MAX_N 100001

struct Edge
{
    int start;
    int end;
    int value;
    bool operator < (Edge edge){
        return this->value < edge.value;
    }
};

Edge edges[MAX_M];          //存放边的向量
int Pre_Vector[MAX_N];      //存放每个顶点前继顶点的向量

int find(int x)
{
    if(Pre_Vector[x] == x)
        return x;
    else
    {
        Pre_Vector[x] = find(Pre_Vector[x]);
        return Pre_Vector[x];
    }
}

void Kruskal(int m,int n)
{
    int count = 0;
    int max = 0;
    int u,v;
    for(int i = 1;i <= m;i++)
    {
        u = find(edges[i].start);
        v = find(edges[i].end);
        if(u == v)
            continue;
        if(max < edges[i].value)
            max = edges[i].value;
        count++;
        Pre_Vector[v] = u;
        if(count == n-1)
            break;
    }
    cout << max << endl;
}

int main()
{
    int n,m;
    int i;
    int root;
    cin >> n >> m >> root;
    for(i = 1;i <= m;i++)
        cin >> edges[i].start >> edges[i].end >> edges[i].value;
    for(i = 1;i <= n;i++)
        Pre_Vector[i] = i;
    sort(edges + 1,edges + m + 1);
    Kruskal(m,n);
    system("pause");
    return 0;
}