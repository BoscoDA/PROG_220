#include <iostream>

// SOLID - Guidelines, not written in blood rules, always have a reason to break them.
// S - Single Responsibillity Principle
//     - Class should do one thing and one thing only
// O - Open Closed Principle
//     - Never modify a class, add new functinality in sub class (for backwards compatability)
// L - Liskov's Substitution Principle
//     - Any subclass can be used to substitute the super class
// I - Dependency Inversion Principle
//     -
// D - Dependency Inversion Principle
//     -

// S
class Scanner
{
public:
    virtual void scan();
};

class Printer
{
public:
    void print() {}
};

// O I
enum ColorType
{
    RGB,
    CMYK
};

class HardwareScanner
{
public:
    void init();
    void scan();
    void shutdown();
};

class ColorScanner : public Scanner, public Printer
{
protected:
    ColorType m_color_type;
    HardwareScanner *m_hw_scanner;

public:
    ColorScanner()
    {
        this->m_hw_scanner = new HardwareScanner();
    }
    ~ColorScanner() { delete this->m_hw_scanner; }
    void scan()
    {
        this->m_hw_scanner->init();
        this->m_hw_scanner->scan();
        this->m_hw_scanner->shutdown();
    }
};

struct ScannerFactory
{
    Scanner *Create();
};

// L
class A
{
    Scanner *m_scanner;
    Printer *m_printer;

public:
    A(Scanner *scanner, Printer *printer)
    {
        this->m_scanner = scanner;
        this->m_printer = printer;
    }

    void run()
    {
        this->m_scanner->scan();
        this->m_printer->print();
    }
};

int main()
{
    ColorScanner *colorScanner = new ColorScanner();
    A *a = new A(colorScanner, colorScanner);
    delete colorScanner;
}