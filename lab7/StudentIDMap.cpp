#include "StudentIDMap.h"

//  StudentIDMap(int nums, string name[], int ID[]);
//     bool findStudent(const string&) const;
//     int getID(const string&);

//     friend ostream& operator<<(ostream& os, const StudentIDMap& studentIDMap);
// private:
//     map<string, int> nameIDMap;
StudentIDMap::StudentIDMap(int nums, string name[], int ID[]){
	for (int i=0;i<nums;i++){
		nameIDMap[name[i]]=ID[i];
	}
}

bool StudentIDMap::findStudent(const string& name) const{
	map<string, int>::const_iterator findItr = nameIDMap.find("name");
	if (findItr!=nameIDMap.end()){
		return true;
	}
	return false;
}

int StudentIDMap::getID(const string& name){
	return nameIDMap[name];
}

ostream& operator<<(ostream& os, const StudentIDMap& studentIDMap){
	map<string, int>::const_iterator iter;
    cout << "{";
    for(iter = studentIDMap.nameIDMap.begin(); iter != studentIDMap.nameIDMap.end(); iter++)
        cout<<"("<<iter->first<<","<<iter->second<<") ";
    cout << "}"<<endl;
    return os;
}
