int a[10000000];
bool isUgly(int num)
{
	if(num % 2 == 0)
	{
	    if(a[num / 2] == 1)
			return true;
		else
			return false;
	}
	if(num % 5 == 0)
	{
		if(a[num / 5] == 1)
			return true;
		else
			return false;
	}
	if(num % 3 == 0)
	{
		if(a[num / 3] == 1)
			return true;
		else
			return false;
	}
	return false;
}

int nthUglyNumber(int n)
{
	if(n == 1)
	{
		return 1;
	}
	int cnt = 1;
	int i = 2;
	a[1] = 1;
	while(1)
	{
		if(isUgly(i))
		{
			cnt++;
			if(cnt == n)
			{
				break;
			}
			a[i] = 1;
		}
		else
		{
			a[i] = 0;
		}
		i++;
	}
	return i;
}