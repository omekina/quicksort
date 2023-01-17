/*
    WARNING:
    CustomString class can handle strings containing control characters.
    Thus using get_memory_pointer() to printf the string is not recommended.

    CustomString(char *input_string) constructor however determines the length of the string by
    counting the number of characters until it encounters the null character.
*/

#pragma once

#include "StringComparation.h"

class CustomString
{
private:
    char *memory_pointer;
    long length;

    bool sanitize_index(long input_index)
    {
        if (input_index < 0 || input_index >= length)
            return false;
        return true;
    }

public:
    CustomString()
    {
        length = 0;
        memory_pointer = nullptr;
    }
    CustomString(char *input_string)
    {
        length = 0;
        while (input_string[length] != '\0')
            length++;
        memory_pointer = new char[length];
        for (long i = 0; i < length; i++)
            memory_pointer[i] = input_string[i];
    }
    CustomString(char *input_string, long input_length)
    {
        if (input_length < 0)
            throw;
        length = input_length;
        memory_pointer = new char[length];
        for (long i = 0; i < length; i++)
            memory_pointer[i] = input_string[i];
    }
    ~CustomString()
    {
        delete[] memory_pointer;
    }

    char& operator[](long input_index)
    {
        if (!sanitize_index(input_index))
            throw;
        return memory_pointer[input_index];
    }
    CustomString operator+(CustomString &input_string)
    {
        char result_string[length + input_string.length];
        for (long i = 0; i < length; i++)
            result_string[i] = memory_pointer[i];
        for (long i = 0; i < input_string.length; i++)
            result_string[length + i] = input_string.memory_pointer[i];
        return CustomString(result_string, length + input_string.length);
    }
    bool operator>(CustomString &input_string)
    {
        return greater_than(memory_pointer, input_string.memory_pointer, length, input_string.length);
    }
    bool operator<(CustomString &input_string)
    {
        return less_than(memory_pointer, input_string.memory_pointer, length, input_string.length);
    }

    char *get_memory_pointer()
    {
        return memory_pointer;
    }
};
