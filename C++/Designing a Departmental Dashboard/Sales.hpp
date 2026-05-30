#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Sales {
  class Team {
    private:
      string teamName;
      vector<string> teamMembers;
      string teamLocation;
    public:
      Team(string name, vector<string> members, string location) : teamName(name), teamMembers(members), teamLocation(location) {};
      string getName() {return teamName;}
      vector<string> getMembers() {return teamMembers;}
      void addMember(string member) {teamMembers.push_back(member);}
      string getLocation() {return teamLocation;}
      void setLocation(string location) {teamLocation = location;}
      void printTeamDetails() {
        cout << "Sales Team Name: " << teamName << endl;
        cout << "Location: " << teamLocation << endl;
        cout << "Members: ";
        for (int i = 0; i < (teamMembers.size() - 1); i++) {
          cout << teamMembers[i] << ", ";
        }
        cout << teamMembers[teamMembers.size() - 1] << endl;
      }
  };
}