#include <iostream>
#define maxn 505

using  namespace std;

int p1[maxn],p2[maxn],t[3][maxn],f1[maxn],f2[maxn];
int n,i;

int main()
{
    while (~scanf("%d",&n)){
        for(i=1;i<=n;i++)
            scanf("%d",p1+i);
        for(i=1;i<=n;i++)
            scanf("%d",p2+i);
        for(i=1;i<=n-1;i++)
            scanf("%d",t[1]+i);
        for(i=1;i<=n-1;i++)
            scanf("%d",t[2]+i);
        f1[1]=p1[1],f2[1]=p2[1];
        for(i=2;i<=n;i++){
            if(f1[i-1]+p1[i]<=f2[i-1]+t[2][i-1]+p1[i])
                f1[i]=f1[i-1]+p1[i];
            else
                f1[i]=f2[i-1]+t[2][i-1]+p1[i];
            if(f2[i-1]+p2[i]<=f1[i-1]+t[1][i-1]+p2[i])
                f2[i]=f2[i-1]+p2[i];
            else
                f2[i]=f1[i-1]+t[1][i-1]+p2[i];
        }
        if(f1[n]>=f2[n])
            printf("%d\n",f2[n]);
        else
            printf("%d\n",f1[n]);
    }
}