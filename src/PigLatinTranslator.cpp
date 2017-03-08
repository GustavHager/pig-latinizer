#include "PigLatinTranslator.hpp"

PigLatinTranslator::PigLatinTranslator(){
  vowels = "aeiouyAEIOUY";
  punctuation = ".,!?:;()[]{}<>`´\'\"";
}

std::string PigLatinTranslator::translate(const std::string& text) const{

  if( text.empty() ) {
    return "";
  }

  std::vector<std::string> punct_sep_str = separate_punctuation(text);

  std::string transl_word = translate_word(punct_sep_str[1]);

  return punct_sep_str[0] + transl_word + punct_sep_str[2];
}


std::string PigLatinTranslator::translate_word(const std::string& word) const{

  if( word.empty() ) {
    return "";
  }

  std::string translation = word;

  bool isCapitalFirst = is_upper_case(translation[0]);
  if( isCapitalFirst && !is_all_upper_case(translation) ) {
    translation[0] = to_lower_case(translation[0]);
  }

  // Take care of the case when the first letter is a vowel
  int vowelIndex = vowels.find(translation[0]);
  bool isVowel = vowelIndex >= 0 && translation[0] != 'y';
  if( isVowel ) {
    if( isCapitalFirst && !is_upper_case(translation[0]) ) {
      translation[0] = to_upper_case(translation[0]);
    }
    return translation + "way";
  }

  int translationIndex = 1;
  vowelIndex = -1;
  do {
    vowelIndex = vowels.find(translation[translationIndex]);
    translationIndex++;
  } while( translationIndex < translation.size() && vowelIndex < 0 );

  // If The word does not contain any vowels
  if( translationIndex == translation.size() && vowelIndex < 0 ) {
    if( isCapitalFirst && !is_upper_case(translation[0]) ) {
      translation[0] = to_upper_case(translation[0]);
    }
    return translation + "ay";
  }

  // If The word contain vowels
  translation = translation.substr(translationIndex-1) + translation.substr(0,translationIndex-1);
  if( isCapitalFirst && !is_upper_case(translation[0]) ) {
    translation[0] = to_upper_case(translation[0]);
  }
  return translation + "ay";
}


std::vector<std::string> PigLatinTranslator::separate_punctuation(const std::string& text) const {
    std::vector<std::string> punct_sep_str(3);

    if( text.empty() ) {
        return punct_sep_str;
    }

    // Find beginning of the word
    int word_start = 0;
    while (word_start < text.size() && is_punctuation(text[word_start])) {
        word_start++;
    }

    // Store start punctuation
    if (word_start > 0) {
        punct_sep_str[0] = text.substr(0, word_start);
    }
    if (word_start == text.size()) {
        // Only punctuation
        return punct_sep_str;
    }

    // Find end of word
    int word_end = text.size() - 1;
    while (word_end > 0 && is_punctuation(text[word_end])) {
        word_end--;
    }

    // Store end punctuation
    if (word_end < text.size()) {
        punct_sep_str[2] = text.substr(word_end+1);
    }

    // Store word and return
    punct_sep_str[1] = text.substr(word_start, word_end - word_start + 1);
    return punct_sep_str;
}

bool PigLatinTranslator::is_punctuation(const char c) const {
    return punctuation.find(c) != std::string::npos;
}

std::string to_lower_case(std::string str) {
  for(std::string::iterator letter = str.begin(); letter != str.end(); letter++) {
    if(is_upper_case(*letter)) {
      *letter = to_lower_case(*letter);
    }
  }
  return str;
}

std::string to_upper_case(std::string str) {
  for(std::string::iterator letter = str.begin(); letter != str.end(); letter++) {
    if(!is_upper_case(*letter)) {
      *letter = to_upper_case(*letter);
    }
  }
  return str;
}

char to_lower_case(char letter) {
  return letter - 'A' + 'a';
}

char to_upper_case(char letter) {
  return letter + 'A' - 'a';
}

bool is_upper_case(char letter) {
  return letter >= 'A' && letter <= 'Z'; 
}

bool is_all_upper_case(std::string str) {
  bool isTrue = true;
  for(std::string::iterator letter = str.begin(); letter != str.end(); letter++) {
    isTrue &= is_upper_case(*letter);
  }
  return isTrue;
}
