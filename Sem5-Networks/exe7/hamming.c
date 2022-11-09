// C program for the above approach

#include <math.h>
#include <stdio.h>

// Store input bits
int input[32];

// Store hamming code
int code[32];

int ham_calc(int, int);
void solve(int input[], int);

// Function to calculate bit for
// ith position
int ham_calc(int position, int c_l)
{
	int count = 0, i, j;
	i = position - 1;

	// Traverse to store Hamming Code
	while (i < c_l) {

		for (j = i; j < i + position; j++) {

			// If current boit is 1
			if (code[j] == 1)
				count++;
		}

		// Update i
		i = i + 2 * position;
	}

	if (count % 2 == 0)
		return 0;
	else
		return 1;
}

// Function to calculate hamming code
void solve(int input[], int n)
{
	int i, p_n = 0, c_l, j, k;
	i = 0;

	// Find msg bits having set bit
	// at x'th position of number
	while (n > (int)pow(2, i) - (i + 1)) {
		p_n++;
		i++;
	}

	c_l = p_n + n;

	j = k = 0;

	// Traverse the msgBits
	for (i = 0; i < c_l; i++) {

		// Update the code
		if (i == ((int)pow(2, k) - 1)) {
			code[i] = 0;
			k++;
		}

		// Update the code[i] to the
		// input character at index j
		else {
			code[i] = input[j];
			j++;
		}
	}

	// Traverse and update the
	// hamming code
	for (i = 0; i < p_n; i++) {

		// Find current position
		int position = (int)pow(2, i);

		// Find value at current position
		int value = ham_calc(position, c_l);

		// Update the code
		code[position - 1] = value;
	}

	// Print the Hamming Code
	printf("\nThe generated Code Word is: ");
	for (i = 0; i < c_l; i++) {
		printf("%d", code[i]);
	}
}

// Driver Code
void main()
{
      int n,k;
	// Given input message Bit
	printf("\n enter no of bits: ");
        scanf("%d",&n);
        printf("\n enter bits: ");
	for(k=0;k<n;k++)
        {
            scanf("%d",&input[k]);
        }

	// Function Call
	solve(input, n);
  printf("\n");
}

