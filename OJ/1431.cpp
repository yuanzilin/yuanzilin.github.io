#include <cstdio>

using namespace std;

int n;

void hanoi_put(int n,int from,int via,int to){
    if(n==1){
        printf("get game from board %d\n"
               "put game to board %d\n",from,to);
    }
    else{
        hanoi_put(n-1,from,to,via);
        printf("get game from board %d\n"
               "put game to board %d\n",from,to);
        hanoi_put(n-1,via,from,to);
    }
}

void hanoi(int n,int from,int via,int to){
    if(n==1){
        printf("get game from board %d\n"
               "playing\n"
               "put game to board %d\n",from,to);
    }
    else{
        hanoi(n-1,from,to,via);
        printf("get game from board %d\n"
               "playing\n"
               "put game to board %d\n",from,to);
        hanoi_put(n-1,via,from,to);
    }
}

int main()
{
    while(~scanf("%d",&n)){
        if(n==1)
        {
            printf("get game from board 1\n"
                   "playing\n"
                   "put game to board 3\n"
                   "leave\n");
            continue;
        }
        if(n==2){
            printf("get game from board 1\n"
                   "playing\n"
                   "put game to board 2\n"
                   "get game from board 1\n"
                   "playing\n"
                   "put game to board 3\n"
                   "leave\n");
            continue;
        }
        if(n>2){
            hanoi(n-2,1,3,2);
            printf("get game from board 1\n"
                   "playing\n"
                   "put game to board 3\n"
                   "get game from board 1\n"
                   "playing\n"
                   "put game to board 1\n"
                   "leave\n");
        }
    }
}