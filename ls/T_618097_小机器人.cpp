#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 
//vector<vector<int>>adj(N);

PII a[N];
PII b[N];
PII c[N];
int s[N];


void gb(int n, int m) {
    int i = 0, j = 1, k = 1;
    while(j <= n && k <= m) {
        if(b[j].first < c[k].first) {
            a[++ i] = b[j ++];
        } else if(b[j].first > c[k].first) {
            a[++ i] = c[k ++];
        } else {
            if(b[j].second < c[k].second) {
                a[++ i] = b[j ++];
            } else {
                a[++ i] = c[k ++];
            }
        }
    }

    while(j <= n) {
        a[++ i] = b[j ++];
    }

    while(k <= m) {
        a[++ i] = c[k ++];
    }
}




void solve()
{
    int n, m;
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    cin >> m;

    sort(a + 1, a + n + 1, [&](PII a, PII b){
        if(a.first != b.first) return a.first < b.first;
        return a.second  < b.second;
    });

    // for(int i = 1; i <= n; i ++) {
    //     cout << a[i].first << " " << a[i].second << endl; 
    // } cout << endl;


    for(int i = 1; i <= m; i ++) {
        int l, r;
        ll k;
        cin >> l >> r >> k;

        int bn = 0, cn = 0;
        
        for(int j = 1; j <= n; j ++) {
            if(l <= a[j].second && a[j].second <= r) {
                b[++bn] = a[j];
                s[bn] = s[bn - 1] + b[bn].first;
            } else {
                c[++cn] = a[j];
            }
        }
        // b是区间内，c是区间外
        
        ll mx = 0, mxj = 0;
        for(int j = 1; j <= bn; j ++) {
            if(k < j * b[j].first - s[j]) break;
            mx = b[j].first, mxj = j;
        } // 找下可以将最大前缀[1,mxj] 全部改成同一个数mx

        // cout << mx << " - " << mxj << endl;

        for(int j = 1; j <= mxj; j ++) {
            ll t = mx - b[j].first;
            k -= t;
            b[j].first = mx;
        } // 先改成一样的， k也要减小，可能用不完

   
        sort(b + 1, b + mxj + 1, [&](PII a, PII b){
            if(a.first != b.first) return a.first < b.first;
            return a.second  < b.second;
        }); // 排一下，因为现在值都相同, 其实是按下标排


        for(int j = 1; j <= mxj && k > 0; j ++) {
            ll t = (k) / (mxj) + (j <= k % mxj ? 1 : 0);
            b[j].first += t;
        }// 把余下的操作次数给补上

        gb(bn, cn);
    }


    sort(a + 1, a + n + 1, [&](PII a, PII b){
        return a.second  < b.second;
    });

    for(int i = 1; i <= n; i ++) {
        cout << a[i].first << " \n"[i == n]; 
    }
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