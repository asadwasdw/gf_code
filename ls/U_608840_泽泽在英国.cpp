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

int a[N], b[N];

void solve()
{
    int n;
    cin >> n;

    assert(1 <= n && n <= 100000);

    
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        assert(1 <= a[i] && a[i] <= 100000);
    }

    stack<int> st;
    int ans = 0;

    for (int i = 0; i <= n + 1; ++i) {
        while (st.size() && a[st.top()] > a[i]) {
            int h = a[st.top()]; st.pop();
            int l = st.empty() ? 0 : st.top() + 1;  
            int w = i - l;                          
            ans = max(ans,h * w);
        }
        st.push(i);
    }

    cout << ans << endl;
}

void solve2() {
    int n;
    cin >> n;
    
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int l = 1; l <= n; l ++) {
        for(int r = l; r <= n; r ++) {
            int h = INF;
            for(int i = l; i <= r; i ++) {
                h = min(a[i], h);
            }
            ans = max((r - l + 1) * h, ans);
        }
    }

    cout << ans << endl;
}

void solve3() {
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        
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