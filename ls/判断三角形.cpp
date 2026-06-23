#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


void print(int ans)
{
    if(ans == 1)cout<<"输入不满足要求,存在小数或者数据超出范围\n";
    if(ans == 2)cout<<"不能构成三角形\n";
    if(ans == 3)cout<<"一般三角形\n";
    if(ans == 4)cout<<"等腰三角形\n";
    if(ans == 5)cout<<"等边三角形\n";
}


void solve()
{
    vector<int>a;
    set<int>s;
    int ans = 0;
    for(int i = 1;i <= 3;i++){
        double x;cin>>x;
        if(x != int(x))ans = 1;
        a.push_back(x);
    }

    sort(a.begin(),a.end());
    if(a[0] < 1 || a[2] > 200){
        cout<<"输入不合法"<<endl;
        return;
    }
    if(a[0] + a[1] <= a[2]){
        ans = 1;
        cout<<"不能构成三角形"<<endl;
        return;
    }

    double p = (1.0 * a[0] + a[1] + a[2]) / 2;
    double area = sqrt(p * (p - a[0]) * (p - a[1]) * (p - a[2]));
    cout<<area<<endl;

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