#include<iostream>
#include<algorithm>
#include<math.h>
#include<set>

using namespace std;

const int N=1e5+10;

int a[N];
set<int>xb;

int f(int x){
    return round(10*sqrt(x));
}


int main()
{
    int n,m;
    cin>>n>>m;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]!=f(a[i])){
            xb.insert(i);
        }
    }

    while(m--)
    {
        int t;
        cin>>t;
        if(t==2){
            cout<<sum<<endl;
            continue;
        }

        int l,r,k;cin>>l>>r>>k;
        xb.insert(n+1);

        int b=(*xb.lower_bound(l));
        while(b<=r)
        {
            int cs=k;
            while(cs){
                t=f(a[b]);
                if(t==a[b])break;
                sum=sum+t-a[b];
                a[b]=t;
                cs--;
            }
            if(a[b]==f(a[b]))xb.erase(b);

            b=(*xb.upper_bound(b));
        }


    }

    return 0;



}