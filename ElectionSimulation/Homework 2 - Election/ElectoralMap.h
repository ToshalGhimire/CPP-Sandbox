#ifndef _ELECTORALMAP_H_
#define _ELECTORALMAP_H_

#pragma once
class ElectoralMap
{
public:

	static ElectoralMap& GetInstance(Election * A) {

		static ElectoralMap instance_(A);

		return instance_;
	}

	ElectoralMap(ElectoralMap const&) = delete;
	void operator=(ElectoralMap const&) = delete;

	//~ElectoralMap();
	void UpdateElection(Election * B) { MyElection = B; }
	void Campaign(int runnerNum, int distNum);
	void Display();
	void VoteCount();
	void VoteCountRepresentative();

private:
	ElectoralMap(Election * A);

	District * Dist1 = new District();
	District * Dist2 = new District();
	Election * MyElection;
	//std::vector<Candidate*> S_runners_;
};


#endif // !_ELECTORALMAP_H_
