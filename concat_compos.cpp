/** 
    @mainpage Concat Composites

    


    Program to slice a string formed after concatenating the first
    k composite numbers.
*/

/** \file concat_compos.cpp
    \brief Main program that, given a number n, returns a substring
    of the string formed by concatenating the first k composite numbers.

    The program accepts a number n from stdin provided by a user.
    Then, the program takes the first few composite numbers, 
    converts them to strings and concatenates them to get a string, say concat_compos 
    of length 1000.  

    Finally, the program prints the first 5 characters of concat_compos 
    starting at index n.  
    
    For example, the first few prime numbers are 4, 6, 8, 9, 10, 12, 14...  
    Thus, concat_compos = "4689101214...". If the user provides n = 3,
    the program should print 91012.

    Requires: C++11
*/


#include<iostream>
#include<string>


/** \brief Returns a string of length 1000 formed after concatenating
    the first k composite numbers.

    The program uses the Sieve of Eratosthenes method to filter prime
    numbers.

    @return std::string
*/
std::string get_concatenated_compos()
{
    const int limit = 2000;
    std::string concat_compos = "";

    int primes[limit];

    // Initialize all primes to True
    for(int i = 0; i < limit; i++)
    {
        primes[i] = true;
    }

    // 0 and 1 are not primes. So, set them to False.
    primes[0] = false;
    primes[1] = false;

    // Apply Sieve of Eratosthenes.
    for(int i = 2; i < limit; i++)
    {
        if(primes[i])
        {
            for(int j = i * i; j < limit; j = j + i)
            {
                if(j < limit)
                {
                    primes[j] = false;
                }
            }
        }
    }

    // Convert each number into a string and concatenate all.
    for(int i = 4; i < limit; i++)
    {
        if(!primes[i])
        {
            concat_compos += std::to_string(i);
        }
    }

    return concat_compos.substr(0, 1000);
}


/** \brief Return a slice of a string of length 5 beginning at the
    given index.

    @param compos is a string
    @param index is an integer
    @return std::string
*/
std::string get_slice_of_5(const std::string & compos, const int index)
{
    return compos.substr(index, 5);
}


/** \brief Program entry point

    The program starts execution from here. It accepts integer input
    from the user until the EOF is reached or when the user terminates
    the program.
*/
int main()
{
    int n;
    std::string concat_compos;

    while(std::cin >> n)
    {
        concat_compos = get_concatenated_compos();
        std::cout << get_slice_of_5(concat_compos, n) << std::endl;
    }

    return 0;
}
