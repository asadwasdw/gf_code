#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int M = 22;
const int N = 2e5+10, maxn = (1ll<<M) + 10;

const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;


int g[M][N];//完成第i个任务，左边是j,右边最小是多少
int f[maxn];//完成t状态任务，右边最小是多少
int p[maxn];//记录t状态最优的上一个状态和t的差异
struct node{
    int x,id;
}a[N];

bool cmp(node a,node b) {
    return a.x > b.x;
}

int b[N];

void solve()
{
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++) cin>>a[i].x, a[i].id = i;

    sort(a+1, a+n+1, cmp);
    memset(g,0x3f,sizeof g);
    for(int i = 1; i <= m; i++ ){
        cin>>b[i];

        for(int j = 1, k = 1; j <= n; j++) {
            k = max(k, j);

            while(k <= n && a[k].x * (k - j + 1) < b[i]) {
                k ++;
            }

            g[i][j] = k;
        }
    }

    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for(int i = 0; i < (1<<m); i++) {
        if(f[i] > n) continue;
        for(int j = 1; j <= m; j++) {
            if(i & (1<<(j-1))) continue;

            int T = (i | (1<<(j-1)));
            if(f[T] > g[j][f[i] + 1]) {
                f[T] = g[j][f[i] + 1];
                p[T] = j;
            }
        }
    }


    if(f[(1<<m) - 1] > n) { cout<<"NO\n"; return ;}
    cout<<"YES\n";

    int T = (1<<m) - 1;

    vector<int>ans[25];

    while(T){
        int S = T ^ (1 << (p[T] - 1));
        //cout<<T<<endl;
        for(int i = f[S] + 1; i <= f[T]; i ++) {
            ans[p[T]].push_back(a[i].id);
        }
        T = S;
    }

    for(int i = 1; i <= m; i++) {
        cout<<ans[i].size()<<" ";
        for(auto t:ans[i])cout<<t<<" ";
        cout<<endl;
    }


}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}