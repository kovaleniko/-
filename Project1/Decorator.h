#pragma once
#include <iostream>
#include <string>
using namespace std;

//class Program
//{
//    static void Main(string[] args)
//    {
//        Pizza pizza1 = new ItalianPizza();
//        pizza1 = new TomatoPizza(pizza1); // ����������� ����� � ��������
//        Console.WriteLine("��������: {0}", pizza1.Name);
//        Console.WriteLine("����: {0}", pizza1.GetCost());
//
//        Pizza pizza2 = new ItalianPizza();
//        pizza2 = new CheesePizza(pizza2);// ����������� ����� � �����
//        Console.WriteLine("��������: {0}", pizza2.Name);
//        Console.WriteLine("����: {0}", pizza2.GetCost());
//
//        Pizza pizza3 = new BulgerianPizza();
//        pizza3 = new TomatoPizza(pizza3);
//        pizza3 = new CheesePizza(pizza3);// ���������� ����� � �������� � �����
//        Console.WriteLine("��������: {0}", pizza3.Name);
//        Console.WriteLine("����: {0}", pizza3.GetCost());
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
    ItalianPizza() : Pizza("����������� �����")
    { }
    int GetCost() override
    {
        return 10;
    }
};
class BulgerianPizza :public Pizza {
public:
    BulgerianPizza()
        :Pizza("���������� �����")
    { }
    int GetCost() override
    {
        return 8;
    }
};

class PizzaDecorator :public Pizza //���������
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
        : PizzaDecorator(p->Name_get() + ", � ��������", p)
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
        : PizzaDecorator(p->Name_get() + ", � �����", p)
    { }

    int GetCost() override
    {
        return pizza->GetCost() + 5;
    }
};

/*������������� �������� Decorator
����������� �������� ������ : ���� �������� ��������� � ��������� ��������������(��������������) "�������".
�������� ����� ��� ���� ������� ��������� �� �������� "����������� ������ ����������� ���" (lowest common denominator LCD).���� ��������� ������ ������ ��� ������ �����������������.
�������� ������� ����� ������� ������(Decorator) ��� ��������� �������������� ������������ �������.
�������� ����� � ����� Decorator ��������� ����� ��� - ���������.
����� Decorator ���������� ��������� ����������.��������� �� ��� - ������ ���������������� � ������������.
����� Decorator ���������� ���������� �������� ��� - �������.
��� ���������� ������ �������������� ���������������� �������� �����, ����������� �� Decorator.
�������� Decorator ��������� �������������� ���������������� � ���������� ���������� �������� �������� ������ Decorator.
������ ����� ��������������� �� ���������������� ������� : ������������� ���� � ������������������ ������������� ��������� ������� � �����������.

����������� �������� Decorator
Adapter ������� ������ ������� ����� ���������, Proxy ������������� ��� �� ���������, � Decorator ������������ ����������� ���������.
Adapter �������� ��������� �������.Decorator ��������� ��������������� �������.Decorator, ����� �������, ����� ��������� ��� �������.��� ���������, Decorator ������������ ����������� ����������, ��� ���������� � ������� ����������.
Decorator ����� ������������� ��� ����������� ������ Composite � ������������ �����������.������ Decorator ��������� ����� ����������� � �� ������������ ��� ������������� ��������.
Decorator ��������� ��������� ����� ������� � �������� ��� ������������.Composite ���������� �������� �� �������������, � �� �������������.��� �������������� �������� ����������, �� ������������������, ������� Composite � Decorator ����� ������������ ������.
Decorator � Proxy ����� ������ ����������, �� ������ ���������.�� ���������� ������ ������ �� ������, �������� ��� ���������� �������.
Decorator ��������� �������� ������� ����� �������, Strategy � ��� ���������� ����������.
*/
/*+ ����������
1. ������� ��������, ��� � ������������.
2. ��������� ��������� ����������� �� ����.
3. ����� ��������� ��������� ����� ������������ �����.
4. ��������� ����� ��������� ������ �������� ������ ������ ������� �� ��� ������ �����.
*/
/*- ����������
1. ������ ��������������� ����������� �������� �������.
2. ������ ��������� �������.
*/
