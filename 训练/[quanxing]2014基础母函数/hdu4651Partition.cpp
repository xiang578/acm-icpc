#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
const int _max = 100000+5;
int c1[_max], c2[_max],ans[_max];
int main()
{
    //int n,i,j,k;
    //freopen("out.txt","w",stdout);
    int n;   //
    int i, j, k;
    memset(ans,0,sizeof(ans));
    int _;
    cin>>_;
    while(_--)
    {
        //scanf("%d",&n);
        n=100000;
        if(ans[n])
        {
            printf("%d\n",ans[n]);
            continue;
        }
        for(i=0; i<=n; ++i)
        {
            c1[i] = 1;
            c2[i] = 0;
        }
        for(i=2; i<=15; ++i)
        {
            //printf("%d\n",i);
            for(j=0; j<=n; ++j)
                for(k=0; k+j<=n; k+=i)
                {
                    printf("%d %d %d\n",i,j,k);
                    c2[j+k] += c1[j];
                    c2[j+k]%=mod;
                }
            for(j=0; j<=n; ++j)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        for(i=0;i<=n;i++)
        {
           printf("c1[%d]=%d;\n",i,c1[i]);
        }
        //cout << c1[n] << endl;
    }
    return 0;
}
