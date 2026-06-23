#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
constexpr int N = 2e6 + 10, mod = 1e9+7;

int n;
int a[N];
int fa[N];
int find(int k){
    return k == fa[k] ? k : fa[k] = find(fa[k]);
}
int merge(int a, int b){
    int f1 = find(a), f2 = find(b);
    if(f1 == f2)return 1;
    fa[f2] = f1;
    return 0;
}

void solve(){
    cin >> n;
    for(int i=1; i<=n; ++i)cin >> a[i];
    for(int i=1; i<=n+n+n; ++i)fa[i] = i;
    vector<array<int, 3>> p;
    for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j){
        int x;cin >> x;
        p.push_back({x, i, j});
    }
    for(int i=1; i<=n; ++i){
        if(a[i] == 1)merge(i*2, i*2+1);
    }
    sort(p.begin(), p.end());
    ll res = 0;
    for(auto [x, l, r] : p){
        if(l == r){
            if(a[l] <= 1)continue;
            if(find(fa[l*2]) == find(fa[l*2+1]))continue;
            res += (ll)x * (a[l] - 1);
            merge(l*2, l*2+1);
        }
        else{
            if(find(l*2) == find(r*2))continue;
            int f1 = (find(l*2) == find(l*2+1));
            int f2 = (find(r*2) == find(r*2+1));
            if(f1 && f2){
                res += x;
            }
            else if(f1){
                res += (ll)x * a[r];
                merge(r*2, r*2+1);
            }
            else if(f2){
                res += (ll)x * a[l];
                merge(l*2, l*2+1);
            }
            else{
                res += (ll)x * (max(a[l], a[r]));
                res += (ll)x * (min(a[l], a[r]) - 1);
                merge(l*2+1, r*2+1);
                merge(l*2, l*2+1);
            }
            merge(l*2, r*2); 
        }
    }
    cout << res << endl;


}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}