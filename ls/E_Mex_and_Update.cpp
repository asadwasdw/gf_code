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
int n, q;
unordered_map<int,int>num;

int tr[N];
void add(int k,int x)
{
    for(int i=k;i<N;i += i&-i)tr[i]+=x;
}

int sum(int k)
{
    int res = 0;
    for(int i=k;i;i -= i&-i) {
        res+=tr[i];
    }
    return res;
}

void solve()
{
    cin>>n;
    cin >> q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(num[a[i]]==0 && a[i]<=n){
            add(a[i]+1,1);
        }
        num[a[i]]++;
    }

    // for(int i=1;i<=n;i++){
    //     cout<<sum(i)<<" ";
    // }cout<<endl;

    while(q--) {
        int k,x;
        cin>>k>>x;
        if(num[a[k]]==1 && a[k]<=n) {
            add(a[k]+1,-1);
        } 
        num[a[k]]--;

        a[k]=x;
        num[a[k]]++;
        if(num[a[k]]==1 && a[k]<=n) {
            add(a[k]+1,1);
        } 

        int l=1,r=n+10;
        while(l<r){
            int mid = (l + r) >>1;
       //     cout<<l<<" "<<r<<" "<<sum(mid)<<" "<<mid<<endl;
            
            if(sum(mid)==mid)l=mid+1;
            else r=mid;
        } 
        cout<<l-1<<endl;
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