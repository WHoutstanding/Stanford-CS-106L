#include <vector>
#include <string>
#include <iostream>
using std::vector;  using std::string;
using std::cout;    using std::endl;

void printVec(const vector<string>& v) {
    cout << "{";
    for(auto elem : v) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}

int main() {
    vector<string> names;
    names.push_back("Anna");
    names.push_back("Avery");
    printVec(names);
   
    // cout << names[400] << endl;
    cout << "I have reached this point!" << endl;
    // cout << names.at(0) << endl;
    return 0;
}
