/**
 * MIT License
 * Copyright (c) 2016 - 2018 Giancarlo Rocha & Ródgger Bruno
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef FRAMEBOT_H
#define FRAMEBOT_H

/* Functions API */

#define API_GETME "getMe"

#define API_GETUPDATES "getUpdates\
?offset=%ld\
&limit=%d\
&timeout=%ld\
&allowed_updates=%s"

#define API_SENDMESSAGE "sendMessage\
?chat_id=%s\
&text=%s\
&parse_mode=%s\
&disable_web_page_preview=%s\
&disable_notification=%s\
&reply_to_message_id=%ld\
&reply_markup=%s"

#define API_getChat "getChat\
?chat_id=%s"

#define API_setChatTitle "setChatTitle\
?chat_id=%s\
&title=%s"

#define API_getChatMember "getChatMember\
?chat_id=%s\
&user_id=%ld"

#define API_setChatDescription "setChatDescription\
?chat_id=%s\
&description=%s"

#define API_getChatMemberCount "getChatMemberCount\
?chat_id=%s"

#define API_kickChatMember "kickChatMember\
?chat_id=%s\
&user_id=%ld\
&until_date=%ld"

#define API_restrictChatMember "restrictChatMember\
?chat_id=%s\
&user_id=%ld\
&until_date=%ld\
&can_send_messages=%s\
&can_send_media_messages=%s\
&can_send_other_messages=%s\
&can_add_web_page_previews=%s"

#define API_unbanChatMember "unbanChatMember\
?chat_id=%s\
&user_id=%ld"

#define API_leaveChat "leaveChat\
?chat_id=%s"

#define API_promoteChatMember "promoteChatMember\
?chat_id=%s\
&user_id=%ld\
&can_change_info=%s\
&can_post_messages=%s\
&can_edit_messages=%s\
&can_delete_messages=%s\
&can_invite_users=%s\
&can_restrict_members=%s\
&can_pin_messages=%s\
&can_promote_members=%s"

#define API_exportChatInviteLink "exportChatInviteLink"

#define API_deleteChatPhoto "deleteChatPhoto\
?chat_id=%s"

#define API_getChatAdministrators "getChatAdministrators\
?chat_id=%s"

#define API_pinChatMessage "pinChatMessage\
?chat_id=%s\
&message_id=%ld\
&disable_notification=%s"

#define API_unpinChatMessage "unpinChatMessage\
?chat_id=%s"

#define API_getfile "getfile\
?file_id=%s"

#define API_getUserProfilePhotos "getUserProfilePhotos\
?user_id=%s\
&offset=%ld\
&limit=%ld"

#define API_forwardMessage "forwardMessage\
?chat_id=%s\
&from_chat_id=%s\
&disable_notification=%s\
&message_id=%ld"

#define API_sendLocation "sendLocation\
?chat_id=%s\
&latitude=%f\
&longitude=%f\
&live_period=%ld\
&disable_notification=%s\
&reply_to_message_id=%ld\
&reply_markup=%s"

#define API_sendContact "sendContact\
?chat_id=%s\
&phone_number=%s\
&first_name=%s\
&last_name=%s\
&disable_notification=%s\
&reply_to_message_id=%ld\
&reply_markup=%s"

#define API_sendPoll "sendPoll\
?chat_id=%s\
&question=%s\
&options=%s\
&is_anonymous=%s\
&type=%s\
&allows_multiple_answers=%s\
&correct_option_id=%d\
&is_closed=%s\
&disable_notification=%s\
&reply_to_message_id=%ld\
&reply_markup=%s"

#define API_stopPoll "stopPoll\
?chat_id=%s\
&message_id=%ld\
&reply_markup=%s"

#define API_sendChatAction "sendChatAction\
?chat_id=%s\
&action=%s"

#define API_sendVenue "sendVenue\
?chat_id=%s\
&latitude=%f\
&longitude=%f\
&title=%s\
&address=%s\
&foursquare_id=%s\
&disable_notification=%s\
&reply_to_message_id=%ld\
&reply_markup=%s"

#define API_editMessageLiveLocation "editMessageLiveLocation\
?chat_id=%s\
&message_id=%ld\
&inline_message_id=%s\
&latitude=%f\
&longitude=%f\
&reply_markup=%s"

#define API_stopMessageLiveLocation "stopMessageLiveLocation\
?chat_id=%s\
&message_id=%ld\
&inline_message_id=%s\
&reply_markup=%s"

#define API_editMessageText "editMessageText\
?chat_id=%s\
&message_id=%ld\
&inline_message_id=%s\
&text=%s\
&parse_mode=%s\
&disable_web_page_preview=%d\
&reply_markup=%s"

#define API_editMessageCaption "editMessageCaption\
?chat_id=%s\
&message_id=%ld\
&inline_message_id=%s\
&caption=%s\
&reply_markup=%s"

#define API_editMessageReplyMarkup "editMessageReplyMarkup\
?chat_id=%s\
&message_id=%ld\
&inline_message_id=%s\
&reply_markup=%s"

#define API_deleteMessage "deleteMessage\
?chat_id=%s\
&message_id=%ld"

#define API_setChatStickerSet "setChatStickerSet\
?chat_id=%s\
&sticker_set_name=%s"

#define API_deleteChatStickerSet "deleteChatStickerSet\
?chat_id=%s"

#define API_answerInlineQuery "answerInlineQuery\
?inline_query_id=%s\
&results=%s\
&cache_time=%ld\
&is_personal=%d\
&next_offset=%s\
&switch_pm_text=%s\
&switch_pm_parameter=%s"

#define API_sendInvoice "sendInvoice\
?chat_id=%ld\
&title=%s\
&description=%s\
&payload=%s\
&provider_token=%s\
&start_parameter=%s\
&currency=%s\
&prices=%s\
&provider_data=%s\
&photo_url=%s\
&photo_size=%lu\
&photo_width=%u\
&photo_height%u\
&need_name=%s\
&need_phone_number=%s\
&need_email=%s\
&need_shipping_address=%s\
&send_phone_number_to_provider=%s\
&send_email_to_provider=%s\
&is_flexible=%s\
&disable_notification=%s\
&reply_to_message_id=%ld\
&reply_markup=%s"

#define API_answerShippingQuery "answerShippingQuery\
?shipping_query_id=%s\
&ok=%s\
&shipping_options=%s\
&error_message=%s"

#define API_answerPreCheckoutQuery "answerPreCheckoutQuery\
?pre_checkout_query_id=%s\
&ok=%s\
&error_message=%s"

#define API_sendMediaGroup "sendMediaGroup\
?chat_id=%s\
?media=%s\
?disable_notification=%s\
?reply_to_message_id=%ld"

#define API_setChatAdministratorCustomTitle "setChatAdministratorCustomTitle\
?chat_id=%s\
&user_id=%ld\
&custom_title=%s"

/* analyze parameter API methods */
#define CONVERT_BOOLEAN_STR(p) (p > 0 ? "true" : "false")
#define CONVERT_URL_STRING(p) (p == NULL ? "" : p)
#define LIMIT_UPDATE(p) (p < 1 ? 100 : p)
#define IFILE_LONG(p) (p > 0 ? api_ltoa(p) : NULL)
#define IFILE_INT(p) (p > 0 ? api_itoa(p) : NULL)

#define ffree(p) (p == NULL ? 0 : free(p))

#define fstrlen(p) (p == NULL ? 0 : strlen(p))

#define STRING_NULL(p) (p == NULL ? "null": p)

#define UPDATE_ID_LAST(x, y) (x->update_id > y->update_id ? x->update_id : y->update_id)

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
#include <ctype.h>

#if defined __linux__ || defined __FreeBSD__
#   include <unistd.h>
#   define scpy(a, b, c) strncpy(a, b, c)
#elif _WIN32
#   include <Windows.h>
#   include <io.h>
#   define scpy(a, b, c) strcpy_s(a, c, b)
#else
#   error "Only Windows, Linux and FreeBSD are supported at the moment."
#endif

#ifdef _MSC_VER
//cURL Fix
#pragma comment(lib, "wldap32.lib" )
#pragma comment(lib, "crypt32.lib" )
#pragma comment(lib, "Ws2_32.lib")
#define CURL_STATICLIB
// --//--
#endif

/* type bool */
typedef int32_t bool;
#define true  1
#define false 0

#define ON  1
#define OFF 0

#define MARKDOWN "HTML"
#define HTML     "MARKDOWN"
#define RAW      NULL

#include <curl/curl.h>
#include <jansson.h>

#include <framebot/memory.h>
#include <framebot/objects.h>
#include <framebot/network.h>
#include <framebot/json.h>
#include <framebot/format.h>
#include <framebot/util.h>
#include <framebot/payments.h>


Bot * framebot_init(const char *token);
refjson *generic_method_call (const char *token, char *formats, ...);
Error * show_error();

/** Available methods **/
User * get_me(Bot *bot);
Framebot *get_updates (Bot *bot, Framebot *framebot, int64_t offset, int32_t limit,
            int64_t timeout, char *allowed_updates);

/* sendMessage */
Message * send_message (Bot *bot, char * chat_id, char *text,
            char * parse_mode, bool disable_web_page_preview,
            int disable_notification, int64_t reply_to_message_id,
            char * reply_markup);
Message * send_message_chat (Bot *bot, int64_t chat_id, char *text,
            char * parse_mode, bool disable_web_page_preview,
            int disable_notification, int64_t reply_to_message_id,
            char * reply_markup);

/* ForwardMessage */
Message * forward_message_from (Bot * bot, int64_t chat_id, char * from_chat_id,
        bool disable_notification, int64_t message_id);
Message * forward_message_from_chat (Bot * bot, char * chat_id, int64_t from_chat_id,
        bool disable_notification, int64_t message_id);
Message * forward_message (Bot * bot, char * chat_id, char * from_chat_id,
        bool disable_notification, int64_t message_id);
Message * forward_message_chat (Bot * bot, int64_t chat_id, int64_t from_chat_id,
        bool disable_notification, int64_t message_id);

/* sendphoto */
Message * send_photo(Bot * bot, char * chat_id, char * filename, char * caption,
        char * parse_mode, bool disable_notification, int64_t reply_to_message_id, char * reply_markup);
Message * send_photo_chat(Bot * bot, int64_t chat_id, char * filename, char * caption,
        char * parse_mode, bool disable_notification, int64_t reply_to_message_id, char * reply_markup);

/* sendaudio */
Message * send_audio(Bot *bot, char * chat_id, char * filename, char * caption,
        char * parse_mode, int32_t duration, char * performer, char * title,
        char * thumb, bool disable_notification, int64_t reply_to_message_id, char * reply_markup);
Message * send_audio_chat(Bot * bot, int64_t chat_id, char * filename, char * caption, 
        char * parse_mode, int32_t duration, char * performer, char * title,
        char * thumb, bool disable_notification, int64_t reply_to_message_id, char * reply_markup);

/* senddocument */
Message * send_document(Bot * bot, char * chat_id, char * filename, char * thumb, char * caption,
        char * parse_mode, bool disable_notification, int64_t reply_to_message_id,  char * reply_markup);
Message * send_document_chat(Bot * bot, int64_t chat_id, char * filename, char *thumb, char * caption,
        char * parse_mode, bool disable_notification, int64_t reply_to_message_id,  char * reply_markup);

/* sendvideo */
Message * send_video(Bot * bot, char * chat_id, char * video, int32_t duration, int32_t width,
        int32_t height, char * thumb, char * caption, char * parse_mode, bool supports_streaming, 
        bool disable_notification, int64_t reply_to_message_id, char * reply_markup);
Message * send_video_chat(Bot * bot, int64_t chat_id, char * video, int32_t duration, int32_t width,
        int32_t height, char * thumb, char * caption, char * parse_mode, bool supports_streaming,
        bool disable_notification, int64_t reply_to_message_id, char * reply_markup);

/* sendvoice */
Message * send_voice(Bot *bot, char * chat_id, char * filename, char * caption, char * parse_mode,
        int32_t duration,  bool disable_notification, int64_t reply_to_message_id,  char * reply_markup);
Message * send_voice_chat(Bot *bot, int64_t chat_id, char * filename, char * caption, char * parse_mode,
        int32_t duration, bool disable_notification, int64_t reply_to_message_id,  char * reply_markup);

/* sendvideonote */
Message * send_video_note(Bot * bot, char * chat_id, char * filename, int32_t duration,
        int32_t length, bool disable_notification, int64_t reply_to_message_id,  char * reply_markup);

Message * send_video_note_chat(Bot * bot, int64_t chat_id, char * filename, int32_t duration,
        int32_t length, bool disable_notification, int64_t reply_to_message_id, char * reply_markup);

// sendMediaGroup

/* sendlocation */
Message * send_location (Bot * bot, char * chat_id, float latitude,
            float longitude, int32_t live_period, bool disable_notification,
            int64_t reply_to_message_id, char * reply_markup);
Message * send_location_chat (Bot * bot, int64_t chat_id, float latitude, float logitude,
            int32_t live_period, bool disable_notification, int64_t reply_to_message_id,
            char * reply_markup);

/* editMessageLiveLocation */
Message * edit_message_live_location(Bot * bot, char * chat_id, int64_t message_id,
        char * inline_message_id, float latitude, float longitude, char * reply_markup);
Message * edit_message_live_location_chat(Bot * bot, int64_t chat_id, int64_t message_id,
        char * inline_message_id, float latitude, float longitude, char * reply_markup);

/* stopMessageLiveLocation */
Message * stop_message_live_location(Bot * bot, char * chat_id, int64_t message_id,
            char * inline_message_id, char * reply_markup);
Message * stop_message_live_location_chat(Bot * bot, int64_t chat_id, int64_t message_id,
            char * inline_message_id, char * reply_markup);

/* sendVenue */
Message * send_venue(Bot * bot, char * chat_id, float latitude, float longitude,
            char * title, char * address, char * foursquare_id, bool disable_notification,
            int64_t reply_to_message_id, char * reply_markup);
Message * send_venue_chat(Bot * bot, int64_t chat_id, float latitude, float longitude,
            char * title, char * address, char * foursquare_id, bool disable_notification,
            int64_t reply_to_message_id, char * reply_markup);

/* sendContact */
Message * send_contact(Bot * bot, char * chat_id, char * phone_number, char * first_name,
            char * last_name, bool disable_notification, int64_t reply_to_message_id, char * reply_markup);
Message * send_contact_chat(Bot * bot, int64_t chat_id, char * phone_number, char * first_name,
            char * last_name, bool disable_notification, int64_t reply_to_message_id, char * reply_markup);

/* sendPoll */
Message * send_poll(Bot *bot, char *chat_id, char *question, char *options, bool is_anonymous,
                    char *type, bool allows_multiple_answers, int32_t correct_option_id, bool is_closed,
                    bool disable_notification, int32_t reply_to_message_id, char *reply_markup);
Message * send_poll_chat(Bot *bot, int64_t chat_id, char *question, char *options, bool is_anonymous,
                    char *type, bool allows_multiple_answers, int32_t correct_option_id, bool is_closed,
                    bool disable_notification, int32_t reply_to_message_id, char *reply_markup);


/* sendChatAction */
int send_chat_action(Bot * bot, char * chat_id, char * action);
int send_chat_action_chat(Bot * bot, int64_t chat_id, char * action);

/* getUserProfilePhotos */
UserProfilePhotos * get_user_profile_photos(Bot * bot, char *user_id,
    int64_t offset, int64_t limit);
UserProfilePhotos * get_user_profile_photos_chat(Bot * bot, int64_t user_id,
    int64_t offset, int64_t limit);

/* getFile */
File * get_file(Bot * bot, const char * file_id);
int file_download(Bot * bot, File * ofile, char *dir);

/* kickChatMember */
bool kick_chat_member (Bot *bot, char *chat_id, int64_t user_id, int64_t until_date);
bool kick_chat_member_chat (Bot *bot, int64_t chat_id, int64_t user_id, int64_t until_date);

/* unbanChatMember */
bool unban_chat_member (Bot *bot, char *chat_id, int64_t user_id);
bool unban_chat_member_chat (Bot *bot, int64_t chat_id, int64_t user_id);

/* restrictChatMember */
bool restrict_chat_member (Bot *bot, char *chat_id, int64_t user_id,
        int64_t until_date, bool can_send_messages,
        bool can_send_media_messages, bool can_send_other_messages,
        bool can_add_web_page_previews);
bool restrict_chat_member_chat (Bot *bot, int64_t chat_id, int64_t user_id,
        int64_t until_date, bool can_send_messages,
        bool can_send_media_messages, bool can_send_other_messages,
        bool can_add_web_page_previews);

/* promoteChatMember */
bool promote_chat_member (Bot *bot, char *chat_id, int64_t user_id, bool can_change_info,
        bool can_post_messages, bool can_edit_messages, bool can_delete_messages,
        bool can_invite_users, bool can_restrict_members, bool can_pin_messages,
        bool can_promote_members);
bool promote_chat_member_chat (Bot *bot, int64_t chat_id, int64_t user_id, bool can_change_info,
        bool can_post_messages, bool can_edit_messages, bool can_delete_messages,
        bool can_invite_users, bool can_restrict_members, bool can_pin_messages,
        bool can_promote_members);

/* exportChatInviteLink */
char *export_chat_invite_link (Bot *bot, char *chat_id);
char *export_chat_invite_link_chat (Bot *bot, int64_t chat_id);

/* setChatPhoto */
int set_chat_photo(Bot *bot, char * chat_id, char *filename);
int set_chat_photo_chat(Bot *bot, int64_t chat_id, char *filename);

/* deleteChatPhoto */
int delete_chat_photo(Bot *bot, char *chat_id);
int delete_chat_photo_chat(Bot *bot, int64_t chat_id);

/* setChatTitle */
int set_chat_title (Bot *bot, char *chat_id, char *title);
int set_chat_title_chat (Bot *bot, int64_t chat_id, char *title);

/* setChatDescription */
bool set_chat_description (Bot *bot, char *chat_id, char *description, bool disable_notification);
bool set_chat_description_chat (Bot *bot, int64_t chat_id, char *description, bool disable_notification);

/* pinChatMessage */
bool pin_chat_message (Bot *bot, char * chat_id, int64_t message_id, bool disable_notification);
bool pin_chat_message_chat(Bot *bot, int64_t chat_id, int64_t message_id, bool disable_notification);

/* unpinChatMessage */
bool unpin_chat_message(Bot *bot, char *chat_id);
bool unpin_chat_message_chat(Bot *bot, int64_t chat_id);

/* leaveChat */
bool leave_chat (Bot *bot, char *chat_id);
bool leave_chat_chat (Bot *bot, int64_t chat_id);

/* getChat */
Chat *get_chat(Bot *bot, char *chat_id);
Chat *get_chat_chat(Bot *bot, int64_t chat_id);

/* getChatAdministrators */
ChatMember *get_chat_administrators (Bot *bot, char *chat_id);
ChatMember *get_chat_administrators_chat(Bot *bot, int64_t chat_id);

/* getChatMembersCount */
uint32_t get_chat_members_count (Bot *bot, char *chat_id);
uint32_t get_chat_members_count_chat (Bot *bot, int64_t chat_id);

/* getChatMember */
ChatMember *get_chat_member(Bot *bot, char *chat_id, int64_t user_id);
ChatMember *get_chat_member_chat(Bot *bot, int64_t chat_id, int64_t user_id);

/** Updating messages **/
Message *edit_message_text(Bot *bot, char *chat_id, int64_t message_id,
    char *inline_message_id, char *text, char * parse_mode,
    bool disable_web_page_preview, char *reply_markup);
Message *edit_message_text_chat(Bot *bot, int64_t chat_id, int64_t message_id,
    char *inline_message_id, char *text, char * parse_mode,
    bool disable_web_page_preview, char *reply_markup);

/* editMessageText */
Message *edit_message_caption(Bot *bot, char *chat_id,
    int64_t message_id, char *inline_message_id, char *caption,
    char * parse_mode, char *reply_markup);
Message *edit_message_caption_chat(Bot *bot, int64_t chat_id,
    int64_t message_id, char *inline_message_id, char *caption,
    char * parse_mode, char *reply_markup);

/* editMessageCaption */
Message *edit_message_reply_markup(Bot *bot, char *chat_id, int64_t message_id,
        char *inline_message_id, char *reply_markup);
Message *edit_message_reply_markup_chat(Bot *bot, int64_t chat_id, int64_t message_id,
        char *inline_message_id, char *reply_markup);

/* delete message */
bool delete_message(Bot *bot, char *chat_id, int64_t message_id);
bool delete_message_chat(Bot *bot, int64_t chat_id, int64_t message_id);

bool answer_inline_query( Bot *bot, char *inline_query_id, char *results, int64_t cache_time, bool is_personal,
    char *next_offset, char *switch_pm_text, char *switch_pm_parameter);

void set_notification(bool disable_notification);
bool get_notification();

Message * send_media_group(Bot *bot, char * chat_id, char * media, char **filename, bool disable_notification, int64_t reply_to_message_id);
Message * send_media_group_chat(Bot *bot, int64_t chat_id, char * media, char **filename, bool disable_notification, int64_t reply_to_message_id);

Poll * stop_poll(Bot *bot, char *chat_id, int64_t message_id, char *reply_markup);
Poll * stop_poll_chat(Bot *bot, int64_t chat_id, int64_t message_id, char *reply_markup);

bool set_chat_administrator_custom_title(Bot *bot, char *chat_id, int64_t user_id, char *custom_title);
bool set_chat_administrator_custom_title_chat(Bot *bot, int64_t schat_id, int64_t user_id, char *custom_title);

Message * send_animation_chat(Bot *bot, int64_t chat_id, char *animation, int32_t duration, int32_t width,
                    int32_t heigth, char *thumb, char * caption, char * parse_mode, bool disable_notification,
                    int32_t reply_to_message_id, char * reply_markup );
Message * send_animation(Bot *bot, char * chat_id, char *animation, int32_t duration, int32_t width,
                    int32_t heigth, char *thumb, char * caption, char * parse_mode, bool disable_notification,
                    int32_t reply_to_message_id, char * reply_markup );

#endif
