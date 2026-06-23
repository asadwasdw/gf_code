#include<iostream>
#include<algorithm>

using namespace std;

const int N=5e5+10;
int n,m;
int f[N];

int find(int x)
{
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}

struct Edg{
    int l,r,w;
}edgs[N];

bool cmp(Edg a,Edg b)
{
    return a.w<b.w;
}


int Kruskal()
{
    int res=0;
    int cnt=0;

    for(int i=1;i<=m;i++)
    {
        int a=edgs[i].l,b=edgs[i].r,w=edgs[i].w;

        int fa=find(a);
        int fb=find(b);

        if(fa!=fb)
        {
            cnt++;
            res+=w;
            f[fa]=fb;

        }

    }

    
    return res;
}


int main()
{
  cin>>n>>m;

  for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        edgs[i]={a,b,c};
    }

    sort(edgs+1,edgs+m+1,cmp);

    int t=Kruskal();

    cout<<t<<endl;
}