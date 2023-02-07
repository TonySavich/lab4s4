#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>

const int N = 5;




int main()
{

    int mas[N][N];
    int v[N];
  

    int dop[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mas[i][j] = 0;
            dop[i][j] = 0;
            v[i] = 0;

        }
    }
    std::string m;
    std::string line;
    int k = 0;
    int r = 0;
    std::ifstream in("in.txt");
    if (in.is_open())
    {
        while (!in.eof()) {
            while (getline(in, line))
            {
                m = line;
                for (int i = 0; i < m.length(); i++) {
                    if (m[i] != ' ') {
                        dop[k][r] = dop[k][r] * 10 + (int)m[i] - 48;
                    }
                    else {
                        r++;
                    }
                }
                k++;
                r = 0;
            }
        }

    }
    in.close();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dop[i][j] != 0) {
                mas[i][dop[i][j] - 1] = 1;

            }

        }
    }


    int dano = 0;
    int komp = 0;


    std::stack <int> gg;

   
    int danotwo = dano;

    while (1) {
        gg.push(dano);

        while (!gg.empty()) {
            int n = gg.top();

            gg.pop();
            v[n] = 2;

            for (int i = 0; i < N; i++) {
                if (mas[n][i] == 1 && v[i] == 0) {
                    v[i] = 1;
                    gg.push(i);

                }
            }
        }



        for (int i = 0; i < N; i++) {
            if (v[i] == 0) {
                danotwo = i;
            }
        }

       
            komp++;
            for (int i = 0; i < N; i++) {
                if (v[i] == 2) {
                    std::cout << i + 1 << " ";
                    v[i] = 10;
                }
            }
            std::cout<< std::endl;
        
            if (dano == danotwo) {
                break;
            }
            else {
                dano = danotwo;
            }


    }
    std::cout << komp;

}
