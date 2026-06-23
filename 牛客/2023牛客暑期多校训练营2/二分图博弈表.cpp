#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int n;
struct c{
    int r,b,g;

    bool operator <(const c & a) const
	{
		return r<a.r;
	}

};

vector<vector<c>> color(N);
int cntcolor[N];

int st[20][20][20];

void dfs(int x,int y,int z)
{
    if(max({x,y,z})>n)return;
    if(st[x][y][z])return ;
    st[x][y][z]=true;
    int sum = x+y+z;
    //cout<<sum<<" "<<x<<" "<<y<<" "<<z<<endl;
    cntcolor[sum]++;
    if(x==0&&y==1&&z==0)cout<<sum<<endl;
    color[sum].push_back({x,y,z});
    dfs(x+1,y,z);
    dfs(x,y+1,z);
    dfs(x,y,z+1);
}



void solve()
{
    
    cin>>n;
    dfs(1,1,1);
    int cnt[2]={0};
    for(int i=3;i<=3*n;i++){
        cout<<"sum="<<i<<",数目： ";
         cout<<color[i].size()<<endl;
         cnt[i%2]+=color[i].size();

         for(auto t:color[i]){
            cout<<t.r<<" "<<t.b<<" "<<t.g<<endl;
         }
        cout<<endl;
    }
    cout<<cnt[0]<<" "<<cnt[1]<<endl;







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