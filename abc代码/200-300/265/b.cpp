#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int a[N];
int jl[N];

void solve()
{

    int n,m,t;
    cin>>n>>m>>t;

    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        jl[x]+=y;
    }

    for(int i=2;i<=n;i++)
    {
        t-=a[i];
        if(t<=0){
            cout<<"No";
            return;
        }

        t+=jl[i];
 

    }

    cout<<"Yes"<<endl;

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}