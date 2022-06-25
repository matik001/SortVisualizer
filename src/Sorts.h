#ifndef SORTVISUALIZER_SORTS_H
#define SORTVISUALIZER_SORTS_H
#include "IntWrapper.h"
#include <queue>

/// rozne sortowania wziete z internetu i zamieniony typ na IntWrapper

void bubbleSort(IntWrapper arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

///insertion sort
void insertionSort(IntWrapper arr[], int n)
{
    for (int i = 1; i <= n - 1; i++)
    {
        int pos = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
            else
                break;
        }
    }
}

///merge sort
int t[100000];  // Tablica pomocnicza
void merge(IntWrapper tab[], int pocz, int sr, int kon)
{
    int i, j, q;
    std::queue<int>values;   // Skopiowanie danych do tablicy pomocniczej
    i = pocz; j = sr + 1;                 // Ustawienie wskaźników tablic
    while (i <= sr && j <= kon)
    {    // Przenoszenie danych z sortowaniem ze zbiorów pomocniczych do tablicy głównej
        if (tab[i]<tab[j])
            values.push(tab[i++].get_value());
        else
            values.push(tab[j++].get_value());
    }
    while (i <= sr) values.push(tab[i++].get_value()); // Przeniesienie nie skopiowanych danych ze zbioru pierwszego w przypadku, gdy drugi zbiór się skończył
    while (values.empty() == false)
    {
        tab[pocz++] = values.front();
        values.pop();
    }
}

void mergesort(IntWrapper tab[], int pocz, int kon)
{
    int sr;
    if (pocz<kon) {
        sr = (pocz + kon) / 2;
        mergesort(tab, pocz, sr);
        mergesort(tab, sr + 1, kon);
        merge(tab, pocz, sr, kon);
    }
}

//quick sort
int partition(IntWrapper arr[], int low, int high)
{
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= arr[high])
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(IntWrapper arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

///heap sort
void heapify(IntWrapper arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(IntWrapper arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

///odd sort
void oddEvenSort(IntWrapper arr[], int n)
{
    bool isSorted = false; // Initially array is unsorted

    while (!isSorted)
    {
        isSorted = true;

        // Perform Bubble sort on odd indexed element
        for (int i = 1; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }

        // Perform Bubble sort on even indexed element
        for (int i = 0; i <= n - 2; i = i + 2)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                isSorted = false;
            }
        }
    }

    return;
}

///gnome sort

void gnomeSort(IntWrapper arr[], int n)
{
    int index = 0;

    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}
/// selection sort
void selectionSort(IntWrapper arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
}

/// Coctail sort
void CocktailSort(IntWrapper a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}


#endif //SORTVISUALIZER_SORTS_H
