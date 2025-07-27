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
int add_task(ToDoList *list);
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
int add_task(ToDoList *list) {
    if(list->task_count >= list->capacity) {
        int new_capacity = 0;
        printf("The array is full you need to add more space: ");
        scanf("%d", &new_capacity);
        new_capacity += list->capacity;

        Task *newList = realloc(list->tasks, sizeof(Task) * new_capacity);
        if(newList == NULL) {
            printf("Memory allocation failed");
            return 1;
        }
        list->tasks = newList;
        list->capacity = new_capacity;
    }

    int id_temp = 0;
    printf("Enter the task ID: ");
    scanf("%d", &id_temp);
    list->tasks[list->task_count].id = id_temp;

    char title_temp[256];
    printf("Enter the task's title: ");
    scanf(" %255[^\n]", title_temp);
    strcpy(list->tasks[list->task_count].title, title_temp);

    int priority_temp = 0;
    printf("Enter the task's priority: ");
    scanf("%d", &priority_temp);
    list->tasks[list->task_count].priority = priority_temp;

    int status_temp = 0;
    printf("Enter the task's status: ");
    scanf("%d", &status_temp);
    list->tasks[list->task_count].is_completed = status_temp;

    list->task_count++;
    return 0;
}

// Function to remove a task by its ID
void remove_task(ToDoList *list, int id) {
    for (int i = 0; i < list->task_count; ++i) {
        if (list->tasks[i].id == id) {
            // Task found, shift subsequent tasks left
            for (int j = i; j < list->task_count - 1; ++j) {
                list->tasks[j] = list->tasks[j + 1];
            }
            // Decrement the task count
            list->task_count--;
            printf("Task with ID %d removed.\n", id);
            return;
        }
    }
    printf("Task with ID %d not found.\n", id);  
}

// Function to toggle a task's completion status
void toggle_task_status(ToDoList *list, int id) {
    for(int i = 0; i < list->task_count; i++) {
        if(list->tasks[i].id == id) {
            list->tasks[i].id = id;
            if(id == 1) {
                printf("The task is compleated\n");
            } else if (id == 0) {
                printf("The task is not compleate\n");
            }
        }
    }
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
