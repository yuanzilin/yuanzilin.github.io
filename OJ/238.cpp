#include <iostream>
#define maxnum 105

using namespace std;

typedef struct P{
    double x,y;
    struct P operator-(const P& b){
        struct P point;
        point.x=this->x-b.x;
        point.y=this->y-b.y;
        return point;
    }//重载减号，方便向量运算
    void input(){
        scanf("%lf%lf",&x,&y);
    }//重载输入函数，方便输入点的信息
}P;

typedef  struct line{
    P a1,a2;
}L ;

int N;
L ls[maxnum];

bool segment_intersect(L,L);//总判断函数
double direction(L,P);//判断方向
bool on_segment(L,P);//判断是否在两个端点之间

int main()
{
    //主函数
    while (~scanf("%d",&N)){
        for(int i=1;i<=N;i++){
            ls[i].a1.input();
            ls[i].a2.input();
        }
        for(int i=1;i<N;i++){
            int flag=0;
            for(int j=i+1;j<=N;j++)
                if(segment_intersect(ls[i],ls[j])){
                    flag=1;
                    break;
                }
            if(!flag)
                printf("%d ",i);
        }
        printf("%d\n",N);

    }
}

bool segment_intersect(L l1,L l2)
{
    double d1=direction(l2,l1.a1);
    double d2=direction(l2,l1.a2);
    double d3=direction(l1,l2.a1);
    double d4=direction(l1,l2.a2);

    if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
        return true;

    else if(d1==0&&on_segment(l2,l1.a1))
        return true;
    else if(d2==0&&on_segment(l2,l1.a2))
        return true;
    else if(d3==0&&on_segment(l1,l2.a1))
        return true;
    else if(!d4&&on_segment(l1,l2.a2))
        return true;
    else
        return false;
}

double direction(L li,P pk)
{
    P pa=pk-li.a1,pb=pk-li.a2;
    return pa.x*pb.y-pa.y*pb.x;
}

bool on_segment(L li,P pk)
{
    if(min(li.a1.x,li.a2.x)<=pk.x<=max(li.a1.x,li.a2.x)&&min(li.a1.y,li.a2.y)<=pk.y<=max(li.a1.y,li.a2.y))
        return true;
    return false;
}