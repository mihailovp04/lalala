#include <iostream>
using namespace std;
int hello(int x) {
    return x;
}
int main()
{

    int result = hello(5);
    cout << "Rezult: " << result << std::endl;
    return 0;
}