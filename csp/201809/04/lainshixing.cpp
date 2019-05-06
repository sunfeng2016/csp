/*************************************
 * About: ͼ����ʽǰ���Ǵ洢��ʾ
 * Author:
 * Date:
 * ��ʽǰ���ǣ�ÿ�����i����һ��������������������Ǵ�i���������бߵļ���
 *���Ա��ڽӱ����Ƕ��㼯�ϣ����ߵı�ʾΪһ����Ԫ��(u, v, w, next)������
 * (u, v)��������ߵ����򶥵�ԣ�w������ϵ�Ȩֵ��nextָ����һ���ߡ�
 *************************************/

#include <iostream>
using namespace std;
#include <memory.h>

const int maxn = 1e5 + 10;
const int maxm = 1e5 + 10;

int head[maxn];                 //head[i]���ڴ洢���Ϊi�ĵ�ָ��ĵ�һ���ߵ�λ��
struct Edge
{
    int to;                     //�ߵ��յ�
    int w;                      //��Ȩ
    int next;                   //��ʽ��¼��һ���ߵ�λ��
}edge[maxm];

int main()
{
    int m,n;
    int tol = 0;
    memset(head,-1,sizeof(head));
    cin >> n >> m;
    //��ͼ����
    while(m--){
        int f,t,w;
        cin >> f >> t >> w;
        edge[tol].to = t;
        edge[tol].w = w;
        edge[tol].next = head[f];
        head[f] = tol++;
    }
    //��������
    for(int i = 1;i <= n;i++)
    {
        cout << i << ": ";
        for(int k = head[i]; k != -1; k = edge[k].next)
        {
            cout << edge[k].to << " * " << edge[k].w << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
