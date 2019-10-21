#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char vet[321][10] = {"prescindir", "corroborar", "incipiente", "indulgente",
"detrimento", "sagacidade", "subestimar", "depreender", "auspicioso",
"preconizar", "maturidade", "equivocado", "vislumbrar", "pertinente",
"morosidade", "conjuntura", "contemplar", "serenidade", "disruptivo",
"finalidade", "coercitivo", "entretanto", "compassivo", "precedente",
"iniquidade", "transeunte", "divergente", "concessivo", "sintetizar",
"restringir", "consolidar", "desprovido", "constituir", "importante",
"pejorativo", "meticuloso", "pernicioso", "disseminar", "estupefato",
"distinguir", "preliminar", "fundamento", "subjacente", "primordial",
"saudosista", "permanente", "filantropo", "mentecapto", "pessimista",
"condizente", "indeferido", "capacidade", "sobrepujar", "considerar",
"desvanecer", "proponente", "espairecer", "conturbado", "disciplina",
"perscrutar", "perseverar", "celeridade", "locupletar", "insipiente",
"apascentar", "escarnecer", "hipocrisia", "apresentar", "excludente",
"reverberar", "extremista", "convescote", "alteridade", "congruente",
"interpelar", "retumbante", "subversivo", "sentimento", "supremacia",
"consciente", "derradeiro", "desfalecer", "relacionar", "inoportuno",
"democracia", "expediente", "atribulado", "redundante", "persuasivo",
"exacerbado", "prevalecer", "decorrente", "assessoria", "idoneidade",
"modalidade", "ociosidade", "importunar", "retrocesso", "escamotear",
"prepotente", "hostilizar", "porventura", "semelhante", "repreender",
"mobilidade", "ascendente", "etimologia", "determinar", "tenacidade",
"demonstrar", "estimativa", "prescrever", "imperativo", "veracidade",
"deliberado", "mesquinhez", "concatenar", "cavalheiro", "autoridade",
"completude", "compadecer", "felicidade", "provimento", "requerente",
"vitalidade", "substituir", "mutuamente", "recorrente", "assembleia",
"rescindido", "hierarquia", "incorporar", "solicitude", "respectivo",
"sacripanta", "apreensivo", "possessivo", "retroativo", "subscrever",
"dissimular", "tempestivo", "lisonjeado", "martirizar", "intimidade",
"delimitado", "pulverizar", "precipitar", "sobressair", "embaixador",
"entusiasta", "astronomia", "conceituar", "conjectura", "fascinante",
"contribuir", "justificar", "repugnante", "resguardar", "intrepidez",
"urbanidade", "emasculado", "insensatez", "prosseguir", "conspurcar",
"reconhecer", "habilidade", "autoestima", "postergado", "expressivo",
"afortunado", "resiliente", "incremento", "analfabeto", "prestativo",
"viabilizar", "descritivo", "perenidade", "melancolia", "exiguidade",
"abrangente", "sobriedade", "esclarecer", "dependente", "fisionomia",
"lancinante", "logradouro", "forasteiro", "preocupado", "tecnologia",
"incentivar", "vangloriar", "chocarrice", "dignificar", "famigerado",
"delicadeza", "despotismo", "transmutar", "desventura", "compungido",
"entorpecer", "extenuante", "humanidade", "exatamente", "atrocidade",
"exuberante", "degradante", "condensado", "inebriante", "itinerante",
"misticismo", "morfologia", "consensual", "leviandade", "sancionado",
"indecoroso", "fatalidade", "prevaricar", "verdadeiro", "subalterno",
"confidente", "melindroso", "miraculoso", "comodidade", "fidelidade",
"idolatrado", "imprevisto", "desempenho", "degenerado", "imprudente",
"suficiente", "melindrosa", "politizado", "setecentos", "exasperado",
"evidenciar", "comparecer", "procedente", "prorrogado", "ludibriado",
"desiderato", "regurgitar", "calamidade", "dissociado", "identidade",
"magistrado", "maloqueiro", "futilidade", "extraviado", "estridente",
"pensamento", "inveterado", "interposto", "manifestar", "assimetria",
"rotisseria", "descomunal", "componente", "explicitar", "transviado",
"inoperante", "rudimentar", "desiludido", "ostracismo", "incessante",
"extrapolar", "sonoridade", "indefinido", "irracional", "compactuar",
"extravasar", "cronologia", "interceder", "comunidade", "continente",
"permanecer", "cataclismo", "voluptuoso", "repercutir", "intrigante",
"estipulado", "embevecido", "denominado", "intitulado", "particular",
"iniciativa", "reproduzir", "unilateral", "hombridade", "estoicismo",
"progenitor", "oligarquia", "pluralismo", "participar", "genealogia",
"consigamos", "estandarte", "sorrateiro", "entusiasmo", "pestanejar",
"fugacidade", "sobrestado", "debilidade", "inofensivo", "testificar",
"retaguarda", "prestigiar", "argumentar", "instigante", "contracapa",
"impaciente", "transmitir", "escoamento", "dissidente", "espectador",
"complicado", "libidinoso", "interregno", "confrontar", "arrebatado",
"integrante", "sempiterno"};


void encript_decript(char *res, char *key, char *msg, int tam){
	int i = 0;
	for (i = 0; i < tam; i++)
	 {

	 	res[i] = key[i] ^ msg[i];
	 	//printf("%c ** %c >> %d\n", key[i], msg[i], res[i]);
	 }
	 res[tam] = '\0';
}

void rand_str(char *dest, size_t length) {
    char charset[] = "!#$%&*()0123456789:;<=>?"
                     // "abcdefghijklmnopqrstuvwxyz"
                     "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while (length-- > 0) {
        size_t index = (double) rand() / RAND_MAX * (sizeof(charset) - 1);
        *dest++ = charset[index];
    }
    *dest = '\0';
}

void getMessage(char v[][10], int i, char *msg){
	//printf("indice = %d\n", i);
	strncpy(msg, v[i],10);
	//printf("msg = %d\n", i);
	msg[10] = '\0';
}


int main(int argc, char const *argv[])
{
	int tam = 10, seed, wordNumber;
	char chave[tam+1];
	char msg[tam+1], result[tam+1];

    	printf("Digite seu numero magico:\n");
	scanf("%d", &seed);

	srand(seed);

	rand_str(chave,tam);
	printf("\nChave gerada: >%s<\n", chave);

	srand(time(NULL));

	wordNumber = rand()%321;
	getMessage(vet, wordNumber, msg);

	//printf("Entre com a msg = ");
	//gets(msg);
	//printf("A mensagem = %s\n", msg);

	encript_decript(result, chave, msg, tam);
	printf("Palavra numero %d: >%s<\n", wordNumber, result);

	//encript_decript(msg, chave, result, tam);
	//printf("A mensagem DEScriptografada eh = %s\n", msg);

	return 0;
}
