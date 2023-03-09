/*Hospital Management System*/
#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include<cstring>
#include<windows.h>
void menu();
void pascode();
void cpascode();
using namespace std;
class one
{
	public:
		virtual void get()=0;
		virtual void show()=0;		
};
class info: public one
{
	public:
		char name[50], time[50];
		int num, age;
		void get()
		{
			system("cls");
			cin.sync();
			cout<<"\nEnter the patient name= ";
			cin.getline(name, 50);
			cout<<"\nEnter the Appoinment Time= ";
			cin.getline(time, 50);
			cout<<"\nEnter Age= ";
			cin>>age;
			cout<<"\nEnter Appoinment no. = ";
			cin>>num;
		}
		void show()
		{
			cout<<"\nName= "<<name;
			cout<<"\nAge= "<<age;
			cout<<"\nNo. = "<<num;
			cout<<"\nTime "<<time;
		}
};
class usama:public info
{
	public:
		info a1;
		void get()
		{
			system("cls");
			ofstream out("usama.txt", ios::app|ios::binary);
			a1.get();
			out.write((char*)&a1,sizeof(info));
			out.close();
			cout<<"Your Entry has been saved";
			getch();
			menu();
		}
		void show()
		{
			ifstream in("usama.txt");
			if(in==NULL)
			{
				cout<<"\n\nNo Data in the File ";
				cout<<"\n\n\t\tPress any key to continue: ";
				getch();
				menu();
			}
			else
			{
				while(!in.eof())
				{
					in.read((char*)&a1,sizeof(a1));
					a1.show();
				}
				in.close();
				getch();
				menu();
			}
		}
};
class bilal:public info
{
	public:
		info a1;
		void get()
		{
			system("cls");
			ofstream out("bilal.txt", ios::app|ios::binary);
			a1.get();
			out.write((char*)&a1,sizeof(info));
			out.close();
			cout<<"Your Entry has been saved";
			getch();
			menu();
		}
		void show()
		{
			ifstream in("bilal.txt");
			if(in==NULL)
			{
				cout<<"\n\nNo Data in the File ";
				cout<<"\n\n\t\tPress any key to continue: ";
				getch();
				menu();
			}
			else
			{
				while(!in.eof())
				{
					in.read((char*)&a1,sizeof(a1));
					a1.show();
				}
				in.close();
				cout<<"Press Enter to continue ";
				getch();
				menu();
			}
		}
};
class awais:public info
{
	public:
		info a1;
		void get()
		{
			system("cls");
			ofstream out("awais.txt", ios::app|ios::binary);
			a1.get();
			out.write((char*)&a1,sizeof(info));
			out.close();
			cout<<"Your Entry has been saved";
			getch();
			menu();
		}
		void show()
		{
			ifstream in("awais.txt");
			if(in==NULL)
			{
				cout<<"\n\nNo Data in the File ";
				cout<<"\n\n\t\tPress any key to continue: ";
				getch();
				menu();
			}
			else
			{
				while(!in.eof())
				{
					in.read((char*)&a1,sizeof(a1));
					a1.show();
				}
				in.close();
			}
		}
};
class staff:public one
{
	public:
		char all[999];
		char name[50],age[20],sal[30],pos[20];
		void get()
		{
			ofstream out("staff.txt",ios::app);
			{
				system("cls");
				cin.sync();
				cout<<"\nEnter Name= ";
				cin.getline(name,50);
				cout<<"\nEnter Age= ";
				cin.getline(age,20);
				cout<<"\nEnter Sallary= ";
				cin.getline(sal,30);
				cout<<"\nEnter Working Position= ";
				cin.getline(pos,20);
		    }
		out<<"\nName= "<<name<<"\nAge= "<<age<<"\nSallary= "<<sal<<"\nworking position= "<<pos;
		out.close();
		cout<<"\nYour Information has been saved: \n\t\t Press any key to continue ";
		getch();
		menu();
	    }
	    void show()
	    {
	    	ifstream in("staff.txt");
	    	if(!in)
	    	{
	    		cout<<"File open error";
			}
			while(!(in.eof()))
			{
			    in.getline(all,999);
			    cout<<all<<endl;
		    }	
			in.close();
			cout<<"\n\t\tPress any Key to continue";
			getch();
			menu();
		}
};
class information
{
	public:
		void drinfo()
		{
			system("cls");
			system("color F3");
			cout<<"\n\n\t\t(Three Doctor Available)\n\n\t\t[Information and Timing are given Below]\n";
		    cout<<"\t\tDr Available: \n";
		    cout<<"\t\tDr. Usama (skin specialist)\n\n";
		    cout<<"\t\tDr Available:\n";
		    cout<<"\t\t[[Timing]]:\n\n";
		    cout<<"\tMonday to Friday\t9AM to 5PM\n";
		    cout<<"\tSaturday        \t9AM to 1PM\n";
		    cout<<"\tSunday          \tOFF\n";
		    cout<<"\t\tDr. Bilal (child specialist)\n\n";
		    cout<<"\t\t[[Timing]]:\n\n";
		    cout<<"\tMonday to Friday\t2PM to 10PM\n";
		    cout<<"\tSaturday        \t8AM to 1PM\n";
		    cout<<"\tSunday          \t12PM to 9PM\n";
		    cout<<"\t\tDr. Awais (DVM)\n\n";
		    cout<<"\t\t[[Timing]]:\n\n";
		    cout<<"\tMonday to Friday\t8AM to 5PM\n";
		    cout<<"\tSaturday        \t10AM to 1PM\n";
		    cout<<"\tSunday          \tOFF\n";
		    cout<<"\nPress Any Key to continue: ";
		    getch();
		    menu();
		}
};
void call_dr()
{
	system("cls");
	int choice;
	cout<<"\n\n\n\t\tPress 1 for Dr. Usama \n\n\t\tPress 2 for Dr. Bilal \n\n\t\tPress 3 for Dr. Awais ";
	cin>>choice;
	one *ptr;
	usama s3;
	bilal s4;
	awais s5;
	if(choice==1)
	{
		ptr=&s3;
		ptr->get();
	}
	if(choice==2)
	{
		ptr=&s4;
		ptr->get();
	}
	if(choice==3)
	{
		ptr=&s5;
		ptr->get();
	}
	else
	{
		cout<<"Sorry invalid choice";
		getch();
		menu();
	}
}
pinfoshow()
{
	system("cls");
	int choice;
	cout<<"\n\n\n\t\t-->Press 1 for Dr. Usama \n\n\t\t-->Press 2 for Dr. Bilal \n\n\t\t-->Press 3 for Dr. Awais \n\n\t\tPlease Enter Your Choice= ";
	cin>>choice;
	one *ptr;
	usama s3;
	bilal s4;
	awais s5;
	if(choice==1)
	{
		ptr=&s3;
		ptr->show();
	}
	if(choice==2)
	{
		ptr=&s4;
		ptr->show();
	}
	if(choice==3)
	{
		ptr=&s5;
		ptr->show();
	}
	else
	{
		cout<<"Sorry invalid choice";
		getch();
		menu();
	}
}
void menu()
{
	system("cls");
	system("color FC");
	cout<<"\n\n";
	cout<<"\t\t\t   |**********MAIN MENU***********|\n"
	    <<"\t\t\t   |  HOSPITAL MANAGEMENT SYSTEM  |\n"
	    <<"\t\t\t   |******************************|\n";
	cout<<"\n\n\t\t    Please Select Any Option     \n";
	cout<<"\n\n\t1-\t\tPress 1 for Available Doctor information\n\n";
	cout<<"\t2-\t\tPress 2 for Doctor Appointment\n\n";
	cout<<"\t3-\t\tPress 3 for Saving Staff information\n\n";
	cout<<"\t4-\t\tPress 4 for Checking Patient Appointment Menu\n\n";
	cout<<"\t5-\t\tPress 5 for Checking Staff information Menu\n\n";
	cout<<"\t6-\t\tPress 6 for Change Password or create Password\n\n";
	cout<<"\t7-\t\t[   Press 7 for Logout   ]\n";
	cout<<"\n\n\t\tPlease Enter Your Choice= ";
	information a1;
	one *ptr;
	staff a2;
	info i2;
	int a;
	cin>>a;
	if(a==1)
	{
		a1.drinfo();
	}
	else if(a==2)
	{
		call_dr();
	}
	else if(a==3)
	{
		ptr=&a2;
		ptr->get();
	}
	else if(a==4)
	{
		pinfoshow();
	}    
	else if(a==5)
	{
		ptr=&a2;
		ptr->show();
	}
	else if(a==6)
	{
		cpascode();
	}
	else if(a==7)
	{
		pascode();
	}
	else
	{
		cout<<"Sorry Invalid Choice";
	}
}
void pascode()
{
	system("cls");
	char p1[50],p2[50],p3[50];
	system("color FC");
	ifstream in("password.txt");
	{
		cin.sync();
		cout<<"\n\n\n\n\n\n\n\t\t\tEnter Password: ";
		cin.getline(p1,50);
		in.getline(p2,50);
		if(strcmp(p2,p1)==0)
		{
			menu();
		}
		else
		{
			cout<<"\n\n\t\tIncorrect Passcode Please Try Again\n";
			Sleep(999);
			pascode();
		}
	}
	in.close();
}
void cpascode()
{
	char n[50];
	system("cls");
	ofstream out("password.txt");
	{
		cin.sync();
		cout<<"\n\n\n\n\t\tEnter new password";
		cin.getline(n,50);
		out<<n;
	}
	out.close();
	cout<<"\n\nYour Password has been Saved";
	getch();
	menu();
}
int main()
{
	pascode();
	system("Pause");
}
