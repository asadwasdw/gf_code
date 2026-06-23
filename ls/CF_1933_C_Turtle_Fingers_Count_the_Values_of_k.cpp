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
    int a, b, l;
    cin >> a >> b >> l;
    set<int> s;
    for(int x = 0; pow(a, x) <= l; x ++ ) {
        for(int y = 0; pow(a, x) * pow(b, y) <= l; y ++) {
            int t = (int)(pow(a, x) * pow(b, y));
            if(l % t == 0) {
                s.insert(l / t);
            }
        }
    }

    cout << s.size() << endl;







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
    return 0;
}