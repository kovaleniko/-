#pragma once
#include <iostream>
#include <string>
using namespace std;

//class Program
//{
//    static void Main(string[] args)
//    {
//        Pizza pizza1 = new ItalianPizza();
//        pizza1 = new TomatoPizza(pizza1); // итальянская пицца с томатами
//        Console.WriteLine("Название: {0}", pizza1.Name);
//        Console.WriteLine("Цена: {0}", pizza1.GetCost());
//
//        Pizza pizza2 = new ItalianPizza();
//        pizza2 = new CheesePizza(pizza2);// итальянская пиццы с сыром
//        Console.WriteLine("Название: {0}", pizza2.Name);
//        Console.WriteLine("Цена: {0}", pizza2.GetCost());
//
//        Pizza pizza3 = new BulgerianPizza();
//        pizza3 = new TomatoPizza(pizza3);
//        pizza3 = new CheesePizza(pizza3);// болгарская пиццы с томатами и сыром
//        Console.WriteLine("Название: {0}", pizza3.Name);
//        Console.WriteLine("Цена: {0}", pizza3.GetCost());
//
//        Console.ReadLine();
//    }
//}

class Pizza
{
    string Name;
public:
    Pizza(string n) {
        this->Name = n;
    }
    string Name_get()const {
        return Name;
    }
    void set(string& n) { Name = n; };
    virtual int GetCost()=0;
};

class ItalianPizza :public Pizza
{
public:
    ItalianPizza() : Pizza("Итальянская пицца")
    { }
    int GetCost() override
    {
        return 10;
    }
};
class BulgerianPizza :public Pizza {
public:
    BulgerianPizza()
        :Pizza("Болгарская пицца")
    { }
    int GetCost() override
    {
        return 8;
    }
};

class PizzaDecorator :public Pizza //декоратор
{
protected:
    Pizza* pizza;
public:
    PizzaDecorator(string n, Pizza* pizza) : Pizza(n)
    {
        this->pizza = pizza;
    }
};

class TomatoPizza :public  PizzaDecorator
{
public:
    TomatoPizza(Pizza* p)
        : PizzaDecorator(p->Name_get() + ", с томатами", p)
    { }

    int GetCost()override
    {
        return pizza->GetCost() + 3;
    }
};

class CheesePizza :public  PizzaDecorator
{
public:
    CheesePizza(Pizza* p)
        : PizzaDecorator(p->Name_get() + ", с сыром", p)
    { }

    int GetCost() override
    {
        return pizza->GetCost() + 5;
    }
};

/*Использование паттерна Decorator
Подготовьте исходные данные : один основной компонент и несколько дополнительных(необязательных) "оберток".
Создайте общий для всех классов интерфейс по принципу "наименьшего общего знаменателя НОЗ" (lowest common denominator LCD).Этот интерфейс должен делать все классы взаимозаменяемыми.
Создайте базовый класс второго уровня(Decorator) для поддержки дополнительных декорирующих классов.
Основной класс и класс Decorator наследуют общий НОЗ - интерфейс.
Класс Decorator использует отношение композиции.Указатель на НОЗ - объект инициализируется в конструкторе.
Класс Decorator делегирует выполнение операции НОЗ - объекту.
Для реализации каждой дополнительной функциональности создайте класс, производный от Decorator.
Подкласс Decorator реализует дополнительную функциональность и делегирует выполнение операции базовому классу Decorator.
Клиент несет ответственность за конфигурирование системы : устанавливает типы и последовательность использования основного объекта и декораторов.

Особенности паттерна Decorator
Adapter придает своему объекту новый интерфейс, Proxy предоставляет тот же интерфейс, а Decorator обеспечивает расширенный интерфейс.
Adapter изменяет интерфейс объекта.Decorator расширяет ответственность объекта.Decorator, таким образом, более прозрачен для клиента.Как следствие, Decorator поддерживает рекурсивную композицию, что невозможно с чистыми адаптерами.
Decorator можно рассматривать как вырожденный случай Composite с единственным компонентом.Однако Decorator добавляет новые обязанности и не предназначен для агрегирования объектов.
Decorator позволяет добавлять новые функции к объектам без наследования.Composite фокусирует внимание на представлении, а не декорировании.Эти характеристики являются различными, но взаимодополняющими, поэтому Composite и Decorator часто используются вместе.
Decorator и Proxy имеют разное назначение, но схожие структуры.Их реализации хранят ссылку на объект, которому они отправляют запросы.
Decorator позволяет изменить внешний облик объекта, Strategy – его внутреннее содержание.
*/
/*+ декоратора
1. Большая гибкость, чем у наследования.
2. Позволяет добавлять обязанности на лету.
3. Можно добавлять несколько новых обязанностей сразу.
4. Позволяет иметь несколько мелких объектов вместо одного объекта на все случаи жизни.
*/
/*- декоратора
1. Трудно конфигурировать многократно обёрнутые объекты.
2. Обилие крошечных классов.
*/
