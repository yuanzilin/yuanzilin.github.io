#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps=1e-10;

double concre(double x){
    if(fabs(x)<eps)
        return 0;
    return x<0?-1:1;
}

typedef struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
}P;

Point operator -(const Point& A,const Point& B) {
    return Point(A.x-B.x,A.y-B.y);
}

double Cross( P A,P B) {
    return A.x*B.y-A.y*B.x;
}

double Dot(P A,P B){
    return A.x*B.x+A.y*B.y;
}

bool operator == (const Point& p1,const Point& p2) {
    return p1.x==p2.x&&p1.y==p2.y;
}

bool operator<(const Point& p1,const Point& p2){
    return p1.x<p2.x||(p1.x==p2.x&&p1.y<p2.y);
}

bool judge_line(P a1,P a2,P b1,P b2){
    double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
            c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    return concre(c1)*concre(c2)<0&&concre(c3)*concre(c4)<0;
}

bool onsegment(P px,P a1,P a2) {
    return concre(Cross(a1-px,a2-px))==0&&concre(Dot(a1-px,a2-px))<0;
}

vector<P> jarvis(vector<P> p){
    sort(p.begin(),p.end());
    p.erase(unique(p.begin(),p.end()),p.end());

    int n=p.size(),m=0;
    vector<P> s(n+1);
    for(int i=0;i<n;i++){
        while (m>1&&Cross(s[m-1]-s[m-2],p[i]-s[m-2])<=0)
            m--;
        s[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i>=0;i--){
        while (m>k&&Cross(s[m-1]-s[m-2],p[i]-s[m-2])<=0)
            m--;
        s[m++]=p[i];
    }
    if(n>1)
        m--;
    s.resize(m);
    return s;
}

int judge_p(P p,vector<P> poly)
{
    int cnt=0;
    int n=poly.size();
    for(int i=0;i<n;i++){
        P p1=poly[i],p2=poly[(i+1)%n];
        if(p1==p||p==p2||onsegment(p,p1,p2))
            return -1;
        int a=concre(Cross(p2-p1,p-p1));
        int a1=concre(p1.y-p.y);
        int a2=concre(p2.y-p.y);
        if(a>0&&a1<=0&&a2>0)
            cnt++;
        if(a<0&&a2<=0&&a1>0)
            cnt--;

    }
    if(cnt!=0)
        return 1;
    return 0;
}

bool jude_total(vector<P> s1,vector<P> s2)
{
    int size1=s1.size();
    int size2=s2.size();
    for(int i=0;i<size1;i++)
        if(judge_p(s1[i],s2)!=0)
            return false;
    for(int i=0;i<size2;i++)
        if(judge_p(s2[i],s1)!=0)
            return false;
    for(int i=0;i<size1;i++)
        for(int j=0;j<size2;j++)
            if(judge_line(s1[i],s1[(i+1)%size1],s2[j],s2[(j+1)%size2]))
                return false;
    return true;
}

int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m)){
        vector<P> p1,p2;
        double x,y;
        for(int i=0;i<n;i++){
            scanf("%lf%lf",&x,&y);
            p1.push_back(Point(x,y));
        }
        for(int i=0;i<m;i++){
            scanf("%lf%lf",&x,&y);
            p2.push_back(Point(x,y));
        }
        if(jude_total(jarvis(p1),jarvis(p2)))
            puts("YES");
        else
            puts("NO");
    }
}