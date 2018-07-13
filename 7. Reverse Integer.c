int reverse(int x)
{
    if(x < 10 && x > -10)
        return x;
    int flag = (x < 0) ? 1 : 0;
    x = (x < 0) ? -x : x;
   	long long tmp = 0;
   	while(x != 0)
   	{
        tmp = 10 * tmp + x % 10;
        x /= 10;
   	}
    if (tmp > INT_MAX || tmp < INT_MIN)
    {
        return 0;
    }
   	int res = (int)((flag == 1) ? -tmp : tmp);
    return res;
}