#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

// Main Code for Party Details

class Party 
{
protected:
    string name;
    int voteCount;

public:
    Party(const string& partyName) : name(partyName), voteCount(0) {}

    string getName() const 
    {
        return name;
    }

    int getVoteCount() const 
    {
        return voteCount;
    }

    void incrementVoteCount() 
    {
        voteCount++;
    }
};
class PollingSystem {
private:
    vector<Party*> parties;

public:
    PollingSystem(const vector<string>& partyNames) 
    {
        for (const auto& name : partyNames) 
        {
            Party* party = new Party(name);
            parties.push_back(party);
        }
    }

    void castVote(const string& partyName) 
    {
        Party* party = findParty(partyName);
        if (party) 
        {
            party->incrementVoteCount();
            cout << "Vote casted successfully!\n";
        } 
        else 
        {
            cout << "Party does not exist!\n";
        }
    }

    Party* findParty(const string& partyName) 
    {
        for (const auto& party : parties) 
        {
            if (party->getName() == partyName) 
            {
                return party;
            }
        }
        return nullptr;
    }

    void displayPartyNames() 
    {
        cout << "Party Names:\n";
        cout << "-----------------\n";

        for (const auto& party : parties) 
        {
            cout << party->getName() << "\n";
        }

        cout << "-----------------\n";
    }
};


int main()
{
    label12:
    int option;
    cout << "________Online Election Polling_________" << endl;
    cout << "________________India____________________" << endl;
    cout << "1-Create an Account" << endl;
    cout << "2-Already an Existing Account" << endl;
    cin >> option;

    // File handling

    ifstream ifile,ifile2;
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
        	string line,line9;
            cout << "Verification is in process - \n";
            ifile2.open("VoterData.txt");
            while (getline(ifile2, line9))
        	{
           		if (line9.compare(id)==0)
           		{
                	cout<<"Verified....\n";
                    ifile2.close();
                    goto label9;
            	}
        	}

            // It will check whether the entered voter id is in Voter Data.txt or not.

        	ifile2.close();
            cout<<"Invalid Voter ID....\n";
            goto label1;
            label9:
                ifile.open("Data.txt");
        	    ofile.open("Data.txt", std::ios::app);
        	    bool accountExists = false; // Flag to check if account already exists
        	    while (getline(ifile, line))
            	{
               		if (line.compare(id)==0)
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
                ofile << id << "\n";
                ofile.close();
                label0:
        	        cout << "Enter your Password \n";
        	        string pass;
                	cin >> pass;
                    string line1;
                    ifile1.open("Pass.txt"); // Open the file for reading
                    while (getline(ifile1, line1))
                    {
                        if (line1.compare(pass)==0)
                        {
                            cout<<"Password already taken \n"; //Checking whether the entered password is already in use 
                                                               // for some other account or not
                            ifile1.close();
                            goto label0;
                        }
                    }
                    ofile1.open("Pass.txt",std::ios::app);
                    ofile1<<pass<<endl;
                    ifile1.close();
        	        ofile1.close();
                	cout << "Your account is created!!\n";
                    cout<<"---------------\n";
                	cout<<"Going to Login Page\n"; // Redirecting to Login Page to Login
                    cout<<"...............\n";
        	        goto label;
    }
    else if (option==2)
    {
        label:
        cout << "Enter Voter ID -";
        string line;
        string id;
        cin >> id;
        int n1=0;
        ifile.open("Data.txt"); // Open the file for reading
        bool accountExists = false;
        while (getline(ifile, line))
        {
            n1=n1+1;
            if (line.compare(id)==0)
            {
                accountExists=true;  // Checking if Account already Exists or not
                break;
            }
        }
        if (accountExists==false)
        {
        	cout<<"Account doesn't Exist\n";
        	cout<<"Going to Create a new one\n"; // Redirecting to Create a new one
        	goto label1;
		}
        ifile.close(); // Close the file after reading
        bool accountExists1 = false;
        label4:
            int flag=0,n2=0;
            while(flag<3)
            {
                n2=0;
                cout << "Enter password - \n";
        		string pass;
                string line1;
                cin >> pass;
                ifile1.open("Pass.txt"); // Open the file for reading
                while (getline(ifile1, line1))
                {
                    n2=n2+1;
                    if (line1.compare(pass)==0)
                    {
                        accountExists1=true; //Checking if the entered password is correct or not
                        flag=4;
                        break;
                    }
                }
                ifile1.close();// Close the file after reading
                if (accountExists1==false)
                {
            	    cout<<"Incorrect Password\nTry again\n";
                    flag=flag+1;
	    	    }
		    }
            if ((n2!=n1 && n2!=0 && n1!=0)||flag==3)
            {
                if (flag!=3){cout<<"Incorrect Password\nTry again\n";}
                goto label4;
            }
    label3:
        ifstream ifile3;
        ofstream ofile3;
        cout << "You are allowed to vote\n";
        cout<<"Choose the Election u want - ";
        int n;
        cout<<"\n1.Central Election\n2.State Election\n3.Municipality Election\n4.Exit\n";
        cout<<"______________________________\n";
        cout<<"Enter the option - ";
        cin>>n;
        if (n==1)
        {
            vector<string> partyNames = {"BJP","INC","BSP","NCP","CPI","TMC"};  // Predefined party names

            PollingSystem PollingSystem(partyNames);

            int choice;

            while (true) 
            {
                label5:
                cout << "Central Polling System\n";
                cout << "----------------------\n";
                cout << "1. Cast Vote\n";
                cout << "2. Display Party Names\n";
                cout << "3. Display Results\n";
                cout << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;
                string line0;int a=0,b=0,c=0,d=0,e=0,f=0;
                switch (choice) 
                {
                    case 1: 
                    {
                        ifile.open("Central.txt");
                        ofile.open("Central.txt",std::ios::app);
                        string line1;
                        while(getline(ifile, line1))
                        {
                            if(line1.compare(id)==0)
                            {
                                cout<<"Already voted....\n"; //Checking if the person has already voted or not
                                ifile.close();
                                ofile.close();
                                goto label5;
                            }
                        }
                        ifile.close();
                        ofile<<id<<"\n";
                        ofile.close();
                        string partyName;
                        cout << "Enter party name: ";
                        cin.ignore();
                        getline(cin, partyName);
                        ofile3.open("Central Total.txt",std::ios::app); //Adding Party name to the file
                        ofile3<<partyName<<endl;
                        ofile3.close();
                        PollingSystem.castVote(partyName);
                        break;
                    }
                    case 2:
                        PollingSystem.displayPartyNames();
                        break;
                    case 3:
                        a=0;b=0;c=0;d=0;e=0;f=0;
                        cout << "Election Results:\n";
                        cout << "-----------------\n";
                        ifile3.open("Central Total.txt");
                        while(getline(ifile3, line0))
                        {
                            if(line0.compare("BJP")==0)
                            {
                                a=a+1;
                            }
                            else if (line0.compare("INC")==0)
                            {
                                b=b+1;
                            }
                            else if (line0.compare("BSP")==0)
                            {
                                c=c+1;
                            }
                            else if (line0.compare("NCP")==0)
                            {
                                d=d+1;
                            }
                            else if (line0.compare("CPI")==0)
                            {
                                e=e+1;
                            }
                            else if (line0.compare("TMC")==0)
                            {
                                f=f+1;
                            }
                        }

                        //Displaying total votes voted of all parties

                        cout<<"BJP"<<" - "<<a<<endl;
                        cout<<"INC"<<" - "<<b<<endl;
                        cout<<"BSP"<<" - "<<c<<endl;
                        cout<<"NCP"<<" - "<<d<<endl;
                        cout<<"CPI"<<" - "<<e<<endl;
                        cout<<"TMC"<<" - "<<f<<endl;
                        ifile3.close();
                        break;
                    case 4:
                        cout << "Going to main menu again .....\n";
                        cout << "----------------------\n";
                        goto label3;
                        break;
                    default:
                    cout << "Invalid choice!\n";
                }

                cout << "\n";
            }
        }
        else if (n==2)
        {
        	vector<string> partyNames = {"AIADMK","CPI","DMDK","DMK"};  // Predefined party names

            PollingSystem statePollingSystem(partyNames);

            int choice;

            while (true) 
            {
                label6:
                cout << "Tamil Nadu Polling System\n";
                cout << "----------------------\n";
                cout << "1. Cast Vote\n";
                cout << "2. Display Party Names\n";
                cout << "3. Display Results\n";
                cout << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;
                string line0;int a=0,b=0,c=0,d=0,e=0,f=0;
                switch (choice) 
                {
                    case 1: 
                    {
                        ifile.open("State.txt");
                        ofile.open("State.txt",std::ios::app);
                        string line2;
                        while(getline(ifile, line2))
                        {
                            if(line2.compare(id)==0)
                            {
                                cout<<"Already voted.....\n"; //Checking if the user already voted or not
                                ifile.close();
                                ofile.close();
                                goto label6;
                            }
                        }
                        ifile.close();
                        ofile<<id<<"\n";
                        ofile.close();
                        string partyName;
                        cout << "Enter party name: ";
                        cin.ignore();
                        getline(cin, partyName);
                        ofile3.open("State Total.txt",std::ios::app); 
                        ofile3<<partyName<<endl; //Addiing Party name to the file
                        ofile3.close();
                        statePollingSystem.castVote(partyName);
                        break;
                    }
                    case 2:
                        statePollingSystem.displayPartyNames();
                        break;
                    case 3:
                        a=0;b=0;c=0;d=0;e=0;f=0;
                        cout << "Election Results:\n";
                        cout << "-----------------\n";
                        ifile3.open("State Total.txt");
                        while(getline(ifile3, line0))
                        {
                            if(line0.compare("AIADMK")==0)
                            {
                                a=a+1;
                            }
                            else if (line0.compare("CPI")==0)
                            {
                                b=b+1;
                            }
                            else if (line0.compare("DMDK")==0)
                            {
                                c=c+1;
                            }
                            else if (line0.compare("DMK")==0)
                            {
                                d=d+1;
                            }
                        }

                        // Showing the total count of votes for all the parties

                        cout<<"AIADMK"<<" - "<<a<<endl;
                        cout<<"CPI"<<" - "<<b<<endl;
                        cout<<"DMDK"<<" - "<<c<<endl;
                        cout<<"DMK"<<" - "<<d<<endl;
                        ifile3.close();
                        break;
                    case 4:
                        cout << "Going to main menu again .....\n";
                        cout<<"--------------------\n";
                        goto label3;
                        break;
                    default:
                        cout << "Invalid choice!\n";
                }

                cout << "\n";
	        }
        }
	    else if (n==3)
	    {
		    vector<string> partyNames = {"BJP","AIADMK","DMK","LEFT","INC"};  // Predefined party names

            PollingSystem muniPollingSystem(partyNames);

            int choice;

            while (true) 
            {
                label10:
                cout << " Municipality Polling System\n";
                cout << "----------------------\n";
                cout << "1. Cast Vote\n";
                cout << "2. Display Party Names\n";
                cout << "3. Display Results\n";
                cout << "4. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;
                string line0;int a=0,b=0,c=0,d=0,e=0,f=0;                
                switch (choice) 
                {
                    case 1: 
                    {
                        ifile.open("Municipality.txt");
                        ofile.open("Municipality.txt",std::ios::app);
                        string line3;
                        while(getline(ifile, line3))
                        {
                            if(line3.compare(id)==0)
                            {
                                cout<<"Already voted.......\n"; //Checking if the user already voted or not
                                ifile.close();
                                ofile.close();
                                goto label10;
                            }
                        }
                        ifile.close();
                        ofile<<id<<"\n";
                        ofile.close();
                        string partyName;
                        cout << "Enter party name: ";
                        cin.ignore();
                        getline(cin, partyName);
                        ofile3.open("Municipality Total.txt",std::ios::app); 
                        ofile3<<partyName<<endl; // Adding the party name to the file
                        muniPollingSystem.castVote(partyName);
                        break;
                    }
                    case 2:
                        muniPollingSystem.displayPartyNames();
                        break;
                    case 3:
                        a=0;b=0;c=0;d=0;e=0;f=0;
                        cout << "Election Results:\n";
                        cout << "-----------------\n";
                        ifile3.open("Municipality Total.txt");
                        while(getline(ifile3, line0))
                        {
                            if(line0.compare("BJP")==0)
                            {
                                a=a+1;
                            }
                            else if (line0.compare("AIADMK")==0)
                            {
                                b=b+1;
                            }
                            else if (line0.compare("DMK")==0)
                            {
                                c=c+1;
                            }
                            else if (line0.compare("LEFT")==0)
                            {
                                d=d+1;
                            }
                            else if (line0.compare("INC")==0)
                            {
                                e=e+1;
                            }
                        }

                        // Showing the total count of votes of all the parties
                        
                        cout<<"BJP"<<" - "<<a<<endl;
                        cout<<"AIADMK"<<" - "<<b<<endl;
                        cout<<"DMK"<<" - "<<c<<endl;
                        cout<<"LEFT"<<" - "<<d<<endl;
                        cout<<"INC"<<" - "<<e<<endl;
                        ifile3.close();
                        break;
                    case 4:
                        cout << "Going to main menu again .....\n";
                        cout << "----------------------\n";
                        goto label3;
                        break;
                    default:
                        cout << "Invalid choice!\n";
                }

                cout << "\n";
            }
	    }
        else if (n==4)
        {
            cout<<"Closing the Program .... ";
        }
	    else
	    {
		    cout<<"Invalid";
	    }
    }
    else
    {
        cout<<"Invalid.....\n";
        goto label12;
    }
    return 0;
}
