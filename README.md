# A personal fork of dwm - the suckless dynamic window manager

## Patches

Look at the commit history for more details on how these patches were
applied.

### Statusbar

+ [notitle](https://dwm.suckless.org/patches/notitle/) - remove window
  name area from statusbar;
+ [statusallmons](https://dwm.suckless.org/patches/statusallmons/) -
  render statusbar on all monitors;
+ [hidevacanttags](https://dwm.suckless.org/patches/hide_vacant_tags/) -
  display only tags with at least one client;
+ [statuspadding](https://dwm.suckless.org/patches/statuspadding/) - add
  configurable horizontal/vertical padding to statusbar.

### Misc

+ [restartsig](https://dwm.suckless.org/patches/restartsig/) - add
  signal handling to cleanly kill/restart dwm.

Requirements
------------
In order to build dwm you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

    make clean install


Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:

    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something
like this in your .xinitrc:

    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.