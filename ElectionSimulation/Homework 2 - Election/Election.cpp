#include "stdafx.h"
//#include "Election.h"

/**
	ctor for Election object
	//does nothing

	@param 
	@return
*/
Election::Election()
{
	std::cout << "An Election object has been created!" << std::endl;

}

/**
	The start of the election, it asks what type of election, then calls Register(), then the function asks user witch canidate is
	campagining and where, ElectorialMap handles all of that. at the end, the voteing is done, then it asks if you would like to start another election

@param none
@return none
*/
void Election::Start() {
	std::cout << "\nAn Election Has Started!" << std::endl;

	bool IsRepresentative = false; //bool to manage representative election (instead of using another class)
	std::string input;
	int input_candidateID;
	int input_distID;

	//deciding what type of election is happening
	while (true)
	{
		std::cout << "What kind of election should we have (direct or representative)?";

		std::cin >> input;
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input == "direct" || input == "d") {
			std::cout << "Youve chosen a direct election" << std::endl;
			Register();
			break;
		}
		else if (input == "representative" || input == "r") {
			std::cout << "Youve chosen a representative election" << std::endl;
			Register();
			IsRepresentative = true;
			break;
		}

	}

	//Singleton called
	ElectoralMap& A = ElectoralMap::GetInstance(this);
	A.UpdateElection(this);

	//directs canidates to go campaigning if they wish to do so.
	while (true)
	{
		this->CandidateInfo();
		std::cout << "\nWhich candidate is campaigning? (Enter 0 to stop)" << std::endl;
		do
		{
			std::cout << " >";
			std::cin >> input_candidateID;
		} while (input_candidateID < 0 || input_candidateID > runners_.size());
		if (input_candidateID == 0) break;

		A.Display();

		std::cout << "\nWhat district will they campagin in? (Enter 0 to stop)" << std::endl;

		do
		{
			std::cout << " >";
			std::cin >> input_distID;
		} while (input_distID < 0 || input_distID > 2);
		if (input_distID == 0) break;


		A.Campaign(input_candidateID - 1, input_distID);



	}

	//vote is counted and winner is outputted
	if (IsRepresentative) {
		A.VoteCountRepresentative();
	}
	else {
		A.VoteCount();
	}
	

	std::string answer;
	std::cout << "Would you like another election? (y or n)\n >";
	std::cin >> answer;

	//starts another election
	if (answer == "y" || answer == "yes"){
		delete this;
		Election * newElection = new Election();
		newElection->Start();
	}
	else {
		std::cout << "\n\nGoodbye!\nCode writtin by Toshal Ghimire\n" << std::endl;
	}
}


/**
	Registers canidates is called insided of start, makes new canidate objects based on user inputs and 
	stores it insided the vector of canidates objects.

@param none
@return none
*/
void Election::Register() {
	
	for (int i = 0; i < 3; i++) {
		while (true)
		{
			std::cout << "Do you want to register a candidate for " << partyStringify((Party)i) << " ( y or n) ?\n > ";
			std::string input;
			std::cin >> input;
			std::transform(input.begin(), input.end(), input.begin(), ::tolower);

			if (input == "y" || input == "yes") {
				std::string Name;
				std::cout << "What is their name?\n > ";
				std::cin >> Name;
				
				Candidate * temp = new Candidate(Name, (Party)i);
				runners_.push_back(temp);

			}
			else if (input == "n" || input == "no"){
				break;
			}
		}
	
	}

}


/**
	Displays all the canidates and the party they are part of

	@param none
	@return none
*/
void Election::CandidateInfo() {
	int i = 0;
	for (auto a : runners_) {
		std::cout <<"("<< ++i <<") Candidate ID "<< a->get_id() << ": " << a->get_name() << " [Party: " << partyStringify(a->get_party()) << "]" << std::endl;
	}

}

