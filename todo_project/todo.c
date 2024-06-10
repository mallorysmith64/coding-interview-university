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
    // char due_date[20];
    char *ptr;
    char *ptr2;
};

// create initial memory for tasks
struct task static *initialTask(int id, char name[], char description[])
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
        struct task *t;
        // memset(&t, 0, sizeof(t));
        t->task_id;
        // strncpy(ptr->task_name, name, 100);
        strcpy(ptr->task_name, name);
        strcpy(ptr->task_description, description);
        // strcpy(ptr->due_date, due_date);

        printf("\nName: %s\n", name);
        printf("Description: %s\n", description);
        // printf("Due Date: %s\n", due_date);

        // free(ptr);
    }
    return ptr;
}

// realloc memory for tasks
void static resizeTask(struct task **ptr, int id, char name[], char description[])
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
void static createTask(struct task **ptr, int id, char name[], char description[])
{

    int i, n = 1;
    int count = 0;

    for (i = 0; i < n; i++)
    {

        FILE *fptr = fopen("todolist.txt", "a");

        fprintf(fptr, "\n%d\t%s\t%s\t", count, name, description);
        printf("\nCreated task successfully!\n%s\n%s", name, description);
        count++;
        fclose(fptr);
    }
}

// read all tasks from file
void static readTask(struct task **ptr, int id, char name[], char description[])
{
    FILE *fptr = fopen("todolist.txt", "r");

    if (fptr == NULL)
    {
        perror("File does not exist");
        exit(1);
    }

    puts("\n#\tTask Name:\tDescription:\tDue Date:");

    while (!feof(fptr))
    {
        char ch;
        ch = fgetc(fptr);
        printf("%c", ch);
    }
    fclose(fptr);
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

            // printf("Enter due date: ");
            // fgets(todo.due_date, sizeof(todo.due_date), stdin);
            // sscanf(todo.due_date, "%s", todo.due_date);

            initialTask(todo.task_id, todo.task_name, todo.task_description);
            resizeTask(&tasks, todo.task_id, todo.task_name, todo.task_description);
            createTask(&tasks, todo.task_id, todo.task_name, todo.task_description);
        }
        else if (strcmp(choice, "r") == 0)
        {
            printf("succesful read \n");
            resizeTask(&tasks, todo.task_id, todo.task_name, todo.task_description);
            readTask(&tasks, todo.task_id, todo.task_name, todo.task_description);
        }

        return 0;
    }
}
