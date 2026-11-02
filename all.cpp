#include <iostream> // подключаем библиотеку для ввода-вывода
#include <fstream>  // для работы с файлами
#include <string>   // для работы со строками
using namespace std; // чтобы не писать std:: перед функциями

int main() {
    ifstream in("input.txt"); // открываем файл для чтения
    ofstream out("output.txt"); // открываем файл для записи
    
    string text, result; // создаём две строки: для чтения и результата
    string forbidden = "user agreement"; // список запрещённых букв
    
    // Читаем весь текст
    getline(in, text); // считываем строку из файла
    
    // Проверяем каждый символ
    for (char c : text) { // перебираем каждый символ в строке
        bool skip = false; // флаг, нужно ли пропустить символ
        for (char f : forbidden) { // проверяем против запрещённых
            if (tolower(c) == tolower(f)) { // сравниваем в нижнем регистре
                skip = true; // если нашли совпадение
                break; // прерываем внутренний цикл
            }
        }
        if (!skip) result += c; // если не нужно пропускать - добавляем
    }
    
    out << result; // записываем результат в файл
    return 0;
}
