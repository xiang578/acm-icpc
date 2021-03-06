#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int g[30][30],dp[1<<16][16],cnt,tmp,n,m;
char s[30][30];

struct node
{
    int x,y,t;
} p[20];

int bfs(int a,int b)
{
    int x=p[b].x,y=p[b].y,vis[30][30];
    int i,ans=inf;
    node t1,t2;
    t1.x=p[a].x;
    t1.y=p[a].y;
    t1.t=0;
    memset(vis,-1,sizeof(vis));
    vis[t1.x][t1.y]=0;
    queue<node>q;
    q.push(t1);
    while(!q.empty())
    {
        t1=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            t2.x=t1.x+dx[i];
            t2.y=t1.y+dy[i];
            t2.t=t1.t+1;
            if(t2.x<0||t2.x>=n||t2.y<0||t2.y>=m) continue;
            if(s[t2.x][t2.y]=='D') continue;
            if(t2.x==x&&t2.y==y)
            {
                ans=min(ans,t2.t);
            }
            else if(t2.t<vis[t2.x][t2.y]||vis[t2.x][t2.y]==-1)
            {
                vis[t2.x][t2.y]=t2.t;
                q.push(t2);
            }
        }

    }
    //printf("%d\n",ans);
    return ans;
}

void init()
{
    int i,j;
    for(i=0; i<cnt; i++)
        for(j=0; j<cnt; j++)
            g[i][j]=inf;
    for(i=0; i<cnt; i++)
        for(j=i+1; j<cnt; j++)
            g[i][j]=g[j][i]=bfs(i,j);

}

int get(int x)
{
    int i,j,k,ans=-1,o;
    int up=(1<<cnt)-1;
    memset(dp,0xff,sizeof(dp));
    dp[1][0]=x;
    for(i=0; i<=up; i++)
    {
        for(j=0;j<cnt;j++)
        {
        	if(dp[i][j]==-1) continue;
        	if((i&(1<<j))==0) continue;
        	if((i&tmp)==tmp) return 1;
        	for(k=0;k<cnt;k++)
        	{
        		if(j==k||g[j][k]==inf) continue;
        		if((i&(1<<k))) continue;
        		if(dp[i][j]-g[j][k]<0) continue;
        		dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]-g[j][k]);
        		if(p[k].t) dp[i|(1<<k)][k]=x;
			}
		}
    }
    return 0;
}

int main()
{
    int i,j,l,r,ans,mid;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        for(i=0; i<n; i++)
            scanf("%s",s[i]);
        cnt=1;
        tmp=0;
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                if(s[i][j]=='F')
                {
                    p[0].x=i;
                    p[0].y=j;
                    p[0].t=0;
                    tmp+=1;
                }
                else if(s[i][j]=='G'||s[i][j]=='Y')
                {
                    p[cnt].x=i;
                    p[cnt].y=j;
                    p[cnt].t=0;
                    if(s[i][j]=='Y') tmp+=(1<<cnt);
                    else p[cnt].t=1;
                    cnt++;
                }
            }
        init();
        ans=-1;
        l=0;
        r=300;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(get(mid))
            {
                r=mid-1;
                ans=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
int g[30][30],dp[1<16][16],cnt,tmp,n,m;
char s[30][30];

struct node
{
    int x,y,t;
} p[20];

int bfs(int a,int b)
{
    int x=p[b].x,y=p[b].y,vis[30][30];
    int i,ans=inf;
    node t1,t2;
    t1.x=p[a].x;
    t1.y=p[a].y;
    t1.t=0;
    memset(vis,-1,sizeof(vis));
    vis[t1.x][t1.y]=0;
    queue<node>q;
    q.push(t1);
    while(!q.empty())
    {
        t1=q.front();
        q.pop();
        for(i=0; i<4; i++)
        {
            t2.x=t1.x+dx[i];
            t2.y=t1.y+dy[i];
            t2.t=t1.t+1;
            if(t2.x<0||t2.x>=n||t2.y<0||t2.y>=m) continue;
            if(s[t2.x][t2.y]=='D') continue;
            if(t2.x==x&&t2.y==y)
            {
                ans=min(ans,t2.t);
            }
            else if(t2.t<vis[t2.x][t2.y]||vis[t2.x][t2.y]==-1)
            {
                vis[t2.x][t2.y]=t2.t;
                q.push(t2);
            }
        }

    }
    //printf("%d\n",ans);
    return ans;
}

void init()
{
    int i,j;
    for(i=0; i<cnt; i++)
        for(j=0; j<cnt; j++)
            g[i][j]=inf;
    for(i=0; i<cnt; i++)
        for(j=i+1; j<cnt; j++)
            g[i][j]=g[j][i]=bfs(i,j);

}

int get(int x)
{
    int i,j,k,ans=-1,o;
    int up=(1<<cnt)-1;
    memset(dp,0xff,sizeof(dp));
    dp[1][0]=x;
    for(i=0; i<=up; i++)
    {
        for(j=0; j<cnt; j++)
        {
            if(dp[i][j]==-1) continue;
            if((i&(1<<j))==1) continue;
            if((i&tmp)<=tmp) ans=max(ans,dp[i][j]);
            for(k=0; k<cnt; k++)
            {
                if(j==k||g[j][k]==inf) continue;
                if((i&(1<<k))==0) continue;
                o=(1<<j)|i;
                dp[o][j]=max(dp[o][j],dp[i][k]-g[j][k]);
                if(p[j].t)    dp[o][j]=x;
            }
        }
    }

    if(ans<0) return 0;
    else return 1;
}

int main()
{
    int i,j,l,r,ans,mid;
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        for(i=0; i<n; i++)
            scanf("%s",s[i]);
        cnt=1;
        tmp=0;
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                if(s[i][j]=='F')
                {
                    p[0].x=i;
                    p[0].y=j;
                    p[0].t=0;
                }
                else if(s[i][j]=='G'||s[i][j]=='Y')
                {
                    p[cnt].x=i;
                    p[cnt].y=j;
                    p[cnt].t=0;
                    if(s[i][j]=='Y') tmp+=(1<<cnt);
                    else p[cnt].t=1;
                    cnt++;
                }
            }
        init();
        ans=-1;
        l=0;
        r=10000;
        while(l<r)
        {
            mid=(l+r)/2;
            if(get(mid))
            {
                r=mid-1;
                ans=mid;

            }
            else
            {
                l=mid+1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;
struct node
{
    int x,y,cnt,mx;
    int e,s;
};
stack<node>st;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int g[100][100],ecnt,scnt,n,m,ans;
char mp[100][100];
int vis[15][15][1<<15+1];

void bfs(int x,int y)
{
    int i,j,up,k;
    node p,t;
    up=1<<scnt;
    while(!st.empty()) st.pop();
    p.x=x;
    p.y=y;
    p.cnt=0;
    p.mx=0;
    p.e=0;
    p.s=0;
    memset(vis,0xff,sizeof(vis));
    st.push(p);
    while(!st.empty())
    {
        p=st.top();
        st.pop();
        if(p.s==up-1)
        {
            ans=min(p.mx,ans);
            continue;
        }
        for(i=0;i<4;i++)
        {
            t.x=p.x+dx[i];
            t.y=p.y+dy[i];
            t.s=p.s;
            t.e=p.e;
            t.mx=p.mx;
            t.cnt=p.cnt+1;
            t.mx=max(t.mx,t.cnt);
            if(t.x<0||t.x>=n||t.y<0||t.y>=m) continue;
            if(mp[t.x][t.y]=='D') continue;
            if(mp[t.x][t.y]=='Y')
            {
                k=1<<g[t.x][t.y];
                t.s=t.s|k;
            }
            if(mp[t.x][t.y]=='G')
            {
                k=1<<g[t.x][t.y];
                if((t.e&k)==0)
                {
                    t.cnt=0;
                    t.e=t.e|k;
                }
            }
            if(vis[t.x][t.y][t.s]==-1||t.cnt<=vis[t.x][t.y][t.s])
            {
                vis[t.x][t.y][t.s]=t.cnt;
                st.push(t);
            }
        }
    }
}
int main()
{
    int i,j,x,y;
    while(~scanf("%d%d",&n,&m)&&n&&m)
    {
        for(i=0;i<n;i++)
            scanf("%s",mp[i]);
        scnt=ecnt=0;
        ans=inf;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mp[i][j]=='F')
                {
                    x=i;
                    y=j;
                }
                else if(mp[i][j]=='G')
                {
                    g[i][j]=ecnt;
                    ecnt++;
                }
                else if(mp[i][j]=='Y')
                {
                    g[i][j]=scnt;
                    scnt++;
                }
            }
        }
        //if(scnt==0) ans=0
        bfs(x,y);
        if(ans>=inf) ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
*/
