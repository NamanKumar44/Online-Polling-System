#include<iostream>
#include<string>
using namespace std;
class State_Candidates
{
private:
    string party_name;
protected:
    string party_leader;
public:
    int count1=0;
    int sno;
    void get_party(int sno)
    {

        cout<<"Enter the name of the party "<<sno<<" - ";
        getline(cin,party_name);
        cout<<"Enter the name of the party leader - ";
        getline(cin,party_leader);
        count1=0;
        this->sno=sno;
    }
    void display_party()
    {
        cout<<"The serial number of the party is "<<sno<<" - \n\n";
        cout<<"The name of the party is "<<party_name<<"- \n\n";
        cout<<"The name of the leader of "<<party_name<<" is "<<party_leader<<"- \n\n";
    }
    void display_party(int count1)
    {
        cout<<"The serial number of the party is "<<sno<<"\n\n";
        cout<<"The name of the party is "<<party_name<<"\n\n";
        cout<<"The name of the leader of "<<party_name<<" is "<<party_leader<<"\n\n";
        cout<<"The number of votes for this party is "<<count1<<"\n\n";

    }


};
class Voter
{
private:
    string name;
public:
    int VoterNumber;
    string vcity;
    int age;
    int voted;
    void get_voter(string name,int VoterNumber,string vcity,int age);
    void display_voter();
    void modify_vote(int status);
};
void Voter::get_voter(string name,int VoterNumber,string vcity,int age)
{
    this->name=name;
    this->VoterNumber=VoterNumber;
    this->vcity=vcity;
    this->age=age;
    this->voted=0;
}

void Voter::display_voter()
{
    cout<<"The name of the voter is "<<name<<"\n";
    cout<<"The VoterID of the voter is "<<VoterNumber<<"\n";
    cout<<"The age of the voter is "<<age<<"\n";
    if (voted==0)
    {
        cout<<"Status: Not voted\n";
    }
    else
    {
        cout<<"Status: Voted\n\n";
    }
}
void Voter::modify_vote(int status)
{
    if (status==1)
    {
        voted=1;
    }
}
class State_election:public State_Candidates, public Voter
{
private:
    string ecity;
public:
    void get_ecity()
    {
        cout<<"Enter the city where the vote is being casted ";
        cin>>ecity;
    }
    friend void get_displayresults(int vn,int pn,class State_election *se,class State_Candidates *s);


};
void get_displayresults(int vn,int pn,class State_election *se,class State_Candidates *s)
{
    int winner=0;
    int tempcount=0;
    int voteslist[pn];
    int k=0;
    cout<<"\n\n******************************************************\n";
    cout<<"\nHere are the list of eligible voters\n\n";
    for (k=0;k<vn;k++)
    {
        cout<<"----------------------------------------------------\n\n";
        se[k].display_voter();
    }
    cout<<"----------------------------------------------------------\n\n";
    cout<<"Here are the final results\n\n";
    for (k=0;k<pn;k++)
    {
        cout<<"--------------------------------------------------------\n\n";
        s[k].display_party(s[k].count1);
    }
    for (k=0;k<pn;k++)
    {
        voteslist[k]=s[k].count1;
        if (s[k].count1>winner)
        {
            winner=s[k].count1;
        }
    }
    k=0;
    while(k<pn)
    {
        if (winner==s[k].count1)
        {
            tempcount++;
        }
        k++;
    }
    int tied[tempcount];
    k=0;
    int z=0;
    while(k<pn)
    {
        if (winner==s[k].count1)
        {
            tied[k]=k+1;
        }
        k++;
    }
    if (tempcount>=2)
    {
        cout<<"-----------------------------------------------------\n";
        cout<<"The votes were tied between the following parties\n\n";
        for (k=0;k<pn;k++)
        {
            if (s[k].sno==tied[z])
            {
                s[k].display_party(s[k].count1);
                z++;
            }

        }
    }
    else
    {
        cout<<"-----------------------------------------------------\n";
        cout<<"The winner is\n\n";
        for (k=0;k<pn;k++)
        {
            if (s[k].sno==tied[0])
            {
                s[k].display_party(s[k].count1);
            }

        }

    }

}

int main()
{
    int i;
    string name;
    int voterno;
    string vcity;
    int age;
    class State_Candidates *s=NULL;
    int pn;
    cout<<"Enter the number of parties - ";
    cin>>pn;
    cin.ignore();
    s=new State_Candidates[pn];
    cout<<"Enter the details of the parties\n";
    for (i=0;i<pn;i++)
    {
        s[i].get_party(i+1);
    }
    class State_election *se=NULL;
    int vn;
    float fvn;
    cout<<"\nEnter the number of voters - ";
    cin>>vn;
    cout<<endl;
    fvn=vn;
    cin.ignore();
    se=new State_election[vn];
    int len=0;//length of voter id
    i=0;
    int flag1=1;
    int la[vn];//list of entered Voter ID
    int lacount=0;
    int flagla=0;
    while(i<vn)
    {
		cout<<"Enter Details of Voter "<<i+1<<endl<<endl;
        cout<<"Enter Voter Name - ";
        getline(cin,name);
        //cout<<"Enter the city from which you are voting";
        //cin>>se[]

        do
        {
            flagla=0;
            cout<<"Enter Voter ID Number - ";
            cin>>voterno;
            for (int l=0;l<lacount;l++)
            {
                if (voterno==la[l])
                {
                    flagla=1;
                }
            }
            if (voterno<10000 || voterno>99999 || flagla==1)
            {
                cout<<"Try Again! Already Taken\n";

            }
        }
        while(voterno<10000 || voterno>99999 || flagla==1);
        lacount++;
        la[i]=voterno;
        cout<<"Enter the city that you are voting from - ";
        cin>>vcity;
        cout<<endl;
        cin.ignore();
        if (true)
        {
            se[i].get_voter(name,voterno,vcity,age);
            i++;
        }

    }
    //elections start
    cout<<"Here are your choices\n";
    for (i=0;i<pn;i++)
    {
        s[i].display_party();
    }
    //here we are assuming that all the turnout percentage is 100
    //State_election *se;
    //se=new State_election[vn];
    i=0;
    int tempaadhar;
    int flagaadhar=0;
    int flagsno=0;
    int tempsno;
    int tempperson=0;
    int j;
    float votecount=0;
    string tempcity;
    while(i<vn)
    {
        flagaadhar=0;
        flagsno=0;
        int flagvoted=1;
        cout<<"Enter Voter ID Number - ";
        cin>>tempaadhar;
        cin.ignore();
        if (tempaadhar==-1)
        {
            break;
        }
        cout<<"Enter the city from which you are voting - ";
        getline(cin,tempcity);
        for (j=0;j<vn;j++)
        {
            if (se[j].VoterNumber==tempaadhar && se[j].voted==0 && se[j].vcity==tempcity)
            {
                //cout<<"Yes";
                flagaadhar=1;
                flagvoted=0;
                tempperson=j;
                break;
            }
        }
        if (flagaadhar==1 && flagvoted==0)
        {
            cout<<"Enter the serial number of the party who you want to vote - ";
            cin>>tempsno;
            for(j=0;j<pn;j++)
            {
                if(s[j].sno==tempsno)
                {
                    flagsno=1;
                    s[j].count1=s[j].count1+1;
                    se[tempperson].modify_vote(1);
                    break;
                }
            }

        }

        if (flagaadhar==1 && flagsno==1)
        {
            cout<<"Vote Has been entered\n";
            votecount++;
            //cout<<votecount;
            i++;
        }
        else
        {
            cout<<"Either Vote already Given OR  Given Information is incorrect \n";
        }

    }
    get_displayresults(vn,pn,se,s);
    float percentage;
    percentage=votecount/fvn;
    cout<<"\nThe percentage of people that have voted are - ";
    cout<<(percentage*100);

}
