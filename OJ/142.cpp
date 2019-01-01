#include <iostream>
#define maxnum 5000000+5

using namespace std;

int money;
int a[7],b[7]={0,1,5,10,50,100,500};

int main()
{
    while (~scanf("%d",a+1)){
        int minans=0;
        for(int i=2;i<=6;i++)
            scanf("%d",a+i);
        scanf("%d",&money);
        for(int i=6;i>0&&money;i--){//
            while (a[i]&&money>=b[i]){
                money-=b[i];
                a[i]--;
                minans++;
            }
        }
        printf("%d\n",minans);
    }
}