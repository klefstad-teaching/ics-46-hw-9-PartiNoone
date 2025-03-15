#include "ladder.h"

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void test_edit_dis(){
    int d = edit_distance("sitting", "kitten");
    cout << "Kitten from sitting: " << d << endl;
    d = edit_distance("dog", "dog");
    cout << "dog from dog: " << d << endl;
    d = edit_distance("Dog", "dog");
    cout << "Dog from dog: " << d << endl;
    d = edit_distance("sunday", "saturday");
    cout << "saturday from sunday: " << d << endl;
}

void verify_wladder() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");

    vector<string> ladder1 = generate_word_ladder("cat", "dog", word_list);
    print_word_ladder(ladder1);
    cout << "size: " << ladder1.size() << endl;
    my_assert(ladder1.size() == 4);

    vector<string> ladder2 = generate_word_ladder("marty", "curls", word_list);
    print_word_ladder(ladder1);
    my_assert(ladder2.size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}

int main() {
    // test_edit_dis();
    verify_wladder();
}