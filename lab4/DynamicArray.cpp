#include "dynamicArray.h"
#include <cassert>
#include <span>
DynamicArray createDynamicArrayWithCapacity(size_t capacity)
{
    int* arr = new int[capacity];
    DynamicArray array;
    array.capacity = capacity;
    array.length = 0;
    array.arr = arr;
    return array;
}
DynamicArray createDynamicArray()
{
    int* arr = new int[16];
    DynamicArray array;
    array.capacity = 16;
    array.length = 0;
    array.arr = arr;
    return array;
}

void addElementToArray(DynamicArray* array, int num)
{
    if (array->arr == 0)
    {
        int* arr = new int[1];
        array->arr = arr;
    }

    if (array->capacity <= array->length)
    {
        int* arr = new int[array->capacity * 2];
        for (int i = 0; i < array->capacity; i++)
        {
            arr[i] = array->arr[i];
        }
        delete[]array->arr;
        array->arr = arr;
        array->capacity *= 2;
    }

    array->arr[array->length++] = num;
}

int getElementAtIndex(DynamicArray* array, int index)
{
    assert(index < array->length);
    return array->arr[index];
}
std::span<int> getCurrentSpan(DynamicArray* array)
{
    return { array->arr, array->length };

}
void free(DynamicArray* array)
{
    array->length = 0;
    delete[]array->arr;
}