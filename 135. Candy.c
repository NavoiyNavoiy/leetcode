int max(int a, int b)
{
	return (a > b) ? a : b;
}
int candy(int* ratings, int ratingsSize)
{
	int candy = 1, sum = 0, record = -1;
	bool flag1 = true, flag2 = true;
	for(int i = 0; i < ratingsSize - 1; i++)
	{
		if(flag1 && ratings[i] < ratings[i + 1])
		{
			sum += candy;
            candy++;
            flag2 = false;
		}
		else if(flag2 && ratings[i] > ratings[i + 1])
		{
			sum += candy;
            candy++;
            flag1 = false;
		}
		else if(flag1 && ratings[i] > ratings[i + 1])
		{
			flag1 = false;
			flag2 = true;
			record = candy;
			candy = 1;
		}
		else if(flag2 && ratings[i] < ratings[i + 1])
		{
			flag2 = false;
			flag1 = true;
			sum += candy;
			candy++;
            if(record > 0)
			    sum += max(candy, record);
			record = -1;
			candy = 2;
		}
		else
		{
            sum += candy;
			candy++;
			if(record > 0)
				sum += max(candy, record);
			record = -1;
            flag1 = true;
            flag2 = true;
            candy = 1;
            record = -1;
		}
	}
    sum += candy;
	candy++;
	if(record > 0)
		sum += max(candy, record);
    return sum;
}