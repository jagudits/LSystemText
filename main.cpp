#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
string get_replacement(char *key);
unordered_map<char, string> P;
int iterations = 6;

int main()
{
    //create map with replacement rules
    P.emplace('A', "AB");
    P.emplace('B', "A");

    //define word
    string w = "A";
    string final_word = w;

    //replace "iterations" times
    for(int i = 0; i < iterations; i++){
        string current = "";

        //iterate over characters
        for(int j = 0; j < final_word.size(); j++){
            current += get_replacement(&final_word[j]);
        }

        //update current word buffer
        final_word = current;
    }

    std::cout <<  final_word;


    return 0;
}

string get_replacement(char *key){
    return P[*key];
}
