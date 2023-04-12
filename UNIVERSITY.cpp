#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <iomanip>
#include <string.h>
#include <sstream>
using namespace std;


int subject;
string sub_name;

class admin{

    public:
        addStudent();
		searchStudent();
		removeProduct();
		admin_run();
		addAward();

};



void viewStudent(){

	system("CLS");
    // OPEN STUDENT.TXT FILE
	fstream studFile;
	studFile.open("student.txt" , ios :: in);

	if (studFile.is_open()) {
		string line;
    cout << "-----------------------------------------------------------"<< endl;
	cout << "|                        STUDENT                          |" << endl;
    cout << "-----------------------------------------------------------"<< endl << endl;

    cout << "^^^^" << "                      " << "^^^^^^" << "                            "<<"^^^^^^"<<endl;
	cout << "|ID|" << "                      " << "|Name|" << "                            "<<"|Date|"<<endl;
	cout << "^^^^" << "                      " << "^^^^^^" << "                            "<<"^^^^^^"<<endl;

		while (getline(studFile,line)) {
			cout << line << endl;
		}
		studFile.close();
	}
}

// 7. MODIFY STUDENT DETAILS
void editStudent (){

ifstream oldf; //read(filled)
    ofstream newf; //write(empty)

    // create datatype for data in file
    string Studentname , EnrollmentDate;
    int StudentId;

    // for selections
    int ans;
    char c;
    int i = 1; //just for mentioning line numbers
    string line;

    // open file
    oldf.open("student.txt");
    newf.open("updated.txt");

    while (oldf >> StudentId >> Studentname >> EnrollmentDate )
    {
        system("CLS");
        cout << "[" << i << "] "<< StudentId << ' ' << Studentname << ' ' << EnrollmentDate << ' ' << std::endl;

        cout << "What do you want to change for this student? (1/2/3/4)"<<endl;
        cout << "1.Id"<<" 2.Name"<<" 3.Enrollment date"<<" 4.ALL"<<endl;
        cout << "Otherwise :Press any other number for keeping the original data"<<endl;
        cin >> ans;

        if(ans==1){
        cout << "Change id for this person : "<<endl;
        cout <<"Previous ID: "<<StudentId<<","<<endl;
        cout <<"New ID is ";
        cin >> StudentId;
        }
        else if(ans==2){
        cout <<"Change the name of the student : "<<endl;
        cout <<"Previous name: "<<Studentname<<","<<endl;
        cout <<"Modified name is ";
        cin >> Studentname;
        }
        else if(ans==3){
        cout << "Change the enrollment date of this student : "<<endl;
        cout <<"Previous Date is "<<EnrollmentDate<<","<<endl;
        cout <<"Modified date is ";
        cin >> EnrollmentDate;
        }
        else if(ans==4){
        cout <<"Change id for this person : "<<endl;
        cout <<"Previous ID"<<StudentId<<","<<endl;
        cout <<"New ID is ";
        cin >> StudentId;
        cout <<"Change the name of the student : "<<endl;
        cout <<"Previous name: "<<Studentname<<","<<endl;
        cout <<"Modified name is ";
        cin >> Studentname;
        cout <<"Change the enrollment date of this student : "<<endl;
        cout <<"Previous Date: "<<EnrollmentDate<<","<<endl;
        cout <<"Modified date is ";
        cin >> EnrollmentDate;
        }
        else{

        }

        cout << endl;

        newf << StudentId   <<"                "<< Studentname           <<"           	            "<< EnrollmentDate       << std::endl;

        i++;
    }

    oldf.close();
    newf.close();

    cout << "Do you want to save the updated data ? (y/n)"<<endl;
    cin >> c;

    if(c=='y'){
        ifstream newf;
        ofstream oldf;

        oldf.open("student.txt");
        newf.open("updated.txt");


        while (newf >> StudentId >> Studentname >> EnrollmentDate){
            oldf << StudentId   << "          " << Studentname                  << "           	     " << EnrollmentDate                << std::endl;
        }

        cout << "All updates are saved."<<endl; // all updated to origin

        oldf.close();
        newf.close();
    }

    else{
        cout << "All updates are SAVED."<<endl;
    }
}

void viewLecturer2(){

	system("CLS");
    // OPEN LECTURE.TXT FILE
	fstream lecFile;
	lecFile.open("lec.txt" , ios :: in);

	if (lecFile.is_open()) {
		string line;
    cout << "-----------------------------------------------------------"<< endl;
	cout << "|                        LECTURER                         |" << endl;
    cout << "-----------------------------------------------------------"<< endl << endl;

    cout << "^^^^^^^^^" << "                              " << "^^^^^^^^" << endl;
	cout << " |Email| " << "                              " <<"  |Name| " << endl;
	cout << "^^^^^^^^^" << "                              " << "^^^^^^^^" << endl;
		while (getline(lecFile,line)) {
			cout << line << endl;
		}
		lecFile.close();
	}
}

void viewupdated(){

    system("CLS");
    //OPEN UPDATE.TXT FILE
	fstream UpdateFile;
	UpdateFile.open("updated.txt" , ios :: in);

	if (UpdateFile.is_open()) {
		string line;
    cout << "-----------------------------------------------------------"<< endl;
	cout << "|                        STUDENT                          |" << endl;
    cout << "-----------------------------------------------------------"<< endl << endl;

    cout << "^^^^" << "                      " <<"^^^^^^" << "                            "<<"^^^^^^"<<endl;
	cout << "|ID|" << "                      " <<"|Name|" << "                            "<<"|Date|"<<endl;
	cout << "^^^^" << "                      " <<"^^^^^^" << "                            "<<"^^^^^^"<<endl;

		while (getline(UpdateFile,line)) {
			cout << line << endl;
		}
		UpdateFile.close();
	}
}

void viewAward(){

    system("CLS");
    // OPEN AWARD.TXT FILE
	fstream AwardFile;
	AwardFile.open("Award.txt" , ios :: in);

	if (AwardFile.is_open()) {
		string line;
    cout << "-----------------------------------------------------------"<< endl;
	cout << "|                        AWARD                            |" << endl;
    cout << "-----------------------------------------------------------"<< endl << endl;

    cout << "^^^^" <<  "                      " <<"^^^^^^" << "                            "<<"^^^^^^^"<<"                            "<<"^^^^^^^"<<endl;
	cout << "|ID|" <<  "                      " <<"|Name|" << "                            "<<"|Batch|"<<"                            "<<"|Award|"<<endl;
	cout << "^^^^" <<  "                      " <<"^^^^^^" << "                            "<<"^^^^^^^"<<"                            "<<"^^^^^^^"<<endl;
		while (getline(AwardFile,line)) {
			cout << line << endl;
		}
		AwardFile.close();
	}
}


// 3. SEARCH STUDENT
int admin :: searchStudent() {

	string search;
    ifstream myFile;
    string line;

    myFile.open("student.txt");
    cout << "Enter any student info to search: ";
    cin >> search;  //GET ANY INFORMATION INSERTED INTO TXT FILE

    size_t stud;
    while(myFile.good()){
        getline(myFile, line);
        stud = line.find(search);
        if(stud != string::npos){
            cout << line << endl;
            break;
        }

    }
    cout << endl;
}


// 1. ADD STUDENT
int admin :: addStudent() {

	string Studentname, EnrollmentDate;
    int StudentId;
    char choice;

    do{
       system("CLS");
	    fstream myFile;
	    myFile.open("student.txt", ios::app);

	    if(myFile.is_open()){
	        cout << "Enter Student ID: ";
	        cin >> StudentId;

	        cin.ignore();

	        cout << "Enter Student name: ";
	        getline(cin, Studentname);

	        cout << "Enter Student Enrollment Date :" ;
	        cin >> EnrollmentDate;


            myFile << StudentId << "                        " << Studentname                       << "           	                   " << EnrollmentDate << "\n";

			myFile.close();
    	}

	    cout << "\n" << Studentname << " has been added into the student list. " << endl;
        cout << "******************************************************************"<< endl;

	    cout << "\nDo you want to add another student? (Y/N): ";
	    cin >> choice;

	    choice = tolower(choice);

	    cout << endl;

	}while(choice == 'y');


	return 0;
}

// 5. ADD AWARD
int admin :: addAward() {

	string Studentnameaward, Award;
    int StudentIdname, Batch;
    char choice;

    do{
	    system("CLS");
	    fstream myFile;
	    myFile.open("Award.txt", ios::app);

	    if(myFile.is_open()){
	        cout << "Enter Student ID: ";
	        cin >> StudentIdname;

	        cin.ignore();

	        cout << "Enter Student name: ";
	        getline(cin, Studentnameaward);

	        cout << "Enter Award: ";
	        getline(cin, Award);

	        cout << "Enter Student Batch " ;
	        cin >> Batch;




            myFile << StudentIdname         << "                " << Studentnameaward       << "           	              " << Batch        << "                             " << Award        <<"\n";

			myFile.close();


    	}

	    cout << "\n" << Studentnameaward << " award has been added into the award list. " << endl;
        cout << "*************************************************************************"<< endl;

	    cout << "\nDo you want to add another student? (Y/N): ";
	    cin >> choice;

	    choice = tolower(choice);

	    cout << endl;

	}while(choice == 'y');


	return 0;
}



int admin :: admin_run() {

	admin MENU;

	int option;
    char choice;

    do{
        system("CLS");
        cout << "\t\t**************************************"<< endl;
        cout << "\t\t\t| ADMINISTRATOR MENU |\t"<< endl;
        cout << "\t\t**************************************"<< endl;

	    cout << "What would you like to do.." << endl;
	    cout << "1) Add Student" << endl;
	    cout << "2) Initial updated Info" << endl;
	    cout << "3) Search Student" << endl;
	    cout << "4) View Lecturer Info" << endl;
	    cout << "5) Add Award" << endl;
	    cout << "6) View Award" << endl;
	    cout << "7) Modify Student Details" << endl;
	    cout << "8) Updated Student Details" << endl;
        cout << "***********************************************************"<< endl;
	    cout << "Enter choice: ";
	    cin >> option;

	    cout << endl;

	    if(option == 1){
	        addStudent(); // ADD BOOK
	    }
	    else if(option == 2){
	        viewStudent();// VIEW STUDENT INFO
	    }
	    else if(option == 3){
	        searchStudent();// SEARCH STUDENT
	    }
	    else if(option == 4) {
	    	viewLecturer2();// VIEW LECTURER INFO
		}
		else if(option == 5){
            addAward();// ADD AWARD
		}
        else if(option == 6){
            viewAward();// VIEW AWARD
		}
		else if(option == 7){
            editStudent();// EDIT STUDENT INFO
		}
		else if(option == 8){
            viewupdated();// VIEW UPDATED INFO
		}
	    else{
	        cout << "Invalid Input!" << endl;
	    }

	    cout << "Would you like to continue to view the ADMIN MENU? (Y/N):";
	    cin >> choice;

		cout << endl;

	    choice = tolower(choice);

    }while(choice == 'y');

    return 0;
}

class lecturer{

    public:
        addLecturer();
        lecturer_run();
        addAttendance();

};


void viewLecturer(){

	system("CLS");

	fstream lecFile;
	lecFile.open("lec.txt" , ios :: in);

	if (lecFile.is_open()) {
		string line;
    cout << "-----------------------------------------------------------"<< endl;
	cout << "|                        LECTURER                         |" << endl;
    cout << "-----------------------------------------------------------"<< endl << endl;

    cout << "^^^^^^^^^" << "                              " << "^^^^^^^^" << endl;
	cout << " |Email| " << "                              " <<"  |Name| " << endl;
	cout << "^^^^^^^^^" << "                              " << "^^^^^^^^" << endl;
		while (getline(lecFile,line)) {
			cout << line << endl;
		}
		lecFile.close();
	}
}


// 3. ATTENDANCE ADDING FUNCTION
int lecturer :: addAttendance()
{
	int Studentidattendance;
	char barring;
	int attendancenum;
    char choice;

    do{
        system("CLS");
	    fstream myFile;
	    myFile.open("attendancerecord.txt", ios::app); //OPEN NEW TXT FILE

	    if(myFile.is_open()){
	        cout << "Enter Student ID: ";
	        cin >> Studentidattendance;

	        cin.ignore();

            cout << "Present or not ( press 1 for present / press 0 for not  : ";
	        cin >> attendancenum ;
	        // GET ATTENDANCE FOR THE DAY

            cout << "Barred or not Barred ( press B for barred / press N for not barred : ";
	        cin >> barring ;
	        // GET BARRING STATUS

            barring = tolower(barring);
            if((attendancenum == 0 || attendancenum == 1) && (barring == 'b' || barring == 'n')){

            myFile << Studentidattendance       << "                    "  <<barring << "                                           " << attendancenum<< "\n";

            // STORING ATTENDANCE STATUS
			myFile.close();}
			else { cout << "wrong input" << endl; }
    	}

	    cout << "\n" << Studentidattendance << " Attendance added IF THE NUMBER WAS BETWEEN 0 TO 1 . IF NOT TRY AGAIN" << endl;
        cout << "******************************************************************************************************"<< endl;

	    cout << "\nDo you want to add another attendance? (Y/N): ";
	    cin >> choice;

	    choice = tolower(choice);

	    cout << endl;

	}while(choice == 'y');


	return 0;
}


// 1. ADD LECTURER
int lecturer :: addLecturer() {


	string Lecturername,LecturerEmail;
    char choice;

    do{
        system("CLS");
	    fstream myFile;
	    myFile.open("lec.txt", ios::app); // OPEN A NEW TXT FILE

	    if(myFile.is_open()){
	        cout << "Enter Lecturer Email : ";
	        cin >> LecturerEmail;

	        cin.ignore();

	        cout << "Enter Lecturer Name : ";
	        getline(cin, Lecturername);


            myFile << LecturerEmail                              << "                  " << Lecturername                           << "\n";

			myFile.close();
    	}

	    cout << "\n" << Lecturername << " has been added into the Lecturer list. " << endl;
        cout << "*******************************************************************"<< endl;

	    cout << "\nDo you want to add another lecturer? (Y/N): ";
	    cin >> choice;

	    choice = tolower(choice);

	    cout << endl;

	}while(choice == 'y');


	return 0;
	}

// LECTURER MENU
int lecturer :: lecturer_run() {

	lecturer MENU;

	int option;
    char choice;

    do{
        system("CLS");
        cout << "\t\t********************************"<< endl;
        cout << "\t\t\t| LECTURER MENU |\t"<< endl;
        cout << "\t\t********************************"<< endl;

	    cout << "What would you like to do.." << endl;
	    cout << "1) Add Lecturer" << endl;
	    cout << "2) View Lecturer Info" << endl;
	    cout << "3) Add Barring Status and Attendance" << endl;
        cout << "***********************************************************"<< endl;
	    cout << "Enter choice: ";
	    cin >> option;

	    cout << endl;

	    if(option == 1){
	        addLecturer();// ADD NEW LECTURER
	    }
	    else if(option == 2){
	        viewLecturer();// VIEW LECTURER INFO
	    }
	    else if(option == 3){
	        addAttendance();// ADD STUDENT'S ATTENDANCE
	    }
	    else{
	        cout << "Invalid Input!" << endl;
	    }

	    cout << "Would you like to continue to view the LECTURER MENU? (Y/N):";
	    cin >> choice;

		cout << endl;

	    choice = tolower(choice);

    }while(choice == 'y');

    return 0;
}


class student{

    public:

		float total_price;
        int receipt();
        int addClass();
        student_run();
        int viewSubject();
};

void viewAttendance(){

	system("CLS");

	fstream attendFile;
	attendFile.open("attendancerecord.txt" , ios :: in);

	if (attendFile.is_open()) {
		string line;
cout << "-----------------------------------------------------------"<< endl;
cout << "|                        ATTENDANCE                       |" << endl;
cout << "-----------------------------------------------------------"<< endl << endl;

cout << "^^^^^^" << "                      " <<"^^^^^^^^^^^^^^^^" << "                            "<<"^^^^^^^^^^^^"<<endl;
cout << " |ID| " << "                      " <<"|Barring Status|" << "                            "<<"|Attendance|"<<endl;
cout << "^^^^^^" << "                      " <<"^^^^^^^^^^^^^^^^" << "                            "<<"^^^^^^^^^^^^"<<endl;
		while (getline(attendFile,line)) {
			cout << line << endl;
		}
		attendFile.close();
	}
}


void viewAward2(){

	system("CLS");

	fstream AwardFile;
	AwardFile.open("Award.txt" , ios :: in);

	if (AwardFile.is_open()) {
		string line;
cout << "-----------------------------------------------------------"<< endl;
cout << "|                        AWARD                            |" << endl;
cout << "-----------------------------------------------------------"<< endl << endl;

cout << "^^^^^^" << "                      " <<"^^^^^^" << "                            "<<"^^^^^^^"<<"                            "<<"^^^^^^^"<<endl;
cout << " |ID| " << "                      " <<"|Name|" << "                            "<<"|Award|"<<"                            "<<"|Batch|"<<endl;
cout << "^^^^^^" << "                      " <<"^^^^^^" << "                            "<<"^^^^^^^"<<"                            "<<"^^^^^^^"<<endl;
		while (getline(AwardFile,line)) {
			cout << line << endl;
		}
		AwardFile.close();
	}
}

void viewStudent2(){

	 system("CLS");

	fstream UpdateFile;
	UpdateFile.open("updated.txt" , ios :: in);

	if (UpdateFile.is_open()) {
		string line;
    cout << "-----------------------------------------------------------"<< endl;
	cout << "|                        STUDENT                          |" << endl;
    cout << "-----------------------------------------------------------"<< endl << endl;

    cout << "^^^^^^" << "                      " << "^^^^^^" << "                            "<<"^^^^^^"<<endl;
	cout << " |ID| " << "                      " << "|Name|" << "                            "<<"|Date|"<<endl;
	cout << "^^^^^^" << "                      " << "^^^^^^" << "                            "<<"^^^^^^"<<endl;
		while (getline(UpdateFile,line)) {
			cout << line << endl;
		}
		UpdateFile.close();
	}
}

// 1. ADD CLASS
int student :: addClass() {

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);



	int subject;
	float price=0;
	string sub_name;
	char choice;

    do {
    system("CLS");
    cout << "\t\t*****************************"<< endl;
    cout << "\t\t\t| SUBJECT |\t"<< endl;
    cout << "\t\t*****************************"<< endl;
    cout << "1. Mathematical Techniques"<<endl;
    cout << "2. Computer Programming"<<endl;
    cout << "3. Sejarah Negara"<<endl;
    cout << "4. Physics"<<endl;
    cout << "5. Internet of Things"<<endl;
    cout << "6. Essential of English"<<endl;
    cout << "7. Introduction to Multimedia"<<endl;
    cout << "***********************************************************"<< endl;

	cout << endl;
	cout << "What subject you would like to add?: " ;
	cin >> subject;




	switch(subject) {
		case 1:
			sub_name = "Mathematical Techniques   ";
			price += 1500;
			break;
		case 2:
			sub_name = "Computer Programming      ";
			price += 2000;
			break;
		case 3:
			sub_name = "Sejarah Negara            ";
			price += 1000;
			break;
		case 4:
			sub_name = "Physics                   ";
			price += 1000;
			break;
		case 5:
			sub_name = "Internet of Things        ";
			price += 2500;
			break;
		case 6:
			sub_name = "Essential of English      ";
			price += 1300;
			break;
		case 7:
			sub_name = "Introduction to Multimedia";
			price += 1800;
			break;


    }while(subject<1 || subject>7) {

		cout << "Wrong selection, try again!" << endl;
		cout << "What subject would you like to add?: ";
		cin >> subject;
	}


    fstream student;
	student.open("subject.txt", ios :: app);
	if(student.is_open()){
		student << "" << sub_name << "                "<<  price << endl;
		student.close();
	}

	total_price = total_price + price;

	cout << endl << endl;

        cout << "Would you like to continue adding subject (Y/N):";
	    cin >> choice;

		cout << endl;

	    choice = tolower(choice);

        }while(choice == 'y');


    return 0;
}



int student :: viewSubject() {

	system("CLS");

    cout << "***********************************************************"<< endl;
	cout << "|                        RECEIPT                          |" << endl;
    cout << "***********************************************************"<< endl << endl;


	cout << "                   TOTAL SUBJECT BILLING                   " << endl;
    cout << "***********************************************************"<< endl << endl;

    cout << "   ^^^^^^^^^" << "                            " << "^^^^^^^" << endl;
	cout << "   |Subject|" <<  "                            " <<"|Price|" << endl;
	cout << "   ^^^^^^^^^" << "                            " << "^^^^^^^" << endl;

	fstream receipt;
	receipt.open("subject.txt" , ios :: in);
	if (receipt.is_open()) {
		string line;

		while (getline(receipt, line)) {
			cout << line << endl;
		}
		receipt.close();
	}

	cout << endl << endl;

	cout << "Total Price: RM" << total_price << endl << endl;
    cout << "***********************************************************"<< endl << endl;

	return 0;
}

// STUDENT MENU
int student :: student_run() {

	student MENU;

	int option;
    char choice;

    do{
        system("CLS");
        cout << "\t\t********************************"<< endl;
        cout << "\t\t\t| STUDENT MENU |\t"<< endl;
        cout << "\t\t********************************"<< endl;

	    cout << "What would you like to do.." << endl;
	    cout << "1) Add Class" << endl;
	    cout << "2) View Student Info" << endl;
	    cout << "3) View Attendance" << endl;
	    cout << "4) View Subject" << endl;
	    cout << "5) View Award" << endl;
        cout << "***********************************************************"<< endl;
	    cout << "Enter choice: ";
	    cin >> option;

	    cout << endl;

	    if(option == 1){
	        addClass(); // ADD SUBJECTS
	    }
	    else if(option == 2){
	        viewStudent2();// VIEW STUDENT INFO
	    }
	    else if(option == 3){
	        viewAttendance();// VIEW STUDENT ATTENDANCE
	    }
	    else if(option == 4) {
	    	viewSubject();// VIEW SUBJECT BILLING
		}
        else if(option == 5) {
	    	viewAward2();// VIEW AWARD OF STUDENTS
		}

	    else{
	        cout << "Invalid Input!" << endl;
	    }

	    cout << "Would you like to continue to view the STUDENT MENU? (Y/N):"<<endl;
	    cin >> choice;

		cout << endl;

	    choice = tolower(choice);

    }while(choice == 'y');

    return 0;
}

// MAIN MENU
int run() {

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	int choice;

    cout << "\t\t***********************************************************"<< endl;
    cout << "\t\t\t| WELCOME TO UNIVERSITY MANAGEMENT SYSTEM |\t"<< endl;
    cout << "\t\t***********************************************************"<< endl;
	cout << "\t\t1. Admin" << endl;
	cout << "\t\t2. Lecturer" << endl;
	cout << "\t\t3. Student" << endl;
	cout << "\t\tChoose one to continue: "<<endl;
	cout << "\t\t***********************************************************"<< endl;
	cin >> choice;


	system("CLS");

// LOGIN MENU FUNCTIONS
	if(choice==1) {             // ADMIN MENU
        const string passwd = "A@DMIN";
		string userpass;


        cout << "Enter password to view ADMIN MENU: ";
        cin >> userpass;

        if(userpass == passwd){
        	admin MENU;
        	MENU.admin_run();
        	return 0;
		}

		else if(userpass != passwd){
            cout << "Invalid password!" << endl;
            for(int i=0; i<2; i++){
                cout << "Re-enter password: ";
                cin >> userpass;
                if(userpass == passwd){
                    admin MENU;
                    MENU.admin_run();
                return 0;
                }
            }
		}
	}
	else if (choice==2){            // LECTURER MENU
				const string passwd = "L@ECTURE";
		string userpass;

        cout << "Enter password to view LECTURER MENU: ";
        cin >> userpass;

        if(userpass == passwd){
        	lecturer MENU;
        	MENU.lecturer_run();
        	return 0;
		}

		else if(userpass != passwd){
            cout << "Invalid password!" << endl;
            for(int i=0; i<2; i++){
                cout << "Re-enter password: ";
                cin >> userpass;
                if(userpass == passwd){
                    lecturer MENU;
                    MENU.lecturer_run();
                return 0;
                }
            }
		}
	}
	else if (choice==3){            //STUDENT MENU
				const string passwd = "S@TUDENT";
		string userpass;

        cout << "Enter password to view STUDENT MENU: ";
        cin >> userpass;

        if(userpass == passwd){
        	student MENU;
        	MENU.student_run();
        	return 0;
		}

		else if(userpass != passwd){
            cout << "Invalid password!" << endl;
            for(int i=0; i<2; i++){
                cout << "Re-enter password: ";
                cin >> userpass;
                if(userpass == passwd){
                    student MENU;
                    MENU.student_run();
                return 0;
                }
            }
		}
	}
	else
		exit(0);



	return 0;
}



int main() {

	char ans;

	do {

		system("CLS");

		run();

		cout << "Do you want to go back to main menu?: ";
		cin >> ans;

		ans = tolower(ans);
	}while(ans=='y');
}
