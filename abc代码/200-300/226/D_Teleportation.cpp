#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
map<PII,int>st;
PII a[N];
void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)continue;
            
            int x = a[i].first-a[j].first;
            int y = a[i].second-a[j].second;
            if(x==0){
                y=1;
            }
            else if(y==0)x=1;
            else {
                int t =__gcd(abs(x),abs(y));
                x/=t;
                y/=t;
            }

            
        
            st[{x,y}]++;
            st[{-x,-y}]++;
        }
    }

    // for(auto t:st){
    //     cout<<t.first.first<<" "<<t.first.second<<endl;
    // }

    cout<<st.size()<<endl;




}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}