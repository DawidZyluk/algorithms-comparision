#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

void Display(int* A, int n);
void DisplayData(double asc, double desc, double rand);
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
void OptimizedQuickSort(int* A, int low, int high);
void EducationalQuickSort(int* A, int low, int high);
int* RandomArrayGenerator(int n);
int* AscendingArrayGenerator(int n);
int* DescendingArrayGenerator(int n);
int* CopyArray(int* A, int n);
double Average(double* A, int n);

// Pytania:
// Jak powinna wygl¹daæ funkcja sprawdzaj¹ca?

// new: dodalem menu, 

int main()
{	
	fstream OutputData;
	OutputData.open("OutputData.txt", ios::out);

	clock_t start, end;
	double executionTime;

	int begin = 1000;
	int n = 5000;
	int krok = 1000;
	int* randomArray = RandomArrayGenerator(n);
	int* backupRandom = CopyArray(randomArray, n);

	const int populations = 10;
	double ascendingTimes[populations];
	double averageAscendingTime;
	double descendingTimes[populations];
	double averageDescendingTime;
	double randomTimes[populations];
	double averageRandomTime;

	do
	{
		cout << "Podaj liczbe elementow (minimum 100): "; cin >> n;
	} while (n < 100);

	int wybor = 0;
	cout << "Co chcesz zrobic?: \n";
	cout << "1. Przeprowadzic symulacje dla podanej liczby elementow\n";
	cout << "2. Zebrac dane dla kolejno rosnacej liczby elementow\n";
	do
	{
		cout << "Twoj wybor (1 albo 2): "; cin >> wybor;
	} while (wybor != 1 && wybor != 2);

	if (wybor == 2)
	{
		do
		{
			cout << "Podaj od jakiej liczby elementow chcesz rozpoczac (minimum 2): "; cin >> begin;
		} while (begin < 1 && begin > n);
		do
		{
			cout << "Podaj od rozmiar kroku: "; cin >> krok;
		} while (krok < 0 && krok > n);
	}
	else
	{
		begin = krok = n;
	}
	
	for (int j = begin; j <= n; j += krok)
	{
		// Selection Sort
		if (wybor == 1) cout << "\n-------------- Selection Sort -------------\n";
		for (int i = 0; i < populations; i++)
		{
			int* ascendingArray = AscendingArrayGenerator(n);
			int* descendingArray = DescendingArrayGenerator(n);
			int* randomArray = CopyArray(backupRandom, n);

			start = clock();
			SelectionSort(ascendingArray, n);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			ascendingTimes[i] = executionTime;

			start = clock();
			SelectionSort(descendingArray, n);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			descendingTimes[i] = executionTime;

			start = clock();
			SelectionSort(randomArray, n);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			randomTimes[i] = executionTime;

			if (wybor == 1) cout << "\r[" << i + 1 << " of " << populations << " populations completed]" << flush;
		}
		averageAscendingTime = Average(ascendingTimes, populations);
		averageDescendingTime = Average(descendingTimes, populations);
		averageRandomTime = Average(randomTimes, populations);
		if(wybor == 1) DisplayData(averageAscendingTime, averageDescendingTime, averageRandomTime);
	}

	return 0;

	

	// Binary Insertion Sort
	cout << "---------- Binary Insertion Sort ----------\n";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = CopyArray(backupRandom, n);

		start = clock();
		BinaryInsertionSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[i] = executionTime;

		start = clock();
		BinaryInsertionSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[i] = executionTime;

		start = clock();
		BinaryInsertionSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[i] = executionTime;

		cout << "\r[" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	averageAscendingTime = Average(ascendingTimes, populations);
	averageDescendingTime = Average(descendingTimes, populations);
	averageRandomTime = Average(randomTimes, populations);
	DisplayData(averageAscendingTime, averageDescendingTime, averageRandomTime);

	// Insertion Sort
	cout << "---------- Insertion Sort ----------\n";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = CopyArray(backupRandom, n);

		start = clock();
		InsertionSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[i] = executionTime;

		start = clock();
		InsertionSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[i] = executionTime;

		start = clock();
		InsertionSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[i] = executionTime;

		cout << "\r[" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	averageAscendingTime = Average(ascendingTimes, populations);
	averageDescendingTime = Average(descendingTimes, populations);
	averageRandomTime = Average(randomTimes, populations);
	DisplayData(averageAscendingTime, averageDescendingTime, averageRandomTime);

	// Bubble Sort
	cout << "\n--------------- Bubble Sort ---------------\n";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = CopyArray(backupRandom, n);

		start = clock();
		BubbleSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[i] = executionTime;

		start = clock();
		BubbleSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[i] = executionTime;

		start = clock();
		BubbleSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[i] = executionTime;

		cout << "\r[" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	averageAscendingTime = Average(ascendingTimes, populations);
	averageDescendingTime = Average(descendingTimes, populations);
	averageRandomTime = Average(randomTimes, populations);
	DisplayData(averageAscendingTime, averageDescendingTime, averageRandomTime);

	// Iterative MergeSort
	cout << "---------- Iterative Merge Sort ----------\n";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = CopyArray(backupRandom, n);

		start = clock();
		IterativeMergeSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[i] = executionTime;

		start = clock();
		IterativeMergeSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[i] = executionTime;

		start = clock();
		IterativeMergeSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[i] = executionTime;

		cout << "\r[" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	averageAscendingTime = Average(ascendingTimes, populations);
	averageDescendingTime = Average(descendingTimes, populations);
	averageRandomTime = Average(randomTimes, populations);
	DisplayData(averageAscendingTime, averageDescendingTime, averageRandomTime);

	// Recursive MergeSort
	cout << "---------- Recursive Merge Sort ----------\n";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = CopyArray(backupRandom, n);

		start = clock();
		RecursiveMergeSort(ascendingArray, 0, n - 1);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[i] = executionTime;

		start = clock();
		RecursiveMergeSort(descendingArray, 0, n - 1);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[i] = executionTime;

		start = clock();
		RecursiveMergeSort(randomArray, 0, n - 1);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[i] = executionTime;

		cout << "\r[" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	averageAscendingTime = Average(ascendingTimes, populations);
	averageDescendingTime = Average(descendingTimes, populations);
	averageRandomTime = Average(randomTimes, populations);
	DisplayData(averageAscendingTime, averageDescendingTime, averageRandomTime);

	// Quick Sort
	cout << "---------- Quick Sort ----------\n";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = CopyArray(backupRandom, n);

		start = clock();
		OptimizedQuickSort(ascendingArray, 0, n - 1);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[i] = executionTime;

		start = clock();
		OptimizedQuickSort(descendingArray, 0, n - 1);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[i] = executionTime;

		start = clock();
		OptimizedQuickSort(randomArray, 0, n - 1);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[i] = executionTime;

		cout << "\r[" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	averageAscendingTime = Average(ascendingTimes, populations);
	averageDescendingTime = Average(descendingTimes, populations);
	averageRandomTime = Average(randomTimes, populations);
	DisplayData(averageAscendingTime, averageDescendingTime, averageRandomTime);

	OutputData.close();
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

void DisplayData(double asc, double desc, double rand)
{
	cout << endl << "\n  Average time taken to sort the arrays: ";
	cout << endl << "  for ascending numbers = " << asc << "s";
	cout << endl << "  for descending numbers = " << desc << "s";
	cout << endl << "  for random numbers = " << rand << "s\n\n";
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
	}
	Swap(A[low], A[j]); 
	return j;
}

void QuickSort(int* A, int low, int high)
{
	if (low < high)
	{
		int mid = Partition(A, low, high);
		QuickSort(A, low, mid - 1);
		QuickSort(A, mid + 1, high);
	}
}

void OptimizedQuickSort(int* A, int low, int high)
{
	if (low < high)
	{
		int mid = Partition(A, low, high);
		if (mid < (low + high) / 2)
		{
			QuickSort(A, low, mid - 1);
		}
		else
		{
			QuickSort(A, mid + 1, high);
		}
	}
}

void EducationalQuickSort(int* A, int low, int high)
{
	Start:
	if (low < high)
	{
		int mid = Partition(A, low, high);
		if (mid < (low + high) / 2)
		{ 
			QuickSort(A, low, mid - 1); 
			low = mid + 1;
			goto Start;              
		}
		else
		{ 
			QuickSort(A, mid + 1, high); 
			high = mid - 1; 
			goto Start;              
		}
	}
}

int* RandomArrayGenerator(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = (rand() % n);

	return arr;
}

int* AscendingArrayGenerator(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = i+1;

	return arr;
}

int* DescendingArrayGenerator(int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++) arr[i] = n - i;

	return arr;
}

int* CopyArray(int* A, int n)
{
	int* res = new int[n];
	for (int i = 0; i < n; i++) res[i] = A[i];

	return res;
}

double Average(double* A, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++) sum += A[i];
	return sum;
}
