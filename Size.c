#include <stdio.h>
#include <stdlib.h>

int str_len(char *str);

int main(){
    char *str = (char *)malloc(100*sizeof(char));
    scanf("%s",str);
    printf("%d", str_len(str));
    free(str);
    return 0;
}

int str_len(char *str){
    if(str==NULL){
        return 0;
    }
else if(*str=='\0'){
      return 0;
}
else {
   return (str_len(str+1)+1); 

}
    
    return 0;
}
