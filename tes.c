#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b)
{
	const int *da = (const int *)a;
	const int *db = (const int *)b;
	return *da > *db;
}

int comp_arr(int array1[], int size1, int array2[], int size2)
{
	qsort(array1, size1, sizeof(int), comp);
	qsort(array2, size2, sizeof(int), comp);

	for (int i = 0; i < size1; i++)
		printf("%d ", array1[i]);
	printf("\n");
	for (int i = 0; i < size2; i++)
		printf("%d ", array2[i]);
	printf("\n");

	int ans = 0;
	for (int i = 0, j = 0; i < size1 && j < size2; ) {
		if (array1[i] == array2[j]) {
			ans++;
			i++, j++;
		}
		else if (array1[i] < array2[j])
			i++;
		else j++;
	}
	return ans;
}

int main()
{
	int arr1[] = {-20, 61, 32, 77, -5, 80};
	int arr2[] = {80, -20, 34, 32, 56, -3, 58, 28};
	printf("%d\n", comp_arr(arr1, 6, arr2, 8));
}
