#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    
    //create a hashmap namely 'map' to count the frequency of each character in string s;
    unordered_map<char, int> map;
    for (char c:s){
        map[c]++;
    }
    
    //create a hashmap namely 'freq' to count the frequency of each value in the hashmap 'map'.
    unordered_map<int,int> freq;
    for (auto ele : map){
        freq[ele.second]++;
    }
    
    
    // for each element in the hashmap 'freq', track the maxFreq of the value as well as the corresponding key.
    int maxFreq =0, maxFreq_key=0;
    for (auto f:freq){  
        if (f.second>maxFreq){
            maxFreq=f.second;
            maxFreq_key = f.first; //maxFreq_key is the most frequent frequency in hashmap map.
        }
    }
    
    // loop through the orginal hashmap 'map' and check the difference between the value in this hashmap and the most 
    // frequent frequency 'maxFreq_key', eg. if the difference is 1, need to remove the element once. If the value 
    // is 1, we can simply remove that corresponding char from string 's' as well. 
    int  removeCounter =0;
    for (auto ele: map){
        if (ele.second==1|| abs(ele.second-maxFreq_key)==1){
            removeCounter++;     
        }
        else if (abs(ele.second-maxFreq_key)>1){
            return "NO";
        }
    }
    if (removeCounter<=1){
        return "YES";
    }
    else {
        return "NO";
    }

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
