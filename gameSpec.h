#include <string>

class gameSpec{
    private:
        std::string console;
        std::string genre;
        std::string esrbRating;
        std::string developer;

    public:
        gameSpec();
        gameSpec(std::string, std::string, std::string, std::string);
        void operator=(const gameSpec&);

        void setConsole(std::string);
        void setGenre(std::string);
        void setEsrbRating(std::string);

        std::string getConsole() const;
        std::string getGenre() const;
        std::string getEsrbRating() const;
        std::string getDeveloper() const;
};