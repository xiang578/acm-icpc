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
const double eps=1e-3;
const ll mod=1000000007;
const int N=2048;
const int M=1e6+10;
int w[M],v[M];
int n,k;
struct node
{
    int id;
    double w,v,val,u;
}p[M];
int cmp(node n1,node n2)
{
    return n1.val>n2.val;
}

double get(double m)
{
    for(int i=0;i<n;i++)
    {
        p[i].val=p[i].v-m*p[i].w;
        p[i].u=0;
    }
    sort(p,p+n,cmp);
    double tv=0,tw=0;
    for(int i=0;i<k;i++)
    {
        tv+=p[i].v;
        tw+=p[i].w;
        p[i].u=1;
    }
    return tv/tw;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d",&n,&k))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].v,&p[i].w);
            p[i].id=i+1;
        }
        double ans=1,t;
        while(1)
        {
            t=get(ans);
            if(fabs(ans-t)<eps)
                break;
            ans=t;
        }
        int f=0;
        for(int i=0;i<n;i++)
        {
            if(p[i].u==0) continue;
            if(!f) f++;
            else printf(" ");
            printf("%d",p[i].id);
        }
        printf("\n");
    }
    return 0;
}
