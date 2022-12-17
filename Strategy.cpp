
#include <iostream>

using namespace std;

class QuackBehavior {
public:
    virtual void quack() = 0;   //вид громкости  будет  воспроизведен в дочерних классах
};

class SimpleQuack : public QuackBehavior {       //Обычный звук
public:
    void quack() {
        cout << "vrrrrrr\n";
    }
};

class PiskQuack : public QuackBehavior {      // громче
public:
    void quack() {
        cout << "vruuaaaaammm\n";
    }
};

class NoQuack : public QuackBehavior {
public:
    void quack() {
        //класс для тишины
    }
};

class ToyDuck {
    QuackBehavior* behavior; //выборщик необходимого поведения
public:
    void quack(QuackBehavior* b) {    //пишем метод, вызывающий звук
        behavior = b;   //значение параметра обязательно передать объекту-выборщику
        b->quack();
    }
};

class TreeDuck : public ToyDuck {};

class RubberDuck : public ToyDuck {};

class GlassDuck : public ToyDuck {};

int main()
{
    ToyDuck* td = new TreeDuck();       
    ToyDuck* rd = new RubberDuck();     
    ToyDuck* gd = new GlassDuck();      


    QuackBehavior* quack_view;   //способ издавать звук

    SimpleQuack simple_quack;      //набор поведений
    PiskQuack  pisk_quack;

    cout << "car is engine on : ";
    quack_view = &simple_quack;  //сначала выбираем способ звука
    td->quack(quack_view); //потом не забываем его заказывать в круглых скобках 


    cout << "engine on  a gazaline: ";
    quack_view = &pisk_quack;
    td->quack(quack_view); //звук машины с бензиновым двигателем

    cout << "engine on a disel : ";
    rd->quack(quack_view); //звук машины с дизелем


    delete td;
    delete rd;
    delete gd;
}