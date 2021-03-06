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
const int N=248;
const int M=1e6+10;
int a,b,c,vis[N][N];
struct node
{
    int x,y,t,fx,fy;
} t,e,p[N][N];

void bfs()
{
    memset(vis,0,sizeof(vis));
    queue<node>q;
    int x,y,k;
    t.x=0;
    t.y=0;
    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t.x==c||t.y==c)
        {
            vector<node>ans;
            ans.clear();
            x=t.x;
            y=t.y;
            while(x!=0||y!=0)
            {
                k=p[x][y].t;
                node tp;
                if(k==1) {tp.t=1;tp.x=1;}
                else if(k==2) {tp.t=1;tp.x=2;}
                else if(k==3) {tp.t=2;tp.x=1;}
                else if(k==4) {tp.t=2;tp.x=2;}
                else if(k==5) {tp.t=3;tp.x=1;tp.y=2;}
                else if(k==6) {tp.t=3;tp.x=2;tp.y=1;}
                int nx=p[x][y].x;
                int ny=p[x][y].y;
                ans.push_back(tp);
                //printf("%d %d %d %d\n",x,y,nx,ny);
                x=nx;
                y=ny;
            }
            printf("%d\n",ans.size());
            for(int i=ans.size()-1; i>=0; i--)
            {
                //printf("%d\n",ans[i].t);
                if(ans[i].t==1) printf("FILL(%d)\n",ans[i].x);
                else if(ans[i].t==2) printf("DROP(%d)\n",ans[i].x);
                else printf("POUR(%d,%d)\n",ans[i].x,ans[i].y);
            }
            return ;
        }
        x=t.x;
        y=t.y;
        if(x<a&&!vis[a][y])
        {
            vis[a][y]=1;
            e.x=a;
            e.y=y;
            e.t=1;
            e.fx=x;
            e.fy=y;
            q.push(e);
            p[e.x][e.y].x=x;
            p[e.x][e.y].y=y;
            p[e.x][e.y].t=1;
        }

        //2
        if(y<b&&!vis[x][b])
        {
            vis[x][b]=1;
            e.x=x;
            e.y=b;
            e.t=2;
            e.fx=x;
            e.fy=y;
            q.push(e);
             p[e.x][e.y].x=x;
            p[e.x][e.y].y=y;
            p[e.x][e.y].t=2;
        }
        //3
        if(x>0&&!vis[0][y])
        {
            vis[0][y]=1;
            e.x=0;
            e.y=y;
            e.t=3;
            e.fx=x;
            e.fy=y;
            q.push(e);
             p[e.x][e.y].x=x;
            p[e.x][e.y].y=y;
            p[e.x][e.y].t=3;
        }

        //4
        if(y>0&&!vis[x][0])
        {
            vis[x][0]=1;
            e.x=x;
            e.y=0;
            e.t=4;
            e.fx=x;
            e.fy=y;
            q.push(e);
             p[e.x][e.y].x=x;
            p[e.x][e.y].y=y;
            p[e.x][e.y].t=4;
        }

        //5 x->y
        int o=min(x,b-y);
        if(x&&!vis[x-o][y+o])
        {
            vis[x-o][y+o]=1;
            e.x=x-o;
            e.y=y+o;
            e.t=5;
            e.fx=x;
            e.fy=y;
            q.push(e);
             p[e.x][e.y].x=x;
            p[e.x][e.y].y=y;
            p[e.x][e.y].t=5;
        }

        //6 y->x
        o=min(y,a-x);
        if(y&&!vis[x+o][y-o])
        {
            vis[x+o][y-o]=1;
            e.x=x+o;
            e.y=y-o;
            e.t=6;
            e.fx=x;
            e.fy=y;
            q.push(e);
             p[e.x][e.y].x=x;
            p[e.x][e.y].y=y;
            p[e.x][e.y].t=6;
        }
    }
    printf("impossible\n");
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        bfs();
    }
    return 0;
}
