#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
int n,m;
string s;

struct SA
{
    int n;
    vector<int> sa, rk, lc;
    SA(string &s){
        n = s.size();
        sa.resize(n);
        lc.resize(n-1);
        rk.resize(n);
        iota(sa.begin(), sa.end(), 0);
        sort(sa.begin(), sa.end(), [&](int a, int b){
            return s[a] < s[b];
        });
        rk[sa[0]] = 0;
        for(int i=1; i<n; ++i){
            rk[sa[i]] = rk[sa[i-1]] + (s[sa[i]] != s[sa[i-1]]);
        }
        int k = 1;
        vector<int> tmp, cnt(n);
        tmp.reserve(n);
        while(rk[sa[n-1]] < n-1){
            tmp.clear();
            for(int i=0; i<k; ++i)tmp.push_back(n-k+i);
            for(auto i : sa){
                if(i >= k){
                    tmp.push_back(i - k);
                }
            }
            fill(cnt.begin(), cnt.end(), 0);
            for(int i=0; i<n; ++i)++cnt[rk[i]];
            for(int i=1; i<n; ++i)cnt[i] += cnt[i-1];
            for(int i=n-1; i>=0; --i){
                sa[--cnt[rk[tmp[i]]]] = tmp[i];
            }
            swap(rk, tmp);
            rk[sa[0]] = 0;
            for(int i=1; i<n; ++i){
                rk[sa[i]] = rk[sa[i-1]] + (tmp[sa[i-1]] < tmp[sa[i]] || sa[i-1] + k == n || tmp[sa[i-1] + k] < tmp[sa[i] + k]);
            }
            k *= 2;
        }
        for(int i=0, j=0; i<n; ++i){
            if(rk[i] == 0){
                j = 0;
            }
            else{
                for(j -= (j > 0); i+j < n && sa[rk[i]-1] + j < n && s[i + j] == s[sa[rk[i]-1] + j]; ++j);
                lc[rk[i]-1] = j;
            }
        }
    }
};
template<class T, class Cmp = less<T>>
struct RMQ
{
    const Cmp cmp = Cmp();
    static constexpr unsigned B = 64;
    using u64 = unsigned long long;
    int n;
    vector<vector<T>> a;
    vector<T> pre, suf, ini;
    vector<u64> stk;
    RMQ(){}
    RMQ(const vector<T> &v){
        init(v);
    }
    void init(const vector<T> &v){
        n = v.size();
        pre = suf = ini = v;
        stk.resize(n);
        if(!n)return;
        const int M = (n - 1) / B + 1;
        const int lg = __lg(M);
        a.assign(lg + 1, vector<T>(M));
        for(int i=0; i<M; ++i){
            a[0][i] = v[i * B];
            for(int j=1; j<B && i*B + j < n; ++j){
                a[0][i] = min(a[0][i], v[i*B + j], cmp);
            }
        }
        for(int i=1; i<n; ++i){
            if(i % B){
                pre[i] = min(pre[i], pre[i-1], cmp);
            }
        }
        for(int i=n-2; i>=0; --i){
            if(i % B != B - 1){
                suf[i] = min(suf[i], suf[i+1], cmp);
            }
        }
        for(int j=0; j<lg; ++j){
            for(int i=0; i+(2<<j)<=M; ++i){
                a[j+1][i] = min(a[j][i], a[j][i + (1<<j)], cmp);
            }
        }
        for(int i=0; i<M; ++i){
            const int l = i * B;
            const int r = min(1U * n, l + B);
            u64 s = 0;
            for(int j=l; j<r; ++j){
                while(s && cmp(v[j], v[__lg(s) + l])){
                    s ^= 1ULL << __lg(s);
                }
                s |= 1ULL << (j - l);
                stk[j] = s;
            }
        }
    }
    T operator()(int l, int r){
        if(l / B != (r - 1) / B){
            T ans = min(suf[l], pre[r - 1], cmp);
            l = l / B + 1;
            r = r / B;
            if(l < r){
                int k = __lg(r - l);
                ans = min({ans, a[k][l], a[k][r - (1<<k)]}, cmp);
            }
            return ans;
        }
        else{
            int x = B * (l / B);
            return ini[__builtin_ctzll(stk[r-1] >> (l - x)) + l];
        }
    }
    
};



void solve()
{
    cin >> n >> m;
    cin >> s;
    SA sa(s);
    RMQ rmq(sa.lc);
    auto check = [&](int l, int r){
        l = sa.rk[l-1];
        r = sa.rk[r-1];
        if(l > r)swap(l, r);
        return rmq(l, r);
    };
    vector<vector<int>> cnt(n+10, vector<int>(30));
    vector<int> sum(n + 10);
    vector<int> st(n+10);
    for(int j=1; j<=n/2; ++j){
        int res = m * 2;
        for(int i=j+1, t=1; i<=n; i+=j, ++t){
            int k = 0;
            while(k < j && i+k <= n){
                int lcp = check(i+k, i-j+k);
                if(lcp == 0){
                    --res;
                    ++k;
                }
                else k += lcp;
                if(res < 0)break;
            }
            if(res < 0)break;
        }
        if(res < 0)continue;
        vector<int> p;
        for(int i=j+1; i<=n; i+=j){
            int k = 0;
            while(k < j && i+k <= n){
                int lcp = check(i+k, 1+k);
                if(lcp == 0){
                    if(st[k] != j)fill(cnt[k].begin(), cnt[k].end(), 0), p.push_back(k), sum[k] = 0;
                    st[k] = j;
                    cnt[k][s[i+k-1]-'a']++;
                    sum[k]++;
                    ++k;
                }
                else k += lcp;
                if(p.size() > m)break;
            }
            if(p.size() > m)break;
        }
        if(p.size() > m)continue;
        int tot = 0, mx_sum = 0;
        for(auto x : p){
            int cur = n / j;
            cur += (x+1 <= n%j);
            cnt[x][s[x]-'a'] += cur - sum[x];
            tot += cur;
            int mx = 0;
            for(int i=0; i<26; ++i)mx = max(mx, cnt[x][i]);
            mx_sum += mx;
        }
        if(tot - mx_sum <= m){
            // cout << j << endl;
            // cout << tot << ' ' << mx_sum << endl;
            // for(auto x : p){
            //     cout << x << endl;
            //     cout << n / j + (x+1 <= n%j) << ' ' << sum[x] << endl;
            //     for(int i=0; i<26; ++i)cout << cnt[x][i] << ' ';cout << endl;
            // }
            cout << "Yes" << endl;return;
        }
    }
    cout << "No" << endl;





}


signed main()
{
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