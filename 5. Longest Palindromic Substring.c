// terrible alg, only beats 11% of the c submission
char* longestPalindrome(char* s)
{
    int front = 0, rear = 0;
    int start = 0, end = 0;
    int flag;
    int max = 1;
    char *begin = s;
    int length = (int)strlen(s);
    while(front < length)
    {
        for(rear = length - 1; rear > front; rear--)
        {
            if(rear - front + 1 <=  max || s[rear] != s[front])
            {
                continue;
            }
            start = front;
            end = rear;
            flag = 0;
            while(start < end)
            {
                if(s[start] != s[end])
                {
                    flag = 1;
                    break;
                }
                start++;
                end--;
            }
            if(flag == 1)
            {
                continue;
            }
            else
            {
                max = rear - front + 1;
                begin = s + front;
                break;
            }
        }
        front++;
    }
    char *res = (char*)malloc(sizeof(char) * (max + 1));
    for(int i = 0; i < max; i++)
    {
        res[i] = begin[i];
    }
    res[max] = '\0';
    return res;
}
