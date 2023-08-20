// Lab 5 aa


// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int main() {
    
	string t, p;
	cout<<"enter string:\n";
	cin>>t;
 
    
   
	cout<<"enter pattern string:\n";
	cin>>p;
    
	int n = t.length();
	int m = p.length();
    
	for(int s= 0; s<=n-m; s++)
	{
       int j = 0;
    
       while(j < m && t[s+j] == p[j])
       {
           j++;
       }
   	 
    	if(j==m) {
        	cout << s << endl;
        	return 0;
    	}
    	 
	}
	cout<<"string not found"<<endl;
    
    
    
   

	return 0;
}


