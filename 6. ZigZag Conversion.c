char* convert(char* s, int numRows) {
    if(numRows == 1)
    {
        return s;
    }
    int pos = 0;
    int length = 0;
    int i = 0;
    int turn = 2 * numRows - 2;
    while(s[pos] != '\0')
    {
        pos++;
    }
    length = pos - 1;
    char *res = (char*)malloc((length + 2) * sizeof(char));
    pos = 0;
    while(pos <= length)
    {
        res[i++] = s[pos];
        pos += turn;
    }
    for(int t = 1; t < numRows - 1; t++)
    {
        pos = t;
        while(pos <= length)
        {
            res[i++] = s[pos];
            if(pos - 2 * t + turn <= length)
            {
                res[i++] = s[pos - 2 * t + turn];
            }
            pos += turn;
        }
    }
    pos = numRows - 1;
    while(pos <= length)
    {
        res[i++] = s[pos];
        pos += turn;
    }
    res[length + 1] = '\0';
    return res;
}