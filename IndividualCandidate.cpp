
#include "IndividualCandidate.h"

IndividualCandidate::IndividualCandidate(std::string userName, std::string password, std::string name, std::string CNIC,
                                         std::string dob, std::string gender, Address &address) {
    username = userName;
    this->password = password;
    setPersonName(name);
    setPersonCNIC(CNIC);
    setPersonGender(gender);
    setPersonAddress(address);
    setDateOfBirth(dob);
    symbol = "";
    voteCount = 0;
    position = 0;
    wonStatus = false;
}

string IndividualCandidate::getUsername() {
    return username;
}

string IndividualCandidate::getPassword() {
    return password;
}

int IndividualCandidate::getVoteCount() {
    return voteCount;
}

int IndividualCandidate::getPosition() {
    return position;
}

bool IndividualCandidate::getWonStatus() {
    return wonStatus;
}

const string IndividualCandidate::getSymbol() const {
    return symbol;
}

void IndividualCandidate::setVoteCount(int count) {
    voteCount = count;
}

void IndividualCandidate::setPosition(int position) {
    this->position = position;
}

void IndividualCandidate::setWonStatus(bool status) {
    wonStatus = status;
}

void IndividualCandidate::setCandidateSymbol(std::string &symbol) {
    this->symbol = symbol;
}

void IndividualCandidate::castVote() {

}