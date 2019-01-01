#include <iostream>
#define maxn 305
#define inf 0xffffff

int n;
int p[maxn],s[maxn][maxn],m[maxn][maxn];

void printmethod(int,int);

int main()
{
    while(~scanf("%d",&n)){
        for(int i=1;i<=n+1;i++){
            scanf("%d",p+i);
            m[i][i]=0;
        }
        for(int l=2;l<=n;l++){
            for(int i=1;i<=n-l+1;i++){
                int j=i-1+l;
                m[i][j]=inf;
                for(int k=i;k<j;k++){
                    int tmp=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
                    if(tmp<=m[i][j]){
                        m[i][j]=tmp;
                        s[i][j]=k;
                    }
                }
            }
        }
        printf("%d\n",m[1][n]);
        printmethod(1,n);
        printf("\n");
    }
}

void printmethod(int i,int j)
{
    if(i==j){
        printf("A%d",i);
        return;
    }
    printf("(");
    printmethod(i,s[i][j]);
    printmethod(s[i][j]+1,j);
    printf(")");
    return;
}