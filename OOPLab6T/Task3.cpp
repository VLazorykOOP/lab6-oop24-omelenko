#include <iostream>
#include <string>
using namespace std;

class WaterBody 
{
protected:
    string name; // Назва водойми
    double area; // Площа (км?)
public:
    WaterBody(const string& name_ = "Unknown", double area_ = 0.0) : name(name_), area(area_) {}

    virtual ~WaterBody() {}

    friend ostream& operator<<(ostream& os, const WaterBody& wb) 
    {
        os << "Name: " << wb.name << ", Area: " << wb.area << " km?";
        return os;
    }

    friend istream& operator>>(istream& is, WaterBody& wb) 
{
        cout << "Enter name: ";
        is >> wb.name;
        cout << "Enter area (km?): ";
        is >> wb.area;
        return is;
    }

    string getName() const { return name; }
    double getArea() const { return area; }
};

class Gulf : virtual public WaterBody 
{
protected:
    double depth; // Глибина (м)
public:
    Gulf(const string& name_ = "Unknown", double area_ = 0.0, double depth_ = 0.0) : WaterBody(name_, area_), depth(depth_) {}

    virtual ~Gulf() {}

    friend ostream& operator<<(ostream& os, const Gulf& g) 
    {
        os << static_cast<const WaterBody&>(g) << ", Depth: " << g.depth << " m";
        return os;
    }

    friend istream& operator>>(istream& is, Gulf& g) 
    {
        is >> static_cast<WaterBody&>(g);
        cout << "Enter depth (m): ";
        is >> g.depth;
        return is;
    }

    double getDepth() const { return depth; }
};


class Bay : virtual public WaterBody 
{
protected:
    double shoreLength; // Довжина берегової лінії (км)
public:
    Bay(const string& name_ = "Unknown", double area_ = 0.0, double shoreLength_ = 0.0) : WaterBody(name_, area_), shoreLength(shoreLength_) {}

    virtual ~Bay() {}

    friend ostream& operator<<(ostream& os, const Bay& b) 
    {
        os << static_cast<const WaterBody&>(b) << ", Shore Length: " << b.shoreLength << " km";
        return os;
    }

    friend istream& operator>>(istream& is, Bay& b) 
    {
        is >> static_cast<WaterBody&>(b);
        cout << "Enter shore length (km): ";
        is >> b.shoreLength;
        return is;
    }

    double getShoreLength() const  { return shoreLength; }
};

class Sea : public Gulf, public Bay 
{
private:
    double saltiness; // Солоність (‰)
public:
    Sea(const string& name_ = "Unknown", double area_ = 0.0, double depth_ = 0.0,  double shoreLength_ = 0.0, double saltiness_ = 0.0)
        : WaterBody(name_, area_), Gulf(name_, area_, depth_),
        Bay(name_, area_, shoreLength_), saltiness(saltiness_)  {}

    virtual ~Sea() {}

    friend ostream& operator<<(ostream& os, const Sea& s) 
    {
        os << "Sea - Name: " << s.getName() << ", Area: " << s.getArea()
            << " km?, Depth: " << s.getDepth() << " m, Shore Length: "
            << s.getShoreLength() << " km, Salinity: " << s.saltiness << "‰";
        return os;
    }

    friend istream& operator>>(istream& is, Sea& s) 
    {
        is >> static_cast<Gulf&>(s);
        cout << "Enter shore length (km): ";
        is >> s.shoreLength;
        cout << "Enter saltiness (‰): ";
        is >> s.saltiness;
        return is;
    }

    void print() const 
    {
        cout << "Sea Information (including inherited fields):\n";
        cout << "Name: " << getName() << "\n";
        cout << "Area: " << getArea() << " km?\n";
        cout << "Depth (from Gulf): " << getDepth() << " m\n";
        cout << "Shore Length (from Bay): " << getShoreLength() << " km\n";
        cout << "Salinity: " << saltiness << "‰\n";
    }
};

int task3() 
{
    Sea sea("Black Sea", 436400, 2212, 1235, 18.9);

    cout << sea << endl;
    
    cout << "\nUsing printInfo method:\n";
    sea.print();

    Sea sea2;
    cout << "\nEnter data for a new sea:\n";
    cin >> sea2;
    cout << "\nNew sea data:\n";
    sea2.print();

    return 0;
}