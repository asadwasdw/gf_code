#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


struct op{
    int r,c,h,w;
};

vector<op>ans;

int len(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y2-y1);
}


void dfs(int n,int x,int y,int jzx,int jzy)
{

    if(n==1){
        return ;
    }
    int len1 = len(1,1,x,y); 
    int len2 = len(1,n,x,y); 
    int len4 = len(n,1,x,y); 
    int len3 = len(n,n,x,y); 
    int mx = max({len1,len2,len3,len4});

    if(len1==mx)
    {
        ans.push_back({1+jzx,1+jzy,n-1,n-1});
        dfs(n-1,x-1,y-1,jzx+1,jzy+1);
    }
    else if(len2==mx)
    {
        ans.push_back({1+jzx,n+jzy,n-1,-n+1});
        dfs(n-1,x-1,y,jzx+1,jzy);
    }
    else if(len3==mx)
    {
        ans.push_back({n+jzx,n+jzy,-n+1,-n+1});
        dfs(n-1,x,y,jzx,jzy);
    }
    else  
    {
        ans.push_back({n+jzx,1+jzy,-n+1,n-1});
        dfs(n-1,x,y-1,jzx,jzy+1);
    }
}



void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    dfs(n,x,y,0,0);

    cout<<"Yes\n";
    cout<<ans.size()<<endl;

    for(auto t:ans){
        cout<<t.r<<" "<<t.c<<" "<<t.h<<" "<<t.w<<endl;
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