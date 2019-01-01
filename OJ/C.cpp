#include <iostream>
#include <cstdio>
#define mode 10007

using namespace std;

int N,Q,l,r,input;
int an[1000001];


int main()
{
    while(cin>>N>>Q){
        scanf("%d",an+1);
        an[1]%=mode;
        for(int i=2;i<=N;i++){
            scanf("%d",&input);
            input%=mode;
            an[i]=(an[i-1]+input)%mode;
        }
        while(Q--){
            scanf("%d %d",&l,&r);
            printf("%d\n",(an[r]-an[l-1]+mode)%mode);
        }

    }
}