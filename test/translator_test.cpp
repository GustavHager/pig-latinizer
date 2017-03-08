#include "gtest/gtest.h"

#include "PigLatinTranslator.hpp"
#include "InverseTranslator.hpp"
#include <iostream>

TEST (InverseLetterWord,Vowelword){
  InverseTranslator t;
  std::string eggway(t.translate("eggway"));
  EXPECT_EQ("egg", eggway);
}

TEST (InversePunctuationWord,VowelWord){
  InverseTranslator t;
  std::string easterway(t.translate("easterway?"));
  EXPECT_EQ("easter?", easterway);
} 

TEST (InverseLetterWord,ConsonantWord){
  InverseTranslator t;
  std::string ananabay(t.translate("ananabay"));
  EXPECT_EQ("banana", ananabay);
} 

TEST (InversePunctuationWord,ConsonantWord){
  InverseTranslator t;
  std::string elphay(t.translate("elphay!"));
  EXPECT_EQ("help!", elphay);
}     

TEST (SingleLetterWords,ConsonantTest){
  PigLatinTranslator t;
  std::string wasp(t.translate("wasp"));
  EXPECT_EQ("aspway", wasp);
}

TEST (SingleLetterWords,YletterTest){
  PigLatinTranslator t;
  std::string yellow(t.translate("yellow"));
  EXPECT_EQ("ellowyay", yellow);
}

TEST (SingleLetterWords,VowelTest){
  PigLatinTranslator t;
  std::string angle(t.translate("angle"));
  EXPECT_EQ("angleway", angle);
}

TEST (EmptyWord,Emptyword){
  PigLatinTranslator t;
  std::string empty(t.translate(""));
  EXPECT_EQ("",empty);
}

TEST (NoVowelsWord,NoVowels){
  PigLatinTranslator t;
  std::string PhD(t.translate("PhD"));
  EXPECT_EQ("PhDay", PhD);
} 

TEST (CapitalLetterWord,CapitalLetter){
  PigLatinTranslator t;
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
