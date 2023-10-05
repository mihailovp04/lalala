#include <stdlib.h>
#include <iostream>

struct TwoInts //Объявляю структуру TwoInts
{
    int a;    //Объявляю переменную a типа инт
    int b;    //Объявляю переменную b типа инт
};

struct StructWithArray    //Объявляю структуру StructWithArray
{
    int arr[4];        //Объявляю массив на 4 элемента 
    int* someNumber;     //Объявляю указатель на переменную someNumber
};

int main()     //Определяю функцию main 
{
    TwoInts i2 = { };     //Создаю переменную i2 типа TwoInts и инициализирую нулями. 
    i2.a = 5;     //Значение поля a устанавливаю в 5 
    i2.b = 7;    //Значение поля b устанавливаю в  7

    std::cout << i2.a << std::endl;    //Выводится значение поля a на консоль
    std::cout << i2.b << std::endl;   //Выводится значение поля b на консоль
    
    StructWithArray s = { };   //Создаю переменную s типа StructWithArray и инициализирую нулями
    s.arr[0] = 10;     //Устанавливаю значение первого элемента массива s.arr в 10

    StructWithArray s1 = { };   //Создаю переменную s1 типа StructWithArray и инициализирую нулями
    s1.arr[0] = 15;      //Устанавливаю значение первого элемента массива s1.arr в 15

    StructWithArray* sPointer = &s;   //Создаю указатель sPointer, который указывает на структуру s
    sPointer->arr[0] = 20;    //Первый элемент массива sPointer->arr  изменяется на 20

    std::cout << s.arr[0] << std::endl;     //На консоль выводится значение первого элемента массива s.arr, которое стало равным 20
    s.arr[0] = 25;     //Значение меняется на 25
    std::cout << s.arr[0] << std::endl;    //Значение выводится на консоль
    sPointer->arr[0] = 30;      // Элемент массива sPointer->arr  изменяется на 30
    std::cout << s.arr[0] << std::endl;   //Значение выводится на консоль

    sPointer = &s1;     //Указатель sPointer переключается на указание на структуру s1
    sPointer->arr[0] = 35;     //Первый элемент массива sPointer->arr  изменяется на 35
    std::cout << s.arr[0] << std::endl;     //Значение элемента массива s.arr  выводится на консоль
    std::cout << s1.arr[0] << std::endl;    //Значение s1.arr  выводится на консоль

    StructWithArray structArray[2] = { 0 };    //Создаю массив из двух структур structArray и инициализирую нулями
    structArray[0].arr[3] = 77;     //Устанавливаю значение 77 для четвертого элемента массива в первой структуре 
    structArray[1].someNumber = &structArray[0].arr[3];    //Указатель someNumber во второй структуре устанавливается на адрес четвертого элемента первой структуры

    sPointer = &s;   //Указатель sPointer переключается на указание на структуру s
    int* pointer = &sPointer->arr[3];     //Создаю указатель pointer, который указывает на четвертый элемент массива sPointer->arr
    s.arr[3] = 72;     //Значение четвертого элемента изменяется на 72, 
    std::cout << *pointer;    //Его значение выводится на консоль через указатель pointer

    StructWithArray memory;    //Создаю структуру memory типа StructWithArray, 
    memset(&memory, 0, sizeof(StructWithArray));     //Функция memset используется для заполнения структуры memoryее нулями
    return 0;
}