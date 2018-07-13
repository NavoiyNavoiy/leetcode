int maxArea(int* height, int heightSize)
{
    int cnt = heightSize;
    int left = 0, right = heightSize - 1;
    int max = 0, v = 0;
    while(cnt >= 2)
    {
        cnt--;
        if(height[left] > height[right])
    	{
    		v = height[right] * cnt;
    		right--;
    	}
    	else
    	{
    		v = height[left] * cnt;
    		left++;
    	}
    	if(v > max)
    	{
    		max = v;
    	}
    }
    return max;
}