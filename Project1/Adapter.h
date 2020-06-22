#pragma once
#include <iostream>
#include <random>
//����������� �������� Adapter
//������� Adapter ��������� �������� ������������ ��� ��������� ���, ��������� ��� ������������� ��������� � ����, ���������� ��� �������������.
//���������� �������� Adapter
//������ �������������� ����������� ����� ��������� ��������� � ������, ���� ���������� ������ �(���) ������������ ��������� �� ����� ��������������� ������������ � ������������ �������.


// ��� ������������ ����� �������������� ������� ���������� �����
class FahrenheitSensor
{
public:
    // �������� ��������� ����������� � �������� ����������
    float getFahrenheitTemp() {
        float t = 32.0;
        // ... ����� �� ���
        return t;
    }
};

class Sensor //��������� ���������
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


class Generator {//����� ��������� ���������

public:
    virtual int next() = 0;

};

class RandomGenerator {//�� ��� �����

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
