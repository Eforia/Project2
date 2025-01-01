#include "Projectstd.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_NAME 256
#define TABLE_SIZE 20
#define CUSTOMER_SIZE 5
#define ORDER_NUM 10


// struct to store report data
typedef struct report {
    int total_sales;
    int failed_s;   // total failed pruchase attempts
    float total;    // total sum of money generated
} report;

// struct to store product data
typedef struct product {
    char description[MAX_NAME]; // name of product
    int item_count;  
    float price;     
    int req;    //total requests
    int freq;   //failed requests
} product;

report final = {0, 0, 0};
product catalog[TABLE_SIZE];

void init_catalog() {
  product temp_catalog[TABLE_SIZE] = {
      {"Milk", 2, 2.99, 0, 0},     {"Eggs", 2, 4.50, 0, 0},
      {"Bread", 2, 1.99, 0, 0},    {"Butter", 2, 3.49, 0, 0},
      {"Cheese", 2, 5.99, 0, 0},   {"Apples", 2, 1.89, 0, 0},
      {"Bananas", 2, 1.29, 0, 0},  {"Chicken", 2, 4.99, 0, 0},
      {"Beef", 2, 6.99, 0, 0},     {"Rice", 2, 3.99, 0, 0},
      {"Pasta", 2, 1.79, 0, 0},    {"Tomato Sauce", 2, 2.49, 0, 0},
      {"Cereal", 2, 3.99, 0, 0},   {"Orange Juice", 2, 4.29, 0, 0},
      {"Coffee", 2, 8.99, 0, 0},   {"Tea", 2, 3.50, 0, 0},
      {"Potatoes", 2, 2.99, 0, 0}, {"Onions", 2, 1.89, 0, 0},
      {"Sugar", 2, 2.79, 0, 0},    {"Flour", 2, 2.49, 0, 0}};
  for (int i = 0; i < TABLE_SIZE; i++) {
    catalog[i] = temp_catalog[i];
  }
}

void order(int product_id, int write_fd) {
  char answer[MAX_NAME + 50];
  // using snprintf we can store a message in the answer variable and write that
  // the pipe
  if (product_id < 0 || product_id >= TABLE_SIZE) {
    snprintf(answer, sizeof(answer), "Error, nonexistant product ID: %d\n",
             product_id);
  } else if (catalog[product_id].item_count > 0) {
    catalog[product_id].item_count--;
    catalog[product_id].req++;
    final.total += catalog[product_id].price;
    snprintf(answer, sizeof(answer), "Purchase succesful: %s\n",
             catalog[product_id].description);
  } else {
    catalog[product_id].req++;
    catalog[product_id].freq++;
    snprintf(answer, sizeof(answer), "Purchase failed: %s is out of stock\n",
             catalog[product_id].description);
  }
  write(write_fd, answer, strlen(answer) + 1);
}

int main(int argc, char **argv) {

  int fd[CUSTOMER_SIZE][2];
  pid_t ppid[CUSTOMER_SIZE];

  srand(getpid());
  init_catalog();

  for (int i = 0; i < CUSTOMER_SIZE; i++) {
    if (pipe(fd[i]) == -1) {
      printf("Error regarding pipe creation\n");
      return 1;
    }

    if ((ppid[i] = fork()) == -1) {
      printf("Error regarding fork creation\n");
      return 1;
    }

    if (ppid[i] == 0) {
      // Child process

      close(fd[i][0]); // close read
      for (int j = 0; j < ORDER_NUM; j++) {
        int product_id =
            rand() % TABLE_SIZE; // picks random number based on table size
        write(fd[i][1], &product_id,
              sizeof(product_id)); // writes product id to pipe
        sleep(1);
      }
      close(fd[i][1]); // close write
      exit(0);         // close child
    }
  }


  // Parent process

  for (int i = 0; i < CUSTOMER_SIZE; i++) {
    close(fd[i][1]); // close write
  }

  for (int i = 0; i < CUSTOMER_SIZE; i++) {
    for (int j = 0; j < ORDER_NUM; j++) {
      int product_id;
      read(fd[i][0], &product_id, sizeof(product_id)); // read product id
      order(product_id, fd[i][1]);
    }
  }

  for (int i = 0; i < CUSTOMER_SIZE; i++) {
    waitpid(ppid[i], NULL, 0); // wait for child process to be terminated
    close(fd[i][0]);           // close read
  }

  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("Product: %s , was requested a total of: %d times with %d units "
           "sold and %d failed purchases due to insufficient stock\n",
           catalog[i].description, catalog[i].req, 2 - catalog[i].item_count,
           catalog[i].freq);
    final.total_sales += catalog[i].req;
    final.failed_s += catalog[i].freq;
  }

  printf("The total number of attempted sales was: %d, of those %d were "
         "completed while %d failed totaling %f euros \n",
         final.total_sales, final.total_sales - final.failed_s, final.failed_s,
         final.total);

  return 0;

}

