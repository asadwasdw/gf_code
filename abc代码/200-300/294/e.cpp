#include<iostream>
#include<algorithm>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> PII;

const int N=2e5+10;
PII a[N];
PII b[N];

int main()
{
    ll l,n1,n2;
    cin>>l>>n1>>n2;

    for(int i=1;i<=n1;i++)cin>>a[i].first>>a[i].second;
    for(int j=1;j<=n2;j++)cin>>b[j].first>>b[j].second;

    ll t1=0,t2=0;
    ll st1=-1,st2=-2;
    ll i=1,j=1;
    ll ans=0;
    while(1)
    {
        if(t1>=l&&t2>=l){
            break;
        }

        if(t1<t2)
        {
            st1=a[i].first;
            if(st1==st2){
                if(t1+a[i].second<=t2)
                ans+=a[i].second;
                else ans+=t2-t1;
            }
            t1+=a[i].second;
            i++;
        }
        else if(t1>t2)
        {
            st2=b[j].first;
            if(st1==st2){

                if(t2+b[j].second<=t1)
                     ans+=b[j].second;
                else ans+=t1-t2;
            }
            t2+=b[j].second;
            j++;
        }
        else {
            st1=a[i].first;
            st2=b[j].first;

            if(st1==st2)
            {
                ans+=min(a[i].second,b[j].second);
            }
            t1+=a[i].second;
            t2+=b[j].second;
            i++;j++;
        }

       // cout<<t1<<" "<<t2<<" "<<ans<<endl;

    }

    cout<<ans<<endl;


}

