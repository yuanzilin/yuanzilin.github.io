#include <iostream>
#include <cstring>
#define maxnum 105

using namespace std;

int n,i,sum;
int eat[maxnum],cake_m[maxnum];

int main()
{
    while (~scanf("%d",&n)){
        sum=0;
        memset(eat,0, sizeof(eat));
        for(i=1;i<=n;i++)
            scanf("%d",cake_m+i);
        for(i=n;i>=1;i--){
            eat[i]=max(eat[i+1],sum-eat[i+1]+cake_m[i]);
            sum+=cake_m[i];
        }
        printf("%d\n",eat[1]);
    }
}