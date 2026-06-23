#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n;cin>>n;
    long long sum=0;
    long long ans=999999989999;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            long long x;
            cin>>x;
            sum+=x;
            if(i+j-1==n){
                ans=min(x,ans);
            }
        }
    }
    cout<<sum-ans<<endl;
}