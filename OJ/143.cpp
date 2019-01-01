#include <iostream>
#include <algorithm>
#define maxnum 10005

using namespace std;

int g,k,n;
double sum;
struct stone{
    int w;
    int v;
    double ave;
    bool operator <(const stone a) const{
        return ave>a.ave;
    }
}s[maxnum];

int judge(){
    int i;
    for(i=1;i<=k;i++){
        if(s[i].w>g)
            break;
        g-=s[i].w;
        sum+=s[i].v;
    }
    if(i<=k){
        sum+=(double)g*s[i].v/s[i].w;
    }
    if(sum<(double)n)
        return 0;
    return 1;
}

int main()
{
    while (~scanf("%d%d%d",&g,&k,&n)){
        sum=0;
        for(int i=1;i<=k;i++){
            scanf("%d%d",&s[i].w,&s[i].v);
            s[i].ave=(double)s[i].v/s[i].w;
        }
        sort(s+1,s+k+1);
        if(judge())
            printf("Yuri is the master!\n");
        else{
            printf("%.3lf\n",n-sum);
        }
    }
}