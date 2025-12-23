# Online-Quiz-System-C-Language

COURSE PROJECT REPORT
Fall 2025

Project Title:  ONLINE QUIZ SYSTEM

SUBMITTED BY:
AHSAN ALI	S25CSC043
ATIF HABIB	S25CSC050
EHTISHAM   S25CSC038
FACULTY NAME (SIR HASSAN)

A project report submitted in partial fulfillment of the Requirements for the award of the degree of Bachelor of Computer Science 
     
DEPARTMENT OF COMPUTER SCIENCE
FACULTY OF INFORMATION TECHNOLOGY
SALIM HABIB UNIVERSITY, KARACHI



1. Introduction
Online Quiz System is a console based application developed using C++ and Object Oriented Programming concepts.
 The purpose of this project is to conduct quizzes in an online manner where students can register, login, attempt questions, and get results automatically.
 The system also provides an admin panel where questions can be added and viewed.
 This project helps in reducing manual work and improves accuracy in result calculation.

2. Goal of the Project
The main goal of this project is to develop a simple quiz system that works using OOPS concepts.
 The project aims to:
Provide an easy way to conduct quizzes


Automate result calculation


Practice object oriented programming in C++


Understand file handling for data storage



3. Problem Statement
Traditional quiz systems are mostly manual and require a lot of effort in checking answers and calculating results.
 There are chances of mistakes and it consumes more time. To solve this problem, an Online Quiz System is developed which automatically checks answers and displays results.

4. Target Audience
This system is mainly designed for:
Students who want to attempt quizzes


Teachers who want to conduct small tests


Beginners learning Object Oriented Programming


Educational institutes for practice purposes



5. Scope of the Project
The scope of this project includes:
Admin can add and view questions


Students can register and login


Students can attempt quizzes


System calculates score and percentage


This project does not include advanced features like database connectivity or graphical interface.
6. Object Oriented Programming Concepts Used
Class
Classes are used to represent different parts of the system.
 The main classes used are:
Question


Admin


Student


ExamSystem



Abstraction
Abstraction is achieved by separating functionalities into different classes.
 Each class performs its own task, such as admin handling questions and students attempting exams.
 The internal working of functions is hidden from the user.

Encapsulation
Encapsulation is implemented by grouping data members and functions inside classes.
 Student data like username and password is kept private and accessed through member functions only.


Object
Objects are created in the main program to access class functionalities.
 For example, objects of Admin and Student classes are created in the ExamSystem class.

7. System Description
Admin Module
Admin login using predefined username and password


Admin can add questions


Questions are stored in a text file


Admin can view all questions



Student Module
Student registration


Student login using file verification


Students can attempt quiz


Score and percentage are calculated automatically


Results are saved in a file

8. File Handling
File handling is used to store data permanently.
questions.txt → stores quiz questions


students.txt → stores student login data


results.txt → stores exam results



9. Implementation Details
The program starts from the main() function.
 An object of ExamSystem class is created which displays the main menu.
 Admin and Student operations are handled through separate classes.
 Questions are read from the file and displayed one by one during the exam.
 User answers are checked and score is updated accordingly.

10. GUI / Output Screen
This project is a console-based application.
 All input and output operations are performed through the terminal screen.
 Menus are displayed for admin and students for easy interaction.
 Although no graphical user interface is used, the system is user-friendly.



11. Result and Output
After attempting all questions:
Total score is displayed


Percentage is calculated


Result is stored in a file


The system successfully conducts the quiz and displays accurate results.

12. Future Aspects
This project can be improved in the future by:
Adding a graphical user interface (GUI)


Using database instead of text files


Adding timer for each quiz


Adding multiple quizzes and subjects


Improving security for login system

13. Conclusion
The Online Quiz System is a simple and effective project based on Object Oriented Programming.
 It helps in understanding classes, objects, abstraction, and file handling in C++.
 This project provides a strong base for developing more advanced applications in the future


