//poj 2135 最小费用最大流
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int N=5024;
const int inf=0x7fffffff;
struct Edge
{
    int from,to,cap,flow,cost;
};
vector<Edge>edges;
vector<int>G[N];
int inq[N],p[N],d[N],a[N];

void AddEdge(int from, int to,int cap, int cost)
{
    Edge tp;
    tp.from=from,tp.to=to,tp.cap=cap,tp.flow=0,tp.cost=cost;
    edges.push_back(tp);

    tp.from=to,tp.to=from,tp.cap=0,tp.flow=0,tp.cost=-cost;
    edges.push_back(tp);

    int g=edges.size();
    G[from].push_back(g-2);
    G[to].push_back(g-1);
}

int BellmanFord(int s,int t,int &flow, int &cost,int n)
{
    int i,j,u;
    for(i=0; i<=n+1; i++) d[i]=inf;
    memset(inq,0,sizeof(inq));
    d[s]=0;
    inq[s]=1;
    p[s]=0;
    a[s]=inf;
    queue<int>Q;
    Q.push(s);
    while(!Q.empty())
    {
        u=Q.front();
        Q.pop();
        inq[u]=0;
        for(i=0; i<G[u].size(); i++)
        {
            Edge &e=edges[G[u][i]];
            if(e.cap>e.flow&&d[e.to]>d[u]+e.cost)
            {
                d[e.to]=d[u]+e.cost;
                p[e.to]=G[u][i];
                a[e.to]=min(a[u],e.cap-e.flow);
                if(!inq[e.to])
                {
                    Q.push(e.to);
                    inq[e.to]=1;
                }
            }
        }
    }
    if(d[t]==inf) return 0;
    flow+=a[t];
    cost+=d[t]*a[t];
    u=t;
    while(u!=0)
    {
        edges[p[u]].flow+=a[t];
        edges[p[u]^1].flow-=a[t];
        u=edges[p[u]].from;
    }
    return 1;
}

int Mincost(int s,int t,int n)
{
    int flow=0,cost=0;
    while(BellmanFord(s,t,flow,cost,n));
    return cost;
}

void init(int n)
{
    for(int i=0; i<=n+1; i++) G[i].clear();
        edges.clear();
}

int main()
{
    int i,u,v,c,n,m;
    while(~scanf("%d%d",&n,&m))
    {
        init(n);
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&c);
            AddEdge(u,v,1,c);
            AddEdge(v,u,1,c);
        }
        AddEdge(0,1,2,0);
        AddEdge(n,n+1,2,0);
        printf("%d\n",Mincost(0,n+1,n));
    }
    return 0;
}
