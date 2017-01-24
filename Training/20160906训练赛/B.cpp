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
const int M=1e6+10;
int a[N];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,k,t,x,y;
    cin>>n>>m>>k>>t;
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&x,&y);
        a[i]=(x-1)*m+y;
    }
    sort(a,a+k);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&x,&y);
        int e=(x-1)*m+y;
        int q=lower_bound(a,a+k,e)-a;
        //printf("%d %d\n",e,q);
        if(q<k&&e==a[q]) printf("Waste\n");
        else
        {
            e-=q;
            if(e%3==1) puts("Carrots");
            else if(e%3==2) puts("Kiwis");
            else puts("Grapes");
        }
    }
    return 0;
}
