#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

/* função que retorna o mínimo de operações necessários para transformar
uma string em outra removendo e inserindo caracteres no seu fim */
int min_ops(string first, string sec, int i, int j, int &count)
    {
    int min_ops = 0;
    
    for(count = 0; count < i; count++)
        {
        if(first[count] != sec[count])
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
    int i = s.size()-1;
    int j = t.size()-1;
    
    //when k bigger than (i+j) I can remove all characters and concat all the new
    if(k > i+j)
        {
        return true;
        }
    
    //when k smaller than (i+j) i have to analyse the minimum operations necessary to convert
    int count = 0;
    int ops = min_ops(s, t, i, j, count);
    if(ops == k)
        {
        return true;
        }
    if(ops > k)
        {
        return false;
        }
    
    //when ops < k, I have 2 alternatives: 1- concat and remove, 2- remove when the string is empty
    if((k-ops)%2 == 0)
        {
        return true;
        }
    if(count == 0)
        {
        return true;
        }
    return false;
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
    puts("Type the number of operations (min = 0 and max = 100): ");    
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
    
    return 0;
    }

