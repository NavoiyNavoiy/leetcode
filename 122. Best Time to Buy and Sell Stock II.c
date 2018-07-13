int maxProfit(int* prices, int pricesSize)
{
	int profit = 0;
	int buy = 0;
	bool flag = false;
	for(int i = 1; i < pricesSize; i++)
	{
		if(prices[i - 1] > prices[i] && flag)
		{
			profit += prices[i - 1] - buy;
			flag = false;
		}
		else if(prices[i - 1] < prices[i] && !flag)
		{
			buy = prices[i - 1];
			flag = true;
		}
	}
	if(flag)
	{
		profit += prices[pricesSize - 1] - buy;
	}
	return profit;
}