#include <stdio.h>
#include <string.h>
#define MAX_ROWS 203

typedef char string[50]; //32 highest string length in data provided but for buffer just set 50 as size


inline
int
linearSearchString(string arrString[], string key, int n)
{
	for (int i = 0; i < n; i++)
		if (strcmp(arrString[i], key) == 0)
			return i;
	return -1;
}



inline
void
selectionSortString(string arrString[], int n)
{
	string temp;
	int max = 0;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
			if (strcmp(arrString[max], arrString[j]) < 0)
				max = j;

		if (max != i)
		{
			strcpy(temp, arrString[i]);
			strcpy(arrString[i], arrString[max]);
			strcpy(arrString[max], temp);
		}
	}
}

inline
void
selectionSortDouble(double arrDouble[], int n)
{
	double temp = 0;
	int max = 0;
	for (int i = 0; i < n - 1; i++)
	{
		max = i;
		for (int j = i + 1; j < n; j++)
			if (arrDouble[max] < arrDouble[j])
				max = j;

		if (max != i)
		{
			temp = arrDouble[i];
			arrDouble[i] = arrDouble[max];
			arrDouble[max] = temp;
		}
	}
}

inline
int
binarySearchString(string strArr[], string key, int n)
{
	int low = 0, high = n, mid;
	while (high >= low)
	{
		mid = low + (high - low) / 2;
		if (strcmp(strArr[mid], key) == 0)
			return mid;
		else if (strcmp(key, strArr[mid]) > 0)
			high = mid - 1;
		else if (strcmp(key, strArr[mid]) < 0)
			low = mid + 1;
	}
	return -1;
}

inline
void
printStringData(string location[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("str[%d]: %s", i, location[i]);
	}
}