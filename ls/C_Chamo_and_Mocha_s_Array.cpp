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
int b[N];

bool check(int mid) {
    for(int i = 1; i <= n; i ++) {
        if(a[i] >= mid) b[i] = 1;
        else b[i] = 0;
        b[i] += b[i - 1];
    }
    // cout << mid << endl;
    // for(int i = 1; i <= n; i ++) cout << b[i] << " \n"[i == n];

    for(int i = 2 ; i <= n; i ++) {
        if(b[i] - b[i - 2] > 1) return true;
        if(i >= 3 && b[i] - b[i - 3] >= 2) return true;
        if(i >= 5 && b[i] - b[i - 5] >= 3) return true;
        if(i >= 7 && b[i] - b[i - 7] >= 4) return true;
        if(i >= 9 && b[i] - b[i - 9] >= 5) return true;
        if(i >= 11 && b[i] - b[i - 11] >= 6) return true;
    }
    return false;
}

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ans = 0;

    int l = 0, r = 1e9; 
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        // cout << check(mid) << " " << mid << endl;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
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
}