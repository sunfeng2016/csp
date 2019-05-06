/*
201812-4
*/

#include <iostream>
using namespace std;
#include <algorithm>

struct Edge                     //边的类型
{
    int start;                  //边的起点
    int end;                    //边的终点
    int val;                    //边的权值
    bool operator < (Edge &obj){//重载<
        return this->val < obj.val;
    }
};

Edge edges[100001];             //存放边
int pre[500001];                //存放邻接顶点
int MaxEdge = 0;
int n,m;

int find(int x)                 //查找某条路径的第一个点，为了判断是否有回路构成
{
    if(pre[x] == x)
    {
        return x;
    }
    else
    {
        pre[x] = find(pre[x]);
        return pre[x];
    }
}

void kruskal()                  //使用克鲁斯卡尔算法构造最小生成树
{
    int total = 0;              
    int u,v;
    for(int i = 1;i <= m;i++)   //每次选择最小的一条边
    {
        u = find(edges[i].start);
        v = find(edges[i].end);
        if(u == v)              //避圈法
            continue;
        MaxEdge = max(MaxEdge,edges[i].val);
        pre[u] = v;
        total++;        
        if(total == n-1)        //直到生成n-1条边为止
            break;
    }
}

int main()
{
    int i;
    cin >> n >> m;
    int root;
    cin >> root;
    for(i = 1;i <= n;i++)
        pre[i] = i;
    for(i = 1;i <= m;i++)
    {
        cin >> edges[i].start >> edges[i].end >> edges[i].val;
    }
    sort(edges + 1,edges + m + 1);
    kruskal();
    cout << MaxEdge << endl;
    system("pause");
    return 0;
}
