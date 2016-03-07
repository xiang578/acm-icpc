/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.top
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
const ll mod=1e9+7;
const int N=2048;
int a[123456];
ll ans;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,f,n;
    cin>>_;
    while(_--)
    {
        scanf("%d",&n);
        f=0;
        for(i=1; i<n; i++)
            scanf("%d",&a[i]);
        a[n]=0;
        ans=26;
        for(i=n-1; i>=1; i--)
        {
            if(!a[i]) ans=(ans*25)%mod;
            else if(a[i]!=a[i+1]+1) {f=1;break;}
        }
        if(f)
        {
            printf("0\n");
            continue;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

/*
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
const ll mod=1e9+7;
const int N=2048;
int a[123456];
ll ans;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int _,i,f,cnt,n;
    cin>>_;
    while(_--)
    {
        scanf("%d",&n);
        f=0;
        for(i=1; i<n; i++)
            scanf("%d",&a[i]);
        a[n]=0;
        ans=1;
        cnt=0;
        for(i=n-1; i>=1; i--)
        {
            if(a[i]==0) cnt++;
            else if(a[i+1]!=a[i]-1) {f=1;break;}
        }
        if(f)
        {
            printf("0\n");
            continue;
        }
        ans=26;
        for(i=0; i<cnt; i++)
        {
            ans=ans*25;
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
*/
