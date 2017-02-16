#include "Translator.hpp"

Translator::Translator(){
  //vowels = {'a', 'e', 'i', 'o', 'u', 'y'}
  vowels = "aeiouy";


}

std::string Translator::translate(const std::string& text) const{

  if( text.empty() ) {
    return "";
  }  
  
  // Take care of the case when the first letter is a vowel
  int vowelIndex = vowels.find(text[0]);
  bool isVowel = vowelIndex >= 0 && text[0] != 'y';
  if ( isVowel ) {
    return text + "way";
  }
  
  int textIndex = 1;
  vowelIndex = -1;
  do {
    vowelIndex = vowels.find(text[textIndex]);
    textIndex++;
  } while( textIndex < text.size() && vowelIndex < 0 );
  
  if( textIndex == text.size() ) {
    return text;  // No translation was possible, the word do not contain any vowels
  }
  
  return text.substr(textIndex-1) + text.substr(0,textIndex-1) + "ay";  
}
