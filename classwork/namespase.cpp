#include <iostream>

const int N = 5;
static const float pi = 3.14;
constexpr int K = 7;
constexpr int function(){
    return K;
}
namespace myspace{
    int r = 1;
    int function(){
        return 0;
    }
    namespace otherspase
    {
        namespace run{
            int r = 3;
        }
    } // namespace otherspase
    
}
 namespace run = myspace::otherspase::run;

double add(double a, double b){
    double c = a + b;
    return c;

}


  int main(){
    myspace::r;
    std::cout << "" << std::endl;
    myspace::otherspase::run::r;



    // начало main тут // пример работы stack
    int x = 3;
    int y = 5;
    double z = add(x, y);
    // конец примера 

    // указатели и ссылки 
    int& intref = x;
    int* pointer_x = &x;
    //std::cout << "adress  __  " << pointer_x << std::endl;
    //std::cout << "ссылка по адресу ___" << *pointer_x << std::endl;
    //std::cout << intref << std::endl;
    //std::cout << x << std::endl;

    // создание переменной под которую выделять память 
    int* mypointerint = new int;
    //std::cout << mypointerint << std::endl;
    //std::cout << *mypointerint << std::endl;
    //*mypointerint = 9;


    int* b = new int[4];
    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    b[3] = 4;
    b += 2;
    std::cout << *b << std::endl;


    //std::cout << add(3,4);
  }


  // text -- текстовые данные 
  // data -- глобальные переменные, данные программы
  // lcap, куча  -- переменные под которые мы сами выделяем память(в коде их поа нет) 
  // new, delete, delete[] -- переменные для создания и удаления кучных данных
  // stack -- локальные переменные(его можно переполнить)
  // ПРИМЕР РАБОТЫ stack (можно брать только верхний элемент)
  // очередь от первого до последнего 