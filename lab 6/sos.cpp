// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>



using namespace std;



bool issumofsubset(int arr[] , int n , int sum)
{
     int capacity = sum;
     int max_profit = sum;
     
     int profit[n]; 
     int weight[n];
     
     for(int i=0; i<n; i++)
     {
         profit[i] = arr[i];
         weight[i] = arr[i]; 
     }
     
     int t[n][capacity];
     
       for(int i= 0; i<capacity; i++)
     {
         t[0][i] = 0;
         
     }
     for(int i=0; i<n; i++)
     {
         t[i][0] = 0;
     }
     
     
     for(int i=1; i<n; i++)
     {
         for(int j= 1; j<capacity ; j++)
         {
             t[i][j] = max(t[i-1][j], profit[i] + t[i-1][j- weight[i]]);
         }
     }
     
     if(t[n-1][capacity-1] == max_profit)
         return true;
     else
         return false;

}



int main() {
    cout<<"enter item size";
     int n;
     cin>>n;
     cout<<"enter sum";
     int sum;
     cin>>sum;
     
     int arr[n];
     
     for(int i=0; i<n; i++)
     {
         cin>>arr[i];
     }
     
    
     bool ans  = issumofsubset(arr, n, sum);
     
     
     cout<<ans<<endl;
    
    return 0;
}

