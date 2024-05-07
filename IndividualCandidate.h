
#ifndef INDIDVIDUAL_CANDIDATE_INDIVIDUALCANDIDATE_H
#define INDIDVIDUAL_CANDIDATE_INDIVIDUALCANDIDATE_H
#include <iostream>
#include "Person.h"

class IndividualCandidate : public Person{
private:
    string username;
    string password;
    string symbol;
    int voteCount;
    int position;
    bool wonStatus;
public:
    IndividualCandidate(string userName, string password, string name, string CNIC, string dob, string gender, Address& address);
    string getUsername();
    string getPassword();
    int getVoteCount();
    int getPosition();
    const string getSymbol() const;
    void setCandidateSymbol(string& symbol);
    bool getWonStatus();
    void setVoteCount(int count);
    void setPosition(int position);
    void setWonStatus(bool status);
    void nominateOnSector(string& sectorCode);
    void castVote() override;

};


#endif //INDIDVIDUAL_CANDIDATE_INDIVIDUALCANDIDATE_H
