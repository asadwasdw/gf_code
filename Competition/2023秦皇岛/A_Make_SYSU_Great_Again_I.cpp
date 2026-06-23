#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

map<PII,bool>st;

void solve()
{

    int n,k;cin>> n>> k;
    vector<PII>ans;

    int x=1,y=1;
    bool flag = true;
    while(k){
        ans.push_back({x,y});
        st[{x,y}] = true;
        k--;

        if(flag) {
            y++;
        }
        else x++;

        if(x==n&&y==n){
            ans.push_back({n,n});
            st[{n,n}]=true;

            ans.push_back({n,1});
            st[{n,1}]=true;
            k-=2;
            break;
        }
        flag = !flag;
    }
    

    for(int i=1;i<=n&&k;i++)
    {
        for(int j=1;j<=n&&k;j++){
            if(st[{i,j}])continue;
            ans.push_back({i,j});
            k--;
        }
    }
    int cnt = 1;
    for(auto t:ans){
        cout<<t.first<<" "<<t.second<<endl;
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<a[i][j]<<" ";
    //     }cout<<endl;
    // }




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