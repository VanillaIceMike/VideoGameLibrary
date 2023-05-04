#include <string>

class gameSpec{
    private:
        std::string console;
        std::string genre;
        std::string esrbRating;

    public:
        gameSpec();
        gameSpec(std::string, std::string, std::string);

        void setConsole(std::string);
        void setGenre(std::string);
        void setEsrbRating(std::string);

        std::string getConsole();
        std::string getGenre();
        std::string getEsrbRating();
};