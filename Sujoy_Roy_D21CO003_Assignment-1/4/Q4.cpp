#include <bits/stdc++.h>
#include <sys/time.h>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> randomList;
int N = 0;
long long count = 0;

int insertionSort(vector<int> arr, int n);
void insertionCall(vector<int> a, int n);
void heapCall(vector<int> a, int n);
void quickCall(vector<int> a, int n);
void mergeCall(vector<int> a, int n);

class Quick
{

    vector<int> arr;
    int n;
    void swap(int *a, int *b);
    int partition(int low, int high);

public:
    int mergeSwapcount = 0;
    Quick(vector<int> a, int no);
    void quickSort(int low, int high);
    void printArray();
};

class Heap
{

private:
    vector<int> arr;
    int n;
    void heapify(int n, int i);

public:
    long long heapSwapCount = 0;
    Heap(vector<int> a, int no);
    void heapSort();
    void printArray();
};

class MergeSorter
{
    int swapCount;
    void merge(vector<int> arr, int l, int m, int r);
    void mergeSort(vector<int> arr, int l, int r);

public:
    MergeSorter() : swapCount(0) {}
    void startSort(vector<int> arr, int l, int r);
    int getSwapCount() const { return swapCount; }
};

int main()
{
    int line;
    ifstream input("randomList.txt");

    if (!input)
    {
        cout << "File not opened!";
        exit(1);
    }

    while (!input.eof())
    {
        input >> line;
        randomList.push_back(line);
    }

    input.close();

    N = randomList.size();

    auto start = std::chrono::high_resolution_clock::now();
    insertionCall(randomList, N);
    auto elapsed = std::chrono::high_resolution_clock::now() - start;
    auto defaultNano = std::chrono::duration_cast<std::chrono::seconds>(elapsed).count();
    cout << "Time taken by Insertion sort swap count: " << defaultNano << " seconds" << endl;

    start = std::chrono::high_resolution_clock::now();
    heapCall(randomList, N);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    auto duration = (elapsed).count();
    cout << "Time taken by function: " << duration << " nanoseconds" << endl;

    start = std::chrono::high_resolution_clock::now();
    quickCall(randomList, N);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    duration = (elapsed).count();
    cout << "Time taken by function: " << duration << " nanoseconds" << endl;

    start = std::chrono::high_resolution_clock::now();
    mergeCall(randomList, N);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    duration = (elapsed).count();
    cout << "Time taken by function: " << duration << " nanoseconds" << endl;

    cout << "Program Ended!";
    return 0;
}

//Question--4
// long long insertionSort(vector<int> arr)
// {
//     cout << arr.size()<<endl;

//     long i, key, j, count = 0;
//     for (i = 1; i < arr.size(); i++)
//     {
//         key = arr[i];
//         j = i - 1;

//         while (j >= 0 && arr[j] > key)
//         {
//             arr[j + 1] = arr[j];
//             count++;
//             j = j - 1;
//         }
//         arr[j + 1] = key;
//     }

//     return count;
// }

Quick::Quick(vector<int> a, int no)
{
    n = no;
    arr = a;
}
void Quick::swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    mergeSwapcount++;
}

int Quick::partition(int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void Quick::quickSort(int low, int high)
{
    if (low < high)
    {

        int pi = partition(low, high);

        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void Quick::printArray()
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

Heap::Heap(vector<int> a, int no)
{
    n = no;
    arr = a;
}

void Heap::heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        heapSwapCount++;
        swap(arr[i], arr[largest]);
        heapify(n, largest);
    }
}

void Heap::heapSort()
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        heapSwapCount++;
        swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}

void Heap::printArray()
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

void MergeSorter::merge(vector<int> arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
        swapCount++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSorter::mergeSort(vector<int> arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void MergeSorter::startSort(vector<int> arr, int l, int r)
{
    swapCount = 0; // start at 0
    mergeSort(arr, l, r);
}

//insertion_Sort
int insertionSort(vector<int> arr, int n)
{
    int i, key, j, count = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            count++;
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    return count;
}

void copyArray(vector<int> a, vector<int> b, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}

void insertionCall(vector<int> a, int n)
{
    vector<int> b(n, 0);
    copyArray(b, a, n);
    int c = insertionSort(b, n);
    cout << "Insertion sort swaps: " << c << endl;
}

void heapCall(vector<int> a, int n)
{
    vector<int> b(n, 0);
    copyArray(b, a, n);
    Heap hp(b, n);
    hp.heapSort();
    cout << "Heap sort swaps: " << hp.heapSwapCount << endl;
}

void quickCall(vector<int> a, int n)
{
    vector<int> b(n, 0);
    copyArray(b, a, n);
    Quick qi(b, n);
    qi.quickSort(0, n - 1);

    cout << "Quick sort Swaps: " << qi.mergeSwapcount << endl;
}

void mergeCall(vector<int> a, int n)
{
    vector<int> b(n, 0);
    copyArray(b, a, n);
    MergeSorter ms;
    ms.startSort(a, 0, n);
    cout << "merge swaps : " << ms.getSwapCount() << endl;
}