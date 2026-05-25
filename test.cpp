#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

bool openLetters(string word, string& table, char c) {
    bool found = false;
    for(size_t i=0; i<word.size(); ++i) {
        if (word[i] == c) {
            table[i] = c;
            found = true;
        }
    }
    return found;
}

void test_openLetters_success_single() {
    cout << "[RUN]     test_openLetters_success_single" << endl;
    string word = "apple";
    string table = "     ";
    char letter = 'a';
    
    cout << "  Input:  word=\"" << word << "\", table=\"" << table << "\", letter='" << letter << "'" << endl;
    bool result = openLetters(word, table, letter);
    cout << "  Output: result=" << (result ? "true" : "false") << ", table=\"" << table << "\"" << endl;
    
    assert(result == true);
    assert(table == "a    ");
    cout << "\033[32m[PASSED]\033[0m   test_openLetters_success_single\n" << endl;
}

void test_openLetters_success_multiple() {
    cout << "[RUN]     test_openLetters_success_multiple" << endl;
    string word = "banana";
    string table = "      ";
    char letter = 'a';
    
    cout << "  Input:  word=\"" << word << "\", table=\"" << table << "\", letter='" << letter << "'" << endl;
    bool result = openLetters(word, table, letter);
    cout << "  Output: result=" << (result ? "true" : "false") << ", table=\"" << table << "\"" << endl;
    
    assert(result == true);
    assert(table == " a a a");
    cout << "\033[32m[PASSED]\033[0m   test_openLetters_success_multiple\n" << endl;
}

void test_openLetters_fail() {
    cout << "[RUN]     test_openLetters_fail" << endl;
    string word = "cherry";
    string table = "      ";
    char letter = 'z';
    
    cout << "  Input:  word=\"" << word << "\", table=\"" << table << "\", letter='" << letter << "'" << endl;
    bool result = openLetters(word, table, letter);
    cout << "  Output: result=" << (result ? "true" : "false") << ", table=\"" << table << "\"" << endl;
    
    assert(result == false);
    assert(table == "      ");
    cout << "\033[32m[PASSED]\033[0m   test_openLetters_fail\n" << endl;
}

void test_words_not_empty() {
    cout << "[RUN]     test_words_not_empty" << endl;
    const vector<string> TEST_WORDS {
        "apricot", "apple", "avocado", "cherry", "kiwi", "banana", 
        "mango", "grape", "lime", "papaya", "fig", "peach", "pear", "plum", "watermelon", "lemon"
    };
    
    cout << "  Checking " << TEST_WORDS.size() << " words in the pool..." << endl;
    for(const string& w : TEST_WORDS) {
        assert(!w.empty());
    }
    cout << "\033[32m[PASSED]\033[0m   test_words_not_empty\n" << endl;
}

int main() {
    cout << "================ STARTING TESTS ================" << endl << endl;
    
    test_openLetters_success_single();
    test_openLetters_success_multiple();
    test_openLetters_fail();
    test_words_not_empty();
    
    cout << "================================================" << endl;
    cout << "\033[32mSUCCESS: ALL TESTS PASSED SUCCESSFULLY!\033[0m" << endl;
    return 0;
}
