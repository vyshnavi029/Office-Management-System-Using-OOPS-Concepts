#include<iostream>
using namespace std;
/*class board_of_directors
{
};*/
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
				employee_name=c1;
			}
			if(choice==2)
			{
				int c2;
				cout<<"Enter the new age: ";
				cin>>c2;
				age=c2;
			}
			if(choice==3)
			{
			int k;
			cout<<"Enter the amount of salary to be incremented: ";
			cin>>k;
			salary+=k;
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
class sales_dept:public department
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
class production_dept:public department
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
class designing_dept:public department
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
	int n=1,choice2,k,k1,f,arr[100],i=1,q,t;
	char choice,choice1;
	while(1)
	{
	cout<<"_______________________________\n";
	cout<<"ENTER 1: To Add New Employee details\n";
	cout<<"_______________________________\n";
	cout<<"ENTER 2: To View List of Employees\n";
	cout<<"_______________________________\n";
	cout<<"ENTER 3: To View Employee details\n";
	cout<<"_______________________________\n";
	cout<<"ENTER 4: To Modify Existing Employee details\n";
	cout<<"_______________________________\n";
	cout<<"ENTER 5: To Remove Employee details\n";
	cout<<"_______________________________\n";
	cout<<"ENTER 0: To Exit\n";
	cout<<"_______________________________\n";
	cout<<"Enter the choice: ";
	cin>>choice2;
	switch(choice2)
	{
	case 1:
		cout<<"\nEmployee of sales dept or designing dept or production dept(s/d/p): ";
		cin>>choice;
		if(choice=='s')
		{
			cout<<"\n\nEnter the details\n\n";
			ptr[n]=new sales_dept;
			ptr[n++]->set();
		}
		else if(choice=='d') 
		{
			cout<<"Enter the details\n\n";
			ptr[n]=new designing_dept;
			ptr[n++]->set();
		}
		else if(choice=='p')
		{
			cout<<"Enter the details\n\n";
			ptr[n] = new production_dept;
			ptr[n++]->set(); 
		}
		break;	
	case 2:
		if(n==1)
		cout<<"Details are not found\n";
		for(int j=1;j<n;j++)
		{
			int flag=0;
			for(k=1;k<i;k++)
			{
				if(arr[k]==j)
				flag=1;
			}
			if(flag==1)
			continue;
		cout<<"\nDetails of employee  "<<endl;
		ptr[j]->get();
	    }
		break;
	case 3:
		int p;
		cout<<"Enter the employee id: ";
		cin>>p;
		for(int j=1;j<n;j++)
		{
			q=0;
			for(k=1;k<i;k++)
			{
				if(arr[k]==j)
				{
					cout<<"Details are not found\n";
					q=1;
					break;
				}
			}
			if(q==1)
			break;
			if(j==p) 
			ptr[j]->get();
		}
		break;
	case 4:
		cout<<"Enter the employee id: ";
		cin>>k1;
		t=0;
		for(k=1;k<i;k++)
			{
				if(arr[k]==k1)
				{
					cout<<"Details are not found\n";
					t=1;
					break;
				}
			}
		if(t==1)
		break;
		++*ptr[k1];
		cout<<"\nUpdated Details\n";
		ptr[k1]->get();
		break;
	case 5:
		cout<<"Enter the employee id: ";
		cin>>k1;
		arr[i++]=k1;
		delete ptr[k1];
		break;
	case 0:
	exit(1);
    }
    }
return 0;
}
