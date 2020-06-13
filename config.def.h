/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int gappx              = 0;        /* default gaps between windows */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int horizpadbar        = 2;        /* horizontal padding for statusbar */
static const int vertpadbar         = 10;        /* vertical padding for statusbar */
static const char *fonts[]          = {
    "monospace:size=10",
    "Twitter Color Emoji:size=8",
    "forkawesome:size=9"
};
static const char dmenufont[]       = "monospace:size=10";

/* Gruvbox dark theme */
static const char gruv_bg0[]		 = "#282828";
static const char gruv_red[]		 = "#cc241d";
static const char gruv_green[]		 = "#98971a";
static const char gruv_yellow[]		 = "#d79921";
static const char gruv_blue[]		 = "#458588";
static const char gruv_purple[]		 = "#b16286";
static const char gruv_aqua[]		 = "#689d6a";
static const char gruv_gray[]		 = "#a89984";
static const char gruv_gray0[]		 = "#928374";
static const char gruv_lightred[]	 = "#fb4934";
static const char gruv_lightgreen[]	 = "#b8bb26";
static const char gruv_lightyellow[] = "#fabd2f";
static const char gruv_lightblue[]	 = "#83a598";
static const char gruv_lightpurple[] = "#d3869b";
static const char gruv_lightaqua[]	 = "#8ec07c";
static const char gruv_fg1[]		 = "#ebdbb2";
/* Gruvbox additional colors */
static const char gruv_bg0_h[]		 = "#1d2021";
static const char gruv_bg1[]		 = "#3c3836";
static const char gruv_bg2[]		 = "#504945";
static const char gruv_bg3[]		 = "#665c54";
static const char gruv_bg4[]		 = "#7c6f64";
static const char gruv_orange[]		 = "#d65d0e";
static const char gruv_bg0_s[]		 = "#32302f";
static const char gruv_fg4[]	 	 = "#a89984";
static const char gruv_fg3[]	     = "#bdae93";
static const char gruv_fg2[] 		 = "#d5c4a1";
static const char gruv_fg0[]         = "#fbf1c7";
static const char gruv_lightorange[] = "#fe8019";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { gruv_bg4, gruv_bg0, gruv_gray0 },
	[SchemeSel]  = { gruv_fg0, gruv_bg0, gruv_blue  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
    /* class      instance    title       tags mask     iscentered   isfloating   monitor */
    { "Gimp",     NULL,       NULL,       0,            0,           1,           -1 },
    { "Firefox",  NULL,       NULL,       1 << 8,       0,           0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
    { "TTT",      btile },
    { "[D]",      deck },
    { "|M|",      centmaster },
    { "###",      grid },
    { NULL,       NULL },
	//{ "[M]",      monocle },
	//{ "><>",      NULL },    /* no layout function means floating behavior */
};

/* key definitions */
#define MODKEY Mod1Mask
#define WINKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", gruv_bg0, "-nf", gruv_fg1, "-sb", gruv_blue, "-sf", gruv_fg1, NULL };
static const char *termcmd[]  = { "st", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_t,      spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_Tab,      focusstack,     {.i = +1 } },
	//{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_e,      zoom,           {0} },
    { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
    { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	//{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ WINKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { WINKEY,                       XK_space,  cyclelayout,    {.i = +1 } },
    { WINKEY|ShiftMask,             XK_space,  cyclelayout,    {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_x,      togglefloating, {0} },
    { MODKEY|ShiftMask,             XK_s,      togglesticky,   {0} },
    { MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
    { WINKEY,                       XK_minus,  setgaps,        {.i = -5 } },
    { WINKEY,                       XK_equal,  setgaps,        {.i = 0 } },
    { WINKEY|ShiftMask,             XK_equal,  setgaps,        {.i = +5  } },
	//{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_F1,     quit,           {0} },
    { MODKEY|ShiftMask,             XK_F2,     quit,           {1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkClientWin,         WINKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         WINKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         WINKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

