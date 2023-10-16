#pragrma once
#include <SFML/Graphics.hpp>
#include <string.h>

class Object{
    public:
    string ksztalt[4] = {"none","kolo","trojkat","prostokat"};
    string tekstura;
    bool teksturaW;
    int r,g,b;
    bool color;
    int ilePunktow;
    float punkty;
    float koordynaty;

    Object(int wybor, bool teksturaW){
        this.ksztalt = ksztalt[wybor];
        this.teksturaW = teksturaW;
      }

}
