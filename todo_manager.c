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


int main(void) {
    ToDoList *todoList = NULL;
    int choice = 0;
    int initial_capacity = 5;


    return 0;
}
