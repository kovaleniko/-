#pragma once
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
class AlarmClockImpl;

// Интерфeйс абстракции
class AlarmClock {
private:
    virtual void toWake() = 0;
protected:
    /**
      It`s our bridge to implementation
    */
    AlarmClockImpl* bridge;
public:

    virtual void start() = 0;
    virtual void stop() = 0;

};

// Интерфейс реализации
class AlarmClockImpl {
public:
    virtual void ring() = 0;
    virtual void notify() = 0;
};

// Уточнение абстракции будильника в качестве зависающего
class LockupAlarmClock : public AlarmClock {
private:
    size_t hourAlarm;    // час расплаты
    size_t minutesAlarm;  // минута расплаты
    bool waitForWake;   // флаг признака ожидания

    virtual void toWake();
protected:
public:
    LockupAlarmClock(AlarmClockImpl& bridgeImpl, size_t hour, size_t minutes);

    virtual void start();
    virtual void stop();
};

LockupAlarmClock::LockupAlarmClock(AlarmClockImpl& bridgeImpl,size_t hour, size_t minutes) {
    this->bridge = &bridgeImpl;
    this->waitForWake = false;

    this->hourAlarm = hour;
    this->minutesAlarm = minutes;
}

// Вставай!!! Вставай!!
void LockupAlarmClock::toWake() {
    this->bridge->notify();
    this->bridge->ring();
}

// Запускаем процесс "зависания" будильника
void LockupAlarmClock::start() {
    // start lockup process
    tm timer;
    waitForWake = true;

    while (waitForWake) {
        time_t t;
        time(&t);
        localtime_s(&timer,&t);

        if (timer.tm_hour == this->hourAlarm && timer.tm_min == this->minutesAlarm) {
            waitForWake = false;
        }

        for (int i = 0; i < 1e6;++i);
    }

    toWake();
}

void LockupAlarmClock::stop() {
    // stop lockup process
    waitForWake = false;
}

// Уточнение интерфейса реализации в качестве будильника, играющего MP3 через внешнюю команду
class ShellMP3AlarmClock : public AlarmClockImpl {
private:
    string cmdplay; // сама команда
protected:
public:
    ShellMP3AlarmClock(const string& cmd);
    ~ShellMP3AlarmClock() {};

    virtual void ring();
    virtual void notify();

};

ShellMP3AlarmClock::ShellMP3AlarmClock(const string& cmd) {
    this->cmdplay = cmd;
}

void ShellMP3AlarmClock::ring() {
    // run command
    system(cmdplay.c_str());
}

void ShellMP3AlarmClock::notify() {
    cout << "ALARMING!" << endl;
}

class SimpleRing : public AlarmClockImpl {

public:
    virtual void ring() {
        cout << char(7) << char(7) << char(7);
    };
    virtual void notify() { cout << "BELL!!! bell"; };
};

/*+ достоинтсва
1. Позволяет строить платформо-независимые программы.
2. Скрывает лишние или опасные детали реализации от клиентского кода.
3. Реализует принцип открытости/закрытости.
*/
/*- недостатки
1. Усложняет код программы из-за введения дополнительных классов.
*/