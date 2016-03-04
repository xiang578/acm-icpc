#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll euler_phi(ll n)
{
    ll m=(ll)sqrt(n+0.5);
    ll ans=n;
    for(ll i=2; i<=m; i++)
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0) n/=i;
        }
    if(n>1) ans=ans/n*(n-1);
    return ans;
}

int main()
{
    ll n,t;
    while(scanf("%lld",&n))
    {
        if(n==1||(n%2==0)) printf("2^? mod %lld = 1\n",n);
        else printf("2^%lld mod %lld = 1\n",euler_phi(n),n);
    }
    return 0;
}
