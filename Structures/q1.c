#include <stdio.h>
#include <string.h>

struct player
{
    char pname[20];
} ;
struct player pl;
char *play(struct player *temp_pl)
{
    strcpy(temp_pl->pname, "kohli");
    return temp_pl->pname;
}
int main()
{
    strcpy(pl.pname, "dhoni");
    printf("%s %s", pl.pname, play(&pl));
    printf("%s", pl.pname);
    printf("%s", play(&pl));
    return 0;
}