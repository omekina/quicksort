void quicksort_int(int array[], unsigned short input_left, unsigned short input_right)
{
    short pointer_left = input_left;
    short pointer_right = input_right;
    int temp = 0;
    int pivot = array[(input_left + input_right) / 2];

    while (pointer_left < pointer_right)
    {
        while (array[pointer_left] < pivot && pointer_left < input_right) ++pointer_left;
        while (array[pointer_right] > pivot && pointer_right > input_left) --pointer_right;
        if (pointer_left <= pointer_right)
            temp = array[pointer_left];
            array[pointer_left++] = array[pointer_right];
            array[pointer_right--] = temp;
    }
    if (pointer_left < input_right) quicksort_int(array, pointer_left, input_right);
    if (pointer_right > input_left) quicksort_int(array, input_left, pointer_right);
}
