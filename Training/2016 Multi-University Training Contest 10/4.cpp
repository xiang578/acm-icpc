#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200000+5;
ll a[N],ans;

struct Tree
{
    int left,right;
    ll sum,f;
}tree[4*N+10];


void build(int id,int l,int r)
{
    tree[id].left=l;
    tree[id].right=r;
    tree[id].f=-1;
    if (l==r)
        tree[id].sum=a[l];
    else
    {
        int mid=(l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    }
}

void pushdown(int id)
{
    if(tree[id].f!=-1)
    {
        tree[id*2].f=tree[id*2+1].f=tree[id].f;
        tree[id*2].sum=tree[id].f*(tree[id*2].right-tree[id*2].left+1);
        tree[id*2+1].sum=tree[id].f*(tree[id*2+1].right-tree[id*2+1].left+1);
        tree[id].f=-1;
    }
}

void update(int id,int l,int r, ll val)
{
    if (l<=tree[id].left&&tree[id].right<=r)
    {
        tree[id].f=val;
        tree[id].sum=val*(tree[id].right-tree[id].left+1);
    }
    else
    {
        pushdown(id);
        int mid=(tree[id].left+tree[id].right)/2;
        if(l<=mid) update(id*2,l,r,val);
        if(r>mid) update(id*2+1,l,r,val);
        tree[id].sum=tree[id*2].sum+tree[id*2+1].sum;
    }

}

ll query(int id,int l,int r)
{
    printf("%d %d\n",l,r);
    if (l==tree[id].left&&tree[id].right==r)
    {
        pushdown(id);
        printf("%lld\n",tree[id].sum);
        return tree[id].sum;
    }
    else
    {
        pushdown(id);
        int mid=(tree[id].left+tree[id].right)/2;
        if(r<=mid) return query(id*2,l,r);
        else if(l>mid) return query(id*2+1,l,r);
        else return query(id*2,l,mid)+query(id*2+1,mid+1,r);
    }
}

int main()
{
    int n,m;
    int u,v,t;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n-1;i++)
            scanf("%lld",&a[i]);
        build(1,1,n-1);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u,&v);
            //if(u>v) {t=u;u=v;v=t;};
            if(u>v) swap(u,v);
            v--;
            //printf("%d %d\n",u,v);
            ll ans=query(1,u,v);
            printf("%lld\n",ans);
            update(1,u,v,0);
        }
    }
    return 0;
}
