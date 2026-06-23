#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define endl "\n" 

//vector<vector<int>>edg(N);
int n,m;
int a[N];


void solve()
{
    string s; cin >> s;
    vector<string> ans;
    string T;
    bool mh = false;
    for(auto t : s) {
        if(t == '/' || (t == ':' && mh == false)){

            if(ans.size() >= 2) {
                int cnt = 0;
                for(auto t : T) if(t == '=') cnt ++;
                // cout << T << " " << cnt << endl;
                if(cnt == 1) ans.push_back(T);
                // else ans[ans.size() - 1] += "/" + T ;
            }
            else 
            {
                mh = true;
                if(T.size())ans.push_back(T);
            }
            T = "";

        } 
        else T += t;
    }

    for(auto t : ans) cout << t << endl;
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