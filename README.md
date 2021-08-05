# Bank Management Mini-Project
Author: Anna DeVries

Date: 3 August 2021

Purpose: for code review

Source: https://www.codewithc.com/mini-project-in-c-bank-management-system/

## Bank Management Services
1) menu() – This function displays the menu or welcome screen to perform different banking activities mentioned below.
2) new_acc() – This function creates a new customer account. It asks for some  personal and banking details of the customer such as name, date of birth, citizenship number, address and phone number. You can enter the amount to deposit and choose one type of deposit account – saving, current, fixed for 1 year, fixed for 2 years or fixed for 3 years.
3) view list() – With this function, you can view the customer’s banking information such as account number, name, address and phone number provided while creating the account.
4) edit() – This function has been used for changing the address and phone number of a particular customer account.
5) transact() – With this function, you can deposit and withdraw money to and from a particular customer account.
6) erase() – This function is for deleting a customer account.
7) see() – This function shows account number, name, date of birth, citizenship number, age, address, phone number, type of account, amount deposited and date of deposit. It also displays the amount of interest corresponding to a particular account type.

## Parts
1) Writing to and from a file
2) Server client
3) Multiple clients and one server 

## Hints
Vagrant is your friend: `valgrind --leak-cheak=full ./bank_services`

Security and memory management matter.
