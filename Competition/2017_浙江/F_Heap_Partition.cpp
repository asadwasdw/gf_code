#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

multiset<int>s;

int cnt = 0; 
void solve()
{
    s.clear();
    cnt = 0;
    int n;cin>>n;
    vector<int>wz(n+1,0);
    vector<int> ans[n + 1];
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        auto tt = s.upper_bound(x) ;
        if(tt == s.begin()){
            cnt ++ ;
            wz[x] = cnt;
            ans[cnt].push_back(i);
        }
        else {
             tt -- ;
            int t = *tt;
            s.erase(tt);
            wz[x] = wz[t];
            ans[wz[x]].push_back(i);
        }
        s.insert(x);
        s.insert(x);
    }

    cout <<cnt<<endl;
    for(int  i = 1;i <= cnt;i++){
        cout<<ans[i].size()<<" ";
        for(auto t:ans[i])cout<<t<<" ";
        cout<<endl;
    }

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}