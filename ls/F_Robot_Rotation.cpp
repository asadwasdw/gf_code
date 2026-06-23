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
vector<int>x,y;
int n,tx,ty;
string ansx,ansy;

bool pdx()
{
    map<int,int>st;
    int n1 = x.size()/2;
    int n2 = x.size()-n1;
    for(int i=0;i<(1<<n1);i++) {
        int res = 0;  
        for(int j=0;j<n1;j++){
            if((i>>j) & 1)res += x[j];
            else res -= x[j];
        }

        st[res]=i+1;
    }


    for(int i=0;i<(1<<n2);i++) {
        int res = 0;  
        for(int j=0;j<n2;j++){
            if((i>>j) & 1)res += x[j + n1];
            else res -= x[j + n1];

           // if(i==7)cout<<res<<" "<<x[j + n1]<<endl;
            
        }
     

        if(st[tx - res]) {
            int t = st[tx - res];
            t--;
           // cout<<i<<" "<<res<<endl;
            for(int k = 0;k<n1;k++){
                ansx+=(char)(((t>>k) & 1) +'0');
            }
            for(int k = 0;k<n2;k++){
                ansx+=(char)(((i>>k) & 1) +'0');
            }
        
    
            return true;
        }
    }
    return false;
}

bool pdy()
{
    map<int,int>st;
    int n1 = y.size()/2;
    int n2 = y.size()-n1;
    for(int i=0;i<(1<<n1);i++) {
        int res = 0;  
        for(int j=0;j<n1;j++){
            if((i>>j) & 1)res += y[j];
            else res -= y[j];
        }
        st[res]=i+1;
    }

    for(int i=0;i<(1<<n2);i++) {
        int res = 0;  
        for(int j=0;j<n2;j++){
            if((i>>j) & 1)res += y[j + n1];
            else res -= y[j + n1];
        }
        if(st[ty - res]) {
            
            int t = st[ty - res];
            t--;
            for(int k = 0;k<n1;k++){
                ansy+=(char)(((t>>k) & 1) +'0');
            }
            for(int k = 0;k<n2;k++){
                ansy+=(char)(((i>>k) & 1) +'0');
            }
            return true;
        }
    }
    return false;
}


void sc()
{
    int st = 0;
    int i = 0,j=0;
    while(i<ansx.size()||j<ansy.size()){
        if(st==0)
        {
            if(ansy[j++] =='1')cout<<"L",st=1;
            else cout<<"R",st=3;
        }
        else if(st == 2)
        {
            if(ansy[j++] =='1')cout<<"R",st=1;
            else cout<<"L",st=3;
        }
        else if(st == 1) {
            if(ansx[i++] =='1')cout<<"R",st=0;
            else cout<<"L",st=2;
        }
        else if(st == 3){
            if(ansx[i++] =='1')cout<<"L",st=0;
            else cout<<"R",st=2;
        }
    }
}





void solve()
{
  
    cin>>n>>tx>>ty;
    for(int i=1;i<=n;i++){
        int t;cin>>t;
        if(i%2==1){
            y.push_back(t);
        }
        else x.push_back(t);
    }
    if(pdx()&&pdy()){
        //cout<<ansy<<" "<<ansx<<endl;
        // int ans = 0;
        // for(int i=0;i<ansx.size();i++){
        //     cout<<x[i]<<" "<<ansx[i]<<endl;;
        //     if(ansx[i]=='1')ans+=x[i];
        //     else ans-=x[i];
        // }
        // cout<<ans<<endl;
        cout<<"Yes\n";
        sc();
    }
    else cout<<"No\n";

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