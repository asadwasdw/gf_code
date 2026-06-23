#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);
int v[N];
int w[N];
int n;



bool check(int mid)
{
    vector<int>a;
    vector<int>b;
    
    for(int i=1;i<=n;i++)
    {
        if(v[i]>=mid)
        {
            //cout<<i<<endl;
            a.push_back(v[i]-mid+w[i]);
        }
        else b.push_back(w[i]);
    }
    int na=a.size();
    int nb=b.size();
 //   cout<<na<<" "<<nb<<endl;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    // for(auto t:a)cout<<t<<" ";cout<<endl;
    // for(auto t:b)cout<<t<<" ";cout<<endl;

    int i =0;
    int j =0;
    while(i<na&&j<nb)
    {
        if(a[i]>=b[j]){
            i++;
            j++;
        }
        else {
            i++;
        }
    }
    //cout<<i<<" "<<j<<endl;
    if(i==na&&j!=nb)return false;
    return true;
}


void solve()
{
    
    cin>>n;
    int l = 0,r=0;
    for(int i =1;i<=n;i++)
    {
        cin>>v[i]>>w[i];
        r=max(r,v[i]);
    }
    //cout<<r<<endl;
    //if(check(0))cout<<"yes";

    while(l<r)
    {
        int mid = (l+r+1)>>1;
        if(check(mid))l=mid;
        else r=mid-1;
    }

    cout<<l<<endl;







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