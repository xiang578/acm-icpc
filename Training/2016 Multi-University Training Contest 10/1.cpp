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
int cnt,a1,a2,b1,b2,n,m;
ll get1()
{
    int x,y;
    ll ret=0;
    if(cnt%2==1) x=y=cnt/2+1;
    else x=cnt/2,y=cnt/2+1;

    if(x+a1-1<=b1)
    {
        ret+=a[a1+x-1];
    }
    else
    {
        x-=b1-a1+1;
        ret+=a[a2+x-1];
    }

    if(y+a1-1<=b1)
    {
        ret+=a[a1+y-1];
    }
    else
    {
        y-=b1-a1+1;
        ret+=a[a2+y-1];
    }
    return ret;
}

ll get2()
{
    int x,y,t;
    ll ret=0;
    if(cnt%2==1) x=y=cnt/2+1;
    else x=cnt/2,y=cnt/2+1;
    if(x+a1-1<a2)
    {
        ret+=a[x+a1-1];
    }
    else
    {
        x-=a2-a1;
        t=(b1-a2+1)*2;
        if(x>t)
        {
            x-=t;
            ret+=a[b1+x];
        }
        else
        {
            if(x%2==1) x=x/2+1;
            else x/=2;
            ret+=a[a2+x-1];
        }
    }

    x=y;
    if(x+a1-1<a2)
    {
        ret+=a[x+a1-1];
    }
    else
    {
        x-=a2-a1;
        t=(b1-a2+1)*2;
        if(x>t)
        {
            x-=t;
            ret+=a[b1+x];
        }
        else
        {
            if(x%2==1) x=x/2+1;
            else x/=2;
            ret+=a[a2+x-1];
        }
    }
    return ret;
}

ll get3()
{
    int x,y,t;
    ll ret=0;
    if(cnt%2==1) x=y=cnt/2+1;
    else x=cnt/2,y=cnt/2+1;

    if(x+a1-1<a2)
    {
        ret+=a[x+a1-1];
    }
    else
    {
        x-=a2-a1;
        t=(b2-a2+1)*2;
        //printf("%d\n",x);
        if(x>t)
        {
            x-=t;
            ret+=a[b2+x];
        }
        else
        {
            if(x%2==1) x=x/2+1;
            else x/=2;
            ret+=a[a2+x-1];
            //printf("%d\n",a2+x-1);
        }
    }

    x=y;
    if(x+a1-1<a2)
    {
        ret+=a[x+a1-1];
    }
    else
    {
        x-=a2-a1;
        t=(b2-a2+1)*2;
        if(x>t)
        {
            x-=t;
            ret+=a[b2+x];
        }
        else
        {
            if(x%2==1) x=x/2+1;
            else x/=2;
            ret+=a[a2+x-1];
        }
    }
    //printf("%d %d %d %d %d\n",a1,a2,b2,b1,ret);
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",a+i);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
            cnt=b1-a1+1+b2-a2+1;
            if(a1==a2)
            {
                if(b2>b1) swap(b1,b2);
            }
            else if(a1>a2)
            {

                swap(a1,a2);
                swap(b1,b2);
            }
            ll ans;
            if(b1<a2) ans=get1();
            else if(a1<=a2&&b2<=b1) ans=get3();
            else  ans=get2();
            printf("%.1f\n",1.0*ans/2);
        }
    }
    return 0;
}

/*
1
10 10
1 2 3 4 5 6 7 8 9 10
1 2
1 10
*/
