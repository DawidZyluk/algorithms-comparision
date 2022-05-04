#include <iostream>

using namespace std;

void Display(int* A, int n);
void SelectionSort(int* A, int n);
void BubbleSort(int* A, int n);
void BinaryInsertionSort(int* A, int n);
void InsertionSort(int* A, int n);
void Merge(int* A, int l, int mid, int h);

int main()
{
	int A[] = { 2,5,8,12,3,6,7,10 };
	int n = size(A);

	Display(A, n);
	Merge(A, 0, 3,7);
	Display(A, n);
}

void Display(int* A, int n)
{
	cout << "[ ";
	for (int i = 0; i < n; i++)
	{
		cout << A[i];
		if (i < n - 1) cout << ", ";
	}
	cout << " ]" << endl;
}

void SelectionSort(int* A, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[min]) min = j;
		int temp = A[i];
		A[i] = A[min];
		A[min] = temp;
	}
}

void BubbleSort(int* A, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (A[i] > A[j])
			{
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}

void BinaryInsertionSort(int* A, int n)
{
	for (int j = n - 2; j >= 0; j--)		
	{
		int x = A[j];						
		int p = j;						
		int k = n;						
		while (k - p > 1)				 
		{
			int i = (p + k) / 2;		
			if (x > A[i]) p = i;					
			else k = i;					
		}								
		for (int i = j; i < k - 1; i++)	A[i] = A[i + 1];			
		A[p] = x;						
	}
}

void InsertionSort(int* A, int n) 
{
	for (int j = n - 2; j >= 0; j--)
	{
		int x = A[j];  
		int i = j + 1;  
		while (i < n && x > A[i])
		{
			A[i - 1] = A[i];  
			i++;
		}
		A[i - 1] = x;  
	}
}

void Merge(int* A, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int k = low;
	int* B = new int[high+1];
	while (i <= mid && j <= high)
	{
		if (A[i] < A[j]) B[k++] = A[i++];
		else B[k++] = A[j++];
	}
	while (i <= mid) B[k++] = A[i++];
	while (j <= high) B[k++] = A[j++];
	for (int l = 0; l < high + 1; l++) A[l] = B[l];
}
