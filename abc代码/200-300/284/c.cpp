#include<iostream>
#include<algorithm>
#include<set>
using namespace std;


const int N=110;
int f[N];

int find(int x)
{
    if(f[x]!=x)return f[x]=find(f[x]);
    return x;
}

int main()
{
    int n,m;cin>>n>>m;
    int num=n;

    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        //if(a>b)swap(a,b);

        int fa=find(a);
        int fb=find(b);

        if(fa!=fb)
        {
            f[fa]=fb;
        }
    }

    set<int>ans;

    for(int i=1;i<=n;i++)ans.insert(find(i));



    cout<<ans.size()<<endl;
}