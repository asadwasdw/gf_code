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


void solve()
{
    int n, k, t;
    cin >> n >> k >> t;

    vector<int> a(n), A(k);

    for(int i = 0; i < n; i ++) a[i] = i;
    for(int i = 0; i < k; i ++) cin >> A[i];

    while(t --) {
        vector<int> v;
        for(auto x : A) {
            v.push_back(a[x]);
        }

        for(int i = 0; i < k; i ++) a[A[(i + 1) % k]] = v[i]; // 每个都向后移动

        for(int i = 0; i < k; i ++)  A[i] = (A[i] + 1) % n; // 每个都 + 1
    }
    for(auto x : a) cout << x << " "; cout << endl;
}

void solve2() {
    int n, k, t;
    cin >> n >> k >> t;
    vector<int> a, A, b(n);
    for(int i = 0; i < n; i ++) a.push_back(i);
    
    for(int i = 0; i < k; i ++) {
        int x; cin >> x;
        A.push_back(x);
    }

    A.push_back(A[0] + n);
    int l = A[0], r = A[1], id = 1;

    for(int i = A[0]; i < A[0] + n; i ++) {
        if(i == r) l = r, r = A[++id];
        int j = i % n;
        int len = r - l;
        int cnt = t / len;
        int now = j + len * cnt;
        if(i - l < t % len) {
            now += len;
        }

        now %= n;
        b[now] = a[j];
    }

    for(int i = 0; i < n; i ++) cout << b[i] << " ";
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