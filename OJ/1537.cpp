#include<iostream>
#define maxn 505
#define init_min 1000000000

using namespace std;

int n,m,i,j,k,mintime;
int p[maxn][maxn],f[maxn][maxn],t[maxn][maxn];

int main()
{
    while(~scanf("%d%d",&n,&m)){
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",p[i]+j);
                t[i][j]=init_min;
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++)
                scanf("%d",f[i]+j);
        }
        for(i=1;i<=n;i++)
            t[i][1]=p[i][1];
        for(k=2;k<=m;k++){
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++){
                    t[i][k]=min(t[i][k],t[j][k-1]+f[j][i]+p[i][k]);
                }
        }
        mintime=init_min;
        for(i=1;i<=n;i++)
            mintime=min(mintime,t[i][m]);
        printf("%d\n",mintime);
    }
}