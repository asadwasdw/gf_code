#include<iostream>
#include<algorithm>

using namespace std;
const int N=1e2+10;
int a[N];

int main()
{
    int n,q;cin>>n>>q;

    while(q--)
    {
        int t,x;
        cin>>t>>x;
        if(t<=2)a[x]+=t;
        else{
            if(a[x]>=2)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }


}