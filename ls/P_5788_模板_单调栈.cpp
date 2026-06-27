#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N], b[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    stack<int> s;
    for(int i = n; i >= 1; i --) {
        while(s.size() && a[i] >= a[s.top()]) {
            s.pop();
        }
        if(s.size()) b[i] = s.top();
        s.push(i);
    }

    for(int i = 1; i <= n; i ++) cout << b[i] << " ";






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