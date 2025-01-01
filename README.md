# Project2

Description /////////////

This program is supossed to create a pseudo e-shop that is handled between a parent and multiple child processes, the parent acting as the store and the children as customers. Using fork() to create child processes and pipe() to handle communications between child and parent.

//////////*


HOW TO RUN PROGRAM /////////////////

1) open terminal in the folder containing the Project2.c file
2) run the make file by typing "make" (the make file uses clang compiler as default if you are using gcc or any other compiler go into the make file and change CC = clang to CC = gcc)
3) now there should be an executable named Project2 now type "./Project2" in the terminal or double click the exe file and the program should run


////////////////////

If done correctly the program should print out something like this(numbers varying due to rng):


Product: Milk , was requested a total of: 10 times with 2 units sold and 8 failed purchases due to insufficient stock
Product: Eggs , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Bread , was requested a total of: 5 times with 2 units sold and 3 failed purchases due to insufficient stock
Product: Butter , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Cheese , was requested a total of: 10 times with 2 units sold and 8 failed purchases due to insufficient stock
Product: Apples , was requested a total of: 5 times with 2 units sold and 3 failed purchases due to insufficient stock
Product: Bananas , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Chicken , was requested a total of: 5 times with 2 units sold and 3 failed purchases due to insufficient stock
Product: Beef , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Rice , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Pasta , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Tomato Sauce , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Cereal , was requested a total of: 5 times with 2 units sold and 3 failed purchases due to insufficient stock
Product: Orange Juice , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Coffee , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Tea , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Potatoes , was requested a total of: 5 times with 2 units sold and 3 failed purchases due to insufficient stock
Product: Onions , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
Product: Sugar , was requested a total of: 5 times with 2 units sold and 3 failed purchases due to insufficient stock
Product: Flour , was requested a total of: 0 times with 0 units sold and 0 failed purchases due to insufficient stock
The total number of attempted sales was: 50, of those 16 were completed while 34 failed totaling 55.240005 euros

////////////////////////////////////////