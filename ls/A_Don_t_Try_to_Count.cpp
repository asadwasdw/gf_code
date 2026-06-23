#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

string x,s;
bool pd()
{
    //cout<<x<<" "<<s<<endl;
    for(int i = 0; i + s.size() <= x.size(); i++){
        if(x.substr(i,s.size()) == s)return true;
    }
    return false;


}

void solve()
{
    int n,m;cin>>n>>m;

  
    cin>>x>>s;
    int ans = 0;
    bool ky = false;

    int cnt = 0;
    while((x.size() <=  2*s.size() || cnt<=2) && ky== false){
        if(pd()){
            ky=true;
        }
        else ans++;
        cnt++;
        x = x + x;
    }
 
    if(!ky)ans =  -1;
    cout<<ans<<endl;

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