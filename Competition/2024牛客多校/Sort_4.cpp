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

//vector<vector<int>>edg(N);
int n,m;
int a[N], f[N], num[N];

int find(int x) {
    if(x != f[x]) f[x] = find(f[x]);
    return f[x];
}


void merge(int a,int b) {
    a = find(a), b = find(b);
    if(a == b) return;
    num[a] += num[b];
    f[b] = a;
}

void solve()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        f[i] = i;
        num[i] = 1;
    }

    for(int i = 1; i <= n; i ++) {
        merge(i, a[i]);
    }
    int ans = 0;
    int cnt = 0;

    for(int i = 1; i <= n; i ++) {
        if(find(i) == i) {
            ans += num[i] / 3;
            num[i] %= 3;
            if(num[i] == 2) cnt ++;
        }
    }
    cout << ans + (cnt + 1) / 2<< endl;
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