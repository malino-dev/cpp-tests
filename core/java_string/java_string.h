#ifndef JAVA_STRING_H
#define JAVA_STRING_H

#include <iostream>
#include <cstdint>
#include <cstring>

namespace mylib {
    class jstr {
        private:
            char* s;
            int32_t n;
        public:
            const int32_t& length = n;

            jstr();
            jstr(const jstr& rhs);
            jstr(jstr&& rhs);
            jstr(char c);
            jstr(const char* str);
            jstr(const char* str, int32_t offset, int32_t count);
            jstr(bool b);
            jstr(int16_t value);
            jstr(uint16_t value);
            jstr(int32_t value);
            jstr(uint32_t value);
            jstr(int64_t value);
            jstr(uint64_t value);

            ~jstr();

            // https://docs.oracle.com/javase/9/docs/api/java/lang/String.html
            char char_at(int32_t index) const;

            int32_t compare_to(jstr& other) const;
            int32_t compare_to_ignore_case(jstr& other) const;

            jstr concat(jstr& other) const;

            bool contains(jstr& other) const;

            bool ends_with(jstr& other) const;

            bool equals(jstr& other) const;

            int32_t index_of(char c, int32_t from) const;
            int32_t index_of(char c) const;
            int32_t index_of(jstr& other, int32_t from) const;
            int32_t index_of(jstr& other) const;

            bool is_empty();

            int last_index_of(char c, int32_t from) const;
            int last_index_of(char c) const;
            int last_index_of(jstr& other, int32_t from) const;
            int last_index_of(jstr& other) const;

            bool matches(jstr& regex) const;

            jstr replace(char old_c, char new_c) const;
            jstr replace_all(jstr& regex, jstr& replacement) const;
            jstr replace_first(jstr& regex, jstr& replacement) const;

            jstr* split(jstr& regex) const; // HEAP - NOT MANAGED
            jstr* split(jstr& regex, int32_t limit) const; // HEAP - NOT MANAGED

            bool starts_with(jstr& prefix) const;
            bool starts_with(jstr& prefix, int32_t offset) const;

            jstr substring(int32_t start) const;
            jstr substring(int32_t start, int32_t end) const;

            char* to_char_array() const; // HEAP - NOT MANAGED

            jstr to_lower_case() const;
            jstr to_upper_case() const;

            jstr ltrim() const;
            jstr rtrim() const;
            jstr trim() const;

            jstr& operator=(const jstr&);
            jstr& operator=(jstr&& rhs);
            jstr& operator=(const char* str);

            char& operator[](int32_t i) const;

            jstr operator+(const jstr& rhs) const;
            jstr& operator+=(const jstr& rhs);

            jstr operator*(int32_t amount) const;
            jstr& operator*=(int32_t amount);
    };
}

namespace std {
    inline ostream& operator<<(ostream& os, const mylib::jstr& rhs) {
        for(int32_t i = 0; i < rhs.length; i += 1) {
            os << rhs[i];
        }

        return os;
    }
}

#endif
