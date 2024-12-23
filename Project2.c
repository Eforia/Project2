#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_NAME 256
#define TABLE_SIZE 20



typedef struct product{
    char name[MAX_NAME];
    int item_count;
    float price;
} product;


product array[TABLE_SIZE] = {
    {"Milk", 2, 2.99},
    {"Eggs", 2, 4.50},
    {"Bread", 2, 1.99},
    {"Butter", 2, 3.49},
    {"Cheese", 2, 5.99},
    {"Apples", 2, 1.89},
    {"Bananas", 2, 1.29},
    {"Chicken", 2, 4.99},
    {"Beef", 2, 6.99},
    {"Rice", 2, 3.99},
    {"Pasta", 2, 1.79},
    {"Tomato Sauce", 2, 2.49},
    {"Cereal", 2, 3.99},
    {"Orange Juice", 2, 4.29},
    {"Coffee", 2, 8.99},
    {"Tea", 2, 3.50},
    {"Potatoes", 2, 2.99},
    {"Onions", 2, 1.89},
    {"Sugar", 2, 2.79},
    {"Flour", 2, 2.49}
};


void main (int argc,char **argv)
{
    int ppid[5];
    ppid[0] = fork();

    if (ppid[0] == 0)
    {
        //parent process

        ppid[1] = fork();

        if(ppid[1] == 0)
        {
            //parent process

            ppid[2] = fork();
            if(ppid[2] == 0)
            {
                //parent process

                ppid[3] = fork();
                if(ppid[3] == 0)
                {
                    //parent process

                    ppid[4] = fork();
                    if(ppid[4] == 0)
                    {
                        //parent process
                    }
                    else if (ppid[4] == 1)
                    {
                        //child process
                    }
                    else
                    {
                        return -1;
                    }
                    
                }
                else if (ppid[3] == 1)
                {
                    //child process
                }
                else
                {
                    return -1;
                }
                
            }
            else if (ppid[2] == 1)
            {
                //child process
            }
                else
            {
                return -1;
            }
        }
        else if (ppid[1] == 1)
        {
            //child process
        }
        else
        {
            return -1;
        }
    }
    else if (ppid[0] == 1)
    {
        //child process
    }
    else
    {
        return -1;
    }
    
}