#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */
vector<string> detonate(vector<string> grid, vector<string> all_bomb){
    int row = grid.size();
    int col = grid[0].size();
    for (int i=0; i<row; i++){
        for (int j=0; j< col; j++){
            if(grid[i][j]=='O'){
                    all_bomb[i][j]='.';
                    if (i-1>=0){
                        all_bomb[i-1][j]='.';}
                    if (i+1<row ){
                        all_bomb[i+1][j]='.';}
                    if (j-1>=0){
                        all_bomb[i][j-1]='.';}
                    if (j+1<col){
                        all_bomb[i][j+1]='.';}
                }
        }
    }
    return all_bomb;
}


vector<string> bomberMan(int n, vector<string> grid) {
    int row = grid.size();
    int col = grid[0].size();
    
    if (n==0 || n==1){
        return grid;
    }
    
   
    vector<string> all_bomb;
    string allBomb = "";
    for (int j =0; j< col; j++){
        allBomb +='O';
        }
    for (int i =0; i<row; i++) {
        all_bomb.push_back(allBomb);
    
    }
    
    
    if (n%4==0 || n%4==2){
        return all_bomb;
    }
   
    else if (n%4 ==3) {
        return detonate(grid, all_bomb);
    }
    else {
        vector<string> detonate_once = detonate(grid,all_bomb);
        return detonate(detonate_once, all_bomb);
    }
    return grid;
       
}
        

    
    



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
