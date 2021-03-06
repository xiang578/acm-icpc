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
string d;
int len;
int v;

void add(int st)
{
    if(st==-1)
    {
        if(d[st+1]=='0') d='1'+d;
        if(d[st+1]=='A') d='A'+d;
        if(d[st+1]=='a') d='a'+d;
        return ;
    }
    string b="";
    int i;
    for(i=st; i>=0; i--)
    {
        if(d[i]>='0'&&d[i]<='9')
        {
            if(d[i]=='9')
            {
                d[i]='0';
                add(i-1);
            }
            else d[i]++;
            return ;
        }

        if('a'<=d[i]&&d[i]<='z')
        {
            if(d[i]=='z')
            {
                d[i]='a';
                add(i-1);
            }
            else d[i]++;
            return ;
        }

        if('A'<=d[i]&&d[i]<='Z')
        {
            if(d[i]=='Z')
            {
                d[i]='A';
                add(i-1);
            }
            else d[i]++;
            return ;
        }
    }

    for(int j=0; j<=st; j++)
    {
        b+=d[j];
    }
    if(d[st+1]=='0') b+='1';
    if(d[st+1]=='A') b+='A';
    if(d[st+1]=='a') b+='a';
    for(int j=st+1;j<d.length();j++)
    {
        b+=d[j];
    }
    d=b;
}

int main()
{
    int i,t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>d;
        scanf("%d",&v);
        int f;
        while(v--)
        {
            len=d.length();
            f=0;
            for(i=len-1; i>=0; i--)
            {
                if(d[i]>='0'&&d[i]<='9')
                {
                    if(d[i]=='9')
                    {
                        d[i]='0';
                        add(i-1);
                    }
                    else d[i]++;
                    f=1;
                }
                else if('a'<=d[i]&&d[i]<='z')
                {
                    if(d[i]=='z')
                    {
                        d[i]='a';
                        add(i-1);
                    }
                    else
                        d[i]++;
                    f=1;
                }
                else if('A'<=d[i]&&d[i]<='Z')
                {
                    if(d[i]=='Z')
                    {
                        d[i]='A';
                        add(i-1);
                    }
                    else d[i]++;
                    f=1;
                }
                if(f==1) break;
            }
            if(f==0)
            {
                d[len-1]+=1;
            }
            cout<<d<<endl;
        }
        printf("\n");
    }
    return 0;
}
