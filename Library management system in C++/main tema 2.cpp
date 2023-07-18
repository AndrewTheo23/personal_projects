#include <iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<cstring>
#include<iomanip>
#include<stdlib.h>

using namespace std;

class book
{
private:
	char book_number[6];
	char book_name[50];
	char author_name[20];
	float book_rating;
	unsigned int book_age;
public:
	void set_book_number(char u_book_number);
	void set_book_name(char u_book_name);
	void set_author_name(char u_author_name);
	void set_book_rating(float u_book_rating);
	void set_book_age(unsigned int u_book_age);
	
	char get_book_number();
	char get_book_name();
	char get_author_name();
	float get_book_rating();
	unsigned int get_book_age();
	
	void show_bestselling(int book_rating)
	{
		if (book_rating >= 5)
			cout << "Yes";
		else cout << "No";
	}
	void show_age_state(int book_age)
	{
		if (book_age >= 25)
			cout << "Old";
		else cout << "New";
	}
	void create_book()
	{
		cout << "\nNEW BOOK ENTRY...\n";
		cout << "\nEnter The book no.";
		cin >> book_number;
		cout << "\n\nEnter The Name of The Book: ";
		cin >> book_name;
		cout << "\n\nEnter The Author's Name: ";
		cin >> author_name;
		cout << "\n\nEnter Rating (1-10): ";
		cin >> book_rating;
		cout << "\n\nEnter the age of the book(0-100): ";
		cin >> book_age;
		cout << "\n\n\nBook Created..";
	}

	void show_book()
	{
		cout << "\nBook no. : " << book_number << endl;
		cout << "\nBook Name : " << book_name << endl;
		cout << "Author Name : " << author_name << endl;
		cout << "Rating : " << book_rating << endl;
		cout << "Age : " << book_age << endl;
	}

	void modify_book()
	{
		cout << "\nBook no. : " << book_number;
		cout << "\nModify Book Name : ";
		cin >> book_name;
		cout << "\nModify Author's Name of Book : ";
		cin >> author_name;
		cout << "\nModify Book's Rating : ";
		cin >> book_rating;
		cout << "\nModify Book's Age : ";
		cin >> book_age;
	}

	char* return_book_number()
	{
		return book_number;
	}

	void report() {
		cout << book_number << setw(25) << book_name << setw(25) << author_name << setw(25);
		show_bestselling(book_rating);
		cout << setw(25);
		show_age_state(book_age);
		cout << endl;
	
	}

};

void book :: set_book_rating(float u_book_rating){
	book_rating = u_book_rating;
}
void book :: set_book_age(unsigned int u_book_age){
	book_age = u_book_age;
} 

float book :: get_book_rating(){
	return book_rating;
}
unsigned book :: get_book_age(){
	return book_age;
}

class student
{
private:
	char admission_number[6];
	char student_name[20];
	char student_book_number[6];
	int token;
public:
	void set_admission_number(char u_admission_number);
	void set_student_name(char u_student_name);
	void set_student_book_number(char u_student_book_number);
	void set_token(int u_token);
	
	char get_admission_number();
	char get_student_name();
	char get_student_book_number();
	int get_token();
	void create_student()
	{
		system("cls");
		cout << "\nNEW STUDENT ENTRY...\n";
		cout << "\nEnter The admission no.";
		cin >> admission_number;
		cout << "\n\nEnter The Name of The Student ";
		cin >> student_name;
		token = 0;
		student_book_number[0] = '/0';
		cout << "\n\nStudent Record Created..";
	}

	void show_student()
	{
		cout << "\nAdmission no. :          " << admission_number << endl;
		cout << "\nStudent Name :            " << student_name << endl;
		cout << "\nNo of Book issued : " << token << endl;
		if (token == 1)
			cout << "\nBook No " << student_book_number << endl;
	}

	void modify_student()
	{
		cout << "\nAdmission no. : " << admission_number << endl;
		cout << "\nModify Student Name : ";
		cin >> student_name;
	}

	char* return_admission_number()
	{
		return admission_number;
	}

	char* return_student_book_number()
	{
		return student_book_number;
	}

	int return_token()
	{
		return token;
	}

	void add_token() {
		token = 1;
	}

	void reset_token() {
		token = 0;
	}

	void get_student_book_number(char t[])
	{
		strcpy(student_book_number, t);
	}

	void report() {
		cout << "\t" << admission_number << setw(20) << student_name << setw(10) << token << endl;
	}

};
void student :: set_token(int u_token){
	token = u_token;
}
int student :: get_token(){
	return token;
}


class library : public book, student
{
private:
	fstream fp, fp1;
	book bk;
	student st;
public:
	void write_book()
	{
		char ch;
		fp.open("book.dat", ios::out | ios::app);
		do
		{
			system("cls");
			bk.create_book();
			fp.write((char*)&bk, sizeof(book));
			cout << "\n\nDo you want to add more record..(y/n?)";
			cin >> ch;
		} while (ch == 'y' || ch == 'Y');
		fp.close();
	}

	void write_student()
	{
		char ch;
		fp.open("student.dat", ios::out | ios::app);
		do
		{
			st.create_student();
			fp.write((char*)&st, sizeof(student));
			cout << "\n\ndo you want to add more record..(y/n?)";
			cin >> ch;
		} while (ch == 'y' || ch == 'Y');
		fp.close();
	}


	void display_spb(char n[])
	{
		cout << "\nBOOK DETAILS\n";
		int flag = 0;
		fp.open("book.dat", ios::in);
		while (fp.read((char*)&bk, sizeof(book)))
		{
			if (_strcmpi(bk.return_book_number(), n) == 0)
			{
				bk.show_book();
				flag = 1;
			}
		}

		fp.close();
		if (flag == 0)
			cout << "\n\nBook does not exist";
		getch();
	}

	void display_sps(char n[])
	{
		cout << "\nSTUDENT DETAILS\n";
		int flag = 0;
		fp.open("student.dat", ios::in);
		while (fp.read((char*)&st, sizeof(student)))
		{
			if ((_strcmpi(st.return_admission_number(), n) == 0))
			{
				st.show_student();
				flag = 1;
			}
		}

		fp.close();
		if (flag == 0)
			cout << "\n\nStudent does not exist";
		getch();
	}

	void modify_book()
	{
		char n[6];
		int found = 0;
		system("cls");
		cout << "\n\n\tMODIFY BOOK RECORD.... ";
		cout << "\n\n\tEnter The book no. of The book";
		cin >> n;
		fp.open("book.dat", ios::in | ios::out);
		while (fp.read((char*)&bk, sizeof(book)) && found == 0)
		{
			if (_strcmpi(bk.return_book_number(), n) == 0)
			{
				bk.show_book();
				cout << "\nEnter The New Details of book" << endl;
				bk.modify_book();
				int pos = -1 * (int)sizeof(bk);
				fp.seekp(pos, ios::cur);
				fp.write((char*)&bk, sizeof(book));
				cout << "\n\n\t Record Updated";
				found = 1;
			}
		}
		fp.close();
		if (found == 0)
			cout << "\n\n Record Not Found ";
		getch();
	}



	void modify_student()
	{
		char n[6];
		int found = 0;
		system("cls");
		cout << "\n\n\tMODIFY STUDENT RECORD... ";
		cout << "\n\n\tEnter The admission no. of The student";
		cin >> n;
		fp.open("student.dat", ios::in | ios::out);
		while (fp.read((char*)&st, sizeof(student)) && found == 0)
		{
			if (_strcmpi(st.return_admission_number(), n) == 0)
			{
				st.show_student();
				cout << "\nEnter The New Details of student" << endl;
				st.modify_student();
				int pos = -1 * (int)sizeof(st);
				fp.seekp(pos, ios::cur);
				fp.write((char*)&st, sizeof(student));
				cout << "\n\n\t Record Updated";
				found = 1;
			}
		}

		fp.close();
		if (found == 0)
			cout << "\n\n Record Not Found ";
		getch();
	}

	void delete_student()
	{
		char n[6];
		int flag = 0;
		system("cls");
		cout << "\n\n\n\tDELETE STUDENT...";
		cout << "\n\nEnter The admission no. of the Student You Want To Delete : ";
		cin >> n;
		fp.open("student.dat", ios::in | ios::out);
		fstream fp2;
		fp2.open("Temp.dat", ios::out);
		fp.seekg(0, ios::beg);
		while (fp.read((char*)&st, sizeof(student)))
		{
			if (_strcmpi(st.return_admission_number(), n) != 0)
				fp2.write((char*)&st, sizeof(student));
			else
				flag = 1;
		}

		fp2.close();
		fp.close();
		remove("student.dat");
		rename("Temp.dat", "student.dat");
		if (flag == 1)
			cout << "\n\n\tRecord Deleted ..";
		else
			cout << "\n\nRecord not found";
		getch();
	}

	void delete_book()
	{
		char n[6];
		system("cls");
		cout << "\n\n\n\tDELETE BOOK ...";
		cout << "\n\nEnter The Book no. of the Book You Want To Delete : ";
		cin >> n;
		fp.open("book.dat", ios::in | ios::out);
		fstream fp2;
		fp2.open("Temp.dat", ios::out);
		fp.seekg(0, ios::beg);
		while (fp.read((char*)&bk, sizeof(book)))
		{
			if (_strcmpi(bk.return_book_number(), n) != 0)
			{
				fp2.write((char*)&bk, sizeof(book));
			}
		}

		fp2.close();
		fp.close();
		remove("book.dat");
		rename("Temp.dat", "book.dat");
		cout << "\n\n\tRecord Deleted ..";
		getch();
	}

	void display_alls()
	{
		system("cls");
		fp.open("student.dat", ios::in);
		if (!fp)
		{
			cout << "ERROR!!! FILE COULD NOT BE OPEN ";
			getch();
			return;
		}

		cout << "\n\n\t\tSTUDENT LIST\n\n";
		cout << "==================================================================\n";
		cout << "Admission No." << setw(10) << "        Name" << setw(20) << "Book Issued\n";
		cout << "==================================================================\n";

		while (fp.read((char*)&st, sizeof(student)))
		{
			st.report();
		}

		fp.close();
		getch();
	}

	void display_allb()
	{
		system("cls");
		fp.open("book.dat", ios::in);
		if (!fp)
		{
			cout << "ERROR!!! FILE COULD NOT BE OPEN ";
			getch();
			return;
		}

		cout << "\n\n\t\tBook LIST\n\n";
		cout << "===================================================================================================================\n";
		cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author" << setw(25) << "Category" << setw(25) << "Age" << endl;
		cout << "===================================================================================================================\n";

		while (fp.read((char*)&bk, sizeof(book)))
		{
			bk.report();
		}
		fp.close();
		getch();
	}

	void book_issue()
	{
		char student_book_number[6], book_number[6];
		int found = 0, flag = 0;
		system("cls");
		cout << "\n\nBOOK ISSUE ...";
		cout << "\n\n\tEnter The student's admission no.";
		cin >> student_book_number;
		fp.open("student.dat", ios::in | ios::out);
		fp1.open("book.dat", ios::in | ios::out);
		while (fp.read((char*)&st, sizeof(student)) && found == 0)
		{
			if (_strcmpi(st.return_admission_number(), student_book_number) == 0)
			{
				found = 1;
				if (st.return_token() == 0)
				{
					cout << "\n\n\tEnter the book no. ";
					cin >> book_number;
					while (fp1.read((char*)&bk, sizeof(book)) && flag == 0)
					{
						if (_strcmpi(bk.return_book_number(), book_number) == 0)
						{
							bk.show_book();
							flag = 1;
							st.add_token();
							st.get_student_book_number(bk.return_book_number());
							int pos = -1 * (int)sizeof(st);
							fp.seekp(pos, ios::cur);
							fp.write((char*)&st, sizeof(student));
							cout << "\n\n\t Book issued successfully\n\nPlease Note: Write the current date 						in backside of your book and submit within 15 days fine 5 Ron for each day 							after 15 days period";
						}
					}
					if (flag == 0)
						cout << "Book no does not exist";
				}
				else
					cout << "You have not returned the last book ";

			}
		}
		if (found == 0)
			cout << "Student record not exist...";
		getch();
		fp.close();
		fp1.close();
	}

	void book_deposit()
	{
		char sn[6], bn[6];
		int found = 0, flag = 0, day, fine;
		system("cls");
		cout << "\n\nBOOK DEPOSIT ...";
		cout << "\n\n\tEnter The student's admission no.";
		cin >> sn;
		fp.open("student.dat", ios::in | ios::out);
		fp1.open("book.dat", ios::in | ios::out);
		while (fp.read((char*)&st, sizeof(student)) && found == 0)
		{
			if (_strcmpi(st.return_admission_number(), sn) == 0)
			{
				found = 1;
				if (st.return_token() == 1)
				{
					while (fp1.read((char*)&bk, sizeof(book)) && flag == 0)
					{
						if (_strcmpi(bk.return_book_number(), st.return_student_book_number()) == 0)
						{
							bk.show_book();
							flag = 1;
							cout << "\n\nBook deposited in no. of days";
							cin >> day;
							if (day > 15)
							{
								fine = (day - 15) * 5;
								cout << "\n\nFine has to deposited  " <<fine<<" RON";
							}
							st.reset_token();
							int pos = -1 * (int)sizeof(st);
							fp.seekp(pos, ios::cur);
							fp.write((char*)&st, sizeof(student));
							cout << "\n\n\t Book deposited successfully";
						}
					}
					if (flag == 0)
						cout << "Book no does not exist";
				}
				else
					cout << "No book is issued..please check!!";
			}
		}
		if (found == 0)
			cout << "Student record not exist...";
		getch();
		fp.close();
		fp1.close();
	}

	void intro()
	{
		system("cls");
		cout << "LIBRARY MANAGEMENT SYSTEM" << endl;
		cout << "\n\nMADE BY : ASAVEI	THEODOR - ANDREI";
		cout << "\n\nFACULTY  : FACULTY OF ELECTRONICS, TELECOMMUNICATIONS, AND INFORMATION TECHNOLOGY";
		getch();
	}

	void admin_menu()
	{
		system("cls");
		int ch2;
		cout << "\n\n\n\tADMINISTRATOR MENU";
		cout << "\n\n\t1.CREATE STUDENT RECORD";
		cout << "\n\n\t2.DISPLAY ALL STUDENTS RECORD";
		cout << "\n\n\t3.DISPLAY SPECIFIC STUDENT RECORD ";
		cout << "\n\n\t4.MODIFY STUDENT RECORD";
		cout << "\n\n\t5.DELETE STUDENT RECORD";
		cout << "\n\n\t6.CREATE BOOK ";
		cout << "\n\n\t7.DISPLAY ALL BOOKS ";
		cout << "\n\n\t8.DISPLAY SPECIFIC BOOK ";
		cout << "\n\n\t9.MODIFY BOOK ";
		cout << "\n\n\t10.DELETE BOOK ";
		cout << "\n\n\t11.BACK TO MAIN MENU";
		cout << "\n\n\tPlease Enter Your Choice (1-11) ";
		cin >> ch2;
		switch (ch2)
		{
		case 1: system("cls");
			write_student(); break;
		case 2: display_alls(); break;
		case 3:
			char num[6];
			system("cls");
			cout << "\n\n\tPlease Enter The Admission No. ";
			cin >> num;
			display_sps(num);
			break;
		case 4: modify_student(); break;
		case 5: delete_student(); break;
		case 6: system("cls");
			write_book(); break;
		case 7: display_allb(); break;
		case 8: {
			char num[6];
			system("cls");
			cout << "\n\n\tPlease Enter The book No. ";
			cin >> num;
			display_spb(num);
			break;
		}
		case 9: modify_book(); break;
		case 10: delete_book(); break;
		case 11: return;
		default:cout << "\a";
		}
		admin_menu();
	}
};
int main()
{
	char ch;
	library L;
	L.intro();
	do
	{
		system("cls");
		cout << "\n\n\n\tMAIN MENU";
		cout << "\n\n\t01. BOOK ISSUE";
		cout << "\n\n\t02. BOOK DEPOSIT";
		cout << "\n\n\t03. ADMINISTRATOR MENU";
		cout << "\n\n\t04. EXIT";
		cout << "\n\n\tPlease Select Your Option (1-4) ";
		ch = getche();
		switch (ch)
		{
		case '1':system("cls");
			L.book_issue();
			break;
		case '2':L.book_deposit();
			break;
		case '3':L.admin_menu();
			break;
		case '4':exit(0);
		default:cout << "\a";
		}
	} while (ch != '4');
}

