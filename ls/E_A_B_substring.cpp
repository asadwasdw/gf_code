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

int tr[N];
int n;

int lowbit(int x) {
    return x&-x;
}

void add(int x) {
    for(int i=x;i<N;i+=lowbit(i))tr[i]+=1;
}

int get(int x) {
    int res=0;
    for(int i=x;i;i-=lowbit(i))res+=tr[i];
    return res;
}



void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    int sum = 0;
    int T = 1e6;

    add(0 + T);

    ll ans = 0;
    for(int i = 1; i <= n; i ++) {
        int x;
        if(s[i] == 'A') x = 1;
        if(s[i] == 'B') x = -1;
        if(s[i] == 'C') x = 0;
        sum += x;

        ll cnt = get(sum - 1 + T);
        // cout << cnt << endl;
        ans += cnt;

        add(sum + T);
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
        solve();
    }
    return 0;
}