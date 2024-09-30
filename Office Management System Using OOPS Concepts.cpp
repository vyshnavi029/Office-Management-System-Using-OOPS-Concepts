#include<iostream>
using namespace std;

class employee
{
	protected:
	string employee_name;
	int age;
	char gender;
	public:
		int employee_id;
		int salary;
		void sete()
		{
			cout<<"Enter the employee name: ";
			cin>>employee_name;
			cout<<"Enter employee id: ";
			cin>>employee_id;
			cout<<"Enter age: ";
			cin>>age;
			cout<<"Enter gender(M/F): ";
			cin>>gender;
			cout<<"Enter the salary: ";
		    cin>>salary;
		}
		void gete()
		{
			cout<<"Employee Name: "<<employee_name<<endl;
			cout<<"Employee Id: "<<employee_id<<endl;
			cout<<"Employee Age: "<<age<<endl;
			cout<<"Employee Gender: "<<gender<<endl;
			cout<<"Salary: "<<salary<<endl;
		}
		virtual void set()=0; //pure virtual function
		virtual void get()=0; //pure virtual function
		void operator ++() {  //Operator Overloading(Polymorphism)
			int choice;
			cout<<"press 1 to modify the name of the employee\npress 2 to modify the age of the employee\n";
			cout<<"press 3 to modify the salary of the employee\n";
			cout<<"Enter the choice: ";
			cin>>choice;
			if(choice==1)
			{
				string c1;
				cout<<"Enter the new name: ";
				cin>>c1;
				employee_name = c1;
				cout << "Name successfully updated!\n"; 
			}
			if(choice==2)
			{
				int c2;
				cout<<"Enter the new age: ";
				cin>>c2;
				age = c2;
				cout << "Age successfully updated!\n"; 
			}
			if(choice==3)
			{
				int k;
				cout<<"Enter the amount of salary to be incremented: ";
				cin>>k;
				salary += k;
				cout << "Salary successfully updated!\n"; 
		    }
		}
};

class department: public employee
{
    protected:
	string dept_name;
    public:
	virtual void set()        //virtual function
	{
		employee::sete();
		cout<<"Enter the employee's department: ";
		cin>>dept_name;
	}
	virtual void get()        //virtual function
	{
		employee::gete();
		cout<<"Employee's Department: "<<dept_name<<endl;
	}
};

class sales_dept: public department
{
	public:
	string designation;
	void set()
	{
		department::set();
		cout<<"Enter the employee's designation: ";
		cin>>designation;
	}
	void get()
	{
		department::get();
		cout<<"Employee's Designation: "<<designation<<endl;
	}
};

class production_dept: public department
{
	public:
	string designation;
	void set()
	{
		department::set();
		cout<<"Enter the employee's designation: ";
		cin>>designation;
	}
	void get()
	{
		department::get();
		cout<<"Employee's Designation: "<<designation<<endl;
	}
};

class designing_dept: public department
{
	public:
	string designation;
	void set()
	{
		department::set();
		cout<<"Enter the employee's designation: ";
		cin>>designation;
	}
	void get()
	{
		department::get();
		cout<<"Employee's Designation: "<<designation<<endl;
	}
};

int main()
{
	employee *ptr[100];
	int n = 1, choice2, k1, i = 1, q, t;
	char choice;
	int removed[100] = {0}; /
	
	while(1)
	{
	cout << endl;
	cout<<"_______________________________\n";
	cout<<"ENTER 1: To Add New Employee details\n";
	cout<<"ENTER 2: To View List of Employees\n";
	cout<<"ENTER 3: To View Employee details by ID\n";
	cout<<"ENTER 4: To Modify Existing Employee details\n";
	cout<<"ENTER 5: To Remove Employee details\n";
	cout<<"ENTER 0: To Exit\n";
	cout<<"Enter the choice: ";
	cin>>choice2;
	
	switch(choice2)
	{
	case 1:
		cout<<"\nEmployee of sales dept or designing dept or production dept(s/d/p): ";
		cin>>choice;
		if(choice == 's')
		{
			cout<<"\n\nEnter the details\n\n";
			ptr[n] = new sales_dept;
			ptr[n++]->set();
		}
		else if(choice == 'd') 
		{
			cout<<"Enter the details\n\n";
			ptr[n] = new designing_dept;
			ptr[n++]->set();
		}
		else if(choice == 'p')
		{
			cout<<"Enter the details\n\n";
			ptr[n] = new production_dept;
			ptr[n++]->set(); 
		}
		break;	
	
	case 2:
		if(n == 1) 
		{
			cout<<"Details are not found\n";
		}
		else
		{
			for(int j = 1; j < n; j++)
			{
				if(removed[j]) continue;  
				cout << "\nDetails of employee " << j << ":\n";
				cout << endl;
				ptr[j]->get();
			}
		}
		break;
		
	case 3:
		cout << endl;
		cout<<"Enter the employee id: ";
		int emp_id;
		cin>>emp_id;
		for(int j = 1; j < n; j++)
		{
			if(ptr[j]->employee_id == emp_id && !removed[j])
			{
				ptr[j]->get();
				q = 1;
				break;
			}
		}
		if(q == 0) cout << "Details are not found\n";
		break;
	
	case 4:
		cout<<"Enter the employee id: ";
		cin>>k1;
		t = 0;
		for(int j = 1; j < n; j++)
		{
			if(ptr[j]->employee_id == k1 && !removed[j])
			{
				++*ptr[j];  
				cout << "\nUpdated Details\n";
				cout << endl;
				ptr[j]->get();
				t = 1;
				break;
			}
		}
		if(t == 0) cout<<"Details are not found\n";
		break;
	
	case 5:
		cout<<"Enter the employee id: ";
		cin>>k1;
		t = 0;
		for(int j = 1; j < n; j++)
		{
			if(ptr[j]->employee_id == k1 && !removed[j])
			{
				removed[j] = 1;  
				cout<<"Employee details successfully removed!\n";
				t = 1;
				break;
			}
		}
		if(t == 0) cout<<"Details are not found\n";
		break;
	
	case 0:
		exit(0); 
	}
    }
return 0;
}

