#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string get_replacement(char *key);

unordered_map<char, string> P;
int iterations = 35; // 6

int main()
{
    //create map with replacement rules
    P.emplace('A', "AB");
    P.emplace('B', "A");

    //define word
    string w = "A"; // A
    string final_word = w;

    //replace "iterations" times
    for(int i = 0; i < iterations; i++){
        string current = "";

        //iterate over characters
        for(size_t j = 0; j < final_word.size(); j++){
            current += get_replacement(&final_word[j]);
        }

        //update current word buffer
        final_word = current;
    }

//    std::cout <<  final_word;
    std::cout << "Size of the result (chars): " << final_word.size();

    return 0;
}

string get_replacement(char *key)
{
    try
    {
        // return the successor string of the production rule according to key
        return P.at(*key);
    }
    catch(std::out_of_range e)
    {
        // key was not found in P
        // treat key as a constant so just return it
        return string(key);
    }
}
