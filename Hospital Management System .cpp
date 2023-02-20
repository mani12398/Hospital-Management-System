#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct info
{
	string name, specialist, disease, discription, gender, address, feild;
	int special_room_no = {};
	int	age = {};
	int	fee = {};
	int	date = {};
};

struct node
{
	info data;
	node* next = {};

};

struct appoint
{
	string name, disease, gender, address, appointment_date;
	int special_room_no = {};
	int age = {};
	int fee = {};
	int date = {};
	int	number_of_times_visited = {};
};

struct node_1 
{
	appoint data;
	int priority = 10;
	node_1* next = NULL;
};

node_1* front = NULL;

bool is_Empty()
{
	if (front == NULL)
	{
		return true;
	}

	else
	{
		return false;

	}

}

void enqueue(int priority)
{
	system("cls");
	node_1* temp = new node_1;

	cout << "Enter Data " << endl;
	cout << "Enter Name of Patient: " << endl;
	cin >> temp->data.name;
	cout << "Enter Age of Patient: " << endl;
	cin >> temp->data.age;
	cout << "Enter Address of Patient: " << endl;
	cin >> temp->data.address;
	cout << "Enter Gender of Patient: " << endl;
	cin >> temp->data.gender;
	cout << "Enter Fees of Patient: " << endl;
	cin >> temp->data.fee;
	cout << "Enter Number of Times Patient has Visited to the Hospital: " << endl;
	cin >> temp->data.number_of_times_visited;

	temp->priority = priority;
	node_1* start = front;

	if (front == NULL)
	{
		front = temp;
	}

	else if (front->priority > temp->priority)
	{
		temp->next = front;
		front = temp;
	}

	else
	{
		while (start->next != NULL && start->next->priority < temp->priority)
		{
			start = start->next;
		}

		temp->next = start->next;
		start->next = temp;
	}

}

void dequeue()
{
	node_1* temp = front;
	if (is_Empty())
	{
		cout << "Underflow " << endl;
		return;
	}

	else
	{
		if (front->next != NULL)
		{
			cout << "Element Deleted From Queue: " << endl;
			front = front->next;
			delete temp;
			temp = NULL;
		}

		else
		{
			cout << "Element Deleted From Queue: " << endl;
			delete front;
			front = NULL;
		}
	}

}

void display_front() 
{
	if (is_Empty())
	{
		cout << "Queue is Empty " << endl;

	}
		
	else
	{
		system("cls");
		
		cout << "Details of Patient In Appointments: " << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "Name of Patient: " << front->data.name << endl;
		cout << "Age of Patient: " << front->data.age << endl;
		cout << "Gender of Patient: " << front->data.gender << endl;
		cout << "Fees for Appointment: " << front->data.fee << endl;
		cout << "Address of Patient: " << front->data.address << endl;
		cout << "No of Times Patient has come to the Hospital: " << front->data.number_of_times_visited << endl;
		cout << "---------------------------------------------------------" << endl;

	}
}

void display_queue() 
{
	node_1* temp = front;

	if (is_Empty())
	{
		cout << "Queue is Empty " << endl;
		return;
	}

	while (temp != NULL)
	{
		cout << "All Appointments List: " << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "Name of Patient: " << temp->data.name << endl;
		cout << "Age of Patient: " << temp->data.age << endl;
		cout << "Gender of Patient: " << temp->data.gender << endl;
		cout << "Fees for Appointment: " << temp->data.fee << endl;
		cout << "Address of Patient: " << temp->data.address << endl;
		cout << "No of Times Patient has come to the Hospital: " << temp->data.number_of_times_visited << endl;
		cout << "---------------------------------------------------------" << endl;

		
		temp = temp->next;
	}
	cout << endl;
}

void search_appointment(string name)
{
	node_1* temp = front;

	while (1)
	{
		if (front == NULL)
		{
			cout << "There are No Appointments " << endl;
		}

		else if (temp->data.name != name && temp->next != NULL)
		{
			temp = temp->next;

		}

		if (temp->data.name == name)
		{

			cout << "--------------------------------------------------------" << endl;
			cout << "Name of Patient: " << temp->data.name << endl;
			cout << "Age of Patient: " << temp->data.age << endl;
			cout << "Gender of Patient: " << temp->data.gender << endl;
			cout << "Fees for Appointment: " << temp->data.fee << endl;
			cout << "Address of Patient: " << temp->data.address << endl;
			cout << "No of Times Patient has come to the Hospital: " << temp->data.number_of_times_visited << endl;
			cout << "---------------------------------------------------------" << endl;

			break;
		}

		break;
	}
}

info input_patient()
{
	system("cls");
	string name, gender, disease, address, discription;
	int  age = {};
	int	special_room_no = {};

	info i;

	cout << "Data Entering in Patient Section " << endl;
	cout << "Enter the Patient Name: " << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter the Patient Gender: " << endl;
	getline(cin, gender);
	cout << "Enter the Patient Disease: " << endl;
	getline(cin, disease);
	cout << "Enter the Patient Discription: " << endl;
	getline(cin, discription);
	cout << "Enter the Patient Address: " << endl;
	getline(cin, address);
	cout << "Enter the Patient Age: " << endl;
	cin >> age;
	cout << "Enter the Patient Special Room No: " << endl;
	cin >> special_room_no;

	i.name = name;
	i.gender = gender;
	i.disease = disease;
	i.address = address;
	i.discription = discription;
	i.age = age;
	i.special_room_no = special_room_no;

	return i;
}

info input_doctor()
{
	system("cls");

	string name, gender, specialist, address;
	int age = {};
	int fee = {};

	info i;

	cout << "Data Entering in Doctor Section " << endl;
	cout << "Enter the Doctor Name: " << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter the Doctor Gender: " << endl;
	getline(cin, gender);
	cout << "Enter the Doctor Specialist: " << endl;
	getline(cin, specialist);
	cout << "Enter the Doctor Address: " << endl;
	getline(cin, address);
	cout << "Enter the Doctor Age: " << endl;
	cin >> age;
	cout << "Enter the Doctor Fees: " << endl;
	cin >> fee;

	i.name = name;
	i.gender = gender;
	i.specialist = specialist;
	i.address = address;
	i.age = age;
	i.fee = fee;

	return i;

}

info input_staff()
{
	system("cls");

	string name, gender, feild, address;
	int  age = {};

	info i;

	cout << "Data Entering in Staff Section " << endl;
	cout << "Enter the Staff Name: " << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter the Staff Gender: " << endl;
	getline(cin, gender);
	cout << "Enter the Staff Field: " << endl;
	getline(cin, feild);
	cout << "Enter the Staff Address: " << endl;
	getline(cin, address);
	cout << "Enter the Staff Age: " << endl;
	cin >> age;

	i.name = name;
	i.gender = gender;
	i.feild = feild;
	i.address = address;
	i.age = age;

	return i;

}

info input_appointment()
{
	system("cls");

	string name, gender, disease, address;
	int age = {};
	int date = {};

	info i;

	cout << "Data Entering in Appointment Section " << endl;
	cout << "Enter The Patient Name: " << endl;
	cin.ignore();
	getline(cin, name);
	cout << "Enter The Patient Gender: " << endl;
	getline(cin, gender);
	cout << "Enter The Patient Disease: " << endl;
	getline(cin, disease);
	cout << "Enter The Patient Address: " << endl;
	getline(cin, address);
	cout << "Enter The Patient Age: " << endl;
	cin >> age;
	cout << "Enter The Patient Appointment Date: " << endl;
	cin >> date;

	i.name = name;
	i.gender = gender;
	i.disease = disease;
	i.address = address;
	i.age = age;
	i.date = date;

	return i;

}

node* append(node* head, info data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		return head;
	}
	node* last = head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = temp;

	cout << "Append Completed " << endl;

	return head;

}

void del_element(node* head, int location)
{
	node* temp = new node;
	temp = head;

	if (head == NULL)
	{
		cout << "Node is NULL " << endl;
		return;
	}

	for (int i = 1; i <= location; i++)
	{
		temp = temp->next;

		if (i < location)
		{
			head = head->next;
		}
	}

	head->next = temp->next;

}

node* search_list(node* head, string name)
{
	int i = 1;

	if (head == NULL)
	{
		system("Cls");
		cout << "Empty " << endl;
		return NULL;
	}

	while (head->next != NULL && head->data.name != name)
	{
		head = head->next;
		i++;

	}

	if (head->data.name == name)
	{
		cout << "Eelment Found at Location " << i << endl;
	}

	return head;
} 

int list_length(node* head)
{
	int temp = 0;

	if (head == NULL)
	{
		cout << "List is Empty " << endl;
		return 0;
	}

	while (head->next != NULL)
	{
		temp++;
		head = head->next;
	}

	return temp + 1;
}

void read_patient_list(node* head)
{

	char store_patient[50][50] = {};

	int i = 0;

	ifstream patient_read;

	patient_read.open("patient.txt");

	if (patient_read.fail())
	{
		cout << "Printing Patient List " << endl;
		cout << "File Not Opened " << endl;
		return;
	}

	cout << "Print Patients List " << endl;

	while (!patient_read.eof())
	{
		patient_read.getline(store_patient[i], 50);
		i++;
	}

	for (int i = 0; i < 50; i++)
	{
		for (int k = 0; k < 50; k++)
		{

			cout << store_patient[i][k];

		}
		cout << endl;
	}

	patient_read.close();

}

void write_patient_list(node* head)
{
	ofstream patient_info;

	patient_info.open("patient.txt", ios::app);
	patient_info << "Printing Patients List: " << endl;

	while (head != NULL)
	{
		patient_info << "Name: " << head->data.name << endl;
		patient_info << "Address: " << head->data.address << endl;
		patient_info << "Gender: " << head->data.gender << endl;
		patient_info << "Discription: " << head->data.discription << endl;
		patient_info << "Disease: " << head->data.disease << endl;
		patient_info << "Age: " << head->data.age << endl;
		patient_info << "Room No: " << head->data.special_room_no << endl;
		head = head->next;
	}

	patient_info.close();
}

void read_doctor_list(node* head)
{

	char storedoctor[50][50] = {};
	int i = 0;

	ifstream doctor_read;
	doctor_read.open("doctor.txt");

	if (doctor_read.fail())
	{
		cout << "Printing Doctors List " << endl;
		cout << "File Not Opened " << endl;
		return;

	}

	cout << "Printing Doctors List " << endl;

	while (!doctor_read.eof())
	{
		doctor_read.getline(storedoctor[i], 50);
		i++;
	}

	for (int i = 0; i < 50; i++)
	{
		for (int k = 0; k < 50; k++)
		{

			cout << storedoctor[i][k];

		}
		cout << endl;
	}

	doctor_read.close();


}

void write_doctor_list(node* head)
{
	ofstream doctor_info;

	doctor_info.open("doctor.txt", ios::app);
	doctor_info << "Printing Doctors List" << endl;

	while (head->next != NULL)
	{

		doctor_info << "Name: " << head->data.name << endl;
		doctor_info << "Address: " << head->data.address << endl;
		doctor_info << "Gender: " << head->data.gender << endl;
		doctor_info << "Specialist: " << head->data.specialist << endl;
		doctor_info << "Age: " << head->data.age << endl;
		doctor_info << "Fees: " << head->data.fee << endl;

		head = head->next;
	}

	doctor_info.close();
}

void read_staff_list(node* head)
{
	char store_staff[50][50] = {};
	int i = 0;

	ifstream staff_read;
	staff_read.open("staff.txt");

	if (staff_read.fail())
	{
		cout << "Printing Staff List " << endl;
		cout << "File Not Opened " << endl;
		return;
	}

	cout << "Printing Staff List " << endl;

	while (staff_read.eof())
	{
		staff_read.getline(store_staff[i], 50);
		i++;
	}

	for (int i = 0; i < 50; i++)
	{
		for (int k = 0; k < 50; k++)
		{

			cout << store_staff[i][k];

		}

		cout << endl;
	}


	staff_read.close();

}

void write_staff_list(node* head)
{
	ofstream staff_list;
	staff_list.open("staff.txt", ios::app);
	staff_list << "Printing Staff List" << endl;

	while (head->next != NULL)
	{
		staff_list << "Name: " << head->data.name << endl;
		staff_list << "Address: " << head->data.address << endl;
		staff_list << "Gender: " << head->data.gender << endl;
		staff_list << "Feild: " << head->data.feild << endl;
		staff_list << "Age: " << head->data.age << endl;

		head = head->next;
	}

	staff_list.close();
}

void change_node(node* head, string data, string new_data)
{
	while (head != NULL)
	{
		if (head->data.name == data)
		{

			head->data.name = new_data;

		}

		head = head->next;
	}

}

node* insert_front(node* head, info data)
{
	node* temp = new node;
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}

void display_title()
{

	cout << "Hospital Management System " << endl;

}
	
void start_code()
{
	
	system("cls");
	display_title();
	cout << "Loading Project " << endl;
	system("cls");

}

int main()
{
	start_code();
	system("pause");
	system("cls");

	node* head = NULL;
	info patient;
	info doctor;
	info staff;
	info appointment;
	string name_search;
	string old_name;
	string new_name;

	while (1)
	{
		system("cls");

		cout << "Welcome " << endl;
		cout << "1. Doctor Section" << endl;
		cout << "2. Patient Section" << endl;
		cout << "3. Staff Section" << endl;
		cout << "4. Appointment Section" << endl;
		cout << "5. Bill Section" << endl;
		cout << "---------------------------------------" << endl;

		int i = {};
		cin >> i;

		if (i == 1) 
		{
			int option = {};
			system("cls");
			
			cout << "Welcome To Doctor Section " << endl;
			cout << "1. Add " << endl;
			cout << "2. Delete " << endl;
			cout << "3. Search " << endl;
			cout << "4. List Length " << endl;
			cout << "5. Print " << endl;
			cout << "6. Change Name " << endl;
			cout << "7. Save Data " << endl;
			cout << "---------------------------------------" << endl;

			while (cin >> option)
			{
				switch (option)
				{


				case 1:

					cout << "Enter Doctor Details " << endl;
					doctor = input_doctor();
					head = append(head, doctor);
					break;

				case 2:

					system("cls");
						
					if (list_length(head) < 2)
					{
						
						cout << "Length is Less than Two " << endl;
						cout << "Terminating Project " << endl;
						cout << "-------------------------------------------------" << endl;
						exit(1);

					}

					else 
					{
						cout << "Enter Location Where You Want to Delete a Doctor at Least Three Doctors must be in List " << endl;
						int i = {};
						cin >> i;
						del_element(head, 1);
					}

					break;

				case 3:

					system("cls");
					cout << "Searching " << endl;
					cout << "Enter Name to Search: " << endl;
					cin.ignore();
					getline(cin, name_search);
					search_list(head, name_search);
					break;

				case 4:

					system("cls");
					cout << "List Length " << endl;
					cout << "You have " << list_length(head) << "New Doctor in Hospital " << endl;
					break;

				case 5:

					system("cls");
					cout << "Printing Doctors List " << endl;
					read_doctor_list(head);
					system("pause");
					break;

				case 6:

					system("cls");
					cout << "Data Change " << endl;
					cin.ignore();
					getline(cin, old_name);
					getline(cin, new_name);
					change_node(head, old_name, new_name);
					break;

				case 7:

					write_doctor_list(head);
					break;

				default:

					break;
				}

				break;

				system("cls");

			}


		}

		if (i == 2) 
		{
			int option = {};
			system("cls");
			cout << "Welcome To Patient Section " << endl;
			cout << "---------------------------------------" << endl;
			cout << "1. Add " << endl;
			cout << "2. Delete " << endl;
			cout << "3. Search " << endl;
			cout << "4. List Length " << endl;
			cout << "5. Print " << endl;
			cout << "6. Change Name " << endl;
			cout << "7. Insert At Front " << endl;
			cout << "8. Save Data " << endl;
			cout << "---------------------------------------" << endl;

			while (cin >> option)
			{
				switch (option)
				{

				case 1:

					cout << "Enter Patient Details ";
					patient = input_patient();
					head = append(head, patient);
					break;

				case 2:

					read_patient_list(head);

					if (list_length(head) < 2)
					{
						cout << "Length is Less than Two " << endl;
						cout << "Terminating Project" << endl;
						cout << "-------------------------------------------------" << endl;
						exit(1);
					}

					else 
					{
						cout << "Enter Location Where You Want to Delete a Patient at Least Three Doctors must be in List " << endl;
						int i;
						cin >> i;
						del_element(head, 1);
					}

					break;

				case 3:

					system("cls");
					cout << "Searching " << endl;
					cout << "Enter Name to Search: " << endl;
					cin.ignore();
					getline(cin, name_search);
					search_list(head, name_search);
					system("pause");
					break;

				case 4:

					system("cls");
					cout << "List Length " << endl;
					cout << "You have " << list_length(head) << "New Patient in Hospital " << endl;
					break;

				case 5:

					system("cls");
					cout << "Printing Patient List " << endl;
					read_patient_list(head);
					system("pause");
					break;

				case 6:

					system("cls");
					cout << "Data Change " << endl;
					cin.ignore();
					cout << "Enter the Old Name: " << endl;
					getline(cin, old_name);
					cout << "Enter the New Name: " << endl;
					getline(cin, new_name);
					change_node(head, old_name, new_name);
					break;

				case 7:

					patient = input_patient();
					head = insert_front(head, patient);
					break;

				case 8:

					write_patient_list(head);
					break;

				}

				break;
				system("cls");

			}
		}
		if (i == 3)
		{
			int option = {};
			system("cls");

			system("cls");
			cout << "Welcome To Staff Section" << endl;
			cout << "---------------------------------------" << endl;
			cout << "1. Add " << endl;
			cout << "2. Delete " << endl;
			cout << "3. Search " << endl;
			cout << "4. List Length " << endl;
			cout << "5. Print " << endl;
			cout << "6. Insert At Front " << endl;
			cout << "7. Save Data " << endl;
			cout << "---------------------------------------" << endl;

			while (cin >> option)
			{
				switch (option)
				{
				case 1:

					cout << "Enter Staff Details ";
					staff = input_staff();
					head = append(head, staff);
					break;

				case 2:

					if (list_length(head) < 2)
					{
						cout << "Length is Less than Two " << endl;
						cout << "Terminating Project" << endl;
						cout << "-------------------------------------------------" << endl;
						exit(1);
	
					}

					else 
					{
						cout << "Enter Location Where You Want to Delete a Staff at Least Three Doctors must be in List " << endl;
						int i;
						cin >> i;
						del_element(head, 1);
					}

					break;

				case 3:

					system("cls");
					cout << "Searching " << endl;
					cout << "Enter Name to Search: " << endl;
					cin.ignore();
					getline(cin, name_search);
					search_list(head, name_search);
					system("pause");
					break;

				case 4:

					system("cls");
					cout << "List Length " << endl;
					cout << "You have " << list_length(head) << "New Patient in Hospital " << endl;
					break;

				case 5:

					system("cls");
					cout << "Printing Staff List " << endl;
					read_staff_list(head);
					system("pause");
					break;

				case 6:

					staff = input_staff();
					head = insert_front(head, staff);
					break;

				case 7:

					write_staff_list(head);
					break;

				default:

					cout << "Wrong Option " << endl;

				}

				break;
				system("cls");
			}
		}
		if (i == 4)
		{
			string name;
			int  i = 0, l = 0;
			int option = {};

			while (1)
			{
				system("cls");
				
				cout << "Welcome To Appointment Section " << endl;
				cout << "1. Emergency Appointments " << endl;
				cout << "2. Non Emergency Appointments " << endl;
				cout << "3. Search Appointment Details " << endl;
				cout << "4. Display All Appointments Details " << endl;
				cout << "5. Display Top Priority Patient Details " << endl;
				cout << "6. Delete Top Priority Patient " << endl;
				cout << "7. Return To Main Menu " << endl;
				cout << "------------------------------------------" << endl;

				cin >> option;

				l++;


				if (option == 1)
				{
					enqueue(i);
					i++;
				}

				if (option == 2)
				{
					enqueue(l);
				}

				if (option == 3)
				{
					system("cls");
					cout << "Searching " << endl;
					cout << "Enter Name to Search: " << endl;
					cin >> name;
					search_appointment(name);
					system("pause");

				}

				if (option == 4)
				{
					system("cls");
					cout << "Printing Appointments List " << endl;
					display_queue();
					system("pause");
				}

				if (option == 5)
				{
					system("cls");
					cout << "Patient in Appointment List " << endl;
					display_front();
					system("pause");

				}

				if (option == 6)
				{
					dequeue();

				}

				if (option == 7)
				{
					break;
				}

				system("cls");

			}


		}

		if (i == 5)
		{
			system("cls");
			int q = {};

			cout << "Hospital Bill " << endl;
			cout << "Enter name to Search: " << endl;
			cin.ignore();
			getline(cin, name_search);
			search_list(head, name_search);

			cout << "1. Emergency " << endl;
			cout << "2. Check Up " << endl;

			cin >> q;

			if (q == 1)
			{
				system("cls");
				int w = {};

				cout << "1. Operation Emergency " << endl;
				cout << "2. Non Operation Emergency " << endl;

				cin >> w;

				if (w == 1)
				{
					
					cout << "Emergency Charges " << endl;
					cout << "OPD = 150 " << endl;
					cout << "Doctor Charges = 500 " << endl;
					cout << "Operation Charges = 5000 " << endl;
					cout << "First Aid Charges = 100 " << endl;
					cout << "Total Amount = 5750 RS " << endl;


				}

				if (w == 2)
				{
					
					cout << "Emergency Charges " << endl;
					cout << "OPD = 150 " << endl;
					cout << "Doctor Charges = 500 " << endl;
					cout << "First Aid Charges = 100 " << endl;
					cout << "Total Amount = 750 RS " << endl;

				}

			}
			if (q == 2)
			{
				cout << "OPD = 150 " << endl;
				cout << "Doctor Charges = 500 " << endl;
				cout << "Total Amount = 650 RS " << endl;
				

			}

		}
	}
}