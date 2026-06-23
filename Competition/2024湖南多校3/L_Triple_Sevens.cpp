#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int n;
void solve()
{
    cin >> n;
    int cnt = 0;
    for(int i=1; i<=3; ++i){
        bool f = false;
        for(int j=1; j<=n; ++j){
            int x;cin >> x;
            if(x == 7)f = true;
        }
        if(f)++cnt;
    }
    if(cnt == 3){
        cout << "777\n";
    }
    else cout << 0;






}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}