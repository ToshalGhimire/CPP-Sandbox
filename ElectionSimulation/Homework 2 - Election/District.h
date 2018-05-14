#ifndef _DISTRICT_H_
#define _DISTRICT_H_

#include "stdafx.h"


//district struct
struct Dist {
	Party x;
	int constituents;
};


class District
{
public:
	District();
	void DisplayDist();

	std::vector<Dist> get_info() { return info_; };
	void ChangeParty(Party from, Party to, int amount);
	int get_square_miles() { return square_miles_; }
	Party get_majority(Party exclude);
	Party get_majority(Party exclude1, Party exclude2);

private:
	static int static_dNum_;
	int district_Num_;
	int square_miles_;
	std::vector<Dist> info_;
};


#endif // !_DISTRICT_H_
