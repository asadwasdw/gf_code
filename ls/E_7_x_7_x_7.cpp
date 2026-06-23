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

struct zfx
{
    int x0,y0,z0;
    int x,y,z;
    void print(){
        cout<<x0<<" "<<y0<<" "<<z0<<" "<<x<<" "<<y<<" "<<z<<endl;
    }
    int V(){
        return x*y*z;
    }
};


zfx js(zfx z1,zfx z2) {
    zfx res;

    res.x0 = max(z1.x0,z2.x0);
    res.y0 = max(z1.y0,z2.y0);
    res.z0 = max(z1.z0,z2.z0);

    res.x = min(z1.x0+z1.x,z2.x0+z2.x);
    res.y = min(z1.y0+z1.y,z2.y0+z2.y);
    res.z = min(z1.z0+z1.z,z2.z0+z2.z);

    res.x = max(0ll,res.x-res.x0);
    res.y = max(0ll,res.y-res.y0);
    res.z = max(0ll,res.z-res.z0);
    return res;
}

int i1,i2,i3,i4,i5,i6;


void solve()
{
    // zfx a,b;
    // a={1,2,1,7,7,7};
    // b={1,2,1,7,7,7};
    // zfx c = js(a,b);
    // a.print();
    // b.print();
    // c.print();

    int A,B,C;
    cin>>A>>B>>C;

    for(int i1 = 0;i1<=15;i1++)
    for(int i2 = 0;i2<=15;i2++)
    for(int i3 = 0;i3<=15;i3++)
    for(int i4 = 0;i4<=15;i4++)
    for(int i5 = 0;i5<=15;i5++)
    for(int i6 = 0;i6<=15;i6++)
    // i2=6,i4=6;
    {
        zfx a,b,c;
        a={0,0,0,7,7,7};
        b={i1,i2,i3,7,7,7};
        c={i4,i5,i6,7,7,7};

        int ans1=3*7*7*7,ans2,ans3;
        zfx ab = js(a,b);
        zfx bc = js(c,b);
        zfx ac = js(a,c);
        zfx abc = js(a,bc);

        // ab.print();
        // ac.print();
        // bc.print();
        // abc.print();
        
        ans3 = abc.V();
        ans2 = ab.V()+bc.V()+ac.V()- 3*ans3;
        ans1 -= 2*ans2 + 3*ans3;

        if(A==ans1 && B == ans2 && C == ans3) {
            cout<<"Yes\n";
            cout<<"0 0 0 "<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<" "<<i6<<endl;
            return;
        }
    }
    cout<<"No\n";





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