#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void no(void)
{
  puts("Nope.");
  exit(1);
}

void ok(void)
{
  puts("Good job.");
  return;
}


int main()
{
  int uVar1;
  size_t sVar2;
  int iVar3;
  bool bVar4;
  char local_3d;
  char local_3c;
  char local_3b;
  int local_3a;
  char local_39[24];
  char local_21[9];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  printf("Please enter key: ");
  local_10 = scanf("%23s",local_39);
  if (local_10 != 1) {
    no();
  }
  if (local_39[1] != '0') {
    no();
  }
  if (local_39[0] != '0') {
    no();
  }
  fflush(stdin);
  memset(local_21,0,9);
  local_21[0] = 'd';
  local_3a = 0;
  local_18 = 2;
  local_14 = 1;
  while(true) 
  {
    sVar2 = strlen(local_21);
    uVar1 = local_18;
    bVar4 = false;
    if (sVar2 < 8) 
    {
      sVar2 = strlen(local_39);
      bVar4 = uVar1 < sVar2;
    }
    if (!bVar4)
        break;
    local_3d = local_39[local_18];
    local_3c = local_39[local_18 + 1];
    local_3b = local_39[local_18 + 2];
    char group[4];
    group[0] = local_3d;
    group[1] = local_3c;
    group[2] = local_3b;
    group[3] = '\0'; 
    iVar3 = atoi(group);
    local_21[local_14] = (char)iVar3;
    local_18 = local_18 + 3;
    local_14 = local_14 + 1;
  }
  local_21[local_14] = '\0';
  iVar3 = strcmp(local_21,"delabere");
  if (iVar3 == 0) 
    ok();
  else
    no();
  return 0;
}
