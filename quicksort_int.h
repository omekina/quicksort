void quicksort_int(int array[], int left_start, int right_start)
{
    int temp;
    int pivot = array[(left_start + right_start) / 2];
    int left_index = left_start;
    int right_index = right_start;

    while (left_index < right_index)
    {
        while (array[left_index] < pivot && left_index < right_start) ++left_index;
        while (array[right_index] > pivot && right_index > left_start) --right_index;
            
        if (left_index <= right_index)
            temp = array[left_index];
            array[left_index++] = array[right_index];
            array[right_index--] = temp;
    }

    if (right_index > left_start) quicksort_int(array, left_start, right_index);
    if (left_index < right_start) quicksort_int(array, left_index, right_start);
}
