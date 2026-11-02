#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in1("input1.txt"); // открываем первый файл
    ifstream in2("input2.txt"); // открываем второй файл
    ofstream out("output.txt"); // файл для вывода
    
    string X, Y; // строки для чтения
    getline(in1, X); // читаем первую строку
    getline(in2, Y); // читаем вторую строку
    
    // Проверяем наличие подстроки
    if (X.find(Y) != string::npos) { // если нашли
        out << "yes"; // выводим yes
    } else {
        out << "no"; // иначе no
    }
    
    return 0;
}