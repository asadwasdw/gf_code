#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
const int N=60010;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);

int n,q,m,k;
constexpr int base = 13331;
struct node
{
    vector<ull> h, p;
    void get(string &s){
        h.clear();p.clear();
        h.resize(s.size() + 10, 0);
        p.resize(s.size() + 10, 0);
        h[0] = 0;
        p[0] = 1;
        for(int i=1; i<=s.size(); ++i){
            h[i] = h[i-1] * base + s[i-1];
            p[i] = p[i-1] * base;
        }
    }

    ull get(int l, int r){
        return h[r] - h[l-1] * p[r - l + 1];
    }
}st;





void solve()
{
    cin >> n >> q >> m >> k;
    vector<node> ha(n + 1);
    string s;
    for(int i=1; i<=n; ++i){
        cin >> s;
        // cout << s << endl;
        ha[i].get(s);
    }
    // cout << "DEBUG" << endl;
    while(q--){
        cin >> s;
        st.get(s);
        // cout << s << endl;
        // cout << ha[1].get(1, 1) << ' ' << st.get(1, 1) << endl;
        int res = 0;
        for(int i=1; i<=n; ++i){
            int t = 0;
            for(int j=1; j<=m && t <= k+1; ++j){
                // cerr << j << endl;
                int l = 0, r = m - j + 1;
                while(l < r){
                    int mid = l + r >> 1;
                    if(ha[i].get(j, j+mid-1) == st.get(j, j+mid-1))l = mid + 1;
                    else r = mid;
                }
                if(l == 0){
                    ++t;
                    continue;
                }
                if(ha[i].get(j, j+l-1) != st.get(j, j+l-1))--l;
                if(l == 0){
                    ++t;
                    continue;
                }
                // cerr << "len:" << j << ' ' << l << endl;
                j = j + l - 1;
            }
            if(t <= k){
                ++res;
            }
        }
        cout << res << endl;
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