#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int a[N],b[N];

void solve()
{
    int n,m;
    cin>>n>>m;
    int l= 1,r=n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }

    string s;cin>>s;
    s=" "+s;

    for(int i=1;i<=n;i++) {
        if(s[i]=='L')l++;
        else r--;
    }
    // cout<<l<<" "<<r<<endl;
    int res = 1;
    for(int i=n;i;i--){
        if(s[i]=='L'){
            l--;
            res*=a[l];
        }
        else {
            r++;
            res*=a[r];
        }
        // cout<<i<<" "<<l<<" "<<r<<endl;
         res%=m;
        b[i]=res;
    }

    for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<"\n";
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