#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=1e6+10;
const int mod=998244353;
const int INF  = 0x3f3f3f3f;
const ll INFll  = 0x3f3f3f3f3f3f3f3f;

vector<vector<int>>edg(N);


void solve()
{
    int a,b,c;
    char t;
    cin>>a>>t>>b>>t>>c;
    //cout<<a<<" "<<b<<" "<<c<<endl;
    if(a+b==c){
        cout<<"Yes"<<endl;
        printf("%d + %d = %d",a,b,c);
        return;
    }
 
        {
            bool ky=true;
            for(int i=0;i<=8&&ky;i++){
                for(int j=0;j<=9;j++){
                    int d = (int)pow(10,i);
                    int t1 = a/d;
                    int t2 = a%d;
                    int t;
                    d*=j;

                    if(t1==0){
                        ky = false;
                        t=d+t2;
                    }
                    else 
                        t = t1*10*(int)pow(10,i)+d+t2;
                    //cout<<t1<<" "<<t2<<" "<<t<<endl;
                    if(t+b==c)
                    {
                        cout<<"Yes"<<endl;
                        printf("%d + %d = %d",t,b,c);
                        return;
                    }
                }
            }
        }

        {
            //cout<<"S"<<endl;
            bool ky=true;
            for(int i=0;i<=8&&ky;i++){
                for(int j=0;j<=9;j++){
                    int d = (int)pow(10,i);
                    int t1 = b/d;
                    int t2 = b%d;
                    int t;
                    d*=j;
                    if(t1==0){
                        ky = false;
                        t=d+t2;
                    }
                    else 
                        t = t1*10*(int)pow(10,i)+d+t2;
                    //cout<<t1<<" "<<t2<<" "<<t<<endl;

                    if(a+t==c)
                    {
                         cout<<"Yes"<<endl;
                        printf("%d + %d = %d",a,t,c);
                        return;
                    }
                }
            }
        }
    

        {
            bool ky=true;
            for(int i=0;i<=8&&ky;i++){
                for(int j=0;j<=9;j++){
                    int d = (int)pow(10,i);
                    int t1 = c/d;
                    int t2 = c%d;
                    int t;
                    d*=j;
                    if(t1==0){
                        ky = false;
                        t=d+t2;
                    }
                    else 
                        t = t1*10*(int)pow(10,i)+d+t2;
                    //cout<<t1<<" "<<t2<<" "<<t<<endl;
                    if(a+b==t)
                    {
                         cout<<"Yes"<<endl;
                        printf("%d + %d = %d",a,b,t);
                        return;
                    }
                }
            }
        }
    

    cout<<"No"<<endl;







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