/*
	Toshal Ghimire
	Homework 2 Election

	This code, creates an election object, which creates canidates objects, then calls the ElectoralMap singleton which creates the district that the elections are centered around

	coded using Microsoft visual studio


*/

#include "stdafx.h"

using namespace std;


int main()
{
	cout << "HW2 Inside Main\n--------------\n" << endl;
	srand(time(0)); //needed to randomize districts each time
	Election *  A = new Election;
	A->Start();
	


    return 0;
}

