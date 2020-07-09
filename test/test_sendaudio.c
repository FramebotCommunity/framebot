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
char filename_id[70];
char *thumb = NULL;
char *user_group = NULL;
Message *result = NULL;
Message *result1 = NULL;
Message *first = NULL;


/*
Message * send_audio(Bot *bot,
char * chat_id
char * filename
char * caption
char * parse_mode
int32_t duration
char * performer
char * title
char * thumb
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



int _audio(){

	printf(WHITE "Send audio ... \n");

	printf(WHITE "Send chat_id ......... " COLOR_RESET);
	fflush(stdout);
	first = send_audio_chat(_bot, chat_id, filename,
			NULL, RAW, 0, NULL, NULL, NULL, OFF,
			0, NULL);
	if(first){
		printf(BLUE "OK\n" COLOR_RESET);
		if(first->document)
			strcpy(filename_id, first->document->file_id);
		else if(first->audio)
			strcpy(filename_id, first->audio->file_id);
		else if(first->voice)
			strcpy(filename_id, first->voice->file_id);

	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET,
			error->error_code, error->description);
		exit(-1);
	}

	_time();


	printf(WHITE "Send username ......... " COLOR_RESET);
	fflush(stdout);
	result = send_audio(_bot, user_group, filename_id,
			NULL, RAW, 0,
			NULL, NULL, NULL, OFF,
			0, NULL);
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


	printf(WHITE "Send caption ......... " COLOR_RESET);
	fflush(stdout);
	result = send_audio_chat(_bot, chat_id, filename_id,
			"parameter caption", RAW, 0,
			NULL, NULL, NULL, OFF,
			0, NULL);
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



	printf(WHITE "Send caption (parse_mode) ......... " COLOR_RESET);
	fflush(stdout);
	result = send_audio_chat(_bot, chat_id, filename_id,
			"parameter parse_mode = MODE_MARKDOWN%0Abold = *bold text*%0Aitalic = _italic text_%0A[inline URL](https://github.com/giancarlopro/framebot)%0A```block_languagepre-formatted fixed-width code block```", MARKDOWN, 0,
			NULL, NULL, NULL, OFF,
			0, NULL);
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


	printf(WHITE "Send duration ......... " COLOR_RESET);
	fflush(stdout);
	result = send_audio_chat(_bot, chat_id, filename_id,
			"parameter duration", RAW, 5,
			NULL, NULL, NULL, OFF,
			0, NULL);
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


	printf(WHITE "Send performer ......... " COLOR_RESET);
	fflush(stdout);
	result = send_audio_chat(_bot, chat_id, filename_id,
			NULL, RAW, 5,
			"performer", NULL, NULL, OFF,
			0, NULL);
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


	printf(WHITE "Send title ......... " COLOR_RESET);
	fflush(stdout);
	result = send_audio_chat(_bot, chat_id, filename_id,
			NULL, RAW, 0,
			"performer", "title", NULL, OFF,
			0, NULL);
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

	printf(WHITE "Com thumb ......... " COLOR_RESET);
	fflush(stdout);
	result = send_audio_chat(_bot, chat_id, filename,
			NULL, RAW, 0,
			NULL, NULL, thumb, OFF,
			0, NULL);
	if(result){
		if(result->document && result->document->thumb)
			printf("thumb audio yes.....");
		else if(result->audio && result->audio->thumb)
			printf("thumb document yes.....");
		else
			printf("without thumb..... ");

		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	_time();

	printf(WHITE "Send disable_notification ......... " COLOR_RESET);
	result = send_audio_chat(_bot, chat_id, filename_id,
			"parameter disable_notification", RAW, 0,
			NULL, NULL, NULL, ON,
			0, NULL);
	if(result){
		printf(BLUE "OK\n" COLOR_RESET);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	_time();

	printf(WHITE "Send file_id telegram ......... " COLOR_RESET);
	if(result->voice){
		printf("..voice..");
		result1 = send_voice_chat(_bot, chat_id, result->voice->file_id, "file_id", RAW,
			0, OFF, 0, NULL);
	}
	else if(result->audio){
		printf("..audio..");
		result1 = send_audio_chat(_bot, chat_id, result->audio->file_id,
			"parameter file_id", RAW, 0,
			NULL, NULL, NULL, OFF,
			0, NULL);
	}
	else if(result->document){
		printf("..document..");
		result1 = send_audio_chat(_bot, chat_id, result->document->file_id,
			"parameter file_id", RAW, 0,
			NULL, NULL, NULL, OFF,
			0, NULL);
	}
	if(result1){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(result);
	}
	else{
		Error *error = get_error();
		printf(RED"false\ncode:%d | description:%s\n"COLOR_RESET, error->error_code, error->description);
		exit(-1);
	}

	_time();

	printf(WHITE "Send reply_to_message_id ......... " COLOR_RESET);
	Message * forward = send_audio_chat(_bot, chat_id, filename,
			"parameter disable_notification", RAW, 0,
			NULL, NULL, NULL, OFF,
			result1->message_id, NULL);
	if(forward){
		printf(BLUE "OK\n" COLOR_RESET);
		message_free(forward);
		message_free(result1);
		message_free(first);
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

	if(argc < 5){
		fprintf(stderr, "sendaudio <token> <username> <path audio> <path thumb>");
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
			_audio();
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
