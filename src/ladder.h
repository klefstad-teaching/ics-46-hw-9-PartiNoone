#include <iostream>
#include <fstream>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

void error(string word1, string word2, string msg);
int edit_distance(string s, string t);
bool edit_distance_is(const std::string& str1, const std::string& str2, int d);
bool edit_distance_within(const std::string& str1, const std::string& str2, int d);
bool is_one_insertion(const std::string& str1, const std::string& str2);
bool is_one_substitution(const string& s, const string& t);
bool is_adjacent(const string& word1, const string& word2);
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list);
void load_words(set<string> & word_list, const string& file_name);
void print_word_ladder(const vector<string>& ladder);
void verify_word_ladder();
