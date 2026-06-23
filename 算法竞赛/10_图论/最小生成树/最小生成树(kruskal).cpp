//https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P3366

#include<iostream>
#include<algorithm>

using namespace std;


const int N=5010,M=2e5+10;

int n,m;
int f[N];

struct e
{
    int l,r,w;
}edge[M];

bool cmp(e a,e b)
{
    return a.w<b.w;
}

int find(int x)
{
    if(f[x]!=x)return f[x]=find(f[x]);
    return x;
}

int main()
{

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)f[i]=i;

    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edge[i]={a,b,c};
    }

    sort(edge+1,edge+m+1,cmp);

    int cnt=0;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int pa=find(edge[i].l);
        int pb=find(edge[i].r);

        if(pa!=pb){
            cnt++;
            ans+=edge[i].w;
            f[pa]=pb;
        }

        if(cnt==n-1)break;
    }

    if(cnt==n-1)cout<<ans<<endl;
    else cout<<"orz"<<endl;
    

}