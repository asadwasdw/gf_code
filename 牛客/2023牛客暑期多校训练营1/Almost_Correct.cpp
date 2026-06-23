#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
vector<PII>ans;
vector<int>s1;
vector<int>s0;


void solve()
{
    ans.clear();
    s1.clear();
    s0.clear();
    int n;cin>>n;
    int l = INF;
    int r = 0;
    for(int i=1;i<=n;i++){
        char t;
        cin>>t;
        if(t=='1'){
            l=min(i,l);
            s1.push_back(i);
        }
        else
        {
            r=max(r,i);
            s0.push_back(i);
        } 
    }

    for(auto t:s0){
        if(t!=r)
        ans.push_back({t,r});
    }

    for(auto t:s1){
        if(t!=l)
        ans.push_back({t,l});
    }


//   for(auto x : s0) if(x != r) ans.push_back({x, r});
//     for(auto x : s1) if(x != l) ans.push_back({x, l});

    for(int i=1;i<=n;i++){
        if(i==l||i==r)continue;

        for(int j=i+1;j<=n;j++){
            if(j==l||j==r)continue;
            ans.push_back({i,j});
        }
    }

    for(int i=s0.size();i>l;i--)ans.push_back({l,i});
    for(int i=1;i<=l-1;i++)ans.push_back({l,i});


    for(int i=s0.size()+1;i<r;i++)ans.push_back({r,i});
    for(int i=n;i>r;i--)ans.push_back({r,i});


    

    cout<<ans.size()<<endl;
    for(auto t:ans)
    {
        if(t.second<t.first)swap(t.second,t.first);
        cout<<t.first<<" "<<t.second<<endl;
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