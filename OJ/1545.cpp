#include <iostream>
#define maxsize 1005

using namespace std;

int n,i,j;
int t[maxsize];

int main()
{
    while (~scanf("%d",&n)){
        for(i=1;i<=n;i++){
            scanf("%d",t+i);
        }
        for(j=2;j<=n;j++){
            for(i=1;i<j;i++)
                t[j]=min(t[j-i]+t[i],t[j]);
        }
        printf("%d\n",t[n]);
    }
}