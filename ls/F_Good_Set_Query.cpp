#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
#define int long long

int p[N];
int d[N];

int find(int x){
    if(x!=p[x]){
        int root =find(p[x]);
        d[x]+=d[p[x]];
        p[x]=root;
    }
    return p[x];
}


void solve()
{
        
    for(int i=1;i<N;i++){
        p[i]=i;
    }

    int n,m;
    cin>>n>>m;
    vector<int>ans;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;

        int fa = find(a);
        int fb = find(b);
        

        if(fa == fb) {
            if((d[a] - c) != d[b]){

            }
            else ans.push_back(i);
        } 
        else {

            d[fa] = d[b] + c - d[a];
            p[fa]=fb;

 
            ans.push_back(i);
          
        }
        find(a);
        find(b);


    }
    for(auto t:ans){
        cout<<t<<" ";
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