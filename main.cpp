#include <iostream>

using namespace std;

void Display(int* A, int n);
void Swap(int& x, int& y);
void SelectionSort(int* A, int n);
void BubbleSort(int* A, int n);
void OptimizedBubbleSort(int* A, int n);
void BinaryInsertionSort(int* A, int n);
void InsertionSort(int* A, int n);
void Merge(int* A, int low, int mid, int high);
void IterativeMergeSort(int* A, int n);
void RecursiveMergeSort(int* A, int low, int high);
int Partition(int* A, int low, int high);
void QuickSort(int* A, int low, int high);
int* RandomArray(int n);
int* AscendingArray(int n);
int* DescendingArray(int n);

// TODO: 
// Funkcja do tworzenia tablicy losowej, min->max i max->min
// Add RandomArray()

int main()
{
	int n = 100;
	int* A = AscendingArray(n);
	
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

void Swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void SelectionSort(int* A, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (A[j] < A[min]) min = j;
		Swap(A[i], A[min]);
	}
}

void BubbleSort(int* A, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (A[j] > A[j + 1]) Swap(A[j], A[j + 1]);
}

void OptimizedBubbleSort(int* A, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		bool swaped = false;
		for (int j = 0; j < n - i - 1; j++)
			if (A[j] > A[j + 1])
			{
				Swap(A[j], A[j + 1]);
				swaped = true;
			}
		if (swaped == false) break;
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
	for (int l = low; l < high + 1; l++) A[l] = B[l];
}

void IterativeMergeSort(int* A, int n)
{
	int p;
	for (p = 2; p <= n; p *= 2)
	{
		for (int i = 0; i + p - 1 < n; i += p)
		{
			int low = i;
			int high = i + p - 1;
			int mid = (low + high) / 2;
			Merge(A, low, mid, high);
		}
	}
	if (p / 2 < n) Merge(A, 0, p / 2 - 1, n - 1);
}

void RecursiveMergeSort(int* A, int low, int high)
{
	if (low < high)
	{
		int mid = low + (high - low) / 2;
		RecursiveMergeSort(A, low, mid);
		RecursiveMergeSort(A, mid+1, high);
		Merge(A, low, mid, high);
	}
}

int Partition(int* A, int low, int high)
{
	int pivot = A[low];
	int i = low + 1;
	int j = high;

	while (true)
	{
		while (A[i] <= pivot && i <= j) i++;
		while (A[j] >= pivot && j >= i) j--;
		if (j < i) break;
		else Swap(A[i], A[j]);
		Display(A, high + 1);
	}
	Swap(A[low], A[j]);
	return j;
}

void QuickSort(int* A, int low, int high)
{
	if (low < high)
	{
		int p = Partition(A, low, high);
		QuickSort(A, low, p - 1);
		QuickSort(A, p + 1, high);
	}
}

int* RandomArray(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = (rand() % 100);

	return arr;
}

int* AscendingArray(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = i+1;

	return arr;
}

int* DescendingArray(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = n - i;

	return arr;
}
