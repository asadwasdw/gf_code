#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define int long long
//vector<vector<int>>edg(N);


void solve()
{
    multiset<int>s;
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        s.insert(x);
    }
    int z = 0;
    int ans = 0;
    while(s.size()>=2){
        int mn = *s.begin();
        s.erase(s.begin());
        int mx = *prev(s.end());
        s.erase(prev(s.end()));
        //cout<<mn<<" "<<mx<<" "<<z<<endl;
        if(mn+z<mx){
            z+=mn;
            s.insert(mx);
            ans+=mn;
        }
        else{
            mn-=mx-z;
             ans+=mx-z+1;
            z=0;
            if(mn)s.insert(mn);
           
        }
    }
    if(s.size()){
        int t = *s.begin();
   
        if(t==1||t==z)ans++;
        else if(z>t)ans+=t;
        else {
        int  mid = (t - z)/2;
        z+=mid;
        ans+=mid;
        //cout<<t-mid-z<<endl;
        ans++;
        if(t-mid-z){
            ans++;
        }
        }
    }
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