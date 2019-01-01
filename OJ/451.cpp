#include <iostream>
#include <cstdio>

using namespace std;

const int maxsize=70;
int beg[maxsize],end[maxsize];
int i,n,biggest,mid;
long long steps;


inline long long hanoi(int num){
    return (1LL << (long long)num)-1;
}

long long moveits(int a[],int cur,int destn){
    if(!cur) return 0;
    else if(a[cur]==destn)
        return moveits(a,cur-1,destn);
    else return moveits(a,cur-1,6-a[cur]-destn)+1+hanoi(cur-1);
}

int main()
{
    while(cin>>n&&n){
        for(i=1;i<=n;i++)
            cin>>beg[i];
        for(i=1;i<=n;i++)
            cin>>end[i];
        biggest=n;
        while(biggest>=1&&beg[biggest]==end[biggest])
            biggest--;
        steps=0;
        if(biggest>0){
            mid=6-beg[biggest]-end[biggest];
            steps=moveits(beg,biggest-1,mid)+1+moveits(end,biggest-1,mid);
        }
        printf("%lld\n",steps);
    }
}