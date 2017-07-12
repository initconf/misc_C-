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

	std::cout << "collatz sequence is" << endl ;

	while (num >1 )
	{
		num = get_collatz(num); 

		std::cout << num <<", "  ; 
	}

} 
