#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
constexpr int N = 2e5+10;

vector<int> z_function(string &s){
    int n = (int)s.size();
    vector<int> z(n);
    for(int i=1,l=0,r=0; i<n; ++i){
        if(i <= r && z[i-l] < r - i + 1){
            z[i] = z[i-l];
        }
        else{
            z[i] = max(0, r-i+1);
            while(i + z[i] < n && s[z[i]] == s[i + z[i]])++z[i];

        }
        if(i + z[i] - 1 > r)l = i, r = i + z[i] - 1;
    }
    return z;
}
constexpr int mod = 936500749, mod2 = 889171919, base = 13331;
int n;
string s[N];
map<pair<ll, ll>, int> mp;
void solve(){
    while(cin >> n){
        ll res = 0;
        mp.clear();
        for(int i=1; i<=n; ++i){
            cin >> s[i];
            ll ha = 0, ha2 = 0;
            for(int j=0; j<s[i].size(); ++j){
                ha = (ha * base % mod + s[i][j]) % mod;
                ha2 = (ha2 * base % mod2 + s[i][j]) % mod2;
            }
            mp[{ha, ha2}]++;
            res += mp[{ha, ha2}] - 1;
        }    
        for(int i=1; i<=n; ++i){
            auto nx = z_function(s[i]);
            // for(int j=0; j<nx.size(); ++j)cout << nx[j] << " \n"[j == (int)nx.size()-1];
            ll ha = 0, ha2 = 0;
            for(int j=0; j<s[i].size(); ++j){
                ha = (ha * base % mod + s[i][j]) % mod;
                ha2 = (ha2 * base % mod2 + s[i][j]) % mod2;
                if((j+1 < nx.size() && nx[j+1] == (int)s[i].size() - j - 1)){
                    if(mp.count({ha, ha2})){
                        // cout << i << endl;
                        res += (ll)mp[{ha, ha2}];
                    }
                }
            }
        }
        cout << res << endl;
    }
    


}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}