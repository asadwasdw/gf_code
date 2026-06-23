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
int a[N];

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    stack<PII> sta;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    sta.push({INF, n + 1});

    for(int i = n; i >= 1; i --) {
        while(sta.size() && a[i] > sta.top().first) {
            sta.pop();
        }
        sum += sta.top().second - (i + 1);
        // cout << i << " " << sta.top().second - (i + 1) << endl;
        sta.push({a[i], i});
    }

    cout << sum << endl;
}

void solve2() {
    int n;
    cin >> n;

    ll sum = 0;
    stack<int> sta;
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        while(sta.size() && sta.top() <= x) sta.pop();
        sum += sta.size();
        sta.push(x);
    }
    cout << sum << endl;
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
    return 0;
}