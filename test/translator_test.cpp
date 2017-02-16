#include <gtest/gtest.h>

#include "Translator.hpp"

TEST (OinkTest, oink){
  Translator t;
  
  EXPECT_EQ("Oink",t.translate("word"));
}



int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
