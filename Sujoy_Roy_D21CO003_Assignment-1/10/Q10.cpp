#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define N 20
int heapstate = 0;

void printArray(int arr[], int n)
{
    if (n == 0)
    {
        cout << "Empty array.\n";
        return;
    }
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

//heapify
void max_heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        max_heapify(arr, n, largest);
    }
}

void min_heapify(int arr[], int n, int i)
{
    // Find largest among root, left child and right child
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // Swap and continue heapifying if root is not largest
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        min_heapify(arr, n, smallest);
    }
}

//add
void add(int arr[], int n, int Key)
{
    arr[n - 1] = Key;
    if (heapstate == 0)
        ;
    else if (heapstate == 1)
        max_heapify(arr, n, n - 1);
    else if (heapstate == 2)
        min_heapify(arr, n, n - 1);

    cout << "Added\n";
}

//extract
int extract(int arr[], int n)
{
    int extraced = arr[0];
    arr[0] = arr[n];
    if (heapstate == 0)
        return extraced;
    else if (heapstate == 1)
        max_heapify(arr, n - 1, 0);
    else if (heapstate == 2)
        min_heapify(arr, n - 1, 0);

    return extraced;
}

void make_max_heap(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(a, n, i);
}

//min-heap
void make_min_heap(int *a, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(a, n, i);
}

//sort
void heapSort(int arr[], int n)
{
    if (heapstate == 1)
    {
        make_max_heap(arr, n);

        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            max_heapify(arr, i, 0);
        }
    }

    else if (heapstate == 2)
    {
        make_min_heap(arr, n);
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            min_heapify(arr, i, 0);
        }
    }

    else
        cout << "Heapstate need to be either 1 or 2.\n";
    cout << "heapstate:" << heapstate << endl;
}

/* A utility function to print array of size n */

// Driver program
int main()
{

    int A[N + 1];
    int heapsize = 0;
    string command = "";
    int val = 0;

    for (int i = 0; i <= N; i++)
        A[i] = 0;
    do
    {
        cout << "(add, extract, neither, max, min, sort, end) : \n";
        cin >> command;
        if (command == "add")
        {
            if (heapsize >= 20)
                cout << "Max Element Limit Reached \n";
            else
            {
                cout << "add-";
                cin >> val;
                heapsize++;
                add(A, heapsize, val);
            }
        }
        if (command == "extract")
        {
            if (heapsize == 0)
                cout << "Empty Heap.\n";
            else
            {
                heapsize--;
                cout << "Extracted : " << extract(A, heapsize) << endl;
            }
        }
        if (command == "neither")
        {
            heapstate = 0;
        }
        if (command == "max")
        {
            heapstate = 1;
            make_max_heap(A, heapsize);
        }
        if (command == "min")
        {
            heapstate = 2;
            make_min_heap(A, heapsize);
        }
        if (command == "sort")
        {
            heapSort(A, heapsize);
        }

        printArray(A, heapsize);
    } while (command != "end");
}
