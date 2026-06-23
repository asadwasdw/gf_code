#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

void print(int x)
{
    if(x==1)cout<<"1001";
    else if (x==2)cout<<"10001";
    else cout<<"10";
}

void solve()
{
    int n;
    cin>>n;
    if(n==1)cout<<"1";
    else if(n==2)cout<<"10";
    else if(n==3)cout<<"Unlucky";
    else{
        while(n%2){
            print(2);
            n-=5;
        }

        while(n>=4){
            print(1);
            n-=4;
        }

        if(n){
            print(3);
        }
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