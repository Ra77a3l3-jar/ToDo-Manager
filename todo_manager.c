#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;             // Unique identifier for the task
    char title[256];    // Title of the task
    int priority;       // Priority of the task (0 = LOW) (1 = HIGH)
    int is_completed;   // Status of the task (0 = not completed, 1 = completed)
} Task;

typedef struct {
    Task *tasks;        // Dynamic array of tasks
    int task_count;     // Number of tasks currently in the list
    int capacity;       // Maximum capacity of the task array
} ToDoList;

/* ================ FUNCTION DECLARATIONS ================== */

ToDoList* initialize_todo_list(int initial_capacity);
void add_task(ToDoList *list);
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

void add_task(ToDoList *list) {
    printf("\n\n╔══════════════════════════════════════════════════════════╗\n");
    printf("║                    ➕ ADD TASK ➕                          ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");

    if (list->task_count >= list->capacity) {
        printf("⚠️  Task list full! Please increase capacity.\n");
    }

    int id_temp;
    printf("📌 Enter the task ID: ");
    scanf("%d", &id_temp);
    list->tasks[list->task_count].id = id_temp;

    char title_temp[256];
    printf("✏️  Enter the task's title: ");
    scanf(" %255[^\n]", title_temp);
    strcpy(list->tasks[list->task_count].title, title_temp);

    int priority_temp;
    printf("🔼 Enter the task's priority: ");
    scanf("%d", &priority_temp);
    list->tasks[list->task_count].priority = priority_temp;

    int status_temp;
    printf("🎯 Enter the task's status (0 for not completed, 1 for completed): ");
    scanf("%d", &status_temp);
    list->tasks[list->task_count].is_completed = status_temp;

    list->task_count++;
    printf("\n🎉 ═══════════════════════════════════════════════════════\n");
    printf("   🎉 TASK ADDED SUCCESSFULLY! 🎉\n");
    printf("   ═══════════════════════════════════════════════════════\n");
}

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

void display_tasks(const ToDoList *list) {
    printf("\n\n╔═════════════════════════════════════════════════════════╗\n");
    printf("║                   📋 ALL TASKS DISPLAY 📋                ║\n");
    printf("╚═════════════════════════════════════════════════════════╝\n");

    if (list->task_count == 0) {
        printf("⚠️  No tasks added yet!\n");
        return;
    }

    for (int i = 0; i < list->task_count; ++i) {
        printf("📋 Task #%d:\n", i + 1);
        printf("   🆔 ID: %d\n", list->tasks[i].id);
        printf("   ✏️  Title: %s\n", list->tasks[i].title);
        printf("   🔼 Priority: %d\n", list->tasks[i].priority);
        printf("   Status: %s\n", list->tasks[i].is_completed ? "✅ Completed" : "❌ Not Completed");
        printf("────────────────────────────────────────\n");
    }
}

void save_tasks_to_file(const ToDoList *list, const char *filename) {
    printf("\n💾 Saving tasks to file...\n");
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("❌ Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < list->task_count; ++i) {
        fprintf(file, "%d %s %d %d\n", 
            list->tasks[i].id, 
            list->tasks[i].title, 
            list->tasks[i].priority, 
            list->tasks[i].is_completed);
    }

    fclose(file);
    printf("✅ Tasks saved successfully!\n");
}

// Function to load tasks from a file
void load_tasks_from_file(ToDoList *list, const char *filename) {
    printf("\n📂 Loading tasks from file...\n");
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("❌ Error opening file for reading.\n");
        return;
    }

    list->task_count = 0; // Reset task count before loading

    while (fscanf(file, "%d %255s %d %d", 
                  &list->tasks[list->task_count].id, 
                  list->tasks[list->task_count].title, 
                  &list->tasks[list->task_count].priority, 
                  &list->tasks[list->task_count].is_completed) != EOF) {
        list->task_count++;
        if (list->task_count >= list->capacity) {
            printf("⚠️ Task list full. Not all tasks loaded.\n");
            break;
        }
    }

    fclose(file);
    printf("✅ Tasks loaded successfully!\n");
}

int main() {
    ToDoList *todoList = NULL; 
    int choice;
    int initial_capacity = 5; 

    printf("\n══════════════════════════════════════════════════════════\n");
    printf("🏆 THE ULTIMATE TO-DO LIST MANAGER 🏆\n");
    printf("══════════════════════════════════════════════════════════\n");

    todoList = initialize_todo_list(initial_capacity);
    if (todoList == NULL) {
        printf("❌ Failed to initialize ToDoList. Exiting.\n");
        return 1;
    }

    while (1) {
        printf("\n╔══════════════════════════════════════════════════════════╗\n");
        printf("║                    🗒️  TO-DO MENU 🗒️                     ║\n");
        printf("╠══════════════════════════════════════════════════════════╣\n");
        printf("║  1. ➕ Add Task                                          ║\n");
        printf("║  2. 🗑️  Remove Task                                      ║\n");
        printf("║  3. 🔄 Toggle Task Status                                ║\n");
        printf("║  4. 📋 Display All Tasks                                 ║\n");
        printf("║  5. 💾 Save Tasks to File                                ║\n");
        printf("║  6. 📂 Load Tasks from File                              ║\n");
        printf("║  7. 🚪 Exit                                              ║\n");
        printf("╚══════════════════════════════════════════════════════════╝\n");
        printf("\n🎯 Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_task(todoList);
                break;
            case 2:
                printf("╔══════════════════════════════════════════════════════════╗\n");
                printf("║                    🗑️ REMOVE TASK 🗑️                     ║\n");
                printf("╚══════════════════════════════════════════════════════════╝\n\n");
                printf("🗑️ Enter task ID to remove: ");
                int id_to_remove;
                scanf("%d", &id_to_remove);
                remove_task(todoList, id_to_remove);
                printf("🗑️ Task removed successfully!\n");
                break;
            case 3:
                printf("╔══════════════════════════════════════════════════════════╗\n");
                printf("║                    🔄 TOGGLE STATUS 🔄                   ║\n");
                printf("╚══════════════════════════════════════════════════════════╝\n\n");
                printf("🔄 Enter task ID to toggle status: ");
                int id_to_toggle;
                scanf("%d", &id_to_toggle);
                toggle_task_status(todoList, id_to_toggle);
                printf("🔄 Task status toggled!\n");
                break;
            case 4:
                display_tasks(todoList);
                break;
            case 5:
                save_tasks_to_file(todoList, "tasks.txt");
                break;
            case 6:
                load_tasks_from_file(todoList, "tasks.txt");
                break;
            case 7:
                printf("\n\n🚪 ═══════════════════════════════════════════════════════\n");
                printf("   🧹 CLEANING UP AND EXITING... 🧹\n");
                printf("   ═══════════════════════════════════════════════════════\n");
                free(todoList->tasks);
                free(todoList);
                printf("👋 Goodbye! Thanks for using the Ultimate To-Do Manager!\n");
                return 0;
            default:
                printf("\n⚠️  ═══════════════════════════════════════════════════════\n");
                printf("   ❌ INVALID CHOICE! PLEASE TRY AGAIN ❌\n");
                printf("   ═══════════════════════════════════════════════════════\n");
        }
    }
}
