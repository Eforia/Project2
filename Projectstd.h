#ifndef PROJECTSTD_H
#define PROJECTSTD_H

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

void init_catalog(); // init of catalog
void order(int product_id, int write_fd); // func for product orders



#endif  //end of header file
