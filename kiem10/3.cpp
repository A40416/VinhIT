#include <iostream>
using namespace std;
long long is_prime(long long n)

{
    if (n % 2 == 0)
        return 0;		// is even, therefore not prime
    for (long long i = 3; i <= ((n / 2) + 1); i += 2)	// Skip all the even numbers
    {
        if (n % i == 0)
            return 0;	//not prime
    }
    return 1;
}
long long find_bigprime(long long n)
{
    long long factor = 0;
    for(long long i = 3; i <= n; i += 2)
    {
        if (n % i == 0)
        {
            if (is_prime(i))
            {
                factor = i;
                cout << factor << endl;
            }
        }
    }
    return factor;
}
    int main()
    {
    	long long input = 600851475143;
    	cout << find_bigprime(input);
    	return 0;
    }