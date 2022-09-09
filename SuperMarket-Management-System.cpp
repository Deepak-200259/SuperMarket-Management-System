#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
	private:
		int pcode;
		float price;
		float discount;
		string pname;
		
	public:
		void menu();
		void administrator();
		void customer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
};

void shopping::menu()
{
	M:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t\t ________________________________________ \n";
	cout<<"\t\t\t\t\t|                                        |\n";
	cout<<"\t\t\t\t\t|          SUPERMARKET MAIN MENU         |\n";
	cout<<"\t\t\t\t\t|                                        |\n";
	cout<<"\t\t\t\t\t|________________________________________|\n";
	cout<<"\t\t\t\t\t                                         \n";
	
	cout<<"\t\t\t\t\t\t  1. Administrator  \n";
	cout<<"\t\t\t\t\t\t                    \n";
	cout<<"\t\t\t\t\t\t  2. Customer       \n";
	cout<<"\t\t\t\t\t\t                    \n";
	cout<<"\t\t\t\t\t\t  3. Exit           \n";
	cout<<"\t\t\t\t\t\t                    \n";
	cout<<"\n\t\t\t\t Please Select: ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			cout<<"\t\t\t\t\t\t  Please Login \n";
			cout<<"\t\t\t\t\t\t  Enter Email : ";
			cin>>email;
			cout<<"\t\t\t\t\t\t  Enter Password : ";
			cin>>password;
			
			if(email=="deepu75280@gmail.com" && password=="Deepu@75280")
			{
				administrator();
			}
			else
			{
				cout<<"\t\t\t\t\t\t  Invalid Email / Password\n";
			}
			break;
		case 2:
			customer();
		case 3:
			exit(0);
		default:
			{
				cout<<"\t\t\t Invalid option! Select from the given options\n";
			}
	}
	goto M;
}

void shopping::administrator()
{
	M:
	int choice;
	cout<<"\n\n\n\t\t\t\t________________________________________________";
	cout<<"\n\t\t\t\t\t\t   Administrator Menu \n";
	cout<<"\t\t\t\t________________________________________________";
	cout<<"\n\t\t\t\t\t\t  1. Add the Product \n";
	cout<<"\t\t\t\t\t\t  2. Modify the Product \n";
	cout<<"\t\t\t\t\t\t  3. Delete the Product \n";
	cout<<"\t\t\t\t\t\t  4. Back to Main Menu \n";
	cout<<"\t\t\t\t\t\t  5. Exit \n";
	
	cout<<"\n\t\t\t\t   Please Enter Your Choice : ";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		case 5:
			exit(0);
		default:
			cout<<"\n\t\t\t\t\t\t  Invalid Choice! Retry\n";
	}
	goto M;
}

void shopping::customer()
{
	M:
	int choice;
	cout<<"\n\n\n\t\t\t\t________________________________________________";
	cout<<"\n\t\t\t\t\t\t         Customer \n";
	cout<<"\t\t\t\t________________________________________________";
	cout<<"\n\t\t\t\t\t\t 1. Buy Product \n";
	cout<<"\t\t\t\t\t\t 2. Go Back \n";
	
	cout<<"\t\t\t Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
		default:
			cout<<"\n\t\t\tInvalid Choice\n";
	}
	goto M;
}

void shopping::add()
{
	M:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	cout<<"\n\n\n\t\t\t________________________________________________";
	cout<<"\n\t\t\t\tAdd New Product \n";
	cout<<"\t\t\t________________________________________________";
	cout<<"\n\t\t\t\t\t\t Product Code of the Product :";
	cin>>pcode;
	cout<<"\n\t\t\t\t\t\t Name of the Product :";
	cin>>pname;
	cout<<"\n\t\t\t\t\t\t Price of the Product :";
	cin>>price;
	cout<<"\n\t\t\t\t\t\t Discount on Product :";
	cin>>discount;
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
		data.close();
	}
	else
	{
		data>>c>>n>>p>>d;
		while(!data.eof())
		{
			if(c==pcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		
		if(token==1)
		{
			goto M;
		}
		else
		{
			data.open("database.txt",ios::app|ios::out);
			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
			data.close();	
		}
	}
	
	cout<<"\n\n\t\t\t  Record Inserted";
}

void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	cout<<"\n\n\n\t\t\t________________________________________________";
	cout<<"\n\t\t\t\t  Modify the Record";
	cout<<"\n\t\t\t________________________________________________";
	cout<<"\n\t\t\t\t\t\t Product Code :";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n\t\t\tFile Doesn't Exist! \n";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>discount;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t\t Product New Code:";
				cin>>c;
				cout<<"\n\t\t\t Product Name: ";
				cin>>n;
				cout<<"\n\t\t\t Price: ";
				cin>>p;
				cout<<"\n\t\t\t Discount: ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\n\t\t\t Record Edited";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
			}
			data>>pcode>>pname>>price>>discount;
		}
	}
	data.close();
	data1.close();
	
	remove("database.txt");
	rename("database1.txt","database.txt");
	
	if(token==0)
	{
		cout<<"\n\n\t\t Sorry! Record Not Found\n";
	}
}

void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\n\t\t\t________________________________________________";
	cout<<"\n\t\t\t\t   Delete Product";
	cout<<"\n\t\t\t________________________________________________";
	cout<<"\n\t\t\t\t\t\t Product Code : ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\t\t\tFile Doesn't Exist !\n";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>discount;
		
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\t\t\t Product Deleted Successfully\n";
				token++;
			}
			else
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
			}
			data>>pcode>>pname>>price>>discount;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n\t\t\t Record Not Found\n";
		}
	}
}

void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n\t\t|______________________________________________________________________________|\n";
	cout<<"\t\t   Product Number \t|\t   Product Name \t|\t    Price \n";
	cout<<"\n\n\t\t|______________________________________________________________________________|\n";
	data>>pcode>>pname>>price>>discount;
	while(!data.eof())
	{
		cout<<"\t\t\t"<<pcode<<"\t\t|\t\t"<<pname<<"\t\t|\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>discount;	
	}
	data.close();
}

void shopping::receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"\n\n\t\t\t\t\t\t RECEIPT";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\t\t\t Empty Database";
	}
	else
	{
		data.close();
		list();
		cout<<"\n\t\t\t\t____________________________________________________\n";
		cout<<"\n\t\t\t\t\t\t                                       \n";
		cout<<"\n\t\t\t\t\t   Please Place the Order        ";
		cout<<"\n\t\t\t\t\t\t                                       \n";
		cout<<"\n\t\t\t\t____________________________________________________\n";
		
		do
		{
			m:
			cout<<"\n\t\t\t\t\t\t Enter Product Code :";
			cin>>arrc[c];
			cout<<"\n\t\t\t\t\t\t Enter the Product Quantity :";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\t\t\t\t\t\t Duplicate Product Code. Please try again!";
					goto m;
				}
			}
			c++;
			cout<<"\n\t\t\t\t\t\t Do you want to buy another product? if yes then y else n :  ";
			cin>>choice;
		}
		while(choice=='y');
	
		cout<<"\n\t\t\t\t\t\t______________RECEIPT_______________\n";
		cout<<"\n\tProduct No. \t\t Product Name \t\t Quantity \t\t Price \t\t Amount \t\t Amount With Discount \n";
	
		for(int i=0;i<c;i++)
		{
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof())
			{
				if(pcode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n\t\t"<<pcode<<"\t\t\t"<<pname<<"\t\t\t"<<arrq[i]<<"\t\t   "<<price<<"\t\t   "<<amount<<"  \t\t"<<dis;
				}
				data>>pcode>>pname>>price>>dis;
			}
		}
		data.close();
	}
	cout<<"\n\t\t\t_________________________________\n";
	cout<<"\n\t\t\t\t\t\t\t     Total Amount :    "<<total;
}

int main()
{
	shopping s;
	s.menu();
}
