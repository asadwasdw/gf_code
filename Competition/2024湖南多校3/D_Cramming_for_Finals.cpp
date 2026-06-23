#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e7+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;


inline ll Read(){
	char ch=getchar();bool f=0;ll x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
//vector<vector<int>>edg(N);

struct Node{
    int x,y;
}node[N];

struct Q{
    ll x;
    int t;
}q[N];

int cnt = 0;

// bool cmp(Q &a, Q &b){
//     if(a.x != b.x) return a.x < b.x;
//     return a.t < b.t;
// }

map<ll,bool>mp;

bool operator < (Q a,Q b){
	if(a.x!=b.x) return a.x<b.x;
	return a.t<a.t;  
}

void solve()
{
    int R,C,d,n;
    // cin >> R >> C >> d >> n;
    R=Read(),C=Read(),d=Read(),n=Read();
    for(int i = 1; i <= n; i ++) {
        // cin >> node[i].x >> node[i].y;
        node[i].x = Read();
        node[i].y = Read();
    }

    for(int i = 1; i <= n; i ++) {
        auto [x,y] = node[i];
        int l = max(1ll, y - d);
        int r = min(C, y + d);

        mp[(y-1)*R+x] = true;
        // cout << i << ' ' << l << ' ' << r << endl;

        for(int j = l; j <= r ;j ++) {
            int d2 = sqrt(d*d - (y-j)*(y-j));
            int up = max(1ll, x - d2);
            int down = min(R, x + d2);
            q[++cnt] = {1ll*(j-1)* R + up,1};
            q[++cnt] = {1ll*(j-1)* R + down + 1,-1};

        }
    }
    q[cnt+1]={R*C+1,0LL};
    sort(q+1,q+cnt+1);
    int ans = n;
    int now = 0;
    for(int i = 1; i <= cnt; i ++) {
        // cout << q[i].x << ' ' << q[i].t << endl;
        auto [x,t] = q[i];
        now += t;
        if(x != q[i+1].x) {
            if(mp[x] == false) ans = min(now,ans);
        }
    }
    cout << ans << '\n';
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
}