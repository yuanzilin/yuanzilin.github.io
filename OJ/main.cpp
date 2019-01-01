#include <iostream>

using namespace std;

int fama(int,int [],int []);

int main()
{
    int n;
    cin>>n;
    int *w=new int[n];
    int *num=new int[n];
    int i;
    for(i=0;i<n;i++)
        cin>>w[i];
    for(i=0;i<n;i++)
        cin>>num[i];
    cout<<fama(n,w,num)<<endl;
    return 0;
}

int fama(int N,int weight[],int num[])
{
    int allweight=0,tempweight=0;
    int i,j,count=0;
    for(i=0;i<N;i++)
        allweight+=weight[i]*num[i];
    int flag[100000]={0};

    tempweight=weight[0]*num[0];
    for(i=0;i<=num[0];i++)
        flag[i*num[0]]=1;

    int neweight=0,currentweight=0;
    for(i=1;i<N;i++){
        for(j=1;j<=num[i];j++){
            for(currentweight=0;currentweight<=tempweight;currentweight++){
                neweight=currentweight+j*weight[i];
                if(flag[currentweight])
                    flag[neweight]=1;
            }
        }
        tempweight+=weight[i]*num[i];
    }

    for(i=0;i<100000;i++)
        if(flag[i])
            count++;
    return count;
}