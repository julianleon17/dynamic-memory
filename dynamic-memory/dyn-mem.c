// CODE ABOUT CRUD IN C WITH DYNAMIC MEMORY
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// GLOBAL
typedef char NAME[100];
typedef char EMAIL[100];
typedef char LASTNAME[100];
typedef int AGE;

typedef struct {
  NAME name;
  EMAIL email;
  LASTNAME lastname;
  AGE age;
} PERSON;

PERSON *list = NULL;
int size = 0;



/*================
 *    FUNCTIONS
 *================*/

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


// Create and Add Person to the List
int addToListOfPeople( NAME name, LASTNAME lastname, EMAIL email, AGE age ) {
    if ( list == NULL ) {
      list = malloc( sizeof( PERSON ) );
    } else {
      list = realloc( list, sizeof( PERSON ) * ( size + 1 ) );
    }

    if ( list ) { // How to validate if "malloc" or "realloc" was success ?

      // Save name of person
      strcpy( list[ size ].name, name );

	  // Save name of person
      strcpy( list[ size ].lastname, lastname );

      // Save email of person
      strcpy( list[ size ].email, email );

      // Save age of person
      list[ size ].age = age;

      size += 1;

      return( 1 );
    }

    return( 0 );
}


// Function that gather data to create new persons
int newPerson() {

  printf( "\n\n \t\tCREAR NUEVA PERSONA \n\n" );

  char goOn;

  NAME readName;
  LASTNAME readLastname;
  EMAIL readEmail;
  AGE readAge;

  do { // Read and Validate Data
    printf( "\n\nIngresa el nombre de la Persona : \n" );
    scanf( "%99s", readName );

    printf( "Ingresa el apellido de la %s : \n", readName );
    scanf( "%99s", readLastname );

    printf( "Ingresa el email de %s : \n", readName );
    scanf( "%99s", readEmail );

    printf( "Ingresa la edad de la Persona : \n" );
    scanf( "%i", &readAge );

    addToListOfPeople( readName, readLastname, readEmail, readAge );

    printf( "\n\nDeseas crear mas personas? [y/n] : " );
    scanf( " %c", &goOn );

    goOn = toupper( goOn );
  } while( goOn != 'N' );

  system("cls");
};

/*( Solve another time )
*/
// Show personal data of each person
// void showPersonalData( int id ) {

  // char comeback;

  // PERSON temporalPerson = list[ id ];

  // system( "cls" );
  // printf( "Information of person with ID [%i]\n\n", id );
  // printf( "Name : %s\n\n", temporalPerson.name );
  // printf( "Lastname : %s\n\n", temporalPerson.lastname );
  // printf( "Email : %s\n\n", temporalPerson.email );
  // printf( "Age : %s", temporalPerson.age );

  // printf( "Name : %s\n\nLastname : %s\n\nEmail : %s\n\nAge : %s\n\n", temporalPerson.name, temporalPerson.lastname, temporalPerson.email, temporalPerson.age );

  // printf( "Back to List [y/n] :" );
  // scanf( "%c", &comeback );

  // comeback = toupper( comeback );

  // if ( comeback == 'Y' ) {
    // goto list;
  // }
// }


// Function that show data of the persons
void printList() {

  int id;
  char watch;
  char idString[20];
  bool goOn;

  printf( "\n\nLISTA DE PERSONAS [%i]\n\n\n", size );
  printf("\n[id] Nombre\t\t  Apellido\t\t  Email\t\t\t  Edad\t\t\n");

  for( int i=0; i<size; i++ ) {
	printf("_________________________________________________________________");
    printf( "\n[%i] %s\t\t  %s\t\t %s\t\t %i\t\t \n", i, list[i].name, list[i].lastname, list[i].email, list[i].age );
  }

  /* ( Solve another time ) 
  printf( "\n\nDo you want to see someone's personal data? [y/n] : " );
  scanf( " %c", &watch );

  watch = toupper( watch );

  if ( watch == 'Y' ) {
    do{
      printf( "\n\nInput ID of person : " );
      scanf( "%s", idString );

      if ( isNumber( idString ) ) {
        id = atoi( idString );

		if ( (id > size) || (id < 0) ) {
			printf( "Invalid ID!\n" );
			goOn = true;
		  } else {
			showPersonalData( id );
			goOn = false;
		  }
	  }
    }while( goOn );
  }

  system( "cls" );
*/
}



int main( int argc, char *argv[] ) {

  int option;
  char options[] = "\n\nOPCIONES\n [1] Ver lista de Personas\n [2] Crear Personas\n [3] Salir\n";

  system("cls");

  // Display the options menu
  do{
    printf( "%s", options );
    printf( "Digita una opcion : " );
    scanf( "%i", &option );

    switch( option ){

      case 1:
        system("cls");

		if ( size != 0 ) {
          list:
          printList();
        }else{
		  printf("No hay elementos");
		}
      break;

      case 2:
        system("cls");
        newPerson();
      break;

      case 3:
        printf( "\nHasta la proxima!\n" );
      break;

      default:
        system("cls");
        printf( "Opcion invalida!" );
    }

  }while( option != 3 );

  free( list );

  return 0;
}