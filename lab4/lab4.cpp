#include <cassert>
#include "dynamicArray.h"
#include <span>
#include <stdio.h>

static void test1()
{
    DynamicArray array = createDynamicArrayWithCapacity(10);
    assert(array.capacity == 10);
}

static void test2()
{
    DynamicArray arr = createDynamicArray();
    assert(arr.length == 0);
    addElementToArray(&arr, 5);
    assert(arr.length == 1);
}
static void test3()
{
    DynamicArray arr = createDynamicArrayWithCapacity(1);
    addElementToArray(&arr, 5);
    assert(arr.capacity == 1);
    addElementToArray(&arr, 10);
    assert(arr.capacity == 2);
    addElementToArray(&arr, 20);
    assert(arr.capacity == 4);
}
static void test4()
{
    DynamicArray arr = createDynamicArray();
    addElementToArray(&arr, 5);
    int el = getElementAtIndex(&arr, 0);
    assert(el == 5);
}
static void test5()
{
    DynamicArray arr{};
    addElementToArray(&arr, 5);
    addElementToArray(&arr, 6);
    addElementToArray(&arr, 7);

    std::span<int> span = getCurrentSpan(&arr);
    assert(span.size() == 3);
    assert(span[0] == 5);
    assert(span[1] == 6);
    assert(span[2] == 7);
}
static void test6()
{
    DynamicArray arr = createDynamicArrayWithCapacity(2);
    addElementToArray(&arr, 5);
    addElementToArray(&arr, 6);
    addElementToArray(&arr, 7);
}
int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();


}