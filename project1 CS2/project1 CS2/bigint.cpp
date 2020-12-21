/**
 * Joel Lee
 * Bigint
 * cs23001
 */

 //the reason is for to create type bigint so that it can hold an integer larger
 //Than the base int Type can hold

#include "bigint.h"


//A default constructor to initialize a bigint to zero.

bigint::bigint() {

    size = 1;

    for (int i = 0; i < Capacity; ++i)
        container[i] = 0;

}

//A constructor to initialize a bigint to an int value you provide [0, maxint].
bigint::bigint(int n) {
    
    // Number of digits will always be at least 1
    size = 1;

    // Gets Number Of Digits
    int newN = n;
    while (newN /= 10)
        size++;

    // Assigns Digits To Array Index In Reverse Order
    for (int i = 0; i < size; ++i) {

        int digit = n % 10;
        container[i] = digit;
        n /= 10;

    }

}


//A constructor to initialize a bigint to a const char[] you provide. You can assume what is provided is a valid bigint
bigint::bigint(const char carr[]) {
   
    
    size = 0;
    int digit = carr[size];	// Gets first digit

    // if the character is valid, its int counterpart will always be >= 0
    while (digit >= 0) {

        digit = carr[size] - '0';
        ++size;

    }
    --size;

    // Converts character to int and stores that number in the array
    for (int i = size - 1; i >= 0; --i)
        container[size - i - 1] = carr[i] - '0';


}


//print function for Debugging purposes
void bigint::debugPrint(std::ostream& out) const {
    for (int i = Capacity - 1; i >= 0; --i)
        out << container[i] << " | ";
}

//returns the size of how many numbers/digits are in BIGINT
int bigint::getSize() {
    return size;
}

void bigint::setSize(int s) {
    size = s;
}

bool bigint::operator==(bigint rhs) {
    // If they don't have the same amount of characters, they aren't equal
    if (size == rhs.size) {

        for (int i = 0; i < size; ++i) {

            if (container[i] != rhs.container[i])
                return false;

        }

        return true;

    }

    return false;
}


//Overloading the Bracket Operator
int bigint::operator[](int index) const {

    // Temporary Array To hold sorted Values
    int tmpArr[Capacity];

    // Give the values from container to the new array
    for (int i = 0; i < Capacity; ++i) {

        tmpArr[i] = container[i];

    }


    // Sort the array so the values are not in reversed order
    int tmp;
    for (int i = 0; i < size / 2; ++i) {

        tmp = tmpArr[size - i - 1];
        tmpArr[size - i - 1] = tmpArr[i];
        tmpArr[i] = tmp;

    }

    // Return the requested value at the specified index
    return tmpArr[index];


}

bigint bigint::operator+(const bigint& rhs) const {
    // Hold which bigint is bigger than the other
    int smallerSize, biggerSize;

    // Gets Bigger and Smaller Bigint Sizes
    if (size < rhs.size) {
        smallerSize = size;
        biggerSize = rhs.size;
    }
    else {
        smallerSize = rhs.size;
        biggerSize = size;
    }

    // Bigint to hold result of calculation
    bigint bintResult;
    bintResult.size = biggerSize;

    // Begin main loop of addition
    for (int i = 0; i < biggerSize; ++i) {

        // Handles the differences in size of the bigints for adding leftover numbers with 0 on the bigger value
        if (container[i] < 0)
            bintResult.container[i] += 0 + rhs.container[i];
        else if (rhs.container[i] < 0)
            bintResult.container[i] += container[i] + 0;
        else
            bintResult.container[i] += container[i] + rhs.container[i];


        // Handles the carryover digit for values greater than 10
        if (bintResult.container[i] > 9) {

            bintResult.container[i] = bintResult.container[i] % 10;
            ++bintResult.container[i + 1];

        }

    }

    // Increased size if the result of the addition is larger than both bigints
    if (bintResult.container[bintResult.size] > 0)
        ++bintResult.size;


    // Return result of the addition
    return bintResult;



}

//Overloading the >> Operator
std::istream& operator>>(std::istream& is, bigint& bint) {

    char ch;					// Hold each character in the stream
    is.get(ch);					// Gets first character from the stream
    int position = 0;			// For indexing the bigint
    // Loops while we are in the file, the character is not a semicolon, and the size is less than the objects capacity
    while (!is.eof() && ch != ';' && position < Capacity) {

        // Handles and ignores newline and space characters
        if (ch == '\n' || ch == ' ') {
            is.get(ch);
            continue;
        }

        bint.container[position] = int(ch) - int('0');		// Convert char to int and place in array
        is.get(ch);											// Gets next character from stream
        ++position;											// Update the index

    }

    // Setting the new bigint's size
    bint.setSize(position);

    // Sort the array so the values of the bigint are in reversed order
    int tmp;
    for (int i = 0; i < bint.getSize() / 2; ++i) {

        tmp = bint.container[bint.getSize() - i - 1];
        bint.container[bint.getSize() - i - 1] = bint.container[i];
        bint.container[i] = tmp;

    }


    // Return the input stream
    return is;

}

//Output Operaotr Overloading for BigInt
std::ostream& operator<<(std::ostream& out, bigint bint) {

    int containerSize = bint.getSize();

    int counter = 0;

    for (int i = containerSize - 1; i >= 0; --i) {

        // Newline for every 80 digits printed
        if (counter == 80 || counter == 160 || counter == 240 || counter
            == 320 || counter == 400 || counter == 480)
            out << "\n";

        out << bint.container[i];
        ++counter;
    }

    return out;

}


// Multiplies a bigint by a single integer digit
bigint bigint::times_digit(int num) const {

    bigint result;

    //Base Cases for 0 and 1
    if (num == 0)
        return bigint(0);
    else if (num == 1)
        return *this;


    for (int i = 0; i < size; ++i) {

        result.container[i] += container[i] * num;		// Multiplies the first index

        int carryover = result.container[i] / 10;		// Gets carryover digit

        if (result.container[i] > 9) {

            result.container[i] = result.container[i] % 10;		// Gets single digit from the multiplication

            result.container[i + 1] = carryover;				// Adds the carryover to next index

        }

    }

    result.setSize(size);		// Sets result's size

    // Increased size if the result of the multiplication is larger than the bigint
    if (result.container[result.size] > 0)
        result.size = size + 1;
    else
        result.size = size;


    // Return result of the multiplication
    return result;

}

// Shifts bigint by base 10 num times
bigint bigint::times_10(int num) const {

    bigint result;

    result.size = size + num;	//New Size

    // Shifts every element in the bigint one index over
    for (int i = 0; i < size; ++i)
        result.container[size - i - 1 + num] = container[size - i - 1];

    return result;

}

bigint bigint::operator*(const bigint& rhs) const {

    bigint product;
    bigint temp;

    // Hold which bigint is bigger than the other
    int smallerSize, biggerSize;

    // Gets Bigger and Smaller Bigint Sizes
    if (size < rhs.size) {
        smallerSize = size;
        biggerSize = rhs.size;
    }
    else {
        smallerSize = rhs.size;
        biggerSize = size;
    }


    if (rhs.size == biggerSize) {
        for (int i = 0; i < biggerSize; ++i) {

            temp = times_digit(rhs.container[i]);
            product = product + temp.times_10(i);

        }
    }
    else
        for (int i = 0; i < smallerSize; ++i) {

            temp = times_digit(rhs.container[i]);
            product = product + temp.times_10(i);

        }

    return product;

}

