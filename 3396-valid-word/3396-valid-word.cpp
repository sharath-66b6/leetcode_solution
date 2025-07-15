class Solution {
public:
    static bool isVowel(char c) {
        string kVowels = "aeiouAEIOU";
        return kVowels.find(c) != string::npos;
    }

    static bool isConsonant(char c) {
        return isalpha(c) && !isVowel(c);
    }
    bool isValid(string word) {
        return word.length() >= 3 &&
            ranges::all_of(word, [](char c) { return isalnum(c); }) &&
            ranges::any_of(word, isVowel) && ranges::any_of(word, isConsonant);
    }
};