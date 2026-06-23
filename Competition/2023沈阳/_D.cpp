#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>PII;
// const int N=1e6+10;

// const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
constexpr int mod = 936500749, mod2 = 889171919, base = 13331;
struct node
{
    vector<ull> h, p;
    void get(string &s){
        h.clear();
        p.clear();
        h.resize(s.size() + 1);
        p.resize(s.size() + 1);
        p[0] = 1;
        for(int i=1; i<=s.size(); ++i){
            h[i] = h[i-1] * base + s[i-1];
            p[i] = p[i-1] * base;
        }
    }
    ull get(int l, int r){
        return h[r] - h[l-1] * p[r - l + 1];
    }
}t1, t2;
string s,t;
vector<ull> tot;
ll ans = 0;
void check(string &s, string &t, bool flag){
    tot.clear();
    t1.get(s);
    t2.get(t);
    unordered_map<ull, int> mp;
    for(int i=1; i<=t.size(); ++i){
        for(int j=i; j<=t.size(); ++j){
            // tot.push_back(t2.get(i, j));
            mp[t2.get(i, j)]++;
        }
    }
    // sort(tot.begin(), tot.end());
    vector<vector<ll>> sum(s.size() + 1, vector<ll>(s.size() + 1, 0));
    
    for(int i=1; i<=s.size(); ++i){
        for(int j=1; j<=i; ++j){
            sum[i][j] = sum[i][j-1];
            if(mp.count(t1.get(j, i)))
            sum[i][j] += mp[t1.get(j, i)];
            // sum[i][j] += upper_bound(tot.begin(), tot.end(), t1.get(j, i)) - lower_bound(tot.begin(), tot.end(), t1.get(j, i));
        }
    }
    for(int i=1; i<=s.size(); ++i){
        for(int j=i+2; j<=s.size(); ++j){
            if(s[i-1] != s[j-1])continue;
            int l = 1, r = min(j - i - 1, (int)s.size() - j + 1);
            while(l < r){
                int mid = l + r >> 1;
                if(t1.get(i, i + mid - 1) == t1.get(j, j + mid - 1))l = mid + 1;
                else r = mid;
            }
            if(t1.get(i, i + l - 1) != t1.get(j, j + l - 1))--l;
            assert(i + l < j && l > 0);

            ans += sum[j-1][i + l] - sum[j-1][i];
            // cout << ans << ' ' << i << ' ' << j << ' ' << l << endl;
        }
    }
    ll res = 0;
    if(flag){
        for(int i=1; i<=s.size(); ++i){
            ans += sum[i][i];
            res += sum[i][i];
        }
        cout << res << endl;
    }
}


void solve()
{
    cin >> s >> t;
    // s = string(5000, 'a');
    // t = s;
    
    check(s, t, true);
    cout << ans << endl;
    check(t, s, false);
    cout << ans << endl;
    






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