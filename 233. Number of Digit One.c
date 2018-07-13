int getCount(int n, long long pow, int r, int* s)
{
	if(r == 0 || n == 0)
	{
		return 0;
	}
	if(n / pow > 1)
	{
		return n / pow * s[r - 1] + pow + getCount(n % pow, pow / 10, r - 1, s);
	}
	else if(n / pow == 1)
	{
		return n / pow * s[r - 1] + (n % pow) + 1 + getCount(n % pow, pow / 10, r - 1, s);
	}
    else
    {
        return getCount(n, pow / 10, r - 1, s);
    }
}

int countDigitOne(int n)
{
    if(n <= 0)
    {
        return 0;
    }
	long long pow = 1;
    int r = 0;
	int a[100];
    int s[100];
	a[0] = 0;
    s[0] = 0;
	while(n / pow != 0)
	{
		a[r + 1] = s[r] * 9 + pow;
        s[r + 1] = s[r] + a[r + 1];
		pow *= 10;
		r++;
	}
	pow /= 10;
	return getCount(n, pow, r, s);
}
