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

#ifdef _WIN32
    #include <Windows.h>
    #define custom_sleep(mili) Sleep(mili)
#else
    #include <unistd.h>
    #define custom_sleep(mili) sleep(mili)
#endif

Bot * _bot = NULL;
char *username = NULL;
int64_t chat_id = 0;
char *user_group;
int valid_username = 0;
char *text = NULL;
Message *result = NULL;

int _message(){
	printf(WHITE "Send sendmessage ... \n");

	printf(WHITE "Send chat_id ........." COLOR_RESET);
	fflush(stdout);
	result = send_message_chat(_bot, chat_id, "parameter chat_id", RAW, 0, 0, 0, NULL);
	if(result){
		printf(CYAN "OK\n" COLOR_RESET);
		message_free(result);
		custom_sleep(2);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send username ........." COLOR_RESET);
	fflush(stdout);
	if(user_group)
		result = send_message(_bot, user_group, "parameter username",  RAW, ON, 0, 0, NULL);
	else
		result = send_message_chat(_bot, chat_id, "without parameter username",  RAW, ON, OFF, 0, NULL);

	if(result){
		printf(CYAN "OK\n" COLOR_RESET);
		message_free(result);
		custom_sleep(2);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send parse_mode HTML ........." COLOR_RESET);
	fflush(stdout);
	result = send_message_chat(_bot, chat_id, "parameter parse_mode = MODE_HTML%0Abold = <b>bold</b>, <strong>bold</strong>%0Aitalic = <i>italic</i>, <em>italic</em>%0Agithub = <a href=\"https://github.com/giancarlopro/framebot\">inline URL</a>",  HTML, ON, OFF, 0, NULL);
	if(result){
		printf(CYAN "OK\n" COLOR_RESET);
		message_free(result);
		custom_sleep(2);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send parse_mode MARKDOWN ........." COLOR_RESET);
	fflush(stdout);
	result = send_message_chat(_bot, chat_id, "parameter parse_mode = MODE_MARKDOWN%0Abold = *bold text*%0Aitalic = _italic text_%0A[inline URL](https://github.com/giancarlopro/framebot)%0A```block_languagepre-formatted fixed-width code block```",  MARKDOWN, ON, OFF, 0, NULL);
	if(result){
		printf(CYAN "OK\n" COLOR_RESET);
		message_free(result);
		custom_sleep(2);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send disable_web_page_preview (not thumb)........." COLOR_RESET);
	fflush(stdout);
	result = send_message_chat(_bot, chat_id, "parameter disable_web_page_preview (not thumb) https://github.com/giancarlopro/framebot",  RAW, ON, OFF, 0, NULL);
	if(result){
		printf(CYAN "OK\n" COLOR_RESET);
		message_free(result);
		custom_sleep(2);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send disable_web_page_preview true........." COLOR_RESET);
	fflush(stdout);
	result = send_message_chat(_bot, chat_id, "parameter disable_web_page_preview https://github.com/giancarlopro/framebot",  RAW, OFF, OFF, 0, NULL);
	if(result){
		printf(CYAN "OK\n" COLOR_RESET);
		message_free(result);
		custom_sleep(2);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send disable_notification ........." COLOR_RESET);
	fflush(stdout);
	result = send_message_chat(_bot, chat_id, "parameter disable_notification",  RAW, ON, ON, 0, NULL);
	if(result){
		printf(CYAN "OK\n" COLOR_RESET);
		custom_sleep(2);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send reply_to_message_id ........." COLOR_RESET);
	fflush(stdout);
	Message * forward = send_message_chat(_bot, chat_id, "parameter reply_to_message_id",  RAW, ON, OFF, result->message_id, NULL);
	if(result){
		printf(CYAN "OK\n" COLOR_RESET);
		message_free(forward);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	return 0;
}

int main(int argc, char *argv[]){

	if(argc < 3){
		fprintf(stderr, "\n./sendmessage <token> <username>\nor\n./sendmessage <token> <username> @<username group>\neach 2 seconds send\n");
		exit(-1);
	}

	if(argc >= 4){
		user_group = argv[3];
	}
	else{
		user_group = NULL;
	}

	_bot = framebot_init(argv[1]);
	if(!_bot){
		fprintf(stderr, "ERROR authentic");
		exit(-1);
	}

	username = argv[2];

	Update *update = NULL, *root_update = NULL;

	root_update = get_updates(_bot, 0, 0, 0, "message");
	update = root_update;

	while(update){
		if(update->message && strcmp(update->message->from->username, argv[2]) == 0){
			valid_username = 1;
			chat_id = update->message->from->id;
			_message();
			break;
		}

		printf("\nuser found: %s\n", update->message->from->username);
		update = update->next;
	}

	list_update_free(root_update);

	if(valid_username == 0)
		printf("\nUsername %s not found", argv[2]);

	return 0;
}
