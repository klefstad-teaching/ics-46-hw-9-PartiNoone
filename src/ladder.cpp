#include "ladder.h"

void error(string word1, string word2, string msg){
    cout << "Error on words " << word1 << " and " << word2 << ": " << msg << endl;
}

int edit_distance(string s, string t){
    // for all i and j, d[i,j] will hold the distance between
    // the first i characters of s and the first j characters of t
    // note that d has (m+1)*(n+1) values
    int m = s.size() + 1;
    int n = t.size() + 1;
    // declare int d[0..m, 0..n], set each element to 0
    // new int d[m][n] = {0};
    int **d = new int*[m];
    for(int i=0; i<m; ++i) {
        d[i] = new int[n] {0};
    }

    // source prefixes can be transformed into empty string by dropping all characters
    for (int i = 1; i < m; ++i)
        d[i][0] = i;

    // target prefixes can be reached from empty source prefix
    // by inserting every character
    for (int j = 1; j < n; ++j)
        d[0][j] = j;

    int substitutionCost = 0;
    for (int j = 1; j < n; ++j){
        int indexj = j-1;
        t[indexj] = (65 <= t[indexj] && t[indexj] <= 90) ? t[indexj] + 32 : t[indexj]; // turn t letter to lowercase
        for (int i = 1; i < m; ++i){
            int indexi = i-1;
            s[indexi] = (65 <= s[indexi] && s[indexi] <= 90) ? s[indexi] + 32 : s[indexi]; // turn s letter to lowercase
            substitutionCost = s[indexi] == t[indexj] ? 0 : 1;
            int min1 = min(d[i-1][j] + 1, d[i][j-1] + 1); // deletion and insertion
            d[i][j] = min(min1, d[i-1][j-1] + substitutionCost); // min1 and substitution
        }
    }
    int result = d[m-1][n-1]; // bottom right corner of matrix
    for(int i=0; i<m; ++i) {
        delete [] d[i]; // need the [] before d since we’re specifying that we’re deallocating an array
    }
    delete [] d;

    return result;
}

bool edit_distance_is(const string& str1, const string& str2, int d){
    // returns true if edit distance is within d
    int distance = edit_distance(str1, str2);
    return distance == d;
}

bool edit_distance_within(const string& str1, const string& str2, int d){
    // returns true if edit distance is within d
    if (d == 1){
        int size1 = str1.size();
        int size2 = str2.size();
        int size_diff = abs(size1 - size2);
        if (size_diff > 1){
            return false;
        } else if (size_diff == 1) {
            return size1 > size2 ? is_one_insertion(str2, str1): is_one_insertion(str1, str2);
        } else if (size_diff == 0) { return is_one_substitution(str1, str2); }
    }
    int distance = edit_distance(str1, str2);
    return distance <= d;
}

bool is_one_insertion(const string& small, const string& big){
    int i = 0;
    int j = 0;
    int count = 0;
    int lim1 = small.size();
    int lim2 = big.size();
    while (i < lim1 && j < lim2){
        if (small[i] != big[j]){
            ++j;
            ++count;
            if (count > 1) return false;
        } else {
            ++i;
            ++j; 
        }
    }
    return true;
}

bool is_one_substitution(const string& s, const string& t){
    int count = 0;
    int lim = s.size();
    for (int i = 0; i < lim; ++i){
        if (s[i] != t[i]){
            ++count;
            if (count > 1) return false;
        }
    }
    return true;
}

bool is_adjacent(const string& str1, const string& str2){
    return edit_distance_within(str1, str2, 1);
}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
    vector<string> beginning = {begin_word};
    if (begin_word == end_word){ // check that begin != end
        return beginning;
    }
    queue<vector<string>> ladder_queue; // ladder_queue = queue of vector of strings
    ladder_queue.push(beginning);
    set<string> visited; // visited = set of strings
    visited.insert(begin_word);
    while (!ladder_queue.empty()) {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder.back(); // last_word = last element of ladder
        for (string word: word_list){
            if (is_adjacent(last_word, word)) {
                if (!visited.contains(word)) {
                    visited.insert(word);
                    vector<string> new_ladder(ladder); // copy constructor
                    new_ladder.push_back(word);
                    if (word == end_word) { return new_ladder; }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    beginning.clear();
    return beginning;
}

void load_words(set<string> & word_list, const string& file_name){
    ifstream inFile;
    inFile.open(file_name);
    string line;
    while (getline(inFile, line)) {
        word_list.insert(line);
    }
    inFile.close();
}

void print_word_ladder(const vector<string>& ladder){
    int s = ladder.size();
    if (s == 0){
        cout << "No word ladder found." << endl;
        return;
    } else {
        cout << "Word ladder found: ";
        for (int i = 0; i < s; ++i){
            cout << ladder[i] << " ";
        }
        cout << endl;
    }
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}
void verify_word_ladder() {
    set<string> word_list;
    load_words(word_list, "words.txt");
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}