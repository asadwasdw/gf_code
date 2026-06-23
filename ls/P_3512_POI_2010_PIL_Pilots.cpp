#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N];

void solve()
{
    int k, n;
    cin >> k >> n;
    
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    deque<int> d1, d2;
    int l = 1;
    int ans = 0;
    for(int r = 1; r <= n; r ++) {
        while(d1.size() && a[d1.back()] <= a[r]) {
            d1.pop_back();
        }
        d1.push_back(r);

        while(d2.size() && a[d2.back()] >= a[r]) {
            d2.pop_back();
        }
        d2.push_back(r);

        if(d1.size() && d2.size() && k < a[d1.front()] - a[d2.front()]  ) {
            l ++;
            if(d1.front() < l) d1.pop_front();
            if(d2.front() < l) d2.pop_front();   
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans;
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