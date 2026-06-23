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

string s[N];

void solve()
{
    s[0] = "0";
    s[1] = "1";

    int n; 
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        int l, r, x;
        cin >> l >> r >> x;
        s[i + 1] = s[l] + s[r];
        cout << s[i + 1][x - 1] << endl;
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