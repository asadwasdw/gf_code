#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;

int f[N];

int find(int x)
{
    if(f[x]!=x)return f[x]=find(f[x]);
    return x;
}

void solve()
{

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)f[i]=i;
    int ansq=0;
    int ansl=n;
    while(m--)
    {
        int a,b;
        char c,d;
        cin>>a>>c>>b>>d;
        int fa=find(a);
        int fb=find(b);

        if(fa!=fb)
        {
            f[fa]=fb;
            ansl--; 
        }
        else{
            ansl--;
            ansq++;

        }
    }

    cout<<ansq<<" "<<ansl<<endl;



}


signed main()
{
    ios::sync_with_stdio(false);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}