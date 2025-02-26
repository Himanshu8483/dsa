// Function Template Example
#include <iostream>
using namespace std;

/*
A template allows us to create a single function or class 
that works with different data types.

Templates allow writing generic code that works with multiple data types without rewriting the same logic.
typename (or class) is used to define a placeholder for a data type in function and class templates.
Templates improve code reusability and flexibility, commonly used for functions, classes, and recursion (e.g., factorial calculation).
*/

// Template function to find sum of two numbers
// Works for any data type (int, float, double, etc.)
template<typename DataType> // 'typename' or 'class' can be used to define a generic data type
DataType sum(DataType num1, DataType num2) {
    return num1 + num2; // Returns sum of num1 and num2
}

// Template function with two different data types
// Multiplies two numbers (different data types allowed)
template<typename FirstType, typename SecondType>
SecondType multiply(FirstType value1, SecondType value2) {
    return value1 * value2; // Returns multiplication result
}

int main() {
    cout << sum(8.3, 9.9) << "\n";  // Calls sum function for double
    cout << multiply(3, 2.3) << "\n"; // Calls multiply function with int & double
    return 0;
}


// Class Template Example
#include <iostream>
using namespace std;

/*
A class template allows a class to work with any data type.
It provides flexibility to define a blueprint for a class that can work with multiple types.
*/

// Template class with one data type
template<typename Type> // 'Type' is a placeholder for any data type
class CybromClass {
    Type value; // Private variable of type Type
public:
    CybromClass(Type input) { // Constructor
        value = input;
    }
    Type show() { 
        return value + 1; // Returns value incremented by 1
    }
};

int main() {
    CybromClass<int> obj(34); // Creating object of class CybromClass with int type
    cout << obj.show() << "\n"; // Output: 35
    return 0;
}


// Class Template with Two Data Types
#include <iostream>
using namespace std;

/*
A template class with multiple data types allows us to define a class 
that can take different types for different attributes or functions.
*/

// Template class with two data types
template<typename FirstType, typename SecondType>
class CybromTwoTypes {
public:
    void show(FirstType num1, SecondType num2) {
        cout << num1 + num2 << "\n"; // Outputs sum of num1 and num2
    }
};

int main() {
    CybromTwoTypes<int, double> obj; // Object with int and double types
    obj.show(3, 4.4); // Calls show function, Output: 7.4
    return 0;
}


// Class Template for Factorial Calculation
#include <iostream>
using namespace std;

/*
This template class calculates the factorial of a number using recursion.
*/

template <typename NumberType>
class Factorial {
public:
    NumberType calculate(NumberType n) {
        if (n <= 1) {
            return 1; // Base case: Factorial of 0 or 1 is 1
        } else {
            return n * calculate(n - 1); // Recursive call
        }
    }
};

int main() {
    Factorial<int> fact; // Creating an object of Factorial class for integers
    int num;
    cout << "Enter a number: ";
    cin >> num;
    
    cout << "Factorial of " << num << " is: " << fact.calculate(num) << endl;
    
    return 0;
}
