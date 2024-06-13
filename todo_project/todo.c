// Write a simple C program that allows you to manage todos with due dates

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define TASK_NAME_SIZE 100
#define TASK_DESCRIPTION_SiZE 200
#define TASK_DUE_DATE 20

#define TODO_FILE "todolist.txt"

struct task
{
    int id;
    char task_name[TASK_NAME_SIZE];
    char task_description[TASK_DESCRIPTION_SiZE];
    char due_date[TASK_DUE_DATE];
};

static void dumpTasks(struct task *tasks, int ntasks)
{
    for (int i = 0; i < ntasks; i++)
    {
        for (int j = 0; j < sizeof(struct task); j++)
        {
            char *ptr = (char *)(tasks + i);
            printf("%d ", ptr[j]);
        }
        printf("\n\n");
    }
    printf("\n\n");
}

// realloc memory for tasks
void static manageTaskArray(struct task **tasks, int *ntasks)
{
    // create initial memory for tasks
    if (*tasks == NULL)
    {
        printf("manageTaskArray(): line %d, *ptr was NULL\n", __LINE__);
        printf("manageTaskArray(): line %d, ntasks was %d\n", __LINE__, *ntasks);

        *ntasks = 1;
        printf("manageTaskArray(): line %d, ntasks was %d\n", __LINE__, *ntasks);
        *tasks = malloc(*ntasks * sizeof(struct task));
    }
    else
    {
        printf("manageTaskArray(): line %d, *ptr was %p\n", __LINE__, *tasks);
        printf("manageTaskArray(): line %d, ntasks was %d\n", __LINE__, *ntasks);

        (*ntasks)++;
        *tasks = realloc(*tasks, *ntasks * sizeof(struct task));
        printf("manageTaskArray(): line %d, *ptr was %p\n", __LINE__, *tasks);
    }
    if (tasks == NULL)
    {
        printf("Malloc/realloc failed, ntasks = %d\n", *ntasks);
        exit(1); // abort();
    }
    else
    {
        dumpTasks(*tasks, *ntasks);
        printf("Malloc successful\n");
        printf("sizeof struct task %ld\n", sizeof(struct task));
        printf("memory address of ptr + 0 %p\n", (void *)*tasks);
        printf("memory address of ptr + %d %p\n", *ntasks, (void *)(*tasks + *ntasks));
        memset((*tasks) + (*ntasks - 1), 0, sizeof(struct task));

        // printf("id: %d\n", id);
        // printf("Name: %s\n", name);
        // printf("Description: %s\n", description);
        // printf("Due Date: %s\n", due_date);
    }
}

// write tasks to file
void static writeTasksToDisk(struct task *tasks, int ntasks)
{
    FILE *fptr = fopen(TODO_FILE, "w");
    if (!fptr)
    {
        perror(TODO_FILE);
        exit(1);
    }

    for (int i = 0; i < ntasks; i++)
    {
        fprintf(fptr, "%d\t%s\t%s\t%s\n",
                tasks[i].id,
                tasks[i].task_name,
                tasks[i].task_description,
                tasks[i].due_date);

        // printf("\nId: %d\nName: %s\nDescription: %s\nDue_Date: %s\n",
        //        tasks[i].id,
        //        tasks[i].task_name,
        //        tasks[i].task_description,
        //        tasks[i].due_date);
    }

    printf("\nCreated task(s) successfully!\nNumber of tasks: %d\n ", ntasks);
    fclose(fptr);
}

static void displayTasks(struct task *tasks, int ntasks)
{
    for (int i = 0; i < ntasks; i++)
    {
        printf("\nId: %d\nName: %s\nDescription: %s\nDue_Date: %s\n",
               tasks[i].id,
               tasks[i].task_name,
               tasks[i].task_description,
               tasks[i].due_date);
    }
}

// read all tasks from file
static int readTasksFromDisk(struct task **tasks, int *ntasks)
{
    *tasks = NULL;
    *ntasks = 0;
    int highestID = -999999;
    FILE *fptr = fopen(TODO_FILE, "r");
    if (fptr == NULL)
    {
        perror(TODO_FILE);
        exit(1);
    }

    while (true)
    {
        struct task t;
        memset(&t, 0, sizeof(t));
        int r = fscanf(fptr, "%d\t%s\t%s\t%s\n", &t.id, t.task_name, t.task_description, t.due_date);

        if (t.id > highestID)
            highestID = t.id;
        if (r < 2) // if we didn't read anywhere near a whole line, we must be at EOF
            break;
        manageTaskArray(tasks, ntasks);
        memcpy((*tasks) + ((*ntasks) - 1), &t, sizeof(t));
        printf("record number: %d\n", (*ntasks) - 1);
        dumpTasks(*tasks, *ntasks);
        (*tasks, *ntasks);
    }
    fclose(fptr);
    return highestID;
}

int main()
{
    char choice[10];
    struct task *tasks = NULL; // , *currentTask = NULL;
    int ntasks = 0;
    int highwaterId = readTasksFromDisk(&tasks, &ntasks);
    ;
    // memset(&todo, 0, sizeof(struct task));

    while (1)
    {
        printf("--------------------------------------\n");
        printf("To add a new task: type 'c'\n");
        printf("To see all current tasks: type 'r'\n");
        printf("To update a task: type 'u'\n");
        printf("To delete a task: type 'd'\n");
        printf("To quit, type 'q'\n");
        printf("--------------------------------------");

        printf("\nYour response: ");
        memset(choice, 0, sizeof(choice));
        fgets(choice, 9, stdin);
        sscanf(choice, "%s", choice);

        if (strcmp(choice, "c") == 0 || strcmp(choice, "C") == 0)
        {
            char task_name[TASK_NAME_SIZE];
            char task_description[TASK_DESCRIPTION_SiZE];
            char task_due_date[TASK_DUE_DATE];

            printf("Enter task name: ");
            fgets(task_name, sizeof(task_name), stdin);
            sscanf(task_name, "%99[^\n]", task_name);

            printf("Enter task description: ");
            fgets(task_description, sizeof(task_description), stdin);
            sscanf(task_description, "%99[^\n]", task_description);

            printf("Enter due date: ");
            fgets(task_due_date, sizeof(task_due_date), stdin);
            sscanf(task_due_date, "%s", task_due_date);

            printf("\n");

            manageTaskArray(&tasks, &ntasks);
            // tasks = initialTask(highwaterId, task_name, task_description, due_date);
            // resizeTask(&tasks, todo.id, todo.task_name, todo.task_description, todo.due_date);
            struct task *newTask = tasks + (ntasks - 1);
            newTask->id = ++highwaterId;
            strncpy(newTask->task_name, task_name, sizeof(newTask->task_name));
            strncpy(newTask->task_description, task_description, sizeof(newTask->task_description));
            strncpy(newTask->due_date, task_due_date, sizeof(newTask->due_date));
            writeTasksToDisk(tasks, ntasks);
        }
        else if (strcmp(choice, "r") == 0 || strcmp(choice, "R") == 0)
        {
            printf("succesful read \n");
            displayTasks(tasks, ntasks);
        }
        else if (strcmp(choice, "q") == 0)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid choice. Try again\n");
        }
    }
    free(tasks);
    exit(0);
}
