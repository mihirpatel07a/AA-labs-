


#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(a<b)
       return gcd(b,a);
    else if(a%b == 0)
        return b;
    else
       return gcd(b, a%b);
}


int power(int a, int x, int n)
{
    int res = 1;

    while(x > 0)
    {
        if(x% 2 == 1)
          res = (res*a)%n;
        
        x = x/2;
        a = (a*a)%n;

    }
    return res;
}

int  isprime(int n)
{
    srand(time(NULL));
    int a = 2 + rand()% (n-3);


    int k = 100;
    while(k >0)
    {
        if(gcd(n,a) != 1)
          return 0;
        if(power(a,n-1,n) != 1)
          return 0;

          k--;
    }
    return 1;

}




int  main()
{
    int n;
    cin>>n;

   int ans =  isprime(n);
   cout<<ans<<endl;
 return 0;
}


