int min(int a, int b)
{
	return (a < b) ? a : b;
}
int minPathSum(int** grid, int gridRowSize, int gridColSize)
{
	int numOfPath[gridRowSize][gridColSize];
	for(int i = 0; i < gridRowSize; i++)
	{
		for(int j = 0; j < gridColSize; j++)
		{
			if(i == 0 && j == 0)
			{
				numOfPath[0][0] = grid[0][0];
			}
			else if(i == 0)
			{
				numOfPath[i][j] = numOfPath[i][j - 1] + grid[i][j];
			}
			else if(j == 0)
			{
				numOfPath[i][j] = numOfPath[i - 1][j] + grid[i][j];
			}
			else
			{
				numOfPath[i][j] = min(numOfPath[i][j - 1], numOfPath[i - 1][j]) + grid[i][j];
			}
		}
	}
	return numOfPath[gridRowSize - 1][gridColSize - 1];
    
}