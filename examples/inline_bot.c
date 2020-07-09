#include <framebot/framebot.h>

#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
    #include <Windows.h>
    #define custom_sleep(mili) Sleep(mili)
#else
    #include <unistd.h>
    #define custom_sleep(mili) sleep(mili/1000)
#endif

int main (int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./inline BOT_TOKEN\n");
        exit(-1);
    }

    char *result = alloc_string("[{\"type\":\"sticker\",\"id\":\"1\",\"sticker_file_id\":\"CAADAQADHAADDf4xFY94M8CVYwIeAg\"}]");
    Bot *inbot = framebot_init(argv[1]);
    if(!inbot)
    	return -1;

    Update *queries = get_updates(inbot, 0, 100, 0, "inline_query");

    int64_t last_update = 0;

    while (1) {

        if (queries) {

            while (queries) {
                if (answer_inline_query(inbot, queries->inline_query->id, result, 0, 0, NULL, NULL, NULL)) {
                    printf("Answered %s!\n", queries->inline_query->from->username);
                }

                last_update = queries->update_id;
                queries = queries->next;
            }
        }

        list_update_free(queries);
        queries = get_updates(inbot, last_update, 100, 0, NULL);
    }

    bot_free(inbot);
    free(result);

    return 0;
}