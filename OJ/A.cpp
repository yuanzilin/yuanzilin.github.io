#include <iostream>

using namespace std;

int n;
long long feibo[101];

int main()
{
    feibo[0]=0;
    feibo[1]=1;
    feibo[2]=1;
    for(int i=3;i<101;i++)
        feibo[i]=feibo[i-1]+feibo[i-2];
    while(cin>>n)
        cout<<feibo[n]<<endl;
}