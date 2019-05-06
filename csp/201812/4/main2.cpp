#include <iostream>
using namespace std;
#include <algorithm>

struct Edge
{
    int start;
    int end;
    int value;
    bool operator < (Edge &edge){
        return this->value < edge.value;
    }
};

int Pre_Vector[500001];
Edge edges[100001];

int find(int x)
{
    if(Pre_Vector[x] == x)
    {
        return x;
    }
    else
    {
        Pre_Vector[x] = find(Pre_Vector[x]);
        return Pre_Vector[x];
    }
}

void kruskal(int m)
{
    int i;
    int count = 0;
    int MaxEdge = 0;
    int u,v;
    for(i = 1; i <= m;i++)
    {
        u = find(edges[i].start);
        v = find(edges[i].end);
        if(u == v)
            continue;
        MaxEdge = max(MaxEdge, edges[i].value);
        Pre_Vector[v] = u;
        count++;
        if(count == m-1)
            break;
    }
    cout << MaxEdge << endl;
}

int main()
{
    int i;
    int n,m;
    int root;
    cin >> n >> m >> root;
    for(i = 1;i <= m;i++)
        cin >> edges[i].start >> edges[i].end >> edges[i].value;
    sort(edges + 1,edges + m + 1);
    for(i = 1;i <= n;i++)
        Pre_Vector[i] = i;
    kruskal(m);
    system("pause");
    return 0;
}
