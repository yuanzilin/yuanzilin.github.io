#include <iostream>
#include <cstring>

using namespace std;

int n,i,len,H;
long long ya,yb;
char inputa[40],inputb[40];

int main()
{
    cin>>n;
    while(n--){
        ya=0,yb=0;
        scanf("%d%s",&H,inputa);
        for(i=0;inputa[i]!='\0';i++);
        len=i;
        for(i=0;i<len;i++){
            ya=(inputa[i]-'0'+(H*ya));
        }
        scanf("%d%s",&H,inputb);
        for(i=0;inputb[i]!='\0';i++);
        len=i;
        for(i=0;i<len;i++){
            yb=(inputb[i]-'0'+(H*yb));
        }
        printf("%lld\n",ya+yb);
    }
}