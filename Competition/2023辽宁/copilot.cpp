#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e7+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
typedef int ull;
ull h[N],p[N];
const ull P = 13331;

ull get(int l, int r) {
    if(l > r) return 0;
    return h[r] - h[l - 1] * p[r - l + 1];
}

bool check(int a, int b) {
    if(a * 2 < b) {
        return get(a + 1, b) == get(1, a)*P + get(1,1);
    }
    return get(a + 1, b) == get(1, b - a);
}

void solve()
{
    string s; cin >> s;
    int n = s.size();
    s = " " + s; 
    p[0] = 1;
    for(int i = 1; i <= n; i ++) {
        h[i] = h[i - 1] * P + s[i] - 'a' + 1;
        p[i] = p[i - 1] * P;
    }
    int ans = 0;
    int j = 1;
    // cout << check(1, 3) << endl;
    // cout << get(5, 8) << " " << get(1, 4) << endl;
    for(int i = 1; i <= n; i ++) {
        while((j < (i)/2 || !check(j, i)) && j <= i) j ++;
        ans ^= (j);
        // cout << i << " " << j << endl;
    }
    cout << ans << endl;







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