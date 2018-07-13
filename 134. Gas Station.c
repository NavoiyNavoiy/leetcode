int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int remain[gasSize];
    for(int i = 0; i < gasSize; i++)
    {
    	remain[i] = gas[i] - cost[i];
    }

    int index = 0;
    int tank = 0;
    bool flag1 = false, flag2 = true;
    while(flag2)
    {
        int i;
    	for(i = 0; i < gasSize; i++)
    	{
    		tank += remain[(i + index) % gasSize];
    		if(i + index + 1 == gasSize)
    		{
    			flag2 = false;
    		}
    		if(tank < 0)
    		{
    			index = (i + index + 1) % gasSize;
    			tank = 0;
    			break;
    		}
    	}
    	if(i == gasSize)
    	{
    		flag1 = true;
            flag2 = false;
    	}
    }
    if(flag1)
    {
    	return index;
    }
    else
    {
    	return -1;
    }
}