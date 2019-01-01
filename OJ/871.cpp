#include <stdio.h>
long long a[25]={0,0,1},b[25]={1};
float percent;
int main()
{
    int i,n;
    for(i=3;i<25;i++)
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    for(i=1;i<25;i++)
        b[i]=i*b[i-1];
    while(scanf("%d",&n)!=EOF){
        percent=((float)a[n]*100)/b[n];
        printf("%.2f%\n",percent);
    }
}