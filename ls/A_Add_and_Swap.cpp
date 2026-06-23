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

int a[N];

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    bool ky = true;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        for(int j = i; j >= 2 && ky; j --) {
            if(a[j] + k <= a[j - 1]) {
                ans.push_back(j - 1);
                a[j] += k; 
                swap(a[j - 1], a[j]); 
            } else if(a[j - 1] <= a[j]) {
                break;
            } 
        }
    }
    if(n == 2 && a[1] > a[2]) {
        cout << "No\n";
        return;
    }

    for(int i = 1; i <= n; i ++)





    cout << "Yes\n";
    cout << ans.size() << endl;
    for(auto t : ans) cout << t << " "; cout << endl;

   



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