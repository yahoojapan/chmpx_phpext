---
layout: contents
language: en-us
title: Configurations
short_desc: CHMPX PHP Extension - PHP Extension library for CHMPX
lang_opp_file: configurationsja.html
lang_opp_word: To Japanese
prev_url: developer.html
prev_string: Developer
top_url: index.html
top_string: TOP
next_url: 
next_string:
---

# Environments
CHMPX PHP Extension library does not define its own environment variable.
However, the environment variable defined by [CHMPX](https://chmpx.antpick.ax/) is loaded into CHMPX PHP Extension library through it.
For information on these environment variables, please see [here](https://chmpx.antpick.ax/configurations.html).

# INI settings
The behaviour of the library can be affected by settings in php.ini as well as by using [ini_set](https://www.php.net/manual/en/function.ini-set). The configuration directives below are defined by CHMPX PHP Extension.

## chmpxpx.debug
Specify the log levels of the library among the following values. This parameter can be set anywhere(`PHP_INI_ALL`).

- **error**  
the level of the importance of the message is the "error" level
- **info**  
the level of the importance of the message is the "info" level
- **warning**  
the level of the importance of the message is the "warning" level
- **silent(default)**  
the level of the importance of the message is the "silent" level which is the default level
 
