#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f; 

//vector<vector<int>>edg(N);
int a[1010][1010];
int n, k;
void ask(int i, int j, int k) {
    // printf("? %d %d %d", i, j, k);
    cout << "? " << i << " " << j << " " << k << endl;
    // cout << endl;
}

int ans() {
    int x; cin >> x;
    return x;
}
int ans2(int i,int j ,int mid) {
    ask(i,j,mid);
    return ans();
    // return a[i][j] <= mid;
}

bool check(int x) {
    int num = 0;
    int l = 0, r = n;
    for(int i = 1; i <= n; i ++) {
        l = 0;
        while(r && !ans2(i,r,x))r --;
        // while(l < r) {
        //     int mid = (l + r + 1) >> 1;
        //     if(ans2(i,mid, x)) l = mid;
        //     else r = mid - 1;
        // }
        num += r;
        // cout << l << endl;
    }
    // cout << num << endl;
    return num >= n * n - k + 1;
}

void solve()
{
  
    cin >> n >> k;

    // for(int i = 1; i <= n; i ++) {
    //     for(int j = 1; j <= n; j ++) {
    //         cin >> a[i][j];
    //     }
    // }
    // check(5);

    int l = 1, r = n * n;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
        // cout << l << " " << r << endl;
    }
    cout  << "! " << l << endl;
}


signed main()
{
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}