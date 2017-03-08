#include "InverseTranslator.hpp"


InverseTranslator::InverseTranslator(){
  //vowels = {'a', 'e', 'i', 'o', 'u', 'y'}
  vowels = "aeiouyAEIOUY";
}

std::string InverseTranslator::translate(const std::string& text) const{

  if( text.empty() ) {
    std::cout << "Returning empty word\n";
    return "";
  } 

  // Check if punctuation mark at end of word
  // Save mark as "end" and add to end of output
  int textLength = text.size();
  std::string word;
  std::string end;

  if (is_punct_mark_end(text)) {
    word = text.substr(0,textLength-1);
    end = text.substr(textLength-1);
  }
  else {
    word = text;
    end = "";
  }

  //Check that word ends with "ay", otherwise return word as is
  bool last2_ay = is_last_2_ay(word);
  if(!last2_ay) {
    return text;
  }

  //Check if word ends with "way"
  //If so, could either originate from word beginning with "w" or with vowel
  //word -> ordway, egg -> eggway
  int word_length = word.size();
  bool last3_way = is_last_3_way(word);
  //std::cout << "Last3_way: " << last3_way << "\n";

  if(last3_way) {  
    std::string stem = word.substr(0,word_length-3);
    PigLatinTranslator t;
    //Vowel beginning word if stem translates to word
    if( word.compare(t.translate(stem)) == 0 && stem.size() > 0) {
      return stem + end;
    }
  }

  //All words now remaining are words ending with "ay"
  if(last2_ay) {
    std::string stem = word.substr(0,word_length-2);
    PigLatinTranslator t;

    //If stem ends with a bunch of consonants, impossible to know how many
    //consonants to retain at end of stem without checking if word exists in
    //dictionary.
    //star -> arstay, tars -> arstay
    
    std::string stem_lc = to_lower_case(stem);
    std::string word_lc = to_lower_case(word);
    
    int stem_size = stem.size(), letter_index = stem.size();
    int match = -1;
    int vowel_index = -1;
    std::string word_test;


    //Test words by moving letters from end of stem to beginning
    //Check that translation matches with stem (lower-case match)

    while(match != 0 && vowel_index < 0  &&  letter_index >=0) {
      letter_index--;
      word_test = stem_lc.substr(letter_index, stem_size-letter_index) +
	stem_lc.substr(0,letter_index);
      match = word_lc.compare(t.translate(word_test));
      vowel_index = vowels.find(stem[letter_index]);
    }

    if(match == 0) {
      bool isCapitalFirst = is_upper_case(stem[0]);
      bool isAllCapitals = is_all_upper_case(stem);
      std::string translation;
      if(isCapitalFirst && !isAllCapitals) {
	stem[0] = to_lower_case(stem[0]);
      }
      translation = stem.substr(letter_index, stem_size-letter_index) + 
        stem.substr(0,letter_index);
      if(isCapitalFirst && !isAllCapitals) {
	translation[0] = to_upper_case(translation[0]);
      }      
      return translation + end;
    }
    else {
      return stem + end;
    }
  }

}

bool is_punct_mark_end(std::string str) {
  std::string::iterator end = str.end()-1;
  return (*end >= '!' && *end <= '.') || (*end >= ':' && *end <= '?');
}

bool is_last_2_ay(std::string str) {
  int str_length = str.size();
  std::string end;
  if (str_length < 2) {
    return false;
  }
  else {
    end = str.substr(str_length-2,2);
    return (end.compare("ay") == 0);
  }
}

bool is_last_3_way(std::string str) {
  int str_length = str.size();
  std::string end;
  if (str_length < 3) {
    return false;
  }
  else {
    end = str.substr(str_length-3,3);
    return (end.compare("way") == 0);
  }
}
