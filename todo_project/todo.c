// Write a simple C program that allows you to manage todos with due dates

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct task
{
    int task_id;
    char task_name[100];
    char task_description[200];
    char due_date[20];
    char *ptr;
    char *ptr2;
};

// create initial memory for tasks
struct task static *initialTask(int id, char name[], char description[], char due_date[])
{
    struct task *ptr = malloc(10 * sizeof(struct task));

    if (ptr == NULL)
    {
        printf("Malloc failed");
        abort();
    }
    else
    {
        printf("Malloc successful");
        ptr->task_id = id;
        strcpy(ptr->task_name, name);
        strcpy(ptr->task_description, description);
        strcpy(ptr->due_date, due_date);

        // printf("\n%p\n%p\n", ptr, &ptr);
        printf("\nName: %s\n", name);
        printf("Description: %s\n", description);
        printf("Due Date: %s\n", due_date);

        free(ptr);
    }
    return ptr;
}

// realloc memory for tasks
void static resizeTask(struct task **ptr, int id, char name[], char description[], char due_date[])
{
    struct task *ptr2 = realloc(*ptr, 40 * sizeof(struct task));

    if (ptr2 == NULL)
    {
        printf("Realloc failed");
        abort();
    }
    else
    {
        printf("Realloc successful");
    }
    free(ptr2);
}

// write tasks to file
void static createTask(struct task **ptr, int id, char name[], char description[], char due_date[])
{

    int i, n = 1;
    int count = 0;

    for (i = 0; i < n; i++)
    {

        FILE *fptr = fopen("todolist.txt", "a");
        count++;
        fprintf(fptr, "\n%d\t %s\t %s\t %s\t", count, name, description, due_date);
        printf("\nCreated task successfully!: %s", name);
        fclose(fptr);
    }
}

// read all tasks from file
void static readTask(struct task **ptr, char name[], char description[], char due_date[])
{
    FILE *fptr = fopen("todolist.txt", "r");

    int i, n = 2;
    // int count = 0;

    puts("\n#\t Task Name:\t Description:\t Due Date:\n");
    for (i = 0; i < n; i++)
    {
        fscanf(fptr, "%s\t %s\t %s\t", name, description, due_date);
        printf("%s\t %s\t %s\t\n", name, description, due_date);
        fclose(fptr);
    }
}

int main()
{

    while (true)
    {
        char choice[10];
        struct task todo;
        struct task *tasks = NULL;
        // char ptr;

        printf("--------------------------------------\n");
        printf("To add a new task: type 'c'\n");
        printf("To see all current tasks: type 'r'\n");
        printf("To update a task: type 'u'\n");
        printf("To delete a task: type 'd'\n");
        printf("--------------------------------------");

        printf("\nYour response: ");
        fgets(choice, 9, stdin);
        sscanf(choice, "%s", choice);

        if (strcmp(choice, "c") == 0)
        {

            printf("Enter task name: ");
            fgets(todo.task_name, sizeof(todo.task_name), stdin);
            sscanf(todo.task_name, "%99[^\n]", todo.task_name);

            printf("Enter task description: ");
            fgets(todo.task_description, sizeof(todo.task_description), stdin);
            sscanf(todo.task_description, "%99[^\n]", todo.task_description);

            printf("Enter due date: ");
            fgets(todo.due_date, sizeof(todo.due_date), stdin);
            sscanf(todo.due_date, "%s", todo.due_date);

            initialTask(todo.task_id, todo.task_name, todo.task_description, todo.due_date);
            resizeTask(&tasks, todo.task_id, todo.task_name, todo.task_description, todo.due_date);
            createTask(&tasks, todo.task_id, todo.task_name, todo.task_description, todo.due_date);
        }
        else if (strcmp(choice, "r") == 0)
        {
            printf("succesful read \n");
            resizeTask(&tasks, todo.task_id, todo.task_name, todo.task_description, todo.due_date);
            readTask(&tasks, todo.task_name, todo.task_description, todo.due_date);
        }

        return 0;
    }
}
