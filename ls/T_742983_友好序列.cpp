#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e5+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
#define x first
#define y second

//vector<vector<int>>adj(N);

int a[N], b[N];
int la[N][20], lb[N][20];
int n;
int lg2[N];

void init() {
    memset(la, -0x3f, sizeof la);
    memset(lb, 0x3f, sizeof lb);
    // for(int i = 1; i <= n; i ++) {
    //     cout << i << " " <<  log2(i) << endl;
    // }
    for(int i = 2; i <= n; i ++) {
        lg2[i] = lg2[i >> 1] + 1;
        // cout << lg2[i] << " " << (int)log2(i) << endl;
    }

    for(int i = 1; i <= n; i ++) la[i][0] = a[i];
    for(int i = 1; i <= n; i ++) lb[i][0] = b[i];

    for(int j = 1; j < 20; j ++) {
        for(int i = 1; i <= n; i ++){
            la[i][j] = max(la[i][j - 1], la[min(n, i + (1 << (j - 1)))][j - 1]);
            lb[i][j] = min(lb[i][j - 1], lb[min(n, i + (1 << (j - 1)))][j - 1]);
        }
    }
}


int query_max(int l, int r) {
    int len = lg2[abs(r - l + 1)];
    return max(la[l][len], la[r - (1 << len) + 1][len]);
}


int query_min(int l, int r) {
    int len = lg2[abs(r - l + 1)];
    return min(lb[l][len], lb[r - (1 << len) + 1][len]);
}

int ans = 0;
void calc(int mid) {
    // int l = mid, r = mid;
    // for(int j = 20; j >= 0; j --) {
    //     int nl = l - (1 << j) + 1;
    //     if(nl < 1) continue;
    //     if(query_max(nl, mid) == a[mid])  l = nl;
    // }

    // for(int j = 20; j >= 0; j --) {
    //     int nr = r + (1 << j) - 1;
    //     if(nr > n) continue;
    //     if(query_min(mid, nr) == b[mid]) r = nr; 
    // }
    // // cout << mid << " " << l << " " << r << endl;
    // ans += (r - mid + 1) * (mid - l + 1);

    int r1 = mid, r2 = mid;

    for(int j = 20; j >= 0; j --) {
        int nr1 = r1 + (1 << j);
        int nr2 = r2 + (1 << j);
        if(nr1 <= n && query_max(mid, nr1) == a[mid]) r1 = nr1;
        if(nr2 <= n && query_min(mid, nr2) == b[mid]) r2 = nr2;
    }

    // cout << mid << " " << r1 << " " << r2 << endl;
    ans += min(r1, r2) - mid + 1;
}

void calc2(int l) {
    int r1 = l, r2 = l; // 最后一个 min(l, r1) > max(l, r1) 的位置， r2 取等号

    for(int j = 20; j >= 0; j --) {
        int nr1 = r1 + (1 << j);
        int nr2 = r2 + (1 << j);
        if(nr1 <= n && query_min(l, nr1) > query_max(l, nr1) ) r1 = nr1;
        if(nr2 <= n && query_min(l, nr2) >=query_max(l, nr2)) r2 = nr2;
    }
    ans += r2 - r1;
    if(a[l] == b[l]) ans++;
    // cout << l << " " << r1 << " " << r2 << endl;
}

void solve()
{

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int j = 1; j <= n; j ++) cin >> b[j];

    init();

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 0; j <= 3; j ++) {
    //         cout << la[i][j] << " \n"[j == 3];
    //     }
    // }

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = i; j <= n; j ++) {
    //         cout << i << " " << j << " " << query_min(i, j) << endl;
    //     }
    // }

    // for(int i = 1; i <= n; i ++) {
    //     if(a[i] == b[i]) {
    //         calc(i);
    //     }
    // }

    for(int i = 1; i <= n; i ++) {
        calc2(i);
    }
    cout << ans << endl;
}

void solve2() {
     cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int j = 1; j <= n; j ++) cin >> b[j];

    init();

    for(int l = 1; l <= n; l ++) {
        for(int r = l; r <= n; r ++) {
            if(query_max(l, r) == query_min(l, r)) ans ++;
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
    return 0;
}