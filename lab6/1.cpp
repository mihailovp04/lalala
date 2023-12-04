#include <iostream>
#include <cstdlib>
#include <chrono>

// Функция для создания динамического буфера заданного размера и заполнения случайными числами
void generateRandomArray(int* buffer, int size) {
    for (int i = 0; i < size; ++i) {
        buffer[i] = rand();  // или любой другой способ генерации случайных чисел
    }
}

// Функция для измерения времени выполнения другой функции
template <typename Func>
std::chrono::microseconds measureTime(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();

    return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
}

int main() {
    const int bufferSize = 1000000;  // Размер буфера

    // Выделяем динамический буфер
    int* dynamicBuffer = new int[bufferSize];

    // Генерируем случайные числа в буфере
    generateRandomArray(dynamicBuffer, bufferSize);

    // Измеряем время выполнения функции
    auto elapsedTime = measureTime([dynamicBuffer, bufferSize]() {
        // Ваш код для сортировки или поиска
        // Например, сортировка пузырьком:
        for (int i = 0; i < bufferSize - 1; ++i) {
            for (int j = 0; j < bufferSize - i - 1; ++j) {
                if (dynamicBuffer[j] > dynamicBuffer[j + 1]) {
                    std::swap(dynamicBuffer[j], dynamicBuffer[j + 1]);
                }
            }
        }
        });

    // Выводим результат измерения времени в микросекундах
    std::cout << "Elapsed Time: " << elapsedTime.count() << " microseconds." << std::endl;

    // Освобождаем выделенную память
    delete[] dynamicBuffer;

    return 0;
}
