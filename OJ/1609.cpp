#include <iostream>
using namespace std;

int n,m;

int any_odd_one(int x){
    int i,len;
    int a=x;
    int numTochar[100]={0};
    int w=8* sizeof(int);
    for(i=0;i<w&&a!=0;i++){
        numTochar[i]=a%2;
        a=a/2;
    }
    len=i;
    int sum=0;
    for(int i=0;i<len;i++){
        if(numTochar[i])
            sum++;
    }
    if(sum&1)
        return 1;
    return 0;
}

int main()
{
    while (~scanf("%d%d",&n,&m)){
        printf("%d\n",any_odd_one(m-1));
    }
}
