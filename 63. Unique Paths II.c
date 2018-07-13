int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize)
{
	int numOfPath[obstacleGridRowSize][obstacleGridColSize];
	for(int i = 0; i < obstacleGridRowSize; i++)
	{
		for(int j = 0; j < obstacleGridColSize; j++)
		{
			if(obstacleGrid[i][j] == 1)
			{
				numOfPath[i][j] = 0;
			}
			else if(i == 0 && j == 0)
			{
				numOfPath[0][0] = 1;
			}
			else if(i == 0)
			{
				numOfPath[i][j] = numOfPath[i][j - 1];
			}
			else if(j == 0)
			{
				numOfPath[i][j] = numOfPath[i - 1][j];
			}
			else
			{
				numOfPath[i][j] = numOfPath[i][j - 1] + numOfPath[i - 1][j];
			}
		}
	}
	return numOfPath[obstacleGridRowSize - 1][obstacleGridColSize - 1];
    
}