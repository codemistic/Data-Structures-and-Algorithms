#include <iostream>
using namespace std;

// classes -> code reusability

class Car
{
private: // default
    string name, color;
    int speed;

public:
    // Parameterized constructors
    Car(string name, string color, int speed) : name(name), color(color), speed(speed) {}

    int get_travel_time(int distance)
    {
        return distance / speed;
    }

    // function header
    int get_speed();

} Audi("R8", "white", 3);

// functions can be defined outside class, provided we have defined its function header in class
int Car ::get_speed()
{
    return speed;
}

int main()
{
    Car Mustang("Mustang", "black", 5);
    cout << Mustang.get_travel_time(5) << "\n";
    cout << Audi.get_travel_time(6) << "\n";
    cout << "Mustang speed : " << Mustang.get_speed() << "\n";

    return 0;
}