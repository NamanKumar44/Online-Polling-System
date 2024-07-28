#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    int option;
    cout << "________Online Election Polling_________" << endl;
    cout << "________________India____________________" << endl;
    cout << "1-Create an Account" << endl;
    cout << "2-Already an Existing Account" << endl;
    cin >> option;
    ifstream ifile;
    ofstream ofile;
    ofstream ofile1;
    ifstream ifile1;
    if (option == 1)
    {
        label1:
        	while (getchar() != '\n'){}
        	cout << "Enter your Voter ID - \n";
        	string id;
        	cin >> id;
        	ifile.open("Data.txt");
        	ofile.open("Data.txt", std::ios::app);
        	string line;
        	cout << "Verification is in process - \n";
        	bool accountExists = false; // Flag to check if account already exists
        	while (getline(ifile, line))
        	{
           		if (line == id)
           		{
                	accountExists = true;
					break;
            	}
        	}
        	ifile.close();
        	if (accountExists)
        	{
            	cout << "Account already exists\n";
            	goto label;
        	}
        	cout << "Verified \n";
        	cout << "Enter your Password \n";
        	ofile << id << "\n";
        	ofile.close();
        	string pass;
        	cin >> pass;
        	ofile1.open("Pass.txt", std::ios::app);
        	ofile1<< pass << "\n";
        	ofile1.close();
        	cout << "Your account is created!!\n";
        	cout<<"Going to Login Page\n";
        	goto label;
    }
    else
    {
        label:
        cout << "Enter Voter ID -";
        string id;
        string line;
        cin >> id;
        ifile.open("Data.txt"); // Open the file for reading
        bool accountExists = false;
        while (getline(ifile, line))
        {
            if (line == id)
            {
                accountExists=true;
                break;
            }
        }
        if (accountExists==false)
        {
        	cout<<"Account doesn't Exist\n";
        	cout<<"Going to Create a new one\n";
        	goto label1;
		}
        ifile.close(); // Close the file after reading
        cout << "Enter password - \n";
        bool accountExists1 = false;
        int flag=0;
        while(flag<3){
		string pass;
        cin >> pass;
        ifile1.open("Pass.txt"); // Open the file for reading
        while (getline(ifile1, line))
        {
            if (line == pass)
            {
                accountExists1=true;
                break;
            }
        }
        if (accountExists1==false)
        {
        	cout<<"Incorrect Password\nTry again\n";
		}
		flag=flag+1;
		}
		if (flag==3)
		{
			cout<<"Try again after an hour";
		}
        ifile1.close(); // Close the file after reading
        cout << "You are allowed to vote\n";
        exit(0);
    }
    return 0;
}

