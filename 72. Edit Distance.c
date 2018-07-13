int min(int a, int b)
{
	return (a < b) ? a : b;
}
int minDistance(char* word1, char* word2)
{
	int m = strlen(word1);
	int n = strlen(word2);
	int d[m + 1][n + 1];
	for(int i = 0; i <= m; i++)
		d[i][0] = i;
	for(int i = 0; i <= n; i++)
		d[0][i] = i;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i == 1 && j == 1)
			{
				d[1][1] = (word1[0] == word2[0]) ? 0 : 1;
			}
			else if(word1[i - 1] == word2[j - 1])
			{
				d[i][j] = min(min(d[i - 1][j - 1], d[i][j - 1] + 1), d[i - 1][j] + 1);
			}
			else
			{
				d[i][j] = min(min(d[i - 1][j - 1], d[i][j - 1]), d[i - 1][j]) + 1;
			}
		}
	}
	return d[m][n];
}