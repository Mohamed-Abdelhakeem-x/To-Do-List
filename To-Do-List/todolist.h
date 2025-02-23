// Student Name: Mohamed Ahmed Mohamed Abdelhakeem
// Department: Software Engineering


#ifndef TODOLIST_H
#define TODOLIST_H

#include <iostream>
#include <string>

// Define the Task class
class Task {
public:
    std::string description;  // Description of the task
    bool isDone;              // Status of the task (done or not)
    Task* next;               // Pointer to the next task in the list

    // Constructor to initialize a task with a description
    Task(const std::string& desc); // Initialize Task with a description and default values for other members
};

// Define the ToDoList class
class ToDoList {
private:
    Task* head;  // Pointer to the first task in the list
    int taskCount;  // Count of tasks in the list

public:
    // Constructor to initialize the to-do list
    ToDoList(); // Initialize ToDoList with an empty list

    // Function to add a new task to the list
    void addTask(const std::string& description); // Add a task to the list

    // Function to remove a task by its description
    void removeTask(const std::string& description); // Remove a task from the list

    // Function to display all tasks
    void displayTasks() const; // Display all tasks in the list

    // Function to display done tasks
    void displayDoneTasks() const; // Display tasks that are marked as done

    // Function to mark a task as done
    void markTaskDone(const std::string& description); // Mark a specific task as done

    // Function to check if a task is done
    bool checkTaskDone(const std::string& description) const; // Check if a specific task is done

    // Function to clear all tasks from the list
    void clearList(); // Clear all tasks from the list

    // Function to get the count of tasks
    int getTaskCount() const; // Return the number of tasks in the list
};

#endif // TODOLIST_H
