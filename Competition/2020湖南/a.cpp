#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
constexpr int N = 2e6+10, mod = 1e9+7;



void solve(){
    int n;
    string s;
    while(cin >> n){
        cin >> s;
        vector<int> f(n+1);
        for(int i=1; i<=n; ++i){
            if(i-3 >= 1 && s[i-1] == '0' && s[i-2] == '2' && s[i-3] == '0' && s[i-4] == '2'){
                f[i] = f[i - 4] + 1;
            }
            f[i] = max(f[i], f[i-1]);
        }
        cout << f[n] << endl;
    }
    


}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}