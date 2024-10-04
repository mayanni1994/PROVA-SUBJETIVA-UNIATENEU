#include <iostream>

int main( ) {
	char reserva[10][6] = {
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' '}
	};
	int fileira = -1, acento = -1;
	char poltrona = ' ';
    char cond, Tipo_Pass,mudar_pol;
   
    while(bool laço_príncipal = true){
         printf("Tipos de reserva\n[C]Comum\n[E]Executiva\nEscolha seu tipo de reserva: ");
         scanf(" %c",&Tipo_Pass);

         printf("\nDigite a fileira (1-10): ");
         if (scanf("%d", &fileira) != 1 || fileira < 1 || fileira > 10) {
            printf("Opção não corresponde. Por gentileza, digite um número entre 1 e 10.\n");
            continue;
        }

        printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
		scanf(" %c", &poltrona);
		
		switch(poltrona){
			case 'A':
			
				acento = 0;
				break;
			case 'B':
			
				acento = 1;
				break;
			case 'C':
			
				acento = 2;
				break;
			case 'D':
			
				acento = 3;
				break;
			case 'E':
			
				acento = 4;
				break;
			case 'F':
			
				acento = 5;
				break;
			default:
				printf("\nPoltrona não corresponde");
		}
		// Implementação da lógica de tipos de passagem
        if (Tipo_Pass == 'C' || Tipo_Pass == 'c') {  // Passagem Econômica
            if (poltrona == 'A' || poltrona == 'F') {
                printf("\nPoltronas A e F são exclusivas para passagem Executiva. Escolha outra poltrona.\n");
                continue;
            } else {
                printf("\nPassagem Econômica reservada na poltrona %c, fileira %d.\n", poltrona, fileira);
            }
        } else if (Tipo_Pass == 'E' || Tipo_Pass == 'e') {  // Passagem Executiva
            if (poltrona != 'F' && poltrona != 'A') {
                printf("\nPara Passagem Executiva, recomendamos as poltronas A ou F.Deseja mudar o local\n(S/N): ");
                scanf(" %c", &mudar_pol);
                if (mudar_pol == 's' || mudar_pol == 'S'){
                    
                    continue;
                    
                }
            } else {
                printf("\nPassagem Executiva reservada na poltrona %c, fileira %d.\n", poltrona, fileira);
            }
        } else {
            printf("\nTipo de passagem inválido.\n");
            continue;
        }
        
        //verificação de cadeiras
        if(reserva[fileira-1][acento] == 'x'){
            printf ("A cadeira já esta reservada, escolha outra");
        }
        else{
            reserva[fileira-1][acento] = 'x';
        }
        
        
         //imprimir as cadeiras
       	printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
		for (int x=0; x<10; x++){
			if (x!=9)	printf("\n\t0%d\t", x+1);
			else		printf("\n\t%d\t", x+1);	
			
			for (int y=0; y<6; y++){
				printf("[%c] ", reserva[x][y]);
				if (y==2){
					printf("\t");
				}
			}
		}
		printf("\n");
        
        
        printf("\nVocê deseja fazer outra reserva?\nDigite |S| ou |N|: ");
        scanf(" %c",&cond);
        if (cond == 's' || cond == 'S' ){
            
            continue;
        }
        else{
            break;
        }
        
    }

		
		printf("\n");
    printf("\nencerrando o sistema...\n");
    	
}
