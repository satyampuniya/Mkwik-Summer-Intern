#include<fstream>
#include<conio.h>
#include<cstdio>
#include<process.h>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<stdlib.h>

using namespace std;

//Creating class book to store book details.

class book
{
	char book_no[6];		//	
	char book_name[50];		//		private members of class book.
	char author[20];		//
  public:
	
	//Function to create new book.
	
	void create_book()																						
	{
		cout<<"\nNEW BOOK ENTRY...\n";
		cout<<"\nEnter The book no.";
		cin>>book_no;													//Getting Book number for the new book to be added.
		cout<<"\n\nEnter The Name of The Book ";
		cin.ignore(256,'\n');											//To remove buff in order to use gets function
		gets(book_name);												//Getting Book name for the new book to be added.
		cout<<"\n\nEnter The Author's Name ";
		gets(author);													//Getting author name for the new book to be added.
		cout<<"\n\n\nBook Created..";
	}

	//Function to display book details.
	
	void show_book()
	{
		cout<<"\nBook no. : "<<book_no;		
		cout<<"\nBook Name : ";
		puts(book_name);
		cout<<"Author Name : ";
		puts(author);
	}

	//Function to return book number.
	
	char* retbook_no()
	{
		return book_no;
	}

};         //class ends here




class student
{
	char admno[6];			//
	char name[20];			//	private members
	char stbook_no[6];		//
	int token;				//

public:
	
	//Function to create new student.
	
	void create_student()
	{
		system("cls");													//function to clear screen.
	 	cout<<"\nNEW STUDENT ENTRY...\n";
	 	fp.open("student.dat",ios::out|ios::app);
	 	while(fp.read((char*)&student,sizeof(student)) && found==0)			//Reading student file till end
       	{
		cout<<"\nEnter The admission no. ";
		cin>>admno;
		if(strcmpi(st.retadmno(),admno)==0)								//If the student number inputed by user matches 														//Getting admission number for new student created.
		cout<<"\n\nEnter The Name of The Student ";
		cin.ignore(256,'\n');
		gets(name);														//Getting student name for new student created.
		token=0;														//Flag variable to check whether a book is issued or not.
		stbook_no[0]='/0';												//Flag variable to store book number
		cout<<"\n\nStudent Record Created..";
	}

	//Function to display student details.
	
	void show_student()
	{
		cout<<"\nAdmission no. : "<<admno;
		cout<<"\nStudent Name : ";
		puts(name);
		cout<<"\nNo of Book issued : "<<token;
		if(token==1)													//Checking whether a book is issued or not
			cout<<"\nBook No "<<stbook_no;
	}

	//Function to return admission number.
	
	char* retadmno()
	{
		return admno;
	}

	//Function to return admission number.
	
	char* retstbook_no()
	{
		return stbook_no;
	}

	//Function to return token value.
	
	int rettoken()
	{
		return token;
	}
	
	//Function to add token to show a book is issued.

	void addtoken()
	{
		token=1;
	}

	//Function to reset token to 0 i.e no book is issued.

	void resettoken()
	{
		token=0;
	}

	//Function to get the book number from user.
	
	void getstbook_no(char t[])
	{
		strcpy(stbook_no,t);
	}

};         																//class ends here


//Creating global file pointer and class objects.

fstream fp,fp1;
book bk;
student student;


//Function to write book details in file.

void write_book()
{
	char ch;
	fp.open("book.dat",ios::out|ios::app);											//File pointer used to write in the file
	do
	{
		system("cls");
		bk.create_book();															//calling create book function to create new book.
		fp.write((char*)&bk,sizeof(book));											//writing in the file.	
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');														//To check the choice of the user to continue or exit.
	fp.close();																		//File pointer closed.
}

//Function to write student details in file.

void write_student()
{
	char ch;					
	fp.open("student.dat",ios::out|ios::app);										//File pointer used to write in the file
	do
	{
		st.create_student();														//calling create student function to create new student.
		fp.write((char*)&st,sizeof(student));										//writing in the file.
		cout<<"\n\ndo you want to add more record..(y/n?)";				
		cin>>ch;
	}while(ch=='y'||ch=='Y');														//To check the choice of the user to continue or exit.
	fp.close();																		//File pointer close.
}

//Function to display book. 

void display_book(char n[])
{
	cout<<"\nBOOK DETAILS\n";
	int flag=0;
	fp.open("book.dat",ios::in);													//Reading from file to display book details.
	while(fp.read((char*)&bk,sizeof(book)))											//Traversing till end of file.
	{
		if(strcmpi(bk.retbook_no(),n)==0)											//Comparing if the character arrays are equal or not
		{
			bk.show_book();															//if found equal show book function from class function is called.
		 	flag=1;
		}
	}
	
	fp.close();																		//file pointer closed.
	if(flag==0)
		cout<<"\n\nBook does not exist";
	getch();
}

//Function To display student.

void display_student(char n[])
{
	cout<<"\nSTUDENT DETAILS\n";
	int flag=0;
	fp.open("student.dat",ios::in);						//Reading from file to display student details.
	while(fp.read((char*)&st,sizeof(student)))			//Traversing till end of file.
	{
		if((strcmpi(st.retadmno(),n)==0))				//Comparing if the character arrays are equal or not
		{
			st.show_student();							//if found equal show book function from class function is called.
			flag=1;
		}
	}
	
	fp.close();											//file pointer closed.
	if(flag==0)
    		cout<<"\n\nStudent does not exist";
 	getch();
}


//Function to issue book

void book_issue()
{
	char st_no[6],bk_no[6];
	int found=0,flag=0;
	system("cls");
	cout<<"\n\nBOOK ISSUE ...";
	cout<<"\n\n\tEnter The student's admission no.";
	cin>>st_no;															//Getting student admission no. 
	fp.open("student.dat",ios::in|ios::out);							//opening student file
    	fp1.open("book.dat",ios::in|ios::out);							//opening book file
    	while(fp.read((char*)&st,sizeof(student)) && found==0)			//Reading student file till end
       	{
		if(strcmpi(st.retadmno(),st_no)==0)								//If the student number inputed by user matches 
		{
			found=1;													//If student exists
			if(st.rettoken()==0)										//To check if the student has already issued any book
			{
		      		cout<<"\n\n\tEnter the book no. ";
				cin>>bk_no;
				while(fp1.read((char*)&bk,sizeof(book))&& flag==0)		//Reading book file till end
				{
			   		if(strcmpi(bk.retbook_no(),bk_no)==0)				//Checking if the book no. inputed exists or not
					{
						bk.show_book();									//if yes, call show book function
						flag=1;											
						st.addtoken();									//Add token to set that the student has issued a book.
						st.getstbook_no(bk.retbook_no());
       						int pos=-1*sizeof(st);		
						fp.seekp(pos,ios::cur);							//Taking the pointer to the current position
						fp.write((char*)&st,sizeof(student));			//Editing the details of the student as the book is issued
						cout<<"\n\n\t Book issued successfully\n\nNote: Submit within 15 days fine Rs. 1 for each day after 15 days period";
					}
		    		}
		  		if(flag==0)
		    			cout<<"Book no does not exist";
			}
	    		else
		  		cout<<"You have not returned the last book ";

		}
	}
      	if(found==0)
		cout<<"Student record not exist...";
	getch();
  	fp.close();
  	fp1.close();
}

//Function to deposit book.

void book_deposit()
{
    char st_no[6],bk_no[6];
    int found=0,flag=0,day,fine;
    system("cls");
    cout<<"\n\nBOOK DEPOSIT ...";
    cout<<"\n\n\tEnter The students admission no.";
    cin>>st_no;															//Getting student admission number
    fp.open("student.dat",ios::in|ios::out);							//Opening student file
    fp1.open("book.dat",ios::in|ios::out);								//Opening book file
    while(fp.read((char*)&st,sizeof(student)) && found==0)
       {
	    if(strcmpi(st.retadmno(),st_no)==0)									//If the student number inputed by user matches 
	    {
		    found=1;														//To check if student exists
		    if(st.rettoken()==1)											//To check if the student has already issued any book
		    {
			while(fp1.read((char*)&bk,sizeof(book))&& flag==0)				//Traversal of book file
			{
			   if(strcmpi(bk.retbook_no(),st.retstbook_no())==0)			//If the book no. of book object is equal to the book no. saved in student obejct
			{
				bk.show_book();												//if true call show book function
				flag=1;
				cout<<"\n\nBook deposited in no. of days";
				cin>>day;
				if(day>15)													//To count the fine on the student
				{
				   fine=(day-15)*1;
				   cout<<"\n\nFine has to deposited Rs. "<<fine;
				}
					st.resettoken();										//Since the book is returned the token is set to 0
					int pos=-1*sizeof(st);
					fp.seekp(pos,ios::cur);									//Taking the file pointer to the current position
					fp.write((char*)&st,sizeof(student));					//Editing the details of the student as the book is returned
					cout<<"\n\n\t Book deposited successfully";
			}
		    }
		  if(flag==0)
		    cout<<"Book no does not exist";
		      }
		 else
			cout<<"No book is issued..please check!!";
		}
	   }
      if(found==0)															
	cout<<"Student record not exist...";
	getch();
  fp.close();
  fp1.close();
  }


//MAIN MENU FUNCTION

void main_menu()
{
	system("cls");
	int ch2;
	cout<<"\n\n\n\tMAIN MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY SPECIFIC STUDENT RECORD ";
	cout<<"\n\n\t3.CREATE BOOK ";
	cout<<"\n\n\t4.DISPLAY SPECIFIC BOOK ";
	cout<<"\n\n\t5.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-5) ";
	cin>>ch2;																		//getting user's choice
	switch(ch2)
	{
    	case 1: system("cls");
	    		write_student();												//Case to create new student
    			break;	
		case 2:
	       		char num[6];													//case to display student details
	       		system("cls");
	       		cout<<"\n\n\tPlease Enter The Admission No. ";
	       		cin>>num;
	       		display_student(num);
	       		break;
		case 3: system("cls");													//case to create new book
				write_book();break;
		case 4: 
			{
	       		char num[6];													//case to display book details
	       		system("cls");
	       		cout<<"\n\n\tPlease Enter The book No. ";
	       		cin>>num;
	       		display_book(num);
	       		break;
	       }
     	case 5: return;															//Return to the main menu
      		
		default:cout<<"WRONG INPUT";
   	}
   	main_menu();																//Using recursion to call the main_menu() again.
}


//MAIN FUNCTION

int main()
{
	char ch;
	do
	{
		system("cls");
		cout<<"\n\n\n\tWELCOME TO LIBRARY MANAGMENT";
		cout<<"\n\n\t01. BOOK ISSUE";
		cout<<"\n\n\t02. BOOK DEPOSIT";
	  	cout<<"\n\n\t03. ADMINISTRATOR MENU";
	  	cout<<"\n\n\t04. EXIT";
	  	cout<<"\n\n\tPlease Select Your Option (1-4) ";
	  	ch=getche();															//Getting user's input
	  	switch(ch)
	  	{
			case '1':system("cls");												//case for issuing book
				 book_issue();
			   	 break;
		  	case '2':book_deposit();											//case for returning book
			    	 break;
		  	case '3':main_menu();
				 break;
		  	case '4':exit(0);
		  	default :cout<<"\a";
		}
    	}while(ch!='4');


