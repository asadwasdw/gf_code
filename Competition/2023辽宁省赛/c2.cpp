#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>adj(N);
typedef array<int,3> PIII;

void solve()
{
    // cout << 4000 * 250000 << endl;
    int n; cin >> n;
    vector<PIII> a(n + 1); 
    vector<PIII> q1(n + 1),q2(n + 1); 
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
        q1[i] = q2[i] = a[i];
    }

    sort(q1.begin() + 1, q1.end(),[&](PIII a, PIII b){ // 血多的在前面
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });

    sort(q2.begin() + 1, q2.end(),[&](PIII a, PIII b){ // 伤害多的在前面
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] > b[1];
    });

    int pre = 0;
    int ans = INF;
    vector<bool> st(n + 1);
    for(int i = 0; i <= n; i ++) {
        pre += q1[i][1];
        st[q1[i][2]] = true;
        vector<bool> st2 = st;
        int q1i = n, q2i = 1;

        int sum = pre;
        int res = i;

        while(1) {
            bool ky = false;

            while(q1i > i && (sum >= q1[q1i][0] || st2[q1[q1i][2]])) {
                if(!st2[q1[q1i][2]]) {
                    sum += q1[q1i][1];
                    st2[q1[q1i][2]] = true;
                    ky = true;
                }
                q1i --;
            }
            // cout << q1i << endl;

            while(q2i <= n && (sum >= q2[q2i][0] || st2[q2[q2i][2]])) {
                if(!st2[q2[q2i][2]]) {
                    sum += q2[q2i][1];
                    st2[q2[q2i][2]] = true;
                    ky = true;
                }
                q2i++;
            }



            if(!ky) {
                if(q2i <= n) {
                    res ++;
                    sum += q2[q2i][1];
                    st2[q2[q2i][2]] = true;
                    ky = true;
                }
                else {
                    break;
                }
            }
        }
        ans = min(ans, res);
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