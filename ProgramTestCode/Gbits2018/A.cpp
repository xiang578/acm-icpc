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
const int M=1e5+10;
char s[10024];
int b[1024];

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++) {
		b[s[i]]++;
	}
	for(int i='a';i<='z';i++)
	{
		for(int j=0;j<b[i];j++)
			printf("%c",i);
	}
	for(int i='0';i<='9';i++)
	{
		for(int j=0;j<b[i];j++)
			printf("%c",i);
	}
	puts("");
    return 0;
}
