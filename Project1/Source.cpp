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
    //Sensor* p = new Adapter(new FahrenheitSensor);
    //cout << "Celsius temperature = " << p->getTemperature() << endl;
    //delete p;

    //Generator* r = new RandomGeneratorAdapter;
    //std::cout << "random " << r->next() << endl;
    /*SimpleRing r;
    LockupAlarmClock bell(r,19,34);
    bell.start();
   */
    //proxy_h();
    setlocale(LC_ALL, "");
    //facade();
    //composite();
    //flyweight();
    //Pizza* pz = new TomatoPizza(new ItalianPizza);
    //std::cout<<pz->Name_get()<<std::endl;
    //Pizza* bpz = new BulgerianPizza;
    //bpz = new CheesePizza(bpz);
    //std::cout << bpz->Name_get() << " " << bpz->GetCost() << std::endl;
    return 0;
}