#include <iostream>
#include <cstring>
#define maxnum 105

using namespace std;

int T,n,m,k;
double b_dis[maxnum][maxnum],p[maxnum][maxnum];

void build_table()
{
    double px=1;
    for(int i=1;i<maxnum;i++){
        double fenzi=1;
        px*=2;
        b_dis[i][0]=1/px;
        for(int j=1;j<=i;j++){
            fenzi=fenzi*(i-j+1)/j;
            b_dis[i][j]=fenzi/px;
        }
    }
}

double count_p()
{
    p[0][0]=1;
    for(int i=0;i<=k;i++){
        p[1][i]=b_dis[k][i];
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<=n;j++){
            int newpos=min(n-k,j);
            for(int t=0;t<=k;t++)
                p[i+1][newpos+t]+=p[i][j]*b_dis[k][t];
        }
    }
    double ans=0;
    for(int i=0;i<=n;i++)
        ans=ans+i*p[m][i];
    return ans;
}

int main()
{
    build_table();
    for(scanf("%d",&T);T--;){
        memset(p,0,sizeof(p));
        scanf("%d%d%d",&n,&m,&k);
        printf("%.3lf\n",count_p());
    }
}