int jump(int* nums, int numsSize)
{
    int test[numsSize];
    test[numsSize - 1] = 0;
    for(int i = numsSize - 2; i >= 0; i--)
    {
        test[i] = 1 << 15;
        for(int j = (nums[i] < numsSize - i - 1) ? nums[i] : numsSize - i - 1; j > 0; j--)
        {
            int min = 1 << 15;
            if(test[i + j] < test[i])
            {
                test[i] = test[i + j] + 1;
            }
        }
    }
    return test[0];
}