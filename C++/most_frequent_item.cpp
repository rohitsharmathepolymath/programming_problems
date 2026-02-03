#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

string mostFrequentItem(string items, char delimiter) {
    unordered_map<string, int> freqMap;
    stringstream ss(items);
    string item;
    vector<string> itemOrder;

    // Split the string by the delimiter and populate frequency map
    while (getline(ss, item, delimiter)) {
        if (freqMap[item] == 0) {
            itemOrder.push_back(item); // Maintain the order of first occurrence
        }
        freqMap[item]++;
    }

    // Find the most frequent item
    string mostFrequent;
    int maxFreq = 0;
    for (const auto& key : itemOrder) {
        if (freqMap[key] > maxFreq) {
            maxFreq = freqMap[key];
            mostFrequent = key;
        }
    }

    return mostFrequent;
}

int main() {
    string items;
    char delimiter;

    // Input the string and delimiter
    cout << "Enter the string of items: ";
    getline(cin, items);
    cout << "Enter the delimiter: ";
    cin >> delimiter;

    // Get the most frequent item
    string result = mostFrequentItem(items, delimiter);

    // Output the result
    cout << "The most frequently occurring item is: " << result << endl;

    return 0;
}
