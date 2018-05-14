#ifndef _ELECTION_H_
#define _ELECTION_H_

#pragma once
#include "stdafx.h"



class Election
{
public:
	Election();
	void Start();

	void Register();
	void CandidateInfo();

	std::vector<Candidate*> get_runners() { return runners_; }

private:
	std::vector<Candidate*> runners_;

};


#endif // _ELECTION_H_
