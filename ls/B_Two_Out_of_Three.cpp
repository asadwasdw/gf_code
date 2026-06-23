#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N];
int b[N];
void solve()
{
    unordered_map<int,int>mp;
    vector<int>ans;

    int n;cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        mp[a[i]]++;
        if(mp[a[i]] == 2) {
            if(ans.size()<2){
                ans.push_back(a[i]);
            }
        }
    }

    if(ans.size()<2) {
        cout<<"-1\n";
        return ;
    }

    int last1,last2;
    for(int i=1;i<=n;i++){
        if(a[i]==ans[0]){
            b[i]=1;
            last1 = i;
        }
        else if(a[i]==ans[1]){
            b[i]=2;
            last2=i;
        }
        else {
            b[i]=1;
        }
    }
    
    b[last1] = 2;
    b[last2] = 3;
    for(int i=1;i<=n;i++)cout<<b[i]<<" ";cout<<endl; 

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