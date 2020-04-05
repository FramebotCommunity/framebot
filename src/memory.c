#include <framebot/memory.h>

char * alloc_string(const char * str){

    if (str) {
        size_t sizestr = fstrlen(str) + 1;
        char *nstr = (char *) calloc(1, sizestr);
        if(!nstr)
            return NULL;

        scpy(nstr, str, sizestr);

        return nstr;
    }

    return NULL;
}

char *realloc_string (char *base, char *str) {
    if (!str)
        return base;
    
    char *tmp = (char *) realloc(base, fstrlen(base) + fstrlen(str) + 1);

    if (tmp)
        strcat(tmp, str);

    return tmp;
}

char * found_str_attach(char * str){
    char attach[10] = "attach://", *field = NULL;
    size_t length, id, i = 0, p = 0;

    length = strlen(str);


    if (length < 9)
        return NULL;


    for(id = 0; id < length; id++){
        if(i >= 9){
            if(i == 9){
                field = calloc(1, (length + 2) - id);
            }

            i++;
            field[p] = str[id];
            p++;
        }
        else if(str[id] == attach[i]){
            i++;
        }
        else{
            i = 0;
        }
    }

    if (p == 0)
        return NULL;

    length = strlen(field);
    field[length] = '\0';


    return field;
}


void ffree_array_str(char **str){

    int id = 0;

    if (str == NULL){
        return;
    }

    while(str[id] != NULL){
        ffree(str[id]);
        id++;
    }

    ffree(str);
}

