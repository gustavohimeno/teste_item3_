#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

/* função que retorna o mínimo de operações necessários para transformar
uma string em outra removendo e inserindo caracteres no seu fim */
int min_ops(string prim, string seg)
    {
    int min_ops = 0;
    int i = prim.size()-1;
    int j = seg.size()-1;
    //
    for(int count = 0; count < i; count++)
        {
        if(prim[count] != seg[count])
            {
            min_ops = i + j - 2*count;
            return min_ops;
            }
        }
    return min_ops;
    }


/* função que retorna se é possível realizar a transformação de uma string em 
outra dado um número k máximo de operações */
bool ConcatRemove(string s, string t, int k)
    {
    int ops = min_ops(s,t);
    if(ops <= k)
        {
        return true;
        }
    else
        {
        return false;
        }
    }


int main()
    {
    char s[100];
    char t[100];
    int k;
    
    //solicita que usuário insira a primeira string
    puts("Type a word (max = 100 characteres): ");
    //recebe a primeira string
    fgets(s, 100, stdin);
    //solicita que o usuário insira a segunda string
    puts("Type a word (max = 100 characteres): ");
    //recebe a segunda string
    fgets(t, 100, stdin);

    //solicita que o usuário insira o máximo de operações
    puts("Type the number of operations (max = 100): ");    
    //recebe o máximo de operações
    cin >> k;
    
    //verifica se é possível realiza a transformação com o máximo de operações
    if(ConcatRemove(s, t, k))
        {
        printf("yes");
        }
    else
        {
        printf("no");
        }
    }
