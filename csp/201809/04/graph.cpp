/*****************************************
 About:����ͼ�ĵϽ�˹����(Dijkstra)�㷨ʵ��
 Author: WoXiang
 Reference: www.WuTianQi.com(Blog)
 ****************************************/

#include <iostream>
using namespace std;

#define MaxNum  100
#define INFINITY INT_MAX

struct Graph
{
    int vexnum;
    int arcnum;
    int arcs[MaxNum][MaxNum];
};

//��Դ�ڵ�root���������нڵ�����·��
void Dijkstra(int root, int *dist, int *prev, Graph &G)
{
    int i,j;
    int min;
    int u;
    bool Status[MaxNum];        //�ж��Ƿ��Ѵ���õ㵽S����
    for(i = 1;i <= G.vexnum;i++)       //��ʼ��
    {                           
        dist[i] = G.arcs[root][i];
        Status[i] = false;      
        if(dist[i] == INFINITY)
            prev[i] = 0;
        else    
            prev[i] = root;
    }
    dist[root] = 0;
    Status[root] = true;

    //���ν�δ����S���ϵĽ���У�ȡdist[]��Сֵ�Ľ��
    //���뼯��S�У�һ��S����������V�еĶ��㣬dist�ͼ�¼
    //�˴�Դ�㵽������������֮������·�����ȡ�

    for(i = 2;i <= G.vexnum;i++)
    {
        min = INFINITY;
        u = root;
        //�ҳ���ǰδʹ�õĵ�j��dist[j]��Сֵ
        for(j = 1;j <= G.vexnum;j++)
        {
            if(!Status[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
                //���浱ǰ�ڽӵ��о�����С�ĺ���
            }   
        }
        Status[u] = true;      //��ʾu����뼯��S��
        //����dist
        for(j = 1;j <= G.vexnum;j++)
        {
            if((!Status[j]) && G.arcs[u][j] < INFINITY)
            {
                if(dist[u] + G.arcs[u][j] < dist[j])
                {
                    dist[j] = dist[u] + G.arcs[u][j];
                    prev[j] = u;
                }
            }
        }
    }
}

void SreachPath(int *prev, int v,int u)
{
    int que[MaxNum];
    int tot = 1;
    que[tot] = u;
    tot++;
    int temp = prev[u];
    while(temp != v)
    {
        que[tot] = temp;
        tot++;
        temp = prev[temp];
    }
    que[tot] = v;
    for(int i = tot;i >= 1;i--)
    {
        if(i != 1)
            cout << que[i] << "---> ";
        else    
            cout << que[i] << endl;
    }
}

int main()
{
    int dist[MaxNum];           //��ʾ��ǰ�㵽Դ�������·������
    int prev[MaxNum];           //��¼��ǰ���ǰһ�����
    Graph G;                    //����ͼ
    cin >> G.vexnum;            //���붥����
    cin >> G.arcnum;            //�������
    int p,q,weight;
    int i,j;
    for(i = 1;i <= G.vexnum;i++)
    {                           //��ʼ���ڽӾ���
        for(j = 1;j <= G.vexnum;j++)
        {
            G.arcs[i][j] = INFINITY;
        }
    }
    for(i = 1;i <= G.arcnum;i++)
    {
        cin >> p >> q >> weight;
        G.arcs[p][q] = weight;
        G.arcs[q][p] = weight;  //����ͼ
    }
    for(i = 1;i <= G.vexnum;i++)
        dist[i] = INFINITY;
    Dijkstra(1,dist,prev,G);
    
    //���·������
    cout << "Դ�㵽���һ����������·������:" << dist[G.vexnum] << endl;

    //���·��
    cout << "Դ�㵽���һ�������·��Ϊ:";
    SreachPath(prev,1,G.vexnum);

    system("pause");
    return 0;
}