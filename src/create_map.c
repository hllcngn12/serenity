#include "serenity.h"

void create_map(Map* map, Info* info){
map->bg   =malloc_arrayint2(map->h,map->w);
map->clsn =calloc_arrayint2(map->h,map->w);
map->fg   =calloc_arrayint2(map->h,map->w);
map->it   =calloc_arrayint2(map->h,map->w);
map->inst =NULL;

for (int y=0; y<map->h; y++)
	if (!(y%2))
		for (int x=0; x<map->w; x++)
			if (!(x%2))	map->bg[y][x]='=';
			else		map->bg[y][x]=' ';
	else	for (int x=0; x<map->w; x++)
			if (!(x%2))	map->bg[y][x]=' ';
			else		map->bg[y][x]='=';

map->bg[0][0]=' '; map->bg[0][map->w-1]=' ';
map->bg[map->h-1][0]=' '; map->bg[map->h-1][map->w-1]=' ';
for (int x=2; x<map->w-2; x+=2)
	if (!(rand()%2)) map->bg[0][x]=' ';
for (int x=map->h%2+1; x<map->w-2; x+=2)
	if (!(rand()%2)) map->bg[map->h-1][x]=' ';
for (int y=2; y<map->h-2; y+=2)
	if (!(rand()%2)) map->bg[y][0]=' ';
for (int y=map->w%2+1; y<map->h-2; y+=2)
	if (!(rand()%2)) map->bg[y][map->w-1]=' ';

Asset* atree1 =load_asset("ass/tree1.txt");
paste_asset(map,10,10,atree1);
free_asset(atree1);

add_inst(map,20,20,info->interactive[0]);
add_inst(map,20,30,info->interactive[0]);

for (int i=0;i<map->w/3;i++)
	add_inst(map,
		rand()%(map->h-20)+10,rand()%(map->w-20)+10,
		info->interactive[1]);
for (int i=0;i<map->w/6;i++)
	add_inst(map,
		rand()%(map->h-20)+10,rand()%(map->w-20)+10,
		info->interactive[2]);}


void free_map(Map* map){
for (int y=0;y<map->h;y++) free(map->bg[y]);
for (int y=0;y<map->h;y++) free(map->clsn[y]);
for (int y=0;y<map->h;y++) free(map->fg[y]);
for (int y=0;y<map->h;y++) free(map->it[y]);
free(map->bg);free(map->clsn);free(map->fg);free(map->it);
free_instlist(map->inst);
free(map->name);free(map);}
