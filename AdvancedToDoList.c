#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100


struct Task {
    int id;
    char desc[100];
    int priority; 
    int status;  
};


void addTask(struct Task *tasks, int *count, FILE *file) {
    if (*count >= MAX_TASKS) {
        printf("Task limit reached!\n");
        return;
    }
    struct Task *t = &tasks[*count];
    t->id = *count + 1;
    printf("Enter task description: ");
    scanf(" %[^\n]s", t->desc);
    printf("Enter priority (1=High, 2=Medium, 3=Low): ");
    scanf("%d", &t->priority);
    t->status = 0; 
    fwrite(t, sizeof(struct Task), 1, file);
    (*count)++;
    printf("Task added successfully!\n");
}

void displayTasks(struct Task *tasks, int count) {
    if (count == 0) {
        printf("No tasks available.\n");
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (tasks[j].priority > tasks[j + 1].priority) {
                struct Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
    printf("\nTasks (Sorted by Priority):\n");
    printf("ID | Description | Priority | Status\n");
    for (int i = 0; i < count; i++) {
        printf("%d | %s | %s | %s\n", tasks[i].id, tasks[i].desc,
               tasks[i].priority == 1 ? "High" : (tasks[i].priority == 2 ? "Medium" : "Low"),
               tasks[i].status == 0 ? "Pending" : "Completed");
    }
}

void completeTask(struct Task *tasks, int count, FILE *file) {
    int id;
    printf("Enter task ID to mark as completed: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (tasks[i].id == id) {
            tasks[i].status = 1;
            printf("Task %d marked as completed!\n", id);
            rewind(file);
            fwrite(tasks, sizeof(struct Task), count, file);
            return;
        }
    }
    printf("Task ID not found.\n");
}

void deleteTask(struct Task *tasks, int *count, FILE *file) {
    int id;
    printf("Enter task ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (tasks[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }
            (*count)--;
            tasks[*count].id = *count + 1; 
            rewind(file);
            fwrite(tasks, sizeof(struct Task), *count, file);
            printf("Task deleted successfully!\n");
            return;
        }
    }
    printf("Task ID not found.\n");
}

int main() {
    struct Task tasks[MAX_TASKS];
    int taskCount = 0;
    FILE *file = fopen("tasks.dat", "rb+");
    if (!file) {
        file = fopen("tasks.dat", "wb+"); 
        if (!file) {
            printf("Error opening file!\n");
            return 1;
        }
    }

    fseek(file, 0, SEEK_END);
    taskCount = ftell(file) / sizeof(struct Task);
    rewind(file);
    fread(tasks, sizeof(struct Task), taskCount, file);

    int choice;
    while (1) {
        printf("\n=== Advanced To-Do List Manager ===\n");
        printf("1. Add Task\n2. Display Tasks\n3. Mark Task Completed\n4. Delete Task\n5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addTask(tasks, &taskCount, file); break;
            case 2: displayTasks(tasks, taskCount); break;
            case 3: completeTask(tasks, taskCount, file); break;
            case 4: deleteTask(tasks, &taskCount, file); break;
            case 5: printf("Exiting...\n"); fclose(file); return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}