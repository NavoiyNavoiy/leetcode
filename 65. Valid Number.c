bool isNumber(char* s)
{
    int front = 0, tail = strlen(s) - 1;
    bool flag = false;
    while(s[front] == ' ')
    {
        front++;
    }
    while(s[tail] == ' ')
    {
        tail--;
    }
    if(front > tail)
    {
        return false;
    }
    if(s[front] == '-' || s[front] == '+')
    {
        front++;
    }
    while(s[front] >= '0' && s[front] <= '9' && front <= tail)
    {
        flag = true;
        front++;
    }
    if(front > tail)
    {
        return true;
    }
    else if(s[front] == '.')
    {
        front++;
        while(s[front] >= '0' && s[front] <= '9' && front <= tail)
        {
            flag = true;
            front++;
        }
        if(front > tail && flag == true)
        {
            return true;
        }
        else if((s[front] == 'e' || s[front] == 'E') && flag == true)
        {
            front++;
            if(s[front] == '-' || s[front] == '+')
            {
                front++;
            }
            if(s[front] < '0' || s[front] > '9')
            {
                return false;
            }
            while(s[front] >= '0' && s[front] <= '9' && front <= tail)
            {
                front++;   
            }
            if(front > tail)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if(s[front] == 'e' || s[front] == 'E')
    {
        front++;
        if(s[front] == '-' || s[front] == '+')
        {
            front++;
        }
        if(flag == false || s[front] < '0' || s[front] > '9')
        {
            return false;
        }
        while(s[front] >= '0' && s[front] <= '9' && front <= tail)
        {
            front++;   
        }
        if(front > tail)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}