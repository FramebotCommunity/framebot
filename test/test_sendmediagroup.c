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
char **filename = NULL;
Message *result = NULL;

char * media = "[{\"type\":\"photo\",\"media\":\"attach://photo_1\"},{\"type\":\"photo\",\"media\":\"attach://photo_2\"}]";

int _media_group(){

	printf(WHITE "Send mediagroup ... \n");


	printf(WHITE "Send chat_id ........." COLOR_RESET);
	fflush(stdout);
	result = send_media_group_chat(_bot, chat_id, media, filename, ON, 0);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf("=========\n");
		if(error)
			printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send chat_id u........" COLOR_RESET);
	fflush(stdout);
	result = send_media_group_chat(_bot, chat_id, media, filename, ON, 28024);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		if(error)
			printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	return 0;
}

int main(int argc, char *argv[]){

	if(argc < 5){
		fprintf(stderr, "sendmediagroup <token> <username> <path photo> <path photo2>");
		exit(-1);
	}

	_bot = framebot_init(argv[1]);
	if(!_bot){
		fprintf(stderr, "ERROR authentic");
		exit(-1);
	}

	filename = calloc(sizeof(char *), 3);

	filename[0] = argv[3];
	filename[1] = argv[4];
	filename[2] = NULL;
	username = argv[2];


	Framebot *update = NULL;

	update = get_updates(_bot, update, 0, 0, 0, "message");

	while(update->up_message){
		if(strcmp(update->up_message->message->from->username, argv[2]) == 0){
			valid_username = 1;
			chat_id = update->up_message->message->from->id;
			_media_group();
			break;
		}
	}

	if(valid_username == 0)
		printf("Username not found");

	return 0;
}
