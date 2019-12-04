
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct{        //tjogador ira receber os nomes dos jogadores com ate 16 caracteres
    char nome[17];

}tJogador;


typedef struct {                        //ttabuleiro ira armazenar as configurações do jogo passada pelo arquivo config
    int turno;                                   
    int tamanho;                            
    char tabuleiro[100][101];   
    int palavraspjogador;
    char palavrasjogador1[25][17];
    char palavrasjogador2[25][17];

}tTabuleiro;

typedef struct{
    char matriz[100][101];



}tMatriz;




typedef struct {            //defini um vetor de char com ate 16 caracteres

    char palavra[17];


}tpalavra;


typedef struct{
char palavrasjogador[25][17];   //defini uma matriz de char 

}matrizpalavras;

typedef struct{     //struct de coordenadas do jogo, pontos que irao procurar as palavras
    int cod1;           
    int cod2;


}coordenadas;

typedef struct{         //struct de estatisticas,guarda informações da partida;
    tJogador nome;
    int Feitos;
    int Recebidos;
    int Total;




}estatisticas;

typedef struct{      //struct para as palavras da estatistica,guardando o valor da pontuação e a palavra
    int identificador;
    char palavras[25][20];  //o vetor palavras guarda a palavra e o numero da jogada no qual foi achada 
    int numerojogada[25];        // o numero da jogada fica armazena na coluna [19]                    




}guardaestatic;

typedef struct{
    int identificador;              //struct com mais tamanho para guardar as palavras não achadas no jogo
    char palavras[50][20];
    int numerojogada[25];



}guardaestatic0;


typedef struct {                //struct guarda um identificador inteiro,e uma matriz de char
    int identificador;
    char letra[25][25];
    


}Guarda;

int  JogadaValida(int cod1,int cod2,tTabuleiro jogo);
 //retorna positivo se a jogada foi dentro dos limites do tabuleiro

int ProcuraNaMatrizVerticalbaixo(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se a a palavra esta escita na matriz verticalmente, iniciando de cima para baixo

int ProcuraNaMatrizHorizontaldireita(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se a palavra esta escrita horizontalmente da esquerda para direita

int ProcuraNaMatrizHorizontalesquerda(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se a palavra esta escrita horizontalmente da direita para a esquerda

Guarda Guardapalavraeidentificador(int identificador,int tamanhopal,char palavra[]);
//retorna uma struct chamada guarda que vai guardar a palavra e um identificador para ela
//identificador positivo para jogador1,negativo para jogador 2,0 nenhuma alteração é feita


coordenadas coordenadasqnaotenhapalavras(int cod1,int cod2,int linha,int coluna,char matriz[linha][coluna],tJogador jogador);
//vai repetir ate o jogador jogar uma coordenada que nao tenha sido jogada ainda
//entao retorna a struct com as coordenadas


int palavraaindanaofoiimpressa(int cod1,int cod2,int linha,int coluna,char matriz[linha][coluna]);
//verifica na matriz se a palavra ja foi revelada,retorna positiva se a posição for(-) ou letra minuscula


void Imprimirtabuleirodepoisdejogado(int linha,int coluna,char matriz[linha][coluna]);
// mostra o tabuleiro depois de jogado,mostrando as marcações ja feitas


void ImprimitaSoLetra(int linha,int coluna,int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna],tTabuleiro jogo);
//quando nao for uma palavra na posicao ira revelar somente a letra,essa funcao revela so a letra em maiusculo
//se ja tiver uma letra minuscula ele substitui por maiuscula

void ImprimitabelapalavraHorizontalesquerda(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]);
//recebe a palavra e a posicao de origem para imprimir, o tamanho a ser impresso de acordo com o tamanho
//imprimi a palavra horizontalmente da direita para esquerda
//tamanho atribuido a um contador
//se ja tem uma maiscula na palavra ele substitui por outra maisucula
//se tem minuscula ele substitui por minuscula
//a primeira letra da palavra é impressa em maiscula

void ImprimitabelapalavraHorizontaldireita(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]);
//recebe a palavra e a posicao de origem para imprimir, o tamanho a ser impresso de acordo com o tamanho
//imprimi a palavra horizontalmente da esquerda para direita
//tamanho atribuido a um contador
//se ja tem uma maiscula na palavra ele substitui por outra maisucula
//se tem minuscula ele substitui por minuscula
//a primeira letra da palavra é impressa em maiscula


void Imprimitabelapalavraverticalparacima(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]);
//recebe a palavra e a posicao de origem para imprimir, o tamanho a ser impresso de acordo com o tamanho
//imprimi a palavra verticalmente de baixo para cima
//tamanho atribuido a um contador
//se ja tem uma maiscula na palavra ele substitui por outra maisucula
//se tem minuscula ele substitui por minuscula
//a primeira letra da palavra é impressa em maiscula


void Imprimitabelapalavravertical(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]);
//recebe a palavra e a posicao de origem para imprimir, o tamanho a ser impresso de acordo com o tamanho
//imprimi a palavra verticalmente de cima para baixo
//tamanho atribuido a um contador
//se ja tem uma maiscula na palavra ele substitui por outra maisucula
//se tem minuscula ele substitui por minuscula
//a primeira letra da palavra é impressa em maiscula

int ProcuraNaMatrizHorizontaldireita(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se tem uma palavra nessa posicao escrita da esquerda para direita

int ProcuraNaMatrizHorizontalesquerda(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se tem uma palavra nessa posicao escrita da direita para esquerda

int ProcuraNaMatrizVerticalcima(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se tem uma palavra nessa posicao escrita de baixo para cima

int ProcuraNaMatrizVerticalbaixo(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se tem uma palavra nessa posicao escrita de cima para baixo


void Mostrartabuleiro(int linha,int coluna,char matriz[linha][coluna],int tamanho);
//imprimi o tabuleiro inicial,antes de serem feitos as jogadas
//so é usado na inicialização do jogo

void PalavrasRestantes( tTabuleiro jogo,tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2);
//imprimi o grafico de palavras restantes inicial,antes de serem editadas
//so é usado na inicialização do jogo

int ProcuraNaMatrizDiagonalparaDireitacima(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se as coordenadas forem de uma palavra escrita na diagonal,da esquerda para direita
//de baixo para cima


int ProcuraNaMatrizDiagonalparaDireitabaixo(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se as coordenadas forem de uma palavra escrita na diagonal,da esquerda para direita
//de cima para baixo

int ProcuraNaMatrizDiagonalparaEsquerdaCima(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se as coordenadas forem de uma palavra escrita na diagonal,da direita para esquerda
//de baixo para cima

int ProcuraNaMatrizDiagonalparaEsquerdaBaixo(int linha,int coluna,tTabuleiro jogo,char palavra[]);
//retorna positivo se as coordenadas forem de uma palavra escrita na diagonal,da direita para esquerda
//de cima para baixo


void ImprimitabelapalavraDiagonalparaEsquerdaBaixo(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]);
//ira imprimir a palavra recebida na diagonal,da direita para esquerda,de cima para baixo
//tamanho atribuido a um contador
//se ja tem uma maiscula na palavra ele substitui por outra maisucula
//se tem minuscula ele substitui por minuscula
//a primeira letra da palavra é impressa em maiscula

void ImprimitabelapalavraDiagonalparaEsquerdaCima(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]);
//ira imprimir a palavra recebida na diagonal,da direita para esquerda,de baixo para cima
//tamanho atribuido a um contador
//se ja tem uma maiscula na palavra ele substitui por outra maisucula
//se tem minuscula ele substitui por minuscula
//a primeira letra da palavra é impressa em maiscula


void ImprimitabelapalavraDiagonalparadireitabaixo(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]);
//ira imprimir a palavra recebida na diagonal,da esquerda para direita,de  cima para baixo
//tamanho atribuido a um contador
//se ja tem uma maiscula na palavra ele substitui por outra maisucula
//se tem minuscula ele substitui por minuscula
//a primeira letra da palavra é impressa em maiscula

void ImprimitabelapalavraDiagonalparadireitacima(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]);
//ira imprimir a palavra recebida na diagonal,da esquerda para direita,de baixo para cima
//tamanho atribuido a um contador
//se ja tem uma maiscula na palavra ele substitui por outra maisucula
//se tem minuscula ele substitui por minuscula
//a primeira letra da palavra é impressa em maiscula


Guarda JogaoJogo(int cod1,int cod2,tTabuleiro jogo,int tamlinha,int tamcoluna, char matriz[tamlinha][tamcoluna]);
Guarda ProcuraNaMatriz(int cod1,int cod2,tTabuleiro jogo,int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]);
Guarda Guardapalavraeidentificador(int identificador,int tamanhopal,char palavra[]);
matrizpalavras RetiraPalavraachadajogador1(tTabuleiro jogo, char palavra[]);
matrizpalavras RetiraPalavraachadajogador2(tTabuleiro jogo, char palavra[]);
void PalavrasRestanteseditadajogo( tTabuleiro jogo,tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2, matrizpalavras novasjogador1, matrizpalavras novasjogador2);
int VerificaSeJogoAcabou(int contapalavras1,int contapalavras2, int quantidadepal,int pontuacao1,int pontuacao2, tJogador jogador1, tJogador jogador2,FILE *arquivo);
tJogador Criajogador(int numero);
tpalavra AchaMaiorPalavra1(tTabuleiro jogo);
tpalavra AchaMaiorPalavra2(tTabuleiro jogo);
void Geraaquivoinicializacao(tTabuleiro jogo,tJogador jogador1 ,tJogador jogador2,FILE *inicializa);
int contadordepalavrasestatistica(guardaestatic palavras,int tamanho);
int contadordenaobarrazero(matrizpalavras palavrasjogador,int tamanho);

int verificaseapalavraestanessalista(char palavra[],guardaestatic pontos);
guardaestatic0 retiraespacobarrazeroponto(guardaestatic0 ponto,int tamanho);
coordenadas AteJogadaservalida1(int linha,int coluna, tTabuleiro jogo, tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2, matrizpalavras novasjogador1, matrizpalavras novasjogador2,int linhamatriz,int colunamatriz,char matriz[linhamatriz][colunamatriz]);
coordenadas AteJogadaservalida2(int linha,int coluna, tTabuleiro jogo, tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2, matrizpalavras novasjogador1, matrizpalavras novasjogador2,int linhamatriz,int colunamatriz,char matriz[linhamatriz][colunamatriz]);
int contadordepalavrasestatisticapara0ponto(guardaestatic0 palavras,int tamanho);
guardaestatic guardapalavraestat(char palavra[],int casa,guardaestatic novaguarda,int contaturno);
int verificaseapalavraestanessalista(char palavra[],guardaestatic pontos);
guardaestatic0 montaPalavrasNaoAchadasEstatisticas(tTabuleiro jogo, guardaestatic ponto1,guardaestatic ponto2,guardaestatic0 ponto0);
guardaestatic OrganizaEmOrdemAlfabetica(guardaestatic ponto,int tamanho);
coordenadas AteJogadaservalida1(int linha,int coluna, tTabuleiro jogo, tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2, matrizpalavras novasjogador1, matrizpalavras novasjogador2,int linhamatriz,int colunamatriz,char matriz[linhamatriz][colunamatriz]);



tTabuleiro LeConf(FILE* pconfig){                    //configurando o jogo seguindo o aqruivo de entrada config.txt
    int turnos;int casa;int tamanho,teste;int linha,coluna;
    tTabuleiro config;
    config.tamanho=0;

    fscanf(pconfig,"%d",&config.turno);                                     //leitura da quantidade de turnos
    fscanf(pconfig,"%d",&config.tamanho);                                   //leitura do tamanho do tabuleiro

    config.tabuleiro[config.tamanho][config.tamanho+1];                     // definindo um tamanho para a matriz do tabuleiro

    for(linha=0;linha<config.tamanho;linha++){
        fscanf(pconfig,"%s",&config.tabuleiro[linha][coluna]);               //lendo a matriz usando %s,e variando as linhas
    }
    fscanf(pconfig,"%d",&config.palavraspjogador);                           //lendo quantidade de palavras por jogador
    
    for(teste=0;teste<config.palavraspjogador;teste++){
        fscanf(pconfig,"%s",&config.palavrasjogador1[teste][coluna]);       //lendo palavras do jogador1
                                                                            //tranformando o conjunto em uma matriz
    }
    
    for(teste=0;teste<config.palavraspjogador;teste++){
        fscanf(pconfig,"%s",&config.palavrasjogador2[teste][coluna]);       //lendo palavras do jogador2
        
    }
     
    return config;              //retornando config como ttabuleiro


}




void PalavrasRestantesjogo( tTabuleiro jogo,tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2){
    int i=0,roda=0,palavra1=0,palavra2=0,palavras=0,roda2=0,palavrascont2=0;int test;
   
    printf("|            Palavras Restantes           |\n");
        
    printf("|%s",jogador1.nome);
    palavra1=strlen(jogador1.nome);
    for(roda=palavra1;roda<16;roda++){ printf(" ");}
            printf("(%02d)|",pontuacao1);
    
 
    printf("%s",jogador2.nome);
    palavra2=strlen(jogador2.nome);
        for(roda=palavra2;roda<16;roda++){ printf(" ");}
            printf("(%02d)|\n",pontuacao2);
    
    
    printf("|");
        for(roda=1;roda<21;roda++){ printf("-");}
            printf("|");
        for(roda=1;roda<21;roda++){ printf("-");}
            printf("|\n");    
    

    for(roda=0;roda<jogo.palavraspjogador;roda++){
        printf("|");
        palavras=strlen(jogo.palavrasjogador1[roda]);
        printf("%s",jogo.palavrasjogador1[roda]);
            
            for(roda2=palavras;roda2<20;roda2++){
                printf(" ");
            }printf("|");
            
            
        palavrascont2=strlen(jogo.palavrasjogador2[roda]);
        printf("%s",jogo.palavrasjogador2[roda]);
            for(roda2=palavrascont2;roda2<20;roda2++){
                printf(" ");
            }printf("|\n"); 
    }    
    
  //função qeu é chamda no começo do jogo que imprmi as palavras restantes e o tabuleiro 
  //so é chamada uma vez antes de ser alterada   
  //apos a primeira jogada uma função parecida é chamada           
        
        
}


tpalavra AchaMaiorPalavra1(tTabuleiro jogo){            
    int tamanho;int cont=0;
    int roda;int tamanhomaior=0;
    tpalavra maior;
    
    
    for(roda=0;roda<jogo.palavraspjogador;roda++){
        tamanho=strlen(jogo.palavrasjogador1[roda]);
        
        if(tamanho>tamanhomaior){
            tamanhomaior=tamanho;
            strcpy(maior.palavra,jogo.palavrasjogador1[roda]);
        
        }
    }
    
    return maior;

    //retorna a maior palavra do jogador 1
    
}
tpalavra AchaMaiorPalavra2(tTabuleiro jogo){
    int tamanho;int cont=0;
    int roda;int tamanhomaior=0;
    tpalavra maior;

    for(roda=0;roda<jogo.palavraspjogador;roda++){
        tamanho=strlen(jogo.palavrasjogador2[roda]);
        
        if(tamanho>tamanhomaior){
            tamanhomaior=tamanho;
            strcpy(maior.palavra,jogo.palavrasjogador2[roda]);
        
        }
        
    
    }
    
    return maior;

//retorna a maior palavra do jogador 2
}



void Geraaquivoinicializacao(tTabuleiro jogo,tJogador jogador1 ,tJogador jogador2,FILE *inicializa){
    //função responsavel por escrever no arquivo de inicialização 
    int roda=0;int rodapalavras=0;int contador=0;
    tpalavra maior1,maior2;
    char primeiraletra;

        fprintf(inicializa,"--Jogador 1--\n");          
        fprintf(inicializa,"Nome: ");
        fprintf(inicializa,jogador1.nome,"%s");        //imprimi nome do jogador
        fprintf(inicializa,"\n"); 
        fprintf(inicializa,"Palavras:\n");              
     
            for(roda=0;roda<jogo.palavraspjogador;roda++){
                fprintf(inicializa,jogo.palavrasjogador1[roda],"%s"); //imprimi palavras do jogador 
                fprintf(inicializa,"\n");
                }
        fprintf(inicializa,"Maior Palavra: \n");     //imprimi a maior palavras do jogador 
        maior1=AchaMaiorPalavra1(jogo);                 
        fprintf(inicializa,maior1.palavra,"%s");
        fprintf(inicializa,"\n");
        fprintf(inicializa,"Letras Iniciais: \n");  
            for(roda='a';roda<='z';roda++){
                for(rodapalavras=0;rodapalavras<jogo.palavraspjogador;rodapalavras++){
                    primeiraletra=jogo.palavrasjogador1[rodapalavras][0];        
                        if(primeiraletra==roda){           //conta quantas vezes aparece cada letra
                        contador++;           
                        }
                }
                        if(contador!=0){        //contador for zero nao tem essa letra nas palavras
                        fprintf(inicializa,"%c -> %d",roda,contador);        //imprimi quais iniciais tem nas palavras de cada jogador e a quantidade
                        fprintf(inicializa,"\n");
                        }
                        contador=0;   
            }    
       
                        fprintf(inicializa,"\n");   
     
    
                        
        fprintf(inicializa,"--Jogador 2--\n");
        fprintf(inicializa,"Nome: ");
        fprintf(inicializa,jogador2.nome,"%s");
        fprintf(inicializa,"\n"); 
        fprintf(inicializa,"Palavras:\n");
     
            for(roda=0;roda<jogo.palavraspjogador;roda++){
                fprintf(inicializa,jogo.palavrasjogador2[roda],"%s");
                fprintf(inicializa,"\n");
                }
        fprintf(inicializa,"Maior Palavra: \n");
        maior2=AchaMaiorPalavra2(jogo);     //recebe a a maior palavra do jogador2
        fprintf(inicializa,maior2.palavra,"%s");
        fprintf(inicializa,"\n");
        fprintf(inicializa,"Letras Iniciais: \n");
                for(roda='a';roda<='z';roda++){
                    for(rodapalavras=0;rodapalavras<jogo.palavraspjogador;rodapalavras++){
                        primeiraletra=jogo.palavrasjogador2[rodapalavras][0];       
                            if(primeiraletra==roda){        
                            contador++;             //conta quantas vezes aparece cada letra
                            }
                    }
                            if(contador!=0){        //contador for zero nao tem essa letra nas palavras
                            fprintf(inicializa,"%c -> %d",roda,contador);   //imprimi quais iniciais tem nas palavras de cada jogador e a quantidade
                            fprintf(inicializa,"\n");
                            }
                            contador=0;   
                } 
   
}



int verificaseapalavraestanessalista(char palavra[],guardaestatic pontos){
    int valido=0;
    int roda=0;        
    for(roda=0;roda<25;roda++){
        if(strcmp(palavra,pontos.palavras[roda])==0){
            return 1;
        }

    }
    
    return valido;

    // vai receber uma palavra e uma matriz de palavras e retornar 1 se essa palavra estiver nela
    //retornar 0 se nao estiver
}



guardaestatic0 montaPalavrasNaoAchadasEstatisticas(tTabuleiro jogo, guardaestatic ponto1,guardaestatic ponto2,guardaestatic0 ponto0){
    int roda=0;
    int adiciona=0;
    int validolista1=0,validolista2=0;
    int validolista12=0,validolista22=0;

    for(roda=0;roda<jogo.palavraspjogador;roda++){
        validolista1=verificaseapalavraestanessalista(jogo.palavrasjogador1[roda],ponto1);
        validolista12=verificaseapalavraestanessalista(jogo.palavrasjogador1[roda],ponto2);
       
       if(!validolista1 && !validolista12){                                             
           strcpy(ponto0.palavras[adiciona],jogo.palavrasjogador1[roda]);
           adiciona++;    
       } 
        
    }
    
    for(roda=0;roda<jogo.palavraspjogador;roda++){
        
        validolista2=verificaseapalavraestanessalista(jogo.palavrasjogador2[roda],ponto1);
        validolista22=verificaseapalavraestanessalista(jogo.palavrasjogador2[roda],ponto2);
     
       
        if(!validolista2 && !validolista22){
           strcpy(ponto0.palavras[adiciona],jogo.palavrasjogador2[roda]);
           adiciona++;
           
        } 
        
    }

    

    return ponto0;

//essa função recebe  matrizes de palavras:pontos1,pontos2 e pontos0
//ele vai verificar quais palavras do jogador1 e do jogador2 estão em pontos1 ou pontos2
//as que nao estiverem em nenhuma das duas irao ser colocadas em ponto0
//e retorna ponto0 com as palavras que nao foram achadas na partida    

}


guardaestatic0 retiraespacobarrazeroponto(guardaestatic0 ponto,int tamanho){
    guardaestatic0 pontonovo;
    int roda;int novo=0;
    
    for(roda=0;roda<tamanho;roda++){
    
        if(strcmp(ponto.palavras[roda]," \0")!=0){
            strcpy(pontonovo.palavras[novo],ponto.palavras[roda]);
            pontonovo.palavras[novo][19]=0;
            novo++;
        
        }    
    }

    return pontonovo;

    //função ira receber uma matriz de palavras e atraves de uma repeticao for vai adicionar a outra matriz as palavras que nao forem iguais a " \0"
    //" \0" são as posições já achadas transformadas para não contar duas vezes a palavra
    //retorna essa nova matriz
    
}



guardaestatic OrganizaEmOrdemAlfabetica(guardaestatic ponto,int tamanho){
    int roda=0;int adiciona=0;
    int roda2=0;int valido=1;
    guardaestatic novoponto;
        for(roda=0;roda<tamanho;roda++){
            for(roda2=roda;roda2<tamanho;roda2++){
                if(strcmp(ponto.palavras[roda],ponto.palavras[roda2])>0){   //strcmp retorna positivo quando encontrar um caracter diferente nas strings e essa caracter é maior na primeira string                   
                strcpy(novoponto.palavras[0],ponto.palavras[roda]);    //copia a palavra que é para ser trocada de lugar para uma variavel temporaria                              
                novoponto.palavras[0][19]=ponto.palavras[roda][19];    //copiar o numero da jogada que esta localizada no vetor coluna 19                                           
                strcpy(ponto.palavras[roda],ponto.palavras[roda2]);     //copia a palavra no lugar da outra                
                ponto.palavras[roda][19]=ponto.palavras[roda2][19];     //guarda o numero da jogada                            
                strcpy(ponto.palavras[roda2],novoponto.palavras[0]);    //copiando a palavra da variavel temporaria de volta na matriz de palavras              
                ponto.palavras[roda2][19]=novoponto.palavras[0][19];    //passando o numero da jogada de volta
                    
                }        
            }   
        }
    
    
    return ponto;
    
    
//coloca em ordem alfabetica a matriz de palavras recebidas em uma nova matriz 
//fazendo a troca de palavras com ajuda de uma variavel novoponto     
//e retorna a struct ponto com as palavras organziadas

}

guardaestatic0 OrganizaEmOrdemAlfabeticapara0ponto(guardaestatic0 ponto,int tamanho){
    int roda=0;int roda2=0;
    guardaestatic0 novoponto;
        for(roda=0;roda<tamanho;roda++){
            for(roda2=roda;roda2<tamanho;roda2++){
                if(strcmp(ponto.palavras[roda],ponto.palavras[roda2])>0){   //strcmp retorna positivo se a  letra diferente da primeira string é maior que a segunda    
                    strcpy(novoponto.palavras[0],ponto.palavras[roda]);    //copia a palavra que é para ser trocada de lugar para uma variavel temporaria                
                    novoponto.palavras[0][19]=0;                           //copiar zero para o numero da jogada que esta localizada no vetor coluna 19                                             
                    strcpy(ponto.palavras[roda],ponto.palavras[roda2]);     //copia a palavra no lugar da outra               
                    ponto.palavras[roda][19]=0;                             //guarda zero como numero da jogada                    
                    strcpy(ponto.palavras[roda2],novoponto.palavras[0]);    //copiando a palavra da variavel temporaria de volta na matriz de palavras                
                    ponto.palavras[roda2][19]=0;
                }
            
            }
        
        }    
    return ponto;
    
    
//coloca em ordem alfabetica a matriz de palavras recebidas em uma nova matriz 
//copia a matriznova para a velha     
//e retorna a matriz

}


//CORRECAO:funcao que verifica se nenhuma plalavra repetida foi adicionada as palavras não achadas,repetindo a matriz de palavras não achada
guardaestatic0 verificasenaotemletrarepetida(guardaestatic ponto1,guardaestatic ponto2,guardaestatic0 ponto0,int tamanho){
    int roda2=0;
    int roda=0;
    int tamanho0=tamanho*2;
    
    
    for(roda=0;roda<tamanho0;roda++){
        for(roda2=0;roda2<tamanho;roda2++){                     
            if(strcmp(ponto0.palavras[roda],ponto1.palavras[roda2])==0){        //CORRECAO:se achar alguma palavra igual copia o " /0" no lugar dele
                strcpy(ponto0.palavras[roda]," \0");            
            }
        }
    }

    for(roda=0;roda<tamanho0;roda++){
        for(roda2=0;roda2<tamanho;roda2++){
            if(strcmp(ponto0.palavras[roda],ponto2.palavras[roda2])==0){        //CORRECAO:se achar alguma palavra igual copia o " /0" no lugar delE    
                strcpy(ponto0.palavras[roda]," \0");                 
            }
        }
    }    
    
    
    return ponto0;

}



void GeraarquivoEstatisticas(FILE *estatistic, tJogador jogador1, tJogador jogador2, tTabuleiro jogo, estatisticas jogadascara1, estatisticas jogadascara2,guardaestatic ponto1,guardaestatic ponto2){
    int roda=0;int rodaletra=0;
    int tamanho;
    int cont2ponto=0,cont1ponto=0,cont0ponto=0;
    guardaestatic0 ponto0;
    
       
    cont2ponto=contadordepalavrasestatistica(ponto2,25);        //conta o tamanho da matriz de 2 pontos
    cont1ponto=contadordepalavrasestatistica(ponto1,25);        //conta o tamanho da matriz de 1 ponto
    
    ponto0=montaPalavrasNaoAchadasEstatisticas(jogo,ponto1,ponto2,ponto0);  //cria a matriz de palavras nao achadas
    ponto0=retiraespacobarrazeroponto(ponto0,jogo.palavraspjogador*2);               //retira " \0" da matriz
    cont0ponto=contadordepalavrasestatisticapara0ponto(ponto0,jogo.palavraspjogador*2);  //calcula o tamanho da matriz a ser impresa
    ponto0=verificasenaotemletrarepetida(ponto1,ponto2,ponto0,jogo.palavraspjogador);//CORRECAO:verifica o conjunto de palavras não achadas se possui palavras que ja foram achadas
    ponto0=retiraespacobarrazeroponto(ponto0,jogo.palavraspjogador*2);      //CORRECAO:repassando as palavras nao achadas ja verificada na função retirabarrazero 
    cont0ponto=contadordepalavrasestatisticapara0ponto(ponto0,jogo.palavraspjogador*2); //CORRECAO:calcula o tamanho da matriz a ser impressa
    
    
    ponto1=OrganizaEmOrdemAlfabetica(ponto1,cont1ponto);
    ponto2=OrganizaEmOrdemAlfabetica(ponto2,cont2ponto);        //reorganiza as palavras em ordem alfabetica
    ponto0=OrganizaEmOrdemAlfabeticapara0ponto(ponto0,cont0ponto);
    
    ponto0.identificador=0;
    fprintf(estatistic,"--------------\n");
    fprintf(estatistic,"--- PONTOS ---\n");
    fprintf(estatistic,"--------------\n");
    fprintf(estatistic,"\n");
    
    fprintf(estatistic,"%s\n",jogador1.nome);
    fprintf(estatistic,"Feitos:");
    fprintf(estatistic," %d\n",jogadascara1.Feitos);        //imprimi a struct estatisticas
    fprintf(estatistic,"Recebidos:");
    fprintf(estatistic," %d\n",jogadascara1.Recebidos);
    fprintf(estatistic,"Total:");
    fprintf(estatistic," %d\n",jogadascara1.Total);

    fprintf(estatistic,"\n");
    
    
    fprintf(estatistic,"%s\n",jogador2.nome);
    fprintf(estatistic,"Feitos:");
    fprintf(estatistic," %d\n",jogadascara2.Feitos);
    fprintf(estatistic,"Recebidos:");                         //impriimi a struct estatisticas
    fprintf(estatistic," %d\n",jogadascara2.Recebidos);
    fprintf(estatistic,"Total:");
    fprintf(estatistic," %d\n",jogadascara2.Total);
    fprintf(estatistic,"\n");
    
    fprintf(estatistic,"---------------------------\n");
    fprintf(estatistic,"--- PALAVRAS POR PONTOS ---\n");
    fprintf(estatistic,"---------------------------\n");
    fprintf(estatistic,"\n");
    
    fprintf(estatistic,"|P|     Palavra    | T |\n");
    fprintf(estatistic,"|-|----------------|---|\n");
    

    for(roda;roda<cont2ponto;roda++){
        fprintf(estatistic,"|%d|",ponto2.identificador);            //imprimi no arquivo o identicador sinalizando os pontos
        fprintf(estatistic,"%s",ponto2.palavras[roda]);             //imprimi as palavras achadas valendo 2 pontos
        tamanho=strlen(ponto2.palavras[roda]);
            for(rodaletra=tamanho;rodaletra<16;rodaletra++){
                fprintf(estatistic," ");
            }      
        fprintf(estatistic,"|%03d|\n",ponto2.palavras[roda][19]);    //imprimi o numero da jogada qual foi achada
    }
   
    
    for(roda=0;roda<cont1ponto;roda++){
        fprintf(estatistic,"|%d|",ponto1.identificador);            //imprimi no arquivo o identicador sinalizando os pontos
        fprintf(estatistic,"%s",ponto1.palavras[roda]);             //imprimi as palavras achadas valendo 1 ponto    
        tamanho=strlen(ponto1.palavras[roda]);
            for(rodaletra=tamanho;rodaletra<16;rodaletra++){
                fprintf(estatistic," ");
            }      
        fprintf(estatistic,"|%03d|\n",ponto1.palavras[roda][19]);     //imprimi o numero da jogada qual foi achada
    }
    
    for(roda=0;roda<cont0ponto;roda++){
        fprintf(estatistic,"|%d|",ponto0.identificador);             //imprimi no arquivo o identicador sinalizando os pontos
        fprintf(estatistic,"%s",ponto0.palavras[roda]);              //imprimi as palavras que nao foram achadas
        tamanho=strlen(ponto0.palavras[roda]);
            for(rodaletra=tamanho;rodaletra<16;rodaletra++){
                fprintf(estatistic," ");
            }      
        fprintf(estatistic,"|%03d|\n",ponto0.palavras[roda][19]);     //imprimi o turno zero
    }
    
    
   
    
  
    fclose(estatistic);
  
    
    
}

int contadordenaobarrazero(matrizpalavras palavrasjogador,int tamanho){
    int roda=0,cont=0;
    
    for(roda=0;roda<tamanho;roda++){
    if(strcmp(palavrasjogador.palavrasjogador[roda],"\0")!=0){
        cont++;
    }
        
    }    
    
    
    return cont;
    
    //retona a quantidade de palavras que possui na matriz de palavras

}
int contadordepalavrasestatistica(guardaestatic palavras,int tamanho){
    int roda=0,cont=0;
    
    for(roda=0;roda<tamanho;roda++){
    if(strcmp(palavras.palavras[roda],"\0")!=0){
        cont++;
    }
        
    }    
    
    
    return cont;


//conta quantas palavras tem na struct guardaestatic palavras
//e retorna essa quantidade    

}
int contadordepalavrasestatisticapara0ponto(guardaestatic0 palavras,int tamanho){
    int roda=0,cont=0;
    
    for(roda=0;roda<tamanho;roda++){
    if(strcmp(palavras.palavras[roda],"\0")!=0){
        cont++;
    }
        
    }    
    
    
    return cont;


//conta quantas palavras tem na struct guardaestatic palavras
//e retorna essa quantidade    

}




void PalavrasRestanteseditadajogo( tTabuleiro jogo,tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2, matrizpalavras novasjogador1, matrizpalavras novasjogador2){
    //essa função sera chamada toda vez que uma jogada foi feita
    //ira imprimir o novo palavrasrestantes
    
    int i=0,roda=0,palavra1=0,palavra2=0,palavras=0,roda2=0,palavrascont2=0;
    int numerobarra1,numerobarra2;int novalinha;
    
    numerobarra1=contadordenaobarrazero(novasjogador1,jogo.palavraspjogador);       //conta quantas palavras ainda tem cada jogador
    numerobarra2=contadordenaobarrazero(novasjogador2,jogo.palavraspjogador);
    
    if(numerobarra1==numerobarra2){
        novalinha=numerobarra1;
    }
    if(numerobarra2>numerobarra1){
        novalinha=numerobarra2;             //o jogador que possuir mais palavras ira definir o tamanho da tabela de palavras
    }
    if(numerobarra1>numerobarra2){
        novalinha=numerobarra1;
    }
   
    
   
    printf("|            Palavras Restantes           |\n");
        
    printf("|%s",jogador1.nome);
        palavra1=strlen(jogador1.nome);
        for(roda=palavra1;roda<16;roda++){ printf(" ");}
        printf("(%02d)|",pontuacao1);
    
    
    printf("%s",jogador2.nome);
        palavra2=strlen(jogador2.nome);
        for(roda=palavra2;roda<16;roda++){ printf(" ");}
        printf("(%02d)|\n",pontuacao2);
    
    
    printf("|");
        for(roda=1;roda<21;roda++){ printf("-");}
        printf("|");
        for(roda=1;roda<21;roda++){ printf("-");}
        printf("|\n");    
    
        
        
        
        
    for(roda=0;roda<novalinha;roda++){
       
        
        printf("|");
        palavras=strlen(novasjogador1.palavrasjogador[roda]);      
        printf("%s",novasjogador1.palavrasjogador[roda]);       //imprmi novasjogador1- uma matriz de palavras que atualiza sem as palavras achadas
        
        
    
            for(roda2=palavras;roda2<20;roda2++){
            printf(" ");
            }printf("|");
            
            
        palavrascont2=strlen(novasjogador2.palavrasjogador[roda]);
        printf("%s",novasjogador2.palavrasjogador[roda]);        //imprmi novasjogador2- uma matriz de palavras que atualiza sem as palavras achadas
            for(roda2=palavrascont2;roda2<20;roda2++){
            printf(" ");
            
           }printf("|\n"); 
    }    
    
           
         printf("\n");  
        
}





void Mostrartabuleiro(int linha,int coluna,char matriz[linha][coluna],int tamanho){
    int casa=0,casa2=0,tabuleiro=0;
     
   
    
    printf("    ");
    for(casa=0;casa<tamanho;casa++){
        printf("%02d",casa);
        if(casa!=tamanho-1){
            printf(" ");
        }
        
    }
    printf("\n");
    
    for(casa2=0;casa2<tamanho;casa2++){
        printf("%02d|",casa2);
        for(tabuleiro=0;tabuleiro<tamanho;tabuleiro++){
            matriz[casa2][tabuleiro]='-';
            printf(" %c ",matriz[casa2][tabuleiro]);
        }
        printf("|\n");
    }
    

 printf("\n");  
 
 //ira mostra o tabuleiro uma vez no começo do jogo
 //antes da primeira jogada
}


int  JogadaValida(int cod1,int cod2,tTabuleiro jogo){
    if((cod1>=0 && cod1<jogo.tamanho) && (cod2>=0 && cod2<jogo.tamanho)){
        return 1;
    }else{
        return 0;
    }
}


int ProcuraNaMatrizVerticalbaixo(int linha,int coluna,tTabuleiro jogo,char palavra[]){
 
    int roda,rodapalavra;
    int valido=1;
    
   
    for(roda=linha,rodapalavra=0;valido;roda++,rodapalavra++){      
        if(palavra[rodapalavra]  != jogo.tabuleiro[roda][coluna] && palavra[rodapalavra] !='\0'){
            return 0;
        }
        if(palavra[rodapalavra]=='\0'){
            return valido;
        }
    }
    

}

int ProcuraNaMatrizVerticalcima(int linha,int coluna,tTabuleiro jogo,char palavra[]){
    int roda,rodapalavra;
    int valido=1;
    
   
    for(roda=linha,rodapalavra=0;valido;roda--,rodapalavra++){      
        if(palavra[rodapalavra]  != jogo.tabuleiro[roda][coluna] && palavra[rodapalavra] !='\0'){         
            return 0;
        }
        if(palavra[rodapalavra]=='\0'){
            return valido;
        }
    }
    
    
    
    
    
}

int ProcuraNaMatrizHorizontalesquerda(int linha,int coluna,tTabuleiro jogo,char palavra[]){
    int rodapalavra;int rodacoluna;
    int valido=1;

    for(rodacoluna=coluna,rodapalavra=0;valido;rodacoluna--,rodapalavra++){      
        if(palavra[rodapalavra]  != jogo.tabuleiro[linha][rodacoluna] && palavra[rodapalavra] !='\0'){
            return 0;
        }
        if(palavra[rodapalavra]=='\0'){
            return valido;
        }
    }
    




}
int ProcuraNaMatrizHorizontaldireita(int linha,int coluna,tTabuleiro jogo,char palavra[]){
    int rodapalavra;int rodacoluna;
    int valido=1;
    int tamanho;
    
    
    for(rodacoluna=coluna,rodapalavra=0;valido;rodacoluna++,rodapalavra++){      
        if(palavra[rodapalavra]  != jogo.tabuleiro[linha][rodacoluna] && palavra[rodapalavra] !='\0'){
            
            return 0;
        }
        if(palavra[rodapalavra]=='\0'){
            return valido;
        }
    }
    


}

int ProcuraNaMatrizDiagonalparaDireitacima(int linha,int coluna,tTabuleiro jogo,char palavra[]){
    int rodapalavra;int rodacoluna,rodalinha;
    int valido=1;
    
    
    
    for(rodacoluna=coluna,rodalinha=linha,rodapalavra=0;valido;rodacoluna++,rodalinha--,rodapalavra++){      
        if(palavra[rodapalavra]  != jogo.tabuleiro[rodalinha][rodacoluna] && palavra[rodapalavra] !='\0'){
            
            return 0;
        }
        if(palavra[rodapalavra]=='\0'){
            return valido;
        }
    }

}

int ProcuraNaMatrizDiagonalparaDireitabaixo(int linha,int coluna,tTabuleiro jogo,char palavra[]){
    int rodapalavra;int rodacoluna,rodalinha;
    int valido=1;
    
    
    
    for(rodacoluna=coluna,rodalinha=linha,rodapalavra=0;valido;rodacoluna++,rodalinha++,rodapalavra++){      
        if(palavra[rodapalavra]  != jogo.tabuleiro[rodalinha][rodacoluna] && palavra[rodapalavra] !='\0'){
            
            return 0;
        }
        if(palavra[rodapalavra]=='\0'){
            return valido;
        }
    }

}

int ProcuraNaMatrizDiagonalparaEsquerdaCima(int linha,int coluna,tTabuleiro jogo,char palavra[]){
    int rodapalavra;int rodacoluna,rodalinha;
    int valido=1;
    
    
    
    for(rodacoluna=coluna,rodalinha=linha,rodapalavra=0;valido;rodacoluna--,rodalinha--,rodapalavra++){      
        if(palavra[rodapalavra]  != jogo.tabuleiro[rodalinha][rodacoluna] && palavra[rodapalavra] !='\0'){
            
            return 0;
        }
        if(palavra[rodapalavra]=='\0'){
            return valido;
        }
    }

}

int ProcuraNaMatrizDiagonalparaEsquerdabaixo(int linha,int coluna,tTabuleiro jogo,char palavra[]){
    int rodapalavra;int rodacoluna,rodalinha;
    int valido=1;
    
    
    
    for(rodacoluna=coluna,rodalinha=linha,rodapalavra=0;valido;rodacoluna--,rodalinha++,rodapalavra++){      
        if(palavra[rodapalavra]  != jogo.tabuleiro[rodalinha][rodacoluna] && palavra[rodapalavra] !='\0'){
            
            return 0;
        }
        if(palavra[rodapalavra]=='\0'){
            return valido;
        }
    }

}

void Imprimitabelapalavravertical(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]){
    int tamanho=0;
    int i=0;int roda;
    int rodapalavra;
    tamanho=strlen(palavra);
    
    for(i=linha,rodapalavra=0,roda=0;roda<tamanho;i++,rodapalavra++,roda++){
        if(palavra[0]){
            palavra[0]=palavra[0]+('A' - 'a');
        }
   
       
        
        if(matriz[i][coluna]>='A' && matriz[i][coluna]<='Z'){
        matriz[i][coluna]=palavra[rodapalavra]+('A' - 'a');
        }else{
        matriz[i][coluna]=palavra[rodapalavra];
        }
        
        
        
        
    }
    
}

void ImprimitabelapalavraDiagonalparadireitabaixo(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]){
    int tamanho=0;
    int rodalinha=0,rodacoluna=0;int roda=0;
    int rodapalavra;
    tamanho=strlen(palavra);
    
    for(rodalinha=linha,rodacoluna=coluna,rodapalavra=0,roda=0;roda<tamanho;rodalinha++,rodacoluna++,rodapalavra++,roda++){
        if(palavra[0]){
            palavra[0]=palavra[0]+('A' - 'a');
        }
   
          
        if(matriz[rodalinha][rodacoluna]>='A' && matriz[rodalinha][rodacoluna]<='Z'){
        matriz[rodalinha][rodacoluna]=palavra[rodapalavra]+('A' - 'a');
        }else{
        matriz[rodalinha][rodacoluna]=palavra[rodapalavra];
        }  
    }
}

void ImprimitabelapalavraDiagonalparadireitacima(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]){
    int tamanho=0;
    int rodalinha=0,rodacoluna=0;int roda=0;
    int rodapalavra;
    tamanho=strlen(palavra);
    
    for(rodalinha=linha,rodacoluna=coluna,rodapalavra=0,roda=0;roda<tamanho;rodalinha--,rodacoluna++,rodapalavra++,roda++){
        if(palavra[0]){
            palavra[0]=palavra[0]+('A' - 'a');
        }
   
          
        if(matriz[rodalinha][rodacoluna]>='A' && matriz[rodalinha][rodacoluna]<='Z'){
        matriz[rodalinha][rodacoluna]=palavra[rodapalavra]+('A' - 'a');
        }else{
        matriz[rodalinha][rodacoluna]=palavra[rodapalavra];
        }  
    }
}

void ImprimitabelapalavraDiagonalparaEsquerdaCima(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]){
    int tamanho=0;
    int rodalinha=0,rodacoluna=0;int roda=0;
    int rodapalavra;
    tamanho=strlen(palavra);
    
    for(rodalinha=linha,rodacoluna=coluna,rodapalavra=0,roda=0;roda<tamanho;rodalinha--,rodacoluna--,rodapalavra++,roda++){
        if(palavra[0]){
            palavra[0]=palavra[0]+('A' - 'a');
        }
   
          
        if(matriz[rodalinha][rodacoluna]>='A' && matriz[rodalinha][rodacoluna]<='Z'){
        matriz[rodalinha][rodacoluna]=palavra[rodapalavra]+('A' - 'a');
        }else{
        matriz[rodalinha][rodacoluna]=palavra[rodapalavra];
        }  
    }
}
void ImprimitabelapalavraDiagonalparaEsquerdaBaixo(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]){
    int tamanho=0;
    int rodalinha=0,rodacoluna=0;int roda=0;
    int rodapalavra;
    tamanho=strlen(palavra);
    
    for(rodalinha=linha,rodacoluna=coluna,rodapalavra=0,roda=0;roda<tamanho;rodalinha++,rodacoluna--,rodapalavra++,roda++){
        if(palavra[0]){
            palavra[0]=palavra[0]+('A' - 'a');
        }
   
          
        if(matriz[rodalinha][rodacoluna]>='A' && matriz[rodalinha][rodacoluna]<='Z'){
        matriz[rodalinha][rodacoluna]=palavra[rodapalavra]+('A' - 'a');
        }else{
        matriz[rodalinha][rodacoluna]=palavra[rodapalavra];
        }  
    }
}


void Imprimitabelapalavraverticalparacima(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]){
    int tamanho=0;
    int i=0;int roda;
    int rodapalavra;
    tamanho=strlen(palavra);
    
    for(i=linha,rodapalavra=0,roda=0;roda<tamanho;i--,rodapalavra++,roda++){
        if(palavra[0]){
            palavra[0]=palavra[0]+('A' - 'a');
        }
   
          
        if(matriz[i][coluna]>='A' && matriz[i][coluna]<='Z'){
        matriz[i][coluna]=palavra[rodapalavra]+('A' - 'a');
        }else{
        matriz[i][coluna]=palavra[rodapalavra];
        }  
    }
    
}

void ImprimitabelapalavraHorizontaldireita(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]){
    int tamanho=0;
    int i=0;int roda;
    int rodapalavra;
    tamanho=strlen(palavra);
    
    for(i=coluna,rodapalavra=0,roda=0;roda<tamanho;i++,rodapalavra++,roda++){
        if(palavra[0]){
            palavra[0]=palavra[0]+('A' - 'a');
        }
   
        if(matriz[linha][i]>='A' && matriz[linha][i]<='Z'){
        matriz[linha][i]=palavra[rodapalavra]+('A' - 'a');
        }else{
        matriz[linha][i]=palavra[rodapalavra];
        }
        
    }
    
}
void ImprimitabelapalavraHorizontalesquerda(int linha,int coluna,char palavra[],int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]){
    int tamanho=0;
    int i=0;int roda;
    int rodapalavra;
    tamanho=strlen(palavra);
    
    for(i=coluna,rodapalavra=0,roda=0;roda<tamanho;i--,rodapalavra++,roda++){
        if(palavra[0]){  
          palavra[0]=palavra[0]+('A' - 'a');
       
        }
   
        if(matriz[linha][i]>='A' && matriz[linha][i]<='Z'){
        matriz[linha][i]=palavra[rodapalavra]+('A' - 'a');
        }
        else{
        matriz[linha][i]=palavra[rodapalavra];
        }
        
        
        
    }
    
}

void ImprimitaSoLetra(int linha,int coluna,int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna],tTabuleiro jogo){

        matriz[linha][coluna]=jogo.tabuleiro[linha][coluna]+('A' - 'a');
}

Guarda Guardapalavraeidentificador(int identificador,int tamanhopal,char palavra[]){
   
    Guarda valor;
    
    valor.identificador=identificador;
    
    strcpy(valor.letra[0],palavra);

    return valor;
  
 //ira guardar na struct um identificador e a palavra que ele recebeu
 //ira copiar a string da palavra para valor.letra   
 //ira retornar a struct

}

Guarda ProcuraNaMatriz(int cod1,int cod2,tTabuleiro jogo,int tamlinha,int tamcoluna,char matriz[tamlinha][tamcoluna]){
    //essa função ira procurar nas coordenas uma palavra, ele realiza uma repeticao para encontrar qual a palavra
    //se alguma função retornar positivo de procura a palavra
    //então ele salva na struct resultado um identificador e a palavra achada
    //identificador positivo palavra pertence ao jogador 1
    //identificador negativo palavra pertence ao jogador 2
    //ele chama a função de imprimir a palavra naquela posição
    //e retorna resultado
    //se ele nao achar nenehuma palavra ele retorna o identificador da struct 0
    
    int i=0;int tamanho;
    Guarda resultado;
    int teste;
 
    resultado.identificador=0;
    for(i=0;i<jogo.palavraspjogador;i++){    
       
    if(ProcuraNaMatrizVerticalbaixo(cod1,cod2,jogo,jogo.palavrasjogador1[i])){
         tamanho=strlen(jogo.palavrasjogador1[i]);
        resultado=Guardapalavraeidentificador(1,tamanho,jogo.palavrasjogador1[i]);
        Imprimitabelapalavravertical(cod1,cod2,jogo.palavrasjogador1[i],tamlinha,tamcoluna,matriz);        
        return resultado;
    }
    if(ProcuraNaMatrizVerticalcima(cod1,cod2,jogo,jogo.palavrasjogador1[i])){
        tamanho=strlen(jogo.palavrasjogador1[i]);
        resultado=Guardapalavraeidentificador(2,tamanho,jogo.palavrasjogador1[i]);
        Imprimitabelapalavraverticalparacima(cod1,cod2,jogo.palavrasjogador1[i],tamlinha,tamcoluna,matriz);
        return resultado;  
    }
    
    if(ProcuraNaMatrizHorizontaldireita(cod1,cod2,jogo,jogo.palavrasjogador1[i])){
        tamanho=strlen(jogo.palavrasjogador1[i]);
        resultado=Guardapalavraeidentificador(3,tamanho,jogo.palavrasjogador1[i]);
        ImprimitabelapalavraHorizontaldireita(cod1,cod2,jogo.palavrasjogador1[i],tamlinha,tamcoluna,matriz);
        return resultado;
    }
    
    if(ProcuraNaMatrizHorizontalesquerda(cod1,cod2,jogo,jogo.palavrasjogador1[i])){
        tamanho=strlen(jogo.palavrasjogador1[i]); 
        resultado=Guardapalavraeidentificador(4,tamanho,jogo.palavrasjogador1[i]);
        ImprimitabelapalavraHorizontalesquerda(cod1,cod2,jogo.palavrasjogador1[i],tamlinha,tamcoluna,matriz);
        
        return resultado;
        
    }
    if(ProcuraNaMatrizDiagonalparaDireitabaixo(cod1,cod2,jogo,jogo.palavrasjogador1[i])){
    tamanho=strlen(jogo.palavrasjogador1[i]);
    resultado=Guardapalavraeidentificador(5,tamanho,jogo.palavrasjogador1[i]);    
    ImprimitabelapalavraDiagonalparadireitabaixo(cod1,cod2,jogo.palavrasjogador1[i],tamlinha,tamcoluna,matriz);
    
    
    return resultado;
    }
    
    if(ProcuraNaMatrizDiagonalparaDireitacima(cod1,cod2,jogo,jogo.palavrasjogador1[i])){
    tamanho=strlen(jogo.palavrasjogador1[i]);
    resultado=Guardapalavraeidentificador(6,tamanho,jogo.palavrasjogador1[i]);
    ImprimitabelapalavraDiagonalparadireitacima(cod1,cod2,jogo.palavrasjogador1[i],tamlinha,tamcoluna,matriz);
    
    
    return resultado;
    }
    
    if(ProcuraNaMatrizDiagonalparaEsquerdabaixo(cod1,cod2,jogo,jogo.palavrasjogador1[i])){
    tamanho=strlen(jogo.palavrasjogador1[i]); 
    resultado=Guardapalavraeidentificador(7,tamanho,jogo.palavrasjogador1[i]);
    ImprimitabelapalavraDiagonalparaEsquerdaBaixo(cod1,cod2,jogo.palavrasjogador1[i],tamlinha,tamcoluna,matriz);
   
    
    return resultado;
    }
    
    if(ProcuraNaMatrizDiagonalparaEsquerdaCima(cod1,cod2,jogo,jogo.palavrasjogador1[i])){
    tamanho=strlen(jogo.palavrasjogador1[i]);
    resultado=Guardapalavraeidentificador(8,tamanho,jogo.palavrasjogador1[i]);
    ImprimitabelapalavraDiagonalparaEsquerdaCima(cod1,cod2,jogo.palavrasjogador1[i],tamlinha,tamcoluna,matriz);
    
    
    return resultado;
    }
    
    
  
    
    if(ProcuraNaMatrizVerticalbaixo(cod1,cod2,jogo,jogo.palavrasjogador2[i])){
       tamanho=strlen(jogo.palavrasjogador2[i]);
       resultado=Guardapalavraeidentificador(-1,tamanho,jogo.palavrasjogador2[i]); 
       Imprimitabelapalavravertical(cod1,cod2,jogo.palavrasjogador2[i],tamlinha,tamcoluna,matriz);
        
       return resultado;
        
           
    }
    if(ProcuraNaMatrizVerticalcima(cod1,cod2,jogo,jogo.palavrasjogador2[i])){
        tamanho=strlen(jogo.palavrasjogador2[i]);
        resultado=Guardapalavraeidentificador(-2,tamanho,jogo.palavrasjogador2[i]);
        Imprimitabelapalavraverticalparacima(cod1,cod2,jogo.palavrasjogador2[i],tamlinha,tamcoluna,matriz);
       
        return resultado;
      
 
    }
    if(ProcuraNaMatrizHorizontaldireita(cod1,cod2,jogo,jogo.palavrasjogador2[i])){
        tamanho=strlen(jogo.palavrasjogador2[i]);
        resultado=Guardapalavraeidentificador(-3,tamanho,jogo.palavrasjogador2[i]);
        ImprimitabelapalavraHorizontaldireita(cod1,cod2,jogo.palavrasjogador2[i],tamlinha,tamcoluna,matriz);
        
        
        return resultado;
        
    }
    if(ProcuraNaMatrizHorizontalesquerda(cod1,cod2,jogo,jogo.palavrasjogador2[i])){
        tamanho=strlen(jogo.palavrasjogador2[i]);
        resultado=Guardapalavraeidentificador(-4,tamanho,jogo.palavrasjogador2[i]);
        ImprimitabelapalavraHorizontalesquerda(cod1,cod2,jogo.palavrasjogador2[i],tamlinha,tamcoluna,matriz);
       
        return resultado;
    }
    if(ProcuraNaMatrizDiagonalparaDireitabaixo(cod1,cod2,jogo,jogo.palavrasjogador2[i])){
    tamanho=strlen(jogo.palavrasjogador2[i]);
    resultado=Guardapalavraeidentificador(-5,tamanho,jogo.palavrasjogador2[i]);    
    ImprimitabelapalavraDiagonalparadireitabaixo(cod1,cod2,jogo.palavrasjogador2[i],tamlinha,tamcoluna,matriz);
    
    
    return resultado;
    }
    
    if(ProcuraNaMatrizDiagonalparaDireitacima(cod1,cod2,jogo,jogo.palavrasjogador2[i])){
    tamanho=strlen(jogo.palavrasjogador2[i]);
    resultado=Guardapalavraeidentificador(-6,tamanho,jogo.palavrasjogador2[i]);
    ImprimitabelapalavraDiagonalparadireitacima(cod1,cod2,jogo.palavrasjogador2[i],tamlinha,tamcoluna,matriz);
    
    
    return resultado;
    }
    
    if(ProcuraNaMatrizDiagonalparaEsquerdabaixo(cod1,cod2,jogo,jogo.palavrasjogador2[i])){
    tamanho=strlen(jogo.palavrasjogador2[i]);    
    resultado=Guardapalavraeidentificador(-7,tamanho,jogo.palavrasjogador2[i]);
    ImprimitabelapalavraDiagonalparaEsquerdaBaixo(cod1,cod2,jogo.palavrasjogador2[i],tamlinha,tamcoluna,matriz);
    
    
    return resultado;
    }
    
    if(ProcuraNaMatrizDiagonalparaEsquerdaCima(cod1,cod2,jogo,jogo.palavrasjogador2[i])){
    tamanho=strlen(jogo.palavrasjogador2[i]);    
    resultado=Guardapalavraeidentificador(-8,tamanho,jogo.palavrasjogador2[i]);
    ImprimitabelapalavraDiagonalparaEsquerdaCima(cod1,cod2,jogo.palavrasjogador2[i],tamlinha,tamcoluna,matriz);
   
    return resultado;
    }
    
    
    
    
    }    
    
    resultado.identificador=0;
    return resultado;
}


Guarda JogaoJogo(int cod1,int cod2,tTabuleiro jogo,int tamlinha,int tamcoluna, char matriz[tamlinha][tamcoluna]){
    //essa funçao manda para Procuranamatriz as posiçoes da jogada,configurajogo,e a matriz de palavras
    //essa função recebe resultado da função procura na matriz 
    //se identificador de resultado for positivo é uma palavra do jogador1
    //se identificador de resultado for negativo é uma palavra do jogador2
    //se identificador de resultado for 0 não tem palavra,entao ele chama a função imprimiSoLetra
    //retorna a struct com a plaavra e identificador alterado
    //identificador 1 é palavra jogador1
    //identificador 2 é palavra jogadpr 2
    //identificador 3 não foi achada nada
    
    Guarda resultadobusca;
    int roda;int roda2;
    int tamanho;
    
    
    
resultadobusca.identificador=0;   
resultadobusca=ProcuraNaMatriz(cod1,cod2,jogo,tamlinha,tamcoluna,matriz);


if(resultadobusca.identificador==1|| resultadobusca.identificador==2 || resultadobusca.identificador==3 || resultadobusca.identificador==4 ||resultadobusca.identificador==5 || resultadobusca.identificador==6 || resultadobusca.identificador==7 || resultadobusca.identificador==8){
    resultadobusca.identificador=1;  
    return resultadobusca;
 
}


if(resultadobusca.identificador==-1|| resultadobusca.identificador==-2 || resultadobusca.identificador==-3 || resultadobusca.identificador==-4 || resultadobusca.identificador==-5 || resultadobusca.identificador==-6 || resultadobusca.identificador==-7 || resultadobusca.identificador==-8){
    resultadobusca.identificador=2;
    return resultadobusca;
 
}    
    

if(resultadobusca.identificador==0){
     ImprimitaSoLetra(cod1,cod2,tamlinha,tamcoluna,matriz,jogo);
 
     resultadobusca.identificador=0;
     return resultadobusca;
     
}


   
}

void Imprimirtabuleirodepoisdejogado(int linha,int coluna,char matriz[linha][coluna]){
    int roda;int roda2;
    int casa;
    printf("    ");
    for(casa=0;casa<coluna;casa++){
        printf("%02d",casa);
        if(casa!=coluna-1){
            printf(" ");
        }
    }
    printf("\n");
    
    
    
    
    
for(roda=0;roda<linha;roda++){
    printf("%02d|",roda);
        for(roda2=0;roda2<coluna;roda2++){
            printf(" %c ",matriz[roda][roda2]);
        }
        printf("|\n");
    }
    
   

 



}

coordenadas AteJogadaservalida1(int linha,int coluna, tTabuleiro jogo, tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2, matrizpalavras novasjogador1, matrizpalavras novasjogador2,int linhamatriz,int colunamatriz,char matriz[linhamatriz][colunamatriz]){
    int valido=1;
    int cod1=linha,cod2=coluna;
    coordenadas dentro;
    while(valido){
    
    PalavrasRestanteseditadajogo(jogo,jogador1,jogador2,pontuacao1,pontuacao2,novasjogador1,novasjogador2); 
    Imprimirtabuleirodepoisdejogado(linhamatriz,colunamatriz,matriz);
    printf("\n");
    printf("Coordenadas fora do tabuleiro.%s por favor entre com novas coordenadas para a sua jogada:\n",jogador1.nome);
    scanf("%d %d",&cod1,&cod2);
        
    if(JogadaValida(cod1,cod2,jogo)){
        dentro.cod1=cod1;
        dentro.cod2=cod2;
        
        valido=0;
    }
    
    }
    return dentro;

   //essa função ira se repetir ate que a jogada do jogador seja valida
   //e retorna uma struct com  as novas coordenadas

}

coordenadas AteJogadaservalida2(int linha,int coluna, tTabuleiro jogo, tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2, matrizpalavras novasjogador1, matrizpalavras novasjogador2,int linhamatriz,int colunamatriz,char matriz[linhamatriz][colunamatriz]){
    int valido=1;
    int cod1=linha,cod2=coluna;
    coordenadas dentro;
    while(valido){
    
    PalavrasRestanteseditadajogo(jogo,jogador1,jogador2,pontuacao1,pontuacao2,novasjogador1,novasjogador2);   
    Imprimirtabuleirodepoisdejogado(linhamatriz,colunamatriz,matriz);
    printf("\n");
    printf("Coordenadas fora do tabuleiro.%s por favor entre com novas coordenadas para a sua jogada:\n",jogador2.nome);
    scanf("%d %d",&cod1,&cod2);
        
    if(JogadaValida(cod1,cod2,jogo)){
        dentro.cod1=cod1;
        dentro.cod2=cod2;
        
        valido=0;
    }
    
    }
    return dentro;

   //essa função ira se repetir ate que a jogada do jogador seja valida
    //e retorna uma struct com  as novas coordenadas

}

int palavraaindanaofoiimpressa(int cod1,int cod2,int linha,int coluna,char matriz[linha][coluna]){
    if(matriz[cod1][cod2]=='-'  || matriz[cod1][cod2]>='a' && matriz[cod1][cod2]<='z'){
        return 1;
    }
    else{
        return 0;
    }
    
    
//verifica se essa coordenada já foi jogada
//ira ter uma uma maiuscula se ja foi jogada    


}

coordenadas coordenadasqnaotenhapalavras1(int cod1,int cod2,int linha,int coluna,char matriz[linha][coluna],tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2, matrizpalavras novasjogador1, matrizpalavras novasjogador2,tTabuleiro jogo){
    int valido=1;
    int novalinha,novacoluna;
    coordenadas nova;
    while(valido){
        PalavrasRestanteseditadajogo(jogo,jogador1,jogador2,pontuacao1,pontuacao2,novasjogador1,novasjogador2);   
        Imprimirtabuleirodepoisdejogado(linha,coluna,matriz);
        printf("\n");
        printf("Coordenadas ja jogadas.%s por favor entre com novas coordenadas para a sua jogada:\n",jogador1.nome);
        scanf("%d %d",&novalinha,&novacoluna);
        
    
        if(palavraaindanaofoiimpressa(novalinha,novacoluna,linha,coluna,matriz)){
            nova.cod1=novalinha;
            nova.cod2=novacoluna;
            valido=0;
        
        }
        
    
    }
    
    return nova;
    
     //essa função ira se repetir ate que a jogada do jogador seja valida
    //e retorna uma struct com  as novas coordenadas

}
coordenadas coordenadasqnaotenhapalavras2(int cod1,int cod2,int linha,int coluna,char matriz[linha][coluna],tJogador jogador1,tJogador jogador2,int pontuacao1,int pontuacao2, matrizpalavras novasjogador1, matrizpalavras novasjogador2,tTabuleiro jogo){
    int valido=1;
    int novalinha,novacoluna;
    coordenadas nova;
    while(valido){
        PalavrasRestanteseditadajogo(jogo,jogador1,jogador2,pontuacao1,pontuacao2,novasjogador1,novasjogador2);   
        Imprimirtabuleirodepoisdejogado(linha,coluna,matriz);
        printf("\n");
        printf("Coordenadas ja jogadas.%s por favor entre com novas coordenadas para a sua jogada:\n",jogador2.nome);
        scanf("%d %d",&novalinha,&novacoluna);
        
    
        if(palavraaindanaofoiimpressa(novalinha,novacoluna,linha,coluna,matriz)){
            nova.cod1=novalinha;
            nova.cod2=novacoluna;
            valido=0;
        
        }
        
    
    }
    
    return nova;
    
    //essa função ira se repetir ate que a jogada do jogador seja valida
    //e retorna uma struct com  as novas coordenadas

}



matrizpalavras RetiraPalavraachadajogador1(tTabuleiro jogo, char palavra[]){
    int roda=0;int adiciona;
    matrizpalavras nova={"\0"};
   
    
    for(roda=0,adiciona=0;roda<jogo.palavraspjogador;roda++){
        if(strcmp(jogo.palavrasjogador1[roda],palavra)!=0 && strcmp(jogo.palavrasjogador1[roda]," \0")!=0 ){
        
            strcpy(nova.palavrasjogador[adiciona],jogo.palavrasjogador1[roda]);
            adiciona++;
        }
       
    
   
    }
    
    
   
    return nova;
    
    //cria uma nova matriz de palavras adicionando apenas as palavras que não são " \0"
    //e retorna a nova matriz
  
}
matrizpalavras RetiraPalavraachadajogador2(tTabuleiro jogo, char palavra[]){
    int roda=0;int adiciona;
    matrizpalavras nova={"\0"};
   
    
    for(roda=0,adiciona=0;roda<jogo.palavraspjogador;roda++){
        if(strcmp(jogo.palavrasjogador2[roda],palavra)!=0 && strcmp(jogo.palavrasjogador2[roda]," \0")!=0 ){
        
            strcpy(nova.palavrasjogador[adiciona],jogo.palavrasjogador2[roda]);
            adiciona++;
        }
    
    
    
    }
    
    
   
    return nova;
  
    //cria uma nova matriz de palavras adicionando apenas as palavras que não são " \0"
    //e retorna a nova matriz
    
}

int VerificaSeJogoAcabou(int contapalavras1,int contapalavras2, int quantidadepal,int pontuacao1,int pontuacao2, tJogador jogador1, tJogador jogador2,FILE *estatistic){
    
    if(contapalavras1==quantidadepal || contapalavras2==quantidadepal){
        if(pontuacao1>pontuacao2){ 
            printf("\n%s Ganhou!!!",jogador1.nome);
        return -2;
        
        }
        if(pontuacao2>pontuacao1){
        printf("\n%s Ganhou!!!",jogador2.nome);
        return -2;
        }
    
        if(pontuacao1==pontuacao2){
            printf("\nEmpate");
        return -2;
        
        }
    
    
    }
     printf("\n");  

     //recebe os dados da partida e verifica se o jogo já acabou
     //imprimi quem ganhou a partida ou se foi empate
     //e retorna -2 para o main finaliza o jogo


}



void jogoresultado(int pontuacao1,int pontuacao2, tJogador jogador1, tJogador jogador2){
        if(pontuacao1>pontuacao2){
            printf("%s Ganhou!!!",jogador1.nome);
            exit(1);
        
        }
        if(pontuacao2>pontuacao1){
        printf("%s Ganhou!!!",jogador2.nome);
        exit(1);
        }
    
        if(pontuacao1==pontuacao2){
            printf("Empate");
            exit(1);
        
        }


 printf("\n");  
 
 //recebe os dados do jogo 
 //e imprimi o resultado final do jogo
 //e da exit 
}

tJogador Criajogador(int numero){
    tJogador jogador;
    printf("Nome do Jogador %d:\n",numero);
    scanf("%s",jogador.nome);
    
    
    return jogador;

    
//função que recebe o nome do jogador
//e retorna tjogador

}



guardaestatic guardapalavraestat(char palavra[],int casa,guardaestatic novaguarda,int contaturno){
  
   
    strcpy(novaguarda.palavras[casa],palavra);
    
    novaguarda.palavras[casa][19]=contaturno;
    
    return novaguarda;
    
    
    //essa função vai guardando as palavras achadas e o turno
    //adiciona a palavra na matriz da struct novaguarda
    //variando a linha que é mandanda como parametro sinalizada por casa
    //na coluna 19 da matriz de novaguarda ira receber o contaturno que corresponde ao numero da jogada qual foi achada a palavra
    //retorna novaguarda atualizada
    
    
}



int main(int argc, char** argv) {
   
    tTabuleiro configurajogo;
    tJogador jogador1,jogador2;
    int pontos1=0,pontos2=0;int turnos;int contadorachado2=0;int contadorachado1=0; int contaturno;
    int cod1=0,cod2=0;int i;int cadeado=0; int contaturnos=0;int roda,roda2;int contapalavras1,contapalavras2;  
    Guarda jogada;
    coordenadas dentro,nova;
    matrizpalavras novajogador1,novajogador2;
    char caminho[1000],inicia[1000],estati[1000];
    FILE *pconfig,*inicializacao,*estatistic;
    estatisticas jogadascara1,jogadascara2;
    guardaestatic valendo1ponto,valendo2ponto;
    
     
    
    sprintf(caminho,"%s/config.txt",argv[1]);           //adiciona o config.txt ao argv[1]
    pconfig=fopen(caminho,"r");                         //abertura do pconfig modo leitura
    
        if(!pconfig){
            printf("ERRO: O diretório de arquivos de configuração não foi informado");
            exit(1);
        } 

        configurajogo= LeConf(pconfig);             //leitura das configurajogo com parametro pconfig
        fclose(pconfig);                             //fechando pconfig                   
     
    sprintf(inicia,"%s/saida/Inicializacao.txt",argv[1]);       
    inicializacao=fopen(inicia,"w");                //criando o arquivo inicialização
     
        if(!inicializacao){
            printf("ERRO: O arquivo de Inicialização não foi gerado");
            exit(1);
        } 
     
    sprintf(estati,"%s/saida/Estatisticas.txt",argv[1]);    
    estatistic=fopen(estati,"w");                   //criando o arquivo estatistica
        if(!estatistic){
            printf("ERRO: O arquivo de Estatisticas não foi gerado");
            exit(1);
        }   
    char matriz[configurajogo.tamanho][configurajogo.tamanho]; 
       
    
        jogador1=Criajogador(1);        //criando jogadores
        jogador2=Criajogador(2);
        valendo1ponto.identificador=1;  //definindo identificadores das structs de pontuação
        valendo2ponto.identificador=2;
        
        Geraaquivoinicializacao(configurajogo,jogador1,jogador2,inicializacao); //chama a função que gera o arquivo de inicialização
        fclose(inicializacao);                                                  //fecha o arquivo            
        
       PalavrasRestantesjogo(configurajogo,jogador1,jogador2,pontos1,pontos2); 
       printf("\n");      
       Mostrartabuleiro(configurajogo.tamanho,configurajogo.tamanho,matriz,configurajogo.tamanho);
       novajogador1=RetiraPalavraachadajogador1(configurajogo," \0");    //inicia as matrizes de palavras para adicinar todas as palavras do jogador antes de retirar
       novajogador2=RetiraPalavraachadajogador2(configurajogo," \0");    //inicia as matrizes de palavras para adicinar todas as palavras do jogador antes de retirar
       
       
        
        
        
           for(turnos=0;turnos<configurajogo.turno;turnos++){                                       //for que ira rodar a quantidade de turnos
                printf("%s por favor entre com as coordenadas para a sua jogada:\n",jogador1.nome);
                    scanf("%d %d",&cod1,&cod2);
                       if(!JogadaValida(cod1,cod2,configurajogo)){  //verifica se a jogada é valida
                            dentro=AteJogadaservalida1(cod1,cod2,configurajogo,jogador1,jogador2,pontos1,pontos2,novajogador1,novajogador2,configurajogo.tamanho,configurajogo.tamanho,matriz);
                            cod1=dentro.cod1;
                            cod2=dentro.cod2;
                       
                       }
                       if(!palavraaindanaofoiimpressa(cod1,cod2,configurajogo.tamanho,configurajogo.tamanho,matriz)){ //verifica se essa coordenada ja foi jogada
                           nova=coordenadasqnaotenhapalavras1(cod1,cod2,configurajogo.tamanho,configurajogo.tamanho,matriz,jogador1,jogador2,pontos1,pontos2,novajogador1,novajogador2,configurajogo);
                           cod1=nova.cod1;
                           cod2=nova.cod2;
                       
                       } 
                        jogada.identificador=0;
                        jogada=JogaoJogo(cod1,cod2,configurajogo,configurajogo.tamanho,configurajogo.tamanho,matriz);  //jogada recebe a struct guarda que possui a palavra achada e um identificador 1,2 ou 0
                        
                        contaturnos++;
                    
                    if(jogada.identificador==1){           //identificador for igual a 1 , palavra achada do jogador 1
                        for(roda=0;roda<configurajogo.palavraspjogador;roda++){
                            if(strcmp(jogada.letra[0],configurajogo.palavrasjogador1[roda])==0){      //quando a palavra retornada for igual a palavra do jogador              
                                valendo2ponto=guardapalavraestat(configurajogo.palavrasjogador1[roda],contadorachado2,valendo2ponto,contaturnos); //valendo dois ponto adicona essa palavra na matriz de pontuação de palabras
                                contadorachado2++;
                                strcpy(configurajogo.palavrasjogador1[roda]," \0");                     //copia " \0" para o lugar que antes era a palavra achada 
                                novajogador1=RetiraPalavraachadajogador1(configurajogo,configurajogo.palavrasjogador1[roda]); //essa função vai retirar a palavra achada do jogador
                                pontos1=pontos1+2;                  //atualiza os dados da partida
                                contapalavras1=contapalavras1+1;
                                jogadascara1.Feitos=jogadascara1.Feitos+2;
                            }
                        }     
                    }
          
                    if(jogada.identificador==2){                                //identificaodr igual a 2,palavra achada do jogador 2
                        for(roda=0;roda<configurajogo.palavraspjogador;roda++){                         
                            if(strcmp(jogada.letra[0],configurajogo.palavrasjogador2[roda])==0){
                                valendo1ponto=guardapalavraestat(configurajogo.palavrasjogador2[roda],contadorachado1,valendo1ponto,contaturnos);
                                contadorachado1++; 
                                strcpy(configurajogo.palavrasjogador2[roda]," \0");          //copia " \0" para o lugar que antes era a palavra achada 
                                novajogador2=RetiraPalavraachadajogador2(configurajogo,configurajogo.palavrasjogador2[roda]);                        
                                pontos2=pontos2+1;                      //atualiza os dados da partida
                                contapalavras2=contapalavras2+1;
                                jogadascara2.Recebidos=jogadascara2.Recebidos+1;
                            } 
                        }
                    }
                    jogadascara1.Total=pontos1;         //atualiza os dados da estatistica
                    jogadascara2.Total=pontos2;
      
            PalavrasRestanteseditadajogo(configurajogo,jogador1,jogador2,pontos1,pontos2,novajogador1,novajogador2); 
            Imprimirtabuleirodepoisdejogado(configurajogo.tamanho,configurajogo.tamanho,matriz);
            cadeado=VerificaSeJogoAcabou(contapalavras1,contapalavras2,configurajogo.palavraspjogador,pontos1,pontos2,jogador1,jogador2,estatistic);                
                if(cadeado==-2){
                    GeraarquivoEstatisticas(estatistic,jogador1,jogador2,configurajogo,jogadascara1,jogadascara2,valendo1ponto,valendo2ponto);
                    exit(1);
                }
                
           
                printf("%s por favor entre com as coordenadas para a sua jogada:\n",jogador2.nome);
                    scanf("%d %d",&cod1,&cod2);
                        if(!JogadaValida(cod1,cod2,configurajogo)){
                            dentro=AteJogadaservalida2(cod1,cod2,configurajogo,jogador1,jogador2,pontos1,pontos2,novajogador1,novajogador2,configurajogo.tamanho,configurajogo.tamanho,matriz);
                            cod1=dentro.cod1;
                            cod2=dentro.cod2;
                       
                       }
                       if(!palavraaindanaofoiimpressa(cod1,cod2,configurajogo.tamanho,configurajogo.tamanho,matriz)){
                           nova=coordenadasqnaotenhapalavras2(cod1,cod2,configurajogo.tamanho,configurajogo.tamanho,matriz,jogador1,jogador2,pontos1,pontos2,novajogador1,novajogador2,configurajogo);
                           cod1=nova.cod1;
                           cod2=nova.cod2;
                       
                       } 
                        
                    
                        jogada.identificador=0;
                        jogada=JogaoJogo(cod1,cod2,configurajogo,configurajogo.tamanho,configurajogo.tamanho,matriz);
                        contaturnos++;
                    
                        if(jogada.identificador==1){        //identificador 1,palavra achada do jogador 1   
                            for(roda=0;roda<configurajogo.palavraspjogador;roda++){
                                if(strcmp(jogada.letra[0],configurajogo.palavrasjogador1[roda])==0){
                                valendo1ponto=guardapalavraestat(configurajogo.palavrasjogador1[roda],contadorachado1,valendo1ponto,contaturnos);
                                contadorachado1++;
                                strcpy(configurajogo.palavrasjogador1[roda]," \0");      //copia " \0" para o lugar que antes era a palavra achada 
                                novajogador1=RetiraPalavraachadajogador1(configurajogo,configurajogo.palavrasjogador1[roda]);
                                pontos1=pontos1+1;                      //atualiza os dados da partida,pontução,e contadores
                                contapalavras1=contapalavras1+1;
                                jogadascara1.Recebidos=jogadascara1.Recebidos+1;
                                
                                }
                            }     
                        }
          
                        if(jogada.identificador==2){ //identificador 2,palavra achada do jogador 2
                            for(roda=0;roda<configurajogo.palavraspjogador;roda++){
                                if(strcmp(jogada.letra[0],configurajogo.palavrasjogador2[roda])==0){
                                valendo2ponto=guardapalavraestat(configurajogo.palavrasjogador2[roda],contadorachado2,valendo2ponto,contaturnos);
                                contadorachado2++;
                                strcpy(configurajogo.palavrasjogador2[roda]," \0");
                                novajogador2=RetiraPalavraachadajogador2(configurajogo,configurajogo.palavrasjogador2[roda]);                         
                                pontos2=pontos2+2;                  //atualiza os dados do jogo,pontuação,e contadores de palavras
                                contapalavras2=contapalavras2+1;
                                jogadascara2.Feitos=jogadascara2.Feitos+2;
                                
                                }
                            }
                        }      
                        jogadascara1.Total=pontos1;     //atualiza os dados da estatistica
                        jogadascara2.Total=pontos2;
                        PalavrasRestanteseditadajogo(configurajogo,jogador1,jogador2,pontos1,pontos2,novajogador1,novajogador2); 
                        Imprimirtabuleirodepoisdejogado(configurajogo.tamanho,configurajogo.tamanho,matriz);
                        cadeado=VerificaSeJogoAcabou(contapalavras1,contapalavras2,configurajogo.palavraspjogador,pontos1,pontos2,jogador1,jogador2,estatistic);
                            if(cadeado==-2){
                                GeraarquivoEstatisticas(estatistic,jogador1,jogador2,configurajogo,jogadascara1,jogadascara2,valendo1ponto,valendo2ponto);
                                exit(1);
                            }
                            jogadascara1.Total=pontos1;         //atualiza os dados da estatistica
                            jogadascara2.Total=pontos2;
       
            }
       
            GeraarquivoEstatisticas(estatistic,jogador1,jogador2,configurajogo,jogadascara1,jogadascara2,valendo1ponto,valendo2ponto); 
            jogoresultado(pontos1,pontos2,jogador1,jogador2);
           
             //se o jogo não acabar achando todas a palavras 
             //apos o fim dos turnos 
             //o programa ira chamar a função de gerar o arquivo de estatistica 
             //e depois chamar a funçãod e imprimir o resultado final do jogo com o vencedor ou se é empate
          
    
       
       
       
       
    return (EXIT_SUCCESS);
}
