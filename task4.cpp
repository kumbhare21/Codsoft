#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool isCompleted;

    Task(std::string desc) : description(desc), isCompleted(false) {}
};

void addTask(std::vector<Task>& tasks) {
    std::string desc;
    std::cout << "Enter task description: ";
    std::getline(std::cin >> std::ws, desc);
    tasks.emplace_back(desc);
    std::cout << "Task added.\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description 
                  << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].isCompleted = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    int taskNumber;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void showMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        showMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
