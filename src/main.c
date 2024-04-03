#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "raylib.h"

#define MAX_STRING_LENGTH 50

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

char TextBuffer[MAX_STRING_LENGTH + 1] = "\0";
int LetterCount = 0;

int main(int argc, char *argv[]){
  
  int msglen = 0;

  if(argc > 1){
    msglen = strlen(argv[1]);
  }

  int charcters[100] = {0};
  char message[msglen];

  if(argc > 1){

    strcpy(message, argv[1]);

    for(int i = 0; message[i]; i++){
      message[i] = tolower(message[i]);
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
          if(argv[1][i+1] == 'h'){
            charcters[i] = TH;
            i++;
          }
          else{
            charcters[i] = T;
          }
          break;
        case 'd':
          if(argv[1][i+1] == 'h'){
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
          if(argv[1][i+1] == 'h'){
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
          if(argv[1][i+1] == 'h'){
            charcters[i] = KH;
            i++;
          }
          else{
            charcters[i] = K;
          }
          break;
        case 'g':
          if(argv[1][i+1] == 'h'){
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
    printf("%d %d %d %d %s \n",charcters[0], charcters[1], charcters[2], charcters[3], message);
  }
  else{
    printf("Provide a word as an argument\n");
    return 1;
  }

  InitWindow(800, 600, "Fremen Transcriptor");
  SetTargetFPS(60);

  Image characters_img[28] = {0};
  
  characters_img[0] = GenImageColor(1, 1, WHITE);
  characters_img[1] = LoadImage("assets/B.png");
  characters_img[2] = LoadImage("assets/F.png");
  characters_img[3] = LoadImage("assets/M.png");
  characters_img[4] = LoadImage("assets/T.png");
  characters_img[5] = LoadImage("assets/TH.png");
  characters_img[6] = LoadImage("assets/D.png");
  characters_img[7] = LoadImage("assets/DH.png");
  characters_img[8] = LoadImage("assets/N.png");
  characters_img[9] = LoadImage("assets/S.png");
  characters_img[10] = LoadImage("assets/SH.png");
  characters_img[11] = LoadImage("assets/Z.png");
  characters_img[12] = LoadImage("assets/J.png");
  characters_img[13] = LoadImage("assets/K.png");
  characters_img[14] = LoadImage("assets/KH.png");
  characters_img[15] = LoadImage("assets/G.png");
  characters_img[16] = LoadImage("assets/GH.png");
  characters_img[17] = LoadImage("assets/Q.png");
  characters_img[18] = LoadImage("assets/L.png");
  characters_img[19] = LoadImage("assets/R.png");
  characters_img[20] = LoadImage("assets/W.png");
  characters_img[21] = LoadImage("assets/Y.png");
  characters_img[22] = LoadImage("assets/H.png");
  characters_img[23] = LoadImage("assets/A.png");
  characters_img[24] = LoadImage("assets/E.png");
  characters_img[25] = LoadImage("assets/I.png");
  characters_img[26] = LoadImage("assets/O.png");
  characters_img[27] = LoadImage("assets/U.png");

  for(int i = 0; i <= 27; i++){
    ImageResizeNN(&characters_img[i], 64, 64);
  }

  Texture2D characters_tex[28] = {0};

  for(int i = 0; i <= 27; i++){
    characters_tex[i] = LoadTextureFromImage(characters_img[i]);
  }

  while(!WindowShouldClose()){
    BeginDrawing();

    ClearBackground((Color){255,212,94,255});

    int cursor_pos = 0;
    for(int i = 99; i >= 0; i--){
      if(charcters[i] > 0){
        DrawTexture(characters_tex[charcters[i]], 400-((strlen(message)/2)*60)+(60*cursor_pos), 300, WHITE);
        cursor_pos++;
      }
    }

    DrawText(TextBuffer, 400-(MeasureText(TextBuffer, 30)/2), 100, 30, BLACK);

    EndDrawing();

    //INPUT
    
    int PressedKey = GetCharPressed();

    while(PressedKey > 0){
      if((PressedKey >=32) && (PressedKey <= 125) && (LetterCount <= MAX_STRING_LENGTH)){

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

    //INPUT
  }

  for(int i = 0; i <= 27; i++){
    UnloadImage(characters_img[i]);
    UnloadTexture(characters_tex[i]);
  }

  return 0;
}
