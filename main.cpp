#include <iostream>//подключение библиотеки функции ввода-вывода
#include <cmath>//подключение математической библиотеки 
using namespace std; //подключение пространства имён std

/*
*\brief Математическая функция, заменяющая конкретные элементы массива на противоположные по знаку
* \ int mas[] - целочисленный массив
* \ const int n - переменная, имеющая целочисленный тип данных 
* \ int k - переменная, имеющая целочисленный тип данных 
*/

void task1(int mas[], int n, int k);

/*
*\brief Математическая функция, определяющая имеются ли элементы в массиве кратные 3
* \ int mas[] - целочисленный массив
* \ const int n - переменная, имеющая целочисленный тип данных
*/


void task2(int mas[], int n);

/*
*\brief Математическая функция, имеются ли элементы массива сумма сосдених пар которых равна заданному числу
* \ int mas[] - целочисленный массив
* \ const int n - переменная, имеющая целочисленный тип данных
* \ int k - переменная, имеющая целочисленный тип данных
*/


void task3(int mas[], int n, int o);


/*
 * \brief Точка входа в программу.
 * \return Возвращает 0 в случае успешного выполнения.
 */

int main()
{
    setlocale(LC_ALL, "Russian");
    int k, a, o;
    const int n = 10;
    cout << "Как ввести массив? " << endl << "1-вручную, 2- рандомно. Ваш выбор: ";
    cin >> a;
    cout << "Введите, какие последние k элементов нужно инверсировать ";
    cin >> k;
    cout << "Задайте число ";
    cin >> o;
    int mas[n];
    if (a == 1)
    {
        for (int i = 0; i < n ; i++)
        {
            cout << "Введите элемент интервал значений [-100:100] ";
            while (!(cin >> mas[i]) || (cin.peek() != '\n') || (mas[i]>100) || (mas[i]<-100))
            {
                cin.clear();
                while (cin.get() != '\n');
                cout << "Введите целое число в интервале [-100:100] \n ";
            }
        }
        for (int i = 0; i < n ; i++)
        {
            cout << mas[i] << " ";
        }
        cout << endl;
    }
    else if (a == 2)
    {
        for (int i = 0; i < n; i++)
        {
            mas[i] = (rand() % 201) - 100;
        }
        cout << "Ваш массив: " << endl;
        for (int i = 0; i < n; i++)
        {
            cout << mas[i] << " ";
        }
        cout << endl;
    }
    task1(mas, n, k);
    task2(mas, n);
    task3(mas, n, o);
    return 0; 
}

void task1(int mas[], int n, int k)
{
    for (int i = n - k; i < n; i++)
    {
        mas[i] = -mas[i];
    }
    cout << "1.Заменить последние k элементов массива на противоположные по знаку: ";
    for (int i = 0; i < n; i++)
    {
        cout << mas[i] << " ";
    }
    cout << endl;
}
void task2(int mas[], int n)
{
    cout << "2.Вывести индексы тех элементов, значения которых кратны 3: ";
    for (int i = 0; i <= n; i++)
    {
        if (mas[i] % 3 == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}
void task3(int mas[], int n, int o)
{
    int h = 0;
    for (int i = 0; i <= n-1; i++)
    {
        if (mas[i] + mas[i + 1] == o)
        {
            h = h + 1;
        }
    }
    if (h > 0)
    {
        cout << "3.Определить, есть ли пара соседних элементов с суммой, равной заданному числу.";
        cout << "Пары есть";
    }
    else
    {
        cout << "3.Определить, есть ли пара соседних элементов с суммой, равной заданному числу.";
        cout << "Пар нет";
    }
}