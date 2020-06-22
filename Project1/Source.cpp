//https://refactoring.guru/ru/design-patterns/bridge
#include "Adapter.h"
#include "Bridge.h"
#include "Proxy.h"
#include "Composite.h"
#include "Decorator.h"
#include "Flyweight.h"
#include "Facade.h"

int main()
{
   /* Sensor* p = new Adapter(new FahrenheitSensor);
    cout << "Celsius temperature = " << p->getTemperature() << endl;
    delete p;*/

    /*SimpleRing r;
    LockupAlarmClock bell(r,10,37);
    bell.start();*/
   
    proxy_h();
    //setlocale(LC_ALL, "");
    //facade();
    //composite();
    return 0;
}