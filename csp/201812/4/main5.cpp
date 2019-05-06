/***********************************
 * About: csp 201812-4 数据中心
 * Author: sunfeng
 * Date: 2019-3-15
 ***********************************/
#include <iostream>
using namespace std;
#include <algorithm>

#define MAX_N 500001
#define MAX_M 100001

struct Edge             //边的类型
{   
    int from;           //边的起点
    int to;             //边的终点
    int value;          //边的权重
    bool operator < (Edge edge){
        return this->value < edge.value;
    }
};

Edge edges[MAX_M];      //边的集合
int PreVec[MAX_N];      //顶点的前继顶点

int find(int x)         //寻找顶点的前继顶点
{
    if(PreVec[x] == x)
        return x;
    else
    {
        PreVec[x] = find(PreVec[x]);
        return PreVec[x];
    } 
}

void kruskal(int m,int n)
{
    int i;
    int u,v;
    int max = 0;
    int count = 0;
    for(i = 1;i <= m;i++)
    {   
        u = find(edges[i].from);
        v = find(edges[i].to);
        if(u == v)
            continue;
        count++;
        PreVec[v] = u;
        if(max < edges[i].value)
            max = edges[i].value;
        if(count == n-1)
            break;
    }
    cout << max << endl;
}

int main()
{
    int n,m,root;
    int i;
    cin >> n >> m >> root;
    for(i = 1;i <= n;i++)
        PreVec[i] = i;
    for(i = 1;i <= m;i++)
        cin >> edges[i].from >> edges[i].to >> edges[i].value;
    sort(edges + 1,edges + m + 1);
    kruskal(m,n);
    system("pause");
    return 0;
}