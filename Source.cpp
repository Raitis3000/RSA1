#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <string>

using namespace boost::multiprecision;
adfads
struct RSANumbers
{

};

cpp_int gcd(cpp_int a, cpp_int b, cpp_int& x, cpp_int& y) {
//Extended Euclidian Algorithm utilized to obtain decryption coefficient//
// Credit for code to //
//https://cp-algorithms.com/algebra/extended-euclid-algorithm.html//
//Theory//
//https://math.stackexchange.com/questions/1226742/rsa-and-extended-euclidian-algorithm//
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    cpp_int x1, y1;
    cpp_int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

cpp_int dCalc(cpp_int e, cpp_int phi, cpp_int n)
{
    cpp_int k = 1;
    while (((k * phi) + 1) % e != 0)
    {
        k++;
    }
    return ((k * phi) + 1) / e;
}

int main() {
    cpp_int n, phi, e, d, decrypted, y, encrypted, msg;

    cpp_int p{ "288266801023767419542696851879528795379403563536737009752243514011049079420527731338762640529791823129699614424881823321502157171761398408469500925323" };
    cpp_int q{ "828562892119780148089106752244593531616768763789500651856375074426988699431756680022343344962232522000596456656763088429686817395217883915574523640377" };

    n = p * q;
    phi = (p - 1) * (q - 1); 
    e = 5;

    while (e < phi)
    {
        // e must be co-prime to phi and
        // smaller than phi.
        if (gcd(e, phi) == 1 && gcd(e, n) == 1)
            break;
        else
            e++;
    }

    //One way to calculate d
    //gcd(e, phi, d, y);

    //Another way to calculate d
    d = dCalc(e, phi, n);

    std::string strMsg;
    std::cout << "Enter message to be encrypted: ";
    std::getline(std::cin, strMsg);
    char asciiToChar;
    
    for (char c : strMsg) {
        msg = int(c);
        encrypted = powm(msg, e, n);
        decrypted = powm(encrypted, d, n);
        asciiToChar = char(decrypted);
        std::cout << "Encrypted message: " << encrypted << " Decrypted Ascii value: " << decrypted << " Associated ascii char: " << asciiToChar << std::endl;
    }

    //std::cout << std::endl;
    //std::cout << "e: " << e << std::endl;
    std::cout << "d: " << d << std::endl;
    //std::cout << "n: " << n << std::endl;
    //std::cout << "phi: " << phi << std::endl;
    //std::cout << "q: " << q << std::endl;
    //std::cout << "p: " << p << std::endl;
    //std::cout << "Message: " << msg << std::endl;
    //std::cout << "Encrypted: " << encrypted << std::endl;
    //std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}


// NOT UTILIZED //
cpp_int gcd(cpp_int a, cpp_int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// NOT UTITLIZED //
bool isPrime(cpp_int number)
{
    for (int a = 2; a < number; a++) {
        if (number % a == 0) {
            return false;
        }
    }
    return true;
}

// NOT UTITLIZED //
cpp_int coprime_check(cpp_int x, cpp_int y)
{
    for (cpp_int currentNum = 2; ; currentNum++) {
        if (isPrime(currentNum) && gcd(currentNum, x) == 1 && gcd(currentNum, y) == 1) {
            std::cout << currentNum << std::endl;
        }
    }
}
