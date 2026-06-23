#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];
int b[N];
unordered_map<int,int>mp,mp2;

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i], mp[a[i]] = i;
    for(int i = 1; i <= n; i ++) cin >> b[i], mp2[b[i]] = i;
    vector<PII> ans;

    for(int i = 1; i <= n; i ++) {
        if(mp[i] < mp2[i]) {
            cout << "-1\n";
            return;
        }

        for(int j = i + 1 ; j <= n; j ++) {
            if(mp[j] < mp[i] && mp[j] >=  mp2[i]) {
                ans.push_back({mp[j],mp[i]});
                swap(a[mp[j]],a[mp[i]]);
                swap(mp[j],mp[i]);
            }
        }
    }

    // for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
    // for(int i = 1; i <= n; i ++) cout << b[i] << " \n"[i == n];
    cout << ans.size() << endl;
    for(auto [x, y] : ans) cout << x << " " << y << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}