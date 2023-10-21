// Online C++ compiler to run C++ program online

#include <bits/stdc++.h>

using namespace std;

int main() {
  int flag  = 0;
   cout<<"enter string:";
   string t;
   cin>>t;
   
   cout<<"enter pattern string:";
   string p;
   cin>>p;
   
   int n = t.length();
   int m = p.length();
   int q =13;
   
   int d = 10;
   
   int p1 = 0;
   int t0 = 0;
   
   for(int i=0 ; i<m; i++)
   {
       p1 = (d*p1 + p[i])%q;
       t0  = (d*t0 + t[i])%q;
   }
   
   
   int ts[n-m+1] ;
   ts[0] = t0;
   
   cout<<ts[0];
   int h = pow(d,m-1);
   
   
  for(int s=0; s<=n-m; s++)
  {
      if(p1 == ts[s])
      {
          int i=0;
          while(i<m && p[i] == t[s+i])
          {
              i++;
          }
          
          if(i == m)
          {
              cout<<"pattern occurs with shift"<<s<<endl;
              flag =1 ;
          }
      }
      
      if(s<n-m)
      {
          ts[s+1] = ((ts[s] - (t[s+1]*h))*d + t[s+1])%q;
          
          if(ts[s+1] < 0)
          {
               ts[s+1] += q;
          }
      }
      
      
  }
  
  
  if(flag == 0)
     cout<<"string does not match";
    return 0;
}

