
//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               ���汣��         ����BUG
//
//                �������Ѿ��������⴦��������OJ��AC����
//
#include "stdio.h"
int main()
{
   int n,i,t,c;
   while(~scanf("%d",&n))
   {
        t=1,c=0;
        for(int j=0;j<n;j++){
        for(i=1;i<=n-j;i++)
        {
            if(c==0) c++;
            else printf(" ");
            printf("%d",i*t);
            if(i==n-j) {t++;c=0;printf("\n");}
        }
        }
   }
    return 0;
}