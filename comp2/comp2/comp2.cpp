// comp2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;


void SelectionSort(int array[], int n) {



}

//recursive
void QuickSort(int array[], int low, int high) {

    //base case
    if (low < high) {

        int pivot = array[low];
        int left = low + 1;
        int right = high;

        while (left <= right) {
            while (left <= high && array[left] <= pivot) {
                left++;
            }
            while (right >= low && array[right] > pivot) {
                right--;
            }
            if (left < right) {
                int temp = array[left];
                array[left] = array[right];
                array[right] = temp;
            }
        }

        int temp = array[low];
        array[low] = array[right];
        array[right] = temp;

        QuickSort(array, low, right - 1);
        QuickSort(array, right + 1, high);
    }
}

void Merge(int array[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int* left = new int[n1];
    int* right = new int[n2];
    for (int i = 0; i < n1; i++) {
        left[i] = array[low + i];
    }
    for (int i = 0; i < n2; i++) {
        right[i] = array[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;


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
//recursive
void MergeSort( int array[], int low,int high) {

    if (low < high) {
        int mid = low + (high - low) / 2;

        MergeSort(array, low, mid);
        MergeSort(array, mid + 1, high);

        Merge(array, low, mid, high);
    }
}



int main()
{
    int array[] = {5, 8, 4, 9, 2, 3, 1, 7, 6};
    int size = sizeof(array) / sizeof(array[0]);
    char choice;

    cout << "please choose an algorythm, q is quicksort, m is merge and s is selectionsort: ";
    cin >> choice;
    


    if (choice == 'q') {

        QuickSort(array, 0, size - 1);

        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    else if (choice == 'm') {

        MergeSort(array, 0, size - 1);

        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    else if (choice == 's') {
        //something
    }
    

    return 0;
}


