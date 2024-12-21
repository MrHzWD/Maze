#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Rout{
public:
    int x;
    int y;
};

class Game{
private:
    char map[32][32];
    void creatMap(){
        for (int i = 0; i < 32; ++i) {
            map[0][i] = 'O';
            map[31][i] = 'O';
            map[i][0] = 'O';
            map[i][31] = 'O';
        }
        srand(time(0));
        for (int i = 1; i < 31; ++i) {
            for (int j = 1; j < 31; ++j) {
                if(rand()%4 == 0){
                    map[i][j] = 'O';
                }else{
                    map[i][j] = '.';
                }
            }
        }
        map[1][1] = 'S';
        map[30][30] = 'E';
    }
    void showMap(){
        for (int i = 0; i < 32; ++i) {
            for (int j = 0; j < 32; ++j) {
                cout << map[i][j] << " ";
            }
            cout << "\n";
        }
    }
    void run(){
        vector<Rout> rout;
        Rout r{};
        r.x = 1;
        r.y = 1;
        while (map[r.y][r.x] != 'E' && map[r.y+1][r.x] != 'E' && map[r.y-1][r.x] != 'E' && map[r.y][r.x+1] != 'E' && map[r.y][r.x-1] != 'E'){
            bool checkChange = false;
            if(map[r.y+1][r.x] == '.'){
                r.y++;
                rout.push_back(r);
                map[r.y][r.x] = 'x';
                checkChange = true;
            }else if(map[r.y][r.x+1] == '.'){
                r.x++;
                rout.push_back(r);
                map[r.y][r.x] = 'x';
                checkChange = true;
            }else if(map[r.y-1][r.x] == '.'){
                r.y--;
                rout.push_back(r);
                map[r.y][r.x] = 'x';
                checkChange = true;
            }else if(map[r.y][r.x-1] == '.'){
                r.x--;
                rout.push_back(r);
                map[r.y][r.x] = 'x';
                checkChange = true;
            }
            if(!checkChange){
                rout.pop_back();
                r.x = rout.end()->x;
                r.y = rout.end()->y;
            }
            _sleep(175);
            system("cls");
            showMap();
        }
        cout << "\nThe End :)\n";
    }

public:
    Game(){
        creatMap();
        showMap();
        run();
    }
};

int main() {
    cout << "\nMaze open source game project :)\n\nProgrammer: MohammadReza Heydarizade\n\n\n...";
    _sleep(3500);
    system("cls");
    Game g;
    return 0;
}
