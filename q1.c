#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordena(int vetor[], int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i; j < tamanho; j++)
        {
            if (vetor[i] > vetor[j])
            {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
}

// Implementação iterativa do algoritmo de busca binária para retornar
// a posição de `target` no array `nums` de tamanho `n`
int buscaBinaria(int nums[], int n, int target){

    // o espaço de busca é nums[low…high]
    int low = 0, high = n - 1;
 
    // faz um loop até esgotar o espaço de busca
    while (low <= high)
    {
        // encontre o valor médio no espaço de pesquisa e
        // compara com o alvo
 
        int mid = (low + high)/2;    // estouro pode acontecer
        // int mid = low + (high - low)/2;
        // int mid = high - (high - low)/2;
 
        // valor alvo foi encontrado
        if (target == nums[mid]) {
            return mid;
            
        }
 
        // se o alvo for menor que o elemento do meio, descarta todos os elementos
        // no espaço de pesquisa certo, incluindo o elemento do meio
        else if (target < nums[mid]) {
            high = mid - 1;
        }
 
        // se o alvo for maior que o elemento do meio, descarta todos os elementos
        // no espaço de pesquisa à esquerda, incluindo o elemento do meio
        else {
            low = mid + 1;
        }
    }
 
    // destino não existe no array
    return -1;
    
}


int main (){
    int posicao = 0, contadora, pesquisa;
    int vetor[posicao];
    int i;

    printf("Digite o valor de posicoes do vetor:");
    scanf("%d", &contadora);

    for (posicao = 0; posicao < contadora; posicao++){
        printf("Digite o valor da posicao %d\n", (posicao + 1));
        scanf("%d", &vetor[posicao]);
    }
    ordena(vetor, posicao);

    printf ("Digite o valor a ser buscado:\n");
    scanf("%d", &pesquisa);
    printf("Vetor ordenado:\n");
    printf("==============================================\n");

    for (posicao = 0; posicao < contadora; posicao++){        
        printf("%d\n", vetor[posicao]);
    }
    
    printf("==============================================\n");
    printf("Elemento a ser pesquisado: %d\n", pesquisa);
    printf("==============================================\n");
    


    int index = buscaBinaria(vetor, contadora, pesquisa);
        if(index != -1){
            printf("Elemento %d encontrado.\n", pesquisa);
        }else{
            printf("Elemento %d NAO encontrado.\n", pesquisa);
        }
}