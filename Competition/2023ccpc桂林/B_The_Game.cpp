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
    int n,m;
    cin>>n>>m;
    multiset<int>t1,t2;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];

    sort(a+1,a+n+1);
    sort(b+1,b+m+1);

    int sum = n-m;
    int cnt = 0;
    bool ky = true;

    for(int i = 1;i <= n - m;i ++){
        t1.insert(a[i]);
    }

    for(int i = n - m + 1,j = 1; i <= n; i++,j++) {
       // cout<<i<<" "<<j<<endl;
        if(a[i] <= b[j]) {
            cnt += b[j] - a[i];
        }
        else ky = false;
        t2.insert(a[i]);
    }



    vector<int>ans;
    while(t1.size() && sum > cnt) {
        int l1 = *t1.begin();
        int r1 = *t2.begin();

        int t = *t1.begin();
        t1.erase(t1.begin());
        t1.insert(t+1);
        ans.push_back(t);

        int x = *prev(t1.end());
        int y = *t2.begin();
        t1.erase(prev(t1.end()));
        t2.erase(t2.begin());
        if(x>y) {
            swap(x,y);
            cnt--;
        }
        t1.insert(x);
        t2.insert(y);
        t1.erase(t1.begin());
        sum--;

        // cout<<"-------------\n";
        // for(auto t:t1)cout<<t<<" ";cout<<endl;
        // for(auto t:t2)cout<<t<<" ";cout<<endl;
        // cout<<sum<<" "<<cnt<<endl;
    }
//    cout<<sum<<endl;
    int j = 1;
    for(auto t:t2) {
        if(t<=b[j]) {
            while(t<b[j]){
                ans.push_back(t);
                t++;
                sum--;
            }
        }
        else ky = false;
        j++;
    }
    // cout<<ky<<endl;
    // cout<<sum<<endl;

    if(!ky || sum) {
        cout<<"-1\n";
    }
    else {
        cout<<n-m<<endl;
        for(auto t:ans)cout<<t<<" ";cout<<"\n";
    }
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