#ifndef _CANDIDATE_H_
#define _CANDIDATE_H_

#pragma once
#include "stdafx.h"

enum class Party { Democrat, Republican, Other, None };

std::string partyStringify(Party X);

class Candidate
{
public:
	Candidate(std::string name, Party x);


	int get_id() const { return id_; }
	std::string get_name() { return name_; }
	Party get_party() { return p_; }


private:
	static int static_id;
	int id_;
	std::string name_;
	Party p_;

};



#endif // !_CANDIDATE_H_
