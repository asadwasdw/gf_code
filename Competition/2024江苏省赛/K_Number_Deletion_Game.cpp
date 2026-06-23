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

int calc(multiset<int> st) {
    if (st.size() == 0) return 0;
    set<int> s;
    int mx = *prev(st.end());
    st.erase(prev(st.end()));
    s.insert(calc(st));
    for (int l = 1; l < mx; l++) {
        st.insert(l);
        s.insert(calc(st));
    }
    int cnt = 0;
    while (s.find(cnt) != s.end())cnt++;
    return cnt;
}

void solve()
{

    int n; cin >> n;
    // multiset<int> st;
    // for (int i = 0; i < n; i++) {
    //     int x;cin >> x;
    //     st.insert(x);
    // }
    // cout << calc(st);

    int mx = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x > mx) {
            mx = x, cnt = 1;
        } else if (x == mx) cnt++;
    }
    if (cnt % 2) cout << "Alice\n";
    else cout << "Bob\n";



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