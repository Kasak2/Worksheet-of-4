#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector<string> names;

map<string, int> nameAgeMap;


void addPerson(const string& name, int age)

{
    names.push_back(name);

    nameAgeMap[name] = age;
}


void displayAboveAge(int ageLimit)

{
    cout << "People above age " << ageLimit << ":\n";

    for (const auto& pair : nameAgeMap)

        {
            if (pair.second > ageLimit)

            {

                cout << pair.first << " - " << pair.second << " years old\n";
            }
    }
}

void displaySortedNames()

{
    vector<string> sortedNames = names;

    sort(sortedNames.begin(), sortedNames.end());

    cout << "\nNames sorted alphabetically:\n";

    for (const string& name : sortedNames)


        {
            cout << name << "\n";
        }
}

int main()

{
    addPerson("Kasak", 50);
    addPerson("Annane", 78);
    addPerson("Kasvi", 24);
    addPerson("Pranish", 19);

    int ageLimit;

    cout << "Enter age to find people above: ";

    cin >> ageLimit;

    displayAboveAge(ageLimit);
    displaySortedNames();

    return 0;
}

