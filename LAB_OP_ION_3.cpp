#include <iostream>
#include <fstream>
#include <string>

int* DevArr(int arr[], const int SIZE, int& resultSize) {
    int* result = new int[SIZE]; // Выделяем память под результат

    resultSize = 0; // Размер результата

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] % 2 != 0) {
            result[i] = arr[i];
            resultSize++;
            // Если arr[i] нечетный, он добавляется в массив result, а затем resultSize увеличивается на 1.
        }
        else {
            for (int j = 1; j < SIZE; j++) {
                if ((i + j) < SIZE) {
                    if ((arr[i] + arr[i + j]) % 2 != 0) {
                        result[i] = arr[i] + arr[i + j];
                        resultSize++;
                        break;
                    }
                }
                if ((i - j) >= 0) {
                    if ((arr[i] + arr[i - j]) % 2 != 0) {
                        result[i] = arr[i] + arr[i - j];
                        resultSize++;
                        break;
                    }
                }// Если  arr[i] четный, программа ищет ближайший нечетный элемент в массиве и добавляет сумму текущего четного элемента с найденным нечетным в массив result.
            }

        }
    }

    // Создание копии массива с размером resultSize
    int* trimmedResult = new int[resultSize];
    for (int i = 0; i < resultSize; i++) {
        trimmedResult[i] = result[i];
    }

    delete[] result; // Удаление исходного, неподогнанного под размер массива

    return trimmedResult;
}

int main() {
    setlocale(LC_ALL, "ru");

    // Открытие файла для чтения
    std::ifstream input_file("input.txt");
    if (!input_file.is_open()) {
        std::cerr << "Ошибка открытия файла input.txt" << std::endl;
        return 1;
    }

    int SIZE;
    input_file >> SIZE; // Чтение размера массива из файла

    int* arr = new int[SIZE]; // Выделяем память под входной массив

    // Чтение элементов массива из файла
    for (int i = 0; i < SIZE; i++) {
        input_file >> arr[i];
    }
    input_file.close();

    int resultSize; // размер массива после работы
    int* result = DevArr(arr, SIZE, resultSize);

    // Запись выходных данных в файл
    std::ofstream output_file("output.txt");
    if (!output_file.is_open()) {
        std::cerr << "Ошибка открытия файла output.txt" << std::endl;
        return 1;
    }
    output_file << "Это размер выходного массива и вводные элементы: " << resultSize << std::endl;
    for (int i = 0; i < resultSize; i++) {
        output_file << result[i] << " ";
        std::cout << result[i] << " ";
    }
    output_file.close();

    std::cout << "Данные успешно записаны в файлы input.txt и output.txt" << std::endl;

    delete[] arr; // Очистка памяти
    delete[] result;

    return 0;
}
