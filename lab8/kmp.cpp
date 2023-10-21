#include <iostream>

using namespace std;

int main()
{
   cout<<"enter patteren string: ";
   
   string p;
   cin>>p;
   
   
   
   p = "0" + p;
   
   int m = p.length();
   int pi[m];
   
   pi[0] = -1;
   pi[1] = 0;
   
   int count = 0;
   int k = 0;
   for(int q = 2; q<m ; q++)
   {
       int t = p[k+1] != p[q];
       count++;
       while(k>0 && t)
       {
           
           k = pi[k];
           
           t = p[k+1] != p[q];
           count++;
       }
       
       if(!t)
          k++;
          
       pi[q] = k;
   }
   
   for(int i=0 ; i<m; i++)
   {
       cout<<pi[i]<<" ";
   }
   
   cout<<endl;
   cout<<count<<endl;

    return 0;
}
