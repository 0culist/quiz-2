```cpp
#include <iostream>
#include <string>
#include <map>

// Base class
class Function {
public:
    virtual void play() = 0; // Pure virtual function
};

// Derived classes for each function
class FuncA : public Function {
public:
    void play() override {
        std::cout << "Function A is called!" << std::endl;
    }
};

class FuncB : public Function {
public:
    void play() override {
        std::cout << "Function B is called!" << std::endl;
    }
};

class FuncC : public Function {
public:
    void play() override {
        std::cout << "Function C is called!" << std::endl;
    }
};

int main() {
    // Map to associate user choices with function pointers
    std::map<std::string, Function*> functions;
    FuncA funcA;
    FuncB funcB;
    FuncC funcC;

    functions["funcA"] = &funcA;
    functions["funcB"] = &funcB;
    functions["funcC"] = &funcC;

    std::string choice;
    std::cout << "Choose a function: funcA, funcB, funcC" << std::endl;
    std::cin >> choice;

    // Call the chosen function
    auto it = functions.find(choice);
    if (it != functions.end()) {
        it->second->play(); // Call the function
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }

    return 0;
}
```

In this example:
- I've created a base class `Function` with a pure virtual method `play()`.
- For each function (`funcA`, `funcB`, `funcC`), I've created a derived class that overrides the `play()` method.
- A `std::map` is used to associate the user's choice with a unique pointer to a `Function` object.
- Based on the user's input, the corresponding function's `play()` method is called.
