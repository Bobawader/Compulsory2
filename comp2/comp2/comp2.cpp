#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>


using namespace std;
using namespace std::chrono;

void SelectionSort(vector <int> & array, int n) {

    /// <summary>
    /// simple sorting system selecting smallest from the largest
    /// </summary>
    /// <param name="array">array in question</param>
    /// <param name="n">size</param>
    int i, j, minIndex;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[minIndex])
                minIndex = j;
        }
        if (minIndex != i) {
            swap(array[minIndex], array[i]);
        }
    }



}


void QuickSort(vector<int>& array, int start, int end) {

    /// <summary>
    /// sorting algorythm which is recursive and divides and conqers
    /// </summary>
    /// <param name="array">array you wish to sort</param>
    /// <param name="start">starting index</param>
    /// <param name="end">end index</param>
    if (start < end) {

        int pivot = array[start];
        int left = start + 1;
        int right = end;

        while (left <= right) {
            while (left <= end && array[left] <= pivot) {
                left++;
            }
            while (right >= start && array[right] > pivot) {
                right--;
            }
            if (left < right) {
                int temp = array[left];
                array[left] = array[right];
                array[right] = temp;
            }
        }

        int temp = array[start];
        array[start] = array[right];
        array[right] = temp;

        QuickSort(array, start, right - 1);
        QuickSort(array, right + 1, end);
    }
}

void Merge(vector<int>& array, int start, int mid, int end) {

    /// <summary>
    /// the brain behind the mergesort function dividing and conqering the array
    /// </summary>
    /// <param name="array"> array you wish to sort</param>
    /// <param name="start">start index</param>
    /// <param name="mid">middle index</param>
    /// <param name="end">end index</param>
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int* left = new int[n1];
    int* right = new int[n2];
    for (int i = 0; i < n1; i++) {
        left[i] = array[start + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = array[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = start;


    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        }
        else {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
}


void MergeSort(vector<int>& array, int start,int end) {

    /// <summary>
    /// recursive sorting function that uses the merge fuction to sort an vector array.
    /// </summary>
    /// <param name="array">the array you wish to sort</param>
    /// <param name="start">start index</param>
    /// <param name="end">end index</param>
    if (start < end) {
        int mid = start + (end - start) / 2;

        MergeSort(array, start, mid);
        MergeSort(array, mid + 1, end);

        Merge(array, start, mid, end);
    }
}



int main()
{

    /// <summary>
    /// the function decides the array size and which sorting system to run
    /// </summary>
    /// <returns>
    ///  return 0 when run correctly
    /// </returns>
    int mili;
   
    cout << "do you want the array to be 10 '1' 100 '2' 1000 '3' 10000 '4': ";
    cin >> mili;

    int arraySize = 0;
    if (mili == 1) {
        arraySize = 10;
    }
    else if (mili == 2) {
        arraySize = 100;
    }
    else if (mili == 3) {
        arraySize = 1000;
    }
    else if (mili == 4) {
        arraySize = 10000;
    }
    
    vector<int> array(arraySize); 

    for (int i = 0; i < arraySize; i++) {
        array[i] = rand() % 1000;
    }

    
    char choice;

    cout << "please choose an algorythm, q is quicksort, m is merge and s is selectionsort: ";
    cin >> choice;
    

    if (choice == 'q') {

        auto begin = high_resolution_clock::now();

        QuickSort(array, 0, arraySize-1);

        for (int i = 0; i < arraySize; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        auto end = high_resolution_clock::now();

        auto elapsed = duration_cast<milliseconds>(end - begin);
        cout << endl << "Time taken by quicksort function: " << elapsed.count() << " milliseconds" << endl;
        
    }


    else if (choice == 'm') {

        auto begin = high_resolution_clock::now();

        MergeSort(array, 0, arraySize - 1);

        for (int i = 0; i < arraySize; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
        
        auto end = high_resolution_clock::now();

        auto elapsed = duration_cast<milliseconds>(end - begin);
        cout << endl << "Time taken by quicksort function: " << elapsed.count() << " milliseconds" << endl;
    }


    else if (choice == 's') {
        auto begin = high_resolution_clock::now();

        SelectionSort(array, arraySize);

        for (int i = 0; i < arraySize; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        auto end = high_resolution_clock::now();

        auto elapsed = duration_cast<milliseconds>(end - begin);
        cout << endl << "Time taken by quicksort function: " << elapsed.count() << " milliseconds" << endl;
    }
    
    return 0;
}


