#include <iostream>

void showMenu() {
    std::cout << "Simple Calculator\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an operation: ";
}

void performOperation(int choice, double num1, double num2) {
    switch (choice) {
        case 1:
            std::cout << "Result: " << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
            break;
        case 2:
            std::cout << "Result: " << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
            break;
        case 3:
            std::cout << "Result: " << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
            break;
        case 4:
            if (num2 != 0) {
                std::cout << "Result: " << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
            } else {
                std::cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Invalid operation.\n";
    }
}

int main() {
    int choice;
    double num1, num2;

    do {
        showMenu();
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting the calculator.\n";
            break;
        }

        std::cout << "Enter the first number: ";
        std::cin >> num1;
        std::cout << "Enter the second number: ";
        std::cin >> num2;

        performOperation(choice, num1, num2);

    } while (choice != 5);

    return 0;
}
