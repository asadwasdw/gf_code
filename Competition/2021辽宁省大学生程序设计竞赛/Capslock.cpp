#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);

int a[N];
void solve()
{
    string s;cin>>s;
    int n = s.size();
    s=" "+s;
    int num = 0;

    for(int i=1;i<=n;i++){
        if(s[i]>='A'&&s[i]<='Z')a[i]++;
        num+=a[i];
    }
    
    if(num==n||(num==n-1&&a[1]==0)){
        for(int i=1;i<=n;i++){
            if(s[i]<='z'&&s[i]>='a')s[i]=(char)(s[i]-'a'+'A');
            else s[i]=(char)(s[i]+'a'-'A');
        }
    }
    for(int i=1;i<=n;i++)cout<<s[i];

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