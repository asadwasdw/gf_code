#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
int a[N];

void solve()
{
    map<int,int> cnt;
    int n; cin >> n;
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i = 1; i <= n; i ++) {
        int x; cin >> x;
        a[i] = x;
        q.push(x);
    }

    while(q.size()) {
        while(cnt[q.top()]) {
            int x = q.top(); q.pop();
            x ++;
            q.push(x);
        }
        int x = q.top();q.pop();
        if(x != q.top()) {
            break;
        } else {
            cnt[x]++;
            q.pop();
        }
    }
    // cout << q.size() << endl;
    if(!q.size()) cout << "Yes\n";
    else cout << "No\n";









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