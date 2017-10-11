//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int* a, int size_num) 
{
	for (int i = 0; i < size_num / 2-1 ; i++)
	{
		if (*(a + i) != *(a + ((size_num - 1) - i)))
		{
			return False;
		}
	}
	return True;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command(char c[], int size) 
{
	char ch;
	do
	{
		printf("\n\nNEW MOVEMENT : Enter a valid command by keyword :");
		printf("\nValid commands : ");
		for (int i = 0; i < size; i++)
		{
			printf("%c", c[i]);
			printf("    ");
		}
		printf("\n");
		ch = my_get_char();
	} //while ((ch != 'a') && (ch != 'd') && (ch != 'w') && (ch != 'x') && (ch != 'h') && (ch != 'k') && (ch != 'u') && (ch != 'm'));
	while (valid_command(ch, c, size) != True);
	return ch;
}

//--------------------------------------------------
// valid_command checks if the character is in the command array
//--------------------------------------------------
boolean valid_command(char character, char c[], int size)
{
	boolean res = False;
	for (int i = 0; i < size; i++) 
	{
		if (character == c[i]) 
		{
			res = True;
		}
	}
	return res;
}
//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int* a, int size_num, int** p_p, int* p_nm, char c) {
	if (c == 'a')								//Moves pointer to the left
	{
		if (*p_p != (a + 0))
		{
			*p_p = (*p_p) - 1;
			*p_nm = *p_nm + 1;
		}
	}


	else if (c == 'd')							//Moves pointer to the right
	{
		if (*p_p != (a + (size_num - 1)))
		{
			*p_p = (*p_p) + 1;
			*p_nm = *p_nm + 1;
		}
	}


	else if (c == 'w')							//Increases the digit by 1
	{
		if (**p_p != 9)
		{
			**p_p = (**p_p) + 1;
			*p_nm = *p_nm + 1;
		}
	}


	else if (c == 'x')							//Decreases the digit by 1
	{
		if (**p_p != 0)
		{
			**p_p = (**p_p) - 1;
			*p_nm = *p_nm + 1;
		}
	}


	else if (c == 'h')							//Moves the pointer to the very left border
	{
		if (*p_p != (a + 0))
		{
			*p_p = &a[0];
			*p_nm = *p_nm + 1;
		}
	}


	else if (c == 'k')							//Moves the pointer to the very right border
	{
		if (*p_p != (a + (size_num - 1)))
		{
			*p_p = &a[size_num - 1];
			*p_nm = *p_nm + 1;
		}
	}


	else if (c == 'u')							//Turns the digit being pointed to be a 9
	{
		if (**p_p != 9)
		{
			**p_p = 9;
			*p_nm = *p_nm + 1;
		}
	}


	else if (c == 'm')							//Turns the digit being pointed to be a 0
	{
		if (**p_p != 0)
		{
			**p_p = 0;
			*p_nm = *p_nm + 1;
		}
	}
}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int* a, int size_num, int* p, int nm) {
	printf("\n------ Game Status -------\n");
	printf("Number = { ");
	for (int i = 0; i < size_num; i++)
	{
		printf("%d ", a[i]);

	}
	printf("}\n");
	int pos = 0;
	for (int index = 0; index < size_num; index++)
	{
		if (p == (a + index))
		{
			pos = index;
		}
	}
	printf("           ");
	for (int j = 0; j < pos; j++)
		printf("  ");
	printf("^\n");								//Prints "^" under the digit of the array ‘a’ it
	printf("Num mov = ");						//is pointing at.
	printf("%d\n", nm);
	printf("\n------------------------------");
}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num, int num_size, char commands[], int command_size) {
	int *a = (int*)malloc(num_size * sizeof(int));

	for (int i = num_size - 1; i >= 0; i--)
	{
		a[i] = pal_num % 10;
		pal_num = pal_num / 10;
	}

	int nm = 0;
	int* p = &a[0];
	int** pp = &p;
	int* pnm = &nm;

	while (is_pal(a, num_size) == False)
	{
		char input = ' ';
		print_status(a, num_size, p, nm);
		input = ask_for_command(commands, command_size);
		process_movement(a, num_size, pp, pnm, input);
	} 

	print_status(a, num_size, p, nm);
	printf("\n------------------------------\n");
	printf("-------------SOLVED!----------\n");
	printf("------------------------------");
	my_get_char();
}