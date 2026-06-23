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

int num1[10][10][100][100];
int num2[10][10][100][100];

void solve()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        int a[10]={0};
        int b[10]={0};
        int cnt = 0;
        for(auto t:s){
            cnt++;
            b[cnt]=a[cnt]=t-'0';
            a[cnt]+=a[cnt-1];
        }
        for(int i =1;i<=cnt;i++){
            
            num1[cnt][i][a[i]][a[cnt]]++;
        }
        for(int i =cnt;i>=1;i--){
            b[i]+=b[i+1];
            num2[cnt][cnt-i+1][b[i]][a[cnt]]++;
            //cout<<cnt<<" "<<cnt-i+1<<" "<<b[i]<<" "<<a[cnt]<<endl;
        }
       // cout<<a[cnt]<<" "<<b[1]<<endl;
    }

   int ans = 0;

    for(int i = 1;i<=5;i++){
        for(int j=1;j<=5;j++){
            if((i+j)%2)continue;
            int g = (i+j)/2;
            for(int sum = 0;sum<=50;sum++) {
                if(i<j){
                    for(int sum1=0;sum1<=sum;sum1++){
                        int sum2 = 2*sum-sum1;
                        ans+=num1[i][i][sum1][sum1]*num2[j][g][sum][sum2];
                    }
                }
                else if(i>j){
                    for(int sum2=0;sum2<=sum;sum2++){
                        int sum1 = 2*sum-sum2;
                        ans+=num1[i][g][sum][sum1]*num2[j][j][sum2][sum2];
                    }
                }
                else {
                    ans+=num1[i][i][sum][sum]*num2[j][j][sum][sum];
                   // ans+=num2[i][i][sum][sum]*num1[j][j][sum][sum];
                }
            }
        }
    }
    cout<<ans<<endl;
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