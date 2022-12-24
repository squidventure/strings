#include <gtest/gtest.h>
#include <functional>

#include "strings.hpp"

using string = std::string;
using vector = std::vector<string>;

TEST(TestStrings, TestContainsString) {
    string buffer = "hello world";
    EXPECT_TRUE(strings::Contains(buffer, "hell"));
    EXPECT_FALSE(strings::Contains(buffer, "Hell"));
}

TEST(TestStrings, TestContainsChar) {
    string buffer = "hello world";
    EXPECT_TRUE(strings::Contains(buffer, "h"));
    EXPECT_FALSE(strings::Contains(buffer, "z"));
}

TEST(TestStrings, TestContainsAny) {
    string buffer = "hello world";
    EXPECT_TRUE(strings::ContainsAny(buffer, "abcd"));
    EXPECT_FALSE(strings::ContainsAny(buffer, "xyz"));
}

TEST(TestStrings, TestCountChar) {
    string buffer = "hello world";
    EXPECT_EQ(strings::Count(buffer, 'o'), 2);
    EXPECT_EQ(strings::Count(buffer, 'c'), 0);
}

TEST(TestStrings, TestCountSubString) {
    string buffer = "abra kadabra";
    EXPECT_EQ(strings::Count(buffer, "ra"), 2);
    EXPECT_EQ(strings::Count(buffer, "seen"), 0);
}

TEST(TestStrings, TestHasPrefix) {
    string buffer = "url: http://localhost:8080/message";
    EXPECT_TRUE(strings::HasPrefix(buffer, "url: "));
    EXPECT_FALSE(strings::HasPrefix(buffer, "/message"));
}

TEST(TestStrings, TestHasSuffix) {
    string buffer = "url: http://localhost:8080/message";
    EXPECT_TRUE(strings::HasSuffix(buffer, "/message"));
    EXPECT_FALSE(strings::HasSuffix(buffer, "url: "));    
}

TEST(TestStrings, TestJoinChar) {
    vector buffer{"h", "e", "l", "l", "o", " ", "w", "o", "r", "l", "d"};
    EXPECT_EQ(strings::Join(buffer, ' '), "h e l l o   w o r l d");
}

TEST(TestStrings, TestJoinString) {
    vector buffer{"h", "e", "l", "l", "o", " ", "w", "o", "r", "l", "d"};
    EXPECT_EQ(strings::Join(buffer, ""), "hello world");
}

TEST(TestStrings, TestReplaceChars) {
    string buffer = "hello world";
    EXPECT_EQ(strings::Replace(buffer, 'o', 'z', 1), "hellz world");
    EXPECT_EQ(strings::Replace(buffer, 'z', 'y', 1), buffer);
}

TEST(TestStrings, TestReplaceStrings) {
    string buffer = "hello world";
    EXPECT_EQ(strings::Replace(buffer, "l", "y", 1), "heylo world");
    EXPECT_EQ(strings::Replace(buffer, "z", "y", 1), buffer);
}

TEST(TestStrings, TestReplaceAllChar) {
    string buffer = "hello world";
    EXPECT_EQ(strings::ReplaceAll(buffer, 'l', 'o'), "heooo worod");
    EXPECT_EQ(strings::ReplaceAll(buffer, 'a', 'z'), buffer);
}

TEST(TestStrings, TestReplaceAllString) {
    string buffer = "hello world";
    EXPECT_EQ(strings::ReplaceAll(buffer, "l", "oo"), "heooooo worood");
    EXPECT_EQ(strings::ReplaceAll(buffer, "a", "z"), buffer);
}

TEST(TestStrings, TestSplitChar) {
    string buffer = "hello world";
    auto split = strings::Split(buffer, ' ');
    EXPECT_EQ(split.size(), 2);
    EXPECT_EQ(split.at(0), "hello");
    EXPECT_EQ(split.at(1), "world");
}

TEST(TestStrings, TestSplitString) {
    string buffer = "hello world";
    auto split = strings::Split(buffer, " ");
    EXPECT_EQ(split.size(), 2);
    EXPECT_EQ(split.at(0), "hello");
    EXPECT_EQ(split.at(1), "world");
}

TEST(TestStrings, TestSplitFunc) {
    std::function<bool(unsigned char)> theFunc = [](unsigned char c) {return std::isspace(c);};
    string buffer = "hello world";
    auto split = strings::SplitFunc(buffer, theFunc);
    EXPECT_EQ(split.size(), 2);
    EXPECT_EQ(split.at(0), "hello");
    EXPECT_EQ(split.at(1), "world");
}

TEST(TestStrings, TestToLower) {
    string buffer = "SQUID";
    EXPECT_EQ(strings::ToLower(buffer), "squid");
}

TEST(TestStrings, TestToUpper) {
    string buffer = "squid";
    EXPECT_EQ(strings::ToUpper(buffer), "SQUID");
}

TEST(TestStrings, TestTrimPrefix) {
    string buffer = "url: localhost:8080/message";
    EXPECT_EQ(strings::TrimPrefix(buffer, "url: "), "localhost:8080/message");
}

TEST(TestStrings, TestTrimSuffix) {
    string buffer = "url: localhost:8080/message";
    EXPECT_EQ(strings::TrimSuffix(buffer, "/message"), "url: localhost:8080");
}

TEST(TestStrings, TestTrimSpace) {
    string buffer = "  \t squid   \t ";
    EXPECT_EQ(strings::TrimSpace(buffer), "squid");
}

auto main(int argc, char* argv[]) -> int {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}