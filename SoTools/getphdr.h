#pragma once
#include "elf.h"
#include "qstring.h"
//program herder == phdr
const char *getphtype(Elf32_Word type);

const char *getphtypedesc(Elf32_Word type);

const QString getphflg(Elf32_Word flag);