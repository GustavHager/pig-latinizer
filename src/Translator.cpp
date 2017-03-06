#include "Translator.hpp"

Translator::Translator(){
  vowels = "aeiouyAEIOUY";
}

std::string Translator::translate(const std::string& text) const{

  if( text.empty() ) {
    return "";
  }

  std::string translation = text;

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
  if( translationIndex == translation.size() ) {
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
