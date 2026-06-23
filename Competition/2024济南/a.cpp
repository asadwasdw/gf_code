#include<bits/stdc++.h>
#define endl '\n'
using ll = long long;
using i64 = long long;
using namespace std;
constexpr int N = 2e6 + 10;

int n,m,k;
string s[N];
void solve(){
    cin >> n >> m >> k;
    string t;
    for(int i=1; i<=n; ++i){
        cin >> s[i];
        s[i] = " " + s[i];
        if(t.size() == 0){
            t = s[i].substr(1, k);
        }
        // cout << s[i] << endl;
    }
    int cnt = 0;
    int x = 1, y = 1;
    for(int i=1; i<=n; ++i){
        for(int j=1, p=1; j<=m*k; j += k, ++p){
            if(s[i].substr(j, k) != t){
                ++cnt;
                x = i, y = p;
            }
        }
    }
    if(cnt > 1){
        cout << 1 << ' ' << 1 << endl;
    }
    else cout << x << ' ' << y << endl;


}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}