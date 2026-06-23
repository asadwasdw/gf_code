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

int dp[N];
int w[N];
int st[N];

int dfs(int x){
    if(st[x])return 0;
    st[x]=1;
    int sum = w[x];
    for(auto t:edg[x]){
        sum+=dfs(t);
    }
    return sum;
}


void solve()
{
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        int x;
        cin>>x;

        while(x--){
            int T;
            cin>>T;
            edg[i].push_back(T);
        }
    }

    cout<<dfs(n);







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