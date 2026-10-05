#include <iostream>
#include <cmath>


int main() {
    char a = 'g';
    std::cout << "Type char: " << sizeof(a) << std::endl;
    unsigned char b = 'g';
    std::cout << "Type unsigned char: " << sizeof(b) << std::endl;
    //
    int с = 4;
    std::cout << "Type int: " << sizeof(с) << std::endl;
    //если целочисленные значения могут быть отрицательными, используем int
    short int d = 4;
    std::cout << "Type short int: " << sizeof(d) << std::endl;
    //если мало памяти 
    long int e = 4;
    std::cout << "Type long int: " << sizeof(e) << std::endl;
    //если нужно хранить большие значения, но нарушает принципы кроссплатформменной разработки (хранит данные по-разному , зависит от системы)
    long long int f = 4;
    std::cout << "Type long long int: " << sizeof(f) << std::endl;
    //если нужно хранить очень большие значения, но нарушает принципы кроссплатформменной разработки (хранит данные по-разному , зависит от системы)    
    //суффиксы  целочисленных типов данных
    long long int g = 4LL;
    unsigned long long int h = 4ULL;
    unsigned int i = 4U;

    // числа с плавающе й точкой
    float j = 4.3f;
    std::cout << "Type float: " << sizeof(j) << std::endl;
    double k = 4.3;
    std::cout << "Type double: " << sizeof(k) << std::endl;
    long double l = 4.3L;
    std::cout << "Type long double: " << sizeof(l) << std::endl;

    // 1 бит - знак
    // x бит - мантисса       float x = 24 бит || double x = 52 бита 
    // y бит - экспонента     float y = 7 бит || double y = 11 бит

    // мантисса : 1.abcdef
    // экспонента : 2^(y)
    // value = (-1)^sign * (1 + mantissa/2^x) * 2^(exponent - (2^y-1))
    // sign - знак (0 или 1 для + и -)
    // mantissa - число в двоичном представлении c x символами (целое число от 0 до 2^x-1)
    // exponent - число в двоичном представлении с y символами (целое число от 0 до 2^y-1)
    // 1. abcdef

    //2. 2^y
    // точность float = 2^-24
    std::cout << "Point precision of float: " << std::pow(2.0L, -24) << std::endl;
    // точность double = 2^-52
    std::cout << "Point precision of double: " << std::pow(2.0L, -52) << std::endl;

    long double m = 4.3;
    std::cout << "Type long double: " << sizeof(m) << std::endl;
    // точность long double = 2^-64
    std::cout << "Point precision of long double: " << std::pow(2.0L, -64) << std::endl;

                                                    // числовые типы закончилися
                                                    // logical types
    bool n = true;
    std::cout << "Type bool: " << sizeof(n) << std::endl;
    // 00000000 - folse 
    // 00101001 - true (что угодно кроме 00000000)

    void *o = nullptr;
    std::cout << "Type void*: " << sizeof(o) << std::endl;






    //преобрпзование типов данных

    int p = 3.14;
    std::cout << "int(3.14): " << p << std::endl;


    // явное приведение типов данных
    double q = (double)3;
    std::cout << "double(3): " << q << std::endl;

    double lbt = static_cast<double>(3);
    std::cout << "double(3) with static_cast: " << lbt << std::endl;

    // dynamic_cast<double>(3); // работает только с полиморфными типами данных
    //reinterpret_cast<double>(3); // работает только с полиморфными типами данных
    double r = 1 / 2;
    std::cout << "1 / 2: " << r << "WARNING: Integer division" << std::endl;

    double fit = 1 / (double)2;
    std::cout << "1 / (double)2: " << fit << std::endl << std::endl;

    // operator sizeof() - возвращает размер типа данных в байтах
    // operator typeid() - возвращает тип данных в виде строки
    // operator decltype() - возвращает тип данных переменной
    // operator typeid().name() - возвращает имя типа данных в виде строки
    // operator cin - используется для ввода данных с клавиатуры
    // operator cout - используется для вывода данных на экран
    // operator endl - используется для вывода перевода строки на экран сбрасывает буфер (/n не сбрасывает буфер вывода)
    // operator cerr - используется для вывода ошибок на экран(сохраняет в буфер отдельно от cout) 
    // operator clog - используется для вывода логов на экран(сохраняет в буфер отдельно от cout)
    // operator new - используется для выделения памяти в динамической памяти
    // operator delete - используется для освобождения памяти в динамической памяти


    // арифметические операторы
    int s = 5;
    int t = 2;

    std::cout << "s: " << s << std::endl;
    std::cout << "t: " << t  << std::endl << std::endl << std::endl;

    std::cout << "s + t: " << s + t << std::endl;
    std::cout << "s - t: " << s - t << std::endl;
    std::cout << "s * t: " << s * t << std::endl;
    std::cout << "s / t: " << s / t << std::endl;
    std::cout << "s % t: " << s % t << std::endl;
    std::cout << "s++(сначала записывается в переменную, а затем значение увеличивается): " << s++ << std::endl;  
    std::cout << "++s(сначала операция инкремента , апосле значение будет записано): " << ++s << std::endl;
    std::cout << "s--(сначала записывается в переменную, а затем значение уменьшается): " << s-- << std::endl;
    std::cout << "--s(сначала операция декремента , апосле значение будет записано): " << --s << std::endl;
    std::cout << "s += t: " << (s += t) << std::endl;
    std::cout << "s -= t: " << (s -= t) << std::endl;
    std::cout << "s *= t: " << (s *= t) << std::endl;
    std::cout << "s /= t: " << (s /= t) << std::endl;
    std::cout << "s %= t: " << (s %= t) << std::endl;

    std::cout << std::endl;
    std::cout << "логические операторы" << std::endl;
    std::cout << "s == t: " << (s == t) << std::endl;
    std::cout << "s != t: " << (s != t) << std::endl;
    std::cout << "s > t: " << (s > t) << std::endl;
    std::cout << "s < t: " << (s < t) << std::endl;
    std::cout << "s >= t: " << (s >= t) << std::endl;
    std::cout << "s <= t: " << (s <= t) << std::endl;
    std::cout << "s && t: " << (s && t) << std::endl;
    std::cout << "s || t: " << (s || t) << std::endl;
    std::cout << "!s: " << (!s) << std::endl;

    /* 
    это многострочный комментарий
    
    
    */

    int x = 0;
    int y = 9;

    // Защита от деления на ноль
    if (x == 0) {
        std::cout << "Division by zero, aborting\n";
        return 1;
    }

    int result = y / x;
    std::cout << "result = " << result << '\n';

    // Проверка на равенство самой себе — всегда true, бессмысленно
    bool same = (result == result);
    std::cout << "same = " << same << '\n';

    // Короткая схема: y/x не вычислится, если x == 0
    bool conditional = (x == 0) || (y / x);
    std::cout << "conditional = " << conditional << '\n';

        bool condition = (4 < 5) && (0 == 0);
    bool condition1 = (4 > 5) || (0 == 0);
    bool condition2 = !condition;

    int x = 0;
    int y = 9;
    // int result = y / x; // NaN
    // std::cout << "result 9/0: " << result << std::endl;
    bool expr1 = (std::numeric_limits<int>::quiet_NaN() == std::numeric_limits<int>::quiet_NaN());
    bool expr2 = x == x;
    std::cout << "NaN == NaN: " << expr1 << std::endl; // В результате работы программы должно быть false
    bool condition3 = (x == 0) || (y / x);
    std::cout << "(x == 0) || (y / x): " << condition3 << std::endl;

    // Оператор присвоения
    int parameter; // объявление
    parameter = 5; // определение
    int parameter1 = 5; // объявление + определение = инициализация
    parameter1 += 5; // parameter1 = parameter1 + 5; Аналогично для операторов -=, /=, *=, %=

    int parameter2 = (condition) ? (1) : (0); // int parameter2 = (condition) ? (true_result) : (false_result); 

    int int_max = std::numeric_limits<int>::max();
    std::cout << "int_max: " << int_max << std::endl;
    int_max += 1;
    std::cout << "int_max + 1: " << int_max << std::endl;
    std::cout << "int_min: " << std::numeric_limits<int>::min() << std::endl;

    double double_max = std::numeric_limits<double>::max();
    std::cout << "double_max: " << double_max << std::endl;
    double_max *= 10.0;
    std::cout << "double_max * 10.0: " << double_max << std::endl;
    std::cout << "double_inf: " << std::numeric_limits<double>::infinity() << std::endl;
    // В числах double существует +0 и -0. При этом +0 == -0 

    // Условный оператор if
    if (int if_parameter1 = 4, if_parameter2 = 5; condition || if_parameter1 + 1 == if_parameter2)
    {
        ;;;;;; // condition == true
        if_parameter1 = if_parameter2;
    }
    else if (condition1)
    {
        ;;;;;; // condition1 == true
        if_parameter2;
    }
    else if (condition2)
    {
        ;;;;;
    }
    else
    {
        ;;;;; // condition == false && condition1 == false && ...
    }

    enum Arrrr
    {
        Case1 = 0,
        Case2 = 1,
        End = 2
    };

    enum class Ar : int
    {
        Case1 = 0,
        Case2 = 1,
        End = 2
    };

    Ar enum_class_parameter = Ar::Case2;
    int enum_class_int = static_cast<int>(enum_class_parameter);

    // Условный оператор switch-case
    int switch_parameter = 13;
    switch (Arrrr enum_parameter; enum_parameter)
    {
    case Arrrr::Case1:
        /* code */
        break;
    case Arrrr::Case2:
        /* code */
        break;
    case 3:
    {
        int inner_switch_parameter = 4; // Если внутри case у switch объявляется переменная, то код кейса пишется внутри {}
        break;
    }
    default:
        /* code */
        break;
    }

    // Цикл while
    while (condition) // Нет секции инициализации
    {
        // condition проверяется в начале итерации
        ;;;; // Выполняется, пока condition == true
        if (condition1)
        {
            break; // Принудительно выйти из цикла
        }

        if (condition2)
        {
            x = y;
            continue; // Принудительно перейти к следующей итерации
        }

        ;;;;;;
    }

    // Цикл do-while
    do
    {
        /* code */
        // condition проверяется в конце итерации
        continue;
        break;
    } while (condition); // Нет секции инициализации
    
    // Цикл for
    for (int counter = 0; counter < 10; counter++) // for (секция инициализации; секция условия; секция поститерации)
    {
        // Перед каждой итерацией проверяется условие из секции условия

        // После каждой итерации происходит действие из секции поститерации
    }

    for (;condition;) // Аналогично циклу while
    {
        continue;
        break;
    }

    // Функции
    // Сигнатура функции: return_type function_name(arg1_type arg1, arg2_type arg2, .........) {   return function_result;   }
    int function_result = function(1, x, "string");

    int function_with_defaults_result = function_with_defaults(2); // Использую значения по умолчанию
    int function_with_defaults_result1 = function_with_defaults(2, 2.0); // Хочу задать b сам
    int function_with_defaults_result2 = function_with_defaults(2, 2.0, "value"); // Если хочу указать c, то должен задать и b

    int res = function(1, 2, "");

    return 0;
}
