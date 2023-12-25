#include <iostream>
#include <cstdlib>
#include <string>


int score_of_done_tasks = 0;
/**
 Функция разделения номеров заданий для main()
 Также она может прервать процесс, если пользователь устал
 */
void goNext() {
    score_of_done_tasks += 1;
    std::string user_decision;
    
    std::cout << "\nTask №" << score_of_done_tasks << " is done, let's start №" << score_of_done_tasks+1 << "?\n";
    std::cout << "press ENTER to continue or write 'stop' to break process: ";
    // std::getline(std::cin, user_decision);
    
    if (user_decision == "stop") {
        std::cout << "Really? Ok, let's finish, I don't want to see you for now...\n";
        exit(0);
    }
    
    std::cout << "\n\n";
}

/**
 Функция оптимизирует ввод данных пользователем (нужно указать type вводимого значения)
 
 @param prompt промпт для вывода в консоль (подсказка для пользователя)
 @return значение которе ввёл пользователь
  */
template <typename T>
T input(std::string prompt) {
    T inputted;
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
    //Указатели в начало и в конец массива
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
 Реализация для https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/
 
 @param array массив для поиска
 @param arraySize размер массива
 @param k число значения для разбиения/поиска
 */
template <typename T>
int getMinimumDifference(T array[], const int arraySize, const int k) {
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
            act_num += 1;
            if (act_num > arraySize-1) {
                act_num = 0;
            }
        }
        for (int n = 0; n < k - 1; ++n) {  // ищем минимальную разницу в k
            T act_diff = abs(act_pair[n + 1] - act_pair[n]);
            if (act_diff < min_dif) {
                min_dif = act_diff;
            }
        }
    }
    
    return min_dif;
}


int main(int argc, const char * argv[]) {
//    /* Task1 */
//    
//    // 1.1
//    const float constFloat = 12.0;
//    const float *const constPtrToConstFloat = &constFloat;
//    
//    // 1.2
//    typedef long int *longIntPtr;
//    
//    // 1.3
//    double *doublePtr = nullptr;
//    
//    // 1.4
//    const short int shortInt = 1;
//    const short int *ptrToConstShortInt = &shortInt;
//    
//    // 1.5
//    using tdConstPtrToFloat = const float *const;
//    tdConstPtrToFloat cptcf = &constFloat;
//    
//    // 1.6
//    typedef char *const charConstPtr;
//    
//    // 1.7
//    double *const constPtrToDouble = nullptr;
//    
//    // 1.8
//    typedef unsigned int *const constIntPtr;

    goNext();
    
    /* Task2 */
    int size_for_2_task = input<int>("Введите размер массива: ");
    double *ptr2arr_task2[size_for_2_task];
    
    goNext();
    
    /* Task6 */
    int arr_for_6_task[] = {2, 30, 4, 10, 0, 7};  // Введите свой массив
    const int k_for_6_task = 3; // Введите собственный k
    
    const int arr6_size = sizeof(arr_for_6_task) / sizeof(arr_for_6_task[0]);
    const int min_diff_6 = getMinimumDifference(arr_for_6_task, arr6_size, k_for_6_task);
    std::cout << "Min diff = " << min_diff_6 << std::endl;
    
    goNext();
    
    return 0;
}
