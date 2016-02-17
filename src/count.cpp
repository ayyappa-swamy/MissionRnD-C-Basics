/*
OVERVIEW:  Given 2 integers (num1, num2), write a function that returns the count of numbers between the num1..num2 that are divisible by num1.
		E.g.: count(3, 15) returns 5 (3, 6, 9, 12, 15).

INPUTS:  Two numbers num1, num2.
		num1, num2 >= 0.

OUTPUT: Return the count of numbers between the num1..num2 that are divisible by num1.

ERROR CASES: Return -1 in error cases.

NOTES:
*/
int count(int num1, int num2) {
	int countVar = 0, factor = 0;
	if (num1 > num2)
		countVar = 0;
	else if (num1 == 1)
		return num2;
	else if (num1 == 0)
		countVar = -1;
	else if (num1 == num2)
		countVar = 1;
	else {
		for (factor = 1; factor*num1 <= num2; factor++){
			countVar++;
		}
	}
	return countVar;
}