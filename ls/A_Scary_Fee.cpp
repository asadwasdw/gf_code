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


void solve()
{
    int n;
    cin >> n;
    map<int,int> mp;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        mp[x] ++;
        if(mp[x] == 2) {
            mp[x] -= 2;
            ans ++;
        }
    }
    cout << ans << endl;
}

int a[N];

void solve2() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ans = 0;

    for(int i = 1; i <= n; i ++) {
        if(a[i] == -1) continue;
        for(int j = i + 1; j <= n; j ++) {
            if(a[i] == a[j]) {
                ans ++;
                a[j] = -1;
                break;
            }
        }
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
        solve2();
    }
}