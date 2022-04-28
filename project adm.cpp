#include <iostream>
#include <fstream>       // for file handling
#include <sstream>       // for string tokenizing
#include<iomanip>
using namespace std;
// 1). Medicine ID
// 2). Medicine Name
// 3). Price
// 4). Manufacture company
// 5). Manufacture date
// 6). Expiry date
// 7). Quantity



// 1. Header file mein jo <sstream> use kiya hai for string tokenizing. Wo kahan pe use ho rahi hai
// 2. System("CLS") kis liye use kiya haii?
// 3.  using namespace std  ko Agar header mein hi globally declare kar den, to baar baar std::cout nahi likhna parta? Just cout likhen gy? Same for the (std:: string details) ko sirf (string details) likhen ge?
// 4. Medicine list ko file handling k through hi change krenge ? Apne according.
// 5. Username or password mein apne names likhny hain. 
// 6. Ab hum ne customer ka banana hai khud. Tw usy merge kesy kren ge like abhi to press 1 for administrator tha na. Press 2 for customer. Administrator k baad kya code likhen ge. Bas guide kar den


// 1). sstream is used for tokenizing the string for example you have one string (hello,world) and you want to put hello in one string and world in another string then for this purpose sstream is used;

//2).System("CLS") is used for clearing the console screen .If something is written on the screen and you want to empty it then it is used.

//3).I have removed the std and wrote usingnamespace std at the top instead of it and same goes for std::string

//4.There are two methods for changing the medicine list 

// a)Through code .Go in the menu  and select the update or insert new medicine and the list is changed.

// b).Explicitly go in the file and add a new row for the medicine but keep in mind the format , first write new medicine id then name write comma after each property name  the format is medicineID,name,price,manufacturingcompany,date,expirydate,quantity and write comma after every property;

//5.Just go in admin file and i have commented where you should write your name and password so write there.


struct Medicine
{
    int medicineID;
    char medicineName[30];
    float Price;
    char manufactureCompany[30];
    char manufactureDate;
    char expiryDate;
    int Quantity;
};

void displaymedicineDetails(string details)
{
	
    // This function is used for clearing the output console from the previous written ouput on the console
	system("CLS");


    stringstream ss(details); //convert my_string into string stream

    string temp_str;

    int index = 1;

    cout << "The medicine details are :" << std::endl;

    cout << "-------------------------------------" << std::endl;

    while (std::getline(ss, temp_str, ','))
    {
        if (index == 1)
        {
            cout << "Medicine ID : " << temp_str << std::endl;
        }
        if (index == 2)
        {
            cout << "Medicine Name : " << temp_str << std::endl;
        }
        if (index == 3)
        {
            cout << "Medicine Price : " << temp_str << std::endl;
        }
        if (index == 4)
        {
            cout << "Medicine Company : " << temp_str << std::endl;
        }
        if (index == 5)
        {
            cout << "Medicine Manufacture Date : " << temp_str << std::endl;
        }
        if (index == 6)
        {
            cout << "Medicine Expiry Date  : " << temp_str << std::endl;
        }
        if (index == 7)
        {
            cout << "Quantity : " << temp_str << std::endl;
        }
        index = index + 1;
    }

    cout << "----------------------------------" << std::endl;
}

void displayallMedicines()
{
	system("CLS");
   
    string *List=new string[100];            // This array of string keeps information of all the medicines
	
	// File reading object
    std::ifstream myfileRead;

    // Opening the file for reading
    myfileRead.open("medicine.txt");

    
    int total=0;
    
    
    // Loading all the medicine data from the file
    while (getline(myfileRead, List[total]))
    {
        total=total+1;
    }
    
	myfileRead.close();
	
	
	cout<<"   ID      "<<"       NAME     "<<"            PRICE      "<<"            Company     "<<"          Expiry-Date    "<<std::endl;
	
	for(int k=0;k<total;k++)
	{
		if(k!=0)
		{
			
		   stringstream ss(List[k]);  // convert my_string into string stream
		
    	   string Temp[10];
    	   int j=0;
    	   while (std::getline(ss,Temp[j], ','))
           {
			   j=j+1;    
           }
        
        
	       // Displaying all the medicines on the screen
	   
           cout << std::setw(5) <<Temp[0];              // Displaying ID
        
           cout<<std::setw(20) <<Temp[1]<<"        ";              // Displaying Name
        
           cout<<std::setw(7) <<Temp[2]<<"        ";              // Displaying Price
        
           cout<<std::setw(20) <<Temp[3]<<"        ";              // Displaying Company
        
           cout<<std::setw(20) <<Temp[5]<<"        ";              // Displaying Expiry Date
        
           cout<<std::endl;
        
		}
		
	}
	
	
	
}

void displayDetails(string medicineName)
{
    // File reading object
    std::ifstream myfileRead;

    // Opening the file for reading
    myfileRead.open("medicine.txt");

    string myText;

    int line = 1;

    int found=0;
    
    while (getline(myfileRead, myText))
    {
        // Discard first line of the admin.txt file
        if (line != 1 && myText.length() >= 4)
        {
            int i;
            for (i = 2; myText[i] != ','; i++)
                ;

            string Name = myText.substr(2, i - 2);

            if (medicineName == Name)
            {
                displaymedicineDetails(myText);

                found = 1;
            }
        }

        line = line + 1;
    }

    if (found == 0)
    {
        cout << "This medicine is not present " << std::endl;
    }
  
}

int checkAuthentication(string userName1, string Password1)
{

    // File reading object
    std::ifstream myfileRead;

    // Opening the file for reading
    myfileRead.open("admin.txt");

    string myText;

    int line = 1;

    int login = 0;

    // read line by line from the admin.txt file and check if the admin entered password and username matches with the file data or not
    // if it does not matches then return false else wise true

    while (getline(myfileRead, myText))
    {
        // Discard first line of the admin.txt file
        if (line != 1)
        {
            int pos = myText.find(",");
            string userName = myText.substr(0, pos);

            string Password = myText.substr(pos + 1, myText.length() - 1);

            // checking if the username and password matches with the file data
            if (userName1 == userName && Password1 == Password)
            {
                // if yes then return true;
                login = 1;
                return login;
            }
        }

        line = line + 1;
    }
    return login;
}
void addMedicine()
{
	int medicineId;
	cout<<"Enter medicine id : ";
	std::cin>>medicineId;
	
	string medicineName;
    cout<<"Enter medicine name : ";
    std::cin>>medicineName;
    
    float price;
    cout<<"Enter price : ";
    std::cin>>price;
    
    string medicineCompany;
    cout<<"Enter manufacturing company : ";
    std::cin>>medicineCompany;
    
    string manufactureDate;
    cout<<"Enter manufacture date (DATE, MONTH ,YEAR) : ";
    std::cin>>manufactureDate;
    
    string expiryDate;
    cout<<"Enter expiry date (DATE, MONTH ,YEAR) : ";
    std::cin>>expiryDate;
    
    
    int quantity;
    cout<<"Enter quantity : ";
    std::cin>>quantity;
    
    std::ofstream appendMedicine;
    
    appendMedicine.open("medicine.txt",std::ios::app);
    
    appendMedicine<<medicineId<<",";
    
    appendMedicine<<medicineName<<",";
    
    appendMedicine<<price<<",";
    
    appendMedicine<<medicineCompany<<",";
    
    appendMedicine<<manufactureDate<<",";
    
    appendMedicine<<expiryDate<<",";
    
    appendMedicine<<quantity<<","<<std::endl;
    
    // closing file
    appendMedicine.close();
    
    displayallMedicines();
    
}

void deleteMedicine(string Id,string medicineName)
{
	string *List=new string[20];       // This array of string keeps information of all the medicines
	
	// File reading object
    std::ifstream myfileRead;

    // Opening the file for reading
    myfileRead.open("medicine.txt");

    
    int total=0;
    while (getline(myfileRead, List[total]))
    {
        total=total+1;
    }
    
	myfileRead.close();
    
    int index=-1;
    for(int k=0;k<total;k++)
    {
    	
    	if (List[k].find(medicineName) != string::npos) 
		{
            index=k;
            break;
        }
	}
	if(index==-1)
	{
		cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxx "<<std::endl;
		cout<<"This medicine is not present "<<std::endl;
		cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxx "<<std::endl;
	}
	else
	{
		std::ofstream appendMedicine;
		appendMedicine.open("medicine.txt");
		for(int k=0;k<total;k++)
        {
    	   if(k!=index)
    	   {
    	   	   appendMedicine<<List[k]<<std::endl;
		   }
	    }
	cout<<"------------------------------"<<std::endl;
	cout<<"Medicine removed successfully "<<std::endl;
	cout<<"------------------------------"<<std::endl;	
	displayallMedicines();
	}
	displayallMedicines();
}

void changePrice()
{
	system("CLS");
   cout<<"Enter medicine name : ";
   string medicineName;
   std::cin>>medicineName;

   
    // Loading all the medicine data from the file
    string *List=new string[20];            // This array of string keeps information of all the medicines
	
	// File reading object
    std::ifstream myfileRead;

    // Opening the file for reading
    myfileRead.open("medicine.txt");

    
    int total=0;
    while (getline(myfileRead, List[total]))
    {
        total=total+1;
    }
    
	myfileRead.close();
	
	int index=-1;
	
	// Checking if that medicine is present
    for(int k=0;k<total;k++)
    {
    	
    	if (List[k].find(medicineName) != string::npos) 
		{
            index=k;
            break;
        }
	}
	
	// If the medicine is not present then display this part
	if(index==-1)
	{
		cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxx "<<std::endl;
		cout<<"This medicine is not present "<<std::endl;
		cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxx "<<std::endl;
	}
	else
	{
		string price;
		cout<<"Enter new price of the medicine : ";
		std::cin>>price;
		
		// Opening file for writing
		std::ofstream appendMedicine;
		appendMedicine.open("medicine.txt");
		
		
		// Writing back to the file
		for(int k=0;k<total;k++)
        {
    	   if(k==index)
    	   {
    	   	  stringstream ss(List[k]);  // convert my_string into string stream
    	   	  
    	   	  string Temp[10];
    	   	  int j=0;
    	   	  while (std::getline(ss,Temp[j], ','))
              {
			     j=j+1;    
    	      }
    	      
    	      for(int q=0;q<j;q++)
    	      {
    	      	if(q==2)
    	      	{
    	      	   appendMedicine<<price<<",";
				}
				else
				{
					if(q!=6)
					{
				 	    appendMedicine<<Temp[q]<<",";
				    }
				    else
				    {
					    appendMedicine<<Temp[q];
					}
				}
			  }
              appendMedicine<<std::endl;
		   }
		   else
		   {
		     appendMedicine<<List[k]<<std::endl;
	       }
	    }
	    
	cout<<"-------------------------------------"<<std::endl;
	cout<<"Medicine Price updated successfully  "<<std::endl;
	cout<<"-------------------------------------"<<std::endl;	
	}
	
}

void changeQuantity()
{
	system("CLS");
    cout<<"Enter medicine name : ";
    string medicineName;
    std::cin>>medicineName;

   
    string *List=new string[20];            // This array of string keeps information of all the medicines
	
	// File reading object
    std::ifstream myfileRead;

    // Opening the file for reading
    myfileRead.open("medicine.txt");

    
    int total=0;
    
    
    // Loading all the medicine data from the file
    while (getline(myfileRead, List[total]))
    {
        total=total+1;
    }
    
	myfileRead.close();
	
	int index=-1;
	
	// Checking if that medicine is present
    for(int k=0;k<total;k++)
    {
    	
    	if (List[k].find(medicineName) != string::npos) 
		{
            index=k;
            break;
        }
	}
	
	// If the medicine is not present then display this part
	if(index==-1)
	{
		cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxx "<<std::endl;
		cout<<"This medicine is not present "<<std::endl;
		cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxx "<<std::endl;
	}
	else
	{
		string quantity;
		cout<<"Enter new quantity of the medicine : ";
		std::cin>>quantity;
		
		// Opening file for writing
		std::ofstream appendMedicine;
		appendMedicine.open("medicine.txt");
		
		
		// Writing back to the file
		for(int k=0;k<total;k++)
        {
    	   if(k==index)
    	   {
    	   	  stringstream ss(List[k]);  // convert my_string into string stream
    	   	  
    	   	  string Temp[10];
    	   	  int j=0;
    	   	  while (std::getline(ss,Temp[j], ','))
              {
			     j=j+1;    
    	      }
    	      
    	      for(int q=0;q<j;q++)
    	      {
    	      	if(q==6)
    	      	{
    	      	   appendMedicine<<quantity;
				}
				else
				{
					appendMedicine<<Temp[q]<<",";
				}
			  }
              appendMedicine<<std::endl;
		   }
		   else
		   {
		     appendMedicine<<List[k]<<std::endl;
	       }
	    }
	    
	cout<<"---------------------------------------"<<std::endl;
	cout<<"Medicine Quantity updated successfully |"<<std::endl;
	cout<<"---------------------------------------"<<std::endl;	
	}
}
void addBill()
{
	system("CLS");
	string customerName;
	string medicineName;
	string medicineID;
	string quantity;
	string subTotal;
	string paidAmount;
	string Change;
	
	cout<<"Enter customer Name : ";
	std::cin>>customerName;
	
	cout<<"Enter medicine ID : ";
	std::cin>>medicineID;
	
	cout<<"Enter medicine Name : ";
	std::cin>>medicineName;
	
	cout<<"Enter quantity : ";
	std::cin>>quantity;
	
	cout<<"Enter subtotal : ";
	std::cin>>subTotal;
	
	cout<<"Enter paid Amount : ";
	std::cin>>paidAmount;
	
	cout<<"Enter Change : ";
	
	std::cin>>Change;
	
	
	
	
}
void Menu1()
{
    cout << " ----------- OPTIONS -----------" << std::endl;
    cout << "| Press 1 for admisintrator     |" << std::endl;
    cout << "| Press 2 for customer          |" << std::endl;
    cout << "| Press 3 for exit              |" << std::endl;
    cout << " -------------------------------" << std::endl;
}

void Menu2()
{
    cout << "------------- Options -------------" << std::endl;
    cout<<"| Press 1 for search medicine        |" << std::endl;
    cout<<"| Press 2 for add medicine           |" << std::endl;
    cout<<"| Press 3 for remove medicine        |" << std::endl;
    cout<<"| Press 4 for update medicine data   |" << std::endl;
    cout<<"| Press 5 for add bill               |" << std::endl;
    cout<<"| Press 6 for checking all medicines |"<< std::endl;
    cout<<"| Press 7 to exit                    |"<<std::endl;
    cout<<" ----------------------------------- "<<std::endl;
}

void Menu3()
{
	cout<<"  --------------Options---------"<<std::endl;
    cout<<"| Press 1 for change in price    |"<<std::endl;
    cout<<"| Press 2 for change in quantity |"<<std::endl;
    cout<<" -------------------------------"<<std::endl;
            	
}


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

void buyMedicine()
{
	system("CLS");
	
    string customerName;
    std::string medicineName;
    
    int quantity;
    
    int paidAmount;
    std::cout<<"--------------------------------------"<<std::endl;
    cout<<" Enter details for the medicine to buy : "<<endl;
	std::cout<<" --------------------------------------  "<<endl;
	
	
	cout<<" Enter your name : ";          // Customer Name
	cin>>customerName;
	
	cout<<" Enter medicine name : ";        // Medicine Name
	cin>>medicineName;
	

	cout<<" Enter quantity : ";          // Quantity
	cin>>quantity;
	
	system("CLS");                      // Clearing the screen
	
	// File handling to get the price of the medicine
	
	int medicinePrices[50]={0,150,400,1200,100,120,85,2400,5053,170,37,100,6040,120,120};
	
	
	
	// Loading all the medicine data from the file
    string *List=new string[20];                    // This array of string keeps information of all the medicines
	
	// File reading object
    std::ifstream myfileRead;

    // Opening the file for reading
    myfileRead.open("medicine.txt");

    
    int total1=0;
    while (getline(myfileRead, List[total1]))
    {
        total1=total1+1;
    }
    
	myfileRead.close();
	
	int index=-1;
	
	// Checking if that medicine is present
    for(int k=0;k<total1;k++)
    {
    	
    	if (List[k].find(medicineName) != string::npos) 
		{
            index=k;
            break;
        }
	}
	
	
	float price=medicinePrices[index];
	
	std::cout<<"----------------------------"<<std::endl;
	std::cout<<"This medicine price is : "<<price<<std::endl;
	std::cout<<"----------------------------"<<std::endl;
	
	
	float total= quantity*price;
	
	cout<<" Total bill is : "<<total<<std::endl;
	
	cout<<" Enter paid amount : ";
	cin>>paidAmount;
	
	total=paidAmount-total;
	
	cout<<" Change is : "<<total<<endl;
	cout<<" _____________________________________"<<endl;
	cout<<" _____________________________________"<<endl;
	cout<<"||                                   ||"<<endl;
	cout<<"||   *** THANK YOU FOR VISITING ***  ||"<<endl;
	cout<<"||                                   ||"<<endl;
	cout<<" _____________________________________"<<endl;
	cout<<" _____________________________________"<<endl;

}

int main()
{
    int choice = 0;

    Menu1();

    // Getting input
    cout << "Choice : ";
    std::cin >> choice;

    if (choice == 1)
    {
        system("CLS");
        // Getting the username as input
        string userName;
        cout << "Enter username : ";

        // getline(std::cin,userName);
        std::cin >> userName;

        // Getting the password as input
        string Password;
        cout << "Enter password : ";

        // getline(std::cin, Password);
        std::cin >> Password;


        // This function check if the password and username entered is correct or incorrect
        int check = checkAuthentication(userName, Password);


        if (check)
        {
            // For clearing the screen
            
            above:
			system("CLS");
		
            
            Menu2();
            int choice2;
            cout << "Choice : ";
            std::cin >> choice;
            
            string medicineName;
            string Id;
            int choice3;

            switch (choice)
            {
            case 1:

                cout << "Enter medicine name : ";
                std::cin >> medicineName;
                
                // Displaying details of that medicine
                displayDetails(medicineName);
            break;
                
            case 2:
            	system("CLS");
            	addMedicine();
            	
            break;
            
            case 3:
            	
            	cout<<"Enter medicine id to delete : ";
            	std::cin>>Id;
            	
            	cout<<"Enter medicine name to delete : ";
            	std::cin>>medicineName;
            	
            	deleteMedicine(Id,medicineName);
            break;
            
            case 4:
                
                system("CLS");
                
            	Menu3();
            	cout<<"Choice : ";
            	std::cin>>choice3;
            	
            	
            	switch(choice3)
            	{
            		case 1:
            			
            			changePrice();
            		
            		break;
            		
            		case 2:
            			
            			changeQuantity();
            			
            		break;
				}
				
			
            break;
            
            case 5:
            	
            	addBill();
            	
            break;
            
            case 6:
            	
            	displayallMedicines();
            	
            break;
            
            case 7:
            	
            	goto above;
            	
            break;
            	
            }
        }
    
//        If incorrect username and password is entered then come in else block
        else
        {
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx " << std::endl;
            cout << "Incorrect username or password " << std::endl;
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx " << std::endl;
        }
    }
    else if(choice==2)
    {
    	Menu4();
    	int choice;
    	std::cout<<"Choose : ";
    	std::cin>>choice;
    	
    	switch(choice)
    	{
    		case 1:
    			
    			displayallMedicines();
    			
    		break;
    		
    		case 2:
    			displayallMedicines();
    			
    			std::cout<<"------------------------------------------------------------------------------------------------------------------------"<<std::endl;
    			std::cout<<"Again press 2 for buying medicine "<<std::endl;
    			std::cout<<"Choice : ";
    			std::cin>>choice;
    			switch(choice)
    			{
    				case 2:
    					
    					buyMedicine();
    				break;
    				
    				default:
    					
    	                cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx " << std::endl;
                        cout << "Incorrect option selected " << std::endl;
                        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx " << std::endl;
    					
    				break;
				}
    			
    			
		}
	}
  
    else
    {
    	cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx " << std::endl;
        cout << "Incorrect option selected " << std::endl;
        cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx " << std::endl;
    }
}
