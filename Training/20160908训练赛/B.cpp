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

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,a[N],all=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        all+=a[i];
    }
    if(all%n!=0) puts("Unrecoverable configuration.");
    else
    {
        all/=n;
        int ok=0,x=-1,y=-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]>all)
            {
                ok=1;
                if(x!=-1) ok=-1;
                x=i;
            }
            if(a[i]<all)
            {
                ok=1;
                if(y!=-1) ok=-1;
                y=i;
            }
            if(ok==-1) break;
        }
        if(!ok) puts("Exemplary pages.");
        else if(ok==-1) puts("Unrecoverable configuration.");
        else printf("%d ml. from cup #%d to cup #%d.\n",a[x]-all,y+1,x+1);
    }
    return 0;
}
