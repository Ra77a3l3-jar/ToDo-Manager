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

int main(void) {

    return 0;
}
