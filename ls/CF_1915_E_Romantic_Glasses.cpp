#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int a[N];
int n,t;
bool flag;
int main(){
        cin>>t;
        while(t--){
                cin>>n;
                for(int i=1;i<=n;i++){
                        cin>>a[i];
                    }
            long long odd[n+2];
            long long even[n+2];
            for (int i=1;i<=n;i++) {
                if (i%2==1){
                    odd[i]=odd[i-1]+a[i];
                    even[i]=even[i-1];
                } else {
                    even[i]=even[i-1]+a[i];
                    odd[i]=odd[i-1];
                }
            }
            
            flag=false;
            for (int i=1;i<=n;i++) 
                if(odd[i]==even[i])
                    flag==true;

            if(flag) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
    }
}