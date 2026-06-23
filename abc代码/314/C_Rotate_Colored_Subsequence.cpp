#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>wz(N);
char ans[N];
void solve()
{
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        wz[x].push_back(i);
    }

    for(int i=1;i<=m;i++){
        for(int j=0;j<wz[i].size();j++){
            int wz1= wz[i][j%wz[i].size()];
            int wz2= wz[i][(j+1)%wz[i].size()];
            ans[wz2]=s[wz1];
            //cout<<wz1<<" "<<wz2<<endl;
        }
    }
   // cout<<s<<endl;

    for(int i=1;i<=n;i++)cout<<ans[i];
    










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