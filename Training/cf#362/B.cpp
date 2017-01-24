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
char s[1024];
string ans;
int main()
{
    int a,d;
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d.%s",&a,s);
    int n=strlen(s);
    ans="";
    for(int i=0;i<n;i++)
    {
        d=0;
        if(s[i]=='e')
        {
            s[i]=0;
            for(int j=i+1;j<n;j++)
                d=d*10+s[j]-'0';
            break;
        }
    }
    n=strlen(s);
    ans=a+'0';
    if(n==d)
    {
        for(int i=0;i<n;i++)
            ans+=s[i];
    }
    else if(n<d)
    {
        for(int i=0;i<n;i++)
            ans+=s[i];
        for(int j=n;j<d;j++)
            ans+='0';
    }
    else if(n>d)
    {
        for(int i=0;i<d;i++)
            ans+=s[i];
        ans+='.';
        for(int i=d;i<n;i++)
            ans+=s[i];
    }
    int t1=0,t2=0,f=0;
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]=='.') {f=1;continue;}
        if(f==0&&!t1)
        {
            t1=t1*10+ans[i]-'0';
        }
        else if(f==1&&!t2)
        {
            t2=t2*10+ans[i]-'0';
        }
        if(t1&&t2) break;
    }
    if(!t1&&!t2) puts("0");
    else if(t1&&!t2)
    {
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]=='.') break;
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    else cout<<ans<<endl;
    return 0;
}
