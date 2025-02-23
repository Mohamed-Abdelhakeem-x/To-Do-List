// Student Name: Mohamed Ahmed Mohamed Abdelhakeem
// Department: Software Engineering

#include "ToDoList.h" // Include the header file for ToDoList and Task

// Function to display the menu
void displayMenu() {
    std::cout << "\nTo-Do List Menu" << std::endl;
    std::cout << "1. Add a task" << std::endl;
    std::cout << "2. Remove a task" << std::endl;
    std::cout << "3. Display all tasks" << std::endl;
    std::cout << "4. Display done tasks" << std::endl;
    std::cout << "5. Mark a task as done" << std::endl;
    std::cout << "6. Check if task is done" << std::endl;
    std::cout << "7. Clear all tasks" << std::endl;
    std::cout << "8. Display task count" << std::endl;  // New option for task count
    std::cout << "9. Quit" << std::endl;
    std::cout << "Choose an option: ";
}

// Main function to test the ToDoList class
int main() {
    ToDoList todo;  // Create a ToDoList object to manage tasks
    int choice;     // Variable to store user's menu choice
    std::string description;  // Variable to store task description

    // Infinite loop to display the menu and handle user input
    while (true) {
        displayMenu();  // Display the menu to the user

        // Validate user input
        while (!(std::cin >> choice) || (choice < 1 || choice > 9)) {
            std::cout << "Invalid choice. Please enter a number between 1 and 9: "; // Display error message
            std::cin.clear();  // Clear the error flag on cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Ignore invalid input
        }

        std::cin.ignore();  // Ignore the newline character left in the buffer

        // Handle user choice based on input
        switch (choice) {
        case 1:
            std::cout << "Enter task description: "; // Prompt for task description
            std::getline(std::cin, description);  // Get the task description from the user
            todo.addTask(description);  // Add the task to the list
            break;
        case 2:
            std::cout << "Enter task description to remove: "; // Prompt for task to remove
            std::getline(std::cin, description);  // Get the task description from the user
            todo.removeTask(description);  // Remove the task from the list
            break;
        case 3:
            std::cout << "To-Do List:" << std::endl; // Display header for all tasks
            todo.displayTasks();  // Display all tasks in the list
            break;
        case 4:
            std::cout << "Done Tasks:" << std::endl; // Display header for done tasks
            todo.displayDoneTasks();  // Display tasks that are marked as done
            break;
        case 5:
            std::cout << "Enter task description to mark as done: "; // Prompt for task to mark as done
            std::getline(std::cin, description);  // Get the task description from the user
            todo.markTaskDone(description);  // Mark the task as done
            break;
        case 6:
            std::cout << "Enter task description to check if done: "; // Prompt for task to check
            std::getline(std::cin, description);  // Get the task description from the user
            if (todo.checkTaskDone(description)) {  // Check if the task is done
                std::cout << "Task is done." << std::endl; // Inform the user that task is done
            }
            else {
                std::cout << "Task is not done." << std::endl; // Inform the user that task is not done
            }
            break;
        case 7:
            todo.clearList();  // Clear all tasks from the list
            std::cout << "All tasks have been cleared." << std::endl; // Inform the user that tasks are cleared
            break;
        case 8:
            std::cout << "Total number of tasks: " << todo.getTaskCount() << std::endl;  // Display the task count
            break;
        case 9:
            std::cout << "Quitting the program." << std::endl; // Inform the user about quitting
            return 0;  // Exit the program
        }
    }

    return 0; // Return 0 to indicate normal termination
}
