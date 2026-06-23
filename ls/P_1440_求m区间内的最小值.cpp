#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
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
    int n, m;
    cin >> n >> m;
    deque <int> q;
    
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    cout << "0" << endl;
    for(int i = 1; i < n; i ++) {
        while(q.size() && (a[q.back()] >= a[i])) {
            q.pop_back();
        }
        q.push_back(i);

        if(q.size() && q.front() <= i - m) q.pop_front();

        cout << a[q.front()] << endl;
    }
}

void solve2() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    priority_queue<PII, vector<PII>, greater<PII>> q; 
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    q.push({0, 0});
    for(int r = 1, l = 1; r <= n; r ++) {
        l = max(l, r - m);
        while(q.size() && q.top().second < l) {
            q.pop();
        }
        cout << q.top().first << endl;
        q.push({a[r], r});
    }
}

void solve3() {
    int n, m;
    cin >> n >> m;
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