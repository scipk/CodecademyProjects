#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Marketing {
  class Team {
    private:
      string teamName;
      vector<string> teamMembers;
      double teamBudget;
    public:
      Team(string name, vector<string> memebrs, double budget) : teamName(name), teamMembers(memebrs), teamBudget(budget) {};
      string getName() {return teamName;}
      void addMember(string member) {teamMembers.push_back(member);}
      int getMemberCount() {return teamMembers.size();}
      double getBudget() {return teamBudget;}
      void setBudget(double newBudget) {teamBudget = newBudget;}
  };

  namespace Support {
    void auditTeam(Marketing::Team& team) {
      cout << "Auditing Marketing Team: " << team.getName() << endl;
      cout << "Number of Members: " << team.getMemberCount() << endl;
      cout << "Team Budget: " << team.getBudget() << endl;
      cout << "Audit complete!" << endl;
    }
  }
}