#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

//vector<vector<int>>edg(N);
int a[N];

void solve()
{
    int n,m;
    cin>>n;
    int sum = 0;
    set<int>s;
    map<int,int>num;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s.insert(x);
        a[i]=x;
        sum+=x;
    }

    sort(a+1,a+n+1);
    sum-=a[1]+a[n];
    //for(int i =1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
    
    if(s.size()>2 || (s.size()==2 && a[1]==a[2])){
        sum++;
    }
    cout<<sum<<endl;
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