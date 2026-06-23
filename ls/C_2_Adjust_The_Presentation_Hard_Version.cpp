#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);
int a[N],fa[N],b[N];
set<int> s[N];

int cnt = 0;
int n, m, q;

void print() {
    if(cnt == n - 1) cout << "YA";
    else cout << "TIDAK";
    cout << endl;
}

int check(int i) {
    if(i < 1 || i >= n) return 0;
    if(*s[a[i]].begin() <= *s[a[i + 1]].begin()) return 1;
    return 0;
}

void modify(int id, int t) {
    cnt -= check(fa[b[id]]) + check(fa[b[id]] - 1);
    s[b[id]].erase(id);
    cnt += check(fa[b[id]]) + check(fa[b[id]] - 1);


    cnt -= check(fa[t]) + check(fa[t] - 1);
    s[t].insert(id); b[id] =  t;
    cnt += check(fa[t]) + check(fa[t] - 1);
}

void solve()
{
    
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        fa[a[i]] = i;
        s[i].clear();
        s[i].insert(m + 1);
    }

    for(int i = 1; i <= m; i ++) {
        cin >> b[i];
        s[b[i]].insert(i);
    }
    cnt = 0;
    for(int i = 1; i < n; i ++) {
        if(check(i)) cnt ++;
    }

    print();

    while(q --) {
        int s, t;
        cin >> s >> t;
        modify(s, t);
        print();
    }
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