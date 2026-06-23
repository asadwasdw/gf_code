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

map<int,int> mp;

int sg(int x) {
    if(x == 0) return 0;
    if(mp[x]) return mp[x];
    if(x % 2 == 0) return 0;

    map<int,int> s;
    int ans = 0;


    for(int i = 1; i <= x; i ++) {
        if(__gcd(i, x) == 1) s[sg(x - i)] ++;
    }

    while(s[ans])ans++;
    return mp[x] = ans;
}

void solve()
{

    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        ans ^= sg(x);
    }
    if(ans) cout << "Alice" ;
    else cout << "Bob";
    cout << endl;
}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    cin>>t;



        
    for(int i = 1; i <= 100; i += 2) {
        cout << i << " " <<  sg(i) << endl;
    }

    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}