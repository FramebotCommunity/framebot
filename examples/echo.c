#include <stdio.h>
#include <framebot/framebot.h>

int main (int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./echo BOT_TOKEN\n");
        exit(-1);
    }

    int64_t last_offset = 0;
    Bot *echo;
    Update *update;
    Update *message, *temp;

    echo = framebot_init(argv[1]);


    update = get_updates(echo, last_offset, 100, 0, NULL);
    message = get_type_updates(MESSAGE, &update);
    temp = message;

    while (temp) {
        if (temp->message) {
            if (send_message_chat (echo, temp->message->from->id, temp->message->text, RAW, 0, ON, temp->message->message_id, NULL)) {
                printf("Sended: \"%s\" to %s!\n", temp->message->text, temp->message->from->username);
            }
        }

        last_offset = temp->update_id + 1;
        temp = temp->next;
    }

    list_update_free(update);
    list_update_free(message);
    return 0;
}
