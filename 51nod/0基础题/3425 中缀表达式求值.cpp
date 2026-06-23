#include<iostream>
#include<stack>
#include<string>
#include<map>
#include <unordered_map>

using namespace std;

stack<char>op;
stack<double>num;


void eval()//求值
{
   double b = num.top();//栈顶元素是后面那个  所以先存下b 在弹出栈顶
    num.pop();

   double a = num.top();
    num.pop();


    char p = op.top();
    op.pop();

    double  ans = 0;

    //计算
    if (p == '+') ans = a+b;
    if (p == '-') ans = a-b;
    if (p == '*') ans = a*b;
    if (p == '/') ans = a/b;

    num.push(ans);
}

char s[1000][100];

int main()
{
    int n=0;
    unordered_map<char, int> h{ {'+', 1}, {'-', 1}, {'*',2}, {'/', 2} };
    
      while(cin>>s[++n]){

    }
    
     for(int i=1;i<n;i++){
        if(isdigit(s[i][0])){
            double ans=atof(s[i]);
            num.push(ans);
        }
        else if (s[i][0] == '-' && s[i][1] >= '0' && s[i][1] <= '9')
        {
            double e = atof(s[i]);
            num.push(e);
        }
        else if (s[i][0] == '+' && s[i][1] >= '0' && s[i][1] <= '9')
        {
            double e = atof(s[i]);
            num.push(e);
        }
        else if(s[i][0]=='('){
            op.push(s[i][0]);
        }
        else if(s[i][0]==')'){
           while(op.top()!='(')
           {
               eval();
           }
           
           op.pop();//去掉上一个括号
        }
        else {
             while(op.size()&&h[s[i][0]]<=h[op.top()])//如果为+ 前面是a*b 那么前面先算a*b  a+b同理
           {                                    // h['(']为0 到这里就会停下
              eval();
           }
           op.push(s[i][0]);
        }
        
    }
  
  
 while(op.size())eval();
  
   printf("%.6lf",num.top());

    
}




