#include "Main.h"
#include "imgui/imgui.h"
static bool record = false;
static int circle_float = 129;
static int circle_anim = 95;
static int tabs = 0;
static int cps = 1;
static int cps_right = 1;
static float reach_distance = 3.0f;
static bool circle_anim_down = false;
static float color[4] = { 140.0f, 0.f, 255.f, 1.f };
static bool automine = false;
static bool R0 = false;
static bool enable_clicker = false;
static bool left_mouse = false;
static bool right_mouse = false;
static bool interaction = false;
static bool active_reach = false;
static bool sprinting = false;
static bool chestesp = false;
static bool tracers = false;
static bool wallhack = false;
static bool bridge = false;
static bool inventory = false;
static bool steal = false;
static float steal_speed = 1.0f;
static int steal_radius = 1;
static bool blockhit = false;
static bool disable = false;
static bool while_clicking = false;
static bool buy = false;
static bool rod = false;
static int sw = 1;
static int rd = 1;
static int delay_rod = 100;
static bool fbridge;
int slot1 = 0x31;
int slot2 = 0x32;


// CMD работа
static bool cmd0 = false;
static bool cmd1 = false;
static bool cmd2 = false;
int countt = 0;

static char command0[64] = { "command" };
static char command1[64] = { "command" };
static char command2[64] = { "command" };

// CMD работа

static bool multiple = false;

bool Hcheck = true;

// Automine

bool active_bot_down = false;
bool active_bot = false;
int tick_count = 0;
static int Dynamic_range = 1;
static int walk_delay = 1;
bool Dynamic_reduction = false;
static int Dynamic_scale_down = 1;
static int Dynamic_delayX = 10;
static float DynamicY = 1.0f;
static int Dynamic_delayY = 10;
static int Dynamic_scale_down_Z = 1;
static float DynamicX = 1.0f;
static int walk_sleep = 100;
static int Dynamic_down_delay = 1;
static int Dynamic_delay_Z = 1;
static bool randomize = false;
static bool rotation = false;
static bool movement0 = false;
static bool reduction = false;
float color_3[4] = { 0.165f, 0.356f, 0.829f, 1.000f };
float color_2[4] = { 0.165f, 0.356f, 0.829f, 1.000f };
float color_1[4] = { 0.165f, 0.356f, 0.829f, 1.000f };

// notifications
bool active_notify = false;
bool notifi_test = false;
bool check_notify = true;
float color_notify = 1;
static int line = 210;
int notify_height = 300;
bool active_notify_load = false;
bool notifi_test_load = false;
bool check_notify_load = true;
float color_notify_load = 1;
static int line_load = 210;
int notify_height_load = 300;
static int up_notify_load = 380;
bool active_notify_delete = false;
bool notifi_test_delete = false;
bool check_notify_delete = true;
float color_notify_delete = 1;
static int line_delete = 210;
int notify_height_delete = 300;
static int up_notify_delete = 380;

//default not configuration
bool active_left = false;
bool active_right = false;
bool interactive = true;
bool CheckLock = true;
bool run = false;
static int click = 0;
static int tick_moon = 0;
static int right_click = 0;
static int bridge_timer = 0;
static int bridge_timer1 = 213;
bool fast = false;
static int hwidelay = 0;
int color_animationY = 0;
bool active_color_bar = false;
int color_animationY2 = 0;
bool active_color_bar2 = false;
int color_animationY1 = 0;
bool active_color_bar1 = false;
bool add_picker = false;
bool add_picker1 = false;
bool add_picker2 = false;
static int inventory_check = 0;
static bool middle = false;
static bool shifting = true;
static float blockhit_delay = 0;
bool Additional_configuration = false;
bool Additional_configurationClicker = true;
bool Additional_configurationAutobuy = true;
static bool mouse_down = false;
static bool left_mouses = false;
static int cycl = 0;
bool theme = true;
bool particle = true;
static bool doubles = false;
int BPS = 1;
static bool rod_toggle = false;
static bool purchase = false;
static bool active_loader = false;
//hotkeys
int test = 130;
int test1 = 1;
static float vector_speed = 100.0f;
static int key0;
static int key1;
static int key2;
static int key3;
static int key4;
static int key5;
static int key6;
int key7 = VK_LBUTTON;
int key8 = VK_RBUTTON;
static int key9;
static int key10;
static int key11;
static int key12;
static int key13;
static int key14;

// ScreenX,Y
int nWidth = GetSystemMetrics(SM_CXSCREEN / 2);
int nHeight = GetSystemMetrics(SM_CYSCREEN / 2);
int xx;
int yy;
int xxx;
int yyy;
int x;
int y;
int py;
int px;
int detecting = true;
int detecting_right = true;
int child_anim = 230;

// theme


int circle = 0;
float background_circle = 0.00f;
float rca0 = 0.138;
float rca1 = 0.138;
float rca2 = 0.138f;
POINT cur_position;
int purchase_x0;
int purchase_y0;
static int buy_speed = 60;
static int size_purchase = 0;
char c;
static bool func_shift = false;
static int avange = 0;
std::string purchase_mouse = "left";
//static const char* items[]{ "1", "2", "3", "4" , "5", "6" , "7" , "8" , "9" , "10" };
static int selectedItem = 0;
static bool autopurchase = false;
static int avange0 = 0;
int timer_purchase = 4;
int end_purch = 0;
static bool theslot = false;

// Слоты
static bool one_slot = true;
static bool two_slot = true;
static bool three_slot = true;
static bool four_slot = true;
static bool five_slot = true;
static bool six_slot = true;
static bool seven_slot = true;
static bool eight_slot = true;
static bool nine_slot = true;
static bool whileslot = true;
// Разное

static int clear_cog = 0.00f;
static char config_name[64] = { "" };
std::string config_save = "Macro0";
static bool slotcheck = false;
static bool slotcheck1 = false;
static bool hide = false;
static bool sound = false;
static bool keyboard = false;
static bool smart_delay = false;
static int smart = 0;
static int smart_right = 0;
static bool lbutton_up = false;
static bool detect_click = false;
static bool rbutton_up = false;
static bool detect_right = false;
static float text_animation = 0.00f;
static bool text_animation_hide = true;
static float loader_animation = 0.f;
static float progress = 250.0f;
static float bar = false;
static float bar_animation = 0.0f;
static bool remember = false;
static float text_animation0 = 0.00f;
static bool text_animation_hide0 = false;
static float dist_opticaly = 1.00f;
static float move_text = 0;
static bool autohit = false;
static int hit_chance = 100.0f;
static int hit_delay = 1.0f;
static float autoblockhit = 0;
std::string active;

std::string username;
std::string password;
static char user[64] = { "" };
static char pass[64] = { "" };
std::string user_active = "eax";
std::string pass_active = "123";
std::string cryptname = "0xA09";
std::string cryptpass = "0xD15";


static bool DXD3 = false;
static float alpha_borders = 0.0f;
static float opticaly_glass = 0.0f;
static float opticaly_glassUI = 0.0f;
static bool togspr = false;
static bool toggle_sprint = false;
static bool it_animation = false;
static bool tweak = false;
static int settings_box = 0;
static bool clean = false;
static bool rod_random = false;
static int rod_detect = 0;
static int key15 = 0x31;
static int key16 = 0x32;
static int key17 = 0x33;
static int key18 = 0x34;
static int key19 = 0x35;
static int key20 = 0x36;
static int key21 = 0x37;
static int key22 = 0x38;
static int key23 = 0x39;