#include <iostream>
#include <cstdlib>
#include <string>


int score_of_done_tasks = 0;
/**
 Функция разделения номеров заданий для main()
 Также она может прервать процесс, если пользователь устал
 */
void goNext() {
    score_of_done_tasks++;
    std::string user_decision;
    
    std::cout << "\nTask №" << score_of_done_tasks << " is done, let's start №" << score_of_done_tasks+1 << "?\n";
    std::cout << "press ENTER to continue or write 'stop' to break process: ";
    std::getline(std::cin, user_decision);
    
    if (user_decision == "stop") {
        std::cout << "Really? Ok, let's finish, I don't want to see you for now...\n";
        exit(0);
    }
    
    std::cout << "\n\n";
}

/**
 Функция оптимизирует ввод данных пользователем (нужно указать type вводимого значения)
 
 @param prompt промпт для вывода в консоль (подсказка для пользователя)
 @return значение которое ввёл пользователь
  */
template <typename T>
T input(const std::string prompt) {
    T inputted(0.0);
    std::cout << prompt;
    std::cin >> inputted;
    return inputted;
}

/**
 Функция оптимизирует печать  пользователя
 
 @param prompt промпт для вывода в консоль (подсказка для пользователя)
 @return строчка которую ввёл пользователь
  */
std::string inputString(const std::string prompt) {
    std::string inputted = "";
    std::cout << prompt;
    std::cin >> inputted;
    return inputted;
}

/**
 Реализация Quick Sort из лекции
 
 @param array массив для сортировки от меньшего к большему
 @param size размер массива
 */
template <typename T>
void qSort(T array[], const int size) {
    // Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    // Центральный элемент массива
    T mid = array[size/2];

    do {
        // Перебираем элементы, ищем те, которые нужно перекинуть в другую часть
        // В левой части массива пропускаем (оставляем на месте) элементы, которые меньше центрального
        while (array[i] < mid) {
            i++;
        }
        // В правой части пропускаем (оставляем на месте) элементы, которые больше центрального
        while (array[j] > mid) {
            j--;
        }

        // Меняем элементы местами
        if (i <= j) {
            T tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    // Если осталось, что сортировать
    if (j > 0) {
        // Левый кусок
        qSort(array, j + 1);
    }
    if (i < size) {
        // Правый кусок
        qSort(&array[i], size - i);
    }
}

/**
 Создаёт рандомное целочисленное число в заданном диапазоне
 
 @param min нижняя граница для выбора
 @param max верхняя граница для выбора
 @return рандомное целочисленное число
 */
int getRandomNumber(const int min, const int max){
    int random_result = min + std::rand() % max;
    return random_result;
}

/**
 Выделяет память для массива из кучи
 
 @param arraySize размер массива (число ячеек памяти для выделения)
 @return адрес первой ячейки выделенной памяти
 */
double* getMemoryFromKuchaForArray(const int arraySize) {
    return new double[arraySize];
}

/**
 Возращает память массива куче
 
 @param array массив  (адрес первой ячейки памяти для возврата)
 */
void returnMemoryToKucha(double array[]) {
    delete[] array;
    array = nullptr;
}

/**
 Заполняет массив рандомными значениями
 
 @param array целочисленный массив для заполнения
 @param size размер массива
 */
template <typename T>
void fillArray(T array[], const int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = getRandomNumber(-999, 999);
    }
}

/**
 Выводит массив в консоль
 
 @param array целочисленный массив для вывода
 @param size размер массива
 @param prompt строчка для вывода перед массивом
 @param sep чем разделить значения массива
 @param print_with_brackets вывести с квадратнами скобками
 */
template <typename T>
void printArray(T array[], const int size, const std::string prompt, const std::string sep, const bool print_with_brackets) {
    std::cout << prompt << std::endl;
    
    if (print_with_brackets) {
        std::cout << "[";
    }
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << sep;
    }
    if (print_with_brackets) {
        std::cout << "\b\b]";
    }
    
    std::cout << "\n";
}

/**
 Меняет местами чётные и нечётные элементы целочисленного массива (сдвигает каждое значение на одно влево)
 
 @param array целочисленный массив для перестановки
 @param size размер массива
 */
void switchEvenAndOddNumbersInArray(int array[], const int size) {
    for (int i = 0; i < size-1; ++i) {
        // std::swap(array[i], array[i+1]);  // Простой вариант
        
        array[i] = array[i] - array[i+1];
        array[i+1] = array[i+1] + array[i];
        array[i] = array[i+1] - array[i];
    }
}

/**
 Заполняет двумерный целочисленный массив значениями от 10 до 50
 
 @param array двумерный целочисленный массив для заполнения
 @param rows кол-во строк в двумерном массиве
 @param columns кол-во столбцов в двумерном массиве
 */
void fillTwoDimensionalArray(int **array, const int rows, const int columns) {
    for (int i = 0; i < rows; ++i) {
        // fillArray(array[i], columns);  // Простой вариант
        
        for (int j = 0; j < columns; ++j) {
            array[i][j] = getRandomNumber(10, 50);
        }
    }
}

/**
 Выводит в консоль двумерный целочисленный массив
 
 @param array двумерный целочисленный массив для выводв
 @param rows кол-во строк в двумерном массиве
 @param columns кол-во столбцов в двумерном массиве
 */
void printTwoDimensionalArray(int **array, const int rows, const int columns) {
    std::cout << "\nYour filled array:\n\n";
    for (int i = 0; i < rows; ++i) {
        // printArray(array[i], columns, "", ", ", false);  // Простой вариант
        
        std::cout << "|";
        for (int j = 0; j < columns; ++j) {
            std::cout << array[i][j] << "|";
        }
        if (i != rows-1) {
            std::cout << "\n|";
            int n = 0;
            while (n < columns) {
                std::cout << "--|";
                n++;
            }
        }
        std::cout << "\n";
    }
}

/**
 Сложение 2-х чисел
 
 @param a первое число
 @param b второе число
 @return сумму a и b
 */
template <typename T>
T add(T a, T b) {
    return a + b;
}

/**
 Вычетание 2-х чисел
 
 @param a первое число
 @param b второе число
 @return разницу a и b
 */
template <typename T>
T subtract(T a, T b) {
    return a - b;
}

/**
 Умножение 2-х чисел
 
 @param a первое число
 @param b второе число
 @return произведение a и b
 */
template <typename T>
T multiply(T a, T b) {
    return a * b;
}

/**
 Деление 2-х чисел
 
 @param a первое число
 @param b второе число
 @return частное a и b
 */
template <typename T>
T divide(T a, T b) {
    return a / b;
}

/**
 Выполняет подсчёт примера через запуск функции по указателю
 
 @param a первое число
 @param b второе число
 @param def2run функция для выполнения
 @return результат вычислений
 */
float runDefByPtr(float a, float b, float (*def2run)(float, float)) {
    return def2run(a, b);
}

/**
 Реализация для https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
 
 @param array массив для поиска
 @param arraySize размер массива
 @param k число значения для разбиения/поиска
 */
template <typename T>
T getMinimumDifference(T array[], const int arraySize, const int k) {
    if (k == 1 || arraySize == 1) {
        return 0;  // так как array[i] - array[i] = 0
    }
    
    qSort(array, arraySize);
    T min_dif = abs(array[0] - array[1]);
    T act_pair[k];  // храним числа k
    
    for (int i = 0; i < arraySize; ++i) {
        int act_num = i;
        for (int j = 0; j < k; ++j) {
            act_pair[j] = array[act_num];  // заполняем массив k числами
            act_num++;
            if (act_num > arraySize-1) {
                act_num = 0;
            }
        }
        for (int n = 0; n < k - 1; ++n) {  // ищем минимальную разницу в k
            T act_diff = abs(act_pair[n+1] - act_pair[n]);
            if (act_diff < min_dif) {
                min_dif = act_diff;
            }
        }
    }
    
    return min_dif;
}

/**
 Реализация для https://leetcode.com/problems/find-lucky-integer-in-an-array/
 
 @param array массив для поиска
 @param size размер массива
 @return счастливое число (кол-во повторений в массиве == числу)
 */
int getLuckyNum(int array[], const int size) {
    qSort(array, size);
    int lucky_num = -1;
    int score = 1;
    
    for (int i = 0; i < size-1; ++i) {
        if (array[i] == array[i+1]) {
            score++;
        } else {
            if (score == array[i]) {
                lucky_num = array[i];
            }
            score = 1;
        }
    }
    if (score == array[size-1]) {
        lucky_num = array[size-1];
    }
    
    return lucky_num;
}

/**
 Реализация для https://leetcode.com/problems/majority-element/
 
 @param array массив для поиска
 @param size размер массива
 @return мажорный элемент (кол-во повторений в массиве > size/2)
 */
int getMajorityElement(int array[], const int size) {
    qSort(array, size);
    int maj_num = -1;
    int score = 1;
    int half = size / 2;
    
    for (int i = 0; i < size-1; ++i) {
        if (i > half && score == 1) {
            return maj_num;
        }
        if (array[i] == array[i+1]) {
            score++;
            if (score > half) {
                maj_num = array[i];
            }
        } else {
            score = 1;
        }
    }
    
    return maj_num;
}


int main(int argc, const char * argv[]) {
    std::srand(static_cast<unsigned int>(time(nullptr)));  // Инициализация рандомайзера, помещение зерна (seed) должно происходить 1 раз за программу
    
    /* Task1 */

    // 1.1
    const float constFloat = 12.0;
    const float *const constPtrToConstFloat = &constFloat;
    
    // 1.2
    typedef long int *longIntPtr;
    
    // 1.3
    double *doublePtr = nullptr;
    
    // 1.4
    const short int shortInt = 1;
    const short int *ptrToConstShortInt = &shortInt;
    
    // 1.5
    using tdConstPtrToFloat = const float *const;
    tdConstPtrToFloat cptcf = &constFloat;
    
    // 1.6
    typedef char *const charConstPtr;
    
    // 1.7
    double *const constPtrToDouble = nullptr;
    
    // 1.8
    typedef unsigned int *const constIntPtr;
    
    /* End of task1 */

    goNext();
    
    /* Task2 */
    double *ptr2arr_task2;
    
    do {
        int size_for_2_task = input<int>("Write array size: ");
        ptr2arr_task2 = getMemoryFromKuchaForArray(size_for_2_task);
        fillArray(ptr2arr_task2, size_for_2_task);
        printArray(ptr2arr_task2, size_for_2_task, "Array in 2nd task looks like:", ", ", true);
        returnMemoryToKucha(ptr2arr_task2);
    } while (inputString("\nPaste 'A' if you want to try it again or anything else to break: ") == "A");
    /* End of task2 */
    
    goNext();
    
    /* Task3 */
    int *ptr2arr_task3 = new int[12];
    fillArray(ptr2arr_task3, 12);
    printArray(ptr2arr_task3, 12, "Array in third task (before changes) looks like:", ", ", true);
    
    switchEvenAndOddNumbersInArray(ptr2arr_task3, 12);
    
    printArray(ptr2arr_task3, 12, "Array in third task (after changes) looks like:", ", ", true);
    
    delete[] ptr2arr_task3;
    ptr2arr_task3 = nullptr;
    /* End of task3 */
    
    goNext();
    
    /* Task4 */
    int score_array_rows_task4 = input<int>("Write num of rows in array: ");
    int score_array_columns_task4 = input<int>("Write num of columns in array: ");
    
    int **ptr2arr_task4 = new int*[score_array_rows_task4];
    for (int i = 0; i < score_array_rows_task4; ++i) {
        ptr2arr_task4[i] = new int[score_array_columns_task4];
    }
    
    fillTwoDimensionalArray(ptr2arr_task4, score_array_rows_task4, score_array_columns_task4);
    printTwoDimensionalArray(ptr2arr_task4, score_array_rows_task4, score_array_columns_task4);
    
    for (int i = 0; i < score_array_rows_task4; ++i) {
        delete[] ptr2arr_task4[i];
        ptr2arr_task4[i] = nullptr;
    }
    delete[] ptr2arr_task4;
    ptr2arr_task4 = nullptr;
    /* End of task4 */
    
    goNext();
    
    /* Task5 */
    // Честно говоря, мы вообще не поняли что требуется в этой задаче
    // Реализовали что-то похожее на описание
    float (*ptr2def_task5)(float, float);
    float a_task5 = input<float>("Write 'a' num: ");
    char sign_task5 = input<char>("Put sign (+, -, *, /): ");
    float b_task5 = input<float>("Write 'b' num: ");
    
    switch (sign_task5) {
        case '+':
            ptr2def_task5 = add;
            break;
        case '-':
            ptr2def_task5 = subtract;
            break;
        case '*':
            ptr2def_task5 = multiply;
            break;
        case '/':
            ptr2def_task5 = divide;
            break;
        default:
            std::cout << "I don't know such sign '" << sign_task5 << "'\n";
            return -1;
    }
    
    float result_task5 = runDefByPtr(a_task5, b_task5, ptr2def_task5);
    std::cout << a_task5 << " " << sign_task5 << " " << b_task5 << " = " << result_task5 << std::endl;
    /* End of task5 */
    
    goNext();
    
    /* Task6 */
    int arr_for_task6[] = {2, 30, 4, 10, 0, 7};  // Введите свой массив
    const int k_for_task6 = 3; // Введите собственный k

    const int arr6_size = sizeof(arr_for_task6) / sizeof(arr_for_task6[0]);
    const int min_diff_6 = getMinimumDifference(arr_for_task6, arr6_size, k_for_task6);
    std::cout << "k = " << k_for_task6 << " & array is [";
    for (auto item : arr_for_task6) {
        std::cout << item << " ";
    }
    std::cout << "\b]\n-> Min diff = " << min_diff_6 << std::endl;
    /* End of task6 */
    
    goNext();
    
    /* Task7 */
    int arr_for_task7[] = {1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 6, 3};  // Введите свой массив
    
    const int arr7_size = sizeof(arr_for_task7) / sizeof(arr_for_task7[0]);
    int lucky_num_7 = getLuckyNum(arr_for_task7, arr7_size);
    std::cout <<"In array [";
    for (auto item : arr_for_task6) {
        std::cout << item << " ";
    }
    if (lucky_num_7 == -1) {
        std::cout << "\b] no lucky num" << std::endl;
    } else {
        std::cout << "\b] lycky num is " << lucky_num_7 << std::endl;
    }
    /* End of task7 */
    
    goNext();
    
    /* Task8 */
    int arr_for_task8[] = {3, 2, 3};  // Введите свой массив
    
    const int arr8_size = sizeof(arr_for_task8) / sizeof(arr_for_task8[0]);
    int maj_num_8 = getMajorityElement(arr_for_task8, arr8_size);
    std::cout <<"Array = [";
    for (auto item : arr_for_task6) {
        std::cout << item << " ";
    }
    if (maj_num_8 == -1) {
        std::cout << "\b] and here no major num" << std::endl;
    } else {
        std::cout << "\b] and majority num is " << maj_num_8 << std::endl;
    }
    /* End of task8 */
    
    /* Finish */
    score_of_done_tasks++;
    std::cout << "\n\nTask №" << score_of_done_tasks << " is done, so that is all, thank you, all the best!\n";
    
    return 0;
}
