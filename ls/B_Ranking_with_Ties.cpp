#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int ans[N];
PII t[N];

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> t[i].first;
        t[i].second = i;
    }

    sort(t + 1, t + n + 1,[](PII a, PII b){
        return a.first > b.first;
    });

    for(int i = 1; i <= n; i ++) {
        if(t[i].first == t[i - 1].first) {
            ans[t[i].second] = ans[t[i - 1].second];
        } else {
            ans[t[i].second] = i;
        }
    }

    for(int i = 1; i <= n; i ++) {
        cout << ans[i] << endl;
    }






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