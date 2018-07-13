struct TreeNode** generateTrees(int n, int* returnSize)
{
    if(n == 0)
    {
        *returnSize = 0;
        return NULL;
    }
       
    
	int size[n + 1][n + 1];
	struct TreeNode*** trees = (struct TreeNode ***) malloc(sizeof(struct TreeNode **) * (n + 1) * (n + 1));

	for(int k = 0; k < n; k++)
	{
		for (int i = 1; i <= n - k; i++)
		{
			int j = i + k;
			int sizeTmp = 0;
			if (i == j)
			{
				sizeTmp = 1;
			}
			else
			{
				sizeTmp += size[i + 1][j] + size[i][j - 1];
				for (int t = i + 1; t < j; t++)
				{
					sizeTmp += size[i][t - 1] * size[t + 1][j];
				}
			}
			size[i][j] = sizeTmp;
			trees[i * (n + 1) + j] = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * sizeTmp);
			int cnt = 0;
			for (int t = i; t <= j; t++)
			{
				if (t - 1 < i)
				{
					if (t + 1 > j)
					{
						trees[i * (n + 1) + j][cnt] = (struct TreeNode *) malloc(sizeof(struct TreeNode));
						trees[i * (n + 1) + j][cnt]->val = t;
						trees[i * (n + 1) + j][cnt]->left = NULL;
						trees[i * (n + 1) + j][cnt]->right = NULL;
						cnt++;
					}
					else
					{
						for (int p = 0; p < size[t + 1][j]; p++)
						{
							trees[i * (n + 1) + j][cnt] = (struct TreeNode *) malloc(sizeof(struct TreeNode));
							trees[i * (n + 1) + j][cnt]->val = t;
							trees[i * (n + 1) + j][cnt]->left = NULL;
							trees[i * (n + 1) + j][cnt]->right = trees[(t + 1) * (n + 1) + j][p];
							cnt++;
						}
					}
				}
				else
				{
					for (int q = 0; q < size[i][t - 1]; q++)
					{
						if (t + 1 > j)
						{
							trees[i * (n + 1) + j][cnt] = (struct TreeNode *) malloc(sizeof(struct TreeNode));
							trees[i * (n + 1) + j][cnt]->val = t;
							trees[i * (n + 1) + j][cnt]->left = trees[i * (n + 1) + t - 1][q];
							trees[i * (n + 1) + j][cnt]->right = NULL;
							cnt++;
						}
						else
						{
							for (int m = 0; m < size[t + 1][j]; m++)
							{
								trees[i * (n + 1) + j][cnt] = (struct TreeNode *) malloc(sizeof(struct TreeNode));
								trees[i * (n + 1) + j][cnt]->val = t;
								trees[i * (n + 1) + j][cnt]->left = trees[i * (n + 1) + t - 1][q];
								trees[i * (n + 1) + j][cnt]->right = trees[(t + 1) * (n + 1) + j][m];
								cnt++;
							}
						}
					}
				}
			}
		}
	}
	*returnSize = size[1][n];
	return trees[1 * (n + 1) + n];

}