#include <stdio.h>
int n,i;
long long path[51]={0,1,2,4,7,13};
long long del[51]={0,0,0,1,1,2};
int main()
{
    for(i=6;i<=50;i++){
        path[i]=path[i-1]+path[i-2]+path[i-3]-del[i-3];
        del[i]=path[i-3]-del[i-3];
    }
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",path[n]);
}