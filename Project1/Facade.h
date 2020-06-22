#pragma once
#include <iostream>
using namespace std;


// ��������� ��������
class TextEditor
{
public:
    void CreateCode()
    {
        cout << R"("��������� ����")" << endl;
    }
    void Save()
    {
        cout << "���������� ����\n";
    }
};
class Compiller
{
public:
    void Compile()
    {
        cout << "���������� ����������\n";
    }
};
class CLR
{
public:
    void Execute()
    {
        cout << "���������� ����������\n";
    }
    void Finish()
    {
        cout << "���������� ������ ����������\n";
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
 ��������� �������� �� ����������� ������� ����������.

-
 ����� ������� ����� ������������ ��������, ����������� �� ���� ������� ���������.

 */
/*
������������� �������� Facade
���������� ��� ���������� �������, ��������������� ���������.
������������� ����� "�������", ��������������� ����������.
��� ��������� ���������� � �������������� �� ����������� ������ �� ��������. "�����" / "�������" ������������ ���������������� ������� ���������� ������� ����������.
������ ���������� ������ "�����".
����������� ������ � ���������������� �������� �������������� "�������".
*/