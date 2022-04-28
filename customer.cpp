/// customer 
#include <iostream>
#include <fstream>       // for file handling
#include <sstream>       // for string tokenizing
#include<iomanip>
using namespace std;


void Menu4()
{
	system("CLS");
    cout<<" ||****************************|| "<<endl;
    cout<<" ||----------------------------||"<<endl;
    cout<<" || WELCOME TO YOUR E-PHARMACY ||"<<endl;
    cout<<" ||----------------------------||"<<endl;
    cout<<" ||****************************||"<<endl;
	cout<<endl;
	cout<<" *******************************"<<endl;
	cout<<" -------------------------------"<<endl;
	cout<<"  Press 1 for medicine details.  "<<endl;
	cout<<"  Press 2 for buying medicines.  "<<endl;
	cout<<" -------------------------------"<<endl;
	cout<<" *******************************"<<endl;
}


int main()
{
	Menu4();
    int choice = 0;
    int choice2= 0;
    if(choice == 1 )
    {
    	displayallMedicines();
	}
   else if(choice== 2)
   { 
      do
      {
          system("CLS");
          displayallMedicines();
          cout<<" Again Press 2 for buying medicine :  "
          cin>>choice2;
      }
      while( choice2== 2)
      {  
    	 system("CLS");
    	 string cname;
    	 int cquantity;
    	 string cpaidAmount;
    	 cout<<" Enter details for the medicine to buy : "<<endl;
    	 cout<<" --------------------------------------  "<<endl;
    	 cout<<endl;
    	 cout<<" Enter your name : ";
    	 cin>>cname;
    	 cout<<endl;
    	 cout<<" Enter medicine name : ";
    	 cin>>medicineName;
    	 cout<<endl;
    	 cout<<" Enter quantity : ";
    	 cin>>cquantity;
    	 system("CLS");
    	 float total= cquantity*price;
    	 cout<<" Total bill is : "<<total;
    	 cout<<endl;
    	 cout<<" Enter paid amount : ";
    	 cin>>cpaidAmount;
    	 cout<<endl;
    	 total=total-cpaidAmount;
    	 cout<<" Change is : "<<total<<endl;
    	cout<<" _____________________________________"<<endl;
    	cout<<" _____________________________________"<<endl;
    	cout<<"||                                   ||"<<endl;
    	cout<<"||   *** THANK YOU FOR VISITING ***  ||"<<endl;
    	cout<<"||                                   ||"<<endl;
    	cout<<" _____________________________________"<<endl;
    	cout<<" _____________________________________"<<endl;

	}
}
	else 
	{
		cout<<" ******* INCORRECT OPTION ******* "<<endl;
	
	}
}

