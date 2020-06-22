#pragma once
#include <iostream>
using namespace std;


// текстовый редактор
class TextEditor
{
public:
    void CreateCode()
    {
        cout << R"("Написание кода")" << endl;
    }
    void Save()
    {
        cout << "Сохранение кода\n";
    }
};
class Compiller
{
public:
    void Compile()
    {
        cout << "Компиляция приложения\n";
    }
};
class CLR
{
public:
    void Execute()
    {
        cout << "Выполнение приложения\n";
    }
    void Finish()
    {
        cout << "Завершение работы приложения\n";
    }
};

class VisualStudioFacade
{
    TextEditor* textEditor = nullptr;
    Compiller* compiller = nullptr;
    CLR* clr = nullptr;
public:
    VisualStudioFacade(TextEditor* te, Compiller* compil, CLR* clr)
    {
        textEditor = te;
        compiller = compil;
        clr = clr;
    }
    void Start()
    {
        textEditor->CreateCode();
        textEditor->Save();
        compiller->Compile();
        clr->Execute();
    }
    void Stop()
    {
        clr->Finish();
    }
    ~VisualStudioFacade() {
        if (textEditor)delete textEditor;
        if (compiller) delete compiller;
        if (clr) delete clr;
    }
};

class Programmer
{
public:
    void CreateApplication(VisualStudioFacade* facade)
    {
        facade->Start();
        facade->Stop();
    }
};


 void facade()
    {
        TextEditor* textEditor = new TextEditor();
        Compiller* compiller = new Compiller();
        CLR* clr = new CLR();

        VisualStudioFacade* ide = 
            new VisualStudioFacade(textEditor, compiller, clr);

        Programmer* programmer = new Programmer();
        programmer->CreateApplication(ide);


}
/*
+
 Изолирует клиентов от компонентов сложной подсистемы.

-
 Фасад рискует стать божественным объектом, привязанным ко всем классам программы.

 */
/*
Использование паттерна Facade
Определите для подсистемы простой, унифицированный интерфейс.
Спроектируйте класс "обертку", инкапсулирующий подсистему.
Вся сложность подсистемы и взаимодействие ее компонентов скрыты от клиентов. "Фасад" / "обертка" переадресует пользовательские запросы подходящим методам подсистемы.
Клиент использует только "фасад".
Рассмотрите вопрос о целесообразности создания дополнительных "фасадов".
*/