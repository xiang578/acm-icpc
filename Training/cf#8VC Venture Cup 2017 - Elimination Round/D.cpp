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
const int N=2048;
const int M=1e7+10;
int n,k;
ll b[M];

void add(int x)
{
    while(x<=n)
    {
        b[x]++;
        x+=x&(-x);
    }
}

int get(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=b[x];
        x-=x&(-x);
    }
    return ret;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>n>>k;
    memset(b,0,sizeof(b));
    int st=1,ed;
    ll ans=2;
    if(k*2<n)
    {
        for(int i=0; i<n; i++)
        {
            ed=st+k;
            if(ed>n) ed-=n;
            if(st<ed)
            {
                //printf("\n%d %d \n",get(ed),get(st-1));
                ans+=get(ed)-get(st-1);
            }
            else
            {
                ans+=get(n)-get(st-1)+get(ed);
            }
            add(st);
            add(ed);
            st=ed;
            if(i==n-1) ans--;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            ed=st+k;
            if(ed>n) ed-=n;
            if(st<ed)
            {
                //printf("\n%d %d \n",get(ed),get(st-1));
                ans+=get(n)-get(ed-1)+get(st);
            }
            else
            {

                ans+=get(st)-get(ed-1);
            }
            add(st);
            add(ed);
            st=ed;
            if(i==n-1) ans--;
            cout<<ans<<" ";
        }
        cout<<endl;
    }
    return 0;
}
