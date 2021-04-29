#include <iostream>
#include <math.h>

int gcd(int a, int b)
{
	int t;
	while (1)
	{
		t = a % b;
		if (t == 0)
		{
			return b;
		}
		a = b;
		b = t;
	}
}


int main()
{
	int d = 2;

	while (true)
	{
		int d2 = 7 * d;
		if (fmod(d2, 120) == 1)
		{
			std::cout << "d is: " << d << std::endl;
		}

		d++;
	}
	return 0;
}