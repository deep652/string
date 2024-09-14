#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> modifyFormat(const vector<string>& strings) {
    vector<int> levels(1, 0);  // Initially, only 1 level with counter 0
    vector<string> result;

    for (const auto& str : strings) {
        int countHashes = 0;

        // Count the number of leading '#'
        for (char ch : str) {
            if (ch == '#') {
                countHashes++;
            } else {
                break;
            }
        }

        // Extract the content after leading '#'
        string content = str.substr(countHashes);
        content = content.substr(content.find_first_not_of(" "));  // Trim leading spaces

        // Adjust the size of the levels vector based on the number of hashes (levels)
        if (levels.size() < countHashes) {
            levels.resize(countHashes, 0);  // Add more levels if needed
        }

        // Increment the counter for the current level
        levels[countHashes - 1]++;

        // Reset the counters for any deeper levels
        for (int i = countHashes; i < levels.size(); ++i) {
            levels[i] = 0;
        }

        // Build the numbering format (e.g., 1, 1.1, 1.2, etc.)
        stringstream formattedString;
        for (int i = 0; i < countHashes; ++i) {
            if (i > 0) formattedString << ".";
            formattedString << levels[i];
        }
        for(auto x:levels)
        {
            cout<<x<<"\t";
        }
        cout<<endl;
        cout<<formattedString.str()<<endl;

        // Add the formatted string along with the content
        formattedString << " " << content;
        result.push_back(formattedString.str());
    }

    return result;
}

void fun( vector<string> strings)
{
    vector<int> level{1, 0};
    for(auto str: strings)
    {
        int count = 0;
        for(auto x: str)
        {
            if(x != '#')
            {
                break;
            }
            count++;
        }

        if(level[1] == 0)
        {
            cout<<level[0]<<endl;
            level[1]++;
        }
        else
        {
            if(count > level[1])
            {
                cout<<level[0]<<"."<<level[1]++<<endl;
            }
            else
            {
                level[0]++;
                level[1] = 0;
            }
        }
    }
}

int main() {
    // Input strings, can be of arbitrary depth of levels
    vector<string> inputStrings = {
        "# adb description",
        "## sbd ded",
        "## dfg frdg",
        "# sbd",
        "## another second level",
        "# new section",
        "## sub of new section",
        "### sub of new section",
        "# sub of new section",
        "## sub of new section",
        "### sub of new section",
        "#### sub of new section",
        "##### sub of new section",
        "# sub of new section",
        "## sub of new section",
        "# sub of new section"
    };

    vector<string> modifiedStrings = modifyFormat(inputStrings);

    // Output the result
    for (const auto& s : modifiedStrings) {
        cout << s << endl;
    }

    fun(inputStrings);
    

    return 0;
}
