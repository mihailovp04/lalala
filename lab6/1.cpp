#include <iostream>
#include <cstdlib>
#include <chrono>

// ������� ��� �������� ������������� ������ ��������� ������� � ���������� ���������� �������
void generateRandomArray(int* buffer, int size) {
    for (int i = 0; i < size; ++i) {
        buffer[i] = rand();  // ��� ����� ������ ������ ��������� ��������� �����
    }
}

// ������� ��� ��������� ������� ���������� ������ �������
template <typename Func>
std::chrono::microseconds measureTime(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

int main() {
    const int bufferSize = 1000000;  // ������ ������

    // �������� ������������ �����
    int* dynamicBuffer = new int[bufferSize];

    // ���������� ��������� ����� � ������
    generateRandomArray(dynamicBuffer, bufferSize);

    // �������� ����� ���������� �������
    auto elapsedTime = measureTime([dynamicBuffer, bufferSize]() {
        // ��� ��� ��� ���������� ��� ������
        // ��������, ���������� ���������:
        for (int i = 0; i < bufferSize - 1; ++i) {
            for (int j = 0; j < bufferSize - i - 1; ++j) {
                if (dynamicBuffer[j] > dynamicBuffer[j + 1]) {
                    std::swap(dynamicBuffer[j], dynamicBuffer[j + 1]);
                }
            }
        }
        });

    // ������� ��������� ��������� ������� � �������������
    std::cout << "Elapsed Time: " << elapsedTime.count() << " microseconds." << std::endl;

    // ����������� ���������� ������
    delete[] dynamicBuffer;

    return 0;
}
