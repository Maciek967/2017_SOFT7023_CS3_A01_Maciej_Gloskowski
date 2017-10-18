
//--------------------------------------------------
// INCLUDE SECTION
//--------------------------------------------------
#include "pal.h"

//--------------------------------------------------
// is_pal
//--------------------------------------------------
boolean is_pal(int* a, int size_num) {
	boolean res = True;

	return res;
}

//--------------------------------------------------
// ask_for_command
//--------------------------------------------------
char ask_for_command(char c[], int size) {
	char res = ' ';

	return res;
}

//--------------------------------------------------
// process_movement
//--------------------------------------------------
void process_movement(int* a, int size_num, int** p_p, int* p_nm, char c) {

}

//--------------------------------------------------
// print_status
//--------------------------------------------------
void print_status(int* a, int size_num, int* p, int num_mov) {

}

//--------------------------------------------------
// user_game_palindrome
//--------------------------------------------------
void user_game_palindrome(int pal_num, int num_size, char commands[], int command_size) {

}

//--------------------------------------------------
// get_solving_array
//--------------------------------------------------
char* get_solving_array(int* a, int size_num, int* p, int* total_movs) {
	char* res = NULL;

	return res;
}

//--------------------------------------------------
// machine_game_palindrome
//--------------------------------------------------
void machine_game_palindrome(int pal_num, int num_size, char* commands, int commands_size){
	int* a = (int*)malloc(num_size * sizeof(int));
	
	for (int i = num_size - 1; i >= 0; i--)
	{
		a[i] = pal_num % 10;
		pal_num = pal_num / 10;
	}

	int nm = 0;
	int* p = &a[0];
	int totalMoves = (num_size / 2) -1;

	for (int i = 0; i < (num_size / 2); i++)	//loops through first half of the array
	{
		if (a[i] < a[num_size - 1 - i])			//if first number is smaller than the last number
		{
			while (a[i] < a[num_size - 1 - i])
			{
				a[i] = a[i] + 1;				//increase the number
				totalMoves = totalMoves + 1;
			}
		}

		else if (a[i] > a[num_size - 1 - i])
		{
			if (a[i] > a[num_size - 1 - i])		//if first number is bigger than the last number
			{
				while (a[i] > a[num_size - 1 - i])
				{
					a[i] = a[i] - 1;
					totalMoves = totalMoves + 1;
				}
			}
		}
	}

	char* sol = get_solving_array(a, num_size, p, totalMoves);
}



