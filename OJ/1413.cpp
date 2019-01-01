#include <cstdio>
#include <string>
#include <iostream>

using  namespace std;

int T;
string A,B;

int main()
{
    for(scanf("%d",&T);T--;){
        cin>>B>>A;
        int len=A.size();
        int cnt1=0,cnt0=0;
        int b1=0,b0=0;
        for(int i=0;i<len;i++){
            if(A[i]!=B[i]){
                if(B[i]=='0')
                    cnt0++;
                if(B[i]=='1')
                    cnt1++;
            }
            if(B[i]=='0')
                b0++;
            if(B[i]=='1')
                b1++;
        }
        if(b0==len||b1==len){
            printf("-1\n");
            continue;
        }
        if(cnt0==cnt1)
            printf("%d\n",cnt0);
        else{
            int maxcnt=max(cnt0,cnt1);
            printf("%d\n",maxcnt);
        }
    }
}
