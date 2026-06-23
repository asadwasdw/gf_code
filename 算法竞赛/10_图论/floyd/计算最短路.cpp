//https://vjudge.net/problem/HDU-1385

#include<iostream>
#include<algorithm>

using namespace std;
const int N=555,INF=0x3f3f3f3f;
int n,map[N][N],path[N][N],tax[N];

void init()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>map[i][j];
            if(map[i][j]==-1)map[i][j]=INF;
            path[i][j]=j;
        }
    }

    for(int i=1;i<=n;i++)cin>>tax[i];
}

void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int i=1;i<=n;i++)
            {
                int len=map[i][k]+map[k][j]+tax[k];
                if(map[i][j]>len)
                {
                    map[i][j]=len;
                    path[i][j]=path[i][k];
                }
                else if(len==map[i][j]&&path[i][j]>path[i][k]){
                    path[i][j]=path[i][k];
                }
            }
        }
    }
}

void print(){
    int s,t;
    while(cin>>s>>t)
    {
        if(s==-1&&t==-1)break;

        printf("From %d to %d :\n",s,t);
        printf("Path: %d",s);
        int k=s;
        while(s!=t){
            printf("-->%d",path[s][t]);
            s=path[s][t];
        }
        cout<<endl;

        printf("Total cost : %d\n\n",map[k][t]);
    }
}


int main()
{
    while(cin>>n)
    {
        if(n==0)break;
       init();
       floyd();
       print();
    }
    
}
