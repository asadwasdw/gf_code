#include<iostream>
#include<algorithm>

using namespace std;

void solve()
{
    long long k;cin>>k;

    long long l1,r1,l2,r2;

    cin>>l1>>r1>>l2>>r2;

    long long l=k-r2;
   long long r=k-l2;
    if(l>r){
        swap(l,r);
    }

   // cout<<l<<" "<<r<<endl;
    l=max(l,l1);
    r=min(r,r1);


    cout<<max((long long)0,r-l+1)<<endl;



}

int main()
{
    int t;cin>>t;while(t--)
    solve();    
}