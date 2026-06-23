#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int f[N];
int find(int x){
    if(x!=f[x])return f[x] = find(f[x]);
    return x;
}

int a[N][N];
int ans[N];

void solve()
{
    int n;cin>>n;

    for(int i=1;i<=n;i++){
        ans[i] = (1<<30)-1;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(i!=j)ans[i] &= a[i][j];
        }
    }
    bool ky = true;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++){
            if(i != j &&  a[i][j] != (ans[i]|ans[j])) ky = false;
        }
    }

    if(ky) {
        cout <<"Yes\n";
        for(int i=1;i<=n;i++)cout <<ans[i]<<" ";cout << '\n';
    }
    else cout << "No\n";


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}