#pragma once

#include <string>
#include <vector>
#include <functional>
#include <algorithm>

namespace strings {
using string = std::string;

bool Contains(string, string);
bool Contains(string, unsigned char);
bool ContainsAny(string, string);
size_t Count(string, unsigned char);
size_t Count(string, string);
bool HasPrefix(string, string);
bool HasSuffix(string, string);
string Join(std::vector<string>, string);
string Join(std::vector<string>, unsigned char);
string Replace(string, unsigned char, unsigned char, size_t);
string Replace(string, string, string, size_t);
string ReplaceAll(string, string, string);
string ReplaceAll(string, unsigned char, unsigned char);
std::vector<string> Split(string, string);
std::vector<string> Split(string, unsigned char);
std::vector<string> SplitFunc(string, std::function<bool(unsigned char)>);
string ToLower(string);
string ToUpper(string);
string TrimPrefix(string, string);
string TrimSuffix(string, string);
string TrimSpace(string);

bool Contains(string buffer, unsigned char c) {
    return Contains(buffer, string(1, c));
}

bool Contains(string buffer, string substr) {
    return ((buffer.find(substr)) != string::npos);
}

bool ContainsAny(string buffer, string chars) {
    for (auto &c: chars) {
        if (Contains(buffer, c)) return true;
    }
    return false;
}

size_t Count(string buffer, unsigned char c) {
    return Count(buffer, string(1, c));
}

size_t Count(string buffer, string substr) {
    size_t count = 0;
    size_t position = 0;
    while ((position = buffer.find(substr, position)) != string::npos) {
        count++;
        position+=substr.length();
    }
    return count;
}

bool HasPrefix(string buffer, string prefix) {
    if (prefix.length() > buffer.length()) return false;
    auto bufferPrefix = buffer.substr(0, prefix.length());
    return (bufferPrefix == prefix); 
}

bool HasSuffix(string buffer, string suffix) {
    if (suffix.length() > buffer.length()) return false;
    auto bufferSuffix = buffer.substr(buffer.size()-suffix.length(), buffer.size());
    return (bufferSuffix == suffix);
}

string Join(std::vector<string> buffer, string delimiter) {
    std::string results;
    for (size_t i = 0; i < buffer.size(); i++) {
        results.append(buffer.at(i));
        if (i < buffer.size()-1) results.append(delimiter);
    }
    return results;
}

string Join(std::vector<string> buffer, unsigned char delimiter) {
    return Join(buffer, string(1, delimiter));
}

string Replace(string buffer, unsigned char token, unsigned char replacement, size_t count) {
    return Replace(buffer, string(1, token), string(1, replacement), count);
}

string Replace(string buffer, string token, string replacement, size_t count) {
    size_t position = 0;
    size_t n = 0;
    while ((position = buffer.find(token, position)) != string::npos && n < count) {
        buffer.replace(position, token.length(), replacement);
        position+=replacement.length();
        n++;
    }
    return buffer;
}

string ReplaceAll(string buffer, string token, string replacement) {
    size_t index = 0;
    while ((index = buffer.find(token, index)) != string::npos) {
        buffer.replace(index, token.length(), replacement);
        index+=replacement.length();
    }
    return buffer;
}

string ReplaceAll(string buffer, unsigned char token, unsigned char replacement) {
    return ReplaceAll(buffer, string(1, token), string(1, replacement));
}

std::vector<string> Split(string s, string delimiter) {
    std::vector<string> results{};
    size_t position = 0;
    size_t previous_index = 0;
    while ((position = s.find(delimiter, position)) != string::npos) {
        results.push_back(s.substr(previous_index, position));
        position+=delimiter.length();
        previous_index = position;
    }
    results.push_back(s.substr(previous_index, s.length()));
    return results;
}

std::vector<string> Split(string buffer, unsigned char delimiter) {
    return Split(buffer, string(1, delimiter));
}

std::vector<string> SplitFunc(string buffer, std::function<bool(unsigned char)> func) {
    std::vector<string> results{};
    string token;
    for (auto &c: buffer) {
        if (func(c)) {
            results.push_back(token);
            token.clear();
            continue;
        }
        token.push_back(c);
    }
    results.push_back(token);
    return results;
}

string ToLower(string buffer) {
    for (size_t position = 0; position < buffer.length(); position++) {
        auto theChar = buffer.at(position);
        if (theChar >= 65 && theChar <= 90) {
            buffer.at(position) += 32;
        }
    }
    return buffer;
}

string ToUpper(string buffer) {
    for (size_t position = 0; position < buffer.length(); position++) {
        auto theChar = buffer.at(position);
        if (theChar >= 97 && theChar <= 122) {
            buffer.at(position) -= 32;
        }
    }
    return buffer;
}

string TrimPrefix(string buffer, string prefix) {
    if (!HasPrefix(buffer, prefix)) return buffer;
    return buffer.substr(prefix.length(), buffer.length());
}

string TrimSuffix(string buffer, string suffix) {
    if (!HasSuffix(buffer, suffix)) return buffer;
    return buffer.substr(0, buffer.length()-suffix.length());
}

string TrimSpace(string buffer) {
    while (std::isspace(buffer.front())) {
        buffer.erase(buffer.begin());
    }
    while (std::isspace(buffer.back())) {
        buffer.pop_back();
    }
    return buffer;
}

}; // end namespace strings


