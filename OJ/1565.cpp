#include <iostream>
#include <cstring>
#define maxn 205
#define mode 1000007

using namespace std;

int dp[maxn][maxn][2];
int n,m,x,y;

int main()
{
    while(~scanf("%d%d%d%d",&n,&m,&x,&y)){
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=dp[0][0][1]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                for(int k=1;k<=x&&i+k<=n;k++)
                    dp[i+k][j][0]=(dp[i][j][1]+dp[i+k][j][0])%mode;
                for(int k=1;k<=y&&j+k<=m;k++)
                    dp[i][j+k][1]=(dp[i][j][0]+dp[i][j+k][1])%mode;
            }
        }
        int ans=(dp[n][m][0]+dp[n][m][1])%mode;
        printf("%d\n",ans);
    }
}