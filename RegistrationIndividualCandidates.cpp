#include "RegistrationIndividualCandidates.h"

RegistrationIndividualCandidates *RegistrationIndividualCandidates::instance = nullptr;

RegistrationIndividualCandidates::RegistrationIndividualCandidates() {

}

RegistrationIndividualCandidates *RegistrationIndividualCandidates::getInstance() {
    if(instance == nullptr){
        instance = new RegistrationIndividualCandidates;
    }
    return instance;
}

void RegistrationIndividualCandidates::registerIndividualCandidate(IndividualCandidate *individualCandidate) {
    individualCandidates.push_back(individualCandidate);

    string individualCandidateFile = individualCandidate->getUsername() + ".json";
    json candidateData;
    json candidate;
    candidate[individualCandidate->getUsername()] = {
            {"Name",individualCandidate->getPersonName()},
            {"CNIC",individualCandidate->getCNIC()},
            {"Address",individualCandidate->getPersonAddress().getConcatenatedAddress()},
            {"Password",individualCandidate->getPassword()},
            {"Gender",individualCandidate->getGender()},
            {"DOB",individualCandidate->getDateOfBirth()}
    };
    candidateData.push_back(candidate);
    ofstream putCandidateData(individualCandidateFile);
    putCandidateData << candidateData.dump(4) << endl;
    putCandidateData.close();

}

void RegistrationIndividualCandidates::loginCandidate(std::string username, std::string password) {
    string candidateFile = username + ".json";
    ifstream getCandidateData(candidateFile);
    json candidateData;
    getCandidateData >> candidateData;
    getCandidateData.close();

    for(auto& candidate : candidateData){
        if(candidate.contains(username)) {
            json &userName = candidate[username];
            if(userName["Password"] == password){
                userInterface(username);
            }
        }
    }
}

void RegistrationIndividualCandidates::nominateOnSectors(IndividualCandidate* individualCandidate,std::string &sectorCode) {
    ifstream getSectors("candidates.json");
    json sectorsData;
    getSectors >> sectorsData;
    getSectors.close();

    json candidate;
    candidate[individualCandidate->getPersonName()] = {
            {"Symbol",individualCandidate->getSymbol()},
            {"VoteCount",individualCandidate->getVoteCount()},
            {"Position",individualCandidate->getPosition()},
            {"WonStatus",individualCandidate->getWonStatus()}
    };
    for(auto& sector : sectorsData){
        if(sector.contains(sectorCode)){
            json& candidateSector = sector[sectorCode];
            candidateSector.push_back(candidate);
        }
    }
    ofstream putCandidateInSector("candidates.json");
    putCandidateInSector << sectorsData.dump(4) << endl;
    putCandidateInSector.close();
}