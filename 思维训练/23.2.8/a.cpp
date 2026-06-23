#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
int a[2*N];
int pos[2*N];
int t,n;
 
int main()
{
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            pos[a[i]]=i;//确定各个数字应该的位置
        }
        int ans=(n%2==1);
        for(int i=1;i<=n/2;i++){
            int l,r;
            //由中间到外依次比较顺序
            if(n%2==1){
                l=(n+1)/2-(ans+1)/2;
                r=(n+1)/2+(ans+1)/2;
                if(l<1||pos[r]-pos[r-1]<0||pos[l+1]-pos[l]<0) break;
                ans+=2; 
            }
            else {
                l=n/2-ans/2;
                r=n/2+1+ans/2;
                if(l<1||pos[r]-pos[r-1]<0||pos[l+1]-pos[l]<0) break;
                ans+=2;
            }
        }
        cout<<ans<<endl;
      
        cout<<(n-ans)/2<<endl;
        
    }
    
 
    return 0;
}