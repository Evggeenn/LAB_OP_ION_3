#include <iostream>
#include <fstream>
#include <string>

int* FooNech(int arr[], const int SIZE) {
    int* result = new int[SIZE];

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 != 0) {
            result[i] = arr[i];
        }
        else {
            for (int j = 1; j < SIZE; j++) {
                if ((i + j) < SIZE) {
                    result[i] = arr[i] + arr[i + j];
                    if (result[i] % 2 != 0)
                        break;
                }
                if ((i - j) >= 0) {
                    result[i] = arr[i] + arr[i - j];
                    if (result[i] % 2 != 0)
                        break;
                }
            }
        }
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "ru");

    int SIZE;
    std::cout << "Введите размер массива: " << std::endl;
    std::cin >> SIZE;

    int* arr = new int[SIZE];

    std::cout << "Введите " << SIZE << " элементов(a): " << std::endl;
    for (int i = 0; i < SIZE; i++) {
        std::cin >> arr[i];
    }

    int* result = FooNech(arr, SIZE);

    // Запись входных данных в файл
    std::ofstream input_file("input.txt");
    if (!input_file.is_open()) {
        std::cerr << "Ошибка открытия файла input.txt" << std::endl;
        return 1;
    }
    input_file << "Это размер входного массива и вводные элементы: " << SIZE << std::endl;
    for (int i = 0; i < SIZE; i++) {
        input_file << arr[i] << " ";
    }
    input_file.close();

    // Запись выходных данных в файл
    std::ofstream output_file("output.txt");
    if (!output_file.is_open()) {
        std::cerr << "Ошибка открытия файла output.txt" << std::endl;
        return 1;
    }
    output_file << "Это размер выходного массива и вводные элементы: " << SIZE << std::endl;
    for (int i = 0; i < SIZE; i++) {
        output_file << result[i] << " ";
    }
    output_file.close();

    std::cout << "Данные успешно записаны в файлы input.txt и output.txt" << std::endl;

    delete[] arr;
    delete[] result;

    return 0;
}
