#include <iostream>
#include <algorithm>
#define maxnum 500005

using namespace std;

int n;
int a[maxnum],b[maxnum];

int b_lis()
{
    b[1]=a[1];
    int len=1;
    for(int i=2;i<=n;i++){
        if(a[i]>b[len])
            b[++len]=a[i];
        else{
            int j=lower_bound(b+1,b+len+1,a[i])-b;
            b[j]=a[i];
        }
    }
    return len;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    printf("%d\n",b_lis());
}