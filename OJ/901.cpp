#include <iostream>
#include <cstring>
#define maxn 10000+5
#define maxm 1000+5
#define mode 1000007

using namespace std;

int m,n,i,j;
int methods[maxn][maxm];

int main()
{
    while(~scanf("%d%d",&n,&m)){
        memset(methods,0,sizeof(methods));
        for(i=0;i<=m;i++)
            methods[i][i]=1;
        for(i=1;i<=n;i++)
            methods[i][1]=1;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(i>j)
                    methods[i][j]=(methods[i-j][j]%mode+methods[i-1][j-1]%mode)%mode;
            }
        }
        printf("%d\n",methods[n][m]);
    }
}