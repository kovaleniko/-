#pragma once
#include <iostream>
#include <vector>
#include <assert.h>

// Component 
class Unit
{
public:
    virtual int getStrength() = 0;
    virtual void addUnit(Unit* p) {
        assert(false);
    }
    virtual ~Unit() {}
};

// Primitives
class Archer : public Unit
{
public:
    virtual int getStrength() {
        return 1;
    }
};

class Infantryman : public Unit
{
public:
    virtual int getStrength() {
        return 2;
    }
};

class Horseman : public Unit
{
public:
    virtual int getStrength() {
        return 3;
    }
};


// Composite
class CompositeUnit : public Unit
{
public:
    int getStrength() {
        int total = 0;
        for (int i = 0; i < c.size(); ++i)
            total += c[i]->getStrength();
        return total;
    }
    void addUnit(Unit* p) {
        c.push_back(p);
    }
    ~CompositeUnit() {
        for (int i = 0; i < c.size(); ++i)
            delete c[i];
    }
private:
    std::vector<Unit*> c;
};


// Вспомогательная функция для создания легиона
CompositeUnit* createLegion()
{
    // Римский легион содержит:
    CompositeUnit* legion = new CompositeUnit;
    // 3000 тяжелых пехотинцев
    for (int i = 0; i < 3000; ++i)
        legion->addUnit(new Infantryman);

    // 1200 лучников
    for (int i = 0; i < 1200; ++i)
        legion->addUnit(new Archer);
    // 300 всадников
    for (int i = 0; i < 300; ++i)
        legion->addUnit(new Horseman);

    return legion;
}

int composite()
{
    // Римская армия состоит из 4-х легионов
    CompositeUnit* army = new CompositeUnit;
    for (int i = 0; i < 4; ++i)
        army->addUnit(createLegion());

    cout << "Roman army damaging strength is "
        << army->getStrength() << endl;
    // …
    delete army;
    return 0;
}


/*Достоинства паттерна Composite
1. В систему легко добавлять новые примитивные или составные объекты, так как
паттерн Composite использует общий базовый класс Component.
2. Код клиента имеет простую структуру – примитивные и составные объекты обрабатываются одинаковым образом.
3. Паттерн Composite позволяет легко обойти все узлы древовидной структуры


Недостатки паттерна Composite
1. Неудобно осуществить запрет на добавление в составной объект Composite 
объектов определенных типов.Так, например, в состав римской армии не могут 
входить боевые слоны.
2. Создаёт слишком общий дизайн классов.
*/