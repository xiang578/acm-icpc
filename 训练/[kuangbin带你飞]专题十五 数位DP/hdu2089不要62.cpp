#include<bits/stdc++.h>
using namespace std;
int f[100][100],dig[10];

int get(int x)
{
    int i,j,cnt=1,ans=0;;
    while(x)
    {
        dig[cnt]=x%10;
        x/=10;
        cnt++;
    }
    dig[cnt]=0;
    for(i=cnt-1;i>=1;i--)
    {
        for(j=0;j<dig[i];j++)
        {
            if(j==4||(j==2&&dig[i+1]==6))
                ans=ans+f[i][j];
        }
        if(dig[i]==4||(dig[i]==2&&dig[i+1]==6)) break;
    }
    return ans;
}

int main()
{
    int n,m;
    f[0][0]=1;

    for(int i=1;i<=7;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(j==4) continue;
            for(int k=0;k<=9;k++)
            {
                if(k==4||(j==6&&k==2)) continue;
                f[i][j]=f[i-1][k]+f[i][j];
            }
        }
    }

    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        printf("%d\n",get(m+1)-get(n));
    }
    return 0;
}
