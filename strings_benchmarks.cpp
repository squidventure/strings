#include <benchmark/benchmark.h>
#include <random>

#include "strings.hpp"

using string = std::string;
using vector = std::vector<string>;

const string AlphaChars = "abcdefghijklmnopqrstuvwxyz";

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> rng(0, AlphaChars.length()-1);

unsigned char randomChar() {
    return AlphaChars.at(rng(gen));
}

string randomString() {
    string results{};
    for (size_t i = 0; i < 3; i++) {
        results.push_back(randomChar());
    }
    return results;
}

static void BM_ContainsChar(benchmark::State& state) {
    string buffer = "the quick red fox jumps over the lazy brown dog";
    for (auto _: state) strings::Contains(buffer, randomChar());
}

static void BM_ContainsString(benchmark::State& state) {
    string buffer = "the quick red fox jumps over the lazy brown dog";
    for (auto _: state) strings::Contains(buffer, randomString());
}

static void BM_ContainsAny(benchmark::State& state) {
    string buffer = "the quick red fox jumps over the lazy brown dog";
    for (auto _: state) strings::ContainsAny(buffer, "dog");
}

static void BM_CountChar(benchmark::State& state) {
    string buffer = "the quick red fox jumps over the lazy brown dog";
    for (auto _: state) strings::Count(buffer, randomChar());
}

static void BM_CountString(benchmark::State& state) {
    string buffer = "the quick red fox jumps over the lazy brown dog";
    for (auto _: state) strings::Count(buffer, randomString());
}

static void BM_HasPrefix(benchmark::State& state) {
    string buffer = "the quick red fox jumps over the lazy brown dog";
    for (auto _: state) strings::HasPrefix(buffer, string(1, randomChar()));
}

static void BM_HasSuffix(benchmark::State& state) {
    string buffer = "the quick red fox jumps over the lazy brown dog";
    for (auto _: state) strings::HasSuffix(buffer, string(1, randomChar()));
}

static void BM_JoinString(benchmark::State& state) {
    vector buffer{"hello", "world"};
    for (auto _: state) strings::Join(buffer, " ");
}

static void BM_JoinChar(benchmark::State& state) {
    vector buffer{"hello", "world"};
    for (auto _: state) strings::Join(buffer, ' ');
}

static void BM_ReplaceString(benchmark::State& state) {
    string buffer = "hello world";
    for (auto _: state) strings::Replace(buffer, "l", "y", 2);
}

static void BM_ReplaceChar(benchmark::State& state) {
    string buffer = "hello world";
    for (auto _: state) strings::Replace(buffer, 'l', 'y', 2);
}

static void BM_ReplaceAllString(benchmark::State& state) {
    string buffer = "hello world";
    for (auto _: state) strings::ReplaceAll(buffer, "l", "y");
}

static void BM_ReplaceAllChar(benchmark::State& state) {
    string buffer = "hello world";
    for (auto _: state) strings::ReplaceAll(buffer, 'l', 'y');
}

static void BM_SplitString(benchmark::State& state) {
    string buffer = "hello cruel world";
    for (auto _: state) strings::Split(buffer, " ");
}

static void BM_SplitChar(benchmark::State& state) {
    string buffer = "hello cruel world";
    for (auto _: state) strings::Split(buffer, ' ');
}

static void BM_SplitFunc(benchmark::State& state) {
    string buffer = "hello cruel world";
    std::function<bool(unsigned char c)> theFunc = [](unsigned char c) {return std::isspace(c);};
    for (auto _: state) strings::SplitFunc(buffer, theFunc);
}

static void BM_ToLower(benchmark::State& state) {
    string buffer = "HELLO CRUEL WORLD";
    for (auto _: state) strings::ToLower(buffer);
}

static void BM_ToUpper(benchmark::State& state) {
    string buffer = "hello cruel world";
    for (auto _: state) strings::ToUpper(buffer);
}

static void BM_TrimPrefix(benchmark::State& state) {
    string buffer = "url: https://localhost:8080/message";
    for (auto _: state) strings::TrimPrefix(buffer, "url: ");
}

static void BM_TrimSuffix(benchmark::State& state) {
    string buffer = "url: https://localhost:8080/message";
    for (auto _: state) strings::TrimSuffix(buffer, "/message");
}

static void BM_TrimSpace(benchmark::State& state) {
    string buffer = "\t  hello world  ";
    for (auto _: state) strings::TrimSpace(buffer);
}

BENCHMARK(BM_ContainsString);
BENCHMARK(BM_ContainsChar);
BENCHMARK(BM_ContainsAny);
BENCHMARK(BM_CountChar);
BENCHMARK(BM_CountString);
BENCHMARK(BM_HasPrefix);
BENCHMARK(BM_HasSuffix);
BENCHMARK(BM_JoinString);
BENCHMARK(BM_JoinChar);
BENCHMARK(BM_ReplaceString);
BENCHMARK(BM_ReplaceChar);
BENCHMARK(BM_ReplaceAllString);
BENCHMARK(BM_ReplaceAllChar);
BENCHMARK(BM_SplitString);
BENCHMARK(BM_SplitChar);
BENCHMARK(BM_SplitFunc);
BENCHMARK(BM_ToLower);
BENCHMARK(BM_ToUpper);
BENCHMARK(BM_TrimPrefix);
BENCHMARK(BM_TrimSuffix);
BENCHMARK(BM_TrimSpace);




BENCHMARK_MAIN();
