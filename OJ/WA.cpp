//char[]
#include<iostream>
#include<vector>
#include<cstdio>
#include <string>

using namespace std;

char x[1005];

int main()
{

    while(~scanf("%s",x)){
        char y[1005];
        int m=0;
        for(;x[m]!='\0';m++);
        for(int i=0;i<m;i++){
            y[i]=x[m-i-1];
        }
        vector<vector<int> > c;
        c.resize(m+1);
        for(int i=0;i<c.size();i++)
            c[i].resize(m+1);
        for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else if(c[i-1][j]>=c[i][j-1])
                c[i][j]=c[i-1][j];
            else
                c[i][j]=c[i][j-1];
        }
        printf("%d\n",c[m][m]);
    }
}
