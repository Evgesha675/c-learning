#include <iostream>
#include <string> // Для работы со строками

using namespace std;

int main() {
    string name;
    int age;

    // Запрашиваем имя пользователя
    cout << "Введите ваше имя: ";
    getline(cin, name); // Используем getline для ввода имени с пробелами

    // Запрашиваем возраст пользователя
    cout << "Введите ваш возраст: ";
    cin >> age;

    // Выводим приветствие
    cout << "Привет, " << name << "! Тебе " << age << " лет." << endl;

    // Дополнительно можно добавить условие
    if (age < 18) {
        cout << "Ты еще совсем молодой!" << endl;
    } else {
        cout << "Ты уже взрослый человек!" << endl;
    }

    return 0;
}
ё