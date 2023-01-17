#pragma once

bool string_greater_than(char *input_string1, char* input_string2, long input_length1, long input_length2)
{
    long maxlength = input_length1 > input_length2 ? input_length1 : input_length2;
    for (long i = 0; i < maxlength; ++i)
    {
        if (i >= input_length1)
            return false;
        if (i >= input_length2)
            return true;
        if (input_string1[i] > input_string2[i])
            return true;
    }
    return false;
}
bool string_less_than(char *input_string1, char* input_string2, long input_length1, long input_length2)
{
    long maxlength = input_length1 > input_length2 ? input_length1 : input_length2;
    for (long i = 0; i < maxlength; ++i)
    {
        if (i >= input_length1)
            return true;
        if (i >= input_length2)
            return false;
        if (input_string1[i] < input_string2[i])
            return true;
    }
    return false;
}
