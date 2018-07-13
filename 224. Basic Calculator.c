int calculateGroup(char* s, int* tail, int credit)
{
    int value = 0, ptr = 0, operate = 1;
    int next;
    while(1)
    {
        int integer = 0;
        if(s[ptr] >= '0' && s[ptr] <= '9')
        {
            while(s[ptr] >= '0' && s[ptr] <= '9')
            {
                integer = integer * 10 + (s[ptr] - '0');
                ptr++;
            }
            ptr--;
            if(operate == 1)
            {
                value += integer;
            }
            else
            {
                value -= integer;
            }
        }
        else if(s[ptr] == '+')
        {
            operate = 1;
        }
        else if(s[ptr] == '-')
        {
            operate = 2;
        }
        else if(s[ptr] == '(')
        {
            int k = calculateGroup(s + (ptr + 1), &next, -1);
            if(operate == 1)
            {
                value += k;
            }
            else
            {
                value -= k;
            }
            ptr += next;
        }
        else if(s[ptr] == ')' || s[ptr] == 0)
        {
            credit++;
        }
        if(credit == 0)
        {
            break;
        }
        ptr++;
    }
    *tail = ptr + 1;
    return value;
}

int calculate(char* s)
{
    int a;
    return calculateGroup(s, &a, -1);
}