
//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P4047
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;


const int N=1010;
int f[N];

struct Node
{
    double x,y;
}node[N];

struct E{
    int l,r;
    double w;
}edge[N*N];

double jl(Node a,Node b)
{
    double x=a.x-b.x;
    double y=a.y-b.y;
    return sqrt(x*x+y*y);
}

bool cmp(E a,E b)
{
    return a.w<b.w;
}

int find(int x)
{
    if(f[x]!=x)return f[x]=find(f[x]);
    return f[x];
}

int main()
{
    int n,m;cin>>n>>m;

    for(int i=1;i<=n;i++)f[i]=i;

    for(int i=1;i<=n;i++)
    {
        double a,b;
        cin>>a>>b;
        node[i]={a,b};
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)continue;
            //cout<<i<<" "<<j<<endl;
            ++cnt;
            edge[cnt]={i,j,jl(node[i],node[j])};
        }
    }

   double ans=0;

    sort(edge+1,edge+cnt+1,cmp);


 //  for(int i=1;i<=cnt;i++) cout<<edge[i].l<<" "<<edge[i].r<<" "<<edge[i].w<<endl;


     int num=0;
     vector<double>xz;
    for(int i=1;i<=cnt;i++)
    {
        int l=edge[i].l;
        int r=edge[i].r;

        int fl=find(l);
        int fr=find(r);
        if(fl==fr)continue;
        xz.push_back(edge[i].w);
    //    cout<<l<<" "<<r<<endl;
        ans+=edge[i].w;
        num++;
        f[fl]=fr;
        if(num==n-1)continue;
    }

    sort(xz.begin(),xz.end());



    ans=xz[xz.size()-m+1];

    printf("%.2lf",ans);

}