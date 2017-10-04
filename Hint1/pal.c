#include "pal.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int a[6]) {
	for (int i = 0; i < 2; i++)
	{
		if (*(a + i) != *(a+(5 - i)))
		{
			return False;
		}
	}
	return True;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command() {
	//NEW MOVEMENT : Enter a valid command by keyword :
	//Valid commands : a d w x
	char ch;
	do
	{
		printf("\n\nNEW MOVEMENT : Enter a valid command by keyword :\nValid commands : a	d	w	x\n");
		//scanf_s("%c", &ch);
		ch = my_get_char();
	} while ((ch != 'a') && (ch !='d') && (ch!= 'w') && (ch != 'x'));
	return ch;
	//my_get_char();
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int a[6], int** p_p, int* p_nm, char ch) {
	if (ch == 'a')								//Moves pointer to the left
	{
		if (*p_p != (a + 0))
		{
			*p_p = (*p_p) - 1;
			*p_nm = *p_nm + 1;
		}
	}
	else if (ch == 'd')							//Moves pointer to the right
	{
		if (*p_p != (a + 5))
		{
			*p_p = (*p_p) + 1;
			*p_nm = *p_nm + 1;
		}
	}
	else if (ch == 'w')							//Increases the digit by 1
	{
		if (**p_p != 9)
		{
			**p_p = (**p_p) + 1;
			*p_nm = *p_nm + 1;
		}
	}
	else if (ch == 'x')							//Decreases the digit by 1
	{
		if (**p_p != 0)
		{
			**p_p = (**p_p) - 1;
			*p_nm = *p_nm + 1;
		}
	}
}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int a[6], int* p, int nm) {
	printf("\n------ Game Status -------\n");
	printf("Number = { ");
	for (int i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);
		
	}
	printf("}\n");
	int pos = 0;
	for (int index = 0; index < 6; index++)
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
	printf("Num mov = ");							//is pointing at.
	printf("%d\n", nm);
	printf("\n------------------------------");
	//printf("\n ","%s%", "Pointer is at position ");
	//printf("%d\n", *p);
}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num) {
	int a[6];
	
	for (int i = 5; i >= 0; i--)
	{
		a[i] = pal_num % 10;
		pal_num = pal_num / 10;
	}
	
	int nm = 0;
	int* p = &a[0];
	int** pp = &p;
	int* pnm = &nm;

	do
	{
		char ch = ' ';
		print_status(a, p, nm);
		ch = ask_for_command();
		process_movement(a, pp, pnm, ch);
	} 
	while (is_pal(a) == False);

	print_status(a, p, nm);
	printf("\n------------------------------\n");
	printf("-------------SOLVED!----------\n");
	printf("------------------------------");
	my_get_char();
}
