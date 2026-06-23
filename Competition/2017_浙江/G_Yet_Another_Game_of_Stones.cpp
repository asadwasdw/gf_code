#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);

int a[N],b[N];

void print(int t)
{
    if(t == 1)cout<<"Alice";
    else cout<<"Bob";
    cout<<"\n";
}

void solve()
{

    int n;cin>>n;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
    }

    for(int i = 1;i <= n;i++){
        cin>>b[i];
    }
    int cnt0 = 0,cnt1 = 0;
    for(int i =1 ;i <= n;i++){
        if(a[i]%2 && b[i] == 2)cnt0++;
        if((a[i]%2 == 0 && b[i] == 2) || (a[i]%2 == 0 && b[i] == 1) ||(a[i]%2 && a[i] > 1 && b[i] == 1)){

            if(a[i]%2 == 0 && b[i] == 1)a[i] = 1;
            else a[i] = 0;
            cnt1++;

        }
    }
    if(cnt0 || cnt1 > 1){
      // cout<<cnt0<<" "<<cnt1<<endl;
        print(2);
        return ;
    }

    int ans = 0 ;
    for(int i = 1;i <= n;i++)ans ^= a[i];
    if((ans && cnt1 == 0) || (cnt1 == 1 && ans == 0)){
        print(1);
    }
    else print(2);
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