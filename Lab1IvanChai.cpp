#include <iostream>
#include <ctime>
#include <cstdlib> 
using namespace std;
const int OTLADKA = 300;
bool four_or_not(bool Num_index[10][9], int list[][9], int i) {
    int prov = 0;
    for (int j = 0; j < 9; j++) {
        if (Num_index[4][j] == list[i][j]) prov++;
    }
    return (prov == 9);
}
bool ittr(bool Num_index[10][9], int list[][9], int Num_weight_cor[], int Q) {
    int corr = 0; // Кол-во изменений весов за иттерацию
    for (int i = 0; i < OTLADKA; i++) {
        int summm = 0;
        for (int j = 0; j < 9; j++) {
            summm += Num_weight_cor[j] * list[i][j];
        }
        if (four_or_not(Num_index, list, i)) {
            if (summm <= Q) {
                corr++;
                cout << endl << endl << "(Шаг " << i << ") " << "Изменение веса " << corr << ":" << endl
                    << "Цифра 4 и вес меньше Q: (+1)" << endl;
                cout << "Веса до изменения: ";
                for (int j = 0; j < 9; j++) cout << Num_weight_cor[j] << ' ';
                cout << endl << "Веса после изменения: ";
                for (int j = 0; j < 9; j++) {
                    Num_weight_cor[j] += list[i][j];
                    cout << Num_weight_cor[j] << ' ';
                }
            }
        }
        else {
            if (summm >= Q) {
                corr++;
                cout << endl << endl << "(Шаг " << i << ") " << "Изменение веса " << corr << ":" << endl
                    << "Не цифра 4 и вес больше Q: (-1)" << endl;
                cout << "Веса до изменения: ";
                for (int j = 0; j < 9; j++) cout << Num_weight_cor[j] << ' ';

                cout << endl << "Веса после изменения: ";
                for (int j = 0; j < 9; j++) {
                    Num_weight_cor[j] -= list[i][j];
                    cout << Num_weight_cor[j] << ' ';
                }
            }
        }
    }
    if (corr == 0) return 1;
}
int main() {
    setlocale(LC_ALL, "ru");
    cout << "Программу написал студент группы УИБ-311 Гапонов Иван." << endl;
    int randNum,
        Q = 52, // Порог
        epoch = 0, // Сётчик эпох
        list[OTLADKA][9], // Полный список отладки
        Num_weight_cor[9] = { 9, 7, 6, 4, 3, 1, 8, 1, 2 }, // Вектор весов
        Num_count[10];
        fill_n(Num_count, 10, OTLADKA / 10);
    bool Num_index[10][9] = {
        {1, 1, 0, 1, 0, 1, 0, 1, 1}, // Num0_index
        {0, 0, 1, 1, 0, 0, 0, 1, 0}, // Num1_index
        {0, 1, 0, 1, 0, 0, 1, 0, 1}, // Num2_index
        {0, 1, 1, 0, 1, 0, 1, 0, 0}, // Num3_index
        {1, 0, 0, 1, 1, 0, 0, 1, 0}, // Num4_index
        {1, 1, 0, 0, 1, 0, 0, 1, 1}, // Num5_index
        {0, 0, 1, 0, 1, 1, 0, 1, 1}, // Num6_index
        {0, 1, 1, 0, 0, 1, 0, 0, 0}, // Num7_index
        {1, 1, 0, 1, 1, 1, 0, 1, 1}, // Num8_index
        {1, 1, 0, 1, 1, 0, 1, 0, 0}  // Num9_index
    };
    for (int i = 0; i < OTLADKA; i++) {
        do {
            randNum = rand() % 10;
        } while (Num_count[randNum] == 0); // Пропускаем, если больше нельзя использовать этот ряд

        Num_count[randNum]--; // Уменьшаем счетчик для выбранного ряда

        for (int j = 0; j < 9; j++) {
            list[i][j] = Num_index[randNum][j];
        }
    }
    cout << "Q равно " << Q << endl;
    for (int i = 0; i < OTLADKA; i++) {
        epoch++;
        cout << endl << "Эпоха " << epoch << ": " << endl;
        if (ittr(Num_index, list, Num_weight_cor, Q) == 1) {
            cout << "Изменений веса за эпоху нет" << endl << "Итоговые веса: ";
            for (int j = 0; j < 9; j++) {
                cout << Num_weight_cor[j] << ' ';
            } 
            cout << endl;
            break;
        }
        else cout << endl << endl << "Изменения веса за эпоху есть(" << endl;
        cout << endl << "Конец эпохи" << endl;
    }
    return 0;
}
