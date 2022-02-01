/*Домашнє завдання "Багатовимірні динамічні масиви"
1. Знайти суму елементів матриці, які є додатні.  Кількість стовпців і рядків матриці повинен вводити користувач.
За введеним даним, динамічно, повинна виділитися пам'ять під матрицю. Матрицю заповнювати випадковими значеннями,
як негативними так і позитивними.
Знайдіть суму елементів, які знаходяться на головній діагоналі.
Знайдіть суму елементів, які знаходяться на другорядній діагоналі.
Обчисліть суму елементів, які знаходяться під головною діагоналлю
2.2. Відсортуйте динамічний масив за зростанням або спаданням.
Реалізуйте меню для користувача.
Наприклад:
    1 – сортування за зростанням
    2 – за спаданням.
    */

#include <ctime>        
#include <iostream>
#include <conio.h>  //бібліотека для getch
#include <stdio.h> 
using namespace std;
void inputArr(int** matrix, int n, int m) {     //функція для вводу елементів масиву 
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = rand() % 41 - 20;    //Заповнення масиву рандомом
        }
    }
}
void printArr(int** matrix, int n, int m) { //ф-ція виведення масиву на екран 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
int sumOfPos(int** matrix, int n, int m) {      //ф-ція для суми додатніх чисел матриці
    int sum = 0;        //сума яку дізнаємось
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) {       //2 цикли для перерахування усіх елементів

            if (matrix[i][j] > 0)       //перевірка, якщо число більше 0(додатнє)
            {
                sum += matrix[i][j];        //сумуємо 
            }
        }
    }
    return sum;     //повертаємо суму 
}
void sumOfMainD(int** matrix, int n, int m) {     //Ф-ція суми головної діагоналі 
    int sum = 0;        //сума яку дізнаємось
    if (n == m) {       //при умові що матриця квадратна та має головну діагональ 
        for (int i = 0; i < n; i++)
        {                                       //2 цикли для перерахування усіх елементів
            for (int j = 0; j < m; j++) {

                if (i == j)                     //перевірка чи знаходимось на елементі головної діагоналі
                {
                    sum += matrix[i][j];        //додаємо наші елементи 
                }
            }
        }
        cout << "Sum of Main diagonal = " << sum;  // виводимо на екран 
    }
    else {
        cout << "--Sorry,but your Matrix have not main diagonal--"; //якщо у матриці відсутня головна діагональ 
    }
}
void sumOfSecD(int** matrix, int n, int m) {     //Ф-ція суми другорядної діагоналі 
    int sum = 0;
    if (n == m) {           //при умові що матриця квадратна та має головну діагональ
        for (int i = 0; i < n; i++)
        {                       //2 цикли для перерахування усіх елементів
            for (int j = 0; j < m; j++)
            {
                if (i + j == m - 1)         //перевірка чи знаходимось на другорядній діагоналі 
                {
                    sum += matrix[i][j];        //додаємо наші елементи 
                }
            }
        }
        cout << "Sum of Secondary diagonal = " << sum;
    }
    else {
        cout << "--Sorry,but your Matrix have not secondary diagonal--";    //якщо у матриці відсутня другорядна діагональ
    }
}
void sumOfUnderMainD(int** matrix, int n, int m) {     //Ф-ція суми під головною діаг. 
    int sum = 0;
    if (n == m) {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++) {       //цикл по елементах нижче головної діагоналі 

                sum += matrix[i][j];
            }
        }
        cout << "Sum of Under the Main diagonal = " << sum;
    }
    else {
        cout << "--Sorry,but your Matrix have not main diagonal--";
    }
}
void sortUp(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)                 //Запускаємо перерахунок усіх елементів матриці
    {
        for (int j = 0; j < m; j++)
        {
            for (int z = 0; z < n; z++)
            {
                for (int x = 0; x < m; x++)         //Запускаємо друге коло для перевірки елементів до елемента 
                {
                    if (z + 1 == n && x + 1 == m) {     //перевірка на останній елемент 
                        continue;       //продовжуємо цикл
                    }
                    else {
                        if (x + 1 == m && matrix[z][x] > matrix[z + 1][0])      //перевірка та зміна елементів між колонками 
                        {
                            int temp = matrix[z][x];
                            matrix[z][x] = matrix[z + 1][0];
                            matrix[z + 1][0] = temp;
                        }
                        else {
                            if (x + 1 == m) //якщо рядлк дійшов кінця
                            {
                                continue; //продовжуємо
                            }
                            else {
                                if (matrix[z][x] > matrix[z][x + 1])        //при умові що у рядку попередній елемент більший за наступниц - 
                                {
                                    swap(matrix[z][x], matrix[z][x + 1]);       //міняємо місцями 
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
void sortDown(int** matrix, int n, int m) {
    for (int i = 0; i < n; i++)                 //Запускаємо перерахунок усіх елементів матриці
    {
        for (int j = 0; j < m; j++)
        {
            for (int z = 0; z < n; z++)
            {
                for (int x = 0; x < m; x++)         //Запускаємо друге коло для перевірки елементів до елемента 
                {
                    if (z + 1 == n && x + 1 == m) {     //перевірка на останній елемент 
                        continue;       //продовжуємо цикл
                    }
                    else {
                        if (x + 1 == m && matrix[z][x] < matrix[z + 1][0])      //перевірка та зміна елементів між колонками 
                        {
                            int temp = matrix[z][x];
                            matrix[z][x] = matrix[z + 1][0];
                            matrix[z + 1][0] = temp;
                        }
                        else {
                            if (x + 1 == m) //якщо рядок дійшов кінця
                            {
                                continue; //продовжуємо
                            }
                            else {
                                if (matrix[z][x] < matrix[z][x + 1])        //при умові що у рядку попередній елемент більший за наступниц - 
                                {
                                    swap(matrix[z][x], matrix[z][x + 1]);       //міняємо місцями 
                                }
                            }
                        }
                    }
                }
            }
        }
    }

}
int main()
{
    int** matrix = nullptr;
    int n = 100;
    int m = 100;
    cout << "Enter size of Matrix columns (N) and rows(M)" << endl; //просимо кор ввести довжину та ширину матриці
    cin >> n >> m;
    matrix = new int* [n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];         //виділяємо пам'ять
    }

    inputArr(matrix, n, m);     //викликаємо ф-цію введеня елементів у масив
    printArr(matrix, n, m);     //виводимо матрицю на екран 
    cout << endl;
    cout << "Sum of positive elements = " << sumOfPos(matrix, n, m);    //виводимо суму додатніх елементів
    cout << endl;
    sumOfMainD(matrix, n, m);           //викликаємо ф-цію для суми елементів головної діагоналі
    cout << endl;
    sumOfSecD(matrix, n, m);            //викликаємо ф-цію для суми елементів другорядної діагоналі
    cout << endl;
    sumOfUnderMainD(matrix, n, m);     //викликаємо ф-цію для суми елементів під головною діагон.
    cout << endl;
    cout << endl;
    cout << "---Sort your matrix---" << endl;
    cout << "  Choise way to sort" << endl;                 //меню для користувача з вказівками 
    cout << "If you need UP, enter = u " << endl;           //просимо обрати у яку сторону сортуємо масив 
    cout << "If you need DOWN, enter = d " << endl;
    char a = _getch();      //викликаємо ф-цію getch для считування клавіши яку вибрав кор
    if (a == 'u') {                 //при умові що оператор обрав 'u'
        sortUp(matrix, n, m);       //викликаємо ф-цію сортування за зростанням та виводимо на екран 
        printArr(matrix, n, m);
    }
    if (a == 'd') {                 //при умові що оператор обрав 'd'
        sortDown(matrix, n, m);//викликаємо ф-цію сортування заспаданням та виводимо на екран 
        printArr(matrix, n, m);
    }



}

