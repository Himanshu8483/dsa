// NAMESPACE IN DSA 
// Namespace: A way to group variables, functions, and classes under a unique name.
// Functions: Blocks of reusable code.
// Classes & Objects: Used to implement Object-Oriented Programming (OOP).
// Using Namespace: Makes it easier to access elements inside a namespace.

#include <iostream>
using namespace std;
// Defining a namespace named 'cybrom'
namespace cybrom {
    int a = 90;  // Global variables inside the namespace
    int b = 100;

    // Function to display the sum of 'a' and 'b'
    void show() {
        cout << "Result = " << a + b << endl;
    }

    // Class definition inside the namespace
    class Bhopal {
    public:
        int square(int num) {  // Function to return the square of a number
            return num * num;
        }
    };

    // Class with a function
    class IOStreamX {
    public:
        void fun() {
            cout << "\nFun function executed\n";
        }
    };
}

using namespace cybrom;  // Allows direct access to 'cybrom' namespace members

int main() {
    cout << a << "\n";  // Accessing variables from 'cybrom' namespace
    cout << b << "\n";
    
    show();  // Calling function from namespace

    Bhopal obj;  // Creating an object of class 'Bhopal'
    cout << "\nSquare of 8 = " << obj.square(8) << endl;  // Calling the method

    IOStreamX obj2;  // Creating an object of class 'IOStreamX'
    obj2.fun();  // Calling the function

    return 0;
}
// nested namespaces in C++
// Namespaces: A way to organize code and prevent name conflicts.
// Nested Namespaces: One namespace inside another.
// Functions: Defining functions inside namespaces.
// Nested namespaces allow better organization when dealing with large projects.

#include <iostream>  // Include standard input-output library
using namespace std; // Allow direct use of standard namespace functions like cout

// Creating a namespace named 'cybrom'
namespace cybrom {
    // Function inside 'cybrom' namespace
    void student() {
        cout << "\nstudent\n";
    }

    // Nested namespace inside 'cybrom'
    namespace bhopal {
        // Function inside 'bhopal' namespace
        void student() {
            cout << "\nbhopal\n";
        }
    }
}

int main() {
    cybrom::student();        // Calls student() function from 'cybrom' namespace
    cybrom::bhopal::student(); // Calls student() function from 'bhopal' namespace inside 'cybrom'
    
    return 0;
}
