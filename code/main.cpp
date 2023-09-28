#include "supmain.h"

/*
    bo sung tat trong luc choi(done)
    replay
    tuy chon tu vung theo ngay
*/

int main(int argc , char * argv[]){

    string input = selectInput();
  ///  du_lieu = input;
  /// cout << input << "\n" ;

    srand(time(0));

    SDL_Window * newWindow;
    SDL_Renderer * newRender;
    SDL_Event e;

    khoitaoSDL(newWindow, newRender);

	///cout << "nhap ngay ban muon (dinh dang yymmdd): ";
///	string s ; cin >> s;
   /// cerr << 1;
    Game * g = new Game(newRender,input);

   /// cerr << 12;



        do{
            pair<bool, bool> p = renderPreGame(newRender, e, g);
            bool runGame = 1, replay = 0;
            if(!p.first) goto nextState;

            do{
                if(p.second) g->auto_adjust_mainCha();

                renderGamePlay(newRender, g);
                solEvent(e, runGame, g);

            }while(runGame && !( g->isGameOver() ));

            nextState:;
            g->mBg->stopMusic();
            renderEndGame(g->true_type, g->total_type, g->sl_die, newRender, e, replay);

            if(!replay) break;

            g->refresh();
        }while(1);

    g->~Game();
    thoatSDL(newWindow, newRender);

    return 0;
}
