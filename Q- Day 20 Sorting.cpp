/*Author: Omar Ashraf*/
/*
_______/\\\\\_________________/\\\\____________/\\\\_______________/\\\\\\\\\_________________/\\\\\\\\\_____
 _____/\\\///\\\______________\/\\\\\\________/\\\\\\_____________/\\\\\\\\\\\\\_____________/\\\///////\\\___
  ___/\\\/__\///\\\____________\/\\\//\\\____/\\\//\\\____________/\\\/////////\\\___________\/\\\_____\/\\\___
   __/\\\______\//\\\___________\/\\\\///\\\/\\\/_\/\\\___________\/\\\_______\/\\\___________\/\\\\\\\\\\\/____
    _\/\\\_______\/\\\___________\/\\\__\///\\\/___\/\\\___________\/\\\\\\\\\\\\\\\___________\/\\\//////\\\____
     _\//\\\______/\\\____________\/\\\____\///_____\/\\\___________\/\\\/////////\\\___________\/\\\____\//\\\___
      __\///\\\__/\\\______________\/\\\_____________\/\\\___________\/\\\_______\/\\\___________\/\\\_____\//\\\__
       ____\///\\\\\/_______________\/\\\_____________\/\\\___________\/\\\_______\/\\\___________\/\\\______\//\\\_
        ______\/////_________________\///______________\///____________\///________\///____________\///________\///__
*/
#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    //====================================================//
    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        // Track number of elements swapped during a single array traversal
        int numberOfSwaps = 0;
        for (int j = 0; j < n - 1; j++)
        {
            // Swap adjacent elements if they are in decreasing order
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                numberOfSwaps++;
            }
        }
        // If no elements were swapped during a traversal, array is sorted
        if (numberOfSwaps == 0)
        {
            break;
        }
        //add all the number of swaps in each traversal to get the number of swaps
        swaps += numberOfSwaps;
    }
    cout << "Array is sorted in " << swaps << " swaps.\n";
    cout << "First Element: " << a[0] << "\n";
    cout << "Last Element: " << a[n - 1] << "\n";
    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
