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
int valid_username = 0;
char *filename = NULL;
char *thumb = NULL;
char *user_group = NULL;
Message *result = NULL;
Message *result1 = NULL;

/*
send_document(Bot * bot
char * chat_id
char * filename
char * thumb
char * caption,
char * parse_mode
bool disable_notification
int64_t reply_to_message_id
char * reply_markup)
*/

void _time(){
	#ifdef _WIN32
		custom_sleep(1000);
	#else
		custom_sleep(1);
	#endif
}


int _document(){

	printf(WHITE "Send document ... \n");

	printf(WHITE "Send chat_id ........." COLOR_RESET);
	fflush(stdout);
	result = send_document_chat(_bot /*bot*/, chat_id/*chat_id*/, filename/*file*/, NULL/*thumb*/,
					NULL/*caption*/, RAW/*parse_mode*/, OFF/*disable_notification*/,
					0/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	_time();

	printf(WHITE "Send username ........." COLOR_RESET);
	fflush(stdout);
	result = send_document(_bot /*bot*/, user_group/*chat_id*/, filename/*file*/, NULL/*thumb*/,
					"username"/*caption*/, RAW/*parse_mode*/, OFF/*disable_notification*/,
					0/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	_time();

	printf(WHITE "Send thumb ........." COLOR_RESET);
	fflush(stdout);
	result = send_document_chat(_bot /*bot*/, chat_id/*chat_id*/, filename/*file*/, thumb/*thumb*/,
					"thumb"/*caption*/, RAW/*parse_mode*/, OFF/*disable_notification*/,
					0/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(result){
		if(result->document && result->document->thumb)
			printf("thumb yes");
		else if(result->audio && result->audio->thumb)
			printf("thumb yes");
		else
			printf("without thumb ");

		printf(BLUE "OK\n" COLOR_RESET);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	_time();

	printf(WHITE "Send thumb file_id ........." COLOR_RESET);
	fflush(stdout);
	if(result->document && result->document->thumb)
		result1 = send_document_chat(_bot /*bot*/, chat_id/*chat_id*/, filename/*file*/, result->document->thumb->file_id/*thumb*/,
					"thumb file_id"/*caption*/, RAW/*parse_mode*/, OFF/*disable_notification*/,
					0/*reply_to_message_id*/, NULL/*reply_markup*/);
	else if(result->audio && result->audio->thumb)
		result1 = send_document_chat(_bot /*bot*/, chat_id/*chat_id*/, filename/*file*/, result->audio->thumb->file_id/*thumb*/,
					"thumb  audio file_id"/*caption*/, RAW/*parse_mode*/, OFF/*disable_notification*/,
					0/*reply_to_message_id*/, NULL/*reply_markup*/);

	else
		result1 = send_document_chat(_bot /*bot*/, chat_id/*chat_id*/, filename/*file*/, NULL/*thumb*/,
					"thumb without file_id"/*caption*/, RAW/*parse_mode*/, OFF/*disable_notification*/,
					0/*reply_to_message_id*/, NULL/*reply_markup*/);

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

	_time();


	printf(WHITE "Send caption ........." COLOR_RESET);
	fflush(stdout);
	result = send_document_chat(_bot /*bot*/, chat_id/*chat_id*/, filename/*file*/, NULL/*thumb*/,
					"caption"/*caption*/, RAW/*parse_mode*/, OFF/*disable_notification*/,
					0/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	_time();

	printf(WHITE "Send parse_mode ........." COLOR_RESET);
	fflush(stdout);
	result = send_document_chat(_bot /*bot*/, chat_id/*chat_id*/, filename/*file*/, NULL/*thumb*/,
					"parameter parse_mode = MODE_MARKDOWN%0Abold = *bold text*%0Aitalic = _italic text_%0A[inline URL](https://github.com/giancarlopro/framebot)%0A```block_languagepre-formatted fixed-width code block```"/*caption*/, MARKDOWN/*parse_mode*/, OFF/*disable_notification*/,
					0/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	_time();


printf(WHITE "Send disable_notification ........." COLOR_RESET);
	fflush(stdout);
	result = send_document_chat(_bot /*bot*/, chat_id/*chat_id*/, filename/*file*/, NULL/*thumb*/,
					"disable_notification"/*caption*/, RAW/*parse_mode*/, ON/*disable_notification*/,
					0/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	_time();


	printf(WHITE "Send reply_to_message_id ........." COLOR_RESET);
	fflush(stdout);
	Message * forward = send_document_chat(_bot /*bot*/, chat_id/*chat_id*/, filename/*file*/, NULL/*thumb*/,
					NULL/*caption*/, RAW/*parse_mode*/, ON/*disable_notification*/,
					result->message_id/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(forward){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
		message_free(forward);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	return 0;
}

int main(int argc, char *argv[]){

	if(argc < 6){
		fprintf(stderr, "./senddocument <token> <username> @<user group> <path document> <path thumb>");
		exit(-1);
	}

	_bot = framebot_init(argv[1]);
	if(!_bot){
		fprintf(stderr, "ERROR authentic");
		exit(-1);
	}

	username   = argv[2];
	user_group = argv[3];
	filename   = argv[4];
	thumb      = argv[5];


	Update *update = NULL, *root_update = NULL;

	root_update = get_updates(_bot, 0, 0, 0, "message");
	update = root_update;

	while(update){
		if(update->message && strcmp(update->message->from->username, argv[2]) == 0){
			valid_username = 1;
			chat_id = update->message->from->id;
			_document();
			break;
		}
		update = update->next;
	}

	if(valid_username == 0)
		printf("Username not found");

	list_update_free(root_update);
	bot_free(_bot);

	return 0;
}
