#include <iostream>

using namespace std;

void Display(int* arr, int n);
void SelectionSort(int* arr, int n);
void BubbleSort(int* arr, int n);
void BinaryInsertionSort(int* A, int n);
void InsertionSort(int* A, int n);

int main()
{
	int tablica[] = { 6,-2,0,3,5,4,2,5,1 };
	int n = size(tablica);

	Display(tablica, n);
	BubbleSort(tablica, n);
	Display(tablica, n);
}

void Display(int* arr, int n)
{
	cout << "[ ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i < n - 1) cout << ", ";
	}
	cout << " ]" << endl;
}

void SelectionSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[min]) min = j;
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

void BubbleSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
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