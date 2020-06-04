#include <stdio.h>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<double> scores(5);
	double scores_sum;

	scores[0] = 5.5;
	scores[1] = 6.7;
	scores[2] = 6.7;
	scores[3] = 9.3;
	scores[4] = 7.5;

	for (unsigned int i = 0; i <= scores.size(); i++)
		{
			scores_sum += scores[i];
			printf("Soma das notas: %g\n", scores_sum);
		}

	printf("Média das notas: %g\n", (scores_sum / scores.size()));
	return 0;
}
