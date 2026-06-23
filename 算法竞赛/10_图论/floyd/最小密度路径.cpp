#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
#include<cstring>
using namespace std;

typedef pair<int,int>PII;

//unordered_map<int,vector<PII>>edgs;
const int INF =0x3f3f3f3f;

const int N=60;


int dis[N][N][1100];

int main()
{
    int n,m;
    cin>>n>>m;
    memset(dis,0x3f,sizeof dis);

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if(dis[a][b][1]>c)
           dis[a][b][1]=c;
       // edgs[a].push_back({b,c});
    }

    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         cout<<dis[i][j][1]<<" ";
    //     }
    //     cout<<endl;
    // }


    for(int l=2;l<=m;l++)
    {
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j][l]=min(dis[i][j][l],dis[i][k][l-1]+dis[k][j][l-1]);
            }
        }
    }
    }




    int q;
    cin>>q;
    
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        
        double ans=INF,mn=INF;

        for(int l=1;l<=n;l++)
        {
            if(dis[a][b][l]<INF){
                ans=(double)dis[a][b][l]/l;
            }
            mn=min(mn,ans);
        }

        if(mn==INF)
            printf("OMG!\n");
        else
            printf("%.3lf\n",mn);//输出 


    }


}