/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=1e5+10;
ll a[N];
int n,m;
struct node
{
    int f,s;
    ll sum,mx,mi;
}t[N*4];

void build(int o,int l,int r)
{
    t[o].f=-1;
    t[o].s=-1;
    if(l!=r)
    {
        int mid=(l+r)/2;
        build(o*2,l,mid);
        build(o*2+1,mid+1,r);
        t[o].sum=t[o*2+1].sum+t[o*2].sum;
        t[o].mx=max(t[o*2+1].mx,t[o*2].mx);
        t[o].mi=min(t[o*2+1].mi,t[o*2].mi);
    }
    else
    {
        t[o].sum=t[o].mx=t[o].mi=a[l];
    }
}
void pushdownf(o)
{

}

void pushdowns(int o)
{


}

void update1(int o,int l,int r,int x,int y,ll v)
{
    if(x<=l&&r<=y)
    {

    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,l,r,t;
    ll x;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",a+i);
        build(1,1,n);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&t);
            if(t==1)
            {
                scanf("%d%d%lld",&l,&r,&x);
                update1(1,1,n,l,r,x);
            }
            else if(t==2)
            {
                scanf("%d%d",&l,&r);
                update2(1,1,n,l,r);
            }
            else if(t==3)
            {
                scanf("%d%d",&l,&r);
                printf("%lld\n",query(1,1,n,l,r));
            }
        }
    }
    return 0;
}
