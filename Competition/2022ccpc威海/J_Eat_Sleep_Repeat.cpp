#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
#define int long long 
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{

    int n, k;cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, int> mp;
    set<int> st;
    st.insert(-1);
    for (int i = 0; i < k; i++) {
        int x, y;cin >> x >> y;
        mp[x] = y;
        if (y == 0)st.insert(x);
    }
    sort(a.begin(), a.end());
    int res = 0;
    for (auto x : a) {
        auto it = st.lower_bound(x);
        it--;

        res += x - *it - 1;
        if (mp[*it + 1]) {
            mp[*it + 1]--;
            if (mp[*it + 1] == 0)st.insert(*it + 1);
        }
    }
    if (res % 2) cout << "Pico\n";
    else cout << "FuuFuu\n";





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