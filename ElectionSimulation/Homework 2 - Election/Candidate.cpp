#include "stdafx.h"
//#include "Candidate.h"

int Candidate::static_id = 0;


/**
ctor that takes the name and party of the canidate, gives unique id to each


@param string name, Party x
@return none

*/
Candidate::Candidate(std::string name, Party x)
{
	id_ = ++static_id;
	
	//if statment to make sure that Party of the canidate is NOT None
	if (x == Party::None) {
		int input;
		std::cout << "\nCanidate "<< name <<" cannot be of Party type None" << std::endl;
		std::cout << "\n(1) Republican\n(2) Democrat\n(3) Other\nPlease enter another party: ";
		std::cin >> input;

		if (input == 1) {
			p_ = Party::Republican;
		}
		else if (input == 2) {
			p_ = Party::Democrat;
		}
		else {
			p_ = Party::Other;
		}


	} 
	else {
		p_ = x;
	}

	name_ = name;
}


/**
function that returns the string of the party inputed

@param Party x
@return string

*/
std::string partyStringify(Party x)
{
	switch (x)
	{
	case Party::Democrat: return "Democrat";
		break;
	case Party::Republican: return "Republican";
		break;
	case Party::Other: return "Other";
		break;
	case Party::None: return "None";
		break;
	default: return "";
		break;
	}

}

