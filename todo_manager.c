#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;             // Unique identifier for the task
    char title[256];    // Title of the task
    int priority;       // Priority of the task
    int is_completed;   // Status of the task (0 = not completed, 1 = completed)
} Task;

typedef struct {
    Task *tasks;        // Dynamic array of tasks
    int task_count;     // Number of tasks currently in the list
    int capacity;       // Maximum capacity of the task array
} ToDoList;

/* ================ FUNCTION DECLARATIONS ================== */

ToDoList* initialize_todo_list(int initial_capacity);
void add_task(ToDoList *list, const char *title, int priority);
void remove_task(ToDoList *list, int id);
void toggle_task_status(ToDoList *list, int id);
void display_tasks(const ToDoList *list);
void save_tasks_to_file(const ToDoList *list, const char *filename);
void load_tasks_from_file(ToDoList *list, const char *filename);

/* =============== FUNCTION IMPLEMENTATIONS ================== */

ToDoList* initialize_todo_list(int initial_capacity) {
    ToDoList *todoList = malloc(sizeof(ToDoList));
    if (todoList == NULL) {
        printf("❌ Failed to allocate memory for ToDoList. Exiting.\n");
        return NULL;
    }
    todoList->tasks = malloc(sizeof(Task) * initial_capacity);
    if (todoList->tasks == NULL) {
        printf("❌ Failed to allocate memory for tasks array. Exiting.\n");
        free(todoList);
        return NULL;
    }
    todoList->task_count = 0;
    todoList->capacity = initial_capacity;
    return todoList;
}

// Function to add a new task
void add_task(ToDoList *list, const char *title, int priority) {
    // TODO: Implement function to add a task to the list.
    // - Check if the list needs resizing.
    // - Assign an ID to the new task.
    // - Set the task's title, priority, and status.
    // - Increment the task count.
}

// Function to remove a task by its ID
void remove_task(ToDoList *list, int id) {
    // TODO: Implement function to remove a task by its ID.
    // - Find the task with the given ID.
    // - Shift other tasks to fill the gap.
    // - Decrement the task count.
}

// Function to toggle a task's completion status
void toggle_task_status(ToDoList *list, int id) {
    // TODO: Implement function to toggle the completion status of a task.
    // - Find the task with the given ID.
    // - Toggle its completion status.
}

// Function to display all tasks
void display_tasks(const ToDoList *list) {
    // TODO: Implement function to display all tasks.
    // - Iterate through the tasks array.
    // - Print the details of each task, including status and priority.
}

// Function to save tasks to a file
void save_tasks_to_file(const ToDoList *list, const char *filename) {
    // TODO: Implement function to save tasks to a file.
    // - Open the file in write mode.
    // - Write each task's details to the file.
    // - Handle file errors gracefully.
}

// Function to load tasks from a file
void load_tasks_from_file(ToDoList *list, const char *filename) {
    // TODO: Implement function to load tasks from a file.
    // - Open the file in read mode.
    // - Read task details and populate the list.
    // - Handle file errors gracefully.
}

int main() {
    ToDoList *todoList = NULL; 
    int choice;
    int initial_capacity = 5; 

    printf("\n══════════════════════════════════════════════════════════\n");
    printf("🗒️  TO-DO LIST MANAGER 🗒️\n");
    printf("══════════════════════════════════════════════════════════\n");

    todoList = initialize_todo_list(initial_capacity);
    if (todoList == NULL) {
        return 1;
    }

    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════╗\n");
        printf("║                    🗒️  TO-DO MENU 🗒️                     ║\n");
        printf("╠══════════════════════════════════════════════════════════╣\n");
        printf("║  1. ➕ Add Task                                          ║\n");
        printf("║  2. 🗑️  Remove Task                                      ║\n");
        printf("║  3. ✅ Toggle Task Status                                ║\n");
        printf("║  4. 📋 Display All Tasks                                 ║\n");
        printf("║  5. 💾 Save Tasks to File                                ║\n");
        printf("║  6. 📂 Load Tasks from File                              ║\n");
        printf("║  7. 🚪 Exit                                              ║\n");
        printf("╚══════════════════════════════════════════════════════════╝\n");
        printf("\n🎯 Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // TODO: Call add_task function
                break;
            case 2:
                // TODO: Call remove_task function
                break;
            case 3:
                // TODO: Call toggle_task_status function
                break;
            case 4:
                // TODO: Call display_tasks function
                break;
            case 5:
                // TODO: Call save_tasks_to_file function
                break;
            case 6:
                // TODO: Call load_tasks_from_file function
                break;
            case 7:
                printf("\n🚪 Exiting and cleaning up...\n");
                free(todoList->tasks);
                free(todoList);
                return 0;
            default:
                printf("\n⚠️  Invalid choice! Please try again.\n");
        }
    }
}
