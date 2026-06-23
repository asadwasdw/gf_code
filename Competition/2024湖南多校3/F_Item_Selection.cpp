#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n,m,s,p,q;
int b[N],c[N];

int jsb(int pag) {
    int l = (pag-1)*m + 1;
    int r = pag*m;
    r=min(n,r);
    return b[r] - b[l-1];
}

int jsc(int pag) {
    int l = (pag-1)*m + 1;
    int r = pag*m;
    r=min(n,r);
    return c[r] - c[l-1];
}

int jsw(int pag){

    int ans = INF;
    ans = min(ans, jsc(pag));
    ans = min(ans, 1 + jsb(pag));
  
    int l = (pag-1)*m + 1;
    int r = pag*m;
    r=min(n,r);
    int sum = r-l+1;

    ans = min(ans, 1 + (sum - jsb(pag)));

    return ans;
}

int w[N];

void solve()
{
    cin >> n >> m >> s >> p >> q;
    for(int i = 1; i <= p; i ++ ){
        int x; cin >> x;
        c[x] ++;
    }

    for(int i = 1; i <= q; i ++ ){
        int x; cin >> x;
        b[x] ++;
        c[x] --;
    }

    for(int i = 1; i <= n; i ++) {
        b[i] += b[i-1];
        c[i] = abs(c[i]) + abs(c[i-1]);
    }
    int l = 0, r = 0;
    int W = 0;
    for(int i=1;i<=(n+m-1)/m;i++){
       
        w[i] = jsw(i);
        // cout << i << ' ' << w[i] << endl;
        if(w[i]) {
            if(l == 0) l = i;
            r = i;
        }
        W += w[i];
    }

    if(W == 0) {
        l = s;
        r = s;

    }
    // cout << l << " " << r <<" "<<W<< endl;

    int ans = min(abs(s - l) + (r-l) , abs(r - s) + (r-l)) + W;
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
}