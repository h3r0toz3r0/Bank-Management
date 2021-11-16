# Bank Management Mini-Project
Author: Anna DeVries

Date: 3 August 2021

Purpose: for code review

Source: https://www.codewithc.com/mini-project-in-c-bank-management-system/

## Useage
make exec - compiles and runs program

make clean - cleans workspace, removes executables and .o files

## Bank Management Services
1) main() – This function displays the menu or welcome screen to perform different banking activities mentioned below.
2) new_acc() – This function creates a new customer account. It asks for some  personal details of the customer and allows the user to choose the type of bank account they would like to create – savings or checking.
3) view list() – With this function, the user can view their banking information.
4) edit() – This function allows the user to update their personal address and phone number.
5) transact() – With this function, the user can deposit and withdraw money to and from their personal account.
6) erase() – This function is for deleting a customer account.

## Parts
1) Writing to and from a file
2) FTP single server/client
3) Multiple clients and one server 

## Hints
Valgrind is your friend: `valgrind --leak-check=full ./BankService`

Security and memory management matter.
