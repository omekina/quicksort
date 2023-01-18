/*
    WARNING:
    CustomString class can handle strings containing control characters.
    Thus using get_memory_pointer() to printf the string is not recommended.

    CustomString(char *input_string) constructor however determines the length of the string by
    counting the number of characters until it encounters the null character.
*/

#pragma once

#include "StringComparison.h"
#include <stdio.h>

class CustomString
{
private:
    char *memory_pointer;
    unsigned long length;
    bool memory_allocated = false;

    bool sanitize_index(unsigned long input_index)
    {
        if (!memory_allocated) throw;
        if (input_index < 0 || input_index >= length) return false;
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
        while (input_string[length] != '\0') ++length;
        ++length;
        memory_pointer = new char[length];
        for (long i = 0; i < length; ++i)
            memory_pointer[i] = input_string[i];
        memory_allocated = true;
        printf("constructor called and computed length: %d, string: %s\n", length, memory_pointer);
    }
    CustomString(char *input_string, unsigned long input_length)
    {
        if (input_length < 0) throw;
        length = input_length;
        memory_pointer = new char[length];
        for (unsigned long i = 0; i < length; ++i)
            memory_pointer[i] = input_string[i];
        memory_allocated = true;
    }
    ~CustomString()
    {
        printf("destructor called on: %s\n", memory_pointer);
        if (memory_allocated) delete[] memory_pointer;
    }

    char& operator[](unsigned long input_index)
    {
        if (!sanitize_index(input_index)) throw;
        return memory_pointer[input_index];
    }
    CustomString operator+(CustomString &input_string)
    {
        unsigned long result_length = length + input_string.length;
        char *result_string = new char[result_length];
        for (long i = 0; i < length; ++i)
            result_string[i] = memory_pointer[i];
        for (long i = 0; i < input_string.length; ++i)
            result_string[length + i] = input_string.memory_pointer[i];
        return CustomString(result_string, result_length);
    }
    bool operator>(CustomString &input_string)
    {
        printf("operator > called with: %s, %s\n", memory_pointer, input_string.memory_pointer);
        return string_greater_than(memory_pointer, input_string.memory_pointer, length, input_string.length);
    }
    bool operator<(CustomString &input_string)
    {
        printf("operator < called with: %s, %s\n", memory_pointer, input_string.get_memory_pointer());
        return string_less_than(memory_pointer, input_string.memory_pointer, length, input_string.length);
    }

    char *get_memory_pointer()
    {
        if (!memory_allocated) throw;
        return memory_pointer;
    }
};
