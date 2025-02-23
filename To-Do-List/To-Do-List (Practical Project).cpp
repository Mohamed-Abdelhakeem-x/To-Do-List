// Student Name: Mohamed Ahmed Mohamed Abdelhakeem
// Department: Software Engineering


#include "ToDoList.h" // Include the header file for ToDoList and Task

// Constructor to initialize a task with a description and set its status to not done
Task::Task(const std::string& desc) : description(desc), isDone(false), next(nullptr) {}

// Constructor to initialize the to-do list
ToDoList::ToDoList() : head(nullptr), taskCount(0) {}

// Function to add a new task to the list
void ToDoList::addTask(const std::string& description) {
    Task* newTask = new Task(description);  // Create a new task with the given description
    newTask->next = head;  // Set the new task's next pointer to the current head of the list
    head = newTask;  // Update the head of the list to the new task
    taskCount++;  // Increment the task count
}

// Function to remove a task by its description
void ToDoList::removeTask(const std::string& description) {
    Task* current = head;  // Start from the head of the list
    Task* previous = nullptr;  // Initialize the previous task pointer

    // Traverse the list to find the task
    while (current != nullptr && current->description != description) {
        previous = current;  // Update previous task to current
        current = current->next;  // Move to the next task
    }

    // If task is not found
    if (current == nullptr) {
        std::cout << "Task not found!" << std::endl; // Inform the user that task is not found
        return; // Exit the function
    }

    // If the task to be removed is the head
    if (previous == nullptr) {
        head = current->next;  // Update head to the next task in the list
    }
    else {
        previous->next = current->next;  // Bypass the current task by linking the previous task to the next task
    }

    delete current;  // Delete the task to free memory
    taskCount--;  // Decrement the task count
    std::cout << "Task removed successfully." << std::endl; // Inform the user that task is removed
}

// Function to display all tasks
void ToDoList::displayTasks() const {
    Task* current = head;  // Start from the head of the list

    // If the list is empty
    if (current == nullptr) {
        std::cout << "No tasks in the list." << std::endl; // Inform the user that the list is empty
        return; // Exit the function
    }

    // Traverse the list and display each task
    while (current != nullptr) {
        std::cout << (current->isDone ? "[X] " : "[ ] ") << current->description << std::endl; // Display the task
        current = current->next;  // Move to the next task in the list
    }
}

// Function to display done tasks
void ToDoList::displayDoneTasks() const {
    Task* current = head;  // Start from the head of the list
    bool anyDone = false;  // Flag to check if any tasks are done

    // Traverse the list and display each done task
    while (current != nullptr) {
        if (current->isDone) {  // Check if the current task is done
            std::cout << "[X] " << current->description << std::endl; // Display the done task
            anyDone = true;  // Set flag to true
        }
        current = current->next;  // Move to the next task in the list
    }

    // If no tasks are done
    if (!anyDone) {
        std::cout << "No tasks are done." << std::endl; // Inform the user that no tasks are done
    }
}

// Function to mark a task as done
void ToDoList::markTaskDone(const std::string& description) {
    Task* current = head;  // Start from the head of the list

    // Traverse the list to find the task
    while (current != nullptr && current->description != description) {
        current = current->next;  // Move to the next task in the list
    }

    // If task is not found
    if (current == nullptr) {
        std::cout << "Task not found!" << std::endl; // Inform the user that task is not found
    }
    else {
        current->isDone = true;  // Mark the task as done
        std::cout << "Task marked as done." << std::endl; // Inform the user that task is marked as done
    }
}

// Function to check if a task is done
bool ToDoList::checkTaskDone(const std::string& description) const {
    Task* current = head;  // Start from the head of the list

    // Traverse the list to find the task
    while (current != nullptr) {
        if (current->description == description) {  // Check if current task matches the description
            return current->isDone;  // Return true if the task is done
        }
        current = current->next;  // Move to the next task in the list
    }
    return false;  // Return false if task not found
}

// Function to clear all tasks from the list
void ToDoList::clearList() {
    Task* current = head;  // Start from the head of the list

    // Traverse the list and delete each task
    while (current != nullptr) {
        Task* next = current->next;  // Save the next task
        delete current;  // Delete the current task
        current = next;  // Move to the next task in the list
    }

    head = nullptr;  // Reset the head of the list to nullptr
    taskCount = 0;  // Reset the task count
    std::cout << "All tasks have been cleared." << std::endl; // Inform the user that all tasks are cleared
}

// Function to get the count of tasks
int ToDoList::getTaskCount() const {
    return taskCount;  // Return the task count
}
