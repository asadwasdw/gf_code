#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

char a[N][N];

void solve()
{
    int n;
    cin>>n;
    
    for(int i = 1;i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>a[i][j];

    ll ans = 0;
    for(int i = 1; i <= n/2; i++) {
        for(int j = 1; j <= n/2; j++) {
        vector<char>t;
        int x = i;
        int y = j;

        for(int k = 1;k <= 4; k++){
            int nx = y;
            int ny = n - x + 1;
            x = nx;
            y = ny;
            t.push_back(a[x][y]);
        }

        sort(t.begin(),t.end());

        for(auto tt:t)
            ans+= t[3] - tt;
        //cout<<ans<<" "<<i<<" "<<j<<endl;


        }   
    }

    cout<<ans<<endl;

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