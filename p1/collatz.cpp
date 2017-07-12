#include "collatz.h"

int collatz::get_collatz(int num) 
{

	if (num ==1 )
		return 1; 

	if (num %2 == 0)
		return  num/2 ; 
	else 
		return (3*num) + 1;
} 

void collatz::print_seq(int num)
{
  
	std::cout << "collatz sequence for " << num << " is : " << endl ;

    std::cout << num <<", " ; 
    
	while (num >1 )
	{
		num = get_collatz(num); 

        if (num >1)
            std::cout << num <<", "  ;
        else
            std::cout << num << "." ;
	}

    std::cout << endl ;
    std::cout << endl ;
    std::cout << endl ;
} 
