#include <iostream>
#define maxw 20005

using namespace std;

int W,N,vi,wi,i,j;
int bag[maxw];

int main()
{
    while(~scanf("%d%d",&W,&N)){
        bag[0]=0;
        for(i=1;i<=W;i++)
            bag[i]=-1;
        for(i=1;i<=N;i++){
            scanf("%d%d",&vi,&wi);
            for(j=W;j>=wi;j--){
                if(bag[j-wi]!=-1&&bag[j-wi]+vi>=bag[j])
                    bag[j]=bag[j-wi]+vi;
            }
        }
        if(bag[W]!=-1)
            printf("%d\n",bag[W]);
        else
            puts("jpx");
    }
    return 0;
}