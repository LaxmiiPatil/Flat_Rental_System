#include<iostream>
#include<fstream>

using namespace std; 

class Purchase
{
	private:
		int fcode;
		float price=0.0;
		char dis;
		string fname;
		
		public:
			
		   void options();
		   void owner();
		   void buyer();
		   void add();
		   void rem();
		   void edit();
		   void list();
		   void receipt();
		   void menu();
		   void Purchasing();
		   
};

void Purchase :: menu()
{
    m:
	int choice;
	string email;
	string password;
	
	cout<<"\n\t\t\t\t*************************************************************\n";
	cout<<"\t\t\t\t                                                            \n";
    cout<<"\t\t\t\t                  WELCOME TO  VISTA RESIDENCY                \n";
    cout<<"\t\t\t\t                                                             \n";
	cout<<"\t\t\t\t*************************************************************\n";
	cout<<"\t\t\t\t                                                             \n";
    cout<<"\t\t\t\t|                        1)Owner                            |\n";
    cout<<"\t\t\t\t|                                                           |\n";
    cout<<"\t\t\t\t|                        2)Buyer                            |\n";
    cout<<"\t\t\t\t|                                                           |\n";
    cout<<"\t\t\t\t|                        3)Exit                             |\n";
    cout<<"\t\t\t\t|                                                           |\n";
    cout<<"\n\t\t\t\t                 Please Select One Option!                     ";
    cin>>choice;

    switch(choice)
	{
		case 1:
			cout<<"\n Please Login -->\n";
			cout<<"\n Enter your Email: \n";
			cin>>email;
			cout<<"\n Enter password: \n";
			cin>>password;
			
			if(email=="jack@gmail.com" && password=="jack123")
			{
				owner();
			}
			else
			{
				cout<<"Invalid Email or password!!\t\t\t";
			}
    	    break;
    	    
    	case 2:
    		{
    		   buyer();	
    		   
			}
			
	    case 3:
	    	{
	    		exit(0);
	    	
			}
			
			default :
				{
					cout<<"Please select from the given option!!";
				}
	}
	goto m;
}

void Purchase:: owner()
{
	m:  
	int choice;
	cout<<"\n\n\n\n\n\tOwner's Menu";
	cout<<"\n|                             |";
	cout<<"\n|     1)Add Empty Flats       |";
	cout<<"\n|                             |";
	cout<<"\n|     2)Modify Flats          |";
	cout<<"\n|                             |";
	cout<<"\n|     3)Delete taken Flats    |";
	cout<<"\n|                             |";
	cout<<"\n|     4)Back to Main Menu     |";
	cout<<"\n|                             |";
	
	cout<<"\n\n Please enter your choice: ";
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
			
		default :
			cout<<"Invalid Choice!!";
	}
    goto m;

}

void Purchase:: buyer()
{
	m:
	int choice;
	int availableFlats = 0;
	int numOfFlats;
	char choice2;


	cout<<"\n\n\n\n\tBuyer's Menu";
	cout<<"\n|                             |";
	cout<<"\n|     1)Buy Flat              |";
	cout<<"\n|                             |";
	cout<<"\n|     2)Go back To Menu       |";
	cout<<"\n|                             |";
	
	cout<<"\n\nEnter your choice:";
	cin>>choice;
    do
    {
	
    int availableFlats = 0;
    ifstream data("database.txt");
    string line;

    while (getline(data, line)) {
        availableFlats++;
    }
    data.close();

    int numOfFlats;

    cout << "\n\nEnter the number of flats you want to buy: ";
    cin >> numOfFlats;

    if (numOfFlats <= 0) {
        cout << "\nInvalid number of flats!";
        buyer(); 
        return;
    }

    if (numOfFlats > availableFlats) {
        cout << "\nSorry, there are only " << availableFlats << " flats available.";
        
    }
}while(numOfFlats==availableFlats);

     cout << "\n\nDo you want to proceed further? Press 'y' to continue or 0 to exit: ";
     cin >> choice2;

     if (choice2 == 'y') {
    cout << "\n\nYou chose to proceed further. Continue with the program...\n";
} else if (choice2 == '0') {
    cout << "Back to the menu...\n";
    menu(); 
}

    switch(choice)
	{
		case 1:
			receipt();
			break;
			
		case 2:
			menu();
			break;
			
		default:
			cout<<"Invalid Choice!!";
	}
	goto m;
}

void Purchase ::add()
{
	m:
	fstream data;
	int c;
	int token = 0;
	float p;
	float d;
	string n;
	
	cout<<"\n\n Add New Flat";
	cout<<"\n\n          ";
	cout<<"\n\n Flat Number: ";
	cin>>fcode;
	cout<<"\n\n Type of the Flat: ";
	cin>>fname;
	cout<<"\n\n Price of the Flat: ";
	cin>>price;
	cout<<"\n\n Discount on the Flat: ";
	cin>>dis;

    data.open("database.txt",ios::out);
    
    if(!data)
    {
    	data.open("database.txt",ios::app|ios::out);
    	data<<" "<<fcode<<" "<<fname<<" "<<price<<" "<<dis<<"\n";
    	data.close();
    
	}
	else
	{
	
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c ==fcode)
			{
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}

	if(token==1)
	goto m;
	else
	{
		data.open("database.txt",ios::app|ios::out);
    	data<<" "<<fcode<<" "<<fname<<" "<<price<<" "<<dis<<"\n";
    	data.close();
	}
    cout<<"\n\n\t\t Record Inserted!!";
}

void Purchase:: edit()
{
	fstream data,data1;
	int fkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\t\t\t Modify Flats";
	cout<<"\n\t\t\t Flat Number:";
	cin>>fkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nFile doesn't exist!!";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		
		data1>>fcode>>fname>>price>>dis;
		while(!data1.eof())
		{
			if(fkey==fcode)
			{
				cout<<"\n\t\t Flat new number:";
				cin>>c;
				cout<<"\n\t\t Type of the Flat:";
				cin>>n;
				cout<<"\n\t\t Price:";
				cin>>p;
				cout<<"\n\t\t Discount:";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"\n\t\t\t Record edited!!";
				token++;
			}
			else
			{
			    data1<<" "<<fcode<<" "<<fname<<" "<<price<<" "<<dis<<"\n";

			}
			data1>>fcode>>fname>>price>>dis;
		}
		data.close();
		data1.close();
		 
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found sorry!!";
		}
	}
	
}

void Purchase::rem()
{
	fstream data,data1;
	int fkey;
	int token=0;
	cout<<"\n\n\t\t Remove Flat";
	cout<<"\n\n\t\t Flat Number: ";
	cin>>fkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"File doesn't exist";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
	    data>>fcode>>fname>>price>>dis;
	    while(!data.eof())
	    {
	    	if(fcode==fkey)
	    	{
	    		cout<<"\n\n\t Flat record deleted successfully";
	    		token++;
			}
			else
			{
				data1<<" "<<fcode<<" "<<fname<<" "<<price<<" "<<dis<<"\n";

			}
			data>>fcode>>fname>>price>>dis;

		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0)
		{
			cout<<"\n\n Record not found!";
		}
		
	}
}

void Purchase:: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|**************************LIST******************************|\n";
	cout<<"\nFlatNo\t\tType\t\tPrice\n";
	cout<<"\n|**********************************************************|\n";
	data>>fcode>>fname>>price>>dis;
	while(!data.eof())
	{
		cout<<fcode<<"\t\t\t"<<fname<<"\t\t\t"<<price<<"\n";
	    data>>fcode>>fname>>price>>dis;
	}
	data.close();
		
}

void Purchase::receipt() {
    m:
	fstream data;
	int y;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	int count=0;
	float amount=0;
	float dis=0;
	float total=0;
	int flag=0;
    int availableFlats;
    int validflats;
    ifstream data2("database.txt");
    string line;

    while (getline(data2, line)) {
        availableFlats++;
    }
    data2.close();

    cout << "\n\n\t\t\t  ";
    data.open("database.txt", ios::in);
    if (!data) {
        cout << "\n\n Empty Database";
    } else {
        data.close();

        list();
        cout << "\n\n\n";
        cout << "|********************************************************|\n";
        cout << "                                                             \n";
        cout << "            Please Select a Flat to Buy                    \n";
        cout << "                                                             \n";
        cout << "|********************************************************|\n";

        int numOfFlats;
        cout << "\n\nEnter the number of flats you want to buy: ";
        cin >> numOfFlats;

        if (numOfFlats <= 0 || numOfFlats > availableFlats) {
            cout << "\nInvalid number of flats!";
            buyer();
            return;
        } else {
            int arrq[100];
            int validFlats = 0;

            for (int i = 0; i < numOfFlats; i++) {
                cout << "\n\n Enter Number of Flat " << i + 1 << ": ";
                cin >> arrq[i];
                bool exists = false;

                ifstream checkData("database.txt");
                int flatCode;
                while (checkData >> flatCode) {
                    if (flatCode == arrq[i]) {
                        exists = true;
                        break;
                    }
                }
                checkData.close();

                if (fcode!= availableFlats) {
                    cout << "\nFlat " << arrq[i] << " doesn't exist!" << endl;
                    return; // Exit the program
                } else {
                    validFlats++;
                }
            }

            if (validFlats == numOfFlats) {
                // Proceed with the receipt
                	cout<<"\n";
		cout<<"\n\n************************************RECEIPT*****************************************\n";
		cout<<"\nFlat No\t   Flat type\t Number of flats\t Price\t   Amount\t    Amount with discount\n";
		
		for(int i=0; i<availableFlats; i++)
		{
			data.open("database.txt",ios::in);
			data>>fcode>>fname>>price>>dis;
			while(!data.eof())
			{
				if(fcode==arrq[i])
				{
					
				    amount+=price;
				    dis=amount-(amount*dis/100);
				    total=total+dis;
				    cout<<"\n"<<fcode<<"\t\t"<<fname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
	
				}
				data>>fcode>>fname>>price>>dis;

			}
			data.close();

		}
		cout<<"\n\n******************************************************************************";
		cout<<"\n\n Total Amount : "<<total;
                // ... (rest of the code for the receipt)
            }else if(fcode!=availableFlats){
            	cout<<"File doesnt exist!!";
			}
        }
    }
}


int main()
{
	Purchase A;
	A.menu();
}
