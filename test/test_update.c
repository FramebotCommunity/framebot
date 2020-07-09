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

char *_str();

/*update*/
User *_user_(int index);
Video *_video_(int index);
VideoNote *_videonote_(int index);
Voice *_voice_(int index);
Sticker *_sticker_(int index);
Update *_update_(int index);
Message *_message_(int u, int index);
PhotoSize *_photosize_(int index);
Chat *_chat_(int index);
Audio *_audio_(int index);
Document *_document_(int index);
Animation *_animation_(int index);
Game *_game_(int index);
MessageEntity *_messageentity_(int index);
Contact *_contact_(int index);
Location *_location_(int index);
Venue *_venue_(int index);
Poll *_poll_(int index);
PassportData *_passportdata_(int index);
Invoice *_invoice_(int index);
SuccessfulPayment *_successfulpayment_(int index);
InlineKeyboardButton *_inlinekeyboardbutton_(int index);
InlineKeyboardMarkup *_inlinekeyboardmarkup_(int index);
Dice *_dice_(int index);



ChatPhoto *_chatphoto_(int index);
ChatPermissions *_chatpermissions_(int index);
BotCommand *_botcommand_(int index);
MaskPosition *_maskposition_(int index);
StickerSet *_sticker_set_(int index);
PollOption *_polloption_(int index);
PollAnswer *_pollanswer_(int index);
PassportFile *_passporfile_(int index);
EncryptedCredentials *_encryptedcredentials_(int index);
EncryptedPassportElement *_encryptedpassportelement_(int index);
ShippingAddress *_shippingaddress_(int index);
OrderInfo *_orderinfo_(int index);
ShippingQuery *_shippingquery_(int index);
PreCheckoutQuery *_precheckoutquery_(int index);
CallbackGame *_callbackgame_(int index);
LoginUrl *_login_url_(int index);
InlineQuery *_inlinequery_(int index);
ChosenInlineResult *_choseninlineresult_(int index);
CallbackQuery *_callbackquery_(int index);
ChatMember *_chatmember_(int index);
File *_file_(int index);
UserProfilePhotos *_userprofilephotos_(int index);



char *_str(){
	char *p = calloc(1, 30);
	strcpy(p, "test update");
	return p;
}



User *_user_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;

	User *user = calloc(1, sizeof(User));
		user->id = 20;
		user->is_bot = ON;
		user->first_name = _str();
		user->last_name = _str();
		user->username = _str();
		user->language_code = _str();
		user->can_join_groups = ON;
		user->can_read_all_group_messages = ON;
		user->supports_inline_queries = ON;
		user->next = _user_(index);

	return user;
}


ChatPhoto *_chatphoto_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;

	ChatPhoto *chatphoto = calloc(1, sizeof(ChatPhoto));
		chatphoto->small_file_id = _str();
		chatphoto->small_file_unique_id = _str();
		chatphoto->big_file_id = _str();
		chatphoto->big_file_unique_id = _str();

	return chatphoto;
}



PhotoSize *_photosize_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	PhotoSize *photosize = calloc(1, sizeof(PhotoSize));
		photosize->file_id = _str();
		photosize->file_unique_id = _str();
		photosize->width = 10;
		photosize->height = 10;
		photosize->file_size = 10;
		photosize->next = _photosize_(index);

	return photosize;
}


ChatPermissions *_chatpermissions_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	ChatPermissions *chatpermissions = calloc(1, sizeof(ChatPermissions));
		chatpermissions->can_send_messages = ON;
		chatpermissions->can_send_media_messages = ON;
		chatpermissions->can_send_polls = ON;
		chatpermissions->can_send_other_messages = ON;
		chatpermissions->can_add_web_page_previews = ON;
		chatpermissions->can_change_info = ON;
		chatpermissions->can_invite_users = ON;
		chatpermissions->can_pin_messages = ON;

		return chatpermissions;
}


Chat *_chat_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Chat *chat = calloc(1, sizeof(Chat));
		chat->id = 10;
		chat->type = _str();
		chat->title = _str();
		chat->username = _str();
		chat->first_name = _str();
		chat->last_name = _str();
		chat->photo = _chatphoto_(1);
		chat->description = _str();
		chat->invite_link = _str();
		chat->pinned_message = _message_(0, 101);
		chat->slow_mode_delay = 10;
		chat->sticker_set_name = _str();
		chat->can_set_sticker_set = ON;

		return chat;
}



MessageEntity *_messageentity_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	MessageEntity *messageentity = calloc(1, sizeof(MessageEntity));

		messageentity->type = _str();
		messageentity->offset = 10;
		messageentity->length = 10;
		messageentity->url = _str();
		messageentity->user = _user_(1);
		messageentity->language = _str();
		messageentity->next = _messageentity_(index);

	return messageentity;
}




BotCommand *_botcommand_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	BotCommand *botcommand = calloc(1, sizeof(BotCommand));
		botcommand->command = _str();
		botcommand->description = _str();
		botcommand->next = _botcommand_(index);

		return botcommand;
}


Audio *_audio_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Audio *audio = calloc(1, sizeof(Audio));
		audio->file_id = _str();
		audio->file_unique_id = _str();
		audio->duration = 10;
		audio->performer = _str();
		audio->title = _str();
		audio->mime_type = _str();
		audio->file_size = 10;
		audio->thumb = _photosize_(1);

		return audio;
}

Document *_document_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Document *document = calloc(1, sizeof(Document));
		document->file_id = _str();
		document->file_unique_id = _str();
		document->thumb = _photosize_(1);
		document->file_name = _str();
		document->mime_type = _str();
		document->file_size = 10;

	return document;
}

Animation *_animation_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Animation *animation = calloc(1, sizeof(Animation));
		animation->file_id = _str();
		animation->file_unique_id = _str();
		animation->width = 10;
		animation->heigth = 10;
		animation->duration = 10;
		animation->thumb = _photosize_(1);
		animation->file_name = _str();
		animation->mime_type = _str();
		animation->file_size = 10;

	return animation;
}



Game *_game_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Game *game = calloc(1, sizeof(Game));
		game->title = _str();
		game->description = _str();
		game->photo = _photosize_(3);//Array
		game->text = _str();
		game->text_entities = _messageentity_(3);//Array
		game->animation = _animation_(1);

	return game;
}


MaskPosition *_maskposition_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	MaskPosition *maskposition = calloc(1, sizeof(MaskPosition));
		maskposition->point = _str();
		maskposition->x_shift = 800;
		maskposition->y_shift = 800;
		maskposition->scale = 800;

		return maskposition;
}


Sticker *_sticker_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;

	Sticker *sticker = calloc(1, sizeof(Sticker));
		sticker->file_id = _str();
		sticker->file_unique_id = _str();
		sticker->width = 10;
		sticker->height = 10;
		sticker->is_animated = ON;
		sticker->thumb = _photosize_(1);
		sticker->emoji = _str();
		sticker->set_name = _str();
		sticker->mask_position = _maskposition_(1);
		sticker->file_size = 10;
		sticker->next = _sticker_(index);

	return sticker;
}


StickerSet *_sticker_set_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	StickerSet *sticker_set = calloc(1, sizeof(StickerSet));
		sticker_set->name = _str();
		sticker_set->title = _str();
		sticker_set->is_animated = ON;
		sticker_set->contains_masks = ON;
		sticker_set->stickers = _sticker_(3);
		sticker_set->thumb = _photosize_(1);

	return sticker_set;
}


Video *_video_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Video *video = calloc(1, sizeof(Video));
		video->file_id = _str();
		video->file_unique_id = _str();
		video->width = 10;
		video->height = 10;
		video->duration = 10;
		video->thumb = _photosize_(1);
		video->mime_type = _str();
		video->file_size = 10;

	return video;
}



VideoNote *_videonote_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	VideoNote *video_note = calloc(1, sizeof(VideoNote));
		video_note->file_id = _str();
		video_note->file_unique_id = _str();
		video_note->length = 10;
		video_note->duration = 10;
		video_note->thumb = _photosize_(1);
		video_note->file_size = 10;

		return video_note;
}


Voice *_voice_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Voice *voice = calloc(1, sizeof(Voice));
		voice->file_id = _str();
		voice->file_unique_id = _str();
		voice->duration = 10;
		voice->mime_type = _str();
		voice->file_size = 10;

		return voice;
}



Contact *_contact_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Contact *contact = calloc(1, sizeof(Contact));
		contact->phone_number = _str();
		contact->first_name = _str();
		contact->last_name = _str();
		contact->user_id = 10;
		contact->vcard = _str();

	return contact;
}

Location *_location_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Location *location = calloc(1, sizeof(Location));
		location->latitude = 800;
		location->longitude = 800;

	return location;
}



Venue *_venue_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Venue *venue = calloc(1, sizeof(Venue));
		venue->location = _location_(1);
		venue->title = _str();
		venue->address = _str();
		venue->foursquare_id = _str();
		venue->foursquare_type = _str();

	return venue;
}



PollOption *_polloption_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	PollOption *polloption = calloc(1, sizeof(PollOption));

	polloption->text = _str();
	polloption->voter_count = 10;
	polloption->next = _polloption_(index);

	return polloption;
}

PollAnswer *_pollanswer_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	PollAnswer *poll_answer = calloc(1, sizeof(PollAnswer));
		poll_answer->poll_id = _str();
		poll_answer->user = _user_(1);
		poll_answer->option_ids = 10;


	return poll_answer;
}


Poll *_poll_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Poll *poll = calloc(1, sizeof(Poll));
		poll->id = _str();
		poll->question = _str();
		poll->options = _polloption_(3);
		poll->total_voter_count = 10;
		poll->is_closed = ON;
		poll->is_anonymous = ON;
		poll->type = _str();
		poll->allows_multiple_answers = ON;
		poll->correct_option_id = 10;

		return poll;
}



Dice *_dice_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Dice *dice = calloc(1, sizeof(Dice));
		dice->value = 10;
	
	return dice;
}



PassportFile *_passporfile_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	PassportFile *passporfile = calloc(1, sizeof(PassportFile));
		passporfile->file_id = _str();
		passporfile->file_unique_id = _str();
		passporfile->file_size = 10;
		passporfile->file_date = 10;


	return passporfile;
}



EncryptedCredentials *_encryptedcredentials_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	EncryptedCredentials *credentials = calloc(1, sizeof(EncryptedCredentials));
		credentials->data = _str();
		credentials->hash = _str();
		credentials->secret = _str();

		return credentials;
}


EncryptedPassportElement *_encryptedpassportelement_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	EncryptedPassportElement *encryptedpassportelement = calloc(1, sizeof(EncryptedPassportElement));
		encryptedpassportelement->type = _str();
		encryptedpassportelement->data = _str();
		encryptedpassportelement->phone_number = _str();
		encryptedpassportelement->email = _str();
		encryptedpassportelement->files = _passporfile_(1);
		encryptedpassportelement->front_side = _passporfile_(1);
		encryptedpassportelement->reverse_side = _passporfile_(1);
		encryptedpassportelement->selfie = _passporfile_(1);
		encryptedpassportelement->translation = _passporfile_(1);
		encryptedpassportelement->hash = _str();

		return encryptedpassportelement;
}


PassportData *_passportdata_(int index){
	if(index == 0)
		return NULL;

	/* metodo não esta feito */
	return NULL;

	index = index - 1;
	
	PassportData *passportdata = calloc(1, sizeof(PassportData));
		passportdata->data = _encryptedpassportelement_(4);
		passportdata->credentials = _encryptedcredentials_(1);

		return passportdata;
}


Invoice *_invoice_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	Invoice *invoice = calloc(1, sizeof(Invoice));
		invoice->title = _str();
		invoice->description = _str();
		invoice->start_parameter = _str();
		invoice->currency = _str();
		invoice->total_amount = 10;

	return invoice;
}



ShippingAddress *_shippingaddress_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	ShippingAddress *shippingaddress = calloc(1, sizeof(ShippingAddress));
		shippingaddress->country_code = _str();
		shippingaddress->state = _str();
		shippingaddress->city = _str();
		shippingaddress->street_line1 = _str();
		shippingaddress->street_line2 = _str();
		shippingaddress->post_code = _str();

	return shippingaddress;
}



OrderInfo *_orderinfo_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	OrderInfo *orderinfo = calloc(1, sizeof(OrderInfo));
		orderinfo->name = _str();
		orderinfo->phone_number = _str();
		orderinfo->email = _str();
		orderinfo->shipping_address = _shippingaddress_(1);

	return orderinfo;
}



SuccessfulPayment *_successfulpayment_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	SuccessfulPayment *successfulpayment = calloc(1, sizeof(SuccessfulPayment));
		successfulpayment->currency = _str();
		successfulpayment->total_amount = 10;
		successfulpayment->invoice_payload = _str();
		successfulpayment->shipping_option_id = _str();
		successfulpayment->order_info = _orderinfo_(1);
		successfulpayment->telegram_payment_charge_id = _str();
		successfulpayment->provider_payment_charge_id = _str();

		return successfulpayment;
}



ShippingQuery *_shippingquery_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	ShippingQuery *shipping_query = calloc(1, sizeof(ShippingQuery));
		shipping_query->id = _str();
		shipping_query->from = _user_(1);
		shipping_query->invoice_payload = _str();
		shipping_query->shipping_address = _shippingaddress_(1);

	return shipping_query;
}



PreCheckoutQuery *_precheckoutquery_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	PreCheckoutQuery *pre_checkout_query = calloc(1, sizeof(PreCheckoutQuery));
		pre_checkout_query->id = _str();
		pre_checkout_query->from = _user_(1);
		pre_checkout_query->currency = _str();
		pre_checkout_query->total_amount = 10;
		pre_checkout_query->invoice_payload = _str();
		pre_checkout_query->shipping_option_id = _str();
		pre_checkout_query->order_info = _orderinfo_(1);

	return pre_checkout_query;
}



CallbackGame *_callbackgame_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	CallbackGame *callbackgame = calloc(1, sizeof(CallbackGame));
		callbackgame->user_id = 10;
		callbackgame->score = 10;
		callbackgame->force = ON;
		callbackgame->disable_edit_message = ON;
		callbackgame->chat_id = 10;
		callbackgame->message_id = 10;
		callbackgame->inline_message_id = _str();

	return callbackgame;
}

LoginUrl *_login_url_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	LoginUrl *login_url = calloc(1, sizeof(LoginUrl));
		login_url->url = _str();
		login_url->forward_text = _str();
		login_url->bot_username = _str();
		login_url->request_write_access = ON;

		return login_url;
}


InlineKeyboardButton *_inlinekeyboardbutton_(int index){

	if(index == 0)
		return NULL;

	index = index - 1;

	InlineKeyboardButton *inlinekeyboardbutton = calloc(1, sizeof(InlineKeyboardButton));
		inlinekeyboardbutton->text = _str();
		inlinekeyboardbutton->url = _str();
		inlinekeyboardbutton->login_url = _login_url_(1);
		inlinekeyboardbutton->callback_data = _str();
		inlinekeyboardbutton->switch_inline_query = _str();
		inlinekeyboardbutton->switch_inline_query_current_chat = _str();
		inlinekeyboardbutton->callback = _callbackgame_(1);
		inlinekeyboardbutton->pay = ON;
		inlinekeyboardbutton->next = _inlinekeyboardbutton_(index);

	return inlinekeyboardbutton;
}




InlineKeyboardMarkup *_inlinekeyboardmarkup_(int index){
	int i = 0;

	if(index == 0)
		return NULL;

	/* metodo nao feito */
	return NULL;

	index = index - 1;

	InlineKeyboardMarkup *inlinekeyboardmarkup = calloc(1, sizeof(InlineKeyboardMarkup));
	inlinekeyboardmarkup->inline_keyboard = calloc(7, sizeof(InlineKeyboardButton *));
		inlinekeyboardmarkup->inline_keyboard[6] = NULL;
		for (; i < 6; ++i){
			inlinekeyboardmarkup->inline_keyboard[i] = _inlinekeyboardbutton_(4);
		}

	return inlinekeyboardmarkup;
}



Message *_message_(int u, int index){ 

	if(index == 0)
		return NULL;

	index = index - 1;



	Message *message = calloc(1, sizeof(Message));

		message->message_id = 10;
		message->from = index == 100 ? NULL : _user_(1);
		message->date = 10;
		message->chat = index == 100 ? NULL : _chat_(1);
		message->forward_from = index == 100 ? NULL : _user_(1);
		message->forward_from_chat = index == 100 ? NULL : _chat_(1);
		message->forward_from_message_id = 10;
		message->forward_signature = index == 100 ? NULL : _str();
		message->forward_sender_name = index == 100 ? NULL : _str();
		message->forward_date = 10;
		message->reply_to_message = index == 100 ? NULL : _message_(0, 101);
		message->edit_date = 10;
		message->media_group_id = index == 100 ? NULL : _str();
		message->author_signature = index == 100 ? NULL : _str();
		message->text = index == 100 ? NULL : _str();
		message->entities = index == 100 ? NULL : _messageentity_(3);//Array
		message->caption_entities = index == 100 ? NULL : _messageentity_(3);//Array
		message->audio = index == 100 ? NULL : _audio_(1);
		message->document = index == 100 ? NULL : _document_(1);
		message->animation = index == 100 ? NULL : _animation_(1);
		message->game = index == 100 ? NULL : _game_(1);
		message->photo = index == 100 ? NULL : _photosize_(3);//Array
		message->sticker = index == 100 ? NULL : _sticker_(1);
		message->video = index == 100 ? NULL : _video_(1);
		message->voice = index == 100 ? NULL : _voice_(1);
		message->video_note = index == 100 ? NULL : _videonote_(1);
		message->caption = index == 100 ? NULL : _str();
		message->contact = index == 100 ? NULL : _contact_(1);
		message->location = index == 100 ? NULL : _location_(1);
		message->venue = index == 100 ? NULL : _venue_(1);
		message->poll = index == 100 ? NULL : _poll_(1);
		message->dice = index == 100 ? NULL : _dice_(1);
		message->new_chat_members = index == 100 ? NULL : _user_(3);
		message->left_chat_member = index == 100 ? NULL : _user_(1);
		message->new_chat_title = index == 100 ? NULL : _str();
		message->new_chat_photo = index == 100 ? NULL : _photosize_(3);//Array
		message->delete_chat_photo = ON;
		message->group_chat_created = ON;
		message->supergroup_chat_created = ON;
		message->channel_chat_created = ON;
		message->migrate_to_chat_id = 10;
		message->migrate_from_chat_id = 10;
		message->pinned_message = index == 100 ? NULL : _message_(0, 101);
		message->invoice = index == 100 ? NULL : _invoice_(1);
		message->successful_payment = index == 100 ? NULL : _successfulpayment_(1);
		message->connected_website = index == 100 ? NULL : _str();
		message->passport_data = index == 100 ? NULL : _passportdata_(1);
		message->reply_markup = index == 100 ? NULL : _inlinekeyboardmarkup_(1);
		message->next = index == 100 ? NULL : _message_(0, index);

	return message;
}


InlineQuery *_inlinequery_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	InlineQuery *inlinequery = calloc(1, sizeof(InlineQuery));
		inlinequery->id = _str();
		inlinequery->from = _user_(1);
		inlinequery->location = _location_(1);
		inlinequery->query = _str();
		inlinequery->offset = _str();

	return inlinequery;
}


ChosenInlineResult *_choseninlineresult_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	ChosenInlineResult *choseninlineresult = calloc(1, sizeof(ChosenInlineResult));
	choseninlineresult->result_id = _str();
	choseninlineresult->from = _user_(1);
	choseninlineresult->location = _location_(1);
	choseninlineresult->inline_message_id = _str();
	choseninlineresult->query = _str();

	return choseninlineresult;
}



CallbackQuery *_callbackquery_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	CallbackQuery *callbackquery = calloc(1, sizeof(CallbackQuery));
	callbackquery->id = _str();
	callbackquery->from = _user_(1);
	callbackquery->message = _message_(0, 101);
	callbackquery->inline_message_id = _str();
	callbackquery->chat_instance = _str();
	callbackquery->data = _str();
	callbackquery->game_short_name = _str();

	return callbackquery;
}


Update *_update_(int index){

	if(index == 0)
		return NULL;

	index = index - 1;

	Update *update = calloc(1, sizeof(Update));
	update->update_id = 10;
	update->message = _message_(0, 4);
	update->edited_message = _message_(0, 1);
	update->channel_post = _message_(0, 1);
	update->edited_channel_post = _message_(0, 1);
	update->inline_query = _inlinequery_(1);
	update->chosen_inline_result = _choseninlineresult_(1);
	update->callback_query = _callbackquery_(1);
	update->shipping_query = _shippingquery_(1);
	update->pre_checkout_query = _precheckoutquery_(1);
	update->poll = _poll_(1);
	update->poll_answer = _pollanswer_(1);

	update->next = _update_(index);

	return update;
}


ChatMember *_chatmember_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;

	ChatMember *chatmember = calloc(1, sizeof(ChatMember));
		chatmember->user = _user_(1);
		chatmember->status = _str();
		chatmember->custom_title = _str();
		chatmember->until_date = 10;
		chatmember->can_be_edited = ON;
		chatmember->can_post_messages = ON;
		chatmember->can_edit_messages = ON;
		chatmember->can_delete_messages = ON;
		chatmember->can_restrict_members = ON;
		chatmember->can_promote_members = ON;
		chatmember->can_change_info = ON;
		chatmember->can_invite_users = ON;
		chatmember->can_pin_messages = ON;
		chatmember->is_member = ON;
		chatmember->can_send_messages = ON;
		chatmember->can_send_media_messages = ON;
		chatmember->can_send_polls = ON;
		chatmember->can_send_other_messages = ON;
		chatmember->can_add_web_page_previews = ON;

		chatmember->next = _chatmember_(index);

		return chatmember;
}



File *_file_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	File *file = calloc(1, sizeof(File));
	file->file_id = _str();
	file->file_unique_id = _str();
	file->file_size = 10;
	file->file_path = _str();

	return file;
}


UserProfilePhotos *_userprofilephotos_(int index){
	if(index == 0)
		return NULL;

	index = index - 1;
	
	UserProfilePhotos *userprofilephotos = calloc(1, sizeof(UserProfilePhotos));
	int i = 0;

	userprofilephotos->total_count = 7;
	userprofilephotos->photos = calloc(7, sizeof(UserProfilePhotos *));


	for(; i < 7; ++i) {
		userprofilephotos->photos[i] = _photosize_(4);
	}


	return userprofilephotos;
}


int main(int argc, char **argv){

	Update *update = _update_(4);

	list_update_free(update);






	ChatPhoto *object1 =_chatphoto_(5);
	chat_photo_free(object1);
	
	ChatPermissions *object2 =_chatpermissions_(5);
	chat_permissions_free(object2);
	
	BotCommand *object3 =_botcommand_(5);
	bot_command_free(object3);
	
	MaskPosition *object4 =_maskposition_(5);
	mask_position_free(object4);
	
	StickerSet *object5 =_sticker_set_(5);
	sticker_set_free(object5);
	
	PollOption *object6 =_polloption_(5);
	poll_option_free(object6);
	
	PollAnswer *object7 =_pollanswer_(5);
	poll_answer_free(object7);
	
	//PassportFile *object8 =_passporfile_(5);
	//passport_file_free(object8);
	
	//EncryptedCredentials *object9 =_encryptedcredentials_(5);
	//encrypted_credentials_free(object9);
	
	//EncryptedPassportElement *object10 =_encryptedpassportelement_(5);
	//encrypted_passport_element_free(object10);
	
	ShippingAddress *object11 =_shippingaddress_(5);
	shipping_address_free(object11);
	
	OrderInfo *object12 =_orderinfo_(5);
	order_info_free(object12);
	
	ShippingQuery *object13 =_shippingquery_(5);
	shipping_query_free(object13);
	
	PreCheckoutQuery *object14=_precheckoutquery_(5);
	pre_checkout_query_free(object14);
	
	CallbackGame *object15 =_callbackgame_(5);
	callback_game_free(object15);
	
	//LoginUrl *object16 =_login_url_(5);
	//login_url_free(object16);
	
	InlineQuery *object17 =_inlinequery_(5);
	inline_query_free(object17);
	
	ChosenInlineResult *object18 =_choseninlineresult_(5);
	chosen_inline_result_free(object18);
	
	CallbackQuery *object19 =_callbackquery_(5);
	callback_query_free(object19);
	
	ChatMember *object20 =_chatmember_(5);
	ChatMember *cmnext = NULL;
	while(object20){
		cmnext = object20->next;
		chat_member_free(object20);
		object20 = cmnext;
	}	

	File *object21 =_file_(5);
	file_free(object21);
	
	UserProfilePhotos *object22 =_userprofilephotos_(5);
	user_profile_photos_free(object22);

	return 0;
}
