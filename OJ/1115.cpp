#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define maxnum 100005
#define inf 0xffffff

using namespace std;

typedef struct point{
    double x,y;
    bool operator <(const point& a){
        return this->x<a.x;
    }
}P;

int n;
P p[maxnum],p2[maxnum];
double dis(P a,P b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double divide(int left,int right){
    if(left==right-1)
        return dis(p[left],p[right]);
    if(left==right)
        return inf;
    int mid=(left+right)>>1;

    double d=min(divide(left,mid),divide(mid+1,right));
    double md=p[mid].x;
    int cnt=0;

    for(int i=left,j=mid+1;(i<=mid||j<=right);i++){
        while(j<=right&&(p[i].y>p[j].y||i>mid))
            p2[cnt++]=p[j],j++;//归并按y排序
        if(abs(p[i].x-md)<d&&i<=mid){//选择中间符合要求的点
            for(int k=j-1;k>mid&&j-k<3;k--)
                d=min(d,dis(p[i],p[k]));
            for(int k=j;k<=right&&k-j<2;k++)
                d=min(d,dis(p[i],p[k]));
        }
        if(i<=mid)
            p2[cnt++]=p[i];
    }
    for(int i=left,j=0;i<=right;i++,j++)
        p[i]=p2[j];
    return d;
}

int main()
{
    while (~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        sort(p,p+n);
        printf("%.2lf\n",divide(0,n-1));
    }
}