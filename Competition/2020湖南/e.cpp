#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
typedef pair<int, int> PII;
constexpr int N = 2e6+10, mod = 1e9+7;

int n,m, a[N];
int tr[N];
void add(int x, int d){
    while(x <= n){
        tr[x] += d;
        x += x&-x;
    }
}
int query(int x){
    int res = 0;
    while(x > 0){
        res += tr[x];
        x -= x&-x;
    }
    return res;
}

void solve(){
    while(cin >> n >> m){
        for(int i=1; i<=n; ++i)cin >> a[i];
        int res = 0;
        vector<int> p(1, 0);
        auto get = [&](int l, int r, int i, int x){
            while(l < r){
                int mid = l + r >> 1;
                if(x - (i - mid + 1) >= m)r = mid;
                else l = mid + 1;
            }
            return l;
        };
        // vector<int> work;
        int work_lz;
        set<int> work;
        set<PII> big;
        
        for(int i=1; i<=n; ++i){
            while(p.size() > 1 && a[p.back()] <= a[i]){
                if(a[p.back()] - (i-1 - p.back() + 1) >= m){
                    auto it = get(p[p.size()-2]+1, p.back(), i-1, a[p.back()]);
                    int val = a[p.back()] - (i - 1 - it + 1) - m;
                    if(val > p.back() - p[p.size()-2])big.erase(big.find({val, p.back() - p[(int)p.size()-2]}));
                    else work.erase(work_lz + val);
                }
                p.pop_back();
            }
            auto it = get(p.back()+1, i, i, a[i]);
            int val = a[i] - (i - it + 1) - m;
            ++work_lz;
            if(val > i - p.back())big.insert({val, i - p.back()});
            else work.insert(val - work_lz);
            
            p.push_back(i);
        }
    }


}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}