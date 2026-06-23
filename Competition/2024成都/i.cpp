#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int INF = 0x3f3f3f3f;
using i64 = long long;
typedef long long ll;


int n,m;
int a[N];

void solve() {
    cin >> n >> m;
    for(int i=1; i<=n; ++i)cin >> a[i];
    a[0] = -1;
    a[n+1] = -1;
    set<int> p;
    map<int, int> mp;
    for(int i=1,j=1; i<=n; ++i){
        if(a[i] > a[i+1]){
            p.insert(j);
            mp[i - j + 1] ++;
            j = i + 1;
        }
    }
    auto check = [&](){
        int temp = *p.rbegin();
        mp[n - temp + 1] --;
        // for(auto [x, y] : mp)cout << x << '-' << y << ' ';cout << endl;
        int res = 0;
        for(auto &&it : mp){
            if(it.second)res = __gcd(res, it.first);
            if(res == 1)break;
        }
        mp[n - temp + 1] ++;
        if(res == 0)return n;
        int cnt = 0;
        for(int i=1; i*i<=res; ++i){
            if(res % i == 0){
                ++cnt;
                if(res/i != i)++cnt;
            }
        }
        return cnt;
    };
    auto add = [&](int x){
        ++mp[x];
    };
    auto del = [&](int x){
        if(--mp[x] == 0){
            mp.erase(x);
        }
    };
    // for(auto [x, y] : mp)cout << x << '-' << y << ' ';cout << endl;
    cout << check() << endl;
    while(m--){
        int x,v;
        cin >> x >> v;
        auto it = p.upper_bound(x);
        --it;
        int l = *it;
        int len = n - l + 1;
        if(next(it) != p.end())len = *next(it) - l;
        del(len);
        int r = l + len - 1;
        int p1 = -1, p2 = -1, p3 = -1, p4 = -1;
        if(a[x+1] >= a[x] && a[x+1] < v){
            add(r - x);
            p1 = x+1;
            // p.insert(x+1);
            r = x;
        }
        else if(v <= a[x+1] && a[x] > a[x+1]){
            int temp = n - *next(it) + 1;
            if(next(next(it)) != p.end())temp = *next(next(it)) - *next(it);
            del(temp);
            p2 = *next(it);
            // p.erase(*next(it));
            r += temp;
        }
        if(a[x] >= a[x-1] && v < a[x-1]){
            add(x - l);
            p3 = l;
            // p.insert(l);
            l = x;
        }
        else if(a[x] < a[x-1] && v >= a[x-1]){
            int temp = l - *prev(it);
            del(temp);
            p4 = *prev(it);
            // p.erase(*prev(it));
            l -= temp;
        }
        p.erase(it);
        if(p1 != -1)p.insert(p1);
        if(p2 != -1)p.erase(p2);
        if(p3 != -1)p.insert(p3);
        if(p4 != -1)p.erase(p4);
        add(r - l + 1);
        p.insert(l);
        // for(auto x : p)cout << x << ' ';cout << endl;
        // for(auto [x, y] : mp)cout << x << '-' << y << ' ';cout << endl;
        cout << check() << endl;
        a[x] = v;
    }



}

signed main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
}