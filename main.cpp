#include <iostream>
#include <string>

int ar[9] = {0};
int pin[9] = {0}; //789 159 751
int num;           //789.159.751
std::string A[20] = {"ena", "dio", "tria", "tesera", "pente", "eksi", "epta", "okto", "ennia"};
std::string V[20] = {"deka", "enteka", "dodeka", "dekatria", "dekatessera", "dekapente", "dekaeksi", "dekaepta", "dekaokto", "dekaennia"};
std::string C[10] = {"eikosi", "trianta", "saranta", "peninta", "eksinta", "ebdominta", "ogdonta", "eneninta"};
std::string D[10] = {"ekaton", "diakosia", "triakosia", "tetrakosia", "pentakosia", "eksakosia", "eptakosia", "oktakosia", "enniakosia"};
std::string F[10] = {"ekaton", "diakosies", "triakosies", "tetrakosies", "pentakosies", "eksakosies", "eptakosies", "oktakosies", "enniakosies"};
std::string E[10] = {"ekaton", "diakosia", "triakosia", "tetrakosia", "pentakosia", "eksakosia", "eptakosia", "oktakosia", "enniakosia"};

int dig(int n) {
    int i = 0, size = 0;
    int j, y, keepn;
    keepn = n;
    while (n != 0) {
        y = n % 10;
        ar[i] = y;
        i++;
        size++;
        n = n / 10;
    }
    return size;
}

void reverse(int ar[], int x) {
    for (int i = 0; i < x; i++) {
        pin[x - 1 - i] = ar[i];
    }

    for (int i = 0; i < x; i++) {
        ar[i] = pin[i];
    }
}

int main() {
    int i, x, z, n, psif, size, digit, pos;
    char a;
    int ekato[3] = {0}, xilia[3] = {0}, miria[3] = {0};
    std::cout << "Dose ena arithmo: ";
    std::cin >> num;
    if (num == 0)
        std::cout << "mhden\n";
    if (num < 0) {
        std::cout << "meion\n";
        num = -num * 1;
    }
    x = dig(num);
    n = num;
    reverse(ar, x);
    int b = 0;
    int c = dig(num);
    for (i = c - 1; i >= 0; i--) {
        ekato[2 - b] = pin[i];
        b++;
    }
    b = 0;
    for (i = c - 4; i >= 0; i--) {
        xilia[2 - b] = pin[i];
        b++;
    }
    b = 0;
    for (i = c - 7; i >= 0; i--) {
        miria[2 - b] = pin[i];
        b++;
    }

    //----------million ----------------
    if (miria[0] + miria[1] + miria[2] != 0) {
        if (miria[0] != 0) {
            std::cout << D[miria[0] - 1] << std::endl;
        }
        //-------------1dig----------
        if (miria[1] != 0) {
            if (miria[1] >= 2) { //ok
                std::cout << C[miria[1] - 2] << std::endl;
            } else if (miria[1] == 1 && miria[2] == 2) {
                std::cout << "dodeka" << std::endl; //ok
            } else if (miria[1] == 1 && miria[2] == 1) {
                std::cout << "enteka" << std::endl; //ok
            } else if (miria[1] == 1 && miria[2] != 1 && miria[2] != 2) {
                std::cout << V[miria[2]] << std::endl;
            }
        }
        //----------2dig-------------
        if (miria[2] != 0 && miria[1] != 1) {
            std::cout << A[miria[2] - 1] << std::endl;
        }
        std::cout << "ekatomyria" << std::endl;
    }
    //----------xilia---------------------------------------------
    //----------million ----------------
    if (xilia[0] + xilia[1] + xilia[2] != 0) {
        if (xilia[0] != 0) {
            std::cout << F[xilia[0] - 1] << std::endl;
        }
        //-------------1dig----------
        if (xilia[1] != 0) {
            if (xilia[1] >= 2) { //ok
                std::cout << C[xilia[1] - 2] << std::endl;
            } else if (xilia[1] == 2) {
                std::cout << "eikosi" << std::endl;
            } else if (xilia[1] == 1 && xilia[2] == 2) {
                std::cout << "dodeka" << std::endl;
            } else if (xilia[1] == 1 && xilia[2] == 1) {
                std::cout << "enteka" << std::endl;
            } else if (xilia[1] == 1 && xilia[2] != 1 && xilia[2] != 2) {
                std::cout << V[xilia[2]] << std::endl;
            }
        }
        //----------2dig-------------
        if (xilia[2] != 0 && xilia[1] != 1) {
            std::cout << A[xilia[2] - 1] << std::endl;
        }
        std::cout << "xiliades" << std::endl;
    }
    //----------------------------------------------
    if (ekato[0] + ekato[1] + ekato[2] != 0) {
        if (ekato[0] != 0) {
            std::cout << D[ekato[0] - 1] << std::endl;
        }
        //-------------1dig----------
        if (ekato[1] != 0) {
            if (ekato[1] >= 2) {
                std::cout << C[ekato[1] - 2] << std::endl;
            } else if (ekato[1] == 2) {
                std::cout << "eikosi" << std::endl;
            } else if (ekato[1] == 1 && ekato[2] == 2) {
                std::cout << "dodeka" << std::endl;
            } else if (ekato[1] == 1 && ekato[2] == 1) {
                std::cout << "enteka" << std::endl; //ok
            } else if (ekato[1] == 1 && ekato[2] != 1 && ekato[2] != 2) {
                std::cout << V[ekato[2]] << std::endl;
            }
        }
        //----------2dig-------------
        if (ekato[2] != 0 && ekato[1] != 1) {
            std::cout << A[ekato[2] - 1] << std::endl;
        }
    }
    return 0;
}
