#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
// #define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n,m,k,st[N],ed[N];

struct ji{
    vector<int>v;
    bool operator < (const ji &k) {
        int s = min(v.size(), k.v.size());
        for(int i = 0; i < s; i++) {
            if(v[i] != k.v[i]) return v[i] > k.v[i];
        }
        return v.size() < k.v.size();
    }

    bool operator == (const ji &k) {
        if(v.size() != k.v.size())return 0;
        for(int i = 0; i < k.v.size(); i++) if(v[i] != k.v[i]) return 0;
        return 1;
    }

    ji operator * (const ji &k) {
        ji res;
        int i = 0, j = 0;
        while(i < v.size() && j < k.v.size()) {
            if(v[i] < k.v[j]) res.v.push_back(v[i++]);
            else res.v.push_back(k.v[j++]);
        }

        while(i < v.size())   res.v.push_back(v[i++]);
        
        while(j < k.v.size()) res.v.push_back(k.v[j++]);
        return res;
    }


    ll w(){
        ll ans = 1;
        for(auto t : v) ans *= t;
        return ans;
    }
    void print() {
        for(auto t:v)cout << t << ' ';
        cout << endl;
    }

}a[N],b[N],c[N];

ll sum1(ji x) {// 计算有多少种组合小于x
    ll ans = 0;
    for(int i = 1, j = m; i <= n; i ++) {
        while(j &&  x < a[i] * b[j]) j--;
        ans += j;
    }
    return ans;
}

ll sum(ji x) { // 计算有多少种组合等于x
    int ans = 0;
    for(int i = 1, j = m; i <= n; i ++) {
        while(j && x < (a[i] * b[j])) j--;
        int si = i, sj = j;
        while(j && x == (a[si] * b[j])) j--;
        while(i && x == (a[i] * b[sj])) i++;
        ans += (i - si) * (sj - j);
    }
    return ans;
}

ji div(int x) {
    ji res;
    for(int i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            while(x % i == 0) {
                res.v.push_back(i);
                x /= i;
            }
        }
    }
    if(x > 1) res.v.push_back(x);

    return res;
}

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        a[i] = div(x);
    }
    for (int i = 1; i <= m; i ++) {
        int x; cin >> x;
        b[i] = div(x);

    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    ji l = a[1] * b[1], r = a[n] * b[m];
    int cnt = 20;
    while(cnt) {
        int tot = 0;
        st[0] = ed[0] = m;
        for(int i = 1; i <= n;i ++) { // 求范围在[l,r]的组合个数;
            st[i] = st[i - 1], ed[i] = ed[i - 1];
            while(st[i] > 1 && (!((a[i] * b[st[i] - 1]) < l))) st[i] --;
            while(ed[i]  && ( r < (a[i] * b[ed[i]]) ) ) ed[i] --;
            tot += ed[i] - st[i] + 1;
        }
        if(tot == sum(l) + sum(r)) break; // 说明在[l,r]内，只有{l,r};在继续二分下去l和r都不会。
        //同时在二分的过程中，保证了sum1(r)>k,那么第k小数肯定不是组成r的，那么答案就是l;
        tot = (1ll*rand()*rand()*rand()) % tot + 1;
        int x,y;
        for(int i = 1; i <= n;i ++) {
            if(tot > ed[i] - st[i] + 1) tot -= ed[i] - st[i] + 1;
            else {
                x = i;
                y = st[i] + tot - 1;
                break;
            }
        }
        // 上面的步骤都是为了重新找到一对数(x,y)，使l<a[x]*b[y]<r;
        ji mid = a[x] * b[y];
        if(sum1(mid) <= k) l = mid;
        else r = mid;
    }
    cout << l.w() <<"\n";

}


signed main()
{
    srand(time(0));
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