# CPP Module 00: C++ Fundamentals

This module is your entry point into modern C++ programming. It introduces you to key language constructs and programming paradigms such as namespaces, classes, member functions, streams, initialization lists, static members, and the use of `const`. Through the following exercises—**Megaphone**, **My Awesome PhoneBook**, and **The Job Of Your Dreams**—you will apply these concepts to solve practical problems. This README explains both the theory behind each exercise and provides code examples to illustrate these ideas in action.

- [General Concepts](#general-concepts)
- [Exercise 00: Megaphone](#exercise-00-megaphone)
- [Exercise 01: My Awesome PhoneBook](#exercise-01-my-awesome-phonebook)
- [Exercise 02: The Job Of Your Dreams](#exercise-02-the-job-of-your-dreams)
- [Conclusion](#conclusion)

---

## General Concepts

Before diving into each exercise, it’s important to cover some foundational C++ topics that will recur throughout these projects.

### Classes and Objects
Classes are blueprints for objects that combine data (attributes) and behaviors (methods). Encapsulation is key: keep member variables private and provide public methods to interact with them.

**Example:**
```cpp
class MyClass {
private:
    int data;
public:
    MyClass(int value) : data(value) {}  // Constructor using an initialization list
    void display() const { std::cout << "Data: " << data << std::endl; }
};
```

### Member Functions and Initialization Lists
Member functions define the actions objects can perform. Constructors often use initialization lists to efficiently initialize members—especially important for constant members.

**Example:**
```cpp
class Point {
    int x, y;
public:
    // x and y are initialized before the constructor body is executed.
    Point(int a, int b) : x(a), y(b) {}
};
```

### Const Qualifier
The `const` qualifier ensures that variables or member functions do not modify the object’s state. For example, getter methods should be declared as `const`.

**Example:**
```cpp
class Immutable {
private:
    int value;
public:
    Immutable(int v) : value(v) {}
    int getValue() const { return value; } // Promise not to modify the object
};
```

### Static Members
Static members belong to the class as a whole rather than to any one object. They are often used for counters or shared data across instances. Only one **copy** exists.

**Example:**
```cpp
class Counter {
public:
    static int count;
    Counter() { count++; }
};

int Counter::count = 0;  // Definition and initialization of the static member
```

### I/O Streams and Formatting
The i/o streams library (iostream) and manipulators (iomanip) are used for input and output operations. They become crucial in formatting outputs—such as aligning data in columns.

**Example:**
```cpp
#include <iostream>
#include <iomanip>
int main() {
    std::cout << std::setw(10) << "Column1" << std::setw(10) << "Column2" << std::endl;
    return 0;
}
```

### ⚠️ Note on `using namespace std;`

The 42 school prevents it's students from using namespaces, and they have a reason for that...
- **Name collisions**: In C++98, the standard library is big, but as you include more headers, you might run into conflicts if you pull in the entire std namespace. A symbol in another library or your own code might clash with something from std.
- **Header pollution**: If you put using namespace std; in a header file, everyone including that header now gets the entire std namespace whether they want it or not. It can lead to unexpected conflicts in other people's code.
- **Readability & clarity**: Being explicit with std:: makes it clear which symbols come from the standard library. It’s a bit more typing, but it makes your code more readable and maintainable.

---

## Exercise 00: Megaphone

### Overview
The **Megaphone** exercise asks you to create a program that outputs input messages in uppercase.

### Concepts Covered
- **Command Line Arguments:** Using `argc` and `argv` to access parameters passed to the program.
- **String Manipulation:** Transforming characters to uppercase using `<cctype>`.
- **Basic I/O:** Using `std::cout` for output.

#### Detailed Explanation:
- **Arguments:**  
  The program uses `argc` to verify if at least one argument exists. If not, it outputs a default message.
- **Conversion to Uppercase:**  
  Iterates over each character of the provided strings and converts them using `std::toupper`.
- **Output Formatting:**  
  Spaces are inserted between command arguments to mimic the original message structure.

---

## Exercise 01: My Awesome PhoneBook

### Overview
For **My Awesome PhoneBook**, you are to design a simple phonebook application that stores up to eight contacts. Two classes are required: `PhoneBook` and `Contact`. This reinforces object-oriented programming, data encapsulation, and formatted output.

### Concepts Covered
- **Class Design & Encapsulation:**  
  Separate classes for `Contact` (managing individual data fields) and `PhoneBook` (managing the array of contacts).
- **Static Allocation:**  
  Use a fixed-size array for storage; dynamic allocation is forbidden.
- **Input Validation:**  
  Ensure that no field (first name, last name, nickname, phone number, darkest secret) is left empty.
- **Formatted Output:**  
  Utilize stream manipulators like `std::setw` and `std::right` to maintain column widths and align output.

#### Detailed Explanation:
- **Encapsulation:**  
  The `Contact` class holds all data about a contact and provides setter/getter functions to interact with its private attributes.
- **Static Allocation:**  
  The `PhoneBook` class uses a fixed array (`contacts[8]`) to store contacts. A circular buffer (using the `oldest` index) ensures that when the maximum is reached, older entries are replaced.
- **Formatted Output:**  
  The `displayContacts` method utilizes `std::setw` for a uniform presentation of the contact fields in a table-like format.
- **Command Loop:**  
  The main function continuously accepts user input (ADD, SEARCH, EXIT), ensuring an interactive experience.

---

## Exercise 02: The Job Of Your Dreams

### Overview
This exercise simulates the process of recovering a lost source file in a banking application. You are given `Account.hpp` (and a corresponding test file and log) and must implement `Account.cpp` such that the output logs match the expected format. It tests your understanding of static members, constructor/destructor behaviors, and overall object-oriented design.

### Concepts Covered
- **Static Members and Methods:**  
  Use static variables (e.g., to keep track of the total number of accounts) and methods that are shared among all objects.
- **Object Lifecycle:**  
  Implement constructors and destructors that log account creation and deletion.
- **Constructor Initialization Lists:**  
  Utilize initialization lists to efficiently initialize member variables.
- **Test-Driven Development:**  
  Your implementation must pass provided tests by matching specific outputs (except for dynamic elements such as timestamps).

#### Detailed Explanation:
- **Static Members:**  
  The static variable `accountCount` demonstrates how data can be shared across all instances of a class. Every time a new account is created, this counter is updated.
- **Lifecycle Management:**  
  The constructor initializes each account via an initialization list, while the destructor logs when an account is closed.
- **Method Implementation:**  
  The account operations (`makeDeposit`, `makeWithdrawal`) change the state of an account and output the results immediately, ensuring consistency with test expectations.

---

Now all that's left for me to do is to wish you happy coding and a good exploration into C++!
