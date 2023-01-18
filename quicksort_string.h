/*
    WARNING:
    quicksort_string() is still in development and is not yet ready for use.
*/

#pragma once

#include "string/CustomString.h"

void quicksort_string(CustomString *array, unsigned short input_left, unsigned short input_right)
{
    short pointer_left = input_left;
    short pointer_right = input_right;
    CustomString temp;
    CustomString pivot(array[(input_left + input_right) / 2].get_memory_pointer());

    while (pointer_left < pointer_right)
    {
        while (array[pointer_left] < pivot && pointer_left < input_right) ++pointer_left;
        while (array[pointer_right] > pivot && pointer_right > input_left) --pointer_right;
        if (pointer_left <= pointer_right)
            temp = CustomString(array[pointer_left].get_memory_pointer());
            array[pointer_left++] = CustomString(array[pointer_right].get_memory_pointer());
            array[pointer_right--] = CustomString(temp.get_memory_pointer());
    }
    if (pointer_left < input_right) quicksort_string(array, pointer_left, input_right);
    if (pointer_right > input_left) quicksort_string(array, input_left, pointer_right);
}
