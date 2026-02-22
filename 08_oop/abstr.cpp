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


/*
Good. That means you’re not pretending to understand it. That’s how real learning starts.

Let’s build this slowly and visually in your head.

First, forget “virtual.” Think about inheritance.

Suppose you write:

class Animal {
public:
    void speak() {
        cout << "Animal sound\n";
    }
};

class Dog : public Animal {
public:
    void speak() {
        cout << "Bark\n";
    }
};

Now:

Dog d;
d.speak();  // Bark

That makes sense.

But now look at this:

Animal* a = new Dog();
a->speak();

What do you think prints?

It prints:

Animal sound

Why?

Because C++ decides which function to call based on the pointer type (Animal*),
not the object type (Dog).

This is called compile-time binding or static binding.

The compiler looks at the pointer type and says:
“I see Animal*. So I’ll call Animal::speak().”

It does NOT care that the actual object is a Dog.

Now enter: virtual functions.

If we change the base class to:

class Animal {
public:
    virtual void speak() {
        cout << "Animal sound\n";
    }
};

Now run:

Animal* a = new Dog();
a->speak();

This time it prints:

Bark

Why?

Because virtual tells the compiler:

“Do not decide which function to call at compile time.
Wait until runtime. Look at the actual object.”

This is called runtime polymorphism or dynamic binding.

The decision is made based on the real object, not the pointer type.

That is the entire point of virtual functions.

Now let’s understand how this works conceptually.

When you mark a function as virtual, C++ creates something called a vtable
(virtual table).

Think of it like a hidden lookup table.

Each class that has virtual functions maintains a table of function addresses.

When you call a virtual function using a base pointer:

- The program checks the vtable of the actual object.
- It finds the correct overridden function.
- It executes that one.

No magic. Just indirection.

Now here’s the deeper reason this exists.

Suppose you build a system with:

Dog
Cat
Cow
AlienSpaceGoat

All inherit from Animal.

You want to write:

void makeItSpeak(Animal* a) {
    a->speak();
}

You don’t want to write:

if(type == Dog) ...
if(type == Cat) ...

That’s messy and fragile.

Virtual functions let you treat all derived classes uniformly
through a base pointer.

This is the foundation of:

Plugin systems
Game engines
GUI frameworks
Database drivers
Operating systems

It’s everywhere.

Now let’s clarify one very important rule:

Virtual functions only work correctly when called through:

- A base class pointer
- Or a base class reference

If you call through an object directly, virtual doesn’t matter much.

Also: always make base class destructors virtual when using polymorphism.

Like this:

virtual ~Animal() {}

Otherwise, deleting derived objects through base pointers
can cause memory leaks.

That’s not theory. That’s painful real-world bug territory.

Now zoom out for a second.

Without virtual:
C++ chooses function at compile time.

With virtual:
C++ chooses function at runtime.

Virtual = “decide later.”

That’s it.

The keyword isn’t mystical. It’s a timing instruction for the compiler.

Why doesn’t C++ make all functions virtual by default?

Because runtime dispatch has a cost:

- Slight memory overhead (vtable)
- Slight performance overhead (indirection)

C++ makes you explicit. If you want runtime behavior, you ask for it.

Control is power.

Virtual functions are not a trick.
They are controlled delayed decision-making.

And that’s a surprisingly powerful idea in software design.
*/