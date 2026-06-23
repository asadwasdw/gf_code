#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);


void solve()
{
    string s,t;
    cin>>s>>t;
    int num1[50]={0},num2[50]={0};

    for(auto t:s){
        num1[t-'a']++;
    }

    
    for(auto T:t){
        num2[T-'a']++;
    }

    int ans = INF;

    for(int i=0;i<26;i++){
        if(num2[i]){
            ans=min(ans,num1[i]/num2[i]);
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