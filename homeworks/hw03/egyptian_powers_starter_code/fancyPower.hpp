#ifndef FANCYPOWER_HPP
#define FANCYPOWER_HPP

#include <iostream>

int fancyPower(int n, int m)
{
	int ans; //Making a variable to return
	static bool negative; //sets if it should be negative or nah

	if(m<0 && n%2 != 0)
	{
		negative = true;
	}
	
	else
	{
		negative = false;
	}
	
	if(m==0)
	{
		ans = 0;
	}

	else if(n == 1)
	{
		ans = m;
	}

	else if(n == 0)
	{
		ans = 1;
	}

	else if(n % 2 == 0)
	{
		ans = fancyPower(n/2,m*m);
	}
	
	else
	{
		ans = m * fancyPower((n-1)/2,m*m);
	}

	if(negative == true)
	{
		return ans*-1;
	}

	else
	{
		return ans;
	}
}

#endif
