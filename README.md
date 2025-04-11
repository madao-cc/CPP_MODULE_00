# CPP Module 00: C++ Fundamentals

This module is your entry point into modern C++ programming. It introduces you to key language constructs and programming paradigms such as namespaces, classes, member functions, streams, initialization lists, static members, and the use of `const`. Through the following exercises—**Megaphone**, **My Awesome PhoneBook**, and **The Job Of Your Dreams**—you will apply these concepts to solve practical problems. This README explains both the theory behind each exercise and provides code examples to illustrate these ideas in action.

- [General Concepts](#general-concepts)
- [Exercise 00: Megaphone](#exercise-00-megaphone)
- [Exercise 01: My Awesome PhoneBook](#exercise-01-my-awesome-phonebook)
- [Exercise 02: The Job Of Your Dreams](#exercise-02-the-job-of-your-dreams)
- [Conclusion](#conclusion)

*(Reference: en.subject.pdf citeturn0file0)*

---

## General Concepts

Before diving into each exercise, it’s important to cover some foundational C++ topics that recur throughout these projects.

### Namespaces
Namespaces help avoid name collisions by grouping related classes and functions. Instead of using `using namespace std;` (which is discouraged in these exercises), you should call functions using the `std::` prefix.

**Example:**
```cpp
#include <iostream>

namespace MyNamespace {
    void displayMessage() {
        std::cout << "Hello, Namespaces!" << std::endl;
    }
}

int main() {
    MyNamespace::displayMessage();
    return 0;
}
```

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
Static members belong to the class as a whole rather than to any one object. They are often used for counters or shared data across instances.

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

---

## Exercise 00: Megaphone

### Overview
The **Megaphone** exercise asks you to create a program that outputs input messages in uppercase. This ensures you are comfortable with handling command line arguments, stream I/O, and basic string manipulation.

### Concepts Covered
- **Command Line Arguments:** Using `argc` and `argv` to access parameters passed to the program.
- **String Manipulation:** Transforming characters to uppercase using `<cctype>`.
- **Basic I/O:** Using `std::cout` for output.

### Code Example: `megaphone.cpp`
```cpp
#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char** argv) {
    // Check if the user provided any arguments.
    if (argc < 2) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }

    // Process each command line argument.
    for (int i = 1; i < argc; ++i) {
        std::string word = argv[i];
        for (char &c : word) {
            std::cout << static_cast<char>(std::toupper(c));
        }
        if (i < argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

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

### Code Example: Contact and PhoneBook Classes

#### Contact.hpp
```cpp
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    // Setters with room for additional validation if required.
    void setFirstName(const std::string& str) { firstName = str; }
    void setLastName(const std::string& str) { lastName = str; }
    void setNickname(const std::string& str) { nickname = str; }
    void setPhoneNumber(const std::string& str) { phoneNumber = str; }
    void setDarkestSecret(const std::string& str) { darkestSecret = str; }

    // Getters to access private data.
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
    std::string getNickname() const { return nickname; }
    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDarkestSecret() const { return darkestSecret; }
};

#endif
```

#### PhoneBook.hpp
```cpp
#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook {
private:
    Contact contacts[8];
    int count;   // Total contacts added so far.
    int oldest;  // Index pointing to the oldest contact.
public:
    PhoneBook() : count(0), oldest(0) {}

    void addContact(const Contact& contact) {
        contacts[oldest] = contact;
        oldest = (oldest + 1) % 8;
        if (count < 8) ++count;
    }

    void displayContacts() const {
        std::cout << std::setw(10) << "Index" << "|"
                  << std::setw(10) << "First Name" << "|"
                  << std::setw(10) << "Last Name" << "|"
                  << std::setw(10) << "Nickname" << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << std::setw(10) << i << "|"
                      << std::setw(10) << (contacts[i].getFirstName().length() > 10 ? 
                                           contacts[i].getFirstName().substr(0, 9) + "." : contacts[i].getFirstName()) << "|"
                      << std::setw(10) << (contacts[i].getLastName().length() > 10 ? 
                                           contacts[i].getLastName().substr(0, 9) + "." : contacts[i].getLastName()) << "|"
                      << std::setw(10) << (contacts[i].getNickname().length() > 10 ? 
                                           contacts[i].getNickname().substr(0, 9) + "." : contacts[i].getNickname())
                      << std::endl;
        }
    }
};

#endif
```

#### Main.cpp (Program Loop)
```cpp
#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main() {
    PhoneBook phonebook;
    std::string command;
    
    while (true) {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (command == "EXIT") {
            break;
        } else if (command == "ADD") {
            Contact newContact;
            std::string input;
            
            std::cout << "Enter first name: ";
            std::getline(std::cin, input);
            newContact.setFirstName(input);
            
            std::cout << "Enter last name: ";
            std::getline(std::cin, input);
            newContact.setLastName(input);
            
            std::cout << "Enter nickname: ";
            std::getline(std::cin, input);
            newContact.setNickname(input);
            
            std::cout << "Enter phone number: ";
            std::getline(std::cin, input);
            newContact.setPhoneNumber(input);
            
            std::cout << "Enter darkest secret: ";
            std::getline(std::cin, input);
            newContact.setDarkestSecret(input);
            
            // Validation: Ensure that all fields are provided
            if (newContact.getFirstName().empty() || newContact.getLastName().empty() || 
                newContact.getNickname().empty() || newContact.getPhoneNumber().empty() || 
                newContact.getDarkestSecret().empty()) {
                std::cout << "Error: All fields are required." << std::endl;
            } else {
                phonebook.addContact(newContact);
                std::cout << "Contact added successfully." << std::endl;
            }
        } else if (command == "SEARCH") {
            phonebook.displayContacts();
            // Here, you can add additional functionality to view a contact in detail.
        } else {
            std::cout << "Invalid command." << std::endl;
        }
    }
    
    return 0;
}
```

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

### Code Example: Account.hpp & Account.cpp

#### Account.hpp
```cpp
#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <string>
#include <ctime>

class Account {
private:
    static int accountCount; // Static member to track total accounts
    int accountIndex;
    double balance;
    // Additional member variables as needed

public:
    Account(double initial_deposit);
    ~Account();
    
    static void displayAccountsInfos();  // Displays class-wide information
    void makeDeposit(double deposit);
    bool makeWithdrawal(double withdrawal);
    void displayStatus() const;          // Displays the account's current status
};

#endif
```

#### Account.cpp
```cpp
#include "Account.hpp"

int Account::accountCount = 0;  // Initialize static member

Account::Account(double initial_deposit)
    : balance(initial_deposit), accountIndex(accountCount) {
    accountCount++;
    std::cout << "Account created: " << accountIndex 
              << ", initial deposit: " << initial_deposit << std::endl;
}

Account::~Account() {
    std::cout << "Account closed: " << accountIndex << std::endl;
}

void Account::makeDeposit(double deposit) {
    balance += deposit;
    std::cout << "Deposited " << deposit << " to account " << accountIndex << std::endl;
}

bool Account::makeWithdrawal(double withdrawal) {
    if (balance < withdrawal) {
        std::cout << "Withdrawal refused for account " << accountIndex << std::endl;
        return false;
    }
    balance -= withdrawal;
    std::cout << "Withdrew " << withdrawal << " from account " << accountIndex << std::endl;
    return true;
}

void Account::displayStatus() const {
    std::cout << "Account " << accountIndex << " balance: " << balance << std::endl;
}

void Account::displayAccountsInfos() {
    std::cout << "Total accounts: " << accountCount << std::endl;
    // Additional aggregate details can be added here.
}
```

#### Detailed Explanation:
- **Static Members:**  
  The static variable `accountCount` demonstrates how data can be shared across all instances of a class. Every time a new account is created, this counter is updated.
- **Lifecycle Management:**  
  The constructor initializes each account via an initialization list, while the destructor logs when an account is closed.
- **Method Implementation:**  
  The account operations (`makeDeposit`, `makeWithdrawal`) change the state of an account and output the results immediately, ensuring consistency with test expectations.

---

## Conclusion

CPP_MODULE_00 lays down the essential building blocks of C++ programming. Through these exercises, you learn to:
- Manipulate command line arguments and transform strings.
- Design classes with proper encapsulation.
- Format and present information using i/o stream manipulators.
- Manage static data and understand object lifecycles with constructors and destructors.

Mastering these topics will not only help you in evaluating your code with peers but also prepare you for the more advanced challenges in subsequent modules. For the complete source code and additional details, please refer to the repository at [CPP_MODULE_00](https://github.com/madao-cc/CPP_MODULE_00).

Happy coding and deep exploration into C++!
