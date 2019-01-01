#include <iostream>

using namespace std;

long long born[101];
long long die[101];

int main()
{
    int T,i,n;
    cin>>T;
    born[1]=1;
    born[2]=1;
    for(i=3;i<=12;i++)
        born[i]=born[i-1]+born[i-2];
  // for(i=13;i<=100;i++)
    born[13]=born[12]+born[11]-1;
    born[14]=born[13]+born[12];
    for(i=15;i<=100;i++)
    {
        if(i%2){
            born[i]=born[i-1]+born[i-2];
        }
        else
            born[i]=born[i-1]+born[i-2]-1;
    }
    while(T--){
        scanf("%d",&n);
        printf("%d\n",born[n]*2);
    }
}