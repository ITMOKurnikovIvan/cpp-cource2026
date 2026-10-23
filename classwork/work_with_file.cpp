#include <iostream>
#include <fstream> // Работа с файлами // потоки ввода/вывода
#include <ios>
#include <iomanip> // манипуляторы потоков ввода/вывода
#include <string>

// Создание собственного манипулятора
// std::ofstream& manipName(std::ofstream& os)
// {
//     return os << "\n";
// }

int main()
{
    // 1. ifstream --- поток (input file stream) ввода из файла. Чтение
    // 2. ofstream --- поток (output file stream) вывода в файл. Запись
    // 3. fstream --- двунаправленный поток. Чтение + Запись

    // Способы взаимодействия с файлом
    // Открытие файла
    // 1. Через конструктор объекта
    std::ofstream outfile("output_data.txt");

    // 2. Через явный метод open()
    std::ifstream fin;
    fin.open("output_data.txt");

    if (!fin.is_open()) // if(!fin)
    {
        std::cerr << "Can't open file\n";
        return 1;
    }

    // .......

    fin.close(); // Явно закрыть файл

    // Режимы взаимодействия с файлом
    // std::ios::in --- Открытие для чтения
    // std::ios::out --- Открытие для записи (перезапись)
    // std::ios::app --- Дозапись в конец файла
    // std::ios::ate --- Открыть файл и перейти в его конец
    // std::ios::trunc --- Усечение файла до нуля
    // std::ios::binary --- Бинарный режим

    std::fstream file("data.bin", std::ios::in | std::ios::out | std::ios::binary);
    file.close();

    std::ofstream out("out.txt");
    out << "Hello, " << 3.14 << '\n';
    out.put('R');
    out.write("raw", 3);
    out.close();
    
    std::ifstream in("out.txt");
    std::string word;
    double number;
    in >> word >> number;
    in.close();

    std::cout << number << ' ' << word << std::endl;

    if (outfile.good())
    {
        std::cout << "All is good" << std::endl;
    }

    if (outfile.eof())
    {
        std::cout << "End Of File" << std::endl;
    }

    if (outfile.fail())
    {
        std::cout << "Non-critical operation failure" << std::endl;
    }

    if (outfile.bad())
    {
        std::cout << "Critical error" << std::endl;
    }

    outfile.clear(); // Сброс флагов ошибок
    outfile.close();

    std::ifstream fin1("out.txt");
    std::string word1;
    fin1 >> word1;
    // Переход в начало файла
    fin1.seekg(0, std::ios::beg); // seekg - операция для перехода на позицию для чтения // 0 - позиция для чтений 
    std::string word2;
    fin1 >> word2;
    std::cout << word1 << ' ' << word2 << std::endl;
    fin1.close();

    // Манипуляторы потока ввода/вывода
    // std::ios::dec/oct/hex --- указание чтения/записи в системе счисления. dec - десятичная, oct - восьмиричная, hex - шестнадцатиричная
    // std::dec/oct/hex
    std::cout << std::ios::dec << ' ' << 16 << std::endl;
    // std::ios::showbase -- выводить с указание системы счисления (префикс)
    // std::showbase
    // std::cout << std::hex << std::showbase << 16 << std::endl;

    // std::ios::showpos --- показывать знак числа
    // std::showpos
    std::cout << std::showpos << 51 << std::endl; 

    // std::ios::setprecision --- указать количество символов после запятой
    // std::ios::fixed --- зафиксировать положение разделяющей точки
    // std::ios::scientific --- выводить число в экспоненциальной форме
    std::cout << std::scientific << std::fixed << std::setprecision(2) << 1001.0 << std::endl;
    std::cout << std::fixed << std::setprecision(3) << std::scientific << 1001.0 << std::endl;

    // std::ios::boolalpha --- выводить true/false словами вместо 1/0
    std::cout << true << std::endl;
    std::cout << std::boolalpha << true << std::endl;

    // Методы позиционирования
    // ifstream:
    // tellg() --- текущая позиция для чтения
    // seekg(pos) --- абсолютная позиция для чтения 
    // seekg(offset, std::ios_base::seekdir) --- относительная позиция для чтения || смещение относительно точки во втором аргументе на offset  
    // ofstream:
    // tellp() --- текущая позиция для записи
    // seekp(pos)
    // seekp(offset, dir)
    // seekdir: std::ios::beg (начало файла), std::ios::cur (текущая позиция), std::ios::end(конец файла)

    return 0;
}
