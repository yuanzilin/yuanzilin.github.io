//用一个数组表示每个年龄的猫的个数，每过一年将个数后移一位
#include <iostream>
#include <cstdio>
#include <cstring>
#define maxage 20
#define maxyear 55

using namespace std;

int T,n;
int a[maxyear][maxage+1],sum[maxyear];

void table(){
    memset(a,0,sizeof a);
    a[1][1]=1;
    sum[1]=2;
    for(int i=2;i<maxyear;i++){
        for(int j=2;j<=maxage;j++){
            a[i][j]=a[i-1][j-1];
        }
        for(int j=2;j<=11;j++)
            a[i][1]+=a[i-1][j];
        for(int j=1;j<=maxage;j++){
            sum[i]+=a[i][j];
        }
        sum[i]*=2;
    }
}

int main()
{
    table();
    for(scanf("%d",&T);T--;){
        scanf("%d",&n);
        printf("%d\n",sum[n]);
    }
}