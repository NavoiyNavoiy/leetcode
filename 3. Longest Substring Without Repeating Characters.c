int lengthOfLongestSubstring(char* s)
{
	int front = 1, rear = -1;
    int tmpcnt = 1, max = 1;
    int cursor = 0, length = strlen(s);
    if(length == 0)
        return 0;
	while(front < length)
	{	
		cursor = front - 1;
		while(cursor > rear && s[cursor] != s[front])
			cursor--;
		tmpcnt -= cursor - rear - 1;
		rear = cursor;
		front++;
		if(tmpcnt > max)
			max = tmpcnt;
	}
	return max;
}