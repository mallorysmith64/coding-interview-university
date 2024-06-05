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
struct task *initialTask(int id, char name[], char description[], char due_date[])
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

        printf("\n%p\n%p\n", ptr, &ptr);
        printf("Name: %s\n", name);
        printf("Description: %s\n", description);
        printf("Due Date: %s\n", due_date);

        free(ptr);
    }
    return ptr;
}

// write tasks to file
void createTask(struct task **ptr, int id, char name[], char description[], char due_date[])
{
    int i, n = 2;
    struct task *ptr2 = realloc(*ptr, 40 * sizeof(struct task));

    if (ptr2 == NULL)
    {
        printf("Realloc failed");
        abort();
    }
    else
    {
        printf("Realloc successful");

        FILE *fptr = fopen("todolist.txt", "a");

        int count = 1;
        for (i = 0; i < n; i++)
        {
            fprintf(fptr, "\n%d %s\t %s\t %s\t", count, name, description, due_date);
            count++;

            fclose(fptr);
        }
    }
}

int main()
{
    char choice[10];
    struct task todo;
    struct task *tasks = NULL;
    char ptr;

    printf("--------------------------------------\n");
    printf("To add a new task: type 'c'\n");
    printf("To see all current tasks: type 'r'\n");
    printf("To update a task: type 'u'\n");
    printf("To delete a task: type 'd'\n");
    printf("--------------------------------------");

    while (true)
    {
        printf("\nYour response: ");
        fgets(choice, 100, stdin);
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
            createTask(&tasks, todo.task_id, todo.task_name, todo.task_description, todo.due_date);
        }
        else if (strcmp(choice, "r") == 0)
        {
            printf("succesful read \n");
            createTask(&tasks, todo.task_id, todo.task_name, todo.task_description, todo.due_date);
        }

        return 0;
    }
}

// fprintf(fptr, "#\t Task Name:\t Description:\t Due Date:\n");