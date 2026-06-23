#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);



void solve()
{
    int n, k, q; cin >> n >> k >> q;
    vector<int> a(n + 1, 0);
    vector<int> ans(n + 1, 0);
    map<int,int> cnt,ccnt;

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] -= i;
    }
    // for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];

    int l = 1, r = k;
    for(int i = l; i <= r; i ++) {
        if(ccnt.count(cnt[a[i]])) ccnt[cnt[a[i]]] --;
        cnt[a[i]]++;
        ccnt[cnt[a[i]]] ++;
    }

    // for(auto[x, t] : ccnt) {
    //     cout << x << " " << t << endl;
    // }

    while(r <= n) {
        ans[l] = ccnt.rbegin()->first;
        // cout << ans[l] << " ";


        ccnt[cnt[a[l]]]--;
        if(ccnt[cnt[a[l]]] == 0) ccnt.erase(cnt[a[l]]);
        cnt[a[l]] --;
        ccnt[cnt[a[l]]]++;
        
        l ++;
        r ++;

        ccnt[cnt[a[r]]]--;
        cnt[a[r]] ++;
        ccnt[cnt[a[r]]]++;
        
    }

    while(q--){
        int l, r; cin >> l >> r;
        cout << k - ans[l] << endl;
    }
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