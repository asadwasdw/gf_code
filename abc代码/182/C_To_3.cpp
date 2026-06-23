#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int num[3];

void solve()
{
    long long n;
    cin>>n;
    int sum = 0;
    while(n)
    {
        int t = (n%10);
        n/=10;
        sum+=t;
        num[t%3]++;
    }
    if(sum<3){
        cout<<"-1";
    }
    else if(sum%3==0){
        cout<<"0";
    }
    else if(sum%3==1)
    {
        if(num[1]&&(num[2]||num[0])){
            cout<<"1";
        }
        else if(num[2]>=2&&(num[1]||num[0])){
            cout<<"2";
        }
        else cout<<"-1";
    }
    else {
        if(num[2]&&(num[1]||num[0])){
            cout<<"1";
        }
        else if(num[1]>=2&&(num[2]||num[0])){
            cout<<"2";
        }
        else cout<<"-1";
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