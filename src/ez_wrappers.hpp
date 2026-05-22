//Wrapper classes for c++ cause java has them and I'm jealous.
// Made by @JustJazzFR ( ͡° ͜ʖ ͡°)
#pragma once

#include <limits>
#include <type_traits>
#include <string>
#include <cstdlib>
#include <ctime>

namespace ezWrappers {
    template <typename T>
    class Float;

    class Character {
        char value;
    public:
        Character(char val) : value(val) {}
        char unwrap() const { return this -> value; }
        static Character wrap(char val) { return Character(val); }
        static const char* strToConstChar(const std::string& str) { return str.c_str(); }
        std::string to_string() { return std::string(1, this -> value); }

        Character operator+(Character& other) { return Character(this -> value + other.unwrap()); }
        Character operator-(Character& other) { return Character(this -> value - other.unwrap()); }
        Character operator*(Character& other) { return Character(this -> value * other.unwrap()); }
        Character operator/(Character& other) { return Character(this -> value / other.unwrap()); }
        Character operator%(Character& other) { return Character(this -> value % other.unwrap()); }
        Character operator<<(Character& other) { return Character(this -> value << other.unwrap()); }
        Character operator>>(Character& other) { return Character(this -> value >> other.unwrap()); }
        bool operator==(Character& other) { return this -> value == other.unwrap(); }
        bool operator!=(Character& other) { return this -> value != other.unwrap(); }
        bool operator<(Character& other) { return this -> value < other.unwrap(); }
        bool operator>(Character& other) { return this -> value > other.unwrap(); }
        bool operator<=(Character& other) { return this -> value <= other.unwrap(); }
        bool operator>=(Character& other) { return this -> value >= other.unwrap(); }
    };

    template <typename T>
    class Integer {
        T value;
    public:
        Integer(T val) {
            static_assert(std::is_integral<T>::value, "T needs to be an integral type");
            this -> value = val;
        }

        T unwrap() const { return this -> value; }
        void set(T newVal) { this -> value = newVal; }
        static int max32() { return std::numeric_limits<int>::max(); }
        static long max64() { return std::numeric_limits<long>::max(); }
        static int min32() { return std::numeric_limits<int>::min(); }
        static long min64() { return std::numeric_limits<long>::min(); }
        static short min16() { return std::numeric_limits<short>::min(); }
        static short max16() { return std::numeric_limits<short>::max(); }
        static Integer<T> wrap(T val) { return Integer<T>(val); }
        static Integer<T> fromFloat(Float<T> val) { return Integer<T>(static_cast<T>(val.unwrap())); }
        static Integer<T> fromCharacter(Character val) { return Integer<T>(static_cast<T>(val.unwrap())); }
        std::string to_string() { return std::to_string(this -> value); }

        Integer<T> operator+(Integer<T>& other) { return Integer<T>(this -> value + other.unwrap()); }
        Integer<T> operator-(Integer<T>& other) { return Integer<T>(this -> value - other.unwrap()); }
        Integer<T> operator*(Integer<T>& other) { return Integer<T>(this -> value * other.unwrap()); }
        Integer<T> operator/(Integer<T>& other) { return Integer<T>(this -> value / other.unwrap()); }
        Integer<T> operator%(Integer<T>& other) { return Integer<T>(this -> value % other.unwrap()); }
        Integer<T> operator<<(Integer<T>& other) { return Integer<T>(this -> value << other.unwrap()); }
        Integer<T> operator>>(Integer<T>& other) { return Integer<T>(this -> value >> other.unwrap()); }
        bool operator==(Integer<T>& other) { return this -> value == other.unwrap(); }
        bool operator!=(Integer<T>& other) { return this -> value != other.unwrap(); }
        bool operator<(Integer<T>& other) { return this -> value < other.unwrap(); }
        bool operator>(Integer<T>& other) { return this -> value > other.unwrap(); }
        bool operator<=(Integer<T>& other) { return this -> value <= other.unwrap(); }
        bool operator>=(Integer<T>& other) { return this -> value >= other.unwrap(); }
    };

    template <typename T>
    class Float {
        T value;
    public:
        Float(T val) {
            static_assert(std::is_floating_point<T>::value, "T needs to be a floating point type");
            this -> value = val;
        }

        T unwrap() const { return this -> value; }
        void set(T newVal) { this -> value = newVal; }
        static float max32() { return std::numeric_limits<float>::max(); }
        static float min32() { return std::numeric_limits<float>::min(); }
        static double max64() { return std::numeric_limits<double>::max(); }
        static double min64() { return std::numeric_limits<double>::min(); }
        static Float<T> wrap(T val) { return Float<T>(val); }
        static Float<T> fromInteger(Integer<T> val) { return Float<T>(static_cast<T>(val.val())); }
        std::string to_string() { return std::to_string(this -> value); }

        Float<T> operator+(Float<T>& other) { return Float<T>(this -> value + other.unwrap()); }
        Float<T> operator-(Float<T>& other) { return Float<T>(this -> value - other.unwrap()); }
        Float<T> operator*(Float<T>& other) { return Float<T>(this -> value * other.unwrap()); }
        Float<T> operator/(Float<T>& other) { return Float<T>(this -> value / other.unwrap()); }
        Float<T> operator%(Float<T>& other) { return Float<T>(this -> value % other.unwrap()); }
        Float<T> operator<<(Float<T>& other) { return Float<T>(this -> value << other.unwrap()); }
        Float<T> operator>>(Float<T>& other) { return Float<T>(this -> value >> other.unwrap()); }
        bool operator==(Float<T>& other) { return this -> value == other.unwrap(); }
        bool operator!=(Float<T>& other) { return this -> value != other.unwrap(); }
        bool operator<(Float<T>& other) { return this -> value < other.unwrap(); }
        bool operator>(Float<T>& other) { return this -> value > other.unwrap(); }
        bool operator<=(Float<T>& other) { return this -> value <= other.unwrap(); }
        bool operator>=(Float<T>& other) { return this -> value >= other.unwrap(); }
    };

    class Boolean {
        bool value;
    public:
        Boolean(bool val) : value(val) {}
        bool unwrap() const { return this -> value; }
        static Boolean wrap(bool val) { return Boolean(val); }
        static bool rndBool() { return std::rand() % 2 == 0; }
        std::string to_string() { return this -> value ? "true" : "false"; }

        bool operator==(Boolean& other) { return this -> value == other.unwrap(); }
        bool operator!=(Boolean& other) { return this -> value != other.unwrap(); }
        bool operator&&(Boolean& other) { return this -> value && other.unwrap(); }
        bool operator||(Boolean& other) { return this -> value || other.unwrap(); }
        bool operator!() { return !this -> value; }
    };
}
