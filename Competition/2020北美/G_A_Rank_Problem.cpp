#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];


void solve()
{
    int n, m;cin >> n >> m;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    while (m--) {
        char c;
        int x, y; cin >> c >> x >> c >> y;
        int id1, id2;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) id1 = i;
            if (a[i] == y) id2 = i;
        }
        if (id1 < id2) continue;
        
        a.insert(a.begin() + id1 + 1, y);
        a.erase(a.begin() + id2);

    }
    for (int i = 0; i < n; i++) {
        cout << "T" << a[i] << ' ';
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