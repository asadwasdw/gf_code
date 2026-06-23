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

void solve()
{
    int x,y;
    cin >> x >> y;
    
    int n;
    string s = "";
    for(int i=1;i<=400;i++){
        s+="wbwbwwbwbwbw";
    }

    n = s.size();
    s = " " + s;

    for(int i=1;i<=n;i++){
        a[i]=a[i-1];
        b[i]=b[i-1];
        if(s[i]=='w')a[i]++;
        else b[i]++;
    }

    bool ky = false;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(a[i]-a[j-1] == x  && b[i] - b[j-1] == y) {
                ky = true;
            }
        }
    }
    if(ky)cout <<"Yes";
    else cout<<"No";

}


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cout << setprecision(11) << fixed;
    int t;t=1;
    //cin>>t;
    for(int i=1;i<=t;i++){
        //printf("Case %d: ",i);
        solve();
    }
}