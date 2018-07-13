int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int carry = 1;
    for(int i = digitsSize - 1; i >= 0; i--)
    {
        if(digits[i] + carry > 9)
        {
            digits[i] = (digits[i] + carry) % 10;
            carry = 1;
        }
        else
        {
            digits[i] = (digits[i] + carry) % 10;
            carry = 0;
        }
    }
    if(carry == 1)
    {
        *returnSize = digitsSize + 1;
        int* a = (int*)malloc(sizeof(int) * (*returnSize));
        a[0] = 1;
        for(int i = 0; i < digitsSize; i++)
        {
            a[i + 1] = digits[i];
        }
        return a;
    }
    *returnSize = digitsSize;
    return digits;
}