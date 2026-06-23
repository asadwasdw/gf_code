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


void solve()
{
    int n, q;
    cin >> n >> q;
    map<PII,int> s;
    map<int, map<int,int>> s2;
    while(q--) {
        int op, i, j, k;
        cin >> op >> i >> j;
        if(op == 1) {
            cin >> k;
            s[{i, j}] = k;
            s2[i][j] = k;
            s[make_pair(i,j)]=k;
        } else {
            // cout << s[{i, j}] << endl;
            cout << s2[i][j] << endl;
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
    return 0;
}