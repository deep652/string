#include <iostream>
#include <sstream>

using namespace std;
int main() {
    stringstream ss;
    ss << "deep shikha";

    string word;

    while(ss >> word)
    {
        cout<<word<<endl;
        if(ss.eof())
            cout<<"end of string reached";
    }
        

    cout<<ss.str();


    return 0;
}
