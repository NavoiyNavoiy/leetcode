/*
i: )
i-1: ( 2 + [i-2]
i-1: ) [i-1-[i-1]] is ( then 2 + [i-1] + [i-1-[i-1]-1]
*/

int longestValidParentheses(char* s)
{
	int n = strlen(s);
	if(n == 0)
	{
		return 0;
	}
    int a[n];
    int m[n];
    int max = 0;
    m[0] = 0;
    for(int i = 1; i < n; i++)
    {
    	if(s[i] == '(')
    	{
    		m[i] = 0;
    	}
    	else
    	{
    		if(s[i - 1] == '(')
    		{
    			if(i - 2 >= 0)
    			{
    				m[i] = 2 + m[i - 2];
    			}
    			else
    			{
    				m[i] = 2;
    			}
    		}
    		else
    		{
    			if(i - 1 - m[i - 1] >= 0 && s[i - 1 - m[i - 1]] == '(')
    			{
    				m[i] = 2 + m[i - 1];
                    if(i - 1 - m[i - 1] - 1 >= 0)
    				{
    					m[i] += m[i - 1 - m[i - 1] - 1];
    				}
    			}
    			else
    			{
    				m[i] = 0;
    			}
    		}
    	}
    	if(m[i] > max)
    	{
    		max = m[i];
    	}
    }
    return max;
}
