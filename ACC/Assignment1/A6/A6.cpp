#include <iostream>
#include <chrono>

using namespace std;

long binomialExponent(int base, int exp);
long squareNmultiplyExponent(long base, int exp);
long conventionalExponent(int base, int exp);

int main(int argc, char *argv[])
{
    long base = atoi(argv[1]);
    int exp = atoi(argv[2]);
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::nanoseconds elapsed_seconds;
    std::time_t end_time;

    cout << "BINOMIAL EXPONENTIATION" << endl << endl;
    start = std::chrono::high_resolution_clock::now();
    long ans = binomialExponent(base, exp);
    end = std::chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Power of " << base << "  to " << exp << " is: " << ans << endl;
    cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " ns\n"<< endl << endl;


    cout << "SQUARE N MULTIPLY EXPONENTIATION" << endl << endl;
    start = std::chrono::high_resolution_clock::now();
    ans = squareNmultiplyExponent(base, exp);
    end = std::chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);
    elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Power of " << base << "  to " << exp << " is: " << ans << endl;
    cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " ns\n"<< endl << endl;


    cout << "CONVENTIONAL EXPONENTIATION" << endl << endl;
    start = std::chrono::high_resolution_clock::now();
    ans = conventionalExponent(base, exp);
    end = std::chrono::high_resolution_clock::now();
    end_time = std::chrono::high_resolution_clock::to_time_t(end);

    elapsed_seconds = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Power of " << base << "  to " << exp << " is: " << ans << endl;
    cout << "finished computation at " << std::ctime(&end_time)
         << "elapsed time: " << elapsed_seconds.count() << " ns\n"<< endl << endl;

}

long binomialExponent(int base, int exp)
{
    long num = base;
    long result = 1;
    long quotient = 0;
    int remainder = 0;
    while (exp > 0)
    {
        quotient = exp / 2;
        remainder = exp % 2;
        if (remainder == 1)
            result = result * num;
        if (quotient == 0)
            break;
        exp = quotient;
        num = num * num;
    }

    return result;
}

long squareNmultiplyExponent(long base, int exp)
{
    if (exp < 0)
    {
        return squareNmultiplyExponent(1 / base, -exp);
    }
    else if (exp == 0)
    {
        return 1;
    }
    else if (exp == 1)
    {
        return base;
    }
    else if (exp % 2 == 0)
    {
        return squareNmultiplyExponent(base * base, exp / 2);
    }
    else if (exp % 2 == 1)
    {
        return base * squareNmultiplyExponent(base * base, (exp - 1) / 2);
    }
    else
    {
        return 0;
    }
}

long conventionalExponent(int base, int exp)
{
    long result = 1;
    while (exp > 0)
    {
        result *= base;
        exp--;
    }
    return result;
}
