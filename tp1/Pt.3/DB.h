/**
 * @file DBheader.h
 * @author Jose Santos (a18605@alunos.ipca.pt)
 * @brief header file to manage core data of the link list program
 * @version 0.1
 * @date 2023-03-19
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include <stdbool.h>
#define TAM 50

/*Estrutura dos gestores*/
typedef struct AdminUser // lista de usuário a manter o programa, irá talvez ser melhorado
                         // conforme o que o professor preferir
{
    char name[15], password[12];
    int codename;
    // char *name, *password;
    struct AdminUser *next;
} AdminUser_t;
/*Fim estrutura dos gestores*/

typedef struct Clientes // lista de usuário a manter o programa, irá talvez ser melhorado
                         // conforme o que o professor preferir
{
    char name[15], password[12];
    int ID;
    // char *name, *password;
    struct Clientes *next;
} Clientes_t;

/*Estruturas para os meios*/
typedef struct Meios // lista de usuário a manter o programa, irá talvez ser melhorado
                     // conforme o que o professor preferir
{
    int CodeID, RegistoAlugado;
    char type[50];
    float batery, autonomia;
    struct Meios *next;
} Meios_t;

typedef struct registo2
{
    char vertice[TAM];
    float peso;
    struct registo2 *next;
} Adjacentes_t;

typedef struct registo1 // Main acesso gestao vertices.
{
    char vertice[TAM]; // array de vertices
    Meios_t *meios;
    struct registo1 *next; // ficar next1 para n confundir com o main
    Adjacentes_t *adjacents;
} Grafo_t;
/*Fim de estruturacao dos meios..*/

/*helper functions list*/
void LoopMeiosProcedure(Meios_t *head, Grafo_t *headGraph);
void LoopAdminsProcedure(AdminUser_t *head);
void LoopClientesProcedure(Clientes_t *head);
/*end of helper list*/


/*Lista invocar funcoes dos gestores*/
AdminUser_t *EnterUser(AdminUser_t **head, char name[], char password[], int codename);
void printList_Admins(AdminUser_t *head);
void ConfirmLogIN(AdminUser_t *head, char name[], int codename);
void serialize_Admins(AdminUser_t *head); // write name data to file
AdminUser_t *deserialize_Admins(AdminUser_t **head); // Read data from file, in dev.
void FreeMem_Admins(AdminUser_t **head);
int existAdmin(AdminUser_t *head, int codename);
AdminUser_t *deleteUser(AdminUser_t *head, int codename);
void ModUser(AdminUser_t **head, int codename, char *name, char *password);
/*Fim lista funcoes dos gestores*/

/*Lista invocar funcoes dos clientes*/
Clientes_t *EnterCliente(Clientes_t **head, char name[], char password[], int ID); 
void printList_Clientes(Clientes_t *head); 
int existCliente(Clientes_t *head, int ID);
void ConfirmLoginCliente(Clientes_t *head, char name[], int ID);
void serialize_Clientes(Clientes_t *head);
Clientes_t *deserialize_Cliente(Clientes_t **head);
Clientes_t *deleteClientes(Clientes_t *head, int ID);
void ModCliente(Clientes_t **head, int ID, char *name, char *password);
void FreeMem_Clientes(Clientes_t **head);
/*Fim Lista funcoes dos clientes*/

/*Lista invocar das funcoes para implementacao dos meios*/
Meios_t *insertMeio(Meios_t **head, char type[], int CodeID, float batery, float autonomia);
void printList_Meios(Meios_t *head);
void serialize_Meios(Meios_t *head);        // write name data to file
Meios_t *deserialize_Meios(Meios_t **head); // Read data from file, in dev.
void FreeMem_Meios(Meios_t **head);
Meios_t *deleteMeio(Meios_t *head, int CodeID);
void ModMeio(Meios_t **head, char *type, int CodeID, float batery, float autonomia);
void RegistoAluguelMeio(Meios_t *head, int CodeID);
void PrintListaMeiosAlugados(Meios_t *head);
Meios_t *PrintOrdemDecrescente(Meios_t *head);
/*Graph implementation section,(WIP), will need to checkout what which one does what..*/
int existeVertice(Grafo_t *head, char V[]);
int criarVertice(Grafo_t **head, char V[]);
// int criarEdge(Grafo_t *head, char vOrigem[], char vDestino[], float peso);
//Experimental implementation, adding function as procedure:
void criarEdge(Grafo_t **head, char vOrigem[], char vDestino[], float peso);//upstream, dk if it will have issues though >P
void listarEdges(Grafo_t *head, char vertice[]);
//WIP, research on adding meios functions..
void inserirMeio_GeoCode(Grafo_t *head, char geocodigo[], int CodeID);
void listMeios_Geocode(Grafo_t *head, char geocodigo[]);
/*Fim lista, invocar meios*/

