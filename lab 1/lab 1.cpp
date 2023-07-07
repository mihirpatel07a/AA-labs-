#include <bits/stdc++.h>
using namespace std;

int partition(int arr[] , int p , int r, int &count)
{
    int x = arr[r];
    int i=p-1;
    int j;
    
    for(j=p; j<=r-1; j++)
    {
        count++;
        if(arr[j] < x)
        {
            i++;
            swap(arr[i] , arr[j]);
        }
    }      
    
    swap(arr[i+1], arr[r]);
    return i+1;
}

int r_partition(int arr[] , int p, int r , int &count)
{
    srand(time(NULL));
    int i = p + rand()% (r-p+1);
    
    swap(arr[i] , arr[r]);
    
    return partition(arr,p,r,count);
}

void r_quicksort(int arr[], int p, int r, int &count)
{
    if(p<r)
    {
        int q = r_partition(arr, p, r, count);
        r_quicksort(arr, p, q-1, count);
        r_quicksort(arr, q+1, r, count);
    }
}

int main()
{
    int count = 0;
    int arr[10];
    
    for(int i=0; i<=9; i++)
    {
         arr[i] = i;
    }

  
    
    r_quicksort(arr, 0, 9,count);

      for(int i=0; i<=9; i++)
      {
        cout<<arr[i]<<" ";
      }
    cout<<"the count is "<<count<<endl;
}