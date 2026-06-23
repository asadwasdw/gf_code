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

//vector<vector<int>>edg(N);
PII b[N];

bool cmp(PII a, PII b) {
    return a.second < b.second;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> b[i].first;
    for(int i = 1; i <= n; i ++) cin >> b[i].second;
    int ans = 0;
    int t = 0;

    sort(b + 1, b + n + 1, cmp);
    multiset<int>st;

    for(int i = 1; i <= n; i ++) {
        b[i].first += b[i - 1].first;
        if(st.size() < k) {
            st.insert(b[i].second);
            t += b[i].second;
        }
        else {
            if(st.size() && *st.begin() < b[i].second) {
                t -= *st.begin(); 
                st.erase(st.begin());
                st.insert(b[i].second);
                t += b[i].second;
            }
            else {

            }
        }
        b[i].second += b[i - 1].second;
        ans = max(ans, b[i].second - t - b[i].first);
    }
    cout << ans << endl;
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