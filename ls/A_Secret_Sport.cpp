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
    int n;
    cin>>n;
    string s;cin>>s;
    s = " " + s;
    set<int>st;
    for(int x=1;x<=n;x++){
        for(int y=1;y<=n;y++){
            int a = 0, b = 0;
            int cnta = 0,cntb = 0;
            int ans = 0;
            for(int i = 1;i<=n;i++){
                if(s[i]=='A'){
                    cnta++;
                }
                else cntb++;
                
                if(cnta == x){
                  cnta = cntb = 0;
                    a++;
                }
                
                if(cntb == x){
                    cnta = cntb = 0;
                    b++;
                }

                if(max(a,b)==y) {
                    //cout<<a<<" "<<b<<" "<<i<<endl;
                    if(i==n){
                        if(a==y)ans=1;
                        if(b==y)ans=2;
                    }
                    else break;
                }
            }
          // cout<<x<<" "<<y<<" "<<ans<<endl;
            if(ans){
                
                st.insert(ans);
            }
        }
    }

    if(st.size()!=1){
        cout<<"?\n";
    }
    else {
        if(*st.begin()==1)cout<<"A\n";
        else cout<<"B\n";
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