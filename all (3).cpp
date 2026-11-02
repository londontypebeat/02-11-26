#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Функция для перевода числа в двоичную систему
string toBinary(long long num) {
    if (num == 0) return "0"; // если число 0, возвращаем "0"
    
    string result = ""; // создаем пустую строку
    while (num > 0) {
        // добавляем остаток от деления на 2 в начало строки
        result = to_string(num % 2) + result; 
        num = num / 2; // делим число на 2
    }
    return result;
}

int main() {
    // Открываем файлы
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    string input; // строка для чтения
    string output = ""; // строка для результата
    
    // Читаем всю строку из файла
    getline(in, input);
    
    // Проходим по каждому символу
    for (int i = 0; i < input.length(); i++) {
        // Проверяем, является ли символ цифрой
        if (isdigit(input[i])) {
            long long number = 0; // создаем переменную для числа
            
            // Собираем число из последовательности цифр
            while (i < input.length() && isdigit(input[i])) {
                number = number * 10 + (input[i] - '0');
                i++; // переходим к следующему символу
            }
            
            // Возвращаемся на один шаг назад
            i--;
            
            // Преобразуем число в двоичную систему
            output += toBinary(number);
        }
        else {
            // Если не цифра - просто добавляем символ
            output += input[i];
        }
    }
    
    // Записываем результат в файл
    out << output;
    return 0;
}
