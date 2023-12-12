#include <iostream>
#include <map>
#include <string>
int main() {
 std::map<std::string, long long> statePopulations;
 // Populate the map with state names and populations
 statePopulations["California"] = 39538223;
 statePopulations["Texas"] = 29145505;
 statePopulations["Florida"] = 21538187;
 statePopulations["New York"] = 20201249;
 statePopulations["Pennsylvania"] = 13002700;
 std::string stateName;
 // Prompt the user to enter a state name
 std::cout << "Enter the name of a state: ";
 std::getline(std::cin, stateName);
 // Search for the state in the map
 auto it = statePopulations.find(stateName);
 if (it != statePopulations.end()) {
 std::cout << "Population of " << stateName << " is: " << it->second << std::endl;
 } else {
 std::cout << "State not found in the map." << std::endl;
 }
 return 0;
}







