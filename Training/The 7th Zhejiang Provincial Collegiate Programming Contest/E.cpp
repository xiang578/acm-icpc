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
int p[5000];

void init()
{
    memset(p,0,sizeof(p));
    p[1]=1;
    for(int i=2; i<5000; i++)
    {
        if(p[i]==1) continue;
        for(int j=2*i; j<5000; j+=i)
        {
            p[j]=1;
        }
    }
}
int ok(int x)
{
    if(x%100==0)
    {
        if(x%400==0) return 1;
        else return 0;
    }
    else if(x%4==0)
        return 1;
    else return 0;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,ans;
    init();
    scanf("%d",&_);
    while(_--)
    {
        int y1,y2,m1,m2,d1,d2;
        scanf("%d%d%d%d%d%d",&y1,&m1,&d1,&y2,&m2,&d2);
        ans=0;
        while(y1!=y2||m1!=m2||d1!=d2)
        {
            if(!p[m1]&&!p[d1]) ans++;
            //printf("%d %d %d %d\n",p[m1],p[d1],m1,d1);
            d1++;
            if(d1==32)
            {
                d1=1;
                m1++;
                if(m1==13)
                {
                    m1=1;
                    y1++;
                }
                continue;
            }
            if(d1==31&&(m1==4||m1==6||m1==11||m1==9))
            {
                d1=1;
                m1++;
                continue;
            }
            if(d1==30&&m1==2)
            {
                m1++;
                d1=1;
                continue;
            }
            if(d1==29&&m1==2&&ok(y1)==0)
            {
                m1++;
                d1=1;
                continue;
            }

        }
        if(!p[d2]&&!p[m2]) ans++;
        printf("%d\n",ans);
    }
    return 0;
}
