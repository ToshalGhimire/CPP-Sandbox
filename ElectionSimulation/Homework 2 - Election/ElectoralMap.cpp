#include "stdafx.h"
//#include "ElectoralMap.h"


/**
	ctor for election singleton, takes in election object inorder to acess its data for vote and campaign

	@param Election object
	@return 

*/
ElectoralMap::ElectoralMap(Election * A)
{
	std::cout << "\nOne singleton has been created\n" << std::endl;
	MyElection = A;
}

/**
	function that takes in the runner ID and the district id, and allows the candidate to campagin in said discrit. the two large if statments are to decide what district to campagin in. 
	this function also calcuates the p_success and P_extra succcess and changes constituents based on a random value.

	@param int runnerID, districtID
	@return void

*/
void ElectoralMap::Campaign(int runnerID, int distID) {
	std::cout << std::endl << MyElection->get_runners()[runnerID]->get_name() << " is Campaigning in District " << distID << "!\n" << std::endl;
	
	Party to = MyElection->get_runners()[runnerID]->get_party();
	int sum_candidates, sum_others;
	int area1 = Dist1->get_square_miles();
	int area2 = Dist2->get_square_miles();
	double prob,p_sucess;

	//District one Campaigning
	if (distID == 1) {
		//change Dist1
		std::vector<Dist> temp = Dist1->get_info();
		sum_candidates = 0;
		sum_others = 0;

		for (auto a : temp) {

			if (a.x == to) {
				sum_candidates = a.constituents;
			}

			if (a.x != to && a.x != Party::None){
				sum_others = sum_others + a.constituents;

			}

		}

		p_sucess = (((sum_candidates + 1) * 2.0) / (sum_others)) * (((sum_candidates + 1) * 2.0)/ (area1));
		std::cout << "CHANCE OF SUCCESS = " << p_sucess * 100 << std::endl;
		std::cout << "CHANCE OF EXTRA SUCCESS = " << p_sucess * 10 << std::endl;
		prob = rand() % 101;
		//std::cout << "YOU GOT = " << prob << std::endl << std::endl;

	
		//----------------------------------code to change it--------------------------------------
		// SUCCESS CHECKER for district 1 ; all 4 Scenarios are adressed here
		if (prob <= p_sucess * 10) {

			//checks if its Scenario 3
			bool isNoneEmpty = false;
			for (auto b : Dist1->get_info()) {
				if (b.x == Party::None && b.constituents == 0)
					isNoneEmpty = true;
			}

			//Scenario 3
			if (isNoneEmpty) {
				std::cout << "Congrats you have converted Someone from " << partyStringify(Dist1->get_majority(to)) << " to " << partyStringify(to) << "!" << std::endl;
				Dist1->ChangeParty(Dist1->get_majority(to), to, 1);
			}
			//Scenario 2
			else {
				std::cout << "Congrats you have converted two votes from None and " << partyStringify(Dist1->get_majority(to, Party::None)) << " to " << partyStringify(to) <<"!" << std::endl;

				Dist1->ChangeParty(Party::None, to, 1);
				Dist1->ChangeParty(Dist1->get_majority(to, Party::None), to, 1);

			}

		}
		else if (prob > p_sucess * 10 && prob <= p_sucess * 100) {
			//Scenario 1
			std::cout << "Congrats you have converted Someone from None to " << partyStringify(to) << "!" << std::endl;

			Dist1->ChangeParty(Party::None, to, 1);
		}
		else {
			std::cout << "None one was converted" << std::endl;

			//Scenario 4
		}

	}
	else if (distID == 2){//district Two Campaigning
		//change Dist2
		std::vector<Dist> temp2 = Dist2->get_info();
		sum_candidates = 0;
		sum_others = 0;

		for (auto a : temp2) {

			if (a.x == to) {
				sum_candidates = a.constituents;
			}

			if (a.x != to && a.x != Party::None) {
				sum_others += a.constituents;

			}

		}

		p_sucess = (((sum_candidates + 1) * 2.0) / (sum_others)) * (((sum_candidates + 1) * 2.0) / (area2));
		std::cout << "CHANCE OF SUCCESS = " << p_sucess *100 << std::endl;
		std::cout << "CHANCE OF EXTRA SUCCESS = " << p_sucess * 10 << std::endl;
		prob = rand() % 100;
		//std::cout << "YOU GOT = " << prob << std::endl << std::endl;

		
		//----------------------------------code to change it--------------------------------------
		// SUCCESS CHECKER for district 2 ; all 4 Scenarios are adressed here
		if (prob <= p_sucess * 10) {

			//checks if its Scenario 3
			bool isNoneEmpty = false;
			for (auto b : Dist2->get_info()) {
				if (b.x == Party::None && b.constituents == 0)
					isNoneEmpty = true;
			}

			//Scenario 3
			if (isNoneEmpty) {
				std::cout << "Congrats you have converted Someone from " << partyStringify(Dist2->get_majority(to)) << " to " << partyStringify(to) << "!" << std::endl;
				Dist2->ChangeParty(Dist2->get_majority(to), to, 1);
			}
			//Scenario 2
			else {
				std::cout << "Congrats you have converted two votes from None and " << partyStringify(Dist2->get_majority(to, Party::None)) << " to " << partyStringify(to) << "!" << std::endl;
				Dist2->ChangeParty(Party::None, to, 1);
				Dist2->ChangeParty(Dist2->get_majority(to, Party::None), to, 1);

			}

		}
		else if (prob > p_sucess * 10 && prob <= p_sucess * 100) {
			//Scenario 1
			std::cout << "Congrats you have converted Someone from None to " << partyStringify(to) << "!" << std::endl;
			Dist2->ChangeParty(Party::None, to, 1);
		}
		else {
			//Scenario 4
			std::cout << "None one was converted" << std::endl;


		}


	}
	else {
		return;
	}
	
	

}

/**
	Displays the two district class made by the electoralMap

	@param 
	@return 

*/
void ElectoralMap::Display() {
	Dist1->DisplayDist();
	Dist2->DisplayDist();
}

/**
	Function that counts the votes for direct election. It has two fourloops for each district and sums all the votes into variables. at the end it prints out the votes for each distict
	as well as the candidate that one

	@param 
	@return void

*/
void ElectoralMap::VoteCount() {
	
	int d1_vote_P1 = 0, d1_vote_P2 = 0, d1_vote_P3 = 0;
	int d2_vote_P1 = 0, d2_vote_P2 = 0, d2_vote_P3 = 0;

	std::cout << std::endl;

	for (auto a : Dist1->get_info()) {

		if (a.x == Party::None && rand() % 100 <= 70) {
			Party b = Dist1->get_majority(Party::None);
			
			//gives vote to majority party not containing none
			switch (b)
			{
			case Party::Democrat: d1_vote_P1 += a.constituents;
				break;
			case Party::Republican: d1_vote_P2 += a.constituents;
				break;
			case Party::Other: d1_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}
			

		}
		else if (a.x == Party::None) {
			Party c = (Party)(rand() % 3);
			switch (c)
			{
			case Party::Democrat: d1_vote_P1 += a.constituents;
				break;
			case Party::Republican: d1_vote_P2 += a.constituents;
				break;
			case Party::Other: d1_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}

		}

		if(a.x != Party::None && rand() % 100 <= 90) {
			switch (a.x)
			{
			case Party::Democrat: d1_vote_P1 += a.constituents;
				break;
			case Party::Republican: d1_vote_P2 += a.constituents;
				break;
			case Party::Other: d1_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}
		}
		else if (a.x != Party::None) {
			Party d;
			do {
				d = (Party)(rand() % 3);
			} while (d == a.x);
			
			switch (d)
			{
			case Party::Democrat: d1_vote_P1 += a.constituents;
				break;
			case Party::Republican: d1_vote_P2 += a.constituents;
				break;
			case Party::Other: d1_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}

		}

	}


	for (auto a : Dist2->get_info()) {

		if (a.x == Party::None && rand() % 100 <= 70) {
			Party b = Dist2->get_majority(Party::None);

			//gives vote to majority party not containing none
			switch (b)
			{
			case Party::Democrat: d2_vote_P1 += a.constituents;
				break;
			case Party::Republican: d2_vote_P2 += a.constituents;
				break;
			case Party::Other: d2_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}


		}
		else if (a.x == Party::None) {
			Party c = (Party)(rand() % 3);
			switch (c)
			{
			case Party::Democrat: d2_vote_P1 += a.constituents;
				break;
			case Party::Republican: d2_vote_P2 += a.constituents;
				break;
			case Party::Other: d2_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}

		}

		if (a.x != Party::None && rand() % 100 <= 90) {
			switch (a.x)
			{
			case Party::Democrat: d2_vote_P1 += a.constituents;
				break;
			case Party::Republican: d2_vote_P2 += a.constituents;
				break;
			case Party::Other: d2_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}
		}
		else if (a.x != Party::None) {
			Party d;
			do {
				d = (Party)(rand() % 3);
			} while (d == a.x);

			switch (d)
			{
			case Party::Democrat: d2_vote_P1 += a.constituents;
				break;
			case Party::Republican: d2_vote_P2 += a.constituents;
				break;
			case Party::Other: d2_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}

		}




	}

	std::cout << "\nDISTRICT ONE VOTES\n" << std::endl;
	std::cout << "Democrat = " << d1_vote_P1 << std::endl;
	std::cout << "Republican = " << d1_vote_P2 << std::endl;
	std::cout << "Other = " << d1_vote_P3 << std::endl;

	std::cout << "\nDISTRICT TWO VOTES\n" << std::endl;
	std::cout << "Democrat = " << d2_vote_P1 << std::endl;
	std::cout << "Republican = " << d2_vote_P2 << std::endl;
	std::cout << "Other = " << d2_vote_P3 << std::endl << std::endl;
	
	


	int winner = 0;
	std::string winner_name;

	int p1 = d1_vote_P1 + d2_vote_P1;
	int p2 = d1_vote_P2 + d2_vote_P2;
	int p3 = d1_vote_P3 + d2_vote_P3;


	int max = std::max(p1, std::max(p2,p3));
	std::cout << std::endl;
	for (auto i : MyElection->get_runners()) {
		switch (i->get_party())
		{
		case Party::Democrat: std::cout << i->get_name() << " = " << d1_vote_P1 + d2_vote_P1 << std::endl;
			if (max == d1_vote_P1 + d2_vote_P1)
				winner_name = i->get_name();
			break;
		case Party::Republican: std::cout << i->get_name() << " = " << d1_vote_P2 + d2_vote_P2 << std::endl;
			if (max == d1_vote_P2 + d2_vote_P2)
				winner_name = i->get_name();
			break;
		case Party::Other: std::cout << i->get_name() << " = " << d1_vote_P3 + d2_vote_P3 << std::endl;
			if (max == d1_vote_P3 + d2_vote_P3)
				winner_name = i->get_name();
			break;
		default:
			break;
		}

		
		
		
	}

	if (winner_name == "") {
		std::cout << "\nLooks like there is no winner!\nThis could be beacuse the there was no candidate for the winning party." << std::endl;
	}
	else {

		std::cout << winner_name << " HAS WON!!\n" << std::endl;

	}
	
	
}

/**

	Function that does the same thing as VoteCount, but instead for Representative election and the formulas that comes with that

@param 
@return void

*/
void ElectoralMap::VoteCountRepresentative() {

	int d1_vote_P1 = 0, d1_vote_P2 = 0, d1_vote_P3 = 0;
	int d2_vote_P1 = 0, d2_vote_P2 = 0, d2_vote_P3 = 0;

	std::cout << std::endl;

	for (auto a : Dist1->get_info()) {

		if (a.x == Party::None && rand() % 100 <= 70) {
			Party b = Dist1->get_majority(Party::None);

			//gives vote to majority party not containing none
			switch (b)
			{
			case Party::Democrat: d1_vote_P1 += a.constituents;
				break;
			case Party::Republican: d1_vote_P2 += a.constituents;
				break;
			case Party::Other: d1_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}


		}
		else if (a.x == Party::None) {
			Party c = (Party)(rand() % 3);
			switch (c)
			{
			case Party::Democrat: d1_vote_P1 += a.constituents;
				break;
			case Party::Republican: d1_vote_P2 += a.constituents;
				break;
			case Party::Other: d1_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}

		}

		if (a.x != Party::None && rand() % 100 <= 90) {
			switch (a.x)
			{
			case Party::Democrat: d1_vote_P1 += a.constituents;
				break;
			case Party::Republican: d1_vote_P2 += a.constituents;
				break;
			case Party::Other: d1_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}
		}
		else if (a.x != Party::None) {
			Party d;
			do {
				d = (Party)(rand() % 3);
			} while (d == a.x);

			switch (d)
			{
			case Party::Democrat: d1_vote_P1 += a.constituents;
				break;
			case Party::Republican: d1_vote_P2 += a.constituents;
				break;
			case Party::Other: d1_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}

		}

	}


	for (auto a : Dist2->get_info()) {

		if (a.x == Party::None && rand() % 100 <= 70) {
			Party b = Dist2->get_majority(Party::None);

			//gives vote to majority party not containing none
			switch (b)
			{
			case Party::Democrat: d2_vote_P1 += a.constituents;
				break;
			case Party::Republican: d2_vote_P2 += a.constituents;
				break;
			case Party::Other: d2_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}


		}
		else if (a.x == Party::None) {
			Party c = (Party)(rand() % 3);
			switch (c)
			{
			case Party::Democrat: d2_vote_P1 += a.constituents;
				break;
			case Party::Republican: d2_vote_P2 += a.constituents;
				break;
			case Party::Other: d2_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}

		}

		if (a.x != Party::None && rand() % 100 <= 90) {
			switch (a.x)
			{
			case Party::Democrat: d2_vote_P1 += a.constituents;
				break;
			case Party::Republican: d2_vote_P2 += a.constituents;
				break;
			case Party::Other: d2_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}
		}
		else if (a.x != Party::None) {
			Party d;
			do {
				d = (Party)(rand() % 3);
			} while (d == a.x);

			switch (d)
			{
			case Party::Democrat: d2_vote_P1 += a.constituents;
				break;
			case Party::Republican: d2_vote_P2 += a.constituents;
				break;
			case Party::Other: d2_vote_P3 += a.constituents;
				break;
			case Party::None:
				break;
			default:
				break;
			}

		}




	}

	int winner = 0;
	std::string winner_name;

	//representaive election votes 

	int d1_constituents = d1_vote_P1 + d1_vote_P2 + d1_vote_P3;
	int d2_constituents = d2_vote_P1 + d2_vote_P2 + d2_vote_P3;
	int total_constituents = d1_constituents + d2_constituents;


	double votes_dist1 = std::floor((d1_constituents*1.0 / total_constituents) * 2 * 5);
	double votes_dist2 = std::floor((d2_constituents*1.0 / total_constituents) * 2 * 5);

	double max = std::max(votes_dist1, votes_dist2);

	std::cout << "\nFinal Results" << std::endl;
	
	std::cout << "\nDistrict One" << std::endl;
	std::cout << "Winning Party was " << partyStringify(Dist1->get_majority(Party::None)) << " with " << votes_dist1 << " votes!" << std::endl;
	for (auto i : MyElection->get_runners()) {
		if (i->get_party() == Dist1->get_majority(Party::None)) {
			
			std::cout << i->get_name() << " = " << votes_dist1  << std::endl;
			if (max == votes_dist1) 
				winner_name = i->get_name();
		}
		

	}

	std::cout << "\nDistrict Two" << std::endl;
	std::cout << "Winning Party was " << partyStringify(Dist2->get_majority(Party::None)) << " with " << votes_dist2 << " votes!" << std::endl;
	for (auto i : MyElection->get_runners()) {
		if (i->get_party() == Dist2->get_majority(Party::None)) {
			std::cout << i->get_name() << " = " << votes_dist2 << std::endl;
			if (max == votes_dist2)
				winner_name = i->get_name();
				
		}

	}
	
	if (winner_name == "") {
		std::cout << "\nLooks like there is no winner!\nThis could be beacuse the there was no candidate for the winning party." << std::endl;
	}
	else {

		std::cout << winner_name << " HAS WON!!\n" << std::endl;

	}


}