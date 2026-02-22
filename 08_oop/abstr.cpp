#include <iostream>
#include <string>

using namespace std;


class Tea {
    public:
        virtual void prepareIngredients() = 0; // pure virtual function
        virtual void brew() = 0; // pure virtual function
        virtual void serve() = 0; // pure virtual function

        void makeTea(){
            prepareIngredients();
            brew();
            serve();
        }
};

//derived class

class GreenTea : public Tea{
public:
    void prepareIngredients() override {
        cout << "green leaves and water is ready" << endl;
    }

    void brew() override {
        cout << "Green Tea brewed" << endl;
    }
    void serve() override {
        cout << "Green Tea Served" << endl;
    }
};

class MasalaTea : public Tea{
public:
    void prepareIngredients() override {
        cout << "green leaves and water is ready along with masala" << endl;
    }

    void brew() override {
        cout << "Masala Tea brewed" << endl;
    }
    void serve() override {
        cout << "Masala Tea Served" << endl;
    }
};

int main(){

    GreenTea greenTea;
    MasalaTea masalaTea;

    greenTea.makeTea();
    masalaTea.makeTea();

    return 0;
}










#include <iostream>
using namespace std;

int main() {

    cout << "ABSTRACTION IN C++\n\n";

    cout << "Abstraction means hiding implementation details and exposing only\n";
    cout << "the necessary functionality to the user.\n\n";

    cout << "It allows you to use an object without knowing how it works internally.\n";
    cout << "For example, when you drive a car, you use the steering and pedals\n";
    cout << "without knowing how the engine works.\n\n";

    cout << "In C++, abstraction is achieved using:\n";
    cout << "1. Classes\n";
    cout << "2. Access specifiers (public, private, protected)\n";
    cout << "3. Abstract classes and pure virtual functions\n\n";

    cout << "Example of Data Abstraction:\n";
    cout << "A class hides internal data using private members and exposes\n";
    cout << "public functions to access or modify that data.\n\n";

    cout << "Example of Interface Abstraction:\n";
    cout << "An abstract class uses pure virtual functions to define a\n";
    cout << "common interface for derived classes.\n\n";

    cout << "Benefits of Abstraction:\n";
    cout << "- Reduces complexity\n";
    cout << "- Improves maintainability\n";
    cout << "- Protects internal data\n";
    cout << "- Makes code flexible and scalable\n\n";

    cout << "Abstraction is about designing clear boundaries and hiding\n";
    cout << "unnecessary implementation details.\n";

    return 0;
}


