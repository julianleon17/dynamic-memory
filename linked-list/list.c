#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// GLOBAL
typedef struct Node {
  int number;
  struct Node *next;
} NODE;

int size = 0;
NODE *start = NULL, *current;


NODE *createNode( int number ) {

  NODE * newNode;

  newNode = malloc( sizeof( NODE ) );
  newNode->next = NULL;
  newNode->number = number;

  return newNode;
}



void addNewNode() {

  int num, goOn;

  do{
    printf( "Ingresa el siguiente numero ( '00' para finalizar  ) :" );
	scanf( "%i", &num );

    if ( num != 00 ) {
      if ( start == NULL ) {
        start = createNode( num );
        size++;
      } else {
        current = start;

        while( current->next != NULL ) {
          current = current->next;
        }
        current->next = createNode( num );
        size++;
      }
      goOn = 1;
    } else {
      goOn = 0;
    }

  } while( goOn != 0 );

  current = start;
}



int showList() {

  system( "cls" );
  printf( "LISTA DE ELEMENTOS\n\n" );

  int i = 0;

  while( current ) {
    printf( "[%i] = %d \n", i, current->number );

	current = current->next;
	i++;
  }
  return( 0 );
}



int main() {

  char options[] = "\n\nOPCIONES\n [1] Crear Nodo\n [2] Listar nodos\n [3] Salir\n";
  int option;

   system( "cls" );

  // Display the options menu
  do{
    printf( "%s", options );
    printf( "Digita una opcion : " );
    scanf( "%i", &option );

    switch( option ) {

      case 1:
        system("cls");
        addNewNode();
      break;

      case 2:
        system("cls");

        if ( size == 0 ) {
          printf("No hay elementos");
        } else {
          showList();
        }
      break;

      case 3:
        printf( "\nHasta la proxima!\n" );
      break;

      default:
        system("cls");
        printf( "Opcion invalida!" );
    }

  } while( option != 3 );

  return 0;
}