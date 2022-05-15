#include <iostream>

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
double Average(double* A, int n);

int main()
{	
	clock_t start, end, program_start, program_end;
	double executionTime;

	int n = 3000;
	int populations = 100;
	int* randomArray = RandomArrayGenerator(n);
	int* backupRandom = CopyArray(randomArray, n);

	/*do
	{
		cout << "Podaj liczbe elementow (minimum 100): "; cin >> n;
	} while (n < 100);
	int x;
	do
	{
		cout << "Podaj liczbe populacji: "; cin >> populations;
	} while (populations < 0 || populations > 100);*/
	
	double* ascendingTimes = new double[populations];
	double* descendingTimes = new double[populations];
	double* randomTimes = new double[populations];
	double collectiveData[8][3]{ 0 }; 

	program_start = clock();
	// Selection Sort
	cout << "\n------------- Selection Sort --------------\n";
	cout << "     [0 of " << populations << " populations completed]";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = RandomArrayGenerator(n);

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

		cout << "\r     [" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	delete[] ascendingTimes, descendingTimes, randomTimes;

	collectiveData[0][0] = Average(ascendingTimes, populations);
	collectiveData[0][1] = Average(descendingTimes, populations);
	collectiveData[0][2] = Average(randomTimes, populations);
	//DisplayCurrentData(collectiveData[0][0], collectiveData[0][1], collectiveData[0][2]);

	// InsertionSort
	cout << "\n\n-------------- Insertion Sort -------------\n";
	cout << "     [0 of " << populations << " populations completed]";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = RandomArrayGenerator(n);

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

		cout << "\r     [" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	delete[] ascendingTimes, descendingTimes, randomTimes;

	collectiveData[4][0] = Average(ascendingTimes, populations);
	collectiveData[4][1] = Average(descendingTimes, populations);
	collectiveData[4][2] = Average(randomTimes, populations);
	//DisplayCurrentData(collectiveData[4][0], collectiveData[4][1], collectiveData[4][2]);

	// BinaryInsertionSort
	cout << "\n\n---------- Binary Insertion Sort ----------\n";
	cout << "     [0 of " << populations << " populations completed]";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = RandomArrayGenerator(n);

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

		cout << "\r     [" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	delete[] ascendingTimes, descendingTimes, randomTimes;

	collectiveData[3][0] = Average(ascendingTimes, populations);
	collectiveData[3][1] = Average(descendingTimes, populations);
	collectiveData[3][2] = Average(randomTimes, populations);
	//DisplayCurrentData(collectiveData[3][0], collectiveData[3][1], collectiveData[3][2]);

	// Bubble Sort
	cout << "\n\n--------------- Bubble Sort ---------------\n";
	cout << "     [0 of " << populations << " populations completed]";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = RandomArrayGenerator(n);

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

		cout << "\r     [" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	delete[] ascendingTimes, descendingTimes, randomTimes;

	collectiveData[1][0] = Average(ascendingTimes, populations);
	collectiveData[1][1] = Average(descendingTimes, populations);
	collectiveData[1][2] = Average(randomTimes, populations);
	//DisplayCurrentData(collectiveData[1][0], collectiveData[1][1], collectiveData[1][2]);

	// Optimized Bubble Sort
	cout << "\n\n---------- Optimized Bubble Sort ----------\n";
	cout << "     [0 of " << populations << " populations completed]";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = RandomArrayGenerator(n);

		start = clock();
		OptimizedBubbleSort(ascendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		ascendingTimes[i] = executionTime;

		start = clock();
		OptimizedBubbleSort(descendingArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		descendingTimes[i] = executionTime;

		start = clock();
		OptimizedBubbleSort(randomArray, n);
		end = clock();
		executionTime = double(end - start) / CLOCKS_PER_SEC;
		randomTimes[i] = executionTime;

		cout << "\r     [" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	delete[] ascendingTimes, descendingTimes, randomTimes;

	collectiveData[2][0] = Average(ascendingTimes, populations);
	collectiveData[2][1] = Average(descendingTimes, populations);
	collectiveData[2][2] = Average(randomTimes, populations);
	//DisplayCurrentData(collectiveData[2][0], collectiveData[2][1], collectiveData[2][2]);

	// IterativeMergeSort
	cout << "\n\n---------- Iterative Merge Sort -----------\n";
	cout << "     [0 of " << populations << " populations completed]";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = RandomArrayGenerator(n);

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

		cout << "\r     [" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	delete[] ascendingTimes, descendingTimes, randomTimes;

	collectiveData[5][0] = Average(ascendingTimes, populations);
	collectiveData[5][1] = Average(descendingTimes, populations);
	collectiveData[5][2] = Average(randomTimes, populations);
	//DisplayCurrentData(collectiveData[5][0], collectiveData[5][1], collectiveData[5][2]);

	// RecursiveMergeSort
	cout << "\n\n---------- Recursive Merge Sort ----------\n";
	cout << "     [0 of " << populations << " populations completed]";
	for (int i = 0; i < populations; i++)
	{
		int* ascendingArray = AscendingArrayGenerator(n);
		int* descendingArray = DescendingArrayGenerator(n);
		int* randomArray = RandomArrayGenerator(n);

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

		cout << "\r     [" << i + 1 << " of " << populations << " populations completed]" << flush;
	}
	delete[] ascendingTimes, descendingTimes, randomTimes;

	collectiveData[6][0] = Average(ascendingTimes, populations);
	collectiveData[6][1] = Average(descendingTimes, populations);
	collectiveData[6][2] = Average(randomTimes, populations);
	//DisplayCurrentData(collectiveData[6][0], collectiveData[6][1], collectiveData[6][2]);

	// Quick Sort
	if (n > 3200)
	{
		cout << "\n\n--------------- Quick Sort ----------------\n";
		cout << "     [0 of " << populations << " populations completed]";
		for (int i = 0; i < populations; i++)
		{
			int* ascendingArray = AscendingArrayGenerator(n);
			int* descendingArray = DescendingArrayGenerator(n);
			int* randomArray = RandomArrayGenerator(n);

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

			cout << "\r     [" << i + 1 << " of " << populations << " populations completed]" << flush;
		}
		delete[] ascendingTimes, descendingTimes, randomTimes;

		collectiveData[7][0] = Average(ascendingTimes, populations);
		collectiveData[7][1] = Average(descendingTimes, populations);
		collectiveData[7][2] = Average(randomTimes, populations);
		//DisplayCurrentData(collectiveData[7][0], collectiveData[7][1], collectiveData[7][2]);
	}
	else
	{
		cout << "\n\n--------------- Quick Sort ----------------\n";
		cout << "     [0 of " << populations << " populations completed]";
		for (int i = 0; i < populations; i++)
		{
			int* ascendingArray = AscendingArrayGenerator(n);
			int* descendingArray = DescendingArrayGenerator(n);
			int* randomArray = RandomArrayGenerator(n);

			start = clock();
			QuickSort(ascendingArray, 0, n - 1);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			ascendingTimes[i] = executionTime;

			start = clock();
			QuickSort(descendingArray, 0, n - 1);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			descendingTimes[i] = executionTime;

			start = clock();
			QuickSort(randomArray, 0, n - 1);
			end = clock();
			executionTime = double(end - start) / CLOCKS_PER_SEC;
			randomTimes[i] = executionTime;

			cout << "\r     [" << i + 1 << " of " << populations << " populations completed]" << flush;
		}
		delete[] ascendingTimes, descendingTimes, randomTimes;

		collectiveData[7][0] = Average(ascendingTimes, populations);
		collectiveData[7][1] = Average(descendingTimes, populations);
		collectiveData[7][2] = Average(randomTimes, populations);
		//DisplayCurrentData(collectiveData[7][0], collectiveData[7][1], collectiveData[7][2]);
	}
	program_end = clock();
	int programExecutionTime = double(program_end - program_start) / CLOCKS_PER_SEC;
	cout << "\n\n              Execution times of sorting algorithms for " << n << " elements and " << populations << " populations";
	DisplayCollectiveData(collectiveData);
	int minutes = (int)(programExecutionTime / 60);
	cout << "\n\n   Program execution time = " << minutes <<"m " << programExecutionTime - (minutes*60) << "s\n\n";
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
	cout << "\n  |      Selection Sort     | "; cout.width(11); cout << data[0][0] << "s"; cout.width(7); cout << " | "; cout.width(11); cout << data[0][1] << "s"; cout.width(8); cout << " | "; cout.width(8); cout << data[0][2] << "s"; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |      Insertion Sort     | "; cout.width(11); cout << data[1][0] << "s"; cout.width(7); cout << " | "; cout.width(11); cout << data[1][1] << "s"; cout.width(8); cout << " | "; cout.width(8); cout << data[1][2] << "s"; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |  Binary Insertion Sort  | "; cout.width(11); cout << data[2][0] << "s"; cout.width(7); cout << " | "; cout.width(11); cout << data[2][1] << "s"; cout.width(8); cout << " | "; cout.width(8); cout << data[2][2] << "s"; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |       Bubble Sort       | "; cout.width(11); cout << data[3][0] << "s"; cout.width(7); cout << " | "; cout.width(11); cout << data[3][1] << "s"; cout.width(8); cout << " | "; cout.width(8); cout << data[3][2] << "s"; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |  Optimized Bubble Sort  | "; cout.width(11); cout << data[4][0] << "s"; cout.width(7); cout << " | "; cout.width(11); cout << data[4][1] << "s"; cout.width(8); cout << " | "; cout.width(8); cout << data[4][2] << "s"; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |  Iterative Merge Sort   | "; cout.width(11); cout << data[5][0] << "s"; cout.width(7); cout << " | "; cout.width(11); cout << data[5][1] << "s"; cout.width(8); cout << " | "; cout.width(8); cout << data[5][2] << "s"; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |  Recursive Merge Sort   | "; cout.width(11); cout << data[6][0] << "s"; cout.width(7); cout << " | "; cout.width(11); cout << data[6][1] << "s"; cout.width(8); cout << " | "; cout.width(8); cout << data[6][2] << "s"; cout.width(7); cout << " | ";
	cout << "\n  ----------------------------------------------------------------------------------";
	cout << "\n  |        Quick Sort       | "; cout.width(11); cout << data[7][0] << "s"; cout.width(7); cout << " | "; cout.width(11); cout << data[7][1] << "s"; cout.width(8); cout << " | "; cout.width(8); cout << data[7][2] << "s"; cout.width(7); cout << " | ";
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

double Average(double* A, int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++) sum += A[i];
	return sum / n;
}
