#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

const int N = 2e5+10;
int f[N];



typedef pair<int,int>PII;

map<PII,int>D;

int find(int x)
{
    if(f[x]!=x)return f[x]=find(f[x]);
    return x;
}

int main()
{
    while(1)
    {
        
    }
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++)f[i]=i;

    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;

        x=find(x);
        y=find(y);
        if(x==y)continue;
        f[x]=y;

    }
    int yq;
    cin>>yq;
    bool ky=true;

    for(int i=1;i<=yq;i++)
    {
        int x,y;
        cin>>x>>y;

        x=find(x);
        y=find(y);
        if(x==y)
        {
            ky=false;
        }


        D[{x,y}]=1;
        D[{y,x}]=1;
    }

    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;

        x=find(x);
        y=find(y);

        if(!D[{x,y}]&&ky)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }


}