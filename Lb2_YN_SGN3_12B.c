//Лабораторная №2
#include <stdio.h>
#include <math.h>

void tableWhile(float, float, float);
void tableDoWhile(float, float, float);
void tableFor(float, float, float, int);

static double epsilon = 0.000001;

void main()
{
	printf("f(x) = (sin(x)*sin(x))/x\n");
	float lower, higher, stepSize;
	int stepCount;
	printf("Enter lower and higher borders:\n");
	scanf_s("%f%f", &lower, &higher);
	if (lower > higher) {
		printf("Error: you must enter lower border first\a");
	}
	else if (lower == higher) {
		printf("Digits must differ\a");
	}
	else {
		printf("Enter amount of repetitions:\n");
		scanf_s("%d", &stepCount);

		if (stepCount <= 1) {
			printf("Amount of repetitions can't be lower 2\a");
		}
		else {
			stepSize = (higher - lower) / (stepCount - 1);
			tableWhile(lower, higher, stepSize);
			tableFor(lower, higher, stepSize, stepCount);
			tableDoWhile(lower, higher, stepSize);
		}
	}
}

void tableWhile(float lower, float higher, float stepSize)
{
	float x = lower;
	float function = 0;
	printf("while:\n");
	printf("x    |");
	while (fabs(higher - lower) >= epsilon) {
		printf("%6.3f|", lower);
		lower = lower + stepSize;
	}
	printf("\n");
	printf("f(x) |");
	while (fabs(higher - x) >= epsilon) {
		if (x == 0) {
			printf(" none|");
			x = x + stepSize;
		}
		else {
			function = (sin(x) * sin(x)) / x;
			printf("%6.3f|", function);
			x = x + stepSize;
		}
	}
	printf("\n\n");
}

void tableDoWhile(float lower, float higher, float stepSize)
{
	float x = lower;
	float function = 0;
	printf("do while:\n");
	printf("x    |");
	do {
		printf("%6.3f|", lower);
		lower = lower + stepSize;
	} while (lower <= higher);
	printf("\n");
	printf("f(x) |");
	do {
		if (x == 0) {
			printf(" none|");
			x = x + stepSize;
		}
		else {
			function = (sin(x) * sin(x)) / x;
			printf("%6.3f|", function);
			x = x + stepSize;
		}
	} while (x <= higher);
	printf("\n\n");
}

void tableFor(float lower, float higher, float stepSize, int stepCount)
{
	float x = lower;
	float function = 0;
	printf("for:\n");
	printf("x    |");
	for (int m = 1; m <= stepCount; m++) {
		printf("%6.3f|", lower);
		lower = lower + stepSize;
	}
	printf("\n");
	printf("f(x) |");
	for (int q = 1; q <= stepCount; q++) {
		if (x == 0) {
			printf(" none|");
			x = x + stepSize;
		}
		else {
			function = (sin(x) * sin(x)) / x;
			printf("%6.3f|", function);
			x = x + stepSize;
		}
	}
	printf("\n\n");
}
