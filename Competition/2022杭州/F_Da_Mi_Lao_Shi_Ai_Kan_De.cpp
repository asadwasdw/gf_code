#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

unordered_map<string,int>st;
void solve()
{
    int n;cin>>n;

    for(int j=1;j<=n;j++){
        int k;cin>>k;
        int cnt = 0;
        while(k--) {
            string s;cin>>s;
            if(st[s])continue;
            
            // for(int i =0;i+3<=s.size();i++){
            //     if(s.substr(i,3)=="bie"){
            //         cout<<s<<"\n";
            //         cnt++;
            //         st[s]=1;
            //         break;
            //     }
            // }

            if(s.find("bie")!=string::npos){
                cout<<s<<"\n";
                st[s]=1;
                cnt++;
            }
           
            
        }
        if(!cnt)cout<<"Time to play Genshin Impact, Teacher Rice!\n";
    }
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