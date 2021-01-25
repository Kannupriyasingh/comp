/*
formula =>
phi(n) = n(1-(1/p1)) * (1-(1/p2)) * (1-(1/p3))* ... * (1-(1/pk))
where p1, p2, p3,...,pk are prime factors of n


input : 5
output:
Euler Totient Phi for 1 is 1
Euler Totient Phi for 2 is 1
Euler Totient Phi for 3 is 2
Euler Totient Phi for 4 is 2
Euler Totient Phi for 5 is 4
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void euler_totient(int num)
{
    int *sieve = new int[num+1];
    for(int i = 1; i <= num; i++)
        sieve[i] = i;
    
    for(int i = 2; i <= num; i++)
    {
        if(sieve[i] == i)
        {
            sieve[i] = i - 1;
            for(int j = 2; i*j <= num; j++)
            {
                //(1 - (1/i)) == (i-1)/i
                sieve[i*j] = (sieve[i*j] * (i-1))/i;
            }
        }
    }
    for(int i = 1; i <= num; i++)
    cout << "Euler Totient Phi for " << i << " is " << sieve[i] << endl;
    
    delete [] sieve;
}
int main()
{
    int num;
    cin >> num;
    euler_totient(num);
    return 0;
}
