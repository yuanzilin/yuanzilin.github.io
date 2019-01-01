#include <iostream>

using namespace std;

int a[7];

int main()
{
    int b[4]={0,5,3,1};
    while (~scanf("%d",a+1)){
        for(int i=2;i<=6;i++)
            scanf("%d",a+i);
        int sum=0;
        sum+=a[6]+a[5]+a[4]+(a[3]+3)/4;
        int m=b[a[3]%4]+a[4]*5;
        if(a[2]>m)
            sum+=(a[2]-m+8)/9;
        int n=sum*36-a[6]*36-a[5]*25-a[4]*16-a[3]*9-a[2]*4;
        if(a[1]>n)
            sum+=(a[1]-n+35)/36;
        printf("%d\n",sum);
    }
}