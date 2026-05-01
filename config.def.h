/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nobody"; // use "nobody" for arch

// Choose a design for DWM_LOGO_PATCH
#define DESIGN_LOCK 0
#define DESIGN_HEART 1
#define DESIGN_LOGO_DWM 100
#define DESIGN_LOGO_FLEXYCON 101
#define DESIGN_EMOJI_SMILE 200
#define ACTIVE_DESIGN DESIGN_HEART

static const char *colorname[NUMCOLS] = {
	#if DWM_LOGO_PATCH && !BLUR_PIXELATED_SCREEN_PATCH
	[BACKGROUND]    = "#32302F",    /* after initialization */
    #if ACTIVE_DESIGN == DESIGN_HEART
	[INIT]          = "#CC241D",    /* after initialization */
	[INPUT]         = "#458588",    /* during input */
	[FAILED]        = "#D79921",    /* wrong password */
    #elif ACTIVE_DESIGN == DESIGN_EMOJI_SMILE
	[INIT]          = "#D79921",
	[INPUT]         = "#458588",
	[FAILED]        = "#CC241D",
    #else
	[INIT]          = "#458588",
	[INPUT]         = "#D79921",
	[FAILED]        = "#CC241D",
	#endif // ACTIVE_DESIGN
	#endif // DWM_LOGO_PATCH
	#if CAPSCOLOR_PATCH
	[CAPS]          = "#B16286",    /* CapsLock on */
	#endif // CAPSCOLOR_PATCH
	#if PAMAUTH_PATCH
	[PAM]           = "#9400D3",    /* waiting for PAM */
	#endif // PAMAUTH_PATCH
	#if KEYPRESS_FEEDBACK_PATCH
	[BLOCKS]        = "#ffffff",    /* key feedback block */
	#endif // KEYPRESS_FEEDBACK_PATCH
};

#if MESSAGE_PATCH || COLOR_MESSAGE_PATCH
/* default message */
static const char * message = "Suckless: Software that sucks less.";

/* text color */
static const char * text_color = "#ffffff";

/* text size (must be a valid size) */
static const char * font_name = "6x10";
#endif // MESSAGE_PATCH | COLOR_MESSAGE_PATCH

#if BACKGROUND_IMAGE_PATCH
/* Background image path, should be available to the user above */
static const char * background_image = "";
#endif // BACKGROUND_IMAGE_PATCH

#if DWM_LOGO_PATCH
#if ACTIVE_DESIGN == DESIGN_LOCK
/* insert grid pattern with scale 1:1 */
static const int logosize   = 50;
/* grid width and height for right center alignment */
static const int logow      = 13;
static const int logoh      = 15;

static XRectangle rectangles[] = {
   /* x   y   w   h */
   {  4,  0,  5,  2 },
   {  3,  1,  2,  2 },
   {  8,  1,  2,  2 },
   {  2,  2,  2,  4 },
   {  9,  2,  2,  4 },
   {  1,  6, 11,  3 },
   {  0,  7,  6,  7 },
   {  1, 12, 11,  3 },
   {  7,  7,  6,  7 },
};
#elif ACTIVE_DESIGN == DESIGN_HEART
static const int logosize   = 50;
static const int logow      = 14;
static const int logoh      = 13;

static XRectangle rectangles[] = {
    /* x   y   w   h */
    {  0,  2, 15,  4 },
    {  1,  1,  6,  1 },
    {  2,  0,  4,  1 },
    {  1,  6, 13,  1 },
    {  2,  7, 11,  1 },
    {  3,  8,  9,  1 },
    {  4,  9,  7,  1 },
    {  5, 10,  5,  1 },
    {  6, 11,  3,  1 },
    {  7, 12,  1,  1 },
    {  8,  1,  6,  1 },
    {  9,  0,  4,  1 },
};
#elif ACTIVE_DESIGN == DESIGN_LOGO_DWM
static const int logosize   = 90;
static const int logow      = 12;
static const int logoh      = 6;

static XRectangle rectangles[] = {
   /* x   y   w   h */
   {  0,  3,  1,  3 },
   {  1,  3,  2,  1 },
   {  0,  5,  8,  1 },
   {  3,  0,  1,  5 },
   {  5,  3,  1,  2 },
   {  7,  3,  1,  2 },
   {  8,  3,  4,  1 },
   {  9,  4,  1,  2 },
   { 11,  4,  1,  2 },
};
#elif ACTIVE_DESIGN == DESIGN_LOGO_FLEXYCON
static const int logosize   = 60;
static const int logow      = 10;
static const int logoh      = 10;

static XRectangle rectangles[] = {
    /* x   y   w   h */
    {  0,  0,  6,  1 },
    {  0,  9,  4,  1 },
    {  1,  0,  1,  9 },
    {  2,  5,  3,  1 },
    {  4,  4,  1,  3 },
    {  7,  6,  1,  4 },
    {  7,  6,  3,  1 },
    {  7,  9,  3,  1 },
};
#elif ACTIVE_DESIGN == DESIGN_EMOJI_SMILE
static const int logosize   = 45;
static const int logow      = 14;
static const int logoh      = 14;

static XRectangle rectangles[] = {
    /* x   y   w   h */
    {  3,  0,  8,  1 },
    {  1,  1, 12,  3 },
    {  0,  3,  3,  8 },
    { 11,  3,  3,  8 },
    {  5,  4,  4,  2 },
    {  3,  6,  8,  3 },
    {  4,  9,  6,  1 },
    {  1, 10,  3,  3 },
    { 10, 10,  3,  3 },
    {  3, 11,  8,  3 },
};
#endif // ACTIVE_DESIGN
#endif // DWM_LOGO_PATCH

#if XRESOURCES_PATCH
/*
 * Xresources preferences to load at startup
 */
ResourcePref resources[] = {
		#if DWM_LOGO_PATCH && !BLUR_PIXELATED_SCREEN_PATCH
		{ "background",   STRING,  &colorname[BACKGROUND] },
		#endif //DWM_LOGO_PATCH
		#if BACKGROUND_IMAGE_PATCH
		{ "bg_image",     STRING,  &background_image },
		#endif // BACKGROUND_IMAGE_PATCH
		{ "locked",       STRING,  &colorname[INIT] },
		{ "input",        STRING,  &colorname[INPUT] },
		{ "failed",       STRING,  &colorname[FAILED] },
		#if CAPSCOLOR_PATCH
		{ "capslock",     STRING,  &colorname[CAPS] },
		#endif // CAPSCOLOR_PATCH
		#if PAMAUTH_PATCH
		{ "pamauth",      STRING,  &colorname[PAM] },
		#endif // PAMAUTH_PATCH
		#if MESSAGE_PATCH || COLOR_MESSAGE_PATCH
		{ "message",      STRING,  &message },
		{ "text_color",   STRING,  &text_color },
		{ "font_name",    STRING,  &font_name },
		#endif // MESSAGE_PATCH | COLOR_MESSAGE_PATCH
};
#endif // XRESOURCES_PATCH

#if ALPHA_PATCH
/* lock screen opacity */
static const float alpha = 0.9;
#endif // ALPHA_PATCH

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;

#if AUTO_TIMEOUT_PATCH
/* length of time (seconds) until */
static const int timeoffset = 60 * 15;

/* should [command] be run only once? */
static const int runonce = 1;

/* command to be run after [time] has passed */
/* TODO: write a script that will check if the user wants to shutdown
on inactivity or not, and act accordingly. */
static const char *command = "doas poweroff";
#endif // AUTO_TIMEOUT_PATCH

#if FAILURE_COMMAND_PATCH
/* number of failed password attempts until failcommand is executed.
   Set to 0 to disable */
static const int failcount = 6;

/* command to be executed after [failcount] failed password attempts */
static const char *failcommand = "shutdown";
#endif // FAILURE_COMMAND_PATCH

#if SECRET_PASSWORD_PATCH
static const secretpass scom[] = {
	/* Password             command */
	{ "shutdown",           "doas poweroff"},
};
#endif // SECRET_PASSWORD_PATCH

#if BLUR_PIXELATED_SCREEN_PATCH
/* Enable blur */
#define BLUR
/* Set blur radius */
static const int blurRadius = 5;
/* Enable Pixelation */
//#define PIXELATION
/* Set pixelation radius */
static const int pixelSize = 10;
#endif // BLUR_PIXELATED_SCREEN_PATCH

#if CONTROLCLEAR_PATCH
/* allow control key to trigger fail on clear */
static const int controlkeyclear = 1;
#endif // CONTROLCLEAR_PATCH

#if DPMS_PATCH
/* time in seconds before the monitor shuts down */
static int monitortime = 60;

#if VISUAL_UNLOCK_PATCH
/* time in seconds before the monitor shuts down, if visual_unlock is enabled */
static const int monitortime_vu = 0;
#endif // VISUAL_UNLOCK_PATCH
#endif // DPMS_PATCH

#if KEYPRESS_FEEDBACK_PATCH
static short int blocks_enabled = 1; // 0 = don't show blocks
static const int blocks_width = 0; // 0 = full width
static const int blocks_height = 16;

// position
static const int blocks_x = 0;
static const int blocks_y = 0;

// Number of blocks
static const int blocks_count = 10;
#endif // KEYPRESS_FEEDBACK_PATCH

#if PAMAUTH_PATCH
/* PAM service that's used for authentication */
static const char* pam_service = "login";
#endif // PAMAUTH_PATCH

#if QUICKCANCEL_PATCH
/* time in seconds to cancel lock with mouse movement */
static const int timetocancel = 4;
#endif // QUICKCANCEL_PATCH
