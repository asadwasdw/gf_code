#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int n;
int a[N];
int ans;

void js(int k){
 
    vector<int>t;
    for(int i=1;i<=k;i++)
    {
        
        int res = 0;
        vector<int>s;
        for(int j=i;j<=n;j+=k){
            s.push_back(a[j]);
        }
        int tt=s[0];
        for(auto T:s){
            if(T!=tt){
                if(res==0){
                    res=abs(T-tt);
                }
                else res=__gcd(abs(T-tt),res);
            }
        }
        if(res)t.push_back(res);
    }
    int res = 0;
    // cout<<k<<endl;for(auto T:t)cout<<T<<" ";cout<<endl;
    for(auto T:t){
        if(res==0)res=T;
        else res=__gcd(res,T);
    }
    
    if(res!=1)ans++;
}



void solve()
{
    ans=1;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    js(1);
    if(n==1)ans--;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            js(i);
            if(i!=n/i)js(n/i);
        }
    }
    cout<<ans<<"\n";

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