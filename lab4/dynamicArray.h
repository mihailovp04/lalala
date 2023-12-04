#pragma once
#include <span>
struct DynamicArray
{
    size_t capacity = 1;
    size_t length;
    int* arr;
};

DynamicArray createDynamicArrayWithCapacity(size_t capacity);
DynamicArray createDynamicArray();
void addElementToArray(DynamicArray* array, int num);
int getElementAtIndex(DynamicArray* array, int index);
std::span<int> getCurrentSpan(DynamicArray* array);