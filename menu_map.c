#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* map(char *array, int array_length, char (*f) (char)){
  char* mapped_array = (char*)(malloc(array_length*sizeof(char)));

  for(int i = 0; i < array_length; i++){
    mapped_array[i] = f(array[i]);
  }
  return mapped_array;
}

char my_get(char c){
  char s;
  
  s = fgetc(stdin);
  return  s;
}

char cprt(char c){
  if (c >= 0x20 && c <= 0x7E){
    printf("%c\n", c);
  }
  else
  {
    printf(".\n");
  }
  return c;
}

char encrypt(char c){
  if (c >= 0x20 && c <= 0x7E){
    return c + 1;
  }
  return c;
}


char decrypt(char c){
  if (c >= 0x20 && c <= 0x7E){
    return c - 1;
  }
  return c;
}

char xprt(char c){
  if (c >= 0x20 && c <= 0x7E){
    printf("%c in hexadecimal = %x\n", c, c);
  }
  return c;
}

struct fun_desc {
  char *name;
  char (*fun)(char);
};


int main(int argc, char **argv){


    struct fun_desc menu[] = { { "my_get", my_get }, { "cprt", cprt }, { "encrypt", encrypt }, { "decrypt", decrypt }, { "xprt", xprt }, { NULL, NULL } };

    char carray[5] = "";
    char *ptr_carray = carray;

    char str[50];
    int first = 1;
    while (first || fgets(str, sizeof(str), stdin) != NULL) {
    
        if(first == 0){

            if(strlen(str) != 2 || !isdigit(str[0])){

                printf("Not within bounds\n");
                break;
            }
            
            int x = atoi(str);

            if(x >= 0 && x <= 4){
                printf("Within bounds \n");
                ptr_carray = map(ptr_carray, 5, menu[x].fun);
            }
            else{
            printf("Not within bounds\n");
            break;
            }
        }
        first = 0;
        printf("Select operation from the following menu:\n");
        for (int i = 0; i < sizeof(menu) / sizeof(menu[0]) - 1; i++) {
            printf("%d) %s\n", i , menu[i].name);
        }

    }



}
