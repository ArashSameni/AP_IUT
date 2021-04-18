#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 200

typedef struct player
{
    int id;
    char name[MAX];
} player;

typedef struct team
{
    char name[MAX];
    int players[5000];
    int pCount;
    bool removed;
} team;

int getPlayerIdByName(player *players, const char *name, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (strcmp(players[i].name, name) == 0)
            return players[i].id;
    }
    return -1;
}

bool isPlayerInTeam(int *playerIds, int pId, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (playerIds[i] == pId)
            return true;
    }
    return false;
}

int getPlayerTeam(team *teams, int pId, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (isPlayerInTeam(teams[i].players, pId, teams[i].pCount))
            return i;
    }
    return -1;
}

int main()
{
    int playersCount, teamsCount;
    scanf("%d %d", &playersCount, &teamsCount);
    getchar();

    player players[playersCount];
    team teams[teamsCount];

    for (int i = 0; i < playersCount; i++)
    {
        players[i].id = i;
        fgets(players[i].name, MAX, stdin);
        players[i].name[strlen(players[i].name) - 1] = '\0';
    }

    for (int i = 0; i < teamsCount; i++)
    {
        int teamPlayersCount;

        fgets(teams[i].name, MAX, stdin);
        teams[i].name[strlen(teams[i].name) - 1] = '\0';
        teams[i].pCount = 0;
        teams[i].removed = false;

        scanf("%d", &teamPlayersCount);
        getchar();
        for (int j = 0; j < teamPlayersCount; j++)
        {
            char pName[MAX];
            fgets(pName, MAX, stdin);
            pName[strlen(pName) - 1] = '\0';
            int pId = getPlayerIdByName(players, pName, playersCount);
            if (pId == -1)
                teams[i].removed = true;
            else
            {
                int playerTeamId = getPlayerTeam(teams, pId, teamsCount);
                if (playerTeamId == -1)
                {
                    int teamPlayersCount = teams[i].pCount;
                    teams[i].players[teamPlayersCount] = pId;
                    teams[i].pCount = teamPlayersCount + 1;
                }
                else
                {
                    teams[i].removed = true;
                    teams[playerTeamId].removed = true;
                }
            }
        }
    }

    char removedTeams[teamsCount + 1][MAX];
    int pos = 0;
    for (int i = 0; i < teamsCount; i++)
    {
        if (teams[i].removed)
            strcpy(removedTeams[pos++], teams[i].name);
    }

    char temp[MAX];
    for (int i = 0; i < pos; i++)
        for (int j = i + 1; j < pos; j++)
        {
            if (strcmp(removedTeams[i], removedTeams[j]) > 0)
            {
                strcpy(temp, removedTeams[i]);
                strcpy(removedTeams[i], removedTeams[j]);
                strcpy(removedTeams[j], temp);
            }
        }

    for (int i = 0; i < pos; i++)
        printf("%s\n", removedTeams[i]);

    return 0;
}