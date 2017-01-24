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
const int M=1e5+10;
struct node
{
    int s,t;
}p[N];

int cmp(node n1,node n2)
{
    return n1.s>n2.s;
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].s>>p[i].t;
    }
    sort(p,p+n,cmp);
    int now=m;
    for(int i=0;i<n;i++)
    {
        if(now>=p[i].s) {ans+=now-p[i].s;now=p[i].s;}
        if(p[i].t>ans) ans=p[i].t;
    }
    ans+=now;
    cout<<ans<<endl;
    return 0;
}
