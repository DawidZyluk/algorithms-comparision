#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

void Display(int* A, int n);
void DisplayCurrentData(double asc, double desc, double rand);
void DisplayCollectiveData(double data[8][3]);
bool isSorted(int* A, int n);
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
int* RandomArrayGenerator(int n);
int* AscendingArrayGenerator(int n);
int* DescendingArrayGenerator(int n);
int* CopyArray(int* A, int n);
double** Average(double** asc, double** desc, double** rand, int n);

int main()
{	
	clock_t start, end;
	double executionTime;

	int n = 1000;
	int populations = 5;

	/*do
	{
		cout << "Podaj liczbe elementow (minimum 100): "; cin >> n;
	} while (n < 100);
	int x;
	do
	{
		cout << "Podaj liczbe populacji: "; cin >> populations;
	} while (populations < 0 || populations > 100);*/
	
	double** ascendingTimes = new double* [8];
	for (int i = 0; i < 8; ++i) ascendingTimes[i] = new double[populations] {0};

	double** descendingTimes = new double* [8];
	for (int i = 0; i < 8; ++i) descendingTimes[i] = new double[populations] {0};

	double** randomTimes = new double* [8];
	for (int i = 0; i < 8; ++i) randomTimes[i] = new double[populations] {0};



	// Selection Sort
	cout << "     [0 of " << populations << " populations completed]";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = RandomArrayGenerator(n);
		int* backupRandom = CopyArray(randomArray, n);

		start = clock();
		SelectionSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[0][i] = executionTime;

		start = clock();
		SelectionSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[0][i] = executionTime;

		start = clock();
		SelectionSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[0][i] = executionTime;

		//Insertion sort
		ascendingArray = AscendingArrayGenerator(n);
		descendingArray = DescendingArrayGenerator(n);
		randomArray = CopyArray(backupRandom, n);

		start = clock();
		InsertionSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[1][i] = executionTime;

		start = clock();
		InsertionSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[1][i] = executionTime;

		start = clock();
		InsertionSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[1][i] = executionTime;
		
		////////////////////////////
		ascendingArray = AscendingArrayGenerator(n);
		descendingArray = DescendingArrayGenerator(n);
		randomArray = CopyArray(backupRandom, n);
		start = clock();
		BinaryInsertionSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[2][i] = executionTime;

		start = clock();
		BinaryInsertionSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[2][i] = executionTime;

		start = clock();
		BinaryInsertionSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[2][i] = executionTime;
		
		//////////////////////////
		ascendingArray = AscendingArrayGenerator(n);
		descendingArray = DescendingArrayGenerator(n);
		randomArray = CopyArray(backupRandom, n);
		start = clock();
		BubbleSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[3][i] = executionTime;

		start = clock();
		BubbleSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[3][i] = executionTime;

		start = clock();
		BubbleSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[3][i] = executionTime;

		//////////////////////////////
		ascendingArray = AscendingArrayGenerator(n);
		descendingArray = DescendingArrayGenerator(n);
		randomArray = CopyArray(backupRandom, n);
		start = clock();
		OptimizedBubbleSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[4][i] = executionTime;

		start = clock();
		OptimizedBubbleSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[4][i] = executionTime;

		start = clock();
		OptimizedBubbleSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[4][i] = executionTime;

		//////////////////////////////////
		ascendingArray = AscendingArrayGenerator(n);
		descendingArray = DescendingArrayGenerator(n);
		randomArray = CopyArray(backupRandom, n);
		start = clock();
		IterativeMergeSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[5][i] = executionTime;

		start = clock();
		IterativeMergeSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[5][i] = executionTime;

		start = clock();
		IterativeMergeSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[5][i] = executionTime;

		/////////////////////
		ascendingArray = AscendingArrayGenerator(n);
		descendingArray = DescendingArrayGenerator(n);
		randomArray = CopyArray(backupRandom, n);
		start = clock();
		RecursiveMergeSort(ascendingArray, 0, n - 1);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[6][i] = executionTime;

		start = clock();
		RecursiveMergeSort(descendingArray, 0, n - 1);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[6][i] = executionTime;

		start = clock();
		RecursiveMergeSort(randomArray, 0, n - 1);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[6][i] = executionTime;

		// Quick Sort
		ascendingArray = AscendingArrayGenerator(n);
		descendingArray = DescendingArrayGenerator(n);
		randomArray = CopyArray(backupRandom, n);
		if (n > 3200)
		{

			start = clock();
			OptimizedQuickSort(ascendingArray, 0, n - 1);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			ascendingTimes[7][i] = executionTime;

			start = clock();
			OptimizedQuickSort(descendingArray, 0, n - 1);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			descendingTimes[7][i] = executionTime;

			start = clock();
			OptimizedQuickSort(randomArray, 0, n - 1);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			randomTimes[7][i] = executionTime;
		}
		else
		{
			start = clock();
			QuickSort(ascendingArray, 0, n - 1);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			ascendingTimes[7][i] = executionTime;

			start = clock();
			QuickSort(descendingArray, 0, n - 1);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			descendingTimes[7][i] = executionTime;

			start = clock();
			QuickSort(randomArray, 0, n - 1);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			randomTimes[7][i] = executionTime;
		}

		cout << "\r     [" << i + 1 << " of " << populations << " populations completed]" << flush;
	}

	double** averageTimes = Average(ascendingTimes, descendingTimes, randomTimes, populations);

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

void DisplayCurrentData(double asc, double desc, double rand)
{
	cout << endl << "\n  Average time taken to sort the arrays: ";
	cout << endl << "  for ascending numbers = " << asc << "s";
	cout << endl << "  for descending numbers = " << desc << "s";
	cout << endl << "  for random numbers = " << rand << "s\n\n";
}

void DisplayCollectiveData(double data[8][3])
{
	//cout.setf(ios::fixed, ios::floatfield);
	cout << endl;
	cout << "\n                            --------------------------------------------------------";
	cout << "\n                            | Ascending values | Descending values | Random values |";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |      Selection Sort     | "; cout.width(12); cout << data[0][0]; cout.width(7); cout << " | "; cout.width(12); cout << data[0][1]; cout.width(8); cout << " | "; cout.width(9); cout << data[0][2]; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |      Insertion Sort     | "; cout.width(12); cout << data[1][0]; cout.width(7); cout << " | "; cout.width(12); cout << data[1][1]; cout.width(8); cout << " | "; cout.width(9); cout << data[1][2]; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |  Binary Insertion Sort  | "; cout.width(12); cout << data[2][0]; cout.width(7); cout << " | "; cout.width(12); cout << data[2][1]; cout.width(8); cout << " | "; cout.width(9); cout << data[2][2]; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |       Bubble Sort       | "; cout.width(12); cout << data[3][0]; cout.width(7); cout << " | "; cout.width(12); cout << data[3][1]; cout.width(8); cout << " | "; cout.width(9); cout << data[3][2]; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |  Optimized Bubble Sort  | "; cout.width(12); cout << data[4][0]; cout.width(7); cout << " | "; cout.width(12); cout << data[4][1]; cout.width(8); cout << " | "; cout.width(9); cout << data[4][2]; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |  Iterative Merge Sort   | "; cout.width(12); cout << data[5][0]; cout.width(7); cout << " | "; cout.width(12); cout << data[5][1]; cout.width(8); cout << " | "; cout.width(9); cout << data[5][2]; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |  Recursive Merge Sort   | "; cout.width(12); cout << data[6][0]; cout.width(7); cout << " | "; cout.width(12); cout << data[6][1]; cout.width(8); cout << " | "; cout.width(9); cout << data[6][2]; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |        Quick Sort       | "; cout.width(12); cout << data[7][0]; cout.width(7); cout << " | "; cout.width(12); cout << data[7][1]; cout.width(8); cout << " | "; cout.width(9); cout << data[7][2]; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
}

bool isSorted(int* A, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (A[i] > A[i + 1])
			return false;
	}
	return true;
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

double** Average(double** asc, double** desc, double** rand, int pop)
{
	double** avg = new double* [8];
	for (int i = 0; i < 8; ++i) avg[i] = new double[3];

	for (int i = 0; i < 8; i++)
	{
		double sumAsc = 0;
		double sumDesc = 0;
		double sumRand = 0;
		for (int j = 0; j < pop; j++)
		{
			sumAsc += asc[i][j];
			sumDesc += desc[i][j];
			sumRand += rand[i][j];
		}
		avg[i][0] = sumAsc / pop;
		avg[i][1] = sumDesc / pop;
		avg[i][2] = sumRand / pop;
	}
	return avg;
}

