// #pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 


ll f[2][21][1<<17];  
vector<int> p;

ll dfs(int u, int last, bool lead, bool limit, int op){ // l 
    if(u == -1)return 1;
    if(!lead && !limit && ~f[op][u][last])return f[op][u][last];
    int up = limit ? p[u] : (op ? 15 : 9);
    ll res = 0;
    for(int i=0; i<=up; ++i){
        if(i == 0 && lead){
            res += dfs(u-1, 0, true, limit && i == p[u], op);
        }
        else{
            if(last >> i & 1)continue;
            res += dfs(u-1, last | (1<<i), false, limit && i == p[u], op);
        }
    }
    if(!limit && !lead)f[op][u][last] = res;
    return res;
}

ll cal(__int128 n, int op){
    if(n < 0)return 0ll;
//    if(n == 0)return 1ll;
    p.clear();
    while(n){
        if(op == 0)p.push_back(n % 10), n /= 10;
        else p.push_back(n % 16), n /= 16;
    }
    return dfs(p.size()-1, 0, true, true, op);
}

void solve()
{
    char c;
    int op;
    cin >> c >> op;
    auto get = [&](string s){ 
        ll res = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i] >= 'a'){
                res = res * 16 + 10 + (s[i] - 'a');
            }
            else{
                res = res * 16 + (s[i] - '0');
            }
        }
        return res;
    };
    auto get2 = [&](ll n){
        string s;
        if(n == 0){
            s = "0";
            return s;
        }
        while(n){
            int x = n % 16;
            n /= 16;
            if(x >= 10)s.push_back('a' + x - 10);
            else s.push_back('0' + x);
        }
        reverse(s.begin(), s.end());
        return s;
    };
    ll mx1 = 8877691, mx2 = 53319412081141;
    // cout << (unsigned long long)cal(((__int128)1 << 64) - 1, 1) <<endl;
    if(op == 1){
        if(c == 'd')op = 0;
        else op = 1;
        unsigned long long x;
        if(c == 'd'){
            cin >> x;
        }
        else{
            string s;cin >> s;
            x = get(s);
        }
        if(c == 'd' && x > mx1 || (c == 'h' && x > mx2)){
            cout << '-' << endl;
            return;
        }
        __int128 l = 0, r = ((__int128)1 << 64) - 1;
        while(l < r){
            __int128 mid = l + r >> 1;
            if(cal(mid, op) >= x)r = mid;
            else l = mid + 1;
        }
        // if(l == ((__int128)1 << 64)){
        //     cout << '-' << endl;
        //     return;
        // }
        if(c == 'd')
        cout << (unsigned long long)l << endl;
        else cout << get2(l) << endl;

    }
    else{
        if(c == 'd')op = 0;
        else op = 1;
        if(c == 'd'){
            unsigned long long a,b;
            cin >> a >> b;
            __int128 aa = a, bb = b;
            cout << (unsigned long long)(cal(bb, op) - cal(aa-1, op)) << endl;
        }
        else{
            string x,y;
            cin >> x >> y;
            __int128 a = get(x), b = get(y);
            cout << (get2(cal(b, op) - cal(a-1, op))) << endl;
        }
    }
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    for(int i=0; i<21; ++i)for(int j=0; j<1<<17; ++j)f[0][i][j] = f[1][i][j] = -1;
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
