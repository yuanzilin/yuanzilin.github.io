#include <iostream>
#include <algorithm>
#define maxsize 100005
using namespace std;

int n,i,pos;
int an[maxsize];

int main()
{
    while (~scanf("%d",&n)){
        for(i=1;i<=n;i++)
            scanf("%d",an+i);
        pos=(n+1)>>1;
        nth_element(an+1,an+pos,an+n+1);
        printf("%d\n",an[pos]);
    }
}