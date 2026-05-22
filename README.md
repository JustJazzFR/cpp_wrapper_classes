# cpp_wrapper_classes
wrapper classes for c++ cause java has them and i'm jealous.

there r 4 wrapper classes(Character, Integer<T>, Float<T>, Boolean)
Integer and Float are intened to be used with integral and floating point types respectively.
heres all the functions and what not for each class.


(for all the wrapper classes that use numeric types, integer, float, char, you can use all math/comparison operators on them. plz tell me if i'm missing any)
Integer:
Integer(T val) -- constructor tht accepts an integral value for T and will error if its not an integral type.
T unwrap() -- returns the inner value of the instance of the class
void set(T newVal) -- sets inner value to a new value
static int max16/32/64() -- returns the max value for each integer size
staic int min16/32/64() -- returns the minimum value for each integer size
static Integer<T> wrap(T val) -- wraps an integer value into an integer class. Yes this can be used as a second constructor
static Integer<T> fromFloat/Character(Float<T>/Character val) -- returns an integer class from the value of a character/float class
std::string to_string() -- converts the value to a string (all wrapper classes have these)

Float:
Float(T val) -- constructor that accepts a floating point value and errors if its not a floating point value
T unwrap() -- returns the inner value of the instance of the class
void set() -- sets the current value to a new value
static float/double max32/64() -- returns the max value for double and float types
static float/double min32/64() -- returns the minimum value for double and float types
static Float<T> wrap(T val) -- wraps a floating point value into a float class. yes this can be used as a second constructor
static Float<T> fromInteger(Integer<T> val) -- converts an instance of an integer class into a Float class.

Character:
Character(char val) -- constructor that accepts a character value
char unwrap() -- returns the inner value
static Character wrap(char val) -- wraps a char value into a Character class. yes this can be used as a second constructor
static const char* strToConstChar(const std::string& str) -- converts a string to const char

Boolean:
Boolean(bool val) -- constructor that accepts a boolean(bool) value
bool unwrap() -- returns the inner value
static Boolean wrap(bool val) -- wraps a bool value into a Boolean class. yes this can be used as a second constructor
static bool rndBool() -- returns a random boolean value

yea thats pretty much all lmk if I should add more
