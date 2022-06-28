#include<stdio.h>
#include<stdlib.h>
#define inf  99999
int matrixMulChain(int arr[], int n)
{
	int min[n][n];
	int i, j, k, l, q;
	for (i = 1; i < n; i++)
		min[i][i] = 0;
	for (l = 2; l < n; l++)
	{
		for (i = 1; i < n - l + 1; i++)
		{
			j = i + l - 1;
			min[i][j] = inf;
			for (k = i; k <= j - 1; k++)
			{
			       q =min[i][k] + min[k + 1][j]
					+ arr[i - 1] * arr[k] * arr[j];
				if (q < min[i][j])
					min[i][j] = q;
			}
		}
	}
	return min[1][n - 1];
}
int main()
{
  int n;
  printf("Enter the size of the array\n");
  scanf("%d",&n);
  int a[n];
  printf("Enter the array elements\n");
  for(int i=0;i<n;i++){
  scanf("%d",&a[i]);
}
  printf("The minimum number of multiplications is %d ",matrixMulChain(a, n));
	return 0;
}
