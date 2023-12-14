/*
Kevin Alvarez
CS136
Project 01 
*/

#include <iostream>
using std::string;
using std::cout;


class Cancer{
	private:
		string name;
		string affected_location;
		string stage;
		int idNumber;
	public:
		//constructor 1
		Cancer(string Name, int id, string location, string Stage)
		{
			name = Name;
			idNumber = id;
			affected_location = location;
			stage = Stage;

		}
		//constructor 2
		Cancer(string Name, int id)
		{
			name = Name;
			idNumber = id;
			affected_location = " ";
			stage = " ";

		}
		//constructor 3
		Cancer()
		{
			name = " ";
			idNumber = 0;
			affected_location = " ";
			stage = " ";

		}
		//mutalator and accessor functions follow
		void setName(string Name)
		{
			name = Name;

		}
		//space
		string getName()
		{
			return name;
		}
		//space
		void setID(int id)
		{
			id = idNumber;
		}
		//space
		int getID()
		{
			return idNumber;
		}
		//space
		void setLocation(string location)
		{
			location = affected_location;
		}
		//space
		string getLocation()
		{
			return affected_location;
		}
		//space
		void setStage(string Stage)
		{
			stage = Stage;
		}
		//space
		string getStage()
		{
			return stage;
		}

};

int main()
{
	char descion;
	int patNum, newNum;
	string  answer, canName;


	//3objects 
	Cancer patient1("Lukimia", 4323, "Arm", "Stage 5");//to check that the 1st consrtuctor will assign the correct values
	Cancer patient2("Prostate", 5642);//to check that 2nd constructor will assign the correct values
	Cancer patient3; //to check that default constructor will asign the correct values

	cout << std::endl;
	cout<< "Patient 1 - Cancer name: " << patient1.getName() << " ID Number: " << patient1.getID() << " Body Part: " << patient1.getLocation() << " Stage: " << patient1.getStage() << std::endl;
	cout<< "Patient 2 - Cancer name: " << patient2.getName() << " ID NUmber: " << patient2.getID() << " Body Part: " << patient2.getLocation() << " Stage: " << patient2.getStage() << std::endl;
	cout<< "Patient 3 - Cancer name: " << patient3.getName() << " ID Number: " << patient3.getID() << " Body Part: " << patient3.getLocation() << " Stage: " << patient3.getStage() << std::endl;





	/*correction calculator*/

	cout<< std::endl<< "Is there a correction you would like to make? Y||N ";
	std::cin >> descion;

	if (descion == 'Y')
	{
		cout<<"Which patient would you like to change? Ex. 1,2, or 3 ";
		std::cin>>patNum;

		if (patNum == 1 )
		{
			cout<<"What would you like to change? Ex. Name, ID, Body Part, Stage ";
			std::cin>>answer;
			if (answer == "Name")
			{
				cout<<"What is the new Cancer name? ";
				std::cin>>canName;
				patient1.setName(canName);
			}
			else if (answer == "Body Part")
			{
				cout<<"What is the new Body Part? ";
				std::cin>>canName;
				patient1.setLocation(canName);
			}
			else if(answer == "Stage")
			{
				cout<<"What is the new Stage? ";
				std::cin>>canName;
				patient1.setStage(canName);
			}
			else
			{
				cout<<"What is the new ID? ";
				std::cin>>newNum;
				patient1.setID(newNum);
			}
		}


		else if (patNum == 2 )
		{
			cout<<"What would you like to change? Ex. Name, ID, Body Part, Stage ";
			std::cin>>answer;
			if (answer == "Name")
			{
				cout<<"What is the new Cancer name? ";
				std::cin>>canName;
				patient2.setName(canName);
			}
			else if (answer == "Body Part")
			{
				cout<<"What is the new Body Part? ";
				std::cin>>canName;
				patient2.setLocation(canName);
			}
			else if(answer == "Stage")
			{
				std::cout<<"What is the new Stage? ";
				std::cin>>canName;
				patient2.setStage(canName);
			}
			else
			{
				cout<<"What is the new ID? ";
				std::cin>>newNum;
				patient2.setID(newNum);
			}
		}


		else if (patNum == 3)
		{
			cout<<"What would you like to change? Ex. Name, ID, Body Part, Stage ";
			std::cin>>answer;
			if (answer == "Name")
			{
				cout<<"What is the new Cancer name? ";
				std::cin>>canName;
				patient3.setName(canName);
			}
			else if (answer == "Body Part")
			{
				cout<<"What is the new Body Part? ";
				std::cin>>canName;
				patient3.setLocation(canName);
			}
			else if(answer == "Stage")
			{
				cout<<"What is the new Stage? ";
				std::cin>>canName;
				patient3.setStage(canName);
			}
			else
			{
				cout<<"What is the new ID? ";
				std::cin>>newNum;
				patient3.setID(newNum);
			}

		}
		else if (patNum >=4)
		{
			cout<<"That patcient doesn't exist. " << std::endl;
			cout<<"Terminating Program. " << std::endl;
			return 0;
		}

		cout<<"New Output is :" << std::endl;
		cout<< "Patient 1 - Cancer name: " << patient1.getName() << " ID Number: " << patient1.getID() << " Body Part: " << patient1.getLocation() << " Stage: " << patient1.getStage() << std::endl;
		cout<< "Patient 2 - Cancer name: " << patient2.getName() << " ID Number: " << patient2.getID() << " Body Part: " << patient2.getLocation() << " Stage: " << patient2.getStage() << std::endl;
		cout<< "Patient 3 - Cancer name: " << patient3.getName() << " ID Number: " << patient3.getID() << " Body Part: " << patient3.getLocation() << "Stage: " << patient3.getStage() << std::endl;


		return 0;

	}

	else if (descion == 'N')
	{
		cout<<"Program ended";
		return 0;
	}





}
