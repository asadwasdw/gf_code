#include<bits/stdc++.h>
#define int long long 
using namespace std;
typedef long long ll;

const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
typedef unsigned long long ull;
//vector<vector<int>>edg(N);
const int P1 = 13331, P2 =  131;
typedef pair<ull,int>PII;
int a[N];
ull hx1[N],p1[N];
int st[N];

void init() {
    p1[0] = 1;
    // p2[0] = 1;
    for(int i = 1; i < N; i ++) {
        p1[i] = p1[i - 1] * P1;
        // p2[i] = p2[i - 1] * P2 % mod;
    }
}

map<PII,int>mp;

PII now;

void add(int x) {
    now.first += p1[x];
    // now.second = (now.second + p2[x])  % mod;
}

void cul(int x) {
    now.first -= p1[x];
    // now.second = (now.second - p2[x] + mod)  % mod;
}

void solve()
{
    mp.clear();
    int n;
    cin >> n;
    now.first = 0, now.second = 0;
    mp[now] ++;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        st[a[i]] ^= 1;
        if(st[a[i]]) {
            add(a[i]);
        }
        else cul(a[i]);
        ans += mp[now];
        mp[now] ++;
    }
    cout << n * (n + 1)/2 - ans << endl;
}


signed main()
{
    init();
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