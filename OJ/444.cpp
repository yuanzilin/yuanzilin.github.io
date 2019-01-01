#include <iostream>

using namespace std;

const int MAXSIZE=1000000;
int shares[MAXSIZE],d[MAXSIZE];

int main()
{
    int n,i;
    int temp,totalprofit;
    while(scanf("%d",&n)!=EOF){
        temp=0,totalprofit=0;
        for(i=0;i<n;i++){
            cin>>shares[i];
            if(!i)
                d[i]=0;
            else
                d[i]=shares[i]-shares[i-1];
        }
        for(i=0;i<n;i++){
            temp+=d[i];
            if(temp>totalprofit)
                totalprofit=temp;
            if(temp<0)
                temp=0;
        }
        if(totalprofit)
            cout<<totalprofit<<"\n";
        else
            cout<<"No solution"<<"\n";
    }
}
