#include <iostream>
#include <string>                   //Inclua string
#include <time.h>                   //Inclua tempo

using namespace std;

struct Jogador{                     //Define estrutura do Jogador
    char nome[10];
    int nivel;
};

Jogador players[4];                 //Array players[] recebe o tipo JOGADOR

void sleep(time_t atraso){          //Define tempo de atraso
    time_t tempo1, tempo2;
    time(&tempo1);

    do{
        time(&tempo2);
    }while((tempo2-tempo1)<atraso);
}

void combinaDuplas(){               //Função para combinar duplas

    Jogador swap;

        //Organiza em ordem decrescente

        for(int k=0; k<4; k++){
            for(int i=1; i<4; i++){
             if(players[i].nivel > players[i-1].nivel){
              swap = players[i-1];
              players[i-1] = players[i];
              players[i] = swap;
            }
        }
    }
}

int main()
{
    int player = 0;

            //INTEGRAÇÃO COM O USUÁRIO

    cout << "Welcome to Matchmarking!" << endl << endl;

    cout << "You'll guide by 3 steps. Register, Double Training and Double View." << endl << endl;
    cout << "Let's start!";
    sleep(5);
    system("cls");
    cout << "Step 1 - Register." << endl << endl;

    /*_______________________________________________*/


    for(int i=0; i<4; i++){               //Entrada de NIVEL e NOME dos jogadores

        cout << "Enter the name's " << player+1 << " player." << endl;
        cin >> players[i].nome;
        cout << "Enter the level of " << player+1 << " player." << endl;
        cin >> players[i].nivel;
        player++;
    }
            //INTEGRAÇÃO COM O USUÁRIO

    system("cls");                         //Limpa a tela
    cout << "Step 2 - Double Training." << endl << endl;
    cout << "Computing data " << endl;
    cout << "Loading: [";
    combinaDuplas();

    for(int i=0; i<10; i++){                //Desenha traços de carregamento
        cout << "=";
        sleep(1);                           //Aguarda 1 segundo
    }
    cout << "] 100%" << endl << endl;

    cout << "Data Analyzed.";

    sleep(3);                               //Aguarda 3 segundos

    system("cls");                          //Limpa tela
    cout << "Step 3 - Double View." << endl << endl;
    cout << "The doubles are: " << endl << endl;

    /*_______________________________________________*/

            //Exibição dos grupos

    cout << "Double A" << endl;
    cout << players[0].nome << "\t\t(" << players[0].nivel << ")" << endl;
    cout << players[3].nome << "\t\t(" << players[3].nivel << ")" << endl;
    sleep(2);                                                           //Aguarda 2 segundos
    cout << "Total level: " << players[0].nivel + players[3].nivel;     //Soma total
    cout << endl << endl;

    cout << "Double B" << endl;
    cout << players[1].nome << "\t\t(" << players[1].nivel << ")" << endl;
    cout << players[2].nome << "\t\t(" << players[2].nivel << ")" << endl;
    sleep(2);                                                           //Aguarda 2 segundos
    cout << "Total level: " << players[1].nivel + players[2].nivel;     //Soma total
    cout << endl << endl;

    return 0;
}
