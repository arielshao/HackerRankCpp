#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */
 
 // function to generate the first N prime numbers.
vector<int> generatePrimes(int N){
    vector<int> primes;
    primes.push_back(2);
    int num =3; // start checking for prime numbers from 3.
    while (primes.size()<N){
        bool is_prime= true;
        
        for (int i=0; i<primes.size(); i++){
            if (num % primes[i]==0){
                is_prime = false;
                break;  // exit the loop since it is not a prime.
            }
        }
        if (is_prime){
            primes.push_back(num);
        }
        num +=2; // update num to the next odd number.
    }
    
    return primes;
}


vector<int> waiter(vector<int> number, int q) {
    stack<int> A, B, tempA;
    vector<int> ans;
    
    vector<int> primes = generatePrimes(q);
   
   //convert the vector number into stack, call it 'tempA'.   
    for (auto &elem: number){
        tempA.push(elem);
    }
        
    int m=primes.size();
    while (q>0){
        while (!tempA.empty()){
            int num = tempA.top();
            if (num %primes[m-q]==0){
                B.push(num);
                tempA.pop();
            }
            else{
                A.push(num);
                tempA.pop();
            }
        }
        tempA =A;
        // empty stack A.
        while (A.size() != 0) {
            A.pop();
        }   
        // move the stack B values to the res
        while(!B.empty()){
            ans.push_back(B.top());
            B.pop();
        }
        q--;
    }     
        // if stack A not empty until all iterations, move it to res;
        while(!tempA.empty()){
            ans.push_back(tempA.top());
            tempA.pop();   
        }

        return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

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
