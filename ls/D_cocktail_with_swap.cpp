#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>edg(N);
vector<vector<char>>edg2(N);

int n,m;
int a[N];
int f[N];

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return;
    f[x] = y;
}


void solve()
{
    int n, l, r; 
    cin >> n >> l >> r;
    string s; cin >> s;
    s = " " + s;

    for(int i = 1; i <= n + 1; i ++) {
        f[i] = i;
    }

    for(int i = 1; i <= n; i ++) {
        int L = i + l , R = min(n, i + r);
        if(L > n) continue;;
        // cout << L << " " << R << endl;
        
        for(int j = find(L); j < R; j = find(j)) {
            merge(j, j + 1);
        } 
        merge(i, L);
    }

    for(int i = 1; i <= n; i ++) {
        int fa = find(i);
        edg[fa].push_back(i);
        edg2[fa].push_back(s[i]);
    }

    for(int i = 1; i <= n; i ++) {
        if(i != find(i)) continue;
        sort(edg[i].begin(),edg[i].end());
        sort(edg2[i].begin(),edg2[i].end());

        for(int j = 0; j < edg[i].size(); j ++) {
            s[edg[i][j]] = edg2[i][j];
        }
    }

    cout << s.substr(1,n);



}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}