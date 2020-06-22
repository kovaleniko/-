#pragma once
#include <iostream>
#include <random>
//Достоинства паттерна Adapter
//Паттерн Adapter позволяет повторно использовать уже имеющийся код, адаптируя его несовместимый интерфейс к виду, пригодному для использования.
//Недостатки паттерна Adapter
//Задача преобразования интерфейсов может оказаться непростой в случае, если клиентские вызовы и(или) передаваемые параметры не имеют функционального соответствия в адаптируемом объекте.


// Уже существующий класс температурного датчика окружающей среды
class FahrenheitSensor
{
public:
    // Получить показания температуры в градусах Фаренгейта
    float getFahrenheitTemp() {
        float t = 32.0;
        // ... какой то код
        return t;
    }
};

class Sensor //требуемый интерфейс
{
public:
    virtual ~Sensor() {}
    virtual float getTemperature() = 0;
};

class Adapter : public Sensor
{
public:
    Adapter(FahrenheitSensor* p) : p_fsensor(p) {
    }
    ~Adapter() {
        delete p_fsensor;
    }
    float getTemperature() {
        return (p_fsensor->getFahrenheitTemp() - 32.0) * 5.0 / 9.0;
    }
private:
    FahrenheitSensor* p_fsensor;
};


class Generator {//класс требующий интерфейс

public:
    virtual int next() = 0;

};

class RandomGenerator {//то что имеем

public:
    int getRandomNumber() {
        std::random_device rand_new;
        return rand_new();
    }
};

class RandomGeneratorAdapter :
    public RandomGenerator, public Generator {

public:
    int next() {
        return getRandomNumber();
    }

};
