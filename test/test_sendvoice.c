#include <framebot/framebot.h>

#define BOLD         "\033[1m"
#define COLOR_RESET  "\033[0m"
#define BLACK  "\033[22;30m"
#define RED    "\033[22;31m"
#define GREEN  "\033[22;32m"
#define BROWN  "\033[22;33m"
#define BLUE   "\033[22;34m"
#define MAGENTA "\033[22;35m"
#define CYAN   "\033[22;36m"
#define GRAY   "\033[22;37m"
#define DARK_GRAY "\033[01;30m"
#define LIGHT_RED "\033[01;31m"
#define LIGHT_GREEN "\033[01;32m"
#define YELLOW "\033[01;33m"
#define LIGHT_BLUE "\033[01;34m"
#define LIGHT_MAGENTA "\033[01;35m"
#define LIGHT_CYAN "\033[01;36m"
#define WHITE "\033[01;37m"

Bot * _bot = NULL;
char *username = NULL;
int64_t chat_id = 0;
int valid_username = 0;
char *filename = NULL;
Message *result = NULL;

int _voice(){

	printf(WHITE "Send voice ... \n");

	printf(WHITE "Send chat_id ........." COLOR_RESET);
	fflush(stdout);
	result = send_voice_chat(_bot, chat_id, filename, NULL, RAW,
            0, ON, 0, NULL);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send username ........." COLOR_RESET);
	fflush(stdout);
	result = send_voice_chat(_bot, chat_id, filename, NULL, RAW,
            0, ON, 0, NULL);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send caption ........." COLOR_RESET);
	fflush(stdout);
	result = send_voice_chat(_bot, chat_id, filename, "caption", RAW,
            0, ON, 0, NULL);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send duration ........." COLOR_RESET);
	fflush(stdout);
	result = send_voice_chat(_bot, chat_id, filename, "duration", RAW,
            10, ON, 0, NULL);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send disable_notification ........." COLOR_RESET);
	fflush(stdout);
	result = send_voice_chat(_bot, chat_id, filename, "disable_notification", RAW,
            0, ON, 0, NULL);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send reply_to_message_id ........." COLOR_RESET);
	fflush(stdout);
	Message * forward = send_voice_chat(_bot, chat_id, filename, "reply_to_message_id", RAW,
            0, ON, result->message_id, NULL);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(forward);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(BLUE"unit parameter successful\n"  COLOR_RESET);

	return 0;
}


int main(int argc, char *argv[]){

	if(argc < 4){
		fprintf(stderr, "sendphoto <token> <username> <path audio>");
		exit(-1);
	}

	_bot = framebot_init(argv[1]);
	if(!_bot){
		fprintf(stderr, "ERROR authentic");
		exit(-1);
	}

	filename = argv[3];
	username = argv[2];

	Update *update = NULL, *root_update = NULL;

	root_update = get_updates(_bot, 0, 0, 0, "message");
	update = root_update;

	while(update){
		if(update->message && strcmp(update->message->from->username, argv[2]) == 0){
			valid_username = 1;
			chat_id = update->message->from->id;
			_voice();
			break;
		}

		update = update->next;
	}

	list_update_free(root_update);

	if(valid_username == 0)
		printf("Username not found");

	return 0;
}
