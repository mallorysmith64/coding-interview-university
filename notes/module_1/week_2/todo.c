// Write a simple C program that allows you to manage todos with due dates

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task
{
    int task_id;
    char task_name[20];
    char task_description[50];
    char due_date[20];
};

struct task *newTask(int id, char name[], char description[], char due_date[])
{
    struct task *ptr1 = malloc(sizeof(struct task));
    ptr1->task_id = id;
    strcpy(ptr1->task_name, name);
    strcpy(ptr1->task_description, description);
    strcpy(ptr1->due_date, due_date);

    printf("%p\n", (void *)ptr1);
    return ptr1;
}

void addTask(int id, char name[], char description[], char due_date[])
{
    char *a;
    char *b;
    char *c;
    // struct task *temp = realloc(*ptr1, 255 * sizeof(char));
    printf("Enter task name: \n");
    // scanf("%s/n", &a);
    printf("Added successfuly \n");

    printf("Enter description: \n");
    // scanf("%s", &b);
    printf("Added successfuly \n");

    // free(temp);
}

int main()
{
    struct task *t;
    char a, b;
    char command[10];

    printf("To add a new task: type 'c'\n");
    printf("To see all current tasks: type 'r'\n");
    printf("To update a task: type 'u'\n");
    printf("To delete a task: type 'd'\n");

    while (1)
    {
        scanf("%s", command);

        if (strcmp(command, "c") == 0)
        {
            // addTask("%d", "%ch", "%ch", "%ch");
        }

        return 0;
    }
}

// read all tasks to user
// void displayTask(struct task *t)
// {
//     printf("Task Name: %s \n",
//            t->task_name);
//     // printf("Task Description: %s\n",
//     //        t->task_description);
// }