#include "stdafx.h"
//#include "District.h"

int District::static_dNum_ = 0;



/**

	ctor that creates a unique district, gives a random size for squaremiles and gives a random number of constituents for each party
	
	@param
	@return
*/
District::District()
{
	district_Num_ = ++static_dNum_;
	
	this->square_miles_ = (rand() % 21) + 5;
	for (int i = 0; i < 4; i++) {
		int r = rand() % 10;
		this->info_.push_back({ (Party)i, r });
	}
	
	

}


/**
	function that displays the district, its square miles, and its number of constituents in each party

	@param none
	@return void

*/
void District::DisplayDist() {
	std::cout << "\nDistrict " << this->district_Num_ << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << " Square miles: " << this->square_miles_ << std::endl;
	//std::cout << "--------------------------" << std::endl;

	for(auto a : this->info_) {
		std::cout << " [Party: " << partyStringify(a.x) << "] : " << a.constituents << "    ";

	}
	std::cout << std::endl;

}



/**
	function that changes the value of the districts. it first checks to see if the transfur is valid 
	(ie ammout changing is greater then the amount thats already in the party), after the check it
	changes the value accordly 

	@param From, to and ammount
	@return 

*/
void District::ChangeParty(Party from, Party to,int amount) {

	bool isValid = true;

	//checks if valid
	for (auto& a : this->info_) {
		if (a.x == from && a.constituents < amount) {
			isValid = false;
		}
	}
	
	
	//changes the value accordly
	if(isValid){
		for (auto& a : this->info_) {
			if (a.x == from) {
				a.constituents -= amount;
			}
			if (a.x == to) {
				a.constituents += amount;
			}

		}
	}
	else {
		std::cout << "Opps! It looks like there are no constituents for that party!" << std::endl;
		return;
	}

}

/**
function that returns the party with the most constituents, excpet for one party

@param Party Exclude(party to exclude)
@return Party

*/
Party District::get_majority(Party exclude) {
	int max = 0;
	Party ret;

	for (auto a : this->info_) {
		if (a.x != exclude) {

			if (max <= a.constituents) {
				ret = a.x;
				max = a.constituents;
			}
			
			

		}
	}

	return ret;
}

/**
function that returns the party with the most constituents, excpet for two party

@param Party exclude1 and exclude2 (the two parties to exclude)
@return Party

*/
Party District::get_majority(Party exclude1, Party exclude2) {
	int max = 0;
	Party ret;

	for (auto a : this->info_) {
		if (a.x != exclude1 || a.x != exclude2) {

			if (max <= a.constituents) {
				ret = a.x;
				max = a.constituents;
			}



		}
	}

	return ret;
}
