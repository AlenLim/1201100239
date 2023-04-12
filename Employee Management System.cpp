#include<iostream>
#include <fstream> //read and write file
#include<vector>

using namespace std;


void login_page();
class admin
{
	private : //use in class only
		string admin_id , admin_pd;
		string emp_name, emp_email, emp_pd , emp_id , emp_hp , emp_address;

		int emp_exp;
		float emp_payroll;
	    int admin_option;

	public :
		admin()
		{
			system("CLS");
			cout << "-------------------------------------------------" << endl;
			cout << "         Welcome To Admin Registration Page      " << endl;
			cout << "-------------------------------------------------" << endl;

		}
		void admin_setdata(string id,string pd)
		{
			admin_id = id;
			admin_pd = pd;
		}
		string get_admin_id()
		{
			return admin_id;
		}
		string get_admin_pd()
		{
			return admin_pd;
		}

		void AddEmp();
};
//8
class emp : public admin{

	public:
		void EmpRegister(){
			cout << "---------------New Employee Account Registration---------------"       << endl;
			cout << "Please enter new user details below to register a new account. "   << endl;
		}
};

//7
struct empInfo{
    string emp_id;
	string emp_name;
	string emp_hp;
	string emp_email;
	string emp_address;
	string emp_exp;
	string emp_payroll;
};


struct Node{
    empInfo data;
    Node* next;

};

//implement linked list
class LinkedList {
    public:
    Node* head;

  // constructor
    LinkedList() : head(nullptr) {}

  // push_front function
void push_front(empInfo data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

  // pop_front function
void pop_front() {
    if (head) {
      Node* temp = head;
      head = head->next;
      delete temp;
    }
}

    // size function
int size() {
    int count = 0;
    Node* current = head;
        while (current) {
            count++;
            current = current->next;
    }
    return count;
}

  // empty function
bool empty() {
    return head == nullptr;
  }
};

//6
void printEmp(empInfo *); //let the system know got this function
void EditEmp(empInfo *);

void printEmp(empInfo *p)
{
	int size=2;

	for(int i=0;i<size;i++){

		cout << "\nInformation User "            <<(i+1);
		cout << "------------------------------------------------------------------- " << endl;
		cout << " " << endl;

		cout << "\nEmployee ID : "                   <<p[i].emp_id;
		cout << "\nEmployee Name : "                 <<p[i].emp_name;
		cout << "\nEmployee Phone Number : "         <<p[i].emp_hp;
		cout << "\nEmployee Email : "                <<p[i].emp_email;
		cout << "\nEmployee Address : "              <<p[i].emp_address;
		cout << "\nEmployee Experience(Year) : "     <<p[i].emp_exp;

		if(p[i].emp_exp=="1"||p[i].emp_exp=="0")
		{
			p[i].emp_payroll="1500.00";
		}
		else if(p[i].emp_exp=="2"||p[i].emp_exp=="3"||p[i].emp_exp=="4")
		{
			p[i].emp_payroll="2500.00";
		}
		else if(p[i].emp_exp=="5"||p[i].emp_exp=="6"||p[i].emp_exp=="7")
		{
			p[i].emp_payroll="3500.00";
		}
		else
		{
			p[i].emp_payroll="5000.00";
		}

		cout<<"\nEmployee payroll : "               <<p[i].emp_payroll;
		cout<<"\n\n";
	}
}

void EditEmp(empInfo *p)
{

	int choice;
	cout << "Which employee you want to edit his/her information : ";
	cin >> choice;

	if(choice<=2 ){

		cout << endl;
		cout << "--------------Please enter employee's current information--------------" << endl;
		cout << " " << endl;

		fflush(stdin);

		cout<<"\nEmployee ID : ";
		getline(cin,p[choice-1].emp_id);

		cout<<"\nEmployee Name : ";
		getline(cin,p[choice-1].emp_name);

		cout<<"\nEmployee Phone Number : ";
		getline(cin,p[choice-1].emp_hp);

		cout<<"\nEmployee Email : ";
		getline(cin,p[choice-1].emp_email);

		cout<<"\nEmployee Address : ";
		getline(cin,p[choice-1].emp_address);

		cout<<"\nEmployee experience : ";
		cin>>p[choice-1].emp_exp;

		if(p[choice-1].emp_exp=="1"||p[choice-1].emp_exp=="0")
		{
			p[choice-1].emp_payroll="1500.00";
		}
		else if(p[choice-1].emp_exp=="2"||p[choice-1].emp_exp=="3"||p[choice-1].emp_exp=="4")
		{
			p[choice-1].emp_payroll="2500.00";
		}
		else if(p[choice-1].emp_exp=="5"||p[choice-1].emp_exp=="6"||p[choice-1].emp_exp=="7")
		{
			p[choice-1].emp_payroll="3500.00";
		}
		else
		{
			p[choice-1].emp_payroll="5000.00";
		}
	}
	else
	{
		cout << " " << endl;
		cout << "Invalid user ID." << endl;
		exit(0);
	}
}

//5
void admin::AddEmp(){ //class call void so :: // string now can add space


			cout << "\nEmployee ID : ";
			cin >> emp_id;

			fflush(stdin);
			cout << "Employee Password : ";
			cin >> emp_pd;

			fflush(stdin);
			cout << "Employee Name : ";
			std::getline(std::cin >> std::ws,emp_name);

			fflush(stdin);
			cout << "Employee Phone Number : ";
			cin >> emp_hp;


			cout << "Employee Email : ";
			cin >> emp_email;


			cout << "Employee Address : ";
			std::getline(std::cin >> std::ws,emp_address);


			cout << "Employee Experience : ";
			cin >> emp_exp;

		if(emp_exp<=1)
		{
			emp_payroll=1500.00;
		}
		else if(emp_exp<=4&&emp_exp>=2)
		{
			emp_payroll=2500.00;
		}
		else if(emp_exp<=7&&emp_exp>=5)
		{
			emp_payroll=3500.00;
		}
		else
		{
			emp_payroll=5000.00;
		}
			fstream new_emp;

			new_emp.open("Employee.txt",ios::app); //allows us to add data to the end of file

			new_emp << "\n" << emp_id << "     " << emp_name << "     " << emp_hp << "     " << emp_email << "		" << emp_address << "		" << emp_exp << "	RM " << emp_payroll;

			new_emp.close();
}

//5
void DeleteEmp()
{
        system("CLS");
        vector<string> file;
        string temp;
        int y=0;

        ifstream infile("Employee.txt"); //read file

        while( !infile.eof() )
        {
            getline(infile, temp); //read
            file.push_back(temp); //push back to the temp variable
        }

        infile.close(); //close file

        string id;
        fflush(stdin);

        cout << " Enter employee ID to delete from the list : ";
        getline(cin, id);

        for(int i = 0; i < (int)file.size(); ++i)
        {
            if(file[i].substr(0, id.length()) == id)
            {

                file.erase(file.begin() + i);
                cout << " Employee deleted. " << endl;
                i = 0; // Reset search
                y+=1 ;

            }
        } //for loop to read the length of the id if the id input != to the length it will loop until find it

        if(y==0)
        {
            cout << " Invalid employee ID. " << endl;
            system("PAUSE");
        }
			//write new order list back out
        ofstream out("Employee.txt", ios::out | ios::trunc);

        //vector
        for (vector<string>::const_iterator i = file.begin(); i != file.end(); ++i)
        {
            out << *i << endl;
        }

        out.close();
	}

//4
void AllEmpInfo()
{
			string line;
    		ifstream myfile ("Employee.txt");
    		cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;
    		cout << "  ID         Name       Phone Number      Email		         Address		       Experience	       Payroll  " << endl;
    		cout << "-------------------------------------------------------------------------------------------------------------------------------" << endl;

			if (myfile.is_open())
  				{
    				while ( getline (myfile,line) )
    			{
      				cout << line <<"\n";
    			}
    				myfile.close();
  				}
  				else cout << "Unable to open file";
}

//4
void SearchEmp()
{
	string id,line;

		cout << "Enter employee ID to Search : ";
		cin >> id;

    		cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    		cout << "  ID      Name       Phone Number   Email		         Address			     Experience	  Payroll" << endl;
    		cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;



		ifstream myStream("Employee.txt");
		while(getline(myStream,line))
		{
    	if (line.find(id) != string::npos) //string::npos is means until the end of the string
                                            //It is a constant static member value with the highest possible value for an element of type size_t.
        cout <<" "<<line<<endl;
		}
}

//3
void AdminMenu()
{
			cout << "----------------------------------------------------" << endl;
			cout << "              Welcome To Admin Main Menu            " << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "Please Select One To Proceed:" << endl;
			cout << " "                             << endl;
			cout << "1.View All Employee"           << endl;
			cout << "2.Add Employee"                << endl;
			cout << "3.Delete Employee"             << endl;
			cout << "4.Search Employee"             << endl;
			cout << "5.Edit Employee"               << endl;
			cout << "6.Log Out"                     << endl;
}

//2
void AdminOption(string id,string pd) //editted
{
	admin an;
	string admin_id,admin_pd;
	int admin_op;
	char  choice;

	do
	{

    system("cls");
	cout << "--------------Admin Login-------------- " <<endl;
	cout << "Enter your Admin ID :";
	cin >> admin_id;

	if(admin_id!=id)
	{
		cout << "Invalid Admin ID. " << endl;
		system("PAUSE");
	}
	else
	{
	cout << "Enter Your Password: ";
	cin >> admin_pd;
	if(admin_pd!=pd)
        {
		cout<<"Invalid password. " << endl;
		system("PAUSE");
        }
	}

	}
	while(admin_id!=id||admin_pd!=pd);

	system ("PAUSE");
	system("CLS");

	do
	{

	AdminMenu();
	fflush(stdin);
	cout << "\nEnter Your Choice :";
	cin >> admin_op;

	switch(admin_op)
	{

		case 1:AllEmpInfo();
		break;

		case 2:cout << "Please enter new employee details : " << endl;
				an.AddEmp();
				cout << "\n\nNew employee has been added SUCCESSFULLY" << endl;
		break;

		case 3:DeleteEmp();
		break;

		case 4:SearchEmp();
		break;

		case 5:{
		    //linked list
            LinkedList list;

  // create some empInfo objects
            empInfo e1;
            e1.emp_id = "120001";
            e1.emp_name = "test1";
            e1.emp_hp = "0123456789";
            e1.emp_email = "test1@gmail.com";
            e1.emp_address = "no1,jalan besar,taman kecil";
            e1.emp_exp = "1";
            e1.emp_payroll = "1500";

            empInfo e2;
            e2.emp_id = "120002";
            e2.emp_name = "test2";
            e2.emp_hp = "0123456789";
            e2.emp_email = "test2@gmail.com";
            e2.emp_address = "no1,jalan besar,taman kecil";
            e2.emp_exp = "4";
            e2.emp_payroll = "2500";

  // add the empInfo objects to the list
            list.push_front(e1);
            list.push_front(e2);

            empInfo infos[] = {e1, e2};
            printEmp(infos);
            EditEmp(infos);
            printEmp(infos);


            system("pause");
			}
		break;

		case 6:
                system("cls");
                return;
                break;
        }

        cout << "\nDo you want to continue? [Y/N]: " ;
        cin >> choice;

        system("CLS"); // Clear screen
    }
    while(choice=='Y'||choice=='y');
}

//1
void admin_register()
{
	admin an;
	string admin_id , admin_pd;
	char  choice;


	cout    <<  "Enter your ID :";
	cin     >>  admin_id;

	cout    <<"Enter Your Password:";
	cin     >>admin_pd;
	an.admin_setdata(admin_id,admin_pd);

	system ("PAUSE");
	system("CLS");

	cout    <<"Do you want to continue? [Y/N]:";
	cin     >>choice;
	if(choice=='Y'||choice=='y')
	{

		AdminOption(admin_id,admin_pd);
		system("cls");
	}
	else
	{
		cout<<"Thank you!!";
		exit(0);
	}


}

void login_page()
{
	string emp_id, emp_pd, line;
	int i=0;


	do
	{
		system("cls");
		cout    << "---------Login using your registered account---------" << endl;
	    cout    << "\nEnter Employee ID: ";
	    cin     >> emp_id;
	    cout    << "Enter Employee Password : ";
	    cin     >> emp_pd;
	    cout    <<  endl;

		ifstream myStream("Employee.txt");
		while(getline(myStream,line))
		{
    	if (line.find(emp_id) != string::npos)
            i=1;
		}
		if(i!=1)
		{
			cout << "Invalid Input. "<<endl;
			system("PAUSE");
		}
		myStream.close();
		system("cls");
	}

	while(i==0);
    	char choice;
    	cout<<"Do you want to continue? [Y/N] :";
		cin>>choice;

		if(choice=='Y' || choice=='y')
		{

		string id,lines;

		system("cls");
		cout<<"This is your Info details"<<endl;
		id=emp_id;

    		cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    		cout << "  ID      Name       Phone Number   Email		         Address			     Experience	   Payroll" << endl;
    		cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

		ifstream myStream("Employee.txt");

		while(getline(myStream,lines))
		{
    	if (lines.find(id) != string::npos)
        cout <<" "<<lines<<endl;
		}

		}

		cout << "Enter to go back main page. " << endl;
		system("PAUSE");
		cin.ignore();
		cin.get();
		system("cls");

		return;

}

void show_main_menu() //newly added
{
    while (true) // Loop indefinitely
    {
        int cA;
        char op;
        cout << "-----------------Welcome-----------------" << endl << endl;
        cout << "1. Admin" << endl;
        cout << "2. Employee" << endl;
        cout << "3. Exit" << endl;
        cout << "Please enter your choice : ";

        cin >> cA;

        switch(cA)
        {
            case 1 :	admin_register();
                system("cls");
                break;
            case 2 :
                cout<<"Already have an account? [Y/N]: ";
                cin>>op;
                if(op == 'Y'||op == 'y')
                {
                    login_page();
                }
                else
                {
                    emp un;
                    system("cls");
                    un.EmpRegister();
                    un.AddEmp();
                    cout << "Account Registered SUCCESSFULLY." << endl;
                    system("PAUSE");
                    system("cls");
                    login_page();
                }
                break;
            case 3 :
                system("PAUSE");
                cout << "Thank you!!" ;
                exit(0);
                break;

            default:
                cout<<"Invalid option. Please enter a valid option. Press enter to choose again...";
                cin.ignore();
                cin.get();
                system("cls");
        }
    }
}

int main() //editted
{
    show_main_menu();
    login_page();
    return 0;
}

