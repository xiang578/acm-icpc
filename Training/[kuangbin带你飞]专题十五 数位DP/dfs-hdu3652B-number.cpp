#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[15];
int dp[15][15][3];
//dp[i][j][k]
//i:数位
//j:余数
//k:3种状态，0-没有1，1-有1，2-有13

//pos为当前处理的数位（权重表示法，也就是剩下pos+1位待填数）
//mod-余数，have-状态;
//lim-后面的数是否可以任意填，1-不可以，0-可以
int dfs(int pos,int mod,int have,int lim)
{
    int n,i,ans=0,mod_x,have_x;

    //余数为0，有13，返回一种结果
    if(pos<=0)
        return mod==0&&have==2;

    //已经搜索过了
    if(!lim&&dp[pos][mod][have]!=-1)
        return dp[pos][mod][have];

    //判断本位枚举的范围
    n=lim?num[pos]:9;
    for(i=0;i<=n;i++)
    {
        mod_x=(mod*10+i)%13;//重新计算余数
        have_x=have;
        if(have==0&&i==1)
            have_x=1;
        if(have==1&&i!=1)
            have_x=0;
        if(have==1&&i==3)
            have_x=2;
        ans+=dfs(pos-1,mod_x,have_x,lim&&i==n);
    }

    //dp[pos][mod][have]要保存的是pos之后可以任意填的结果
    //存在dfs(...,1)和dfs(...,0)的区别，如果lim=1时，记录dp可能会导致错误
    //所以每一次dfs(...,1)都要重新计算
    if(!lim)
        dp[pos][mod][have]=ans;
    return ans;
}

int main()
{
    int n,i;
    while(~scanf("%d",&n))
    {
        memset(num,0,sizeof(num));
        memset(dp,0xff,sizeof(dp));
        i=0;
        while(n)
        {
            num[++i]=n%10;
            n/=10;
        }
        printf("%d\n",dfs(i,0,0,1));
    }
    return 0;
}
