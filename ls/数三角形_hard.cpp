#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=3e3+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N*2);

int tr[N];
void add(int k,int x) {
    for(int i=k;i<N;i+=i&-i)tr[i]+=x;
}

int sum(int k) {
    if(k<=0)return 0;
    int res = 0;
    for(int i = k; i; i -= i&-i) res += tr[i];
    return res;
}

int query(int l,int r) {
    return sum(r) - sum(l-1);
}
char c[N][N];
int n,m;

int d1[N][N];
int d2[N][N];

int js(int row,int l,int r){
    for(int i = 0; i < N; i++) tr[i] = 0;
    int ans = 0;
    {
        int mx = 0;
        int i = l;
        for(; i <= r;i += 2) {
            int L = i, R = i + d1[row][i] * 2 - 2;
            edg[R].push_back(L);
            mx = max(R,mx);
            R = i;
            L = i - (d2[row][i] - 1) * 2;
            ans += query(L,R); 
            add(i,1);
            for(auto t:edg[i]) {
                add(t,-1);
            }
            edg[i].clear();
        }
        for(;i <= mx; i+=2) {
            for(auto t:edg[i])add(t,-1);
            edg[i].clear();
        }
    }

    {
        int mx = 0;
        int i = l + 1;
        for(; i <= r;i += 2) {
            int L = i, R = i + d1[row][i] * 2 - 2;
            edg[R].push_back(L);
            mx = max(R,mx);
            R = i;
            L = i - (d2[row][i] - 1) * 2;
            ans += query(L,R); 
            add(i,1);
            for(auto t:edg[i]) {
                add(t,-1);
            }
            edg[i].clear();
        }
        for(;i <= mx; i+=2) {
            for(auto t:edg[i])add(t,-1);
            edg[i].clear();
        }
    }
    // cout << row <<" " << l << " " << r <<" "<<ans<<endl;
    return ans;
}




void solve()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin>>c[i][j];
            if(c[i][j] == '*') {
                d1[i][j] = d1[i-1][j+1] + 1;
                d2[i][j] = d2[i-1][j-1] + 1;
            }
        }
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++)cout <<d2[i][j]<<" ";cout<<endl;
    // }
    int ans = 0;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(c[i][j]=='.')continue;
            int len = 1;
            while(c[i][j+len]=='*')len++;
            ans += js(i,j,j+len-1);
            j=j+len-1;
        }
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
}