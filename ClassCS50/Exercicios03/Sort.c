#include <stdio.h>
#include <cs50.h>


void bubble_sort(int array[], int n);
void section_sort(int array[], int size);
void insertion_sort(int array[], int size);
void merge(int array[], int start_1, int end_1, int start_2, int end_2);
void merge_sort(int array[], int start, int end);
void print_array(int array[], int n);

int main(void) {
    int size = 5;

    printf("Bubble sort\n");
    int bubble_nums[] = { 7, 3, 0, 5, 2 };
    bubble_sort(bubble_nums, size);
    print_array(bubble_nums, size);

    printf("Section sort\n");
    int section_nums[] = { 7, 3, 0, 5, 2 };
    section_sort(section_nums, size);
    print_array(section_nums, size);

    printf("Insertion sort\n");
    int insertion_nums[] = { 7, 3, 0, 5, 2 };
    insertion_sort(insertion_nums, size);
    print_array(insertion_nums, size);

    printf("Merge sort\n");
    int merge_nums[] = { 7, 3, 0, 5, 2 };
    merge_sort(merge_nums, 0, size - 1);
    print_array(merge_nums, size);

}

void bubble_sort(int array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swaps = 0;

        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j + 1];
                array[i + 1] = array[j];
                array[j] = temp;

                swaps++;
            }
        }

        if (!swaps) break;
    }
}

void section_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int smallest = array[i];
        int position = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] < smallest) {
                smallest = array[j];
                position = j;
            }
        }

        int temp = array[i];
        array[i] = smallest;
        array[position] = temp;
    }
}

void insertion_sort(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i - 1;
        int to_sort = array[i];

        while (j >= 0 && to_sort < array[j]) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = to_sort;
    }
}

void merge(int array[], int start_1, int end_1, int start_2, int end_2) {
    int length = end_2 - start_1 + 1;
    int index = start_1;
    int temp[length];

    while (start_1 <= end_1 && start_2 <= end_2) {
        if (array[start_1] <= array[start_2]) {
            temp[index] = array[start_1];
            index++;
            start_1++;
        }
        else {
            temp[index] = array[start_2];
            index++;
            start_2++;
        }
    }

    while (start_1 <= end_1) {
        temp[index] = array[start_1];
        start_1++;
        index++;
    }

    while (start_2 <= end_2) {
        temp[index] = array[start_2];
        start_2++;
        index++;
    }

    for (int i = end_2, j = 0; j < length; i--, j++) {
        array[i] = temp[i];
    }
}

void merge_sort(int array[], int start, int end) {
    if (end > start) {
        int middle = (start + end) / 2;

        merge_sort(array, start, middle);
        merge_sort(array, middle + 1, end);
        merge(array, start, middle, middle + 1, end);
    }
}

void print_array(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}