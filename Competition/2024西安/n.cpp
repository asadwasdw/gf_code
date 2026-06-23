#include<bits/stdc++.h>
#define ll long long
using namespace std;
// #define int long long
typedef pair<int,int> PII;
const int N = 1e6 + 10;
const int mod = 998244353;

using i64 = long long;
void solve() {
    string tmp; 
    vector<string> s(2);
    getline(cin, tmp);
    for (int i = 0; i < 2; i++) {
        getline(cin, s[i]);
    }
    vector<int> t;
    {  
        vector<int> z;
        int idx = s[0].find('(', 0);
        z.push_back(idx);
        idx = s[0].find(',', idx + 1);
        z.push_back(idx);
        if (s[0].find(',', idx + 1) == string::npos) {
            idx = s[0].find(')', idx + 1);
            z.push_back(idx);
        } else {
            idx = s[0].find(',', idx + 1);
            z.push_back(idx);
            idx = s[0].find(')', idx + 1);
            z.push_back(idx);
        }
        for (int i = 1; i < z.size(); i++) {
            t.push_back(stoll(s[0].substr(z[i - 1] + 1, z[i] - z[i - 1] - 1)));
        }
    }
    
    // bool ok = false; 
    // int last = 0;
    // for (auto c : s[0]) {
    //     if (c >= '0' && c <= '9') {
    //         ok = true;
    //         last = last * 10 + c - '0';
    //     } else {
    //         if (ok) {
    //             t.push_back(last);
    //             last = 0;
    //             ok = false;
    //         }
    //     }
    // }
    char id1 = s[0][4];
    i64 ans = 0;
    // {  
        vector<int> z;
        int idx = s[1].find('(', 0);
        z.push_back(idx);
        idx = s[1].find(',', idx + 1);
        z.push_back(idx);
        if (s[1].find(',', idx + 1) == string::npos) {
            idx = s[1].find(')', idx + 1);
            z.push_back(idx);
        } else {
            idx = s[1].find(',', idx + 1);
            z.push_back(idx);
            idx = s[1].find(')', idx + 1);
            z.push_back(idx);
        }
    // }
    // cerr << t[0] << ' ' << t[1] << ' ' << t[2] << ' ';
    int nx = (t.size() > 2 ? t[2] : 1);
    int i = t[0];
    // for (int i = t[0]; i < t[1]; i += nx) 
    while(1){
        if (nx < 0 && i <= t[1]) break;
        if (nx > 0 && i >= t[1]) break; 
        i64 d, val1, val2;
        if (z.size() == 4) {
            // cerr << s[1].substr(z[2] + 1, z[3] - z[2] - 1) << "\n";
            if (s[1].substr(z[2] + 1, z[3] - z[2] - 1)[0] == id1) d = i;
            else d = stoll(s[1].substr(z[2] + 1, z[3] - z[2] - 1));
        } else {
            d = 1;
        }
        if (s[1][z[0] + 1] == id1) {
            val1 = i;
            val2 = stoll(s[1].substr(z[1] + 1, z[2] - z[1] - 1));
        } else if (s[1][z[1] + 1] == id1) {
            
            val1 = stoll(s[1].substr(z[0] + 1, z[1] - z[0] - 1));
            val2 = i;
        } else {
            val1 = stoll(s[1].substr(z[0] + 1, z[1] - z[0] - 1));
            val2 = stoll(s[1].substr(z[1] + 1, z[2] - z[1] - 1));
        }
        
        if (d < 0) {
            val2++;
            if (val1 >= val2) {
                i64 cnt = abs(val2 - val1) / abs(d) + 1;
                ans += (val1 + val1 + d * (cnt - 1)) * abs(cnt) / 2;
            }
        } else {
            val2--;
            if (val1 <= val2) {
                // cerr << val1 << ' ' << val2 << ' ' << d << "\n";

                i64 cnt = abs(val2 - val1) / abs(d) + 1;
                // cerr << cnt << ' ';
                ans += (val1 + val1 + d * (cnt - 1)) * abs(cnt) / 2;
                // cerr << (val1 + val1 + d * cnt) * abs(cnt) / 2 << "\n";

            }
        }
        
        i += nx;
    }   
    // for (int i = 0; i < 2; i++) {
    //     cout << s[i] << "\n";
    // }
    cout << ans << "\n";

}

signed main() {
    // ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}