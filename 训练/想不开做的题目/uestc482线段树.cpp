#include<bits/stdc++.h>
using namespace std;
const int N=100000+10;
typedef long long ll;

struct edge
{
    ll u,v,w;
}g[N];
struct node
{
    ll m,t;
    friend bool operator <(node n1,node n2)
    {
        return n1.m<n2.m;
    }
}p,o;
int n;

int cmp(edge a,edge b)
{
    return a.u<b.u;
}

ll bfs(ll m)
{
    int i;
    priority_queue<node>pq;
    p.m=1;
    p.t=0;
    pq.push(p);
    while(!pq.empty())
    {
        p=pq.top();
        //printf("%d %d\n",p.m,p.t);
        pq.pop();
        if(p.m>=m) return p.t;
        for(i=0;i<n;i++)
        {
            if(g[i].v>p.m) break;
            o.m=g[i].u;
            o.t=p.t+g[i].w;
            printf("%d %d\n",o.m,o.t);
            pq.push(o);
        }
    }
    return -1;
}

int main()
{
    int _,i,cas=0;
    ll m;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%lld",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&g[i].u,&g[i].v,&g[i].w);
        }
        sort(g,g+n,cmp);
        printf("Case #%d: %lld\n",++cas,bfs(m));
    }
    return 0;
}
