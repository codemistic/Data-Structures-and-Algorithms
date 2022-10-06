// Compile Time Polymorphism
// Static Polymorphism
// Static or Early binding

// Examples
// 1. Function overloading
// 2. Operator overloading

class Add
{
public:
    int sum(int A, int B)
    {
        // sum(10, 20)
        return A + B;
    }

    int sum(int A, int B, int C)
    {
        // sum(10, 20, 30)
        return A + B + C;
    }
};

// 1 name, 2 functions, behave differently in different situations
// Function overloading is an example of compile time polymorphism