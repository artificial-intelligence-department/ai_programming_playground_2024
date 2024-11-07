#include <iostream>
#include <vector>



class chessPiece {
protected:

    int x;
    int y;

    char symbol;

public:

    chessPiece(int x, int y, char symb = 'O') {
        this->x = x;
        this->y = y;
        symbol = symb;
    }

    char getSymbol() { return symbol; }

    virtual bool isAbleToAttack(int X, int Y) {
        return false;
    }
};

std::vector<chessPiece*> figures;

class King : public chessPiece {
public:
    King(int x, int y) : chessPiece(x, y, 'K') {};

    bool isAbleToAttack(int X, int Y) override {
        int abs1 = abs(X - x);
        int abs2 = abs(Y - y);
        if ((abs1 == 1 && abs2 == 1) || (abs1 == 1 && abs2 == 0) || (abs1 == 0 && abs2 == 1)) return true;
        return false;
    }
};

class Rook : public chessPiece {
public:
    Rook(int x, int y) : chessPiece(x, y, 'R') {};

    bool isAbleToAttack(int X, int Y) override {
        if (y == Y || x == X) return true;
        return false;
    }
};

class Bishop : public chessPiece {
public:
    Bishop(int x, int y) : chessPiece(x, y, 'B') {};

    bool isAbleToAttack(int X, int Y) override {
        for (int k = 1; k <= 8; k++) {
            if ((y + k) == Y && (x + k) == X) return true;
            if ((y + k) == Y && (x - k) == X) return true;
            if ((y - k) == Y && (x + k) == X) return true;
            if ((y - k) == Y && (x - k) == X) return true;
        }
        return false;
    }
};

class Queen : public chessPiece {
public:
    Queen(int x, int y) : chessPiece(x, y, 'Q') {};

    bool isAbleToAttack(int X, int Y) override {
        if (y == Y || x == X) return true;
        for (int k = 1; k <= 8; k++) {
            if ((y + k) == Y && (x + k) == X) return true;
            if ((y + k) == Y && (x - k) == X) return true;
            if ((y - k) == Y && (x + k) == X) return true;
            if ((y - k) == Y && (x - k) == X) return true;
        }
        return false;
    }
};

class Knight : public chessPiece {
public:
    Knight(int x, int y) : chessPiece(x, y, 'N') {};

    bool isAbleToAttack(int X, int Y) override {
        if (X == x + 1 && Y == y + 2) return true;
        if (X == x - 1 && Y == y + 2) return true;
        if (X == x + 1 && Y == y - 2) return true;
        if (X == x - 1 && Y == y - 2) return true;
        if (X == x + 2 && Y == y + 1) return true;
        if (X == x + 2 && Y == y - 1) return true;
        if (X == x - 2 && Y == y + 1) return true;
        if (X == x - 2 && Y == y - 1) return true;
        return false;
    }
};

class Pawn : public chessPiece {
public:
    Pawn(int x, int y) : chessPiece(x, y, 'P') {};

    bool isAbleToAttack(int X, int Y) override {
        return (X == x + 1 && (Y == y - 1 || Y == y + 1));
    }
};

std::string ableToAttack(int x, int y) {
    if (figures[8 * (x - 1) + y - 1]->getSymbol() != 'O') return "X";
    std::string str = "";
    for (auto& fig : figures) {
        if (str.find(fig->getSymbol()) == std::string::npos && fig->isAbleToAttack(x, y)) {
            char symb = fig->getSymbol();
            if (str == "") str += symb;
            else if (str[str.size() - 1] <= symb) str += symb;
            else {
                const int SIZE = str.size();
                for (int i = 0; i < SIZE; i++) {
                    if (str[i] > symb) {
                        str.insert(str.begin() + i, symb);
                        break;
                    }
                }
            }
            
        }
    }
    return str == "" ? "O" : str;
}

int main() {

    std::string symbs = "OPRNBKQ";
    const size_t NPOS = std::string::npos;
    char symb;
    chessPiece* figure = nullptr;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cin >> symb;

            if (symbs.find(symb) != NPOS) {
                switch (symb)
                {
                case 'O':
                    figure = new chessPiece(i + 1, j + 1);
                    break;
                case 'P':
                    figure = new Pawn(i + 1, j + 1);
                    break;
                case 'R':
                    figure = new Rook(i + 1, j + 1);
                    break;
                case 'N':
                    figure = new Knight(i + 1, j + 1);
                    break;
                case 'B':
                    figure = new Bishop(i + 1, j + 1);
                    break;
                case 'K':
                    figure = new King(i + 1, j + 1);
                    break;
                case 'Q':
                    figure = new Queen(i + 1, j + 1);
                    break;
                default:
                    break;
                }
                figures.push_back(figure);
            }
        }
    }
    int Q;
    std::cin >> Q;
    int x, y;
    std::vector<std::string> outputs;
    for (int i = 0; i < Q; i++) {
        std::cin >> x >> y;
        outputs.push_back(ableToAttack(x, y));
    }
    for (std::string str : outputs) std::cout << str << std::endl;

    return 0;
}