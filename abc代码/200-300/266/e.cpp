#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

double f[N];
void solve()
{
    int n;
    cin>>n;

    f[1]=3.5;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=6;j++){
            f[i]+=max(f[i-1],double(j));
        }
        //cout<<f[i]<<endl;
        f[i]/=6;
    }
    //cout<<f[n]<<endl;
    printf("%.10lf",f[n]);
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