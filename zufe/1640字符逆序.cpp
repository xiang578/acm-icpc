#include<stdio.h>
#include<string.h>
int main()
{
    char a[150];
    while(gets(a))
    {
        int i,l=strlen(a);
        for(i=l-1;i>=0;i--)
            printf("%c",a[i]);
    }
    return 0;
}
