#include <iostream>


/**
 Реализация Quick Sort из лекции
 
 @param array массив для сортировки от меньшего к большему
 @param size размер массива
 */
template <typename T>
void qSort(T array[], int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    int mid = array[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(array[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(array[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qSort(array, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
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
int getMinimumDifference(T array[], int arraySize, int k) {
    qSort(array, arraySize);
    int min_dif;
    
    for (int i = 0; i < arraySize; ++i) {
        
    }
    
    return min_dif;
}


int main(int argc, const char * argv[]) {
    
    /* Task6 */
    int arr_for_6_task[] = {2, 3, 1, 10, 0};  // Введите свой массив
    int k_for_6_task = 2; // Введите собственный k
    
    int arr6_size = sizeof(my_arr) / sizeof(my_arr[0]);
    int a = getMinimumDifference(arr_for_6_task, arr6_size, k_for_6_task);
    std::cout << a << "\n";
    
    return 0;
}
