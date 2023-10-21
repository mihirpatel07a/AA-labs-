#include <iostream>

using namespace std;

int main()
{
  string p;
  cin>>p;
  
  p = "0" + p;
  
  int m = p.length();
  
  
  int pi[m];
  pi[0] = -1;
  pi[1] = 0;
  
  
  int count = 0;
  int k = 0;
  
  for(int q = 2; q<m; q++)
  {
      int t = p[k+1] != p[q];
      count++;
      
      while(k>0 && t)
      {
          k = pi[k];
          
     count++;
          t = p[k+1] != p[q];
      }
      if(!t)
      
        k++;
        
        
    pi[q] = k;
  }
   
   
   
//   for(int i = 0; i<m; i++)
//   {
//       cout<<pi[i]<<" ";
//   }
//   cout<<endl;
   
//   cout<<count<<endl;



   cout<<"enter t String: ";
   int count1 = 0;
   string t;
   cin>>t;
    t = "0" + t;
    
    int n = t.length();
    int q = 0;
    for(int i=1; i<n; i++)
    {
        
        int t1 = p[q+1] != t[i];
        count1++;
        while(q>0 && t1)
        {
            q = pi[q];
            count1++;
            t1 = p[q+1] != t[i];
        }
        
        if(!t1)
           q++;
           
        if(q == m)
        {
             cout<<"pattern occurs with shift" <<i-m<<endl;
             q = pi[q];
        }
    }
    
    
    cout<<count1<<endl;
    
    
    return 0;
}


