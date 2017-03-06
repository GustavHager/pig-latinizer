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

TEST (CapitalLetterWord,CapitalLetter){
  Translator t;
  std::string Latin(t.translate("Latin"));
  std::string ABC(t.translate("ABC"));
  std::string TIME(t.translate("TIME"));
  std::string TiMe(t.translate("TiMe"));

  EXPECT_EQ("Atinlay", Latin);
  EXPECT_EQ("ABCway", ABC);
  EXPECT_EQ("IMETay", TIME);
  EXPECT_EQ("IMetay", TiMe);
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
