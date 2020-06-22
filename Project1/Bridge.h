#pragma once
#include <iostream>
#include <string>
#include <time.h>

using namespace std;
class AlarmClockImpl;

// ������e�� ����������
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

// ��������� ����������
class AlarmClockImpl {
public:
    virtual void ring() = 0;
    virtual void notify() = 0;
};

// ��������� ���������� ���������� � �������� �����������
class LockupAlarmClock : public AlarmClock {
private:
    size_t hourAlarm;    // ��� ��������
    size_t minutesAlarm;  // ������ ��������
    bool waitForWake;   // ���� �������� ��������

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

// �������!!! �������!!
void LockupAlarmClock::toWake() {
    this->bridge->notify();
    this->bridge->ring();
}

// ��������� ������� "���������" ����������
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

// ��������� ���������� ���������� � �������� ����������, ��������� MP3 ����� ������� �������
class ShellMP3AlarmClock : public AlarmClockImpl {
private:
    string cmdplay; // ���� �������
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

/*+ �����������
1. ��������� ������� ���������-����������� ���������.
2. �������� ������ ��� ������� ������ ���������� �� ����������� ����.
3. ��������� ������� ����������/����������.
*/
/*- ����������
1. ��������� ��� ��������� ��-�� �������� �������������� �������.
*/