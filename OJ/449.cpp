#include<cstdio>

int life,n;

int main()
{
    while(scanf("%d",&n)!=EOF){
        life=0;
        while(n){
            n/=2;
            life++;
        }
        printf("%d\n",life);
    }
}