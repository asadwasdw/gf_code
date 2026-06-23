#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>adj(N);
int f[N];
int cnt = 0;
int ask(int a, int b) {
	cnt ++;
    cout << "? " << a << " " << b << endl;
    int c; cin >> c;
    return c;
}



int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}

vector<PII> ans;

void merge(int a, int b) {
    a = find(a), b = find(b);
    f[a] = b;
}


void dfs(int a, int b) {
	if(find(a) == find(b)) return; 
    int c = ask(a, b);
    if(c == a) {
        merge(a, b);
        ans.push_back({a, b});
        return;
    }
    dfs(a, c);
    dfs(c, b);
}

void solve()
{
	cnt = 0;
    int n; 
    cin >> n;
    ans.clear();
    for(int i = 1; i <= n; i ++) {
        f[i] = i;
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if(find(i) != find(j))
                dfs(i, j);
        }
    }
    cout << "! ";

    for(auto t : ans) cout << t.first << " " << t.second << ' ';
    cout << endl;
    
    assert(cnt <= 15 * n);

}


signed main()
{


    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}
