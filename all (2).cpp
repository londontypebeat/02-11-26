#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream in1("input1.txt");
    ifstream in2("input2.txt");
    ofstream out("output.txt");
    
    string X, Y;
    getline(in1, X);
    getline(in2, Y);
    
    // Указатели для двух строк
    int i = 0; // указатель для строки X
    int j = 0; // указатель для строки Y
    
    while (i < X.size() && j < Y.size()) {
        if (X[i] == Y[j]) {
            j++; // двигаем указатель по Y
        }
        i++; // всегда двигаем указатель по X
    }
    
    // Если прошли всю строку Y - значит нашли подстроку
    if (j == Y.size()) {
        out << "yes";
    } else {
        out << "no";
    }
    
    return 0;
}
