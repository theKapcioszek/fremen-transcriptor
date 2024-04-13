#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "raylib.h"

#define MAX_STRING_LENGTH 50
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define CHAR_WIDTH ((SCREEN_WIDTH/800)*64)
#define CHAR_HEIGHT ((SCREEN_HEIGHT/600)*64)

char concat_result[255];

char *concat(const char* str1, const char* str2){

  strcpy(concat_result, str1);
  strcat(concat_result, str2);

  return concat_result;
}

enum Character {
  B = 1,
  F,
  M,
  T,
  TH,
  D,
  DH,
  N,
  S,
  SH,
  Z,
  J,
  K,
  KH,
  G,
  GH,
  Q,
  L,
  R,
  W,
  Y,
  H,
  A,
  E,
  I,
  O,
  U
};

void transcript(char* message, int *charcters){

  for(int i = 0; message[i]; i++){
    message[i] = tolower(message[i]);
  }

  for(int i = 0; i < 100; i++){
    charcters[i] = 0;
  }

  for(int i = 0; i < strlen(message); i++){
    switch (message[i]){
      case 'b':
        charcters[i] = B;
        break;
      case 'f':
        charcters[i] = F;
        break;
      case 'm':
        charcters[i] = M;
        break;
      case 't':
        if(message[i+1] == 'h'){
          charcters[i] = TH;
          i++;
        }
        else{
          charcters[i] = T;
        }
        break;
      case 'd':
        if(message[i+1] == 'h'){
          charcters[i] = DH;
          i++;
        }
        else{
          charcters[i] = D;
        }
        break;
      case 'n':
        charcters[i] = N;
        break;
      case 's':
        if(message[i+1] == 'h'){
          charcters[i] = SH;
          i++;
        }
        else{
          charcters[i] = S;
        }
        break;
      case 'z':
        charcters[i] = Z;
        break;
      case 'j':
        charcters[i] = J;
        break;
      case 'k':
        if(message[i+1] == 'h'){
          charcters[i] = KH;
          i++;
        }
        else{
          charcters[i] = K;
        }
        break;
      case 'g':
        if(message[i+1] == 'h'){
          charcters[i] = GH;
          i++;
        }
        else{
          charcters[i] = G;
        }
        break;
      case 'q':
        charcters[i] = Q;
        break;
      case 'l':
        charcters[i] = L;
        break;
      case 'r':
        charcters[i] = R;
        break;
      case 'w':
        charcters[i] = W;
        break;
      case 'y':
        charcters[i] = Y;
        break;
      case 'h':
        charcters[i] = H;
        break;
      case 'a':
        charcters[i] = A;
        break;
      case 'e':
        charcters[i] = E;
        break;
      case 'i':
        charcters[i] = I;
        break;
      case 'o':
        charcters[i] = O;
        break;
      case 'u':
        charcters[i] = U;
        break;
      default: 
        break;
    }
  }
}

void screenshot(bool fullscreen, char* message){
  Image screenshot = LoadImageFromScreen();
  if(!fullscreen){
    ImageCrop(&screenshot, (Rectangle){
      (SCREEN_WIDTH/2)-((strlen(message)/2)*60)-5,
      (SCREEN_HEIGHT/2)-5,
      (CHAR_WIDTH*strlen(message))+7,
      CHAR_HEIGHT+7
    });
    char filename[strlen(message)+4];
    strcpy(filename, message);
    strcat(filename, ".png");
    ExportImage(screenshot, filename);
  }
  else{
    int file_count = 1;
    char filename[strlen("screenshot")+10];
    strcpy(filename, "screenshot.png");
    while(FileExists(filename)){
      strcpy(filename, "");
      sprintf(filename, "screenshot%d.png", file_count);
      file_count++;
    }
    ExportImage(screenshot, filename);
  }
}

char TextBuffer[MAX_STRING_LENGTH + 1] = "\0";
int LetterCount = 0;
bool cmd_flag = false;
int cursor_pos_backup = 0;

int main(int argc, char *argv[]){

  const char *executablePath = GetApplicationDirectory();

  int msglen = 0;

  if(argc > 1){
    msglen = strlen(argv[1]);
    cmd_flag = true;
  }
  else{
    msglen = MAX_STRING_LENGTH;
  }

  int charcters[100] = {0};
  char message[msglen];

  if(cmd_flag == true){
    strcpy(message, argv[1]);
    transcript(message, charcters);
  }

  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Fremen Transcriptor");
  SetTargetFPS(60);

  Image characters_img[28] = {0};
  
  characters_img[0] = GenImageColor(1, 1, WHITE);
  characters_img[1] = LoadImage(concat(executablePath,"fremen-assets/B.png"));
  characters_img[2] = LoadImage(concat(executablePath,"fremen-assets/F.png"));
  characters_img[3] = LoadImage(concat(executablePath,"fremen-assets/M.png"));
  characters_img[4] = LoadImage(concat(executablePath,"fremen-assets/T.png"));
  characters_img[5] = LoadImage(concat(executablePath,"fremen-assets/TH.png"));
  characters_img[6] = LoadImage(concat(executablePath,"fremen-assets/D.png"));
  characters_img[7] = LoadImage(concat(executablePath,"fremen-assets/DH.png"));
  characters_img[8] = LoadImage(concat(executablePath,"fremen-assets/N.png"));
  characters_img[9] = LoadImage(concat(executablePath,"fremen-assets/S.png"));
  characters_img[10] = LoadImage(concat(executablePath,"fremen-assets/SH.png"));
  characters_img[11] = LoadImage(concat(executablePath,"fremen-assets/Z.png"));
  characters_img[12] = LoadImage(concat(executablePath,"fremen-assets/J.png"));
  characters_img[13] = LoadImage(concat(executablePath,"fremen-assets/K.png"));
  characters_img[14] = LoadImage(concat(executablePath,"fremen-assets/KH.png"));
  characters_img[15] = LoadImage(concat(executablePath,"fremen-assets/G.png"));
  characters_img[16] = LoadImage(concat(executablePath,"fremen-assets/GH.png"));
  characters_img[17] = LoadImage(concat(executablePath,"fremen-assets/Q.png"));
  characters_img[18] = LoadImage(concat(executablePath,"fremen-assets/L.png"));
  characters_img[19] = LoadImage(concat(executablePath,"fremen-assets/R.png"));
  characters_img[20] = LoadImage(concat(executablePath,"fremen-assets/W.png"));
  characters_img[21] = LoadImage(concat(executablePath,"fremen-assets/Y.png"));
  characters_img[22] = LoadImage(concat(executablePath,"fremen-assets/H.png"));
  characters_img[23] = LoadImage(concat(executablePath,"fremen-assets/A.png"));
  characters_img[24] = LoadImage(concat(executablePath,"fremen-assets/E.png"));
  characters_img[25] = LoadImage(concat(executablePath,"fremen-assets/I.png"));
  characters_img[26] = LoadImage(concat(executablePath,"fremen-assets/O.png"));
  characters_img[27] = LoadImage(concat(executablePath,"fremen-assets/U.png"));

  for(int i = 0; i <= 27; i++){
    ImageResizeNN(&characters_img[i], CHAR_WIDTH, CHAR_HEIGHT);
  }

  Texture2D characters_tex[28] = {0};

  for(int i = 0; i <= 27; i++){
    characters_tex[i] = LoadTextureFromImage(characters_img[i]);
  }

  while(!WindowShouldClose()){

    if(IsKeyPressed(KEY_F2)){
      screenshot(true, message);
    }

    if(IsKeyPressed(KEY_F3)){
      screenshot(false, message);
    }

    transcript(message, charcters);

    BeginDrawing();

    ClearBackground((Color){255,212,94,255});

    int cursor_pos = 0;
    for(int i = 99; i >= 0; i--){
      if(charcters[i] > 0){
        DrawTexture(characters_tex[charcters[i]], (SCREEN_WIDTH/2)-((strlen(message)/2)*60)+(60*cursor_pos), (SCREEN_HEIGHT/2), WHITE);
        cursor_pos++;
      }
    }

    DrawText(TextBuffer, (SCREEN_WIDTH/2)-(MeasureText(TextBuffer, 30)/2), (SCREEN_HEIGHT/6), (SCREEN_HEIGHT/20), BLACK);

    EndDrawing();

    //INPUT
    if(cmd_flag == false){
      int PressedKey = GetCharPressed();

      while(PressedKey > 0){
        if((PressedKey > 32) && (PressedKey <= 125) && (LetterCount <= MAX_STRING_LENGTH)){

          TextBuffer[LetterCount] = (char)PressedKey;
          TextBuffer[LetterCount+1] = '\0';
          LetterCount++;
        }
        PressedKey = GetCharPressed();
      }

      if(IsKeyDown(KEY_BACKSPACE)){
        WaitTime(0.2);
        LetterCount--;
        if(LetterCount < 0){
          LetterCount = 0;
        }
        TextBuffer[LetterCount] = '\0';

      }
      strcpy(message, TextBuffer);
    } 
    //INPUT
  }

  for(int i = 0; i <= 27; i++){
    UnloadImage(characters_img[i]);
    UnloadTexture(characters_tex[i]);
  }

  return 0;
}
