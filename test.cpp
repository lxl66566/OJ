#include <chrono>
#include <iostream>

std::ostream&
operator<<( std::ostream& dest, __uint128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 128 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}
int main() {
    // unsigned long long n = 0;
    // while (true) {
    //     auto start = std::chrono::high_resolution_clock::now();
    //     for (int i = 0;i <= 1e8;++i)
    //     {
    //         swap(a,b);
    //     }
    //     auto finish = std::chrono::high_resolution_clock::now();

    //     auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
    //     std::cout << microseconds.count() << "µs\n";
    //     // if (microseconds > std::chrono::seconds(1))
    //         break;
    // }
    __uint128_t n = 0;
    std::cout << n - 1 << '\n';
}