#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

vector<vector<int>>adj(N);


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 10);
    vector<int> q(n + 10, 0);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        adj[a[i]].push_back(i);
    }
    vector<PII> qj;
    int m = 0;
    for(int i = 1; i <= n; i ++) {
        if(adj[i].size()) {
            m ++ ;
            qj.push_back({adj[i][0], adj[i][adj[i].size() - 1]});
        }
    }
    sort(qj.begin(), qj.end());
    // for(auto [l, r] : qj) cout << l << " " << r << endl;

    int L = 1, R = 1;
   
   {
        vector<PII> ans;
        for(auto [l, r] : qj) {
            if(l <= R) {
                R = max(R, r);
            } else {
                if(R >= L)
                    sort(a.begin() + L, a.begin() + R + 1, [&](int a, int b){
                        return a > b;
                    });
                L = l, R = r;
            }
        }

        sort(a.begin() + L, a.begin() + R + 1, [&](int a, int b){
            return a > b;
        });
   }


    // for(int i = 1; i <= n; i ++) cout << a[i] << " \n"[i == n];
    q[0]=-1e9;
   
    int ans=0;
    for(int i=1;i<=n;i++){

        int t=lower_bound(q.begin()+1,q.begin()+ans+1,a[i])-(q.begin())-1;
        //cout<<t<<endl;
        q[t+1]=a[i];
        ans=max(t+1,ans);

       // for(int i=1;i<=ans;i++)cout<<q[i]<<" ";cout<<endl;
    }
    
    cout<<m - ans<<endl;






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