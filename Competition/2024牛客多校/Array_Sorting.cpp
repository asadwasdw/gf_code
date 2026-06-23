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


void solve()
{
    int n;
    cin >> n;


    if(n == 1) {
        cout << "0";
        return;
    }
    // int m = n / 2;
    // n %= 2;
    auto isp = [&](int x) -> bool {
        for(int i = 2; i <= sqrt(x); i ++) {
            if(x % i == 0) return false;
        }
        return true;
    };


    vector<int>v;
    int x = n;
    while(x > 1) {
        v.push_back(x);
        x/=2;
        
    }



    bool ky = false;
    int cnt = 200, lastcnt = 200;

    cout << 200 << endl;

    while(cnt) {
        for(int I = 0; I < v.size()  && cnt; I ++) {
            int i = v[I];
            vector<PII> ans;
            map<int,int> mp;
            for(int j = 1, J = j + i - 1; J <= n; j ++, J ++) {
                if(mp.count(j))continue;
                ans.push_back({j, J});
                mp[J]++;
            }
            // cout << i << " " << ans.size() << endl;
            if(ans.size()) {
                cnt --;
                ky = true;
                cout << ans.size() << " ";
                for(int i = 0; i < ans.size(); i ++) cout << ans[i].first << " " << ans[i].second << " \n"[i == ans.size() - 1];

                if(n%2 && ans.back().second < n) {
                    cnt--;
                    cout << ans.size() << " ";
                    for(int i = 0; i < ans.size(); i ++) cout << ans[i].first + 1 << " " << ans[i].second + 1 << " \n"[i == ans.size() - 1];
                } 
            }
        }

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