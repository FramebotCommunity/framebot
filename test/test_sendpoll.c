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
char *user_group = NULL;
Message *result = NULL;
Message *result1 = NULL;
char *title = "title poll";
char * options = "[\"1 option\", \"2 option\", \"3 option\"]";

/*
send_poll(
Bot *bot
char *chat_id
char *question
char *options
bool is_anonymous,
char *type
bool allows_multiple_answers
int32_t correct_option_id
bool is_closed,
bool disable_notification
int32_t reply_to_message_id
char *reply_markup
)*/

int _poll(){
	printf(WHITE "Send sendPoll ... \n");

	printf(WHITE "Send chat_id ........." COLOR_RESET);
	fflush(stdout);
	result = send_poll_chat(_bot/*bot*/, chat_id/*chat_id*/, "chat_id"/*question*/,
				options/*options*/, OFF/*is_anonymous*/, NULL/*type*/, OFF/*allows_multiple_answers*/,
				0/*correct_option_id*/, OFF/*is_closed*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/,
				NULL/*char *reply_markup*/);
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
	result = send_poll(_bot/*bot*/, user_group/*chat_id*/, "username"/*question*/,
				options/*options*/, OFF/*is_anonymous*/, NULL/*type*/, OFF/*allows_multiple_answers*/,
				0/*correct_option_id*/, OFF/*is_closed*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/,
				NULL/*char *reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}


	printf(WHITE "Send is_anonymous ........." COLOR_RESET);
	fflush(stdout);
	result = send_poll_chat(_bot/*bot*/, chat_id/*chat_id*/, "is_anonymous"/*question*/,
				options/*options*/, ON/*is_anonymous*/, NULL/*type*/, OFF/*allows_multiple_answers*/,
				0/*correct_option_id*/, OFF/*is_closed*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/,
				NULL/*char *reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}


	printf(WHITE "Send type quiz ........." COLOR_RESET);
	fflush(stdout);
	result = send_poll_chat(_bot/*bot*/, chat_id/*chat_id*/, "type quiz"/*question*/,
				options/*options*/, OFF/*is_anonymous*/, "quiz"/*type*/, OFF/*allows_multiple_answers*/,
				0/*correct_option_id*/, OFF/*is_closed*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/,
				NULL/*char *reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}


	printf(WHITE "Send type regular ........." COLOR_RESET);
	fflush(stdout);
	result = send_poll_chat(_bot/*bot*/, chat_id/*chat_id*/, "type regular"/*question*/,
				options/*options*/, OFF/*is_anonymous*/, "regular"/*type*/, OFF/*allows_multiple_answers*/,
				0/*correct_option_id*/, OFF/*is_closed*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/,
				NULL/*char *reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}


	printf(WHITE "Send allows_multiple_answers ........." COLOR_RESET);
	fflush(stdout);
	result = send_poll_chat(_bot/*bot*/, chat_id/*chat_id*/, "allows_multiple_answers"/*question*/,
				options/*options*/, OFF/*is_anonymous*/, NULL/*type*/, ON/*allows_multiple_answers*/,
				0/*correct_option_id*/, OFF/*is_closed*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/,
				NULL/*char *reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}


	printf(WHITE "Send correct_option_id ........." COLOR_RESET);
	fflush(stdout);
	result = send_poll_chat(_bot/*bot*/, chat_id/*chat_id*/, "correct_option_id"/*question*/,
				options/*options*/, OFF/*is_anonymous*/, "quiz"/*type*/, OFF/*allows_multiple_answers*/,
				2/*correct_option_id*/, OFF/*is_closed*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/,
				NULL/*char *reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send is_closed ........." COLOR_RESET);
	fflush(stdout);
	result = send_poll_chat(_bot/*bot*/, chat_id/*chat_id*/, "is_closed"/*question*/,
				options/*options*/, OFF/*is_anonymous*/, NULL/*type*/, OFF/*allows_multiple_answers*/,
				0/*correct_option_id*/, ON/*is_closed*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/,
				NULL/*char *reply_markup*/);
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
	result = send_poll_chat(_bot/*bot*/, chat_id/*chat_id*/, "disable_notification"/*question*/,
				options/*options*/, OFF/*is_anonymous*/, NULL/*type*/, OFF/*allows_multiple_answers*/,
				0/*correct_option_id*/, OFF/*is_closed*/, ON/*disable_notification*/, 0/*reply_to_message_id*/,
				NULL/*char *reply_markup*/);
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
	result1 = send_poll_chat(_bot/*bot*/, chat_id/*chat_id*/, "reply_to_message_id"/*question*/,
				options/*options*/, OFF/*is_anonymous*/, NULL/*type*/, OFF/*allows_multiple_answers*/,
				0/*correct_option_id*/, OFF/*is_closed*/, OFF/*disable_notification*/, result->message_id/*reply_to_message_id*/,
				NULL/*char *reply_markup*/);
	if(result1){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
		message_free(result1);
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
		fprintf(stderr, "sendphoto <token> <username> @<user_group>");
		exit(-1);
	}

	_bot = framebot_init(argv[1]);
	if(!_bot){
		fprintf(stderr, "ERROR authentic");
		exit(-1);
	}

	username   = argv[2];
	user_group = argv[3];

	Update *update = NULL, *root_update = NULL;

	root_update = get_updates(_bot, 0, 0, 0, "message");
	update = root_update;

	while(update){
		if(update->message && strcmp(update->message->from->username, argv[2]) == 0){
			valid_username = 1;
			chat_id = update->message->from->id;
			_poll();
			break;
		}

		update = update->next;

	}

	list_update_free(root_update);
	bot_free(_bot);

	if(valid_username == 0)
		printf("\nUsername %s not found", argv[2]);


	return 0;
}
