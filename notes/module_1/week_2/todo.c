// Write a simple C program that allows you to manage todos with due dates

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct task
{
    int task_id;
    char task_name[20];
    char task_description[50];
    char due_date[20];
    int *ptr;
};

struct task *newTask(int id, char name[], char description[], char due_date[])
{
    struct task *ptr = malloc(10 * sizeof(struct task));

    if (ptr == NULL)
    {
        printf("Malloc failed");
        abort();
    }
    else
    {
        printf("Malloc works\n");
        ptr->task_id = id;
        strcpy(ptr->task_name, name);
        strcpy(ptr->task_description, description);
        strcpy(ptr->due_date, due_date);

        printf("%p\n%p\n", ptr, &ptr);
        printf("Name: %s\n", name);
        printf("Description: %s\n", description);
        printf("Due Date: %s\n", due_date);
        free(ptr);
    }
    return ptr;
}

int main()
{
    char choice[10];
    struct task todo;

    printf("To add a new task: type 'c'\n");
    printf("To see all current tasks: type 'r'\n");
    printf("To update a task: type 'u'\n");
    printf("To delete a task: type 'd'\n");

    while (true)
    {
        printf("\nYour response: ");
        scanf("%s", choice);

        if (strcmp(choice, "c") == false)
        {
            printf("Enter task name: \n");
            scanf("%s", todo.task_name);

            printf("Enter task description: \n");
            scanf("%s", todo.task_description);

            printf("Enter due date: \n");
            scanf("%s", todo.due_date);
            newTask(todo.task_id, todo.task_name, todo.task_description, todo.due_date);
        }

        return 0;
    }
}

// void addTask(int id, char name[], char description[], char due_date[])
// {
//     char *a;
//     char *b;
//     char *c;
//     struct task *d = realloc((void *)a, 255 * sizeof(void *));

//     printf("Enter task name: \n");
//     // scanf("%ch/n", &d);
//     printf("Added successfuly \n");

//     printf("Enter description: \n");
//     // scanf("%s", &b);
//     printf("Added successfuly \n");

//     // free(temp);
// }