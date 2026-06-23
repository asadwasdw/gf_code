#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;
#define int long long

//vector<vector<int>>edg(N);

int a[N];
int b[N];

void solve()
{
    int n,m,x;
    cin>>n>>m>>x;
    set<int>s;

    for(int i=0;i<n;i++)cin>>a[i]; 
    for(int i=0;i<m;i++)cin>>b[i],s.insert(b[i]); 
    
    vector<int>lsh;
    lsh.push_back(-1);
    for(auto t:s){
        lsh.push_back(t);
    }
    lsh.push_back(INFll);
    
    
    // for(int i=0;i<n*m;i++){
    //     vector<int>t;
    //     t.push_back(a[i/m]);
    //     t.push_back(b[i%m]);
    //     t.push_back(x);
    //     sort(t.begin(),t.end());
    //     x=t[1];
    //    // cout<<i/m<<" "<<i%m<<endl;
    //     // cout<<x<<endl;
    // }

    for(int i=0;i<n;i++){
       // cout<<x<<" "<<a[i]<<endl;

        // if(x == a[i]) {

        // }
        // else if(s.count(a[i])){
        //     x=a[i];
        // }
        // else if(x>a[i]){
        //     auto t = lower_bound(lsh.begin(),lsh.end(),a[i]);
        //     if(*t !=INFll){
        //         x = min(x,*t);
        //         //cout<<a[i]<<" "<<x<<endl;
        //     }
        //     if(lsh[1]<a[i])x = a[i];
        // }
        // else if(x<a[i])
        // {
        //     auto t = lower_bound(lsh.begin(),lsh.end(),a[i])-1;
        //     if(*t!=-1){
        //         x = max(x,*t);
        //     }
        //     if(lsh[lsh.size()-2]>a[i])x = a[i];
        // }

        if (x==a[i]) continue;
        if (x>a[i]) {
            if (a[i]>=lsh[1]) x=a[i];
            else x=min(x, lsh[1]);
        } else {
            if (a[i]<=lsh[lsh.size()-2]) x=a[i];
            else x = max(x, lsh[lsh.size()-2]);
        }


    }
    cout<<x<<endl;


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