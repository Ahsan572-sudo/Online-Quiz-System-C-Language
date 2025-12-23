#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//          ************ QUESTION CLAS  *************
class Question {
public:
    string text, optA, optB, optC, optD;
    char correct;

    void inputQuestion() {
        cout << "\nEnter question: ";
        cin.ignore();
        getline(cin, text);
        cout << "Option A: ";
		getline(cin, optA);
        cout << "Option B: "; 
		getline(cin, optB);
        cout << "Option C: ";
	    getline(cin, optC);
        cout << "Option D: "; 
		getline(cin, optD);
        cout << "Correct option (A/B/C/D): ";
        cin >> correct;
    }

    void displayQuestion() {
        cout << "\nQ: " << text << endl;
        cout << "A) " << optA << endl;
        cout << "B) " << optB << endl;
        cout << "C) " << optC << endl;
        cout << "D) " << optD << endl;
    }
};

// 			********** ADMIN CLASS  **********
class Admin {
public:
    void login() {
        string user, pass;
        cout << "\n=== Admin Login ===\n";
        cout << "Username: "; 
		cin >> user;
        cout << "Password: "; 
		cin >> pass;

        if (user == "admin" && pass == "1234") {
            cout << "Login successful!\n";
            menu();
        } else {
            cout << "Invalid login!\n";
        }
    }

    void menu() {
        int ch;
        do {
            cout << "\n=== Admin Menu ===\n";
            cout << "1. Add Question\n";
			cout << "2. view Question\n";
			cout << "3. Exit";
            cout << "Enter choice: ";
            cin >> ch;

            if (ch == 1) addQuestion();
            else if (ch == 2) viewQuestions();
        } while (ch != 3);
    }

    void addQuestion() {
        ofstream fout("questions.txt", ios::app);
        Question q;
        q.inputQuestion();
        fout << q.text << "|" << q.optA << "|" << q.optB << "|" 
             << q.optC << "|" << q.optD << "|" << q.correct << endl;
        fout.close();
        cout << "Question added successfully!\n";
    }

    void viewQuestions() {
        ifstream fin("questions.txt");
        string line;
        cout << "\n=== All Questions ===\n";
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }
};

//  			********** STUDENT CLASS  **********
class Student {
    string name, username, password;
public:
    void registerStudent() {
        cout << "\n=== Student Registration ===\n";
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Create username: ";
        cin >> username;
        cout << "Create password: ";
        cin >> password;

        ofstream fout("students.txt", ios::app);
        fout << username << " " << password << " " << name << endl;
        fout.close();
        cout << "Registration successful!\n";
    }

    void login() {
        cout << "\n=== Student Login ===\n";
        string u, p, fileUser, filePass, fileName;
        cout << "Username: "; cin >> u;
        cout << "Password: "; cin >> p;

        ifstream fin("students.txt");
        bool found = false;

        while (fin >> fileUser >> filePass) {
            getline(fin, fileName); // read remaining name
            if (u == fileUser && p == filePass) {
                found = true;
                cout << "Login successful! Welcome " << fileName << endl;
                takeExam();
                break;
            }
        }
        fin.close();

        if (!found)
            cout << "Invalid login!\n";
    }

    void takeExam() {
        ifstream fin("questions.txt");
        if (!fin) {
            cout << "No questions found. Ask admin to add some.\n";
            return;
        }

        string text, optA, optB, optC, optD;
        char correct, answer;
        int score = 0, total = 0;
        string line;

        cout << "\n=== Exam Started ===\n";

        while (getline(fin, line)) {
            int count = 0;
            string part[6], temp = "";
            for (int i = 0; i < line.size(); i++) {
                if (line[i] == '|') {
                    part[count++] = temp;
                    temp = "";
                } else temp += line[i];
            }
            part[count] = temp;

            text = part[0];
            optA = part[1];
            optB = part[2];
            optC = part[3];
            optD = part[4];
            correct = part[5][0];

            cout << "\nQ: " << text << endl;
            cout << "A) " << optA << "\nB) " << optB
                 << "\nC) " << optC << "\nD) " << optD << endl;
            cout << "Your answer (A/B/C/D): ";
            cin >> answer;

            if (toupper(answer) == toupper(correct))
                score++;
            total++;
        }

        fin.close();
        cout << "\nExam Finished!\n";
        cout << "You scored: " << score << " out of " << total << endl;
        float percent = (score * 100.0) / total;
        cout << "Percentage: " << percent << "%\n";

        ofstream fout("results.txt", ios::app);
        fout << username << " scored " << score << "/" << total
             << " (" << percent << "%)\n";
        fout.close();
    }
};

// 			**********Main Menu**********
class ExamSystem {
public:
    void menu() {
        int choice;
        Admin admin;
        Student student;

        do {
            cout << "\n*****ASSALAMUALIKUM EVERY ONE*****\n ====ONLINE Quiz SYSTEM =====\n";
            cout << "1. Admin Login\n";
            cout << "2. Student Register\n";
            cout << "3. Student Login\n";
            cout << "4. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            if (choice == 1)
                admin.login();
            else if (choice == 2)
                student.registerStudent();
            else if (choice == 3)
                student.login();
        } while (choice != 4);

        cout << "Thank you for using the system!\n";
    }
};

//  			********** MAIN FUNCTION  **********
int main() {
    ExamSystem system;
    system.menu();
    return 0;
}