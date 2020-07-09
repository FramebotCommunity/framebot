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
char filename_id[100];
char *thumb = NULL;
char *user_group = NULL;
Message *result = NULL;
Message *result1 = NULL;
Message *first = NULL;

/*
send_video_note(
Bot * bot
char * chat_id
char * filename
int32_t duration
int32_t length
char *thumb
bool disable_notification
int64_t reply_to_message_id
char * reply_markup)
*/

int _videonote(){

	printf(WHITE "Send videonote ... \n");

	printf(WHITE "Send chat_id ........." COLOR_RESET);
	fflush(stdout);
	first = send_video_note_chat(_bot, chat_id, filename, 0/*duration*/, 0/*length*/,
				NULL/*thumb*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(first){
		printf(BLUE "OK\n" COLOR_RESET);
		if(first->video_note)
			strcpy(filename_id, first->video_note->file_id);
		else if(first->video)
			strcpy(filename_id, first->video->file_id);
		message_free(first);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send username ........." COLOR_RESET);
	fflush(stdout);
	result = send_video_note(_bot, user_group, filename, 0/*duration*/, 0/*length*/,
				NULL/*thumb*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/, NULL/*reply_markup*/);
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
	result = send_video_note_chat(_bot, chat_id, filename, 30/*duration*/, 0/*length*/,
				NULL/*thumb*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	printf(WHITE "Send length ........." COLOR_RESET);
	fflush(stdout);
	result = send_video_note_chat(_bot, chat_id, filename, 0/*duration*/, 420/*length*/,
				NULL/*thumb*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}


	printf(WHITE "Send thumb ...." COLOR_RESET);
	fflush(stdout);
	result = send_video_note_chat(_bot, chat_id, filename, 0/*duration*/, 320/*length*/,
				thumb/*thumb*/, OFF/*disable_notification*/, 0/*reply_to_message_id*/, NULL/*reply_markup*/);
	if(result){
		if(result->video && result->video->thumb)
			printf("..video thumb yes..");

		else if(result->video_note && result->video_note->thumb)
			printf("..video_note thumb yes..");

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
	result = send_video_note_chat(_bot, chat_id, filename, 0/*duration*/, 0/*length*/,
				NULL/*thumb*/, ON/*disable_notification*/, 0/*reply_to_message_id*/, NULL/*reply_markup*/);
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
	Message *forward = send_video_note_chat(_bot, chat_id, filename, 0/*duration*/, 0/*length*/,
				NULL/*thumb*/, OFF/*disable_notification*/, result->message_id/*reply_to_message_id*/, NULL/*reply_markup*/);
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

	return 0;
}

int main(int argc, char *argv[]){

	if(argc < 4){
		fprintf(stderr, "sendvideonote <token> <username> @<user_group> <path video> <path thumb>");
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
			_videonote();
			break;
		}

		update = update->next;
	}

	list_update_free(root_update);

	if(valid_username == 0)
		printf("Username not found");

	return 0;
}
