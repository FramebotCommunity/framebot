#include <framebot/util.h>

int api_tg_exist(const char *filename){
    FILE *b;

    b = fopen(filename, "r");


    if(b){
        fclose(b);
        return 1;
    }

    return 0;
}


bool verify_count_field(char **filename, char **field){
	int field_id = 0, file_id = 0, id = 0;

	while(filename != NULL){
		if(filename[id] != NULL) {
			file_id++;
		}
		else{
			break;
		}

		id++;
	}

	id = 0;

	while(field != NULL){

		if(field[id] != NULL) {
			field_id++;
		}
		else{
			break;
		}
		id++;
	}

	if(file_id != field_id){
		return false;
	}


	return true;
}

