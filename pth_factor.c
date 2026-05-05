#include "headers.h"

long pthFactor(long n, long p) {
    long i, c;
    long fC = 0;


    for (i = 1; i <= sqrt(n); i++)
    {
	    if (n % i == 0)
	    {
		    fC++;

		    if (fC == p)
			    return (i);
	    }
    }

    for (i = sqrt(n); i >= 1; i--)
    {
	    if (i * i == n)
		    continue;
	    if (n % i == 0)
	    {
		    c = n / i;
		    fC++;

		    if (fC == p)
			    return (c);
	    }
    }

    return (0);
}
