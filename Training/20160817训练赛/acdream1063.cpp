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
const int N=1e6+10;

struct node
{
    int l,r;
    int has,cnt,num;
} p[N];
int q,t,tot,b[100],a[100],ans;
char s[1024];

int get(int x)
{
    int cnt=0;
    memset(a,0,sizeof(a));
    if(x==0)
    {
        a[0]=0;
        cnt++;
    }
    else
    {
        while(x!=0)
        {
            a[cnt]=x%2;
            x/=2;
            cnt++;
        }
    }
    //printf("%d\n",cnt);
    for(int i=30; i>=0; i--)
    {
        b[i]=a[30-i];
    }
    return 31;
}
void in(int o,int now,int cnt)
{
    p[o].cnt++;
    if(now==cnt)
    {
        p[o].has++;
        p[o].num=t;
        return ;
    }
    if(b[now]==1)
    {
        if(p[o].r==-1)
        {
            p[o].r=tot;
            p[tot].l=-1;
            p[tot].r=-1;
            p[tot].has=0;
            p[tot].cnt=0;
            tot++;
        }
        in(p[o].r,now+1,cnt);
    }
    else
    {
        if(p[o].l==-1)
        {
            p[o].l=tot;
            p[tot].l=-1;
            p[tot].r=-1;
            p[tot].has=0;
            p[tot].cnt=0;
            tot++;
        }
        in(p[o].l,now+1,cnt);
    }
}

void de(int o,int now,int cnt)
{
    //printf("%d %d\n",now,cnt);
    p[o].cnt--;
    if(now==cnt)
    {
        p[o].has--;
        //printf("    %d\n",p[o].num);
        return ;
    }
    if(b[now]==1)
    {
        de(p[o].r,now+1,cnt);
    }
    else
    {
        de(p[o].l,now+1,cnt);
    }
}

void query1(int o,int now)
{
    //printf("%d %d %d\n",now,p[o].cnt,x);
    if(p[o].cnt==0) return ;
    if(p[o].has!=0)
    {
        if(ans==-1) ans=t^p[o].num;
        else ans=max(ans,t^p[o].num);
    }
    if(b[now]==0)
    {
        if(p[o].r!=-1&&p[p[o].r].cnt!=0)
        {
            query1(p[o].r,now+1);
        }
        else if(p[o].l!=-1&&p[p[o].l].cnt!=0)
        {
            query1(p[o].l,now+1);
        }
    }
    else if(b[now]==1)
    {
        if(p[o].l!=-1&&p[p[o].l].cnt!=0)
        {
            query1(p[o].l,now+1);
        }
        else if(p[o].r!=-1&&p[p[o].r].cnt!=0)
        {
            query1(p[o].r,now+1);
        }
    }
}

void query2(int o,int now)
{
    //printf("%d %d %d\n",now,p[o].cnt,x);
    if(p[o].cnt==0) return ;
    if(p[o].has!=0)
    {
        if(ans==-1) ans=t^p[o].num;
        else ans=min(ans,t^p[o].num);
    }
    if(b[now]==1)
    {
        if(p[o].r!=-1&&p[p[o].r].cnt!=0)
        {
            query2(p[o].r,now+1);
        }
        else if(p[o].l!=-1&&p[p[o].l].cnt!=0)
        {
            query2(p[o].l,now+1);
        }
    }
    else if(b[now]==0)
    {
        if(p[o].l!=-1&&p[p[o].l].cnt!=0)
        {
            query2(p[o].l,now+1);
        }
        else if(p[o].r!=-1&&p[p[o].r].cnt!=0)
        {
            query2(p[o].r,now+1);
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,cnt;
    scanf("%d",&_);
    while(_--)
    {
        tot=0;
        p[tot].l=-1;
        p[tot].r=-1;
        p[tot].has=0;
        p[tot].cnt=0;
        tot++;
        scanf("%d",&q);
        for(int i=0; i<q; i++)
        {
            scanf("%s%d",s,&t);
            cnt=get(t);
            if(s[0]=='i')
            {
                in(0,0,cnt);
            }
            else if(s[2]=='i')
            {
                ans=-1;
                query2(0,0);
                printf("%d\n",ans);
            }
            else if(s[2]=='a')
            {
                ans=-1;
                query1(0,0);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
