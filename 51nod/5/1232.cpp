/**
求解区间完美数的个数;
完美数:一个数能够整除它的所有非零数位;
小技巧hash : 对于最大的数位 lcm_max=2520; 离散预处理hash值
因此我们在对该数字进行求和过程中 只需要对2520进行取余即可;
dp[len][digit][mp[now_lcm]];
表示第len位digit(前面值和)%2520后所有数位为lcm为now_lcm的个数
如此空间就不是问题了 
*/
 
#include<bits/stdc++.h>
#define  ll unsigned long long
using namespace std;
 
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b);}
 
ll dp[19][2522][50];
int num[10],len,mp[2522];
 
void init(){
	int k=0;
	for(int i=1;i<=2520;i++){
		if(2520%i==0){
			mp[i]=++k;
		}
	}	
} 
 
ll dfs(int len,int digit,int now_lcm,bool end_flag){
	if(len<=0) return digit%now_lcm==0;
	if(!end_flag&&dp[len][digit][mp[now_lcm]]!=-1) return dp[len][digit][mp[now_lcm]];
	int maxx=end_flag?num[len]:9;
	ll ans=0;
	for(int i=0;i<=maxx;i++)
        ans+=dfs(len-1,(digit*10+i)%2520,i==0?now_lcm:now_lcm/gcd(now_lcm,i)*i,i==maxx&&end_flag);
	return end_flag?ans:dp[len][digit][mp[now_lcm]]=ans;
}
 
ll solved(ll n){
	len=0;
	while(n){
		num[++len]=n%10;
		n/=10;
	}

    cout<<len<<" "<<endl;
    return 0;
	//return dfs(len,0,1,true); 
}
 
int main (){
    
	init();
	int t;
	cin>>t;
	memset(dp,-1,sizeof(dp));
	while(t--){
		
		memset(num,0,sizeof(num));
		ll l,r;
		cin>>l>>r;
		cout<<solved(r)-solved(l-1)<<endl;
	} 
	return 0;
}