#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "ResourcePath.hpp"
using namespace std;

int mineCounter = -4;
int dg = 0;
int test = 0;
bool resets(int mousex, int mousey);
bool mines(int mousex, int mousey);
bool mines(int mousex, int mousey)
{
    cout << mousex << " " << mousey << endl;
    if(mousex <= 32 && mousey <= 32)
        return false;
    return true;
}
bool resets(int mousex, int mousey)
{
    return true;
}
int main()
{
    
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "minesweeper");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile(resourcePath() + "images/digits.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture t;
    if(!t.loadFromFile(resourcePath()+ "images/tile_hidden.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture re;
    if (!re.loadFromFile(resourcePath() + "images/face_happy.png"))
    {
        return EXIT_FAILURE;
    }
    
    sf::Texture d;
    if(!d.loadFromFile(resourcePath()+ "images/debug.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture f;
    if(!f.loadFromFile(resourcePath()+ "images/flag.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture t1;
    if(!t1.loadFromFile(resourcePath()+ "images/test_1.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture t2;
    if(!t2.loadFromFile(resourcePath()+ "images/test_2.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture m;
    if(!m.loadFromFile(resourcePath()+ "images/mine.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture k;
    if(!k.loadFromFile(resourcePath()+ "images/face_lose.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture w;
    if(!w.loadFromFile(resourcePath()+ "images/face_win.png"))
    {
        return EXIT_FAILURE;
    }
    
    // number sprites
    sf::Texture z;
    if(!z.loadFromFile(resourcePath()+ "images/tile_revealed.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture num1;
    if(!num1.loadFromFile(resourcePath()+ "images/number_1.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture num2;
    if(!num2.loadFromFile(resourcePath()+ "images/number_2.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture num3;
    if(!num3.loadFromFile(resourcePath()+ "images/number_3.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture num4;
    if(!num4.loadFromFile(resourcePath()+ "images/number_4.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture num5;
    if(!num5.loadFromFile(resourcePath()+ "images/number_5.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture num6;
    if(!num6.loadFromFile(resourcePath()+ "images/number_6.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture num7;
    if(!num7.loadFromFile(resourcePath()+ "images/number_7.png"))
    {
        return EXIT_FAILURE;
    }
    sf::Texture num8;
    if(!num8.loadFromFile(resourcePath()+ "images/number_8.png"))
    {
        return EXIT_FAILURE;
    }
    
    sf::Sprite zero(z);
    sf::Sprite one(num1);
    sf::Sprite two(num2);
    sf::Sprite three(num3);
    sf::Sprite four(num4);
    sf::Sprite five(num5);
    sf::Sprite six(num6);
    sf::Sprite seven(num7);
    sf::Sprite eight(num8);

    sf::Sprite win(w);
    sf::Sprite kill(k);
    sf::Sprite mine(m);
    sf::Sprite reset(re);
    sf::Sprite sprite(texture);
    sf::Sprite sprite2(texture);
    sf::Sprite sprite3(texture);
    sf::Sprite s(t);
    sf::Sprite debug(d);
    sf::Sprite test1(t1);
    sf::Sprite test2(t2);
    sf::Sprite flags(f);

    reset.setPosition(sf::Vector2f(368.f, 512.f));
    kill.setPosition(sf::Vector2f(368.f, 512.f));
    win.setPosition(sf::Vector2f(368.f, 512.f));
    debug.setPosition(sf::Vector2f(496.f, 512.f));
    test1.setPosition(sf::Vector2f(560.f, 512.f));
    test2.setPosition(sf::Vector2f(624.f, 512.f));

     //Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }

    int var[25][16];
    int vars[25][16];
    int hidden[25][16];
    
    
    int count = 0;
    while(count < 54)
    {
        int i = rand() % 25;
        int j = rand() % 16;
        hidden[i][j] = -1;
        count++;
        mineCounter++;
    }
    
    for (int i = 0; i < 25; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            int n = 0;
            if (hidden[i][j] == -1)
                continue;
            if (hidden[i+1][j] == -1 && i+1 < 26)
                n++;
            if (hidden[i][j+1] == -1 && j+1 < 16)
                n++;
            if (hidden[i-1][j] == -1 && i-1 >= 0)
                n++;
            if (hidden[i][j-1] == -1 && j-1 >= 0)
                n++;
            if (hidden[i+1][j+1] == -1 && i+1 < 26 && j+1 < 16)
                n++;
            if (hidden[i-1][j-1] == -1 && i-1 >= 0 && j-1 >= 0)
                n++;
            if (hidden[i-1][j+1] == -1 && i-1 >= 0 && j+1 < 16)
                n++;
            if (hidden[i+1][j-1] == -1 && i+1 < 26 && j-1 >= 0)
                n++;
            hidden[i][j] = n;
        }
    }
    
    //for show
    for(int i = 0; i < 25; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            var[i][j] = -2;
            vars[i][j] = -2;
        }
    }
    
    int smiley = 0;
    // Start the game loop
    while (window.isOpen())
    {
        
        //create board
        
        window.clear();
        for(int i = 0; i < 1; i++)
        {
            for(int j = 0; j < 16; j++)
            {
                s.setPosition(i*(32.f), j*(32.f));
                window.draw(s);
            }
        }
        //window.clear();
        for(int i = 0; i <= 24; i++)
        {
            for(int j = 0; j <= 15; j++)
            {
                if(vars[i][j] == -2)
                {
                    s.setPosition(i*(32.f), j*(32.f));
                    window.draw(s);
                }
                if(var[i][j] == -3)      //flag
                {
                    flags.setPosition(i*(32), j*(32));
                    window.draw(flags);
                }
                else if(var[i][j] == -1)      //mine
                {
                    mine.setPosition(i*(32.f), j*(32.f));
                    window.draw(mine);
                }
                else if(var[i][j] == 0)
                {
                    if (hidden[i+1][j] == 0 && i+1 < 26)
                    {
                        var[i+1][j] = 0;
                    }
                    else if (hidden[i+1][j] != -1 && i+1 < 26)
                        var[i+1][j] = hidden[i+1][j];
                    if (hidden[i][j+1] == 0 && j+1 < 16)
                    {
                        var[i][j+1] = 0;
                    }
                    else if (hidden[i][j+1] != -1 && j+1 < 16)
                        var[i][j+1] = hidden[i][j+1];
                    if (hidden[i-1][j] == 0 && i-1 >= 0)
                    {
                        var[i-1][j] = 0;
                    }
                    else if (hidden[i-1][j] != -1 && i-1 >= 0)
                        var[i-1][j] = hidden[i-1][j];
                    if (hidden[i][j-1] == 0 && j-1 >= 0)
                    {
                        var[i][j-1] = 0;
                    }
                    else if (hidden[i][j-1] != -1 && j-1 >= 0)
                        var[i][j-1] = hidden[i][j-1];
                    if (hidden[i+1][j+1] == 0 && i+1 < 26 && j+1 < 16)
                    {
                        var[i+1][j+1] = 0;
                    }
                    else if (hidden[i+1][j+1] != -1 && hidden[i+1][j+1] != 0 && i+1 < 26 && j+1 < 16)
                        var[i+1][j+1] = hidden[i+1][j+1];
                    if (hidden[i-1][j-1] == 0 && i-1 >= 0 && j-1 >= 0)
                    {
                        var[i-1][j-1] = 0;
                    }
                    else if (hidden[i-1][j-1] != -1 && hidden[i-1][j-1] != 0 && i-1 >= 0 && j-1 >= 0)
                        var[i-1][j-1] = hidden[i-1][j-1];
                    if (hidden[i-1][j+1] == 0 && i-1 >= 0 && j+1 < 16)
                    {
                        var[i-1][j+1] = 0;
                    }
                    else if (hidden[i-1][j+1] != -1 && hidden[i-1][j+1] != 0 && i-1 >= 0 && j+1 < 16)
                        var[i-1][j+1] = hidden[i-1][j+1];
                    if (hidden[i+1][j-1] == 0 && i+1 < 26 && j-1 >= 0)
                    {
                        var[i+1][j-1] = 0;
                    }
                    else if(hidden[i+1][j-1] != -1 && hidden[i+1][j-1] != 0 && i+1 < 26 && j-1 >= 0)
                        var[i+1][j-1] = hidden[i+1][j-1];
                    zero.setPosition(i*(32), j*(32));
                    window.draw(zero);
                    
                }
                else if(var[i][j] == 1)
                {
                    one.setPosition(i*(32), j*(32));
                    window.draw(one);
                    
                }
                else if(var[i][j] == 2)
                {
                    two.setPosition(i*(32), j*(32));
                    window.draw(two);
                    
                }
                else if(var[i][j] == 3)
                {
                    three.setPosition(i*(32), j*(32));
                    window.draw(three);
                }
                else if(var[i][j] == 4)
                {
                    four.setPosition(i*(32), j*(32));
                    window.draw(four);
                }
                else if(var[i][j] == 5)
                {
                    five.setPosition(i*(32), j*(32));
                    window.draw(five);
                }
                else if(var[i][j] == 6)
                {
                    six.setPosition(i*(32), j*(32));
                    window.draw(six);
                }
                else if(var[i][j] == 7)
                {
                    seven.setPosition(i*(32), j*(32));
                    window.draw(seven);
                }
                else if(var[i][j] == 8)
                {
                    eight.setPosition(i*(32), j*(32));
                    window.draw(eight);
                }
                
            }
        }
        sprite.setTextureRect(sf::IntRect(0, 0, 20, 32));
        sprite.setPosition(sf::Vector2f(0, 512.f));     // zero
        if(mineCounter/10 == 9)
        {
            sprite2.setTextureRect(sf::IntRect(189, 0, 20, 32));
            sprite2.setPosition(23, 512.f);
        }
        else if(mineCounter/10 == 8)
        {
            sprite2.setTextureRect(sf::IntRect(169, 0, 20, 32));
            sprite2.setPosition(23, 512.f);
        }
        else if(mineCounter/10 == 7)
        {
            sprite2.setTextureRect(sf::IntRect(149, 0, 20, 32));
            sprite2.setPosition(23, 512.f);
        }
        else if(mineCounter/10 == 6)
        {
            sprite2.setTextureRect(sf::IntRect(129, 0, 20, 32));
            sprite2.setPosition(23, 512.f);
        }
        else if(mineCounter/10 == 5)
        {
            sprite2.setTextureRect(sf::IntRect(110, 0, 20, 32));
            sprite2.setPosition(23, 512.f);
        }
        else if(mineCounter/10 == 4)
        {
            sprite2.setTextureRect(sf::IntRect(87, 0, 20, 32));
            sprite2.setPosition(23, 512.f);
        }
        else if(mineCounter/10 == 3)
        {
            sprite2.setTextureRect(sf::IntRect(67, 0, 20, 32));
            sprite2.setPosition(23, 512.f);
        }
        else if(mineCounter/10 == 2)
        {
            sprite2.setTextureRect(sf::IntRect(47, 0, 20, 32));
            sprite2.setPosition(23, 512.f);
        }
        else if(mineCounter/10 == 1)
        {
            sprite2.setTextureRect(sf::IntRect(27, 0, 20, 32));
            sprite2.setPosition(23, 512.f);
        }
        else if(mineCounter/10 == 0)
        {
            sprite2.setTextureRect(sf::IntRect(0, 0, 20, 32));
            sprite2.setPosition(23, 512.f);
        }
        if(mineCounter%10 == 9)
        {
            sprite3.setTextureRect(sf::IntRect(189, 0, 20, 32));
            sprite3.setPosition(40, 512.f);
        }
        if(mineCounter%10 == 8)
        {
            sprite3.setTextureRect(sf::IntRect(169, 0, 20, 32));
            sprite3.setPosition(40, 512.f);
        }
        if(mineCounter%10 == 7)
        {
            sprite3.setTextureRect(sf::IntRect(149, 0, 20, 32));
            sprite3.setPosition(40, 512.f);
        }
        if(mineCounter%10 == 6)
        {
            sprite3.setTextureRect(sf::IntRect(129, 0, 20, 32));
            sprite3.setPosition(40, 512.f);
        }
        if(mineCounter%10 == 5)
        {
            sprite3.setTextureRect(sf::IntRect(107, 0, 20, 32));
            sprite3.setPosition(40, 512.f);
        }
        if(mineCounter%10 == 4)
        {
            sprite3.setTextureRect(sf::IntRect(87, 0, 20, 32));
            sprite3.setPosition(40, 512.f);
        }
        if(mineCounter%10 == 3)
        {
            sprite3.setTextureRect(sf::IntRect(65, 0, 20, 32));
            sprite3.setPosition(40, 512.f);
        }
        if(mineCounter%10 == 2)
        {
            sprite3.setTextureRect(sf::IntRect(45, 0, 20, 32));
            sprite3.setPosition(40, 512.f);
        }
        if(mineCounter%10 == 1)
        {
            sprite3.setTextureRect(sf::IntRect(25, 0, 20, 32));
            sprite3.setPosition(40, 512.f);
        }
        if(mineCounter%10 == 0)
        {
            sprite3.setTextureRect(sf::IntRect(0, 0, 20, 32));
            sprite3.setPosition(40, 512.f);
        }
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sprite3);
        if(smiley == 0)
            window.draw(reset);
        else if(smiley == 1)
            window.draw(kill);
        else
            window.draw(win);
        window.draw(debug);
        window.draw(test1);
        window.draw(test2);
        int t = 0;
        for(int i = 0; i < 25; i++)
        {
            for(int j = 0; j < 16; j++)
            {
                if(var[i][j] >= 0)
                t++;
                //cout <<  "t " << t << endl;
            }
        }
        if(t == 350 && test == 0)
            smiley = 2;
        else if(t == (400 - mineCounter) && test == 1)
            smiley = 2;
        else if(t == (400 - mineCounter) && test == 2)
            smiley = 2;
        if(smiley == 2)
        {
            for(int i = 0; i < 25; i++)
            {
                for(int j = 0; j < 16; j++)
                {
                    if(hidden[i][j] == -1)
                    {
                        var[i][j] = -3;
                        mineCounter--;
                        
                    }
                }
            }
        }
        window.display();
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    if(event.mouseButton.y <= 512 && smiley != 1 && smiley != 2)          //flag
                    {
                        
                        int x = event.mouseButton.x/32;
                        int y = event.mouseButton.y/32;
                        //int temp = var[x+1][y];
                        if(var[x][y] == -3 || var[x][y] == -2)
                        {
                            if(var[x][y] == -3)
                            {
                                var[x][y] = -2;
                                mineCounter++;
                            }
                            else
                            {
                                var[x][y] = -3;
                                mineCounter--;
                            }
                        }
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Left)    //left button
                {
                    if(event.mouseButton.x >= 368 && event.mouseButton.y >= 512 && event.mouseButton.x <= 432 && event.mouseButton.y <= 578)
                    {
                        resets(event.mouseButton.x, event.mouseButton.y);             //reset
                        smiley = 0;
                        test = 0;
                        mineCounter = -4;
                        //window.clear();
                        for(int i = 0; i < 25; i++)
                        {
                            for(int j = 0; j < 16; j++)
                            {
                                var[i][j] = -2;
                                hidden[i][j] = -2;
                            }
                        }
                        int c = 0;
                        while(c < 54)
                        {
                            int i = rand() % 25;
                            int j = rand() % 16;
                            hidden[i][j] = -1;
                            c++;
                            mineCounter++;
                        }
                        for (int i = 0; i < 26; i++)
                        {
                            for (int j = 0; j < 16; j++)
                            {
                                int n = 0;
                                if (hidden[i][j] == -1)
                                    continue;
                                if (hidden[i+1][j] == -1 && i+1 < 26)
                                    n++;
                                if (hidden[i][j+1] == -1 && j+1 < 16)
                                    n++;
                                if (hidden[i-1][j] == -1 && i-1 >= 0)
                                    n++;
                                if (hidden[i][j-1] == -1 && j-1 >= 0)
                                    n++;
                                if (hidden[i+1][j+1] == -1 && i+1 < 26 && j+1 < 16)
                                    n++;
                                if (hidden[i-1][j-1] == -1 && i-1 >= 0 && j-1 >= 0)
                                    n++;
                                if (hidden[i-1][j+1] == -1 && i-1 >= 0 && j+1 < 16)
                                    n++;
                                if (hidden[i+1][j-1] == -1 && i+1 < 26 && j-1 >= 0)
                                    n++;
                                hidden[i][j] = n;
                            }
                        }
                        window.clear();
                    }
                    else if(event.mouseButton.x >= 560 && event.mouseButton.y >= 512 && event.mouseButton.x <= 624 && event.mouseButton.y <= 578 && smiley != 1 && smiley != 2)
                    {
                        window.clear();           //test 1
                        test = 1;
                        for(int i = 0; i < 25; i++)
                        {
                            for(int j = 0; j < 16; j++)
                            {
                                var[i][j] = -2;
                                hidden[i][j] = -2;
                            }
                        }
                        mineCounter = 0;
                        ifstream in(resourcePath()+ "boards/testboard.brd");
                        
                        vector<vector<int> > board(0);
                        
                        string str;
                        while(getline(in, str)) {
                            vector<int> row(0);
                            
                            for (int i = 0; i < str.size(); i++) {
                                char c = str[i];
                                if ((int)c == 13) {
                                    break;
                                }
                                row.push_back((int)c - '0');
                            }
                            board.push_back(row);
                        }
                        in.close();
                        
                        mineCounter = 0;
                        for(int i = 0; i < board.size(); i++) {
                            for(int j = 0; j < board[i].size(); j++) {
                                //cout << board[i][j];
                                if(board[i][j] == 1)
                                {
                                    hidden[j][i] = -1;
                                    mineCounter++;
                                }
                            }
                            //cout << endl;
                        }

                        for (int i = 0; i < 25; i++)
                        {
                            for (int j = 0; j < 16; j++)
                            {
                                int n = 0;
                                if (hidden[i][j] == -1)
                                    continue;
                                if (hidden[i+1][j] == -1 && i+1 < 26)
                                    n++;
                                if (hidden[i][j+1] == -1 && j+1 < 16)
                                    n++;
                                if (hidden[i-1][j] == -1 && i-1 >= 0)
                                    n++;
                                if (hidden[i][j-1] == -1 && j-1 >= 0)
                                    n++;
                                if (hidden[i+1][j+1] == -1 && i+1 < 26 && j+1 < 16)
                                    n++;
                                if (hidden[i-1][j-1] == -1 && i-1 >= 0 && j-1 >= 0)
                                    n++;
                                if (hidden[i-1][j+1] == -1 && i-1 >= 0 && j+1 < 16)
                                    n++;
                                if (hidden[i+1][j-1] == -1 && i+1 < 26 && j-1 >= 0)
                                    n++;
                                hidden[i][j] = n;
                            }
                        }
                    }
                    else if(event.mouseButton.x >= 624 && event.mouseButton.y >= 512 && event.mouseButton.x <= 688 && event.mouseButton.y <= 578 && smiley != 1 && smiley != 2)
                    {
                        window.clear();
                        //mineCounter = 98;                      //test 2
                        test = 2;
                        for(int i = 0; i < 25; i++)
                        {
                            for(int j = 0; j < 16; j++)
                            {
                                var[i][j] = -2;
                                hidden[i][j] = -2;
                            }
                        }

                        ifstream in(resourcePath()+ "boards/testboard2.brd");
                        
                        vector<vector<int> > board(0);
                        
                        string str;
                        while(getline(in, str)) {
                            vector<int> row(0);
                            
                            for (int i = 0; i < str.size(); i++) {
                                char c = str[i];
                                if ((int)c == 13) {
                                    break;
                                }
                                row.push_back((int)c - '0');
                            }
                            board.push_back(row);
                        }
                        in.close();
                        
                        mineCounter = 0;
                        for(int i = 0; i < board.size(); i++) {
                            for(int j = 0; j < board[i].size(); j++) {
                                //cout << board[i][j];
                                if(board[i][j] == 1)
                                {
                                    hidden[j][i] = -1;
                                    mineCounter++;
                                }
                            }
                            //cout << endl;
                        }
                        //mineCounter = 1;
                        for (int i = 0; i < 25; i++)
                        {
                            for (int j = 0; j < 16; j++)
                            {
                                int n = 0;
                                if (hidden[i][j] == -1)
                                    continue;
                                if (hidden[i+1][j] == -1 && i+1 < 26)
                                    n++;
                                if (hidden[i][j+1] == -1 && j+1 < 16)
                                    n++;
                                if (hidden[i-1][j] == -1 && i-1 >= 0)
                                    n++;
                                if (hidden[i][j-1] == -1 && j-1 >= 0)
                                    n++;
                                if (hidden[i+1][j+1] == -1 && i+1 < 26 && j+1 < 16)
                                    n++;
                                if (hidden[i-1][j-1] == -1 && i-1 >= 0 && j-1 >= 0)
                                    n++;
                                if (hidden[i-1][j+1] == -1 && i-1 >= 0 && j+1 < 16)
                                    n++;
                                if (hidden[i+1][j-1] == -1 && i+1 < 26 && j-1 >= 0)
                                    n++;
                                hidden[i][j] = n;
                            }
                        }
                    }
                    else if(event.mouseButton.x >= 496 && event.mouseButton.y >= 512 && event.mouseButton.x <= 559 && event.mouseButton.y <= 578 && smiley != 1 && smiley != 2)
                    {
                        if(dg == 0)
                        {
                            for(int i = 0; i < 25; i++)           //debug
                            {
                                for(int j = 0; j < 16; j++)
                                {
                                    if(hidden[i][j] == -1)
                                        var[i][j] = hidden[i][j];
                                }
                            }
                            dg++;
                        }
                        else
                        {
                            for(int i = 0; i < 25; i++)           //debug
                            {
                                for(int j = 0; j < 16; j++)
                                {
                                    if(hidden[i][j] == -1)
                                        var[i][j] = -2;
                                }
                            }
                            dg = 0;
                        }
                    }
                    else if(event.mouseButton.y <= 512 && smiley != 1 && smiley != 2)       //when clicking on the board
                    {
                        int x = event.mouseButton.x/32.f;
                        int y = event.mouseButton.y/32.f;
                        if(hidden[x][y] == -1 && var[x][y] != -3)  //mine
                        {
                            for(int i = 0; i < 25; i++)
                            {
                                for(int j = 0; j < 16; j++)
                                {
                                    if(hidden[i][j] == -1)
                                        var[i][j] = hidden[i][j];
                                }
                            }
                            smiley = 1;
                            
                        }
                        if(var[x][y] != -3 && smiley != 1 && smiley != 2)          //to show number
                        {
                            int n = 0;
                            var[x][y] = hidden[x][y];
                            for(int i = 0; i < 25; i++)
                            {
                                for(int j = 0; j < 16; j++)
                                {
                                    //cout << n  << " " << var[i][j] << endl;
                                    n++;
                                }
                            }
                            
                        }
                    }
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
