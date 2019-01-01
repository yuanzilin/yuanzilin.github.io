#include <iostream>
#include <cstring>
#include <vector>
#define maxnum 505

using  namespace std;

char in[maxnum];

int lcs(){
    char newin[maxnum];
    int len=strlen(in);
    for(int i=0;i<len;i++){
        int j=len-1-i;
        newin[i]=in[j];
    }
    vector<vector<int> > c;
    c.resize(len+1);
    for(int i=0;i<c.size();i++)
        c[i].resize(len+1);
    //puts("yes");
    for(int i=1;i<=len;i++){
        //printf("i=%d\n",i);
        for(int j=1;j<=len;j++){
            if(in[i-1]==newin[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else if(c[i-1][j]>c[i][j-1])
                c[i][j]=c[i-1][j];
            else
                c[i][j]=c[i][j-1];
        }
    }

    return c[len][len];
}

int main()
{
    while (~scanf("%s",in)){
        printf("%d\n",lcs());
    }
}