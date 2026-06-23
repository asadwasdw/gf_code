#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);

int a[2][N][4];
int n, m, k;

bool check(int i, int mid) {
    i -- ;
    int N = a[i%2][i + mid * 2][0] - a[i%2][max(0,i)][0];
    int M = a[i%2][i + mid * 2][1] - a[i%2][max(0,i)][1];
    int K = a[i%2][i + mid * 2][2] - a[i%2][max(0,i)][2];

    // cout << i + mid * 2 << " ";
    // cout << i - 2 << " " << i + mid * 2 << endl; 
    // cout << N << " " << M << " " << K << endl;
    
    if(N > n) return false;
    if(M > m) return false;
    if(K > k) return false;
    
    return true;
}

void solve()
{

    cin >> n >> m >> k;
    string s;
    cin >> s;
    int num = s.size() * 2;
    s = " " + s + s;


    for(int i = 2; i <= num; i ++) {
        int t = s[i - 1] + s[i] -'0'-'0';
        a[i%2][i][0] = a[i%2][i - 2][0];
        a[i%2][i][1] = a[i%2][i - 2][1];
        a[i%2][i][2] = a[i%2][i - 2][2];

        a[i%2][i][t] ++;

        // cout  << i << " " << a[i%2][i][0] << " " << a[i%2][i][1] << " " << a[i%2][i][2] << "\n";
    }

    int ans = 0;
    // cout << s << endl;

    // cout << check(2, 1) << endl;

    for(int i = 1; i <= num; i ++) {
        int len = min(num/4,(num - i) / 2);
        int l = 0, r = len;
        while(l < r) {
            int mid = (r + l + 1) >> 1;
            if(check(i,mid)) l = mid;
            else r = mid - 1;
        }
        // cout << i << " " << l * 2 << endl;
        ans = max(ans, l * 2);
    }
    cout << ans;
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