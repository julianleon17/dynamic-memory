#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// GLOBAL
typedef struct Node {
  int number;
  struct Node *next;
} NODE;

int size = 0;
NODE *start = NULL, *current;


/*================
 *    FUNCTIONS
 *================*/

// Node creation function
NODE *createNode( int number ) {

  NODE * newNode;

  newNode = malloc( sizeof( NODE ) );
  newNode->next = NULL;
  newNode->number = number;

  return newNode;
}


// This function indicates if the get argument is number or not
bool isNumber( char number[] ) {

  int stringSize = strlen( number );

  for ( int i=0; i<stringSize; i++ ) {

    if ( !(number[i] >= 48 && number[i] <= 57) ) {
      return false;
    }
  }
  return true;
}


// Add a new item to the list
void addNewNode() {

  char number[20], string[20];
  bool goOn, firstNumber = true;
  int num;

  printf( "\t\t Debes ingresar al menos un dato\n" );
  printf( "\t\t ( 'exit' para finalizar )\n\n\n\n" );

  do{
    if ( firstNumber ){
	  printf( "Ingresa el primer numero :" );
	  firstNumber = false;
    } else {
      printf( "Ingresa el siguiente numero :" );
    }
    scanf( "%s", number );

    if ( isNumber( number ) ) {
      num = atoi( number );

      if ( num != 00 ) {
        if ( start == NULL ) {
          start = createNode( num );
        } else {
          current = start;

          while( current->next != NULL ) {
            current = current->next;
          }

          current->next = createNode( num );
          size++;
        }
        goOn = true;
      } else {
        goOn = false;
      }
    } else {

      // Capitalizing on the whole word
      for ( int i=0; number[i] != strlen(number) ; i++ ) {
        string[i] = toupper( number[i] );
      }

      // Compare if the user enters the word EXIT
      if ( strcmp(string, "EXIT") == 0 ) {
        printf("\nComing Out...\n");
        goOn = false;
      } else {
        printf( "El dato introducido no es un numero!\n" );
        goOn = true;
      }
    }
  } while( goOn );

  system( "cls" );
  current = start;
}


// Show list with all elements
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


// Pincipal function
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