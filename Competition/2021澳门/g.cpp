#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 1e18;
const ll INFll  = 1e18;
#define endl "\n" 

int p[N];
int dp[N][2];
int lxt[N],rxt[N];
int a[N];
int n, k;

int lowbit(int x) {
    return x & (-x);
}
int tr[N];
void updata(int x) {
    while(x <= n) {
        tr[x] = a[x];
        for(int i = 1; i < lowbit(x); i <<= 1) 
            tr[x] = min(tr[x], tr[x - i]);
        x += lowbit(x);
    }
}

// void updata(int x)
// {
// 	int lx, i;
// 	while (x <= n)
// 	{
// 		tr[x] = a[x];
// 		lx = lowbit(x);
// 		for (i=1; i<lx; i<<=1)
// 			tr[x] = max(tr[x], tr[x-i]);
// 		x += lowbit(x);
// 	}		
// }


// int query(int L, int R) {
//     if(L > R) return INF;
//     int ans = INF;
//     while(L <= R) {
//         ans = min(ans,a[R]);
//         R--;
//         while(R - L >= lowbit(R)) {
//             ans = min(ans,tr[R]);
//             R -= lowbit(R);
//         }
      
//     }
//     return ans;
// }

int query(int x, int y)
{
	int ans = INF;
	while (y >= x)
	{
		ans = min(a[y], ans);
		y --;
		for (; y-lowbit(y) >= x; y -= lowbit(y))
			ans = min(tr[y], ans);
	}
	return ans;
}


int query_not(int l, int r) {
    if(l < 1) l += n;
    if(r > n) r -= n;
    // cout << l << " " << r << endl;
	if (l <= r)
	{
		int res = INF;
		if (l != 1) res = query(1, l - 1);
		if (r != n) res = min(query(r + 1, n), res);
        // if(l == 7)
        // cout << r << " "<< query(1,l - 1) << query(r + 1, n) << endl;
		return res;
	}
    else {
        return query(r + 1, l - 1);
    }
}


int js(int p1, int p2)
{
	if (p1 < 1) p1 += n;
	if (p1 > n) p1 -= n;
	return min(n - p2 + p1, min(abs(p1 - p2), p2 + n - p1));
}


void solve()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i ++) cin >> a[i], p[a[i]] = i;
    if(n == k) {
        cout << "0\n";
        return;
    }

    // for(int i = 1; i <= n; i ++) {
    //     tr[i] = a[i];
    //     for(int j = 1; j < lowbit(i); j <<= 1) {
    //         tr[i] = tr[i] > tr[i - j] ? tr[i] : tr[i - j];
    //     }
    // }

    for(int i = 1; i <= n; i ++) {
        updata(i);
    }
    // a[9] = INF;
    // update(9, INF);
    // cout << query(9, 11) << endl;
    // cout << query(4,n);
    // cout << query_not(3,3) << endl;
    
   
  
    int t = query_not(1, k);
    // cout << t << endl;
    for(int i = 1; i <= n; i ++ ) {
        dp[i][0] = dp[i][1] = INF;
        a[p[i]] = INF;
        // for(int i = 1; i <= n; i ++) updata(i);
        updata(p[i]);
        if(i >= t) {
            lxt[i] = query_not(p[i], p[i] + k - 1);
            rxt[i] = query_not(p[i] - k + 1,p[i]);
        }

        // if(i == 5) {
        //     cout << p[i] << endl;
        //     cout << query_not(7, 7) << endl;
        //     cout << query(8, 10) << endl;
        // }
        // cout << i << " "  << p[i] << endl;
        //  for(int i = 1; i <= n; i ++) cout << query(i,i) << " \n"[i == n];
        // cout << query(1, p[i]) << " " << query(7, 11) << endl;
        // cout << i << " " << lxt[i] << " " << rxt[i] << endl;

    }

    dp[t][0] = min(p[t] - 1,n - (p[t] - 1));
    dp[t][1] = min(p[t] - k,n - (p[t] - k));

    int ans = INF;
    for(int i = t; i <= n; i ++) {
        int u = lxt[i];
        if(u == INF) ans = min(ans, dp[i][0]);
        else {
			dp[u][0] = min(dp[u][0], dp[i][0] + js(p[i], p[u]));
			dp[u][1] = min(dp[u][1], dp[i][0] + js(p[i] + k - 1, p[u]));
        }

        u = rxt[i];
        if(u == INF) ans = min(ans, dp[i][1]);
        else {
            dp[u][0] = min(dp[u][0], dp[i][1] + js(p[i] - k + 1, p[u]));
            dp[u][1] = min(dp[u][1], dp[i][1] + js(p[i],p[u]));
        }
    }
    cout << ans  << endl;
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