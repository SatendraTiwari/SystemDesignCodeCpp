#include <iostream>
#include <string>

using namespace std;

// Component Interface
class Pizza {
public:
    virtual string getDescription() const = 0;
    virtual int getCost() const = 0;
    virtual ~Pizza() {}
};

// Concrete Component
class PlainPizza : public Pizza {
public:
    string getDescription() const override {
        return "Plain Pizza";
    }

    int getCost() const override {
        return 100;
    }
};

// Abstract Decorator
class PizzaDecorator : public Pizza {
protected:
    Pizza* pizza;
public:
    PizzaDecorator(Pizza* p) : pizza(p) {}
    virtual ~PizzaDecorator() {
        delete pizza;
    }
};

// Concrete Decorator: Extra Cheese
class ExtraCheese : public PizzaDecorator {
public:
    ExtraCheese(Pizza* p) : PizzaDecorator(p) {}

    string getDescription() const override {
        return pizza->getDescription() + ", Extra Cheese";
    }

    int getCost() const override {
        return pizza->getCost() + 30;
    }
};

// Concrete Decorator: Olives
class Olives : public PizzaDecorator {
public:
    Olives(Pizza* p) : PizzaDecorator(p) {}

    string getDescription() const override {
        return pizza->getDescription() + ", Olives";
    }

    int getCost() const override {
        return pizza->getCost() + 20;
    }
};

// Concrete Decorator: Mushrooms
class Mushrooms : public PizzaDecorator {
public:
    Mushrooms(Pizza* p) : PizzaDecorator(p) {}

    string getDescription() const override {
        return pizza->getDescription() + ", Mushrooms";
    }

    int getCost() const override {
        return pizza->getCost() + 25;
    }
};

// --- Usage ---
int main() {
    Pizza* myPizza = new PlainPizza();
    cout << myPizza->getDescription() << " | Rs. " << myPizza->getCost() << endl;

    myPizza = new ExtraCheese(myPizza);
    // myPizza = new Olives(myPizza);
    // myPizza = new Mushrooms(myPizza);

    cout << myPizza->getDescription() << " | Rs. " << myPizza->getCost() << endl;

    delete myPizza; // important to avoid memory leak

    return 0;
}
