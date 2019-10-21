#include <stdio.h>
#include <stdlib.h>



int main(int argc, char const *argv[])
{
	int d, rec;
	scanf("%d", &d);
	scanf("%d", &rec);

	int* nprocessa;
	nprocessa = (int*)malloc(0 * sizeof(int));

	int numeroarq = 0;
	int sobra = 0, totaln = 0;
	for (int i = 0; i < d; ++i)
	{
		int narq;
		scanf("%d", &narq);

		if (numeroarq < sobra + narq )
		{
			numeroarq = sobra + narq;
			nprocessa = (int*)realloc(nprocessa, numeroarq * sizeof(int));
		}

		for (int i = 0; i < narq; ++i)
		{
			scanf("%d", &nprocessa[i + sobra]);
		}


		int recsobra;
		totaln = narq + sobra;
		recsobra = rec;

		for (int i = totaln - 1, ctr = 0; (i >= 0) && (ctr != 1); --i)
		{
			int t = recsobra - nprocessa[i];
			if (t > 0)
			{
				recsobra = recsobra - nprocessa[i];
				sobra = 0;
			}

			else if (t == 0)
			{
				recsobra = 0;
				sobra = i;
				ctr = 1;
			}

			else if (t < 0)
			{
				ctr = 1;
				sobra = i + 1;
			}
		}

		if (sobra == 1)
		{
			printf("Resta 1 arquivo.\n");
		}
		else if (sobra == 0)
		{
			printf("Todos os arquivos foram processados.\n");
		}
		else if (sobra > 1)
		{
			printf("Restam %d arquivos.\n", sobra);
		}


	}

	free(nprocessa);


	return 0;
}
