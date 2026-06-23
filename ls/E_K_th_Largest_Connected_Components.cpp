#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);
int f[N];
int find(int x) {
    if(f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if(x == y)return;
    vector<int> res;
    sort(adj[x].begin(), adj[x].end(),[&](int a, int b){
        return a > b;
    });

    sort(adj[y].begin(), adj[y].end(),[&](int a, int b){
        return a > b;
    });

    int cnt = 11, i = 0, j = 0;
    while(cnt -- && (i < adj[x].size() || j < adj[y].size())) {
        if(i < adj[x].size() && j < adj[y].size()) {
            if(adj[x][i] > adj[y][j]) {
                res.push_back(adj[x][i]);
                i++;
            } else {
                res.push_back(adj[y][j]);
                j++;
            }
            continue;
        }

        if(i < adj[x].size()) {
            res.push_back(adj[x][i]);
            i++;
            continue;
        } 
        if(j < adj[y].size()) {
            res.push_back(adj[y][j]);
            j++;
            continue;
        } 
    }

    swap(res, adj[y]);
    f[x] = y;
}


void solve()
{
    int n, q;
    cin >> n >> q;
    
    for(int i = 1; i <= n; i ++) adj[i].push_back(i), f[i] = i;
    for(int i = 1; i <= q; i ++) {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1) {
            merge(x, y);
        } else {
            x = find(x);
            if(y > adj[x].size()) {
                cout << "-1" << endl;
            } else {
                
                sort(adj[x].begin(), adj[x].end(),[&](int a, int b){
                    return a > b;
                });
                
                cout << adj[x][y - 1] << endl;
            }
        }
    } 







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