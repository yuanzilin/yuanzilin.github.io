#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

typedef struct loc{
    int x,h;
}location;
location pos[105],neg[105];

int main()
{
    int n,i,j,x,h,minh;
    int len_pos,len_neg;
    double PI=acos(-1),r,maxv,temp;
    while(scanf("%d",&n)!=EOF){
        i=0,j=0,maxv=0;
        while(n--){
            scanf("%d%d",&x,&h);
            if(x>=0){
                pos[i].x=x;
                pos[i].h=h;
                i++;
            }
            if(x<=0){
                neg[j].x=x;
                neg[j].h=h;
                j++;
            }
        }
        len_pos=i,len_neg=j;
        for(i=0;i<len_pos;i++){
            for(j=0;j<len_neg;j++){
                minh=min(pos[i].h,neg[j].h);
                r=(double)(pos[i].x-neg[j].x)/2;
                maxv=max(minh*r*r*PI,maxv);
            }
        }
        printf("%.3lf\n",maxv);
    }
}