#include <iostream> 
 
using namespace std; 
 
int main() { 
    int i; 
    i = 69; 
    int number; 
    number = 72; 
     
    cout << "i = " << i << endl; 
    cout << "number = " << number << endl; 
 
    i = i + number; 
     
    cout << "i = " << i << endl; 
 
    int array[3] = { }; 
    int* iPointer = &i; 
    number = *iPointer; 
 
    cout << "number = " << number << endl; 
 
    *iPointer = 15; 
    iPointer = &array[0]; 
    iPointer += 2; 
     
    cout << "*iPointer = " << *iPointer << endl; 
 
    array[0] = 5; 
    *iPointer = 6; 
 
    cout << "array[0] = " << array[0] << endl; 
 
    return 0; 
}