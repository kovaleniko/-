#pragma once
#include <iostream>
#include <string>
using namespace std;
class Person
{
    string nameString;
    static string list[];
    static int next;
public:
    Person()
    {
        nameString = list[next++];
    }
    string name()
    {
        return nameString;
    }
};
string Person::list[] =
{
  "Tom", "Dick", "Harry", "Bubba"
};
int Person::next = 0;

class PettyCashProtected
{
    int balance;
public:
    PettyCashProtected()
    {
        balance = 500;
    }
    bool withdraw(int amount)
    {
        if (amount > balance)
            return false;
        balance -= amount;
        return true;
    }
    int getBalance()
    {
        return balance;
    }
};

class PettyCash // proxy
{
    PettyCashProtected realThing;
public:
    bool withdraw(Person& p, int amount)
    {
        if (p.name() == "Tom" || p.name() == "Harry"
            || p.name() == "Bubba")
            return realThing.withdraw(amount);
        else
            return false;
    }
    int getBalance()
    {
        return realThing.getBalance();
    }
};

int proxy_h()
{
    PettyCash pc;
    Person workers[4];
    for (int i = 0, amount = 100; i < 4; i++, amount += 100)
        if (!pc.withdraw(workers[i], amount))
            cout << "No money for " << workers[i].name() << '\n';
        else
            cout << amount << " dollars for " << workers[i].name() << '\n';
    cout << "Remaining balance is " << pc.getBalance() << '\n';
    return 0;
}
/*Существует четыре ситуации, когда можно использовать паттерн Proxy :

Виртуальный proxy является заместителем объектов, создание которых обходится дорого.Реальный объект создается только при первом запросе / доступе клиента к объекту.
Удаленный proxy предоставляет локального представителя для объекта, который находится в другом адресном пространстве("заглушки" в RPC и CORBA).
Защитный proxy контролирует доступ к основному объекту. "Суррогатный" объект предоставляет доступ к реальному объекту, только вызывающий объект имеет соответствующие права.
Интеллектуальный proxy выполняет дополнительные действия при доступе к объекту.
Вот типичные области применения интеллектуальных proxy :

Подсчет числа ссылок на реальный объект.При отсутствии ссылок память под объект автоматически освобождается(известен также как интеллектуальный указатель или smart pointer).
Загрузка объекта в память при первом обращении к нему.
Установка запрета на изменение реального объекта при обращении к нему других объектов.*/
