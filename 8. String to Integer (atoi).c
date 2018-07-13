int myAtoi(char* str)
{
    int i = 0;
    int res = 0;
    int sign = 1;
    while(str[i] != '\0')
    {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
        {
            i++;
            continue;
        }
        if(str[i] == '-' || str[i] == '+')
        {
            sign = (str[i] == '-') ? -1 : 1;
            i++;
        }
        while(str[i] >= '0' && str[i] <= '9')
        {
            res = res * 10 + str[i] - '0';
            if((res > INT_MAX / 10 && str[i + 1] >= '0' && str[i + 1] <= '9') || (res == INT_MAX / 10 && str[i + 1] > '7' && str[i + 1] <= '9'))
                return (sign == -1) ? INT_MIN : INT_MAX;
            i++;
        }
        break;
    }
    return sign * res;
}