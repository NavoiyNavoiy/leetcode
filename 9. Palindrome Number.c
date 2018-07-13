// terrible alg!!!!
bool isPalindrome(int x)
{
    if(x < 0)
        return false;
    int pow = 10;
    int tail, head;
    if(x < 10)
        return true;
    while((x / 10) / pow != 0)
    {
        pow *= 10;
    }
    while(pow >= 1)
    {
        tail = x / pow;
        head = x % 10;
        if(tail != head)
        {
            return false;
        }
        x = (x % pow) / 10;
        pow /= 100;
    }
    return true;
}