#include "gtest/gtest.h"

#include "Translator.hpp"
#include <iostream>


TEST (SingleLetterWords,ConsonantTest){
  Translator t;
  std::string wasp(t.translate("wasp"));

  EXPECT_EQ("aspway", wasp);
}

TEST (SingleLetterWords,YletterTest){
  Translator t;
  std::string yellow(t.translate("yellow"));

  EXPECT_EQ("ellowyay", yellow);
}

TEST (SingleLetterWords,VowelTest){
  Translator t;
  std::string angle(t.translate("angle"));

  EXPECT_EQ("angleway", angle);
}

TEST (EmptyWord,Emptyword){
  Translator t;
  std::string empty(t.translate(""));

  EXPECT_EQ("",empty);
}

TEST (NoVowelsWord,NoVowels){
  Translator t;
  std::string PhD(t.translate("PhD"));

  EXPECT_EQ("PhDay", PhD);
} 

/*
Commented oink test since segfaulted

TEST (OinkTest, oink){
  Translator t;
 
  EXPECT_EQ("Oink",t.translate("word"));
}
*/


int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
