#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);


void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    // s.erase(unique(s.begin(),s.end()), s.end());
    // cout << s << endl;
    set<char> num;

    vector<int> a(n + 10, 0), b(n + 10, 0);
    map<char,bool> st;
    n = s.size();
    s = " " + s;
    for(int i = 1; i <= n; i ++) {
        a[i] = a[i - 1];
        if(st[s[i]] == false) {
            st[s[i]] = true;
            a[i] ++;
        }
        num.insert(s[i]);
    }

    st.clear();
    for(int i = n; i; i --) {
        b[i] = b[i + 1];
        if(st[s[i]] == false) {
            st[s[i]] = true;
            b[i] ++;
        }
    }
    // for(int i = 1; i <= n; i += 1) cout << a[i] << " \n"[i == n];
    // for(int i = 1; i <= n; i += 1) cout << b[i] << " \n"[i == n];

    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] != a[i - 1]) {
            ans += b[i + 1];
            // cout << ans << " " << i << endl;
        }
    }
    cout << ans + num.size();
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