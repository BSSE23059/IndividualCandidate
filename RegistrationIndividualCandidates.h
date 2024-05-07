
#ifndef INDIDVIDUAL_CANDIDATE_REGISTRATIONINDIVIDUALCANDIDATES_H
#define INDIDVIDUAL_CANDIDATE_REGISTRATIONINDIVIDUALCANDIDATES_H
#include <iostream>
#include <vector>
#include "IndividualCandidate.h"
#include "nlohmann/json.hpp"
#include "fstream"
#include "userInterface.h"
using json = nlohmann::json;
using namespace std;

class RegistrationIndividualCandidates {
private:
    static RegistrationIndividualCandidates* instance;
    vector<IndividualCandidate*> individualCandidates;
    RegistrationIndividualCandidates();
public:
    static RegistrationIndividualCandidates* getInstance();
    void registerIndividualCandidate(IndividualCandidate* individualCandidate);
    void loginCandidate(string username, string password);
    void nominateOnSectors(IndividualCandidate* individualCandidate, string& sectorCode);

};


#endif //INDIDVIDUAL_CANDIDATE_REGISTRATIONINDIVIDUALCANDIDATES_H
